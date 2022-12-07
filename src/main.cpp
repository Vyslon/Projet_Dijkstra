#include "graphe.h"
#include "distPred.h"
#include <iostream>

int main()
{
    Graphe grp("test");
    grp.affichageGrilleHauteur();
    distPred * tab = new distPred[9];
    grp.dijkstra(0, tab);
    std::cout << std::endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << tab[i * j].clr;
        }
        std::cout << std::endl;
    }
}