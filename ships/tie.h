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

class TIE : public Ship {

public:
    ~TIE() override = default;
    double getWeight() const override { return weight; }
};


#endif //POO2_LABO2_SQUADRON_TIE_H
