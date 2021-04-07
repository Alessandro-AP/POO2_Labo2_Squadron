/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : destroyer.cpp
 Auteur(s)   : Alessandro Parrino et Daniel Sciarra
 Date        : 24.03.2021
 But         :
 Remarque(s) :
 Compilateur : MinGW 6.3.0
 -----------------------------------------------------------------------------------
 */

#include "destroyer.h"

size_t Destroyer::counter = 0;

Destroyer::Destroyer(double load, const std::string &nickname)
        : CargoShip(++counter, 40, 9000000000, "Super-class Star Destroyer",
                    nickname, 250000, load) {
}
