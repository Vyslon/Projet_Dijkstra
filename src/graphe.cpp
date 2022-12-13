#include "graphe.h"
#include "distPred.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <queue>
#include <tuple>

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
    fichierGraphe.close();
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
    lignes = grp.lignes;
	colonnes = grp.colonnes;

	delete[] grilleHauteur;
	delete[] couleurs;

	grilleHauteur = new int[lignes * colonnes];
	couleurs = new couleur[lignes * colonnes];
	
	for (int i = 0; i < lignes * colonnes; i++)
	{
		grilleHauteur[i] = grp.grilleHauteur[i];
		couleurs[i] = grp.couleurs[i];
	}
    return *this;
}

// initialiser comme il faut tab (tout le monde est blanc sauf le noeud sur lequel je commence
// idNoeud est l'indice global du noeud
// distances : + infini a tout le monde sauf, 0 sur le noeud de départ et indice du précèdent = 0
void Graphe::dijkstra(int idNoeud, distPred * tab)
{
    // Ici, on fait en sorte que les noeuds les moins éloignés sont en haut de la file de priorité (le sens de la
    // comparaison est inversé par rapport à une fonction de comparaison classique car la file de priorité cherche à
    // trier par ordre décroissant par défaut
    struct myComparator
    {
        int operator()(const std::tuple<int, int>& t1,
                       const std::tuple<int, int>& t2)
        {
            return std::get<0>(t1) > std::get<0>(t2);
        }
    };

    // Tuples : <distance, id>
    std::priority_queue<std::tuple<int, int>,
            std::vector<std::tuple<int, int>>,
            myComparator> noeudsGris;

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
    noeudsGris.push(std::make_tuple(0, idNoeud));

    int indiceNoeudMin;
    int currNoeud = 0;
    while (!noeudsGris.empty())
    {
        if (indiceNoeudMin > 0)
            currNoeud = indiceNoeudMin;

        indiceNoeudMin = std::get<1>(noeudsGris.top());

        for (int i = 0; i < 4; i++)
        {
            int voisin = accesIndiceGlobalVoisin(indiceNoeudMin, i);
            if ((voisin != -1 && tab[voisin].clr == blanc))
            {
                    tab[voisin].clr = gris;
                    tab[voisin].idPredecesseur = indiceNoeudMin;
                    tab[voisin].distance = calculDist(indiceNoeudMin, voisin) + tab[indiceNoeudMin].distance;
                    noeudsGris.push(std::make_tuple(tab[voisin].distance, voisin));
            }
        }

        tab[indiceNoeudMin].clr = noir;
        noeudsGris.pop();
    }
}

int Graphe::calculDist(int idDepart, int idCible) const
{
    return sqrt(1 + (grilleHauteur[idDepart] - grilleHauteur[idCible]) * (grilleHauteur[idDepart] - grilleHauteur[idCible]));
}

bool Graphe::estVoisin(int idDepart, int idCible) const
{
    if (idDepart == idCible - 1 && (idCible % colonnes) != 0)
        return true;
    else if (idDepart == idCible + 1 && (idDepart % colonnes) != 0)
        return true;
    else if (idDepart == idCible - colonnes && idCible >= colonnes)
        return true;
    else if (idDepart == idCible + colonnes && idCible < (lignes * (colonnes - 1)))
        return true;
    else
        return idDepart == idCible;
} // 0 et 3 voisins

int Graphe::getColonnes(){
    return colonnes;
}

int Graphe::getLignes(){
    return lignes;
}

void Graphe::voronoi(distPred ** graphesLibrairies, int nbLibrairies, int * idLibrairies)
{
    grilleVoronoi = new std::tuple<int, int>[lignes * colonnes];

    // Faire tourner les Dijkstra depuis main.cpp
    // Stocker sur un tuple de int, en tant qu'attribut de la classe + affichage
    for (int i = 0; i < lignes * colonnes; i++)
    {
        // distance et id de la librairie la plus proche
        // (distance, id)
        std::tuple<int, int> distId = std::make_tuple(INT_MAX, INT_MAX);
        for (int j = 0; j < nbLibrairies; j++)
        {
            if (graphesLibrairies[j][i].distance < std::get<0>(distId))
                distId = std::make_tuple(graphesLibrairies[j][i].distance, idLibrairies[j]);
        }
        grilleVoronoi[i] = std::make_tuple(std::get<0>(distId), std::get<1>(distId));
        if (i % colonnes == 0)
            std::printf("\n");

        std::printf("(%d, %d)  ", std::get<0>(distId), std::get<1>(distId));
    }
}