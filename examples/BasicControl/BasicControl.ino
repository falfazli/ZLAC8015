#include <Arduino.h>
#include <ModbusMaster.h>
#include <ZLAC8015.h>

// Define the pins for Serial communication
#define TX_PIN 1
#define RX_PIN 0

// Create the ModbusMaster instance
ModbusMaster node;

// Create the ZLAC8015 instance
ZLAC8015 motor(node, 1);  // Modbus ID 1

void setup() {
  // Start the serial communication with the PC
  Serial.begin(9600);

  // Start the serial communication with the ZLAC8015
  Serial1.begin(9600, SERIAL_8N1, RX_PIN, TX_PIN);

  // Initialize the Modbus node and motor driver
  motor.begin();
  motor.enable();
  motor.setVelocityMode();
}

void loop() {
  // Example: Set motor RPM
  motor.setRPM(1000);

  // Wait for 2 seconds
  delay(2000);

  // Example: Stop the motor
  motor.setRPM(0);

  // Wait for 2 seconds
  delay(2000);
}