/**
 * 🍻 Prost 
 * v.0.1.2
 * 
 * Brings 2 Midi host devices to the table of data sharing.
 * Intermediary device to allow Midi host to Midi host communication.
 * 
 * https://github.com/frederickk/prost
 */
  
#include <Arduino.h>
#include <midi_serialization.h>
#include <midi_messages.h>
#include <usbmidi.h>


#define DEBUG 0 // Set to 1 to see debug log messages.

#if defined(__AVR_ATmega32U4__)
  #ifdef ARDUINO_MICRO
    #define LED_USB D3
    #define LED_SERIAL D5
    #define ANALOG_SYNC D9
  #elif FEATHER_32U4
    #define LED_USB A5
    #define LED_SERIAL A3
    #define ANALOG_SYNC NULL
  #elif CORE_TEENSY
    // TODO(frederickk): Add Teensy pins.
  #else
    #define LED_USB 3
    #define LED_SERIAL 5
    #define ANALOG_SYNC 9
  #endif
#else
  #error Only 32u4 based boards are supported
#endif

#define CLOCK 0xF8
#define START 0xFA
#define CONTINUE 0xFB
#define STOP 0xFC


MidiToUsb midiDataParser;

static uint8_t countClock; // Keep track of clock ticks.
static uint8_t intervalClock = 24; // Default interval is quarter notes.
static uint8_t syncPulse = 0;

void clockHandler(uint8_t byte);
void printClockDebug();


void setup() {
  Serial.begin(9600);
  Serial1.begin(31250); // MIDI baudrate.

  pinMode(LED_USB, OUTPUT);
  pinMode(LED_SERIAL, OUTPUT);
  pinMode(ANALOG_SYNC, OUTPUT); // Analog sync is more reliable with 5V boards.
}

void loop() {
  USBMIDI.poll();

  // When Serial Midi data is received, pass to MidiUSB.
  while(Serial1.available() > 0) {
    uint8_t serialData = Serial1.read();

    USBMIDI.write(serialData);
    USBMIDI.flush();

    digitalWrite(LED_SERIAL, HIGH);
    clockHandler(serialData);
  }
  
  // When MidiUSB data is received, pass to Serial Midi.
  while(USBMIDI.available()) {
    uint8_t usbData = USBMIDI.read();
    midi_event_t event;

    // uint8_t msgType = event.m_event & 0x0f;
    // uint8_t byte1 = event.m_data[0];
    // uint8_t byte2 = event.m_data[1];
    // uint8_t byte3 = event.m_data[2];

    Serial1.write(usbData);
    Serial1.flush();

    if (midiDataParser.process(usbData, event)) {
      digitalWrite(LED_USB, HIGH);
      clockHandler(event.m_data[0]);
    }
  }

  digitalWrite(ANALOG_SYNC, LOW);

  if (syncPulse == 1) {
    digitalWrite(ANALOG_SYNC, HIGH);
    digitalWrite(LED_SERIAL, HIGH);
    digitalWrite(LED_USB, HIGH);
  }

  digitalWrite(LED_USB, LOW);
  digitalWrite(LED_SERIAL, LOW);
}

/**
 * Handles clock Midi messages for analog sync.
 * @param  byte  Incoming Midi byte, following header byte.
 */ 
void clockHandler(uint8_t byte) {
  // syncPulse = 0;

  switch (byte) {
    case CLOCK:
      ++countClock;
      if (countClock == intervalClock) {
        countClock = 0;
        syncPulse = 1;
      } else {
        syncPulse = 0;
      }
#if DEBUG
        Serial.print("---> CLOCK <---");
        printClockDebug();
#endif
      break;
    case START:
      countClock = 0;
      syncPulse = 1;
#if DEBUG
        Serial.println("|--- START ---|");
        printClockDebug();
#endif
      break;
    case CONTINUE:
      syncPulse = 1;
#if DEBUG
        Serial.print("<--- CONT. --->");
        printClockDebug();
#endif
      break;
    case STOP:
      syncPulse = 0;
      countClock = 0;
#if DEBUG
        Serial.print("|-|- STOP  -|-|");
        printClockDebug();
#endif
      break;
  }
}

/**
 * Prints clock debug messages to Serial terminal.
 */ 
void printClockDebug() {
  Serial.print("\t");
  Serial.print(intervalClock);
  Serial.print("\t");
  Serial.print(countClock);
  Serial.print("\t");
  Serial.println(syncPulse);
}