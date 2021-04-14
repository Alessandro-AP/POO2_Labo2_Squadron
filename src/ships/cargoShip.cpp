/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : cargoShip.cpp
 Auteur(s)   : Alessandro Parrino et Daniel Sciarra
 Date        : 24.03.2021
 Compilateur : MinGW 6.3.0
 -----------------------------------------------------------------------------------
 */

#include "cargoShip.h"
#include <iomanip>

CargoShip::CargoShip(size_t id, size_t speed, double weight, const std::string& model,
                     const std::string& nickname, double maxLoad, double load)
        : Ship(id, speed, weight, model, nickname), maxLoad(maxLoad) {

    if (load > maxLoad)
        throw std::invalid_argument("Chargement max depassee!");
    this->load = load;
}

void CargoShip::setLoad(double newLoad) {
    load = newLoad;
}

double CargoShip::getWeight() const {
    return weight + load;
}

std::ostream& CargoShip::toStream(std::ostream& os) const {
    return Ship::toStream(os) << "\n  cargo : " << std::setprecision(1) << std::fixed
                              << load << " tons (max : " << maxLoad << ")";
}
