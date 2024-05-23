#include <Wire.h>

#define SLAVE_ADDR 9

int x = 0; // Variable to be modified by the slave

void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("I2C Master Demonstration");
}

void loop() {
  testLowBeamOn(5000);
  testLowBeamOff(1000);
  while (true) {

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
