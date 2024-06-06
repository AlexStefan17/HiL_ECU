# Use an official Ubuntu base image
FROM ubuntu:20.04

# Install dependencies
RUN apt-get update && apt-get install -y \
    git \
    curl \
    python3 \
    python3-pip \
    tar \
    && rm -rf /var/lib/apt/lists/*

# Set the working directory
WORKDIR /workspace

# Copy the project files into the container
COPY . /workspace

# Copy arduino-cli binary from the repository
COPY arduino-cli /usr/local/bin/arduino-cli

# Ensure scripts are executable
RUN chmod +x /workspace/compile_upload.sh /workspace/monitor_serial.sh

# Set the entrypoint
ENTRYPOINT ["/bin/bash"]

# Run compile_upload.sh script when the container starts
CMD ["bash", "/workspace/compile_upload.sh"]
