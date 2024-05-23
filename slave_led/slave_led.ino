#include <Wire.h>

#define SLAVE_ADDR 9
#define LED_PIN 13

void setup() {
  Wire.begin(SLAVE_ADDR);
  Wire.onRequest(requestEvent);
  Wire.onReceive(receiveEvent);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("I2C Slave Demonstration");
}

void receiveEvent(int numBytes) {
  String command = "";
  while (Wire.available()) {
    char c = Wire.read();
    command += c;
  }
  Serial.print("Received command: ");
  Serial.println(command);
  
  // Process the received command immediately
  if (command == "LowBeam_ON") {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Low Beam turned on");
  } 
  else if (command == "LowBeam_OFF") {
    digitalWrite(LED_PIN, LOW);
    Serial.println("Low Beam turned off");
  }
  else if (command == "HighBeam_ON") {
    digitalWrite(LED_PIN, LOW);
    // digitalWrite()
  }
  
}

void requestEvent() {
  // Check if LED is on, send 1 if it is, otherwise send 0
  int ledState = digitalRead(LED_PIN);
  Wire.write(ledState);
}

void loop() {
  // Maintain loop for I2C communication
  delay(50);
}
