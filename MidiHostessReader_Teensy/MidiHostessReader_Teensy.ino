#include <Wire.h>


#define I2C_ADDR 0x26
#define BYTE_COUNT 4
#define SLAVE_RESET_PIN 2
#define LED_PIN 13 // TEENSY 3.x

uint8_t count;
uint8_t error_count;


char c_buf[64];


void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);

  Wire.begin();

  Serial.begin(115200);
  while (!Serial) {; }
}

void loop() {
  uint8_t i;
  uint8_t req_rtn;               // num bytes returned by requestFrom() call
  uint8_t in_midi[BYTE_COUNT];   // data read back from writer

  // count total number of requests
  count++;

  while (usbMIDI.read()) {
    Wire.beginTransmission(I2C_ADDR);

    // which MIDI message, 128-255
    Serial.println(usbMIDI.getType(), DEC);       
    Wire.write(usbMIDI.getType());

    // which MIDI channel, 1-16
    Serial.println(usbMIDI.getChannel(), DEC);
    Wire.write(usbMIDI.getChannel());
    
    // first data byte of message, 0-127
    Serial.println(usbMIDI.getData1(), DEC);
    Wire.write(usbMIDI.getData1()); 

    // second data byte of message, 0-127     
    Serial.println(usbMIDI.getData2(), DEC);
    Wire.write(usbMIDI.getData2());

    // which virtual cable with MIDIx8, 0-7     
//    Serial.println(usbMIDI.getCable(), DEC);    

    Wire.endTransmission();
  }

  // read bytes from writer
  req_rtn = Wire.requestFrom(I2C_ADDR, (int)BYTE_COUNT);
  for (i = 0; i < req_rtn; i++) {
    in_midi[i] = Wire.read();
  }

}
