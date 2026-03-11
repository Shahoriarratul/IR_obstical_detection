


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
  
  // delay();
}

void moveForward() {
// Move both motors forward
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
analogWrite(enA, 75);   // Motor A speed


digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
analogWrite(enB, 75);
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



