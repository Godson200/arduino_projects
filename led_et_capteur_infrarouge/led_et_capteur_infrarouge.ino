#include <IRremote.h>

int rec_pin = 11;
IRrecv irrecv(rec_pin);
decode_results results;

int pin1 = 3;
int pin2 = 4;
int pin3 = 5;
int pin4 = 6;
int pin5 = 7;
int pin6 = 8;
int pin7 = 9;
int pin8 = 10;
int pin9 = 12;
int i = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  // Initialize serial communication
  irrecv.enableIRIn();
  for (i = 3; i <= 12; i++) {
    pinMode(i, OUTPUT);  // Set all pins as output
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume();
  }
  delay(10);
  
  all();
  delay(2000);
  clean();
  delay(2000);
  carre();
  delay(2000);
}

void all() {
  for (i = 3; i <= 12; i++) {
    digitalWrite(i, HIGH);
  }
  delay(1000);
  for (i = 3; i <= 12; i = i + 2) {
    digitalWrite(i, LOW);
  }
}

void clean() {
  for (i = 3; i <= 12; i++) {
    digitalWrite(i, LOW);
  }
}

void carre() {
  digitalWrite(3, HIGH);
  delay(100);
  digitalWrite(3, LOW);
  delay(100);
  digitalWrite(4, HIGH);
  delay(100);
  digitalWrite(4, LOW);
  delay(100);
  digitalWrite(5, HIGH);
  delay(100);
  digitalWrite(5, LOW);
  delay(100);
  digitalWrite(6, HIGH);
  delay(100);
  digitalWrite(6, LOW);
  delay(100);
  digitalWrite(8, HIGH);
  delay(100);
  digitalWrite(8, LOW);
  delay(100);
  digitalWrite(9, HIGH);
  delay(100);
  digitalWrite(9, LOW);
  delay(100);
  digitalWrite(10, HIGH);
  delay(100);
  digitalWrite(10, LOW);
  delay(100);
  digitalWrite(11, HIGH);
  delay(100);
  digitalWrite(11, LOW);
  delay(1000);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
}
