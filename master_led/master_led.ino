#include <Wire.h>

#define SLAVE_ADDR 9

int x = 0; // Variable to be modified by the slave
bool testsCompleted = false; // Flag to track if tests are completed

void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("I2C Master Demonstration");
}


void loop() {
  if (!testsCompleted) {
    testLowBeamOn(2000);
    testLowBeamOff(2000);
    testHighBeamOn(2000);
    testHighBeamOff(2000);
    testFogOn(2000);
    testFogOff(2000);

    // Signal the end of tests
    Serial.println("All tests completed");

    // Set the flag to true after all tests are done
    testsCompleted = true;
  }

  // Halt further execution
  while (testsCompleted) {
    // Do nothing, effectively stopping further loop execution
  }
}

void sendMessage(String command) {
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(command.c_str());
  Wire.endTransmission();
  Serial.println("Command sent: " + command);
}

void testLowBeamOn(int time) {
  int expectedResponse = 1;
  String command = "LowBeam_ON";

  // Send the command
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(command.c_str());
  Wire.endTransmission();
  Serial.println("Command sent: " + command);

  // Request data from slave
  Wire.requestFrom(SLAVE_ADDR, 1); // Request data from slave

  while (Wire.available()) {
    int receivedData = Wire.read(); // Read data from slave
    x = receivedData; // Update variable x with received data
    Serial.println();
    Serial.println("###########");
    Serial.println("Test testLowBeamOn");
    Serial.println("###########");
    Serial.println("Received data from slave: " + String(x)); // Print received data
    Serial.println("Expected response: " + String(expectedResponse)); // Debug
    if (receivedData == expectedResponse) {
      Serial.println("LB is ON");
      Serial.println("###########");
      Serial.println("Test passed");
      Serial.println("###########");
    } else {
      Serial.println("###########");
      Serial.println("LB is OFF");
      Serial.println("###########");
      Serial.println("Test failed");
      Serial.println("###########");

    }
  }
  delay(time);
}
// pune test name sa apara acolo la print

void testLowBeamOff(int time) {
  int expectedResponse = 0;
  String command = "LowBeam_OFF";
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(command.c_str());
  Wire.endTransmission();
  Serial.println("Command sent: " + command);

  // Request data from slave
  Wire.requestFrom(SLAVE_ADDR, 1); // Request data from slave

  while (Wire.available()) {
    int receivedData = Wire.read(); // Read data from slave
    x = receivedData; // Update variable x with received data
    Serial.println();
    Serial.println("###########");
    Serial.println("Test testLowBeamOff");
    Serial.println("###########");
    Serial.println("Received data from slave: " + String(x)); // Print received data
    Serial.println("Expected response: " + String(expectedResponse)); // Debug
    if (receivedData == expectedResponse) {
      Serial.println("LB is OFF");
      Serial.println("###########");
      Serial.println("Test passed");
      Serial.println("###########");
    } else {
      Serial.println("###########");
      Serial.println("LB is ON");
      Serial.println("###########");
      Serial.println("Test failed");
      Serial.println("###########");

    }
  }
  delay(time);
}

void testHighBeamOn(int time) {
  int expectedResponse = 2;
  String command = "HighBeam_ON";

  // Send the command
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(command.c_str());
  Wire.endTransmission();
  Serial.println("Command sent: " + command);

  // Request data from slave
  Wire.requestFrom(SLAVE_ADDR, 1); // Request data from slave

  while (Wire.available()) {
    int receivedData = Wire.read(); // Read data from slave
    x = receivedData; // Update variable x with received data
    Serial.println();
    Serial.println("###########");
    Serial.println("Test testHighBeamOn");
    Serial.println("###########");
    Serial.println("Received data from slave: " + String(x)); // Print received data
    Serial.println("Expected response: " + String(expectedResponse)); // Debug
    if (receivedData == expectedResponse) {
      Serial.println("HB is ON");
      Serial.println("###########");
      Serial.println("Test passed");
      Serial.println("###########");
    } else {
      Serial.println("###########");
      Serial.println("HB is OFF");
      Serial.println("###########");
      Serial.println("Test failed");
      Serial.println("###########");

    }
  }
  delay(time);
}

