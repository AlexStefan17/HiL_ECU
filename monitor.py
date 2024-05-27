import subprocess
import sys

def monitor_and_log():
    # Start the arduino-cli monitor command
    process = subprocess.Popen(['arduino-cli', 'monitor', '-p', '/dev/ttyUSB0'],
                               stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

    with open('log.txt', 'w') as log_file:
        while True:
            line = process.stdout.readline()
            if line:
                print(line, end='')  # Print to console
                log_file.write(line)  # Write to log file
                log_file.flush()

                # Check for the end-of-tests signal
                if "All tests completed" in line:
                    print("All tests completed. Exiting...")
                    process.terminate()
                    break

            if process.poll() is not None:
                break

if __name__ == "__main__":
    monitor_and_log()
