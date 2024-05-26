#! /bin/bash

# ECU
arduino-cli compile -b arduino:avr:uno Desktop/disertatie_code/slave_led/slave_led.ino
arduino-cli upload -b arduino:avr:uno -p /dev/ttyUSB1

# HiL
arduino-cli compile -b arduino:avr:uno Desktop/disertatie_code/master_led/master_led.ino 
arduino-cli upload -b arduino:avr:uno -p /dev/ttyUSB0
arduino-cli monitor -p /dev/ttyUSB0 | tee log.txt
