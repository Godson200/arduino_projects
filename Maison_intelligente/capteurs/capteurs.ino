#include <Servo.h>
#include <Ultrasonic.h>

// Pin definitions
const int ldrPin = A0;              // Photorésistance
const int smokePin = A1;            // Capteur de fumée
const int pirPin = 2;               // Capteur de présence
const int relayPin = 3;             // Relais
const int trigPin = 9;              // Capteur ultrason trig
const int echoPin = 10;             // Capteur ultrason echo
const int servoPin = 11;            // Servo

// Threshold values
const int lightThreshold = 500;     // Seuil pour la photorésistance
const int smokeThreshold = 300;     // Seuil pour le capteur de fumée
const int presenceThreshold = HIGH; // Seuil pour le capteur de présence (PIR)
const int distanceThreshold = 50;   // Seuil pour le capteur ultrason (cm)

// Create objects
Servo myServo;
Ultrasonic ultrasonic(trigPin, echoPin);

void setup() {
  pinMode(ldrPin, INPUT);
  pinMode(smokePin, INPUT);
  pinMode(pirPin, INPUT);
  pinMode(relayPin, OUTPUT);
  myServo.attach(servoPin);
  
  Serial.begin(9600);
}

void loop() {
  // Read sensor values
  int lightLevel = analogRead(ldrPin);
  int smokeLevel = analogRead(smokePin);
  int presence = digitalRead(pirPin);
  int distance = ultrasonic.read(CM);

  // Print sensor values for debugging
  Serial.print("Light: ");
  Serial.print(lightLevel);
  Serial.print(" | Smoke: ");
  Serial.print(smokeLevel);
  Serial.print(" | Presence: ");
  Serial.print(presence);
  Serial.print(" | Distance: ");
  Serial.println(distance);

  // Relay control logic
  if (lightLevel < lightThreshold || smokeLevel > smokeThreshold || presence == presenceThreshold || distance < distanceThreshold) {
    digitalWrite(relayPin, HIGH); // Turn on the relay
  } else {
    digitalWrite(relayPin, LOW);  // Turn off the relay
  }

  // Servo control logic
  if (presence == presenceThreshold) {
    myServo.write(90); // Move servo to 90 degrees
  } else {
    myServo.write(0);  // Move servo to 0 degrees
  }

  delay(1000); // Delay for readability
}
