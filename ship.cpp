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


Ship::Ship(size_t id, size_t speed, size_t weigth, const std::string& model,
           const std::string& nickname) : id(counter++), speed(speed), weigth(weigth),
           model(model), nickname(nickname) {
}

void Ship::setNickname(const std::string &name) {
    nickname = name;
}

double Ship::consumption(size_t distance) const {
    return cbrt(getWeight()) / 2.0 * log10((double) speed * getWeight())
            * log10(distance + 1.0);
}
