/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : tie.h
 Auteur(s)   : Alessandro Parrino et Daniel Sciarra
 Date        : 24.03.2021
 But         :
 Remarque(s) :
 Compilateur : MinGW 6.3.0
 -----------------------------------------------------------------------------------
 */


#ifndef POO2_LABO2_SQUADRON_TIE_H
#define POO2_LABO2_SQUADRON_TIE_H


#include "ship.h"

// est-ce qu'on fait un fichier cpp ?

class TIE : public Ship {

public:
    TIE(size_t id, size_t speed, double weight, const std::string& model,
        const std::string& nickname) : Ship(id, speed, weight, model, nickname) {}
    ~TIE() override = default;
    double getWeight() const override { return weight; }
};


#endif //POO2_LABO2_SQUADRON_TIE_H
