#include <Arduino.h>
#include <ModbusMaster.h>
#include <ZLAC8015.h>

// Define the pins for Serial communication
#define TX_PIN 1
#define RX_PIN 0

// Create the ModbusMaster instances
ModbusMaster node1;
ModbusMaster node2;

// Create the ZLAC8015 instances
ZLAC8015 motor1(node1, 1);  // Modbus ID 1
ZLAC8015 motor2(node2, 2);  // Modbus ID 2

void setup() {
  // Start the serial communication with the PC
  Serial.begin(9600);

  // Start the serial communication with the ZLAC8015 motor drivers
  Serial1.begin(9600, SERIAL_8N1, RX_PIN, TX_PIN);

  // Initialize the Modbus nodes and motor drivers
  motor1.begin();
  motor2.begin();
  motor1.enable();
  motor2.enable();
  motor1.setVelocityMode();
  motor2.setVelocityMode();
}

void loop() {
  // Example: Set motor RPMs
  motor1.setRPM(1000);
  motor2.setRPM(1500);

  // Wait for 2 seconds
  delay(2000);

  // Example: Stop the motors
  motor1.setRPM(0);
  motor2.setRPM(0);

  // Wait for 2 seconds
  delay(2000);
}