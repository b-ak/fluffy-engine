// One-time setup helper for the clock's BLE module (HM-10 / AT-09 / MLT-BT05).
//
// Bridges the Nano's USB serial to the BLE module on D8 / D10 so AT commands
// can be typed in the Arduino Serial Monitor, e.g. to give each clock its own
// name. Flash this, configure the module, then flash
// seven_segment_mux_clock_ble again. Steps are in ../../ReadMe.md.
//
// While this sketch runs, the first hour digit flickers with the USB serial
// traffic (D1/TX also drives that digit). That is expected and harmless.
//
// AT commands only work while no phone is connected to the module.

#include <SoftwareSerial.h>

#define ble_rx_pin 8   // module TXD -> D8
#define ble_tx_pin 10  // D10 -> 1k/2k divider -> module RXD

SoftwareSerial ble(ble_rx_pin, ble_tx_pin);

void setup() {
  Serial.begin(9600);
  ble.begin(9600);
  Serial.println(F("BLE AT passthrough ready. Type AT and expect OK."));
}

void loop() {
  if (Serial.available()) ble.write(Serial.read());
  if (ble.available()) Serial.write(ble.read());
}
