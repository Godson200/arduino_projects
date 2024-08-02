# Contrôle de LEDs avec Arduino
<img src="montage .jpg">
Ce projet Arduino permet de contrôler une série de LEDs à l'aide de trois boutons poussoirs. Chaque bouton déclenche un comportement spécifique des LEDs, qui dure au moins 5 secondes. Les comportements sont les suivants :

1. **Bouton 1** : Allume les LEDs de manière séquentielle.
2. **Bouton 2** : Fait clignoter toutes les LEDs simultanément.
3. **Bouton 3** : Fait clignoter les LEDs de manière alternée.

## Matériel requis

- 7 LEDs
- 3 boutons poussoirs
- Résistances pour les LEDs et les boutons (valeurs typiques : 220Ω pour les LEDs, 10kΩ pour les boutons)
- Une carte Arduino (par exemple, Arduino Uno)
- Câblage et une breadboard

## Schéma de connexion

| Composant | Broche Arduino |
|-----------|----------------|
| LED 1     | 3              |
| LED 2     | 4              |
| LED 3     | 5              |
| LED 4     | 6              |
| LED 5     | 7              |
| LED 6     | 8              |
| LED 7     | 9              |
| Bouton 1  | 12             |
| Bouton 2  | 13             |
| Bouton 3  | 11             |

**Note** : Assurez-vous d'ajouter des résistances appropriées aux LEDs et aux boutons poussoirs.
## Fonctionnement du code
- Bouton 1 : Allume les LEDs de manière séquentielle.
- Bouton 2 : Fait clignoter toutes les LEDs simultanément.
- Bouton 3 : Fait clignoter les LEDs de manière alternée.
## Fonction allumage : Allume et éteint une LED spécifique avec une durée spécifiée.
## Utilisation
- Chargez le code sur votre carte Arduino.
- Connectez les LEDs et les boutons aux broches appropriées selon le schéma de connexion.
- Appuyez sur un bouton pour voir les LEDs réagir selon le comportement programmé.
## Auteur
GUEDJE Godson