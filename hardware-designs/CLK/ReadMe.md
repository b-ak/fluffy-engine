## Clock

A clock using Four, 1 inch 7 segment displays and One Shift register. Runs with an arduino Nano. 
Powered by a 5V adapter and USB Mini B cable. Uses a DS3231 RTC. 

[Credits to korolg for the Idea and Code](http://fritzing.org/projects/7-segment-led-clock-with-multiplexing)

![Top](./schematics/clock_top.png)
![Bottom](./schematics/clock_bot.png) 
![Preview](./schematics/preview.jpg) 

## Programming (Updated Spetember 2025)

Will require the following libraries for the code to build on Android IDE 1.8.8

1. Install [Adafruit Bus IO](https://github.com/adafruit/Adafruit_BusIO)
2. Install [RTCLib by Adafruit](https://github.com/adafruit/RTClib)

## IDE Settings 

IDE settings for flashing the Arudino IDE 1.8.8 (which were used at the time the HW was built).
I haven't tried the Newer adruinos as the same HW has been running for ~6 years 

```
Board: Arduino Nano
Processor: ATMega328P (Old Bootloader)
Port: As per system device enumeration
Programmer: AVRISP mkII
```

## Setting the time over Bluetooth

The clock can be set from a phone with a small BLE module glued to the back of the board, so it never needs to be reflashed to change the time.

**Sync page:** [https://b-ak.github.io/fluffy-engine/clk/](https://b-ak.github.io/fluffy-engine/clk/)

Open it, tap **Sync clock to this time**, pick the clock from the list, and the clock is set to the phone's date and time. **Check clock time** shows what the clock reads and how far off it is.

The page works in Chrome on Android and desktop, and in the Bluefy browser on iPhone (Safari has no Web Bluetooth). Don't pair the module in the phone's Bluetooth settings; the page connects to it directly.

### How it works

GitHub Pages never talks to the clock. It only delivers the page's code to the phone; after that, the phone talks to the clock directly over Bluetooth.

- **GitHub Pages** is free static hosting built into GitHub. When `web/index.html` changes on `main`, the *Deploy CLK sync page* workflow copies it to GitHub's web servers, which serve it at `https://b-ak.github.io/fluffy-engine/clk/`. Nothing runs on GitHub's side, and it never learns that a clock exists.
- **Chrome on the phone** downloads that one HTML file and runs its JavaScript, which is where the logic lives. Browsers only allow Bluetooth access (the Web Bluetooth API) from secure https pages, which is why the page is hosted on Pages rather than opened from a local file.
- **The time source is the phone's own clock**, read with JavaScript's `new Date()`. The phone keeps it accurate itself, from the mobile network or internet time servers. The page doesn't fetch the time from anywhere; it copies the phone's.
- **The AT-09 module** doesn't interpret anything. It is a transparent bridge: bytes the phone writes to its FFE1 characteristic come out of its TXD pin as plain serial data, and bytes going into its RXD pin go back to the phone as a Bluetooth notification. To the Nano it looks like a serial cable.
- **The Nano** reads those bytes on D8, checks the command (`T20261127163600`), writes the time into the DS3231 over I2C, reads it back, and replies `OK …` through D10 and the divider.
- **The DS3231** does the actual timekeeping. The Nano never keeps time itself: on every pass through `loop()` it reads the time from the RTC and shows it. The coin cell keeps the RTC running through power cuts, which is why the time survives an unplug.

```mermaid
sequenceDiagram
    participant GH as GitHub Pages (https)
    participant P as Phone (Chrome page)
    participant M as AT-09 (BLE to UART)
    participant N as Nano (firmware)
    participant R as DS3231 (RTC + coin cell)

    Note over GH,P: 1. Once, when the page opens
    P->>GH: GET /fluffy-engine/clk/
    GH-->>P: index.html (page + JavaScript)

    Note over P,R: 2. Tap "Sync clock to this time" (no internet needed)
    P->>P: Read phone clock, wait for the next second
    P->>M: BLE write to FFE1: T20261127163600
    M->>N: UART bytes on D8
    N->>R: I2C: set date and time
    N->>R: I2C: read time back
    R-->>N: 2026-11-27 16:36:00
    N-->>M: OK 2026-11-27 16:36:00 on D10 (via divider)
    M-->>P: BLE notification
    Note over P: Shows "Clock set to ..."

    Note over N,R: 3. Every loop, forever (about every 15 ms)
    loop Display loop
        N->>R: I2C: read time
        R-->>N: hh:mm:ss
        N->>N: Drive the 7-segment digits
    end
```

Details the diagram compresses:

- **GitHub only appears in step 1.** Once the page is open, the sync goes phone, Bluetooth, clock, and never touches the internet. Reopening the page later needs internet again, unless Chrome serves it from its cache.
- **The page waits for the start of the next second before sending**, so the clock starts that second in step with the phone. That's why **Check clock time** agrees to within a second.
- **The `OK` reply is a round trip, not an echo.** The Nano reads the time back from the DS3231 before replying, so "Clock set to …" confirms what the RTC actually holds, not just that bytes arrived.
- **Replies reach the page as Bluetooth notifications** on the FFE1 characteristic, which the page subscribes to. **Check clock time** works the same way: the page sends `?` and the Nano replies `NOW …`.

### Sketches

| Sketch | Use |
|---|---|
| `code/seven_segment_mux_clock_basic.ino` | Original clock, no Bluetooth. Time is set by reflashing. |
| `code/seven_segment_mux_clock_ble/` | Clock with Bluetooth time setting. Flash this once the module is fitted. |
| `code/ble_at_passthrough/` | One-time helper to send AT commands to the module (e.g. to name it). |

The Bluetooth sketches also use `SoftwareSerial`, which comes with the Arduino IDE. IDE settings are the same as above.

### Parts

- One HM-10 style BLE breakout per clock: **AT-09**, **HM-10** or **MLT-BT05** (CC2541), 6 pins (STATE, RXD, TXD, GND, VCC, EN/BRK). Use the breakout board with its own 3.3V regulator, not the bare module.
- **1kΩ** and **2kΩ** resistors (two 1kΩ in series, or 10kΩ/20kΩ, work too)
- Optional: a **10–100µF** capacitor across the module's VCC and GND

### Wiring

The module talks to the Nano over `SoftwareSerial` on **D8/D10**. D0/D1 are not used for it, since D1 drives the first hour digit. D8 and D10 are not connected to anything else on the board.

| Module pin | Nano pin | Notes |
|---|---|---|
| VCC | 5V | Same net as the RTC and 74HC595 supply. The module's regulator drops it to 3.3V. |
| GND | GND | |
| TXD | D8 | 3.3V output, read fine by the Nano. |
| RXD | D10, through the divider | The module's input is 3.3V, so don't connect 5V directly. |
| STATE | not connected | |
| EN / BRK | not connected | |

Divider on the D10 line (5V x 2/3 = 3.3V):

```
Nano D10 ──[ 1kΩ ]──┬──► module RXD
                    │
                  [ 2kΩ ]
                    │
                   GND
```

Check the pin labels on the module you receive; some clones order them differently.

### Mounting

- Put **Kapton tape or double-sided foam tape** between the module and the back of the board, so the module's traces can't touch the through-hole leads. Foam tape also keeps it removable.
- Leave the **antenna end** (the zig-zag trace) hanging past the board edge, or at least away from the Nano, the RTC and large copper areas.
- Solder the wires straight to the Nano's pins on the back. The two resistors can sit inline in the wires under heat-shrink.

### One-time setup: name each clock

With two clocks, give each module its own name so they can be told apart in the phone's list. Names starting with `CLK` are listed by the sync page without ticking "Show all Bluetooth devices".

1. Flash `code/ble_at_passthrough/` to the Nano. The first hour digit flickers while it runs; that's expected.
2. Open the Serial Monitor at **9600 baud**. Make sure no phone is connected to the module (AT commands only work while it is disconnected).
3. Type `AT` and send. The module should reply `OK`. If it replies `ERROR` or nothing, change the line ending setting: AT-09 / MLT-BT05 clones usually need **Both NL & CR**, a genuine HM-10 usually needs **No line ending**. An `ERROR` reply still means the wiring is fine; only the line ending is wrong.
4. Send `AT+NAMECLK-Hall` (or `CLK-Bedroom`, up to 12 characters). `AT+NAME` reads the name back.
5. Unplug the power for a few seconds so the module restarts with the new name. On some clones `AT+RESET` leaves the module silent (LED off, not advertising) until it is power-cycled, so a power cycle is the reliable way. Pressing the Nano's reset button doesn't restart the module.
6. Flash `code/seven_segment_mux_clock_ble/` back to the Nano.

Leave the baud rate and the service/characteristic UUIDs at their defaults (9600, FFE0/FFE1); the sketch and the page expect them.

Tested module: Robu AT-09 (ZS-040 carrier, CC2541), firmware `+VERSION=v6.1`. Needs **Both NL & CR**; `AT+RESET` needs a power cycle afterwards.

### Protocol

For reference or for use from another app. 9600 baud, one command per line (`\n` or `\r` ends it):

| Command | Meaning | Reply |
|---|---|---|
| `TYYYYMMDDhhmmss` | Set date and time, e.g. `T20261123235000` | `OK 2026-11-23 23:50:00` (read back from the RTC), or `ERR` |
| `?` | Read the clock | `NOW 2026-11-23 23:50:00` |

Each command is at most 16 bytes, so it fits a single 20-byte BLE write. The sketch never adjusts the RTC at boot, so a power cut can't reset the time.

### Troubleshooting

- **Clock not in the list:** tick "Show all Bluetooth devices", or name the module as above. Only one phone can be connected at a time.
- **"The clock didn't answer":** check that the clock runs `seven_segment_mux_clock_ble`, that module TXD goes to D8, and the D10 divider to module RXD. If only the D10 side is broken, the time is still set but the reply never reaches the phone; "Check clock time" will also get no answer.
- **Brief flicker while syncing:** `SoftwareSerial` pauses the display for a few milliseconds while a command arrives. It only happens during a sync.
