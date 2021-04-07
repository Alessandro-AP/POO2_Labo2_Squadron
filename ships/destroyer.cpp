/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : destroyer.cpp
 Auteur(s)   : Alessandro Parrino et Daniel Sciarra
 Date        : 24.03.2021
 But         :
 Remarque(s) :
 Compilateur : MinGW 6.3.0
 -----------------------------------------------------------------------------------
 */

#include "destroyer.h"

size_t Destroyer::counter = 0;

Destroyer::Destroyer(double load, const std::string &nickname) {
    maxLoad = 250000;
    if (load > maxLoad)
        throw std::invalid_argument("Chargement max : 250000 tonnes !");
    model = "Super-class Star Destroyer";
    this->nickname = nickname;
    id = ++counter;
    speed = 40;
    weight = 9000000000;
}
