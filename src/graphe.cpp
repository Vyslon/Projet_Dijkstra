#include "graphe.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

Graphe::Graphe(std::string fichier)
{
    std::ifstream fichierGraphe;
    fichierGraphe.open("data/" + fichier + ".txt");
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

int Graphe::accesIndiceGlobalVoisinNord(int ligne, int colonne) const
{
    return grilleHauteur[accesIndiceGlobal(ligne - 1, colonne)]
}

int Graphe::accesIndiceGlobalVoisinSud(int ligne, int colonne) const
{
    return grilleHauteur[accesIndiceGlobal(ligne + 1, colonne)]
}

int Graphe::accesIndiceGlobalVoisinEst(int ligne, int colonne) const
{
    return grilleHauteur[accesIndiceGlobal(ligne, colonne + 1)]
}

int Graphe::accesIndiceGlobalVoisinOuest(int ligne, int colonne) const
{
    return grilleHauteur[accesIndiceGlobal(ligne, colonne - 1)]
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
// distances : + infini a tout le monde sauf, 0 sur le noeud de départ et indice du précèdent = 0
void Graphe::dijkstra(int idNoeud, distPred * tab)
{
    for (int i = 0; i < lignes; i++)
    {
        for (int j = 0; j < colonnes; j++)
        {
            tab[i * colonnes + j].clr = blanc;
        }
    }
    tab[idNoeud].clr = gris;
    // TODO : while (il reste des noeuds gris (sans file de priorité puis avec))
    // TODO : utiliser stack puis file de priorité
}