/**
 * name.c
 */

#if defined (__MK20DX256__) || defined (__MK20DX128__) || defined (__MKL26Z64__)
  #include "usb_names.h"

  #define MIDI_NAME   {'P', 'r', 'o', 's', 't', '-', 'M'}
  #define MIDI_NAME_LEN 7

  // Do not change this part. This exact format is required by USB.
  struct usb_string_descriptor_struct usb_string_product_name = {
    2 + MIDI_NAME_LEN * 2,
    3,
    MIDI_NAME
  };
#endif
