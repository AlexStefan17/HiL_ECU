#!/bin/bash

# Define the serial port and log file
SERIAL_PORT="/dev/ttyUSB0"
LOG_FILE="/var/lib/jenkins/workspace/git/HiL_ECU/log.txt"

# Start reading from the serial port
cat "$SERIAL_PORT" | while IFS= read -r line
do
    # Append the line to the log file
    echo "$line" | tee -a "$LOG_FILE"
    
    # Check if the line contains "All tests completed"
    if [[ "$line" == *"All tests completed"* ]]; then
        echo "Detected completion message. Stopping..."
        pkill -P $$ cat
        break
    fi
done
