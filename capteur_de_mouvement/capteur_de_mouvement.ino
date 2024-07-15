int capteur=2;
int buzzer=4;
int ledV=22;
int ledR=23;
int mesure;
void setup() {
  // put your setup code here, to run once:
pinMode(capteur,INPUT);
pinMode(buzzer,OUTPUT);
pinMode(ledV,OUTPUT);
pinMode(ledR,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(ledV,LOW);
digitalWrite(ledR,LOW);
digitalWrite(buzzer,LOW);
mesure=digitalRead(capteur);
if(mesure==HIGH)
{ digitalWrite(ledV,HIGH);
digitalWrite(ledR,LOW);
digitalWrite(buzzer,HIGH);
Serial.println("objet detecté");
}
if(mesure==LOW){
{digitalWrite(ledV,LOW);
digitalWrite(ledR,HIGH);
digitalWrite(buzzer,LOW);
Serial.println("aucun objet detecté");}
delay(500);}}
