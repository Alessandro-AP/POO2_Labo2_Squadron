/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : destroyer.h
 Auteur(s)   : Alessandro Parrino et Daniel Sciarra
 Date        : 24.03.2021
 But         :
 Remarque(s) :
 Compilateur : MinGW 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef POO2_LABO2_SQUADRON_DESTROYER_H
#define POO2_LABO2_SQUADRON_DESTROYER_H

#include "cargoShip.h"

class Destroyer : public CargoShip {

public:
    explicit Destroyer(double load, const std::string& nickname = "");

private:
    static size_t counter;
};


#endif //POO2_LABO2_SQUADRON_DESTROYER_H
