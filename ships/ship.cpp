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
#include <iomanip>

Ship::Ship(size_t id, size_t speed, double weight, const std::string& model,
           const std::string& nickname) : id(id), speed(speed), weight(weight), model(model),
                                          nickname(nickname) {
}

Ship::~Ship() = default;

void Ship::setNickname(const std::string &name) {
    nickname = name;
}

double Ship::consumption(size_t distance) const {
    return log10(speed * getWeight()) * log10(distance + 1.0) * cbrt(getWeight()) / 2.0;
}

std::ostream &operator<<(std::ostream &os, const Ship &ship) {
    return ship.toStream(os);
}

std::ostream &Ship::toStream(std::ostream &os) const {
    os << (nickname.empty() ? "" : nickname + " ") + "[" + model + " #" << id << "]\n"
          "  weight : " << std::setprecision(2) << std::fixed << getWeight() << " tons\n"
          "  max speed : " << speed << " MGLT";
    return os;
}
