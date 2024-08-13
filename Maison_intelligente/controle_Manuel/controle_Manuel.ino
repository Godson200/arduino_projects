int lampe1 = 2; // Pin associée à lampe1
int lampe2 = 3; // Pin associée à lampe2
int lampe3 = 4; // Pin associée à lampe3
int ventpin = 5; // Pin associée au ventilateur

int bouton1 = 6; // Pin associée à bouton1
int bouton2 = 7; // Pin associée à bouton2
int bouton3 = 8; // Pin associée à bouton3
int boutonvent = 9; // Pin associée à boutonvent

bool lampe1State = false; // État de lampe1
bool lampe2State = false; // État de lampe2
bool lampe3State = false; // État de lampe3
bool ventState = false; // État du ventilateur

void setup() {
  pinMode(lampe1, OUTPUT);
  pinMode(lampe2, OUTPUT);
  pinMode(lampe3, OUTPUT);
  pinMode(ventpin, OUTPUT);
  
  pinMode(bouton1, INPUT_PULLUP);
  pinMode(bouton2, INPUT_PULLUP);
  pinMode(bouton3, INPUT_PULLUP);
  pinMode(boutonvent, INPUT_PULLUP);
  
  digitalWrite(lampe1, LOW);
  digitalWrite(lampe2, LOW);
  digitalWrite(lampe3, LOW);
  digitalWrite(ventpin, LOW);
}

void loop() {
  // Gestion du bouton 1 pour lampe 1
  if (digitalRead(bouton1) == LOW) {
    delay(200); // Anti-rebond
    lampe1State = !lampe1State; // Inverse l'état de la lampe
    digitalWrite(lampe1, lampe1State ? HIGH : LOW); // Allume ou éteint la lampe en fonction de l'état
    while(digitalRead(bouton1) == LOW); // Attendre que le bouton soit relâché
  }

  // Gestion du bouton 2 pour lampe 2
  if (digitalRead(bouton2) == LOW) {
    delay(200); // Anti-rebond
    lampe2State = !lampe2State; // Inverse l'état de la lampe
    digitalWrite(lampe2, lampe2State ? HIGH : LOW); // Allume ou éteint la lampe en fonction de l'état
    while(digitalRead(bouton2) == LOW); // Attendre que le bouton soit relâché
  }

  // Gestion du bouton 3 pour lampe 3
  if (digitalRead(bouton3) == LOW) {
    delay(200); // Anti-rebond
    lampe3State = !lampe3State; // Inverse l'état de la lampe
    digitalWrite(lampe3, lampe3State ? HIGH : LOW); // Allume ou éteint la lampe en fonction de l'état
    while(digitalRead(bouton3) == LOW); // Attendre que le bouton soit relâché
  }

  // Gestion du bouton pour le ventilateur
  if (digitalRead(boutonvent) == LOW) {
    delay(200); // Anti-rebond
    ventState = !ventState; // Inverse l'état du ventilateur
    digitalWrite(ventpin, ventState ? HIGH : LOW); // Allume ou éteint le ventilateur en fonction de l'état
    while(digitalRead(boutonvent) == LOW); // Attendre que le bouton soit relâché
  }
}
