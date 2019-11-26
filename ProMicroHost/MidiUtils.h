/**
 * MidiUtils.h
 *
 * Wrapper utility class for handling Midi USB methods.
 * http://www.arduino.cc/en/Reference/MIDIUSB
 * https://github.com/PaulStoffregen/cores/tree/master/usb_midi
 * 
 * ken.frederick@gmx.de
 * http://kenfrederick.de/
 *
 * Reference:
 * https://www.midi.org/specifications/item/table-1-summary-of-midi-message
 * https://ccrma.stanford.edu/~craig/articles/linuxmidi/misc/essenmidi.html
 * http://digitalsoundandmusic.com/6-1-5-a-closer-look-at-midi-messages/
 */

#ifndef _MIDI_UTILS
#define _MIDI_UTILS


#if !defined(MIDI_INTERFACE) || !defined(CORE_TEENSY_MIDI)
  #include "MIDIUSB.h"
#endif


class MidiUtils {
  private:
    MidiUtils() {}


  public:
    /**
     * MIDI message command.
     * Note-off (key, velocity)
     */
    const static byte NOTE_OFF = 0x80;

    /**
     * MIDI message command.
     * Note-on (key, velocity)
     */
    const static byte NOTE_ON = 0x90;

    /**
     * MIDI message command.
     * Aftertouch/Polyphonic Key Pressure (key, touch)
     */
    const static byte AFTERTOUCH = 0xA0;

    /**
     * MIDI message command.
     * Control change (controller no., controler value)
     */
    const static byte CONTROL_CHANGE = 0xB0;

    /**
     * MIDI message command.
     * Patch/Program change (instrument no., )
     */
    const static byte PATCH_CHANGE = 0xC0;

    /**
     * MIDI message command.
     * Channel Pressure (pressure)
     */
    const static byte PRESSURE = 0xD0;

    /**
     * MIDI message command.
     * Pitch bend (lsb [7 bits], msb [7 bits])
     */
    const static byte PITCH_BEND = 0xE0;

    /**
     * System message command.
     * Start of system exclusive message (variable)
     */
    const static byte MSG_START = 0xF0;

    /**
     * System message command.
     * MIDI Time Code Quarter Frame (Sys Common)
     */
    const static byte TIME_QUART_FRAME = 0xF1;

    /**
     * System message command.
     * Song Position Pointer (Sys Common)
     * This is an internal 14 bit register that holds the number of MIDI beats
     * (1 beat = six MIDI clocks) since the start of the song.
     */
    const static byte SONG_POS = 0xF2;

    /**
     * System message command.
     * Song Select (Sys Common)
     * The Song Select specifies which sequence or song is to be played.
     */
    const static byte SONG_SEL = 0xF3;

    /**
     * System message command.
     * Tune Request (Sys Common)
     * Upon receiving a Tune Request, all analog synthesizers should tune their
     * oscillators.
     */
    const static byte TUNE_REQ = 0xF6;

    /**
     * System message command.
     * End of system exclusive message
     * Used to terminate a System Exclusive dump.
     */
    const static byte MSG_END = 0xF7;

    /**
     * System message command.
     * Timing Clock (Sys Realtime)
     * Sent 24 times per quarter note when synchronization is required
     */
    const static byte CLOCK = 0xF8;

    /**
     * System message command.
     * Start (Sys Realtime)
     * Start the current sequence playing. (This message will be followed with
     * Timing Clocks).
     */
    const static byte START = 0xFA;

    /**
     * System message command.
     * Continue (Sys Realtime)
     * Continue at the point the sequence was Stopped.
     */
    const static byte CONTINUE = 0xFB;

    /**
     * System message command.
     * Stop (Sys Realtime)
     * Stop the current sequence.
     */
    const static byte STOP = 0xFC;

    /**
     * System message command.
     * Active Sensing (Sys Realtime)
     */
    const static byte ACTIVE_SENSE = 0xFE;

    /**
     * System message command.
     * System Reset (Sys Realtime)
     */
    const static byte RESET = 0xFF;


