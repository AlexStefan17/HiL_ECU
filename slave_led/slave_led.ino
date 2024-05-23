#include <Wire.h>

#define SLAVE_ADDR 9
#define LB 13
#define HB 12
#define FOG 11

void setup() {
  Wire.begin(SLAVE_ADDR);
  Wire.onRequest(requestEvent);
  Wire.onReceive(receiveEvent);
  pinMode(LB, OUTPUT);
  pinMode(HB, OUTPUT);
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
    digitalWrite(LB, HIGH);
    Serial.println("Low Beam turned on");
  } 
  else if (command == "LowBeam_OFF") {
    digitalWrite(LB, LOW);
    Serial.println("Low Beam turned off");
  }
  else if (command == "HighBeam_ON") {
    digitalWrite(LB, HIGH);
    digitalWrite(HB, HIGH);
    Serial.println("High Beam turned on");
  }
  else if (command == "HighBeam_OFF") {
    digitalWrite(LB, LOW);
    digitalWrite(HB, LOW);
    Serial.println("High Beam turned off");
  }
  else if (command == "Fog_ON") {
    digitalWrite(LB, HIGH);
    digitalWrite(FOG, HIGH);
    Serial.println("Fog Beam turned on");
  }
}
/*
  LB OFF && HB OFF => 0
  LB ON && HB OFF => 1
  LB ON && HB ON => 2
  
*/
void requestEvent() {
  // Check if LED is on, send 1 if it is, otherwise send 0
  int LBState = digitalRead(LB);
  int HBState = digitalRead(HB);
  if (LBState == 0 && HBState == 0) {
    Wire.write(0);
  }
  else if (LBState == 1 && HBState == 0) {
    Wire.write(1);
  }
  else if (LBState == 1 && HBState == 1) {
    Wire.write(2);
  }
}

void loop() {
  // Maintain loop for I2C communication
  delay(50);
}
