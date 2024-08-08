# Système de Gestion de Capteurs avec Relais et Servomoteur

Ce projet Arduino utilise plusieurs capteurs pour gérer un relais et un servomoteur. Les capteurs inclus sont une photorésistance, un capteur de fumée, un capteur de présence (PIR) et un capteur ultrasonique.

## Matériel Utilisé

- Arduino Uno
- Photorésistance (LDR)
- Capteur de fumée
- Capteur de présence (PIR)
- Capteur ultrasonique (HC-SR04)
- Relais
- Servomoteur
- Résistances et câblage de connexion

## Connexions des Broches

- **Photorésistance (LDR)** : Connexion à l'entrée analogique `A0`
- **Capteur de fumée** : Connexion à l'entrée analogique `A1`
- **Capteur de présence (PIR)** : Connexion à l'entrée numérique `2`
- **Capteur ultrasonique** :
  - **Trig** : Connexion à la broche numérique `9`
  - **Echo** : Connexion à la broche numérique `10`
- **Relais** : Connexion à la sortie numérique `3`
- **Servomoteur** : Connexion à la sortie PWM `11`

## Description du Code

Le code Arduino lit les valeurs de plusieurs capteurs et utilise ces données pour contrôler un relais et un servomoteur.

### Bibliothèques Utilisées

- `Servo.h` : Pour contrôler le servomoteur.
- `Ultrasonic.h` : Pour lire les données du capteur ultrasonique.

### Seuils de Capteurs

- **Photorésistance** : `500`
- **Capteur de fumée** : `300`
- **Capteur de présence (PIR)** : `HIGH`
- **Capteur ultrasonique** : `50 cm`

### Logique de Contrôle

1. **Relais** :
   - S'allume si la lumière est faible, la fumée est détectée, une présence est détectée, ou si un objet est détecté à moins de 50 cm.
   - S'éteint sinon.

2. **Servomoteur** :
   - Se déplace à 90 degrés si une présence est détectée.
   - Se déplace à 0 degré sinon.

### Fonctionnement

Le programme lit les valeurs des capteurs, les affiche via le moniteur série pour le débogage, et applique la logique de contrôle du relais et du servomoteur en conséquence. 

### Installation et Utilisation

1. Connectez tous les composants aux broches spécifiées.
2. Téléversez le code sur votre Arduino à l'aide de l'IDE Arduino.
3. Ouvrez le moniteur série pour voir les valeurs des capteurs en temps réel.
4. Observez le comportement du relais et du servomoteur en fonction des lectures des capteurs.
