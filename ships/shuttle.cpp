/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : shuttle.cpp
 Auteur(s)   : Alessandro Parrino et Daniel Sciarra
 Date        : 24.03.2021
 But         :
 Remarque(s) :
 Compilateur : MinGW 6.3.0
 -----------------------------------------------------------------------------------
 */

#include "shuttle.h"
#include <exception>

size_t Shuttle::counter = 0;

Shuttle::Shuttle(double load, const std::string& nickname) {
    maxLoad = 80;
    if (load > maxLoad)
        throw std::invalid_argument("Chargement max : 80 tonnes !");
    model = "Lambda-class shuttle";
    this->nickname = nickname;
    id = ++counter;
    speed = 54;
    weight = 360;
    this->load = load;
}
