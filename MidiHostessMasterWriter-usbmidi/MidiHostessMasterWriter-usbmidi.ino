#include <Wire.h>
#include <usbmidi.h> 

#define ADDR 8
#define NUM_BYTES 4

#define MIDI_NOTE_OFF 0b10000000
#define MIDI_NOTE_ON 0b10010000
#define MIDI_CONTROL 0b10110000
#define MIDI_PITCH_BEND 0b11100000

#define LED_ACTIVE 5
#define LED_DATA_1 6
#define LED_DATA_2 9
#define LED_MISC 10


// Active data transfer
bool activity = false;

// Buffer for holding read bytes from I2C
unsigned char buf[NUM_BYTES];


void setup() {
  Serial.begin(9600);

  pinMode(LED_ACTIVE, OUTPUT);

  Wire.begin();
}

void loop() {
  USBMIDI.poll();

  midiIncomingUSBHandler();

  // blink the LED when any activity has happened
  if (activity) {
    digitalWrite(LED_ACTIVE, HIGH);
  } else {
    digitalWrite(LED_ACTIVE, LOW);
  }
}

/**
 * Handler for incoming USB.
 */
void midiIncomingUSBHandler() {

  Wire.beginTransmission(ADDR);
  while (USBMIDI.available()) {
    uint8_t rx = USBMIDI.read();
     debug(rx);

    Wire.write(rx);
//    Serial.print(rx >> 4, HEX);
//    Serial.print(rx & 0xf, HEX);
//    Serial.print('-');

//    activity = true;
  }
//  Serial.println();
  Wire.endTransmission();

  USBMIDI.flush();
}

void debug(uint8_t rx) {
  Serial.print(rx);
  Serial.print("\t");

  uint8_t command = rx & 0b11110000;
  uint8_t channel = (rx & 0b00001111) + 1;
  uint8_t key = 0;
  uint8_t velocity = 0;

  switch(command) {
    case MIDI_NOTE_ON:
    case MIDI_NOTE_OFF:
      if (USBMIDI.peek() & 0b10000000) {
        key = USBMIDI.read();
      }
      if (USBMIDI.peek() & 0b10000000) {
        velocity = USBMIDI.read();
      }
      break;
  }
  
  Serial.print(command);
  Serial.print("\tCh:");
  Serial.print(channel);
  Serial.print("\tK:");
  Serial.print(key);
  Serial.print("\tV:");
  Serial.print(velocity);
  Serial.print('\n');
}
