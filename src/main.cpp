#include "graphe.h"
#include "distPred.h"
#include <iostream>

int main()
{
    Graphe grp("hauteurs");
    std::cout << "Les indices globales des noeuds :" << std::endl;
    grp.affichageGrilleHauteur();

    std::printf("\nId global : %d (pour 2ème ligne et 0ème colonne)\n", grp.accesIndiceGlobal(2, 0));

    std::printf("Altitude à l'indice global 1 : %d\n", grp.accesAltitude(1));

    std::printf("Indice global du voisin nord du noeud 4 : %d\n", grp.accesIndiceGlobalVoisin(4, 0));
    std::printf("Indice global du voisin sud du noeud 4 : %d\n", grp.accesIndiceGlobalVoisin(4, 1));
    std::printf("Indice global du voisin est du noeud 4 : %d\n", grp.accesIndiceGlobalVoisin(4, 2));
    std::printf("Indice global du voisin ouest du noeud 4 : %d\n", grp.accesIndiceGlobalVoisin(4, 3));

    grp.modificationAltitudeSommet(1, 15);
    std::printf("Altitude à l'indice global 1 : %d\n", grp.accesAltitude(1));


    grp.modificationAltitudeSommet(1, 12);
    /**
     * Exemple Voronoi (en prenant uniquement en compte les distances)
     * */
    // Les emplacements ainsi que les couts des librairies sont chargées à parrtir de fichier                                                     std::make_tuple(7, 3)};
    grp.recupLibrairies("librairies");

    std::printf("\nDiagramme de Voronoï en prenant uniquement en compte les distances\n");
    distPred * tab = nullptr;

    distPred ** graphesLibrairies = new distPred*[grp.getNbLibrairies()];

    // Calcule dijkstra pour toutes les librairies
    for (int i = 0; i < grp.getNbLibrairies(); i++)
    {
        tab = new distPred[grp.getLignes()*grp.getColonnes()];
        grp.dijkstra(std::get<0>(grp.idLibrairiesCout[i]), tab);
        graphesLibrairies[i] = tab;
    }
    grp.voronoi(graphesLibrairies);

    /**
     * Exemple VoronoiLivraison (en prenant en compte les distances et les coût au km)
     * */
    std::printf("\n");
    std::printf("\nDiagramme de Voronoï en compte les distances et les coûts de livraison au km\n");


    distPred ** graphesLibrairiesL = new distPred*[grp.getNbLibrairies()];

    for (int i = 0; i < grp.getNbLibrairies(); i++)
    {
        tab = new distPred[grp.getLignes()*grp.getColonnes()];
        grp.dijkstra(std::get<0>(grp.idLibrairiesCout[i]), tab);
        graphesLibrairies[i] = tab;
    }
    grp.voronoiLivraison(graphesLibrairies);

}
