//
// Created by Thomas SANTONI on 11/12/2022.
//
#include <string>
#include "distPred.h"

std::string getCouleur(couleur clr){
    std::string nom_couleur;
    switch (clr)
    {
    case 0 :
        nom_couleur="blanc";
        break;
    case 1 :
        nom_couleur="gris";
        break;
    case 2 :
        nom_couleur="noir";
        break;
    default:
        nom_couleur="inconnu";
        break;
    }
    return nom_couleur;
}
