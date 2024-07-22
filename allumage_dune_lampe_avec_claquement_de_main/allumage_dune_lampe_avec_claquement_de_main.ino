int pinD = 7;
int valeur = 0;
bool activation = 0;
int relay = 8;
unsigned long lastClapTime = 0;
unsigned long clapInterval = 3000; // Intervalle maximal entre deux claps en millisecondes
int clapCount = 0;

void setup() {
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
  pinMode(pinD, INPUT);
}

void loop() {
  valeur = digitalRead(pinD);
  unsigned long currentTime = millis();
  
  if (valeur == 1) {
    // Si un clap est détecté, vérifiez le temps écoulé depuis le dernier clap
    if (currentTime - lastClapTime <= clapInterval) {
      clapCount++;
    } else {
      clapCount = 1;
    }
    
    lastClapTime = currentTime;
    
    // Si deux claps sont détectés en moins d'une seconde, changez l'état de la lampe
    if (clapCount == 2) {
      activation = !activation;
      digitalWrite(relay, activation ? HIGH : LOW);
      clapCount = 0; // Réinitialiser le compteur de claps
    }
    
    delay(100); // Anti-rebond
  }
  
  Serial.println(activation);
}
