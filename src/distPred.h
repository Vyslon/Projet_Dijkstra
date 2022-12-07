//
// Created by Thomas SANTONI on 30/11/2022.
//

#include <list>

#ifndef VORONOI_DISTPRED_H
#define VORONOI_DISTPRED_H

enum couleur {
    blanc,
    gris,
    noir
};

class distPred
{
    public:
        int id;
        int distance = INT_MAX;
        int idPredecesseur;
        couleur clr;
};

#endif //VORONOI_DISTPRED_H