void testHighBeamOff(int time) {
  int expectedResponse = 0;
  String command = "HighBeam_OFF";

  // Send the command
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(command.c_str());
  Wire.endTransmission();
  Serial.println("Command sent: " + command);

  // Request data from slave
  Wire.requestFrom(SLAVE_ADDR, 1); // Request data from slave

  while (Wire.available()) {
    int receivedData = Wire.read(); // Read data from slave
    x = receivedData; // Update variable x with received data
    Serial.println();
    Serial.println("###########");
    Serial.println("Test testHighBeamOff");
    Serial.println("###########");
    Serial.println("Received data from slave: " + String(x)); // Print received data
    Serial.println("Expected response: " + String(expectedResponse)); // Debug
    if (receivedData == expectedResponse) {
      Serial.println("HB is OFF");
      Serial.println("###########");
      Serial.println("Test passed");
      Serial.println("###########");
    } else {
      Serial.println("###########");
      Serial.println("HB is ON");
      Serial.println("###########");
      Serial.println("Test failed");
      Serial.println("###########");

    }
  }
  delay(time);
}

void testFogOn(int time) {
  int expectedResponse = 3;
  String command = "Fog_ON";

  // Send the command
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(command.c_str());
  Wire.endTransmission();
  Serial.println("Command sent: " + command);

  // Request data from slave
  Wire.requestFrom(SLAVE_ADDR, 1); // Request data from slave

  while (Wire.available()) {
    int receivedData = Wire.read(); // Read data from slave
    x = receivedData; // Update variable x with received data
    Serial.println();
    Serial.println("###########");
    Serial.println("Test testFogOn");
    Serial.println("###########");
    Serial.println("Received data from slave: " + String(x)); // Print received data
    Serial.println("Expected response: " + String(expectedResponse)); // Debug
    if (receivedData == expectedResponse) {
      Serial.println("Fog is ON");
      Serial.println("###########");
      Serial.println("Test passed");
      Serial.println("###########");
    } else {
      Serial.println("###########");
      Serial.println("Fog is OFF");
      Serial.println("###########");
      Serial.println("Test failed");
      Serial.println("###########");

    }
  }
  delay(time);
}

void testFogOff(int time) {
  int expectedResponses[] = {0}; // Expected responses for fog off
  int expectedResponseSize = sizeof(expectedResponses) / sizeof(expectedResponses[0]);
  String command = "Fog_OFF";

  sendMessage(command);

  // Request data from slave
  Wire.requestFrom(SLAVE_ADDR, 1); // Request data from slave

  while (Wire.available()) {
    int receivedData = Wire.read(); // Read data from slave
    x = receivedData; // Update variable x with received data
    Serial.println();
    Serial.println("###########");
    Serial.println("Test testFogOff");
    Serial.println("###########");
    Serial.println("Received data from slave: " + String(x)); // Print received data

    // Check if the received data is in the expected responses
    if (isValueInArray(receivedData, expectedResponses, expectedResponseSize)) {
      Serial.println("Fog is OFF");
      Serial.println("###########");
      Serial.println("Test passed");
      Serial.println("###########");
    } else {
      Serial.println("###########");
      Serial.println("Fog is ON");
      Serial.println("###########");
      Serial.println("Test failed");
      Serial.println("###########");
    }
  }
  delay(time);
}

void testHBNegativeTest(int time) {
  int expectedResponses[] = {0}; // Expected responses for fog off
  int expectedResponseSize = sizeof(expectedResponses) / sizeof(expectedResponses[0]);
  String command = "Fog_OFF";

  sendMessage(command);

  // Request data from slave
  Wire.requestFrom(SLAVE_ADDR, 1); // Request data from slave

  while (Wire.available()) {
    int receivedData = Wire.read(); // Read data from slave
    x = receivedData; // Update variable x with received data
    Serial.println();
    Serial.println("###########");
    Serial.println("Test testHBNegativeTest");
    Serial.println("###########");
    Serial.println("Received data from slave: " + String(x)); // Print received data

    // Check if the received data is in the expected responses
    if (isValueInArray(receivedData, expectedResponses, expectedResponseSize)) {
      Serial.println("Fog is OFF");
      Serial.println("###########");
      Serial.println("Test passed");
      Serial.println("###########");
    } else {
      Serial.println("###########");
      Serial.println("Fog is ON");
      Serial.println("###########");
      Serial.println("Test failed");
      Serial.println("###########");
    }
  }
  delay(time);
}

// Function to check if a value is in the array
bool isValueInArray(int value, int array[], int size) {
  for (int i = 0; i < size; i++) {
    if (array[i] == value) {
      return true; // Value found in the array
    }
  }
  return false; // Value not found in the array
}
