/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : lineFighter.h
 Auteur(s)   : Alessandro Parrino et Daniel Sciarra
 Date        : 24.03.2021
 Compilateur : MinGW 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef POO2_LABO2_SQUADRON_LINEFIGHTER_H
#define POO2_LABO2_SQUADRON_LINEFIGHTER_H

#include "tie.h"

/**
 * Classe représentant un LineFighter
 */
class LineFighter : public TIE {

public:

    /**
     * Constructeur
     * @param nickname Surnom du LineFighter
     */
    explicit LineFighter(const std::string& nickname = "");

private:

    static size_t counter;
};

#endif //POO2_LABO2_SQUADRON_LINEFIGHTER_H