/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : shuttle.h
 Auteur(s)   : Alessandro Parrino et Daniel Sciarra
 Date        : 24.03.2021
 But         :
 Remarque(s) :
 Compilateur : MinGW 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef POO2_LABO2_SQUADRON_SHUTTLE_H
#define POO2_LABO2_SQUADRON_SHUTTLE_H

#include "cargoShip.h"

class Shuttle : public CargoShip {

public:
    explicit Shuttle(double load, const std::string& nickname = "");
    ~Shuttle() override = default;

private:
    static size_t counter;
};


#endif //POO2_LABO2_SQUADRON_SHUTTLE_H
