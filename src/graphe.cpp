#include "graphe.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <queue>

Graphe::Graphe(std::string fichier)
{
    std::ifstream fichierGraphe;
    fichierGraphe.open("../data/" + fichier + ".txt");
    int nbColonnes;
    int nbLignes;

    if (fichierGraphe.is_open())
    {
        fichierGraphe >> nbColonnes >> nbLignes;
        initialise(nbColonnes, nbLignes);

        for (int i = 0; i < nbLignes; i++)
        {
            for (int j = 0; j < nbColonnes; j++)
            {
                fichierGraphe >> grilleHauteur[i * nbColonnes + j];
            }
        }
    }
    else
    {
        std::cout << "Erreur : d'ouverture du fichier : " << fichier << ".txt" << std::endl;
    }
}

void Graphe::initialise(int largeur, int hauteur)
{
    colonnes = largeur;
    lignes = hauteur;
    grilleHauteur = new int[largeur * hauteur];
}

Graphe::~Graphe()
{
    delete [] grilleHauteur;
}

void Graphe::affichageGrilleHauteur()
{
    for (int i = 0; i < lignes * colonnes; i++)
    {
        std::printf("%d ", grilleHauteur[i]);
    }
}

int Graphe::accesIndiceGlobal(int idLigne, int idColonne) const
{
    return idLigne * lignes + idColonne;
}

int Graphe::accesAltitude(int indiceGlobal) const
{
    return grilleHauteur[indiceGlobal];
}

int Graphe::accesIndiceGlobalVoisin(int indiceGlobal, int orientation) const
{
    if (indiceGlobal % colonnes == colonnes - 1 && orientation == 2)
        return -1;
    else
    if (indiceGlobal % colonnes == 0 && orientation == 3)
        return -1;
    else
    if (indiceGlobal < colonnes && orientation == 0)
        return -1;
    else
    if (indiceGlobal >= (lignes - 1) * colonnes && orientation == 1)
        return -1;

    int res;

    switch (orientation)
    {
        case 0:
            res = indiceGlobal - colonnes;
            break;
        case 1:
            res = indiceGlobal + colonnes;
            break;
        case 2:
            res = indiceGlobal + 1;
            break;
        case 3:
            res = indiceGlobal - 1;
            break;
    }

    return res;
}

void Graphe::modificationAltitudeSommet(int indiceGlobal, int altitude)
{
    grilleHauteur[indiceGlobal] = altitude;
}

Graphe& Graphe::operator= (const Graphe & grp)
{
    // TODO
    return *this;
}

// initialiser comme il faut tab (tout le monde est blanc sauf le noeud sur lequel je commence
// idNoeud est l'indice global du noeud
// distances : + infini a tout le monde sauf, 0 sur le noeud de départ et indice du précèdent = 0
void Graphe::dijkstra(int idNoeud, distPred * tab)
{
    //std::stack<int> noeudsGris;

    // TODO
    class comp {
        public:
            bool operator() (const distPred * n1, const distPred * n2) const { return n1->distance > n2->distance; }
    };

    std::priority_queue<distPred*, std::vector<distPred*>, comp> noeudsGris;

    for (int i = 0; i < lignes; i++)
    {
        for (int j = 0; j < colonnes; j++)
        {
            tab[i * colonnes + j].clr = blanc;
            tab[i * colonnes + j].id = i * colonnes + j;
        }
    }
    tab[idNoeud].clr = gris;
    tab[idNoeud].distance = 0;
    noeudsGris.push(&tab[idNoeud]);

    int indiceNoeudMin;
    int currNoeud;
    while (!noeudsGris.empty())
    {
        // TODO : A voir si c'est gênant de retirer les éléments de noeudsGris
        //while (!noeudsGris.empty())
        //{
            /*
            currNoeudGris = noeudsGris.top();
            noeudsGris.pop();
            currDist = tab[currNoeudGris].distance;
            if (currDist < distMin)
            {
                distMin = currDist;
                indiceNoeudMin = currNoeudGris;
            }*/
        indiceNoeudMin = noeudsGris.top()->id;
        noeudsGris.pop();
        //}
        for (int i = 0; i < 4; i++)
        {
            int voisin = accesIndiceGlobalVoisin(indiceNoeudMin, i);
            if (voisin != -1 && tab[voisin].clr == blanc)
            {
                tab[voisin].clr = gris;
                noeudsGris.push(&tab[voisin]);
                tab[voisin].idPredecesseur = indiceNoeudMin;
                tab[voisin].distance = calculDist(indiceNoeudMin, voisin) + tab[indiceNoeudMin].distance;
            }
        }

        tab[indiceNoeudMin].clr = noir;
    }
    // TODO : while (il reste des noeuds gris (sans file de priorité puis avec))
    // TODO : utiliser stack puis file de priorité
}

int Graphe::calculDist(int idDepart, int idCible) const
{
    return sqrt(1 + (grilleHauteur[idDepart] - grilleHauteur[idCible]) * (grilleHauteur[idDepart] - grilleHauteur[idCible]));
}