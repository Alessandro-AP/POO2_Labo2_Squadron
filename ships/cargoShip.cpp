/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : cargoShip.cpp
 Auteur(s)   : Alessandro Parrino et Daniel Sciarra
 Date        : 24.03.2021
 But         :
 Remarque(s) :
 Compilateur : MinGW 6.3.0
 -----------------------------------------------------------------------------------
 */

#include "cargoShip.h"
#include <iomanip>

void CargoShip::setLoad(double newLoad) {
    load = newLoad;
}

double CargoShip::getWeight() const {
    return weight + load;
}

std::ostream &CargoShip::toStream(std::ostream &os) const {
    return Ship::toStream(os) << "\n  cargo : " << std::setprecision(1) << std::fixed
            << load << " tons (max : " << maxLoad << ")";
}
