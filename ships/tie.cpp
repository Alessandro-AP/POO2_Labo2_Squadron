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

#include "tie.h"

TIE::TIE(size_t id, size_t speed, double weight, const std::string& model,
         const std::string& nickname) : Ship(id, speed, weight, model, nickname) {
}

double TIE::getWeight() const {
    return weight;
}
