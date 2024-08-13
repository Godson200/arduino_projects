#include <BluetoothSerial.h>
#include <ESP32Servo.h>

BluetoothSerial Serialbt;
Servo servo;
int servopin = 18;
int relaispin = 2;
int ventpin = 21;

void setup() {

  Serial.begin(115200);
  Serialbt.begin("Ma_Maison");
  servo.attach(servopin); // Correction: remplacer `Servo.attach` par `servo.attach`
  pinMode(relaispin, OUTPUT);
  pinMode(ventpin, OUTPUT);
  digitalWrite(relaispin,LOW);
  servo.write(0);
  digitalWrite(ventpin,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (Serialbt.available()) {
    char c = Serialbt.read();
    if (c == '0') {
      digitalWrite(relaispin, LOW);
    } 
    else if (c == '1') {
      digitalWrite(relaispin, HIGH);
    } 
    else if (c == '2') {
      servo.write(180); // Correction: utiliser `servo.write` pour contrôler le servo
    } 
    else if (c == '3') {
      servo.write(0); // Correction: même changement ici pour `servo.write`
    } 
    else if (c == '4') {
      digitalWrite(ventpin, HIGH);
    } 
    else if (c == '5') {
      digitalWrite(ventpin, LOW);
    }
  }
}