    static void writeUsb(const uint8_t *buffer, size_t size) {
#if !defined(MIDI_INTERFACE) || !defined(CORE_TEENSY_MIDI)
      MidiUSB.write(buffer, size);
#else
      // TODO (frederickk): Implement raw byte writing for Teensy.
#endif
    }
    
    /**
     * Sends 3 byte Midi message.
     * @param type   command type
     * @param data1  first data byte
     * @param data2  second data byte
     */
    void sendUsb(byte type, byte data1, byte data2) {
#if !defined(MIDI_INTERFACE) || !defined(CORE_TEENSY_MIDI)
      // First parameter is the event type (top 4 bits of the command byte).
      // Second parameter is command byte combined with the channel.
      // Third parameter is the first data byte
      // Fourth parameter second data byte
      midiEventPacket_t midiMsg = {type >> 4, type, data1, data2};
      MidiUSB.sendMIDI(midiMsg);
#else
      // TODO (frederickk): Implement for Teensy.
#endif
    }

    /**
     * Triggers Midi note.
     * @param channel  anything between 0-15. Typically reported to the user as 1-16.
     * @param pitch    note number (48 = middle C).
     * @param velocity  note velocity: 64 = normal, 127 = fastest
     */
    static void noteOnUsb(byte channel, byte pitch, byte velocity = 100) {
#if !defined(MIDI_INTERFACE) || !defined(CORE_TEENSY_MIDI)
      midiEventPacket_t noteOn = {0x09, MidiUtils::NOTE_ON | channel, pitch, velocity};
      MidiUSB.sendMIDI(noteOn);
#else
      usbMIDI.sendNoteOn(pitch, velocity, channel);
#endif
    }

    /**
     * Detriggers Midi note.
     * @param channel  anything between 0-15. Typically reported to the user as 1-16.
     * @param pitch    note number (48 = middle C).
     * @param velocity  note velocity: 64 = normal, 127 = fastest
     */
    static void noteOffUsb(byte channel, byte pitch, byte velocity = 0) {
#if !defined(MIDI_INTERFACE) || !defined(CORE_TEENSY_MIDI)
      midiEventPacket_t noteOff = {0x08, MidiUtils::NOTE_OFF | channel, pitch, velocity};
      MidiUSB.sendMIDI(noteOff);
#else
      usbMIDI.sendNoteOff(pitch, velocity, channel);
#endif
    }

    /**
     * Sends control message.
     * @param channel  anything between 0-15. Typically reported to the user as 1-16.
     * @param control  control number number (0-119).
     * @param value  control value (0-127).
     */
    static void controlChangeUsb(byte channel, byte control, byte value) {
#if !defined(MIDI_INTERFACE) || !defined(CORE_TEENSY_MIDI)
      midiEventPacket_t event = {0x0B, MidiUtils::CONTROL_CHANGE | channel, control, value};
      MidiUSB.sendMIDI(event);
#else
      usbMIDI.sendControlChange(control, value, channel);
#endif
    }

    static void midiSendRealTime(byte type) {
      switch (type) {
        case MidiUtils::CLOCK:
        case MidiUtils::START:
        case MidiUtils::CONTINUE:
        case MidiUtils::STOP:
        case MidiUtils::ACTIVE_SENSE:
        case MidiUtils::RESET:
#if !defined(MIDI_INTERFACE) || !defined(CORE_TEENSY_MIDI)
          midiEventPacket_t cmd = {type >> 4, type, 0, 0};
          MidiUSB.sendMIDI(cmd);
#else
        // TODO (frederickk): Confirm Teensy implementation.
        // usbMIDI.sendRealTimeClock(type);
#endif
          break;
        default: // Invalid Real Time marker
          break;
      }
    }

    /**
     * Flushes USB Midi Buffer.
     */
    static void flushUsb() {
#if !defined(MIDI_INTERFACE) || !defined(CORE_TEENSY_MIDI)
      MidiUSB.flush();
#endif
    }
};


#endif
