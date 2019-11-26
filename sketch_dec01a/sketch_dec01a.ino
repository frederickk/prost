#include <Wire.h>
#include <MIDI.h>

#if defined(USBCON)
  // Instantiate USB Midi
  #include <midi_UsbTransport.h>
  
  static const unsigned sUsbTransportBufferSize = 16;
  typedef midi::UsbTransport<sUsbTransportBufferSize> UsbTransport;
  
  UsbTransport sUsbTransport;
  
  MIDI_CREATE_INSTANCE(UsbTransport, sUsbTransport, MIDI);

#else
  // No USB available, fallback to Serial
  MIDI_CREATE_DEFAULT_INSTANCE();
#endif


#define WRITER_ADDR 0x26
#define BYTE_COUNT 4


void setup() {
  Wire.begin();

  Serial.begin(115200);
  while (!Serial);

  MIDI.begin(MIDI_CHANNEL_OMNI);
//  MIDI.setHandleNoteOn(handleNoteOn);
//  MIDI.setHandleNoteOff(handleNoteOff);
  Serial.println("Arduino ready.");
}

void loop() {
  if (MIDI.read()) {
    byte type = MIDI.getType();
//    NoteOff               = 0x80,
//    NoteOn                = 0x90,
//    Clock                 = 0xF8,
//    Start                 = 0xFA,
//    Continue              = 0xFB,
//    Stop                  = 0xFC,

    byte data1 = MIDI.getData1();
    byte data2 = MIDI.getData2();
    byte channel = MIDI.getChannel();

    Serial.print("type   : ");
    Serial.println(type, HEX);
    Serial.print("data1  : ");
    Serial.println(data1, HEX);
    Serial.print("data2  : ");
    Serial.println(data2, HEX);
    Serial.print("channel: ");
    Serial.println(channel, HEX);
//
//    Serial.println("---------");
//    Serial.println("Send data to writer...");

    Wire.beginTransmission(WRITER_ADDR);
    Wire.write(type);
    Wire.write(data1);
    Wire.write(data2);
    Wire.write(channel);
    Wire.endTransmission();

//    Serial.println("---------"); 
  }
}
