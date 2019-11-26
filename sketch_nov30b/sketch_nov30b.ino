/*
 * i2c-slave-demo.ino
 */

#include "TinyWireS.h"

#define SLAVE_ADDR 9
#define ANSWERSIZE 5

uint8_t master_bytes;

String answer = "Hello";

void setup() {
  TinyWireS.begin(SLAVE_ADDR);
  TinyWireS.onRequest(requestEvent);
  TinyWireS.onReceive(receiveEvent);
}

void receiveEvent(uint8_t num_bytes) {
  master_bytes = num_bytes;

  while (0 < TinyWireS.available()) {
    byte x = TinyWireS.receive();
  }
}

void requestEvent() {
  byte response[ANSWERSIZE];

  for (byte i = 0; i < ANSWERSIZE; i++) {
    response[i] = (byte)answer.charAt(i);
  }

  write(response, sizeof(response));
}

void loop() {
  TinyWireS_stop_check();  
}


void write(const uint8_t *data, size_t quantity) {
  for (size_t i = 0; i < quantity; ++i) {
    TinyWireS.send(data[i]);
  }
}
