#ifndef _GRAPH
#define _GRAPH

#include <string>

class Graphe
{
    private:
        /**
         */
        int * grilleHauteur;
        /**
         */
        int L;
        int C;

    public:
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
        int accesIndiceGlobal(int ligne, int colonne) const;

        /**
         * Donne l'altitude d'un sommet à partir de son indice global
         * @param indiceGlobal indice global du sommet (calculable avec la fonction accesIndiceGlobal())
         * @return altitude du sommet
         */
        int accesAltitude(int indiceGlobal) const;

        /**
         * Donne l'indice global du voisin nord du sommet donné en paramètre
         * Précondition : le voisin nord existe (ligne > 0)
         * @param ligne indice de ligne du sommet dont on veut connaître le voisin nord
         * @param colonne indice de colonne du sommet dont on veut connaître le voisin nord
         * @return indice global du voisin nord du sommet donné en paramètre
         */
        int accesIndiceGlobalVoisinNord(int ligne, int colonne) const;

        /**
        * Donne l'indice global du voisin sud du sommet donné en paramètre
        * Précondition : le voisin sud existe (ligne < L - 1, L étant le nombre de lignes)
        * @param ligne indice de ligne du sommet dont on veut connaître le voisin sud
        * @param colonne indice de colonne du sommet dont on veut connaître le voisin sud
        * @return indice global du voisin sud du sommet donné en paramètre
        */
        int accesIndiceGlobalVoisinSud(int ligne, int colonne) const;

        /**
         * Donne l'indice global du voisin est du sommet donné en paramètre
         * Précondition : le voisin est existe (colonne < C - 1, C étant le nombre de colonnes)
         * @param ligne indice de ligne du sommet dont on veut connaître le voisin est
         * @param colonne indice de colonne du sommet dont on veut connaître le voisin est
         * @return indice global du voisin est du sommet donné en paramètre
         */
        int accesIndiceGlobalVoisinEst(int ligne, int colonne) const;

        /**
         * Donne l'indice global du voisin ouest du sommet donné en paramètre
         * Précondition : le voisin ouest existe (colonne > 0)
         * @param ligne indice de ligne du sommet dont on veut connaître le voisin ouest
         * @param colonne indice de colonne du sommet dont on veut connaître le voisin ouest
         * @return indice global du voisin ouest du sommet donné en paramètre
         */
        int accesIndiceGlobalVoisinOuest(int ligne, int colonne) const;

        /**
         * Modifie l'altitude d'un sommet à partir d'un indice global
         * @param indiceGlobal indice global du sommet dont on veut modifier l'altitude
         */
        void modificationAltitudeSommet(int indiceGlobal);

        /**
         * Affiche la grille de hauteur
         */
        void affichageGrilleHauteur();
};

#endif