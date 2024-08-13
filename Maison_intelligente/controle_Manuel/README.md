
# Projet de Commande Manuel de la maison 

## Description

Ce projet consiste à contrôler trois lampes et un mini-ventilateur à l'aide de boutons poussoirs. Chaque bouton est associé à une lampe ou au ventilateur, permettant de les allumer ou de les éteindre indépendamment. Une pression sur un bouton allume l'appareil associé, et une deuxième pression l'éteint. Le projet utilise une carte Arduino, et le code gère les rebonds des boutons ainsi que l'état des appareils.

## Matériel Nécessaire

- 1 Carte Arduino (Uno, Mega, etc.)
- 3 LEDs ou Lampes
- 1 Mini-ventilateur
- 4 Résistances (220 ohms pour les LEDs, valeurs adaptées pour les lampes et le ventilateur)
- 4 Boutons poussoirs
- Fils de connexion
- Breadboard

## Schéma de Connexion

1. Connecter chaque LED ou lampe aux broches digitales 2, 3, et 4 de l'Arduino, avec une résistance en série pour limiter le courant.
2. Connecter le mini-ventilateur à la broche digitale 5 de l'Arduino, avec une résistance adaptée.
3. Connecter les boutons poussoirs aux broches digitales 6, 7, 8, et 9. Utiliser les résistances pull-up internes de l'Arduino.
4. Relier toutes les connexions GND au GND de l'Arduino.

## Explication du Code
### Initialisation des Pins
1. Dans la fonction setup(), les broches de l'Arduino sont configurées :

- pinMode(lampe1, OUTPUT) : Définit la broche associée à la lampe1 comme sortie.
- pinMode(bouton1, INPUT_PULLUP) : Définit la broche associée au bouton1 comme entrée avec une résistance pull-up interne, ce qui permet de détecter les appuis sur le bouton.
### Gestion des Boutons et des Appareils
La logique principale se trouve dans la fonction loop(). Pour chaque appareil (lampe ou ventilateur), le code vérifie si le bouton correspondant est pressé.

1. Anti-rebond
delay(200) : Ajoute un délai de 200 millisecondes après la détection d'un appui sur un bouton pour ignorer les rebonds mécaniques du bouton. Cela évite les multiples détections lors d'une seule pression.
2. Inversion de l'État
lampe1State = !lampe1State; : Cette ligne inverse l'état de la lampe1. Si elle est allumée, elle s'éteint et vice versa.
3. Opérateur Ternaire
- digitalWrite(lampe1, lampe1State ? HIGH : LOW); :
- Explication : L'opérateur ternaire est une manière concise d'écrire une condition. Dans ce cas, si lampe1State est true, alors la broche de la lampe1 est mise à HIGH (ce qui allume la lampe). Si lampe1State est false, la broche est mise à LOW (ce qui éteint la lampe).
- Syntaxe : condition ? valeur_si_vrai : valeur_si_faux;
- Application : Ici, lampe1State est la condition. Si elle est vraie, HIGH est sélectionné; sinon, LOW est sélectionné.
4. Boucle while
while(digitalRead(bouton1) == LOW); : Cette boucle attend que le bouton soit relâché avant de continuer à vérifier d'autres boutons. Cela garantit que chaque pression sur le bouton est traitée une seule fois, évitant ainsi les répétitions non désirées.
## Fonctionnement Global
Chaque bouton contrôle indépendamment l'état d'une lampe ou du ventilateur. En appuyant sur un bouton, l'appareil correspondant s'allume ou s'éteint, en fonction de son état précédent. Le code gère les rebonds des boutons pour garantir un comportement stable et prévisible.

## Auteur
GUEDJE Godson