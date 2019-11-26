#include <Wire.h>
#include "MIDIUSB.h"

#define SLAVE_ADDR 9
#define BYTE_COUNT 5

void setup() {
  Wire.begin();

  Serial.begin(115200);
  while (!Serial);
}

void loop() {
  midiEventPacket_t rx;
  uint8_t i;
  uint8_t in_midi[BYTE_COUNT];

//  while (MidiUSB.available()) {
//    rx = MidiUSB.read();
//
//    // Output the byte to the Serial interface.
//    Serial.print(rx >> 4, HEX);
//    Serial.print(rx & 0xf, HEX);
//    Serial.print('\n');
//  }


  do {
    rx = MidiUSB.read();

    if (rx.header != 0) {
      byte type = rx.header;
      byte channel = rx.byte1;
      byte data1 = rx.byte2;
      byte data2 = rx.byte3;
  
      Serial.print("type   : ");
      Serial.println(type, HEX);
      Serial.print("channel: ");
      Serial.println(channel, HEX);
      Serial.print("data1  : ");
      Serial.println(data1, HEX);
      Serial.print("data2  : ");
      Serial.println(data2, HEX);
      Serial.println("---------");

//      in_midi[0] = rx.header;
//      Serial.print("Header  : ");
//      Serial.println(rx.header);
//      in_midi[1] = rx.byte1; 
//      Serial.print("rx.byte1: ");
//      Serial.println(rx.byte1);
//      in_midi[2] = rx.byte2;
//      Serial.print("rx.byte2: ");
//      Serial.println(rx.byte2);
//      in_midi[3] = rx.byte3;
//      Serial.print("rx.byte3: ");
//      Serial.println(rx.byte3);
    }
  } while (rx.header != 0);
  
//  Serial.println("Write data to slave");
//
//  Wire.beginTransmission(SLAVE_ADDR);
////  Wire.write(0);
//  for (i = 0; i < BYTE_COUNT; i++) {
//    Wire.write(in_midi[i]);
//  }
//  Wire.endTransmission();
//
//  Serial.println("Receive data");
//
//  // Read response from Slave
//  Wire.requestFrom(SLAVE_ADDR, BYTE_COUNT);
//
//  // Add characters to string
//  String response = "";
//  while (Wire.available()) {
//    char b = Wire.read();
//    response += b;
//  }
//
//  // Print to Serial Monitor
//  Serial.println(response);
}
