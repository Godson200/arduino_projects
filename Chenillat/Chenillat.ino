/*int led1 = 3;
int led2 = 4;
int led3 = 5;
int led4 = 6;
int led5 = 7;
int led6 = 8;
int led7 = 9;
int bouton1 = 12;
int bouton2 = 13;
int valeur = 0;
int mode = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(bouton1, INPUT_PULLUP);
  pinMode(bouton2, INPUT_PULLUP);
}

void loop() {
  // Check button states
  if (digitalRead(bouton1) == LOW) {
    delay(200); // debounce delay
    mode++;
    if (mode > 2) {
      mode = 0;
    }
    while (digitalRead(bouton1) == LOW); // Wait for button release
  }

  if (digitalRead(bouton2) == LOW) {
    delay(200); // debounce delay
    mode--;
    if (mode < 0) {
      mode = 2;
    }
    while (digitalRead(bouton2) == LOW); // Wait for button release
  }

  // Switch case to handle different modes
  switch (mode) {
    case 0:
      // Mode 0: Sequential lighting
      for (int i = 3; i <= 9; i++) {
        allumage(i, 500);
      }
      for (int i = 9; i >= 3; i--) {
        allumage(i, 500);
      }
      break;
    
    case 1:
      // Mode 1: Alternate lighting
      for (int i = 3; i <= 9; i += 2) {
        allumage(i, 500);
      }
      for (int i = 4; i <= 9; i += 2) {
        allumage(i, 500);
      }
      break;
    
    case 2:
      // Mode 2: Blink all LEDs
      for (int i = 3; i <= 9; i++) {
        digitalWrite(i, HIGH);
      }
      delay(500);
      for (int i = 3; i <= 9; i++) {
        digitalWrite(i, LOW);
      }
      delay(500);
      break;
  }
  if(digitalRead(bouton1==HIGH)
  {Serial.println("bouton1");}
  if(digitalRead(bouton2==HIGH)
  {Serial.println("bouton2");}
}

void allumage(int pin, int duration) {
  digitalWrite(pin, HIGH);
  delay(duration);
  digitalWrite(pin, LOW);
  delay(duration);
}*/

int led1 = 3;
int led2 = 4;
int led3 = 5;
int led4 = 6;
int led5 = 7;
int led6 = 8;
int led7 = 9;
int bouton1 = 12;
int bouton2 = 13;
int bouton3 = 11;

void setup() {
  // Initialisation de la communication série et des broches
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(bouton1, INPUT_PULLUP);
  pinMode(bouton2, INPUT_PULLUP);
  pinMode(bouton3, INPUT_PULLUP);
}

void loop() {
  // Vérification de l'état des boutons
  if (digitalRead(bouton1) == LOW) {
    delay(200); // Anti-rebond
    while (digitalRead(bouton1) == LOW); // Attendre que le bouton soit relâché
    unsigned long startTime = millis();
    while (millis() - startTime < 5000) { // Exécute pendant 5 secondes
      // Allumage séquentiel des LEDs
      for (int i = 3; i <= 9; i++) {
        allumage(i, 500);
      }
      for (int i = 9; i >= 3; i--) {
        allumage(i, 500);
      }
    }
  }

  if (digitalRead(bouton2) == LOW) {
    delay(200); // Anti-rebond
    while (digitalRead(bouton2) == LOW); // Attendre que le bouton soit relâché
    unsigned long startTime = millis();
    while (millis() - startTime < 5000) { // Exécute pendant 5 secondes
      // Clignotement simultané de toutes les LEDs
      for (int i = 3; i <= 9; i++) {
        digitalWrite(i, HIGH);
      }
      delay(500);
      for (int i = 3; i <= 9; i++) {
        digitalWrite(i, LOW);
      }
      delay(500);
    }
  }

  if (digitalRead(bouton3) == LOW) {
    delay(200); // Anti-rebond
    while (digitalRead(bouton3) == LOW); // Attendre que le bouton soit relâché
    unsigned long startTime = millis();
    while (millis() - startTime < 5000) { // Exécute pendant 5 secondes
      // Clignotement alterné des LEDs
      for (int i = 3; i <= 9; i += 2) {
        digitalWrite(i, HIGH);
      }
      delay(500);
      for (int i = 3; i <= 9; i += 2) {
        digitalWrite(i, LOW);
      }
      for (int i = 4; i <= 9; i += 2) {
        digitalWrite(i, HIGH);
      }
      delay(500);
      for (int i = 4; i <= 8; i += 2) {
        digitalWrite(i, LOW);
      }
    }
  }
}

void allumage(int pin, int duration) {
  digitalWrite(pin, HIGH);
  delay(duration);
  digitalWrite(pin, LOW);
  delay(duration);
}
