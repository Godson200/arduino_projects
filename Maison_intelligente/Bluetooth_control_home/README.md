# Projet de Commande d'Appareils via Bluetooth avec ESP32

## Description

Ce projet utilise une carte ESP32 pour contrôler plusieurs appareils (un relais, un servo-moteur, et un ventilateur) via une connexion Bluetooth. L'utilisateur peut envoyer des commandes depuis un appareil Bluetooth (comme un smartphone) pour activer ou désactiver ces appareils.

## Matériel Nécessaire

- 1 Carte ESP32
- 1 Relais
- 1 Servo-moteur
- 1 Ventilateur
- Fils de connexion
- Breadboard

## Schéma de Connexion

1. Connecter le relais à la broche digitale 2 de l'ESP32.
2. Connecter le servo-moteur à la broche digitale 18 de l'ESP32.
3. Connecter le ventilateur à la broche digitale 21 de l'ESP32.
4. Relier toutes les connexions GND au GND de l'ESP32.

## Explication du Code

1. if (Serialbt.available()) : Vérifie si une commande a été reçue via Bluetooth.
2. char c = Serialbt.read(); : Lit la commande reçue et la stocke dans la variable c.
3. if...else if... : Ces conditions vérifient la valeur de c et effectuent l'action correspondante :
- '0' : Désactive le relais.
- '1' : Active le relais.
- '2' : Positionne le servo à 180 degrés.
- '3' : Positionne le servo à 0 degrés.
- '4' : Active le ventilateur.
- '5' : Désactive le ventilateur.
## Fonctionnement Global
Le projet permet de contrôler un relais, un servo-moteur, et un ventilateur via des commandes Bluetooth. Selon la commande envoyée, l'ESP32 active ou désactive les appareils connectés, permettant ainsi une commande sans fil pratique et efficace.

## Auteur
GUEDJE Godson