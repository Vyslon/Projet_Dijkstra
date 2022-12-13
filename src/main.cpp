#include "graphe.h"
#include "distPred.h"
#include <iostream>

int main()
{
    Graphe grp("test");
    std::cout << "Les indices globales des noeuds :" << std::endl;
    grp.affichageGrilleHauteur();

    const int nbLibrairies = 3;
    distPred * tab = nullptr;
    int idlibrairies [nbLibrairies] = {0, 6, 7};
    distPred ** graphesLibrairies = new distPred*[nbLibrairies];

    for (int i = 0; i < nbLibrairies; i++)
    {
        tab = new distPred[grp.getLignes()*grp.getColonnes()];
        grp.dijkstra(idlibrairies[i], tab);
        graphesLibrairies[i] = tab;
    }
    grp.voronoi(graphesLibrairies, nbLibrairies, idlibrairies);

    //
    std::printf("\n");

    for (int i = 0; i < nbLibrairies; i++) {
        tab = graphesLibrairies[i];
        for (int i = 0; i < grp.getLignes(); i++) {
            for (int j = 0; j < grp.getColonnes(); j++) {
                std::cout << tab[grp.getColonnes() * i + j].distance << "  ";
            }
            std::cout << std::endl;

        }

        std::cout << "Les couleurs des noeuds après Dijkstra:" << std::endl;
        for (int i = 0; i < grp.getLignes(); i++) {
            for (int j = 0; j < grp.getColonnes(); j++) {
                std::cout << getCouleur(tab[grp.getColonnes() * i + j].clr) << "  ";
            }
            std::cout << std::endl;

        }
    }
}
