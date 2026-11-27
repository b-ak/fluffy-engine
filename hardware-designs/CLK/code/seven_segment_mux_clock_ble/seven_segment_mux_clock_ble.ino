// 4-digit multiplexed 7-segment clock with a DS3231 RTC and BLE time setting.
//
// Same display hardware and code as seven_segment_mux_clock_basic.ino, plus an
// HM-10 / AT-09 style BLE UART module on SoftwareSerial (D8 / D10) so the time
// can be set from a phone without reflashing. See ../../ReadMe.md for wiring and
// the sync web page.
//
// BLE protocol (9600 baud, one command per line, '\n' or '\r' terminated):
//   TYYYYMMDDhhmmss   set date and time, e.g. T20261123235000
//                     reply: "OK YYYY-MM-DD hh:mm:ss" (time read back from the RTC)
//                            "ERR" if the command is malformed or out of range
//   ?                 read the clock, reply: "NOW YYYY-MM-DD hh:mm:ss"
// Commands are 16 bytes including the newline, which fits a single 20-byte BLE write.

#include <Wire.h>
#include <RTClib.h>
#include <SoftwareSerial.h>

// set shift register pins
#define data_pin 13
#define latch_pin 12
#define clock_pin 11

// set digit segments 5V pins
#define d1_pin 1
#define d2_pin 2
#define d3_pin 3
#define d4_pin 4
#define dot_pin 7
#define btn_pin 9

// BLE module (HM-10 / AT-09 / MLT-BT05), 3.3V logic
#define ble_rx_pin 8   // module TXD -> D8
#define ble_tx_pin 10  // D10 -> 1k/2k divider -> module RXD
#define ble_baud 9600  // factory default of these modules

#define mux_delay 3 // set delay between switching display of digits

// define digits, 0 - on, 1 - off
byte segments[10] = {
  0b00000001, // 0
  0b01100111, // 1
  0b00010010, // 2
  0b01000010, // 3
  0b01100100, // 4
  0b01001000, // 5
  0b00001000, // 6
  0b01100011, // 7
  0b00000000, // 8
  0b01000000  // 9
};

byte segments_off = 0b01111111;

// create RTC object for clock
RTC_DS3231 rtc;

// BLE UART
SoftwareSerial ble(ble_rx_pin, ble_tx_pin);

// "T" + 14 digits; anything longer is not a valid command
#define cmd_max 15
char cmd[cmd_max + 1];
byte cmd_len = 0;
bool cmd_overflow = false;



// HELPER FUNCTIONS

// clears digits on display by turning power off
void clearDisplay() {
  digitalWrite(d1_pin, LOW);
  digitalWrite(d2_pin, LOW);
  digitalWrite(d3_pin, LOW);
  digitalWrite(d4_pin, LOW);
}

// display single digit
void displayDigit(int digit_pin, int number) {
  // using shift register to light up required led segments
  digitalWrite(latch_pin, LOW);
  shiftOut(data_pin, clock_pin, LSBFIRST, segments[number]);
  digitalWrite(latch_pin, HIGH);
  // blank display
  clearDisplay();
  // light up required digit
  digitalWrite(digit_pin, HIGH);
}

// display time
void displayTime(int hours, int minutes) {
  int h1, h2, m1, m2;
  h2 = hours % 10;
  h1 = (hours % 100) / 10;
  m2 = minutes % 10;
  m1 = (minutes % 100) / 10;

  if (h1==0) {
    clearDisplay(); // diplay first hour digit only if it is greater than 0
  }
  else
  {
    displayDigit(d1_pin, h1);
  }
  delay(mux_delay);
  displayDigit(d2_pin, h2);
  delay(mux_delay);
  displayDigit(d3_pin, m1);
  delay(mux_delay);
  displayDigit(d4_pin, m2);
  delay(mux_delay);
}

// blink dot
void blinkDot(int seconds) {
  if ( (seconds % 2) == 0 ) {
    clearDisplay();
    digitalWrite(latch_pin, LOW);
    shiftOut(data_pin, clock_pin, LSBFIRST, segments_off);
    digitalWrite(latch_pin, HIGH);
    digitalWrite(d2_pin, HIGH);
    digitalWrite(dot_pin, LOW);
  } else {
    clearDisplay();
    digitalWrite(dot_pin, HIGH);
  }
  delay(mux_delay);
}

// display date
void displayDate(int days, int months) {
  int d1, d2, m1, m2;
  d2 = days % 10;
  d1 = (days % 100) / 10;
  m2 = months % 10;
  m1 = (months % 100) / 10;
  if (d1 == 0) {
    clearDisplay(); // diplay first hour digit only if it is greater than 0
  } else {
    displayDigit(d1_pin, d1);
  }
  delay(mux_delay);
  displayDigit(d2_pin, d2);
  digitalWrite(dot_pin, LOW);
  delay(mux_delay);
  digitalWrite(dot_pin, HIGH);
  displayDigit(d3_pin, m1);
  delay(mux_delay);
  displayDigit(d4_pin, m2);
  delay(mux_delay);
}


