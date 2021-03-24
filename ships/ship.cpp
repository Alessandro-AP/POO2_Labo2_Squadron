/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : ship.cpp
 Auteur(s)   : Alessandro Parrino et Daniel Sciarra
 Date        : 24.03.2021
 But         :
 Remarque(s) :
 Compilateur : MinGW 6.3.0
 -----------------------------------------------------------------------------------
 */

#include "ship.h"
#include <cmath>

size_t Ship::counter = 0;

void Ship::setNickname(const std::string &name) {
    nickname = name;
}

double Ship::consumption(size_t distance) const {
    return cbrt(getWeight()) / 2.0 * log10((double) speed * getWeight())
            * log10(distance + 1.0);
}
