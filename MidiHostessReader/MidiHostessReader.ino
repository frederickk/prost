/**
 * MidiHostess
 * Reader
 * 
 * Arduino MKR1000
 * 
 * This devices reads the Midi data from sending host and
 * writes it out to the writing device to transmit to the
 * receiving host.
 * 
 * ken.frederick@gmx.de
 * http://kenfrederick.de/
 */

#include <Wire.h>
#include "MIDIUSB.h"

#define I2C_ADDR 0x26
#define BYTE_COUNT 4
#define SLAVE_RESET_PIN 2
#define LED_PIN 6 // MKR10000

uint8_t count;
uint8_t error_count;


char c_buf[64];


void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);

  Serial.begin(115200);
  while (!Serial) {; }

  Wire.begin(); 
}

void loop() {
  midiEventPacket_t rx;

  uint8_t i;
  uint8_t req_rtn;               // num bytes returned by requestFrom() call
  uint8_t in_midi[BYTE_COUNT];   // data read back from writer

  // count total number of requests
  count++;

  do {
    rx = MidiUSB.read();

    if (rx.header != 0) {
      Wire.beginTransmission(I2C_ADDR);
      Wire.write(rx.header);
      Wire.write(rx.byte1); 
      Wire.write(rx.byte2);
      Wire.write(rx.byte3);
      Wire.endTransmission();

      digitalWrite(LED_PIN, HIGH);
    } else {
      digitalWrite(LED_PIN, LOW);
    }
  } while (rx.header != 0);

  // read bytes from writer
  req_rtn = Wire.requestFrom(I2C_ADDR, (int)BYTE_COUNT);
  for (i = 0; i < req_rtn; i++) {
    in_midi[i] = Wire.read();
  }
  
}

void debugPrint(uint8_t req_rtn) {
//  uint8_t i;
//  uint8_t out_midi[BYTE_COUNT];  // data written from master
//  bool mismatch;
//  
//  // compare in/out data values
//  mismatch = false;
//  for (i = 0; i < BYTE_COUNT; i++) {
//    mismatch = mismatch || (out_midi[i] != in_midi[i]);
//  }
//
//  // increment the error counter if the number of byte variables don't match or
//  // if the data itself doesn't match
//  if (mismatch || (BYTE_COUNT != req_rtn)) {
//    error_count++;
//  }
//
//  snprintf(c_buf, sizeof(c_buf), "req: %3d,err: %3d", count, error_count);
//  Serial.println(c_buf);
//
//  snprintf(c_buf, sizeof(c_buf), "size: %2d/%2d,%s", BYTE_COUNT, req_rtn, BYTE_COUNT != req_rtn?"MISMATCH  <<--- !!!":"MATCH");
//  Serial.println(c_buf);
//  
//  snprintf(c_buf, sizeof(c_buf), "data: %s", mismatch?"MISMATCH  <<--- !!!":"MATCH");
//  Serial.println(c_buf);
//
//  if (BYTE_COUNT >= 1) {
//    snprintf(c_buf, sizeof(c_buf), "midi[0]: %02x/%02x", out_midi[0], in_midi[0]);
//    Serial.println(c_buf);
//  }
//
//  if (BYTE_COUNT >= 2) {
//    snprintf(c_buf, sizeof(c_buf), "midi[1]: %02x/%02x", out_midi[1], in_midi[1]);
//    Serial.println(c_buf);
//  }
//
//  if (BYTE_COUNT >= 3) {
//    snprintf(c_buf, sizeof(c_buf), "midi[2]: %02x/%02x", out_midi[2], in_midi[2]);
//    Serial.println(c_buf);
//  }  

  //  delay(1000);
}
