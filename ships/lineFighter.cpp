/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : lineFighter.cpp
 Auteur(s)   : Alessandro Parrino et Daniel Sciarra
 Date        : 24.03.2021
 But         :
 Remarque(s) :
 Compilateur : MinGW 6.3.0
 -----------------------------------------------------------------------------------
 */

#include "lineFighter.h"

size_t LineFighter::counter = 0;

LineFighter::LineFighter(const std::string& nickname) {
    model = "TIE/LN";
    this->nickname = nickname;
    id = ++counter;
    speed = 100;
    weight = 6;
}
