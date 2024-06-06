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

# Install arduino-cli
RUN tar -xzf /workspace/arduino-cli_0.35.3_Linux_64bit.tar.gz -C /usr/local/bin \
    && rm /workspace/arduino-cli_0.35.3_Linux_64bit.tar.gz

# Ensure scripts are executable
# RUN chmod +x /workspace/compile_upload.sh /workspace/monitor_serial.sh /workspace/jenkins_build.sh

# Set the entrypoint
ENTRYPOINT ["/bin/bash"]
