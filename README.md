<p align="center">
  <img src="https://formation-professionnelle.universite-lyon.fr/var/site/storage/images/3/3/5/0/533-17-fre-FR/Lyon-1-Claude-Bernard.png">
</p>


| **Nom**    | **Prénom** | **Numéro étudiant**                                                                                           |
|:----------|:-----------------------------------------|:---------------------------------------------------------|
| KOCHKAR SHERINE  | Baya | 12018503 |
| SANTONI | Thomas | 12110336 |

# Description du main.cpp
Le fichier main.cpp est composé de différentes parties : 
- 1) Appels aux différentes fonctions de base pour montrer qu'elles fonctionnent
- 2) Démonstration de Voronoï, on affiche pour chaque noeud un couple (distance de la librairie la plus proche, id de la librairie la plus proche)
- 3) Démonstration de Voronoï pondéré par le coût de livraison au km, on affiche pour chaque noeud un couple (coût total de la livraison la moins cher (distance * coût au km), id de la librairie correspondante)

# Fichiers de configuration
| Paramètre    | Nom du fichier                                                                                           |
|:----------|:--------------------------------------------------------------------------------------------------|
| **Hauteur des différents noeuds**  | ```./data/hauteurs.txt``` |
| **Librairies et leurs coût au km**  | ```./data/librairies.txt``` |

## Format pour le fichier des hauteurs :
```bash
nbLignes nbColonnes
hauteurNoeud0 hauteurNoeud1 hauteurNoeud2 ...
hauteurNoeud3 ...
```

## Format pour le fichier des librairies :
```bash
nbLibrairies
numLigneL1 numColonneL1 coutAuKmL1
numLigneL2 numColonneL2 coutAuKmL2
...
```
