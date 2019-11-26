/**
 * Requirements
 * http://www.arduino.cc/en/Reference/MIDIUSB
 * https://github.com/pfeerick/elapsedMillis/
 */

#include <Wire.h>
#include <elapsedMillis.h>
#include "MidiUtils.h"

#define LED_PIN 6
#define I2C_DEVICE_ADDR 8
#define NUM_BYTES 4

// A variable to know how long the LED has been turned on
elapsedMillis ledOnMillis;

// Active data transfer
bool activity = false;

int tick = 0;

// Midi Packet to send
midiEventPacket_t tx;

// Buffer for holding read bytes from I2C
uint8_t buf[NUM_BYTES];


void setup() {
  Serial.begin(115200);
//  while (!Serial); // Leonardo: wait for serial monitor
  Serial.println("\n2HOST");

  Wire.begin();

  pinMode(LED_PIN, OUTPUT);
//  digitalWrite(LED_PIN, HIGH);
//  delay(100);
//  digitalWrite(LED_PIN, LOW);
}

void loop() {
  activity = false;

//  debug();

  midiIncomingUSBHandler();

//  // request 4 bytes
//  uint8_t req = Wire.requestFrom(I2C_DEVICE_ADDR, NUM_BYTES);
//
//  Wire.readBytes(buf, req);
//  if (req != NUM_BYTES) {
//    Serial.print("Error, didn't receive enough bytes: ");
//    Serial.println(req);
//  } else {
//    MidiUtils::writeUsb(buf, NUM_BYTES);
//    MidiUtils::flushUsb();
//  }

  // blink the LED when any activity has happened
  if (activity) {
    digitalWrite(LED_PIN, HIGH);
    ledOnMillis = 0;
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  
//  if (ledOnMillis > 15) {
//    digitalWrite(LED_PIN, LOW);
//    TXLED0;
//  }

//  delay(100);
}

void debug() {
  for (byte i = 0; i < 255; i++) {
    Wire.beginTransmission(I2C_DEVICE_ADDR);
    Wire.write(i);
    Wire.endTransmission();
    delay(100);
  }
}

/**
 * Handler for incoming USB.
 */
void midiIncomingUSBHandler() {
  midiEventPacket_t rx;

//  Serial.print("rx.header: ");
//  Serial.print(rx.header, HEX);

  do {
    rx = MidiUSB.read();

    if (rx.header != 0) {
      activity = true;
      tx = rx;

     // get the USB MIDI message, defined by these 4 numbers (except SysEX)
      byte type = rx.byte1;
  //    byte channel = rx.byte1;
      byte data1 = rx.byte2; // e.g. pitch
      byte data2 = rx.byte3; // e.g. velocity
  
//      Serial.print("  type: ");
//      Serial.print(type, HEX);
//      Serial.print("  data1: ");
//      Serial.print(data1, HEX);
//      Serial.print("  data2: ");
//      Serial.print(data2, HEX);

      // Then simply send the data over I2C
      Wire.beginTransmission(I2C_DEVICE_ADDR);
//      Wire.write(tx.header);
//      Wire.write(tx.byte1);
      Wire.write(tx.byte2);
//      Wire.write(tx.byte3);
      Wire.endTransmission();

//      MidiUtils::flushUsb();

//      Wire.beginTransmission(I2C_DEVICE_ADDR);
//      if (type == MidiUtils::NOTE_ON) {
//        digitalWrite(LED_PIN, HIGH);
//        Wire.write('H');
//      } else {
//        digitalWrite(LED_PIN, LOW);
//        Wire.write('L');
//      }
//      Wire.endTransmission();

//      if (type == MidiUtils::CLOCK) {
//        // no led activity on clock
//        activity = false;
//        ledOnMillis = 0;
//      } else {
//        activity = true;
//      }
    } else {
//      activity = false;
//      tx = {0x0F, MidiUtils::MSG_START | 1, 0, 0};
//      digitalWrite(LED_PIN, LOW);
    }
  } while(rx.header != 0);
}

/**
 * Converts BPM to Milliseconds.
 */
uint8_t bpmToMs(uint8_t bpm) {
  return 60000 / bpm;
}
