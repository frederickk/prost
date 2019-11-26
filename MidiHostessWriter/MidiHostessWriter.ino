/**
 * MidiHostess
 * Writer
 * 
 * Digistump Attiny85
 * 8MHz
 * 
 * This devices recieves the Midi data from the reader device and
 * transmit the data to receiving Midi host.
 * 
 * ken.frederick@gmx.de
 * http://kenfrederick.de/
 */

#include "TinyWireS.h"
#include <DigiMIDI.h>

#define I2C_ADDR 0x26
#define BYTE_COUNT 4
#define LED_PIN 1


DigiMIDIDevice midi;

uint8_t reader_data[BYTE_COUNT];
uint8_t reader_bytes;
uint8_t sender_data[BYTE_COUNT];



void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);

  TinyWireS.begin(I2C_ADDR);
  TinyWireS.onReceive(receiveEvent);
//  TinyWireS.onRequest(requestEvent);

  sender_data[0] = 0x90; // note on
  sender_data[1] = 0x48; // note C4 (72)
  sender_data[2] = 0x64; // velocity 100
  sender_data[3] = 0x02; // channel 2
}

void loop() {
  midi.update();

//  digitalWrite(LED_PIN, HIGH);
//  delay(500);
  digitalWrite(LED_PIN, LOW);
//  delay(500);

//  midi.send(
//    0x90, // note on
//    0x48, // note C4 (72)
//    0x64, // velocity 100
//    0x02  // channel 2
//  );

  TinyWireS_stop_check();  
}

/**
 * Executes whenever data is received from master this function
 * is registered as an event, see setup().
 * 
 * numBytes  number of bytes sent through.
 */
void receiveEvent(uint8_t num_bytes) {
  digitalWrite(LED_PIN, HIGH);
  
  uint8_t i;
  
  reader_bytes = num_bytes;

  for (i = 0; i < reader_bytes; i++) {
    reader_data[i] = TinyWireS.receive();
  }

//  midi.sendNoteOn(reader_data[1], reader_data[2]);
  midi.send(
    reader_data[0],
    reader_data[1],
    reader_data[2],
    reader_data[3]
  );
}

///**
// * Gets called when the ATtiny receives an I2C read writer request.
// */
//void requestEvent() {
//  uint8_t i;
//
//  for (i = 0; i < BYTE_COUNT; i++) {
//    TinyWireS.send(sender_data[i]);
//  }
//  
////  for (i = 0; i < reader_bytes; i++) {
////    TinyWireS.send(reader_data[i]);
////  }
////
////  for (i = 0; i < reader_bytes; i++) {
////    reader_data[i] += 0x5a;
////  }
//
//  reader_bytes = 2; 
//}







//void receiveEvent(uint8_t numBytes) {
//  
//  uint8_t bytesRead;
//  while (TinyWireS.available()) {
//    digitalWrite(LED_PIN, HIGH);
//    reader_data[bytesRead] = TinyWireS.receive();
//    bytesRead++;
//  }
//
////  uint8_t i;
////  for (i = 0; i < bytesRead + 1; i++) {
////    reader_data[i] = TinyWireS.read();
////  }
//
//
//  //  midi.sendNoteOn(60, 100);
//  midi.send(
//    0x90, // note on byte
//    reader_data[1],
//    0x64, // velocity 100
//    0x01  // channel 1
//  );
//  
//  //  midi.send(
//  //    reader_data[0],
//  //    reader_data[1],
//  //    reader_data[2],
//  //    reader_data[3]
//  //  );
//
//  digitalWrite(LED_PIN, LOW);
//}
