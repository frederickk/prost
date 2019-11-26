#!/bin/sh

# Update boards
arduino-cli board list

# Install core for SAMD (Arduino MKR1000)
arduino-cli core install arduino:samd
arduino-cli board listall mkr

# Compile
arduino-cli compile --fqbn arduino:samd:mkr1000 ./MidiHostessReader/MidiHostessReader

# Upload
arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:samd:mkr1000 ./MidiHostessReader/MidiHostessReader


