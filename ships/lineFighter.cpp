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

LineFighter::LineFighter(const std::string& nickname) : TIE(++counter, 100, 6,
                                                            "TIE/LN", nickname) {
}
