#ifndef _GRAPH
#define _GRAPH

#include <string>
#include "distPred.h"

class Graphe
{
    private:
        /**
         * Grille représentant les altitudes des différents sommets
        */
        int * grilleHauteur;

        /**
         * tableau représentant les couleurs des différents sommets
        */ 
        couleur * couleurs;
        
        /**
         * Nombre de lignes du graphe
         */
        int lignes;

        /**
         * Nombre de colonnes du graphe
        */
        int colonnes;

    public:
        /**
             * Grille dans laquelle est stockée pour chaque noeud, un couple (distance de la librairie la plus proche,
             * id de la librairie la plus proche)
            */
        std::tuple<int, int> * grilleVoronoi;

        /**
         * Constructeur
         */
        Graphe();

        /**
        * Initialise un graphe à partir d'un fichier (cf énoncé)
        * @param fichier fichier dans lequel est stocké le graphe à initialisé
        */
        Graphe(std::string fichier);

        /**
        * Destructeur
        */
        ~Graphe();

        /**
        * Initialise le graphe (dans un tableau 1D de taille largeur * hauteur)
        * @param largeur du graphe
        * @param hauteur du graphe
        */
        void initialise(int largeur, int hauteur);

        /**
        * Opérateur d'affectation
         * @param grp graphe à copier
         * @return graphe actuel (*this)
        */
        Graphe& operator = (const Graphe & grp);

        /**
         * Donne l'indice global d'un sommet à partir de ses indices de ligne et de colonne
         * @param ligne indice de ligne du sommet
         * @param colonne indice de colonne du sommet
         * @return indice global du sommet
         */
        int accesIndiceGlobal(int idLigne, int idColonne) const;

        /**
         * Donne l'altitude d'un sommet à partir de son indice global
         * @param indiceGlobal indice global du sommet (calculable avec la fonction accesIndiceGlobal())
         * @return altitude du sommet
         */
        int accesAltitude(int indiceGlobal) const;

        /**
         * Donne l'indice global du voisin nord du sommet donné en paramètre
         * Précondition : le voisin pour l'orientation donnée existe
         * @param indiceGlobal indice global du sommet dont on veut connaître le voisin
         * @param orientation 0 = Nord, 1 = Sud, 2 = Est, 3 = Ouest
         * @return indice global du voisin du sommet donné en paramètre
         */
        int accesIndiceGlobalVoisin(int indiceGlobal, int orientation) const;

        /**
         * Modifie l'altitude d'un sommet à partir d'un indice global
         * @param indiceGlobal indice global du sommet dont on veut modifier l'altitude
         * @param altitude altitude a affecté au sommet correspondant à indiceGlobal
         */
        void modificationAltitudeSommet(int indiceGlobal, int altitude);

        /**
         * Affiche la grille de hauteur
         */
        void affichageGrilleHauteur();

        /**
         * Applique l'algorithme de Dijkstra
         * @param idNoeud indice de noeud
         * @return PCD : tableau [indice de Noeud] de paire(distance, indice de Nœud))
         */
        void dijkstra(int idNoeud, distPred * tab);

        /**
         * Enregistre et affiche pour chaque point de la grille l'indice de la librairie dont il est la plus proche
         * (ainsi que la distance)
         * format d'affichage :
         * (distance, id de la librairie la plus proche)
         * @param graphesLibrairies tableau contenant les tableau de distPred pour chaque librairie (calculés avec la
         * méthode dijkstra
         * @param nbLibrairies : nombre de librairies (todo : à remplacer par une donnée membre)
         * @param idLibrairies : indices globaux des librairies  (todo : à remplacer par une donnée membre)
         */
        void voronoi(distPred ** graphesLibrairies, int nbLibrairies, int * idLibrairies);

        /**
         * Enregistre et affiche pour chaque point de la grille l'indice de la librairie avec le coût de livraison le
         * plus faible (distance * coût au Km)
         * format d'affichage :
         * (coût, id de la librairie avec le coût de livraison le plus faible)
         * @param graphesLibrairies tableau contenant les tableau de distPred pour chaque librairie (calculés avec la
         * méthode dijkstra
         * @param nbLibrairies : nombre de librairies (todo : à remplacer par une donnée membre)
         * @param idLibrairies : indices globaux des librairies  (todo : à remplacer par une donnée membre)
         */
        void voronoiLivraison(distPred ** graphesLibrairies, int nbLibrairies, std::tuple<int, int> * idLibrairiesCout);

        int calculDist(int idDepart, int idCible) const;

        bool estVoisin(int idDepart, int idCible) const;

        /**
         * Retourne le nombre de colonnes de graphe
         * @return colonnes : nombre de colonnes de graphe
         */
        int getColonnes();

        /**
         * Retourne le nombre de lignes de graphe
         * @return colonnes : nombre de lignes de graphe
         */
        int getLignes();

        /**
         * TODO :
         * Récupère les emplacements des librairies dans un fichier :
         * 1 ligne par librairie sous le format :
         * numLigne nuCcolonne coutLivraison
         * numLigne numColonne coutLivraison
         * ...
         * puis stocke les emplacements de ces librairies dans une donnée membre idlibrairiesCout
         * (stocke également le nombre de librairies dans une donnée membre nbLibrairies)
         * */
         void recupLibrairies(std::string fichier);
};

#endif