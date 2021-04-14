/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : tie.h
 Auteur(s)   : Alessandro Parrino et Daniel Sciarra
 Date        : 24.03.2021
 Compilateur : MinGW 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef POO2_LABO2_SQUADRON_TIE_H
#define POO2_LABO2_SQUADRON_TIE_H

#include "ship.h"

/**
 * Classe représentant un TIE
 */
class TIE : public Ship {

public:
    /**
     * Constructeur
     * @param id ID du TIE
     * @param speed Vitesse du TIE
     * @param weight Poids total du TIE
     * @param model Modèle du TIE
     * @param nickname Surnom du TIE
     */
    TIE(size_t id, size_t speed, double weight, const std::string& model,
        const std::string& nickname);

    /**
     * @return le poids d'un TIE
     */
    double getWeight() const override;
};

#endif //POO2_LABO2_SQUADRON_TIE_H