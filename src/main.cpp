#include "graphe.h"
#include "distPred.h"
#include <iostream>

int main()
{
    // TODO : ici montrer que toutes les fonctionnalités demandées fonctionnent "En plus des opérations classiques
    // d’initialisation, d’affectation et de testament de graphe,
    // prévoir des fonctions d’accès à l’indice global d’un sommet en fonction de ses indices de ligne ou
    // de colonne, d’accès à l’altitude d’un sommet (en fonction de son indice global), d’accès à l’indice
    // global du voisin Nord (resp. Sud, Est et Ouest) d’un sommet (avec pour précondition que le
    // voisin existe) ainsi que des procédures de modification de l’altitude d’un sommet et une procédure
    // d’affichage de la grille de hauteur.
    // Faire un petit programme qui illustre que votre module met correctement en œuvre toutes les
    // fonctionnalités demandées pour les graphes de terrain."
    Graphe grp("test");
    std::cout << "Les indices globales des noeuds :" << std::endl;
    grp.affichageGrilleHauteur();


    /**
     * Exemple Voronoi (en prenant uniquement en compte les distances)
     * */

    std::printf("\nDiagramme de Voronoï en prenant uniquement en compte les distances\n");

    // todo : à remplacer par une donnée membre
    const int nbLibrairies = 3;
    distPred * tab = nullptr;

    // todo : à remplacer par une donnée membre (liste de tuples, voir plus bas)
    // indices globaux des librairies du graphe
    int idlibrairies [nbLibrairies] = {0, 6, 7};
    distPred ** graphesLibrairies = new distPred*[nbLibrairies];

    // Calcule dijkstra pour toutes les librairies
    for (int i = 0; i < nbLibrairies; i++)
    {
        tab = new distPred[grp.getLignes()*grp.getColonnes()];
        grp.dijkstra(idlibrairies[i], tab);
        graphesLibrairies[i] = tab;
    }
    grp.voronoi(graphesLibrairies, nbLibrairies, idlibrairies);

    /**
     * Exemple VoronoiLivraison (en prenant en compte les distances et les coût au km)
     * */
    std::printf("\n");

    // todo : pas besoin de faire un autre graphe, il faut juste utiliser une donnée membre idLibrairiesCout
    Graphe grpL("test");
    std::cout << "Les indices globales des noeuds :" << std::endl;
    grp.affichageGrilleHauteur();

    std::printf("\nDiagramme de Voronoï en compte les distances et les coûts de livraison au km\n");

    const int nbLibrairiesL = 3;
    distPred * tabL = nullptr;

    // todo : à remplacer par une donnée membre (liste de tuples, voir plus bas)
    //
    std::tuple<int, int> idlibrairiesCout [nbLibrairies] = {std::make_tuple(0, 10), std::make_tuple(6, 2),
                                                            std::make_tuple(7, 3)};
    distPred ** graphesLibrairiesL = new distPred*[nbLibrairies];

    for (int i = 0; i < nbLibrairies; i++)
    {
        tab = new distPred[grp.getLignes()*grp.getColonnes()];
        grp.dijkstra(idlibrairies[i], tab);
        graphesLibrairies[i] = tab;
    }
    grp.voronoiLivraison(graphesLibrairies, nbLibrairies, idlibrairiesCout);

}
