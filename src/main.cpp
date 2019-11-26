/**
 * 🍻 Prost 
 * v.0.1.0
 * 
 * Brings 2 Midi host devices to the table of data sharing.
 * Intermediary device to allow Midi host to Midi host communication.
 * 
 * https://github.com/frederickk/prost
 */
  
#include <Arduino.h>
#include <usbmidi.h>


#define LED_SERIAL 3
#define LED_USB 5


void setup() {
  Serial.begin(9600);
  Serial1.begin(31250); // MIDI baudrate

  pinMode(LED_SERIAL, OUTPUT);
  pinMode(LED_USB, OUTPUT);
}

void loop() {
  USBMIDI.poll();

  // When MidiUSB data is received, pass to Serial Midi.
  while(USBMIDI.available()) {
    Serial1.write(USBMIDI.read());
    Serial1.flush();
    digitalWrite(LED_USB, HIGH);
  }

  // When Serial Midi data is received, pass to MidiUSB.
  while(Serial1.available() > 0) {
    USBMIDI.write(Serial1.read());
    USBMIDI.flush();
    digitalWrite(LED_SERIAL, HIGH);
  }

  digitalWrite(LED_USB, LOW);
  digitalWrite(LED_SERIAL, LOW);
}