// BLE TIME SETTING

// parse n decimal digits starting at s; returns -1 if any char is not a digit
int parseDigits(const char *s, byte n) {
  int value = 0;
  for (byte i = 0; i < n; i++) {
    if (s[i] < '0' || s[i] > '9') return -1;
    value = value * 10 + (s[i] - '0');
  }
  return value;
}

byte daysInMonth(int year, int month) {
  static const byte days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (month == 2 && (year % 4 == 0)) return 29; // valid for 2000-2099, the DS3231 range
  return days[month - 1];
}

// reply with a prefix and the time currently held by the RTC
void replyTime(const __FlashStringHelper *prefix) {
  char buf[] = "YYYY-MM-DD hh:mm:ss";
  rtc.now().toString(buf);
  ble.print(prefix);
  ble.println(buf);
}

// "TYYYYMMDDhhmmss" -> set the RTC; returns false if malformed or out of range
bool setTimeFromCommand(const char *c) {
  int year   = parseDigits(c + 1, 4);
  int month  = parseDigits(c + 5, 2);
  int day    = parseDigits(c + 7, 2);
  int hour   = parseDigits(c + 9, 2);
  int minute = parseDigits(c + 11, 2);
  int second = parseDigits(c + 13, 2);

  if (year < 2000 || year > 2099) return false;
  if (month < 1 || month > 12) return false;
  if (day < 1 || day > daysInMonth(year, month)) return false;
  if (hour < 0 || hour > 23) return false;
  if (minute < 0 || minute > 59) return false;
  if (second < 0 || second > 59) return false;

  rtc.adjust(DateTime(year, month, day, hour, minute, second));
  return true;
}

void handleCommand() {
  if (cmd_len == 1 && cmd[0] == '?') {
    replyTime(F("NOW "));
  } else if (cmd[0] == 'T' && cmd_len == cmd_max && setTimeFromCommand(cmd)) {
    replyTime(F("OK "));
  } else if ((cmd[0] == 'T' && cmd_len > 1) || cmd[0] == '?') {
    ble.println(F("ERR"));
  }
  // anything else is ignored, including module status text such as "OK+CONN"
  // and the lone 'T' left over from "OK+LOST" when a phone disconnects
}

// read whatever the BLE module has sent; never blocks the display loop
void pollBle() {
  while (ble.available()) {
    char c = ble.read();

    // 'T' and '?' always start a new command. This also drops status text
    // that some firmwares send without a line ending ("OK+CONN", "OK+LOST").
    if (c == 'T' || c == '?') {
      cmd_len = 0;
      cmd_overflow = false;
    }

    if (c == '\n' || c == '\r') {
      if (cmd_len > 0 && !cmd_overflow) {
        cmd[cmd_len] = '\0';
        handleCommand();
      }
      cmd_len = 0;
      cmd_overflow = false;
    } else if (cmd_len < cmd_max) {
      cmd[cmd_len++] = c;
    } else {
      cmd_overflow = true; // too long; discard until the next line ending
    }
  }
}


// MAIN PROGRAM BODY
#define LED_BUILTIN_TX 30

void setup() {

  // set pin modes
  pinMode(data_pin, OUTPUT);
  pinMode(latch_pin, OUTPUT);
  pinMode(clock_pin, OUTPUT);
  pinMode(d1_pin, OUTPUT);
  pinMode(d2_pin, OUTPUT);
  pinMode(d3_pin, OUTPUT);
  pinMode(d4_pin, OUTPUT);
  pinMode(dot_pin, OUTPUT);
  pinMode(btn_pin, INPUT_PULLUP); // activate pullup resistor for button pin in atmega

  digitalWrite(LED_BUILTIN_TX, LOW);

  ble.begin(ble_baud);

  // start connection with clock and the clock itself
  Wire.begin();
  if (! rtc.begin()) {
    ble.println(F("ERR RTC"));
    while (1);
  }

  // The time is set over BLE now (see ReadMe), so the RTC is never adjusted at
  // boot. To set it from the computer instead, uncomment ONE of these, flash,
  // then comment it again and flash once more (otherwise every power loss
  // resets the clock to this value).
  // rtc.adjust(DateTime(__DATE__, __TIME__));
  // rtc.adjust(DateTime(2025, 9, 3, 7, 44, 0)); // Year, Month, Date, Hour, Minute, Second
}

void loop() {

  pollBle();

  // read time
  DateTime now = rtc.now();
  int hours = now.hour();
  int minutes = now.minute();
  int seconds = now.second();
  int days = now.day();
  int months = now.month();

  // display date if button is pressed and time otherwise
  if ( digitalRead(btn_pin) == LOW) {
    displayDate(days, months);
  } else {
    displayTime(hours, minutes);
    blinkDot(seconds); // blink divider dot
  }

}
