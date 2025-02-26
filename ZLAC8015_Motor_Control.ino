#include <Arduino.h>
#include <HardwareSerial.h>

// Define the pins for Serial communication
#define TX_PIN 1
#define RX_PIN 0
#define DE_PIN 2  // Driver Enable pin for RS485
#define RE_PIN 3  // Receiver Enable pin for RS485

// Define the serial connection to ZLAC8015
HardwareSerial ZLAC8015Serial(1);

// Function prototypes
void sendCommand(String command);
void enableRS485Transmit();
void enableRS485Receive();

void setup() {
  // Start the serial communication with the PC
  Serial.begin(9600);

  // Start the serial communication with the ZLAC8015
  ZLAC8015Serial.begin(9600, SERIAL_8N1, RX_PIN, TX_PIN);

  // Set the DE and RE pins as OUTPUT
  pinMode(DE_PIN, OUTPUT);
  pinMode(RE_PIN, OUTPUT);

  // Initialize RS485 in receive mode
  enableRS485Receive();

  // Allow time for the serial ports to initialize
  delay(1000);

  // Send initialization commands to ZLAC8015
  sendCommand("IDLE"); // Example: Set motor to idle state
}

void loop() {
  // Example: Send a command to rotate the motor forward at 50% speed
  sendCommand("MOTOR FORWARD 50");

  // Wait for 2 seconds
  delay(2000);

  // Example: Send a command to stop the motor
  sendCommand("MOTOR STOP");

  // Wait for 2 seconds
  delay(2000);
}

// Function to send a command to the ZLAC8015
void sendCommand(String command) {
  enableRS485Transmit();
  ZLAC8015Serial.println(command);
  delay(100); // Small delay to ensure the command is sent
  enableRS485Receive();
}

// Function to enable RS485 transmit mode
void enableRS485Transmit() {
  digitalWrite(DE_PIN, HIGH);
  digitalWrite(RE_PIN, HIGH);
}

// Function to enable RS485 receive mode
void enableRS485Receive() {
  digitalWrite(DE_PIN, LOW);
  digitalWrite(RE_PIN, LOW);
}