


// L298N Motor Driver - Correct Configuration
// L298N requires digital pins for direction, PWM for speed

// Motor A (Left side)
const int enA = 10;    // PWM pin for Motor A speed
const int in1 = 2;   // Direction control 1
const int in2 = 3;   // Direction control 2

// Motor B (Right side)  
const int enB = 11;    // PWM pin for Motor B speed
const int in3 = 4;    // Direction control 3
const int in4 = 5;    // Direction control 4
const int sensorPin = 9;

void setup() {
  Serial.begin(9600);
  
  // Initialize all motor control pins as outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  pinMode(sensorPin, INPUT);
  
  Serial.println("L298N Motor Driver Started");
  Serial.println("Waiting for sensor to read 0...");
}

void loop() {
  int sensorValue = digitalRead(sensorPin);
  //int sensorAnalogValue = analogRead(sensorPin);
  
  Serial.print("Sensor: ");
  //Serial.print(sensorAnalogValue);
  Serial.print(sensorValue);
  Serial.print(" | Motors: ");
  
  if (sensorValue == 0 ) { 
    stopMotors();
    Serial.println("STOPPED | obstacle detectected");

  } else {
    // Rotate all motors forward
    moveForward();
    Serial.println("MOVING FORWARD | No obstacle");
  }
  
  delay(500);
}

void moveForward() {
// Move both motors forward
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
analogWrite(enA, 70);   // Motor A speed


digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
analogWrite(enB, 70);
}


void stopMotors() {
  // Stop both motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}








//By Harsh


// /*
//  * ARDUINO IR SENSOR MOTOR CONTROL SYSTEM
//  * Object Detection with Speed Control
//  * 
//  * WIRING:
//  * 
//  * L298N MOTOR DRIVER:
//  * Left Motor:  enA=5, in1=12, in2=11
//  * Right Motor: enB=6, in3=8, in4=7
//  * 
//  * IR SENSOR:
//  * VCC -> 5V
//  * GND -> GND
//  * OUT -> Pin 9
//  * 
//  * BEHAVIOR:
//  * - No object detected: Motors move forward
//  * - Object detected: Motors stop
//  */

// // ================================
// // PIN DEFINITIONS
// // ================================

// // Left Motor (Motor A)
// const int enA = 5;      // PWM speed control
// const int in1 = 12;     // Direction control 1
// const int in2 = 11;     // Direction control 2

// // Right Motor (Motor B)
// const int enB = 11;      // PWM speed control
// const int in3 = 8;      // Direction control 3
// const int in4 = 7;      // Direction control 4

// // IR Sensor
// const int sensorPin = 9; // Digital IR sensor

// // ================================
// // SPEED SETTINGS
// // ================================

// int motorSpeed = 75;    // Change this value (0-255) to control speed
// int speedOffsetA = 0;    // Adjust if left motor is slower (try 10, 20, etc.)
// int speedOffsetB = 0;    // Adjust if right motor is slower (try 10, 20, etc.)

// // ================================
// // FUNCTION DECLARATIONS
// // ================================

// void moveForward();
// void stopMotors();
// void setMotorSpeeds(int leftSpeed, int rightSpeed);

// // ================================
// // SETUP FUNCTION - RUNS ONCE
// // ================================

// void setup() {
//   // Start serial communication for debugging
//   Serial.begin(9600);
//   Serial.println("Arduino Motor Control System Started");
//   Serial.println("=====================================");
  
//   // Set motor control pins as outputs
//   pinMode(enA, OUTPUT);
//   pinMode(in1, OUTPUT);
//   pinMode(in2, OUTPUT);
//   pinMode(enB, OUTPUT);
//   pinMode(in3, OUTPUT);
//   pinMode(in4, OUTPUT);
  
//   // Set sensor pin as input
//   pinMode(sensorPin, INPUT);
  
//   // Initialize motors in stopped state
//   stopMotors();
  
//   // Display initial settings
//   Serial.print("Motor Speed: ");
//   Serial.println(motorSpeed);
//   Serial.print("Left Offset: ");
//   Serial.println(speedOffsetA);
//   Serial.print("Right Offset: ");
//   Serial.println(speedOffsetB);
//   Serial.println("Waiting for sensor input...");
//   Serial.println();
  
//   delay(1000); // Wait for system to stabilize
// }

// // ================================
// // MAIN LOOP - RUNS CONTINUOUSLY
// // ================================

// void loop() {
//   // Read IR sensor (0 = object detected, 1 = clear)
//   int sensorValue = digitalRead(sensorPin);
  
//   // Display sensor reading
//   Serial.print("Sensor: ");
//   Serial.print(sensorValue);
//   Serial.print(" | ");
  
//   // Check for obstacle
//   if (sensorValue == 0) {
//     // OBJECT DETECTED - STOP MOTORS
//     stopMotors();
//     Serial.println("OBSTACLE DETECTED - STOPPED");
//   } else {
//     // NO OBSTACLE - MOVE FORWARD
//     moveForward();
//     Serial.println("PATH CLEAR - MOVING FORWARD");
//   }
  
//   // Small delay before next reading
//   delay(100);
// }

// // ================================
// // MOTOR CONTROL FUNCTIONS
// // ================================

// /**
//  * Move both motors forward with calibrated speeds
//  */
// void moveForward() {
//   // Calculate individual motor speeds with offsets
//   int leftSpeed = motorSpeed + speedOffsetA;
//   int rightSpeed = motorSpeed + speedOffsetB;
  
//   // Ensure speeds are within valid range (0-255)
//   leftSpeed = constrain(leftSpeed, 0, 255);
//   rightSpeed = constrain(rightSpeed, 0, 255);
  
//   // Set the calculated speeds
//   setMotorSpeeds(leftSpeed, rightSpeed);
  
//   // Display motor speeds for debugging
//   Serial.print("  Left Motor: ");
//   Serial.print(leftSpeed);
//   Serial.print(" | Right Motor: ");
//   Serial.println(rightSpeed);
// }

// /**
//  * Set individual speeds for both motors
//  * @param leftSpeed - Speed for left motor (0-255)
//  * @param rightSpeed - Speed for right motor (0-255)
//  */
// void setMotorSpeeds(int leftSpeed, int rightSpeed) {
// //  Left Motor (Motor A) - Forward direction

//   digitalWrite(in1, LOW);
//   digitalWrite(in2, HIGH);


//   analogWrite(in4, leftSpeed);
  
//  // Right Motor (Motor B) - Forward direction
//   digitalWrite(in3, HIGH);
//   digitalWrite(in4, LOW);
//   analogWrite(enB, rightSpeed);
// }

// /**
//  * Stop both motors immediately
//  */
// void stopMotors() {
//   // Set all direction pins to LOW to brake
//   digitalWrite(in1, LOW);
//   digitalWrite(in2, LOW);
//   digitalWrite(in3, LOW);
//   digitalWrite(in4, LOW);
  
//   // Set speed to 0
//   analogWrite(enA, 0);
//   analogWrite(enB, 0);
// }

// /**
//  * Test function to check motor wiring (optional)
//  * Run this in setup() to test your connections
//  */
// void motorTest() {
//   Serial.println("Testing motors...");
  
//   // Test forward motion
//   Serial.println("Forward for 2 seconds...");
//   moveForward();
//   delay(2000);
  
//   // Stop
//   Serial.println("Stopping...");
//   stopMotors();
//   delay(1000);
  
//   Serial.println("Motor test complete!");
// }