/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : shuttle.cpp
 Auteur(s)   : Alessandro Parrino et Daniel Sciarra
 Date        : 24.03.2021
 Compilateur : MinGW 6.3.0
 -----------------------------------------------------------------------------------
 */

#include "shuttle.h"

size_t Shuttle::counter = 0;

Shuttle::Shuttle(double load, const std::string& nickname)
        : CargoShip(++counter, 54, 360, "Lambda-class shuttle",
                    nickname, 80, load) {}
