#!/bin/bash

# Define the GitHub repository URL with SSH
REPO_URL="git@github.com:AlexStefan17/HiL_ECU.git"

# Define the branch you want to clone
BRANCH="main"

# Define the directory where the repository should be cloned
CLONE_DIR="/var/lib/jenkins/workspace/git/HiL_ECU"

# Remove the existing directory if it exists
rm -rf "$CLONE_DIR"

cd /var/lib/jenkins/workspace/git

# Clone the specified branch of the repository into the specified directory
git clone --branch $BRANCH $REPO_URL

cd /var/lib/jenkins/workspace/git/HiL_ECU
tar -xzf arduino-cli_0.35.3_Linux_64bit.tar.gz arduino-cli  

# Run the compile and upload script
echo "Run compile_upload.sh"
bash compile_upload.sh

# Run the monitor script
echo "monitor_serial.sh"
bash monitor_serial.sh
