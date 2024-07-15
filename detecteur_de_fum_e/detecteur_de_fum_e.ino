#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
int ledV=8;
int ledJ=4; 
int ledR=2;
int buzzer=13;
int capf=A0;
int mesure=0;

void setup() {
  // put your setup code here, to run once:
lcd.init();
lcd.backlight();
lcd.setCursor(0,0);
lcd.print("Bonjour");
pinMode(ledV,OUTPUT);
pinMode(ledJ,OUTPUT);
pinMode(ledR,OUTPUT);
pinMode(buzzer,OUTPUT);
pinMode(capf,INPUT);
digitalWrite(ledV, LOW);
digitalWrite(ledJ, LOW);
digitalWrite(ledR, LOW);
digitalWrite(buzzer, LOW);
delay(2000);
lcd.clear();

}

void loop() {
  // put your main code here, to run repeatedly:
mesure=analogRead(capf);
Serial.print ("valeur mesurée :");
Serial.println(mesure);
lcd.setCursor(1,1);
lcd.print(mesure);
lcd.setCursor(0,0);
if (mesure < 80 ) {
digitalWrite(ledV, HIGH);
digitalWrite(ledJ, LOW);
digitalWrite(ledR, LOW);
digitalWrite(buzzer, LOW);
lcd.print(" AIR CORRECT");
}
else
{
if (mesure < 140 ) {
digitalWrite(ledV, LOW);
digitalWrite(ledJ, HIGH);
digitalWrite(ledR, LOW);
digitalWrite(buzzer, LOW);
lcd.print(" AIR MALSAIN");
}
else
{
digitalWrite(ledV, LOW);
digitalWrite(ledJ, LOW);
digitalWrite(ledR, HIGH);
digitalWrite(buzzer, HIGH);
lcd.print("ALERTE POLLUTION");
}
}

delay(1000);
lcd.clear();
}
