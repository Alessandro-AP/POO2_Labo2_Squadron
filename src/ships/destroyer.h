/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : destroyer.h
 Auteur(s)   : Alessandro Parrino et Daniel Sciarra
 Date        : 24.03.2021
 Compilateur : MinGW 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef POO2_LABO2_SQUADRON_DESTROYER_H
#define POO2_LABO2_SQUADRON_DESTROYER_H

#include "cargoShip.h"

/**
 * Classe représentant un Ship
 */
class Destroyer : public CargoShip {

public:

    /**
     * Constructeur
     * @param load Poids du chargement (cargo)
     * @param nickname Surnom
     */
    explicit Destroyer(double load, const std::string& nickname = "");

private:

    static size_t counter;
};

#endif //POO2_LABO2_SQUADRON_DESTROYER_H