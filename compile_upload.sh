#!/bin/bash

# Define the base directory
BASE_DIR="/var/lib/jenkins/workspace/git"

# Define the paths for the sketches
SLAVE_LED_PATH="$BASE_DIR/slave_led/slave_led.ino"
MASTER_LED_PATH="$BASE_DIR/master_led/master_led.ino"

# Define the board and port parameters
BOARD="arduino:avr:uno"
SLAVE_PORT="/dev/ttyUSB1"
MASTER_PORT="/dev/ttyUSB0"

# Ensure PATH is set to include arduino-cli installation directory
# export PATH=$PATH:/var/lib/jenkins/workspace/git/bin

./arduino-cli core install arduino:avr

# Compile and upload the slave_led sketch
./arduino-cli compile -b $BOARD $SLAVE_LED_PATH
./arduino-cli upload -b $BOARD -p $SLAVE_PORT $SLAVE_LED_PATH

# Compile and upload the master_led sketch
./arduino-cli compile -b $BOARD $MASTER_LED_PATH
./arduino-cli upload -b $BOARD -p $MASTER_PORT $MASTER_LED_PATH
