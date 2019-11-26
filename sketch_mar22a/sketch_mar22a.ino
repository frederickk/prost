#include "MIDIUSB.h"

uint8_t ppqn = 0;

void setup() {
  Serial.begin(115200);

  // Start
  midiSendRealTime(0xFA);
  MidiUSB.flush() ;
}

void loop() {

//  midiCommand(0xFA, 0, 0);
  midiSendRealTime(0xF8);
  MidiUSB.flush() ;

  delay(bpmToMs(90));
}

/**
 * Converts BPM to Milliseconds.
 */
uint8_t bpmToMs(uint8_t bpm) {
  return 60000 / bpm;
}

/**
 * Sends a 3-byte midi message
 */
void midiCommand(byte cmd, byte data1, byte  data2) {
  // First parameter is the event type (top 4 bits of the command byte).
  // Second parameter is command byte combined with the channel.
  // Third parameter is the first data byte
  // Fourth parameter second data byte

  midiEventPacket_t midiMsg = {cmd >> 4, cmd, data1, data2};
  MidiUSB.sendMIDI(midiMsg);
}

void midiSendRealTime(uint8_t type) {
  switch (type) {
    case 0xF8: // Clock
    case 0xFA: // Start
    case 0xFB: // Continue
    case 0xFC: // Stop
    case 0xFE: // ActiveSensing
    case 0xFF: // SystemReset
//      send(type, 0, 0, 0, cable);
      midiCommand(type, 0, 0);
      break;
    default: // Invalid Real Time marker
      break;
  }
}
