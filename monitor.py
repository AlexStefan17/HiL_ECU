import subprocess
import time

def monitor_and_log():
    try:
        # Start the cat and tee command in a single line
        process = subprocess.Popen(
            'cat /dev/ttyUSB0 | tee -a /var/lib/jenkins/workspace/git/HiL_ECU/log.txt',
            shell=True,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            universal_newlines=True,
            bufsize=1
        )
        print("Started monitoring /dev/ttyUSB0 and logging to log.txt")
    except Exception as e:
        print("Error starting subprocess:", e)
        return

    while True:
        line = process.stdout.readline()
        if line:
            print("Output:", line.strip())  # Print to console

            # Check for the end-of-tests signal
            if "All tests completed" in line:
                print("All tests completed.")
                process.terminate()
                break

        if process.poll() is not None:
            print("Process ended")
            break

        time.sleep(1)  # Add a small delay to avoid busy-waiting

    # Capture and print any error output
    error_output = process.stderr.read()
    if error_output:
        print("Error Output:", error_output)

if __name__ == "__main__":
    monitor_and_log()
