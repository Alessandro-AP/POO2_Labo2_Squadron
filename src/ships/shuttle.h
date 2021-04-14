/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : shuttle.h
 Auteur(s)   : Alessandro Parrino et Daniel Sciarra
 Date        : 24.03.2021
 Compilateur : MinGW 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef POO2_LABO2_SQUADRON_SHUTTLE_H
#define POO2_LABO2_SQUADRON_SHUTTLE_H

#include "cargoShip.h"

/**
 * Classe représentant un Ship
 */
class Shuttle : public CargoShip {

public:

    /**
     * Constructeur
     * @param load Poids du chargement (cargo)
     * @param nickname Surnom
     */
    explicit Shuttle(double load, const std::string& nickname = "");

private:

    static size_t counter;
};

#endif //POO2_LABO2_SQUADRON_SHUTTLE_H