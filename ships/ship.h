/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : ship.h
 Auteur(s)   : Alessandro Parrino et Daniel Sciarra
 Date        : 24.03.2021
 Compilateur : MinGW 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef BASE_SHIP_H
#define BASE_SHIP_H

#include <ostream>

/**
 * Classe représentant un Ship
 */
class Ship;

/**
 * Surcharge de l'opérateur d'affichage sur un flux pour afficher un Ship
 * @param os Flux de sortie
 * @param ship Ship à afficher
 * @return le flux de sortie contenant le Ship formaté
 */
std::ostream& operator<<(std::ostream& os, const Ship& ship);

class Ship {

public:

    /**
     * Constructeur
     * @param id ID du Ship
     * @param speed Vitesse du Ship
     * @param weight Poids total du Ship
     * @param model Modèle du Ship
     * @param nickname Surnom du Ship
     */
    Ship(size_t id, size_t speed, double weight, const std::string& model,
         const std::string& nickname);

    /**
     * Destructeur
     */
    virtual ~Ship();

    /**
     * Modifie le surnom d'un Ship
     * @param name Nouveau surnom
     */
    void setNickname(const std::string& name);

    /**
     * Calcul la consommation d'un Ship en fonction de la distance fournie en paramètre
     * @param distance Distance à parcourir
     * @return consommation du Ship pour la distance donnée
     */
    double consumption(size_t distance, size_t speed) const;

    /**
     * Méthode abstraite retournant le poids total d'un Ship
     * @return poids d'un Ship
     */
    virtual double getWeight() const = 0;

    /**
     * @return retourne la vitesse d'un Ship
     */
    size_t getSpeed() const;

    /**
     * Formate et écrit un Ship sur un flux de sortie
     * @param os Flux de sortie
     * @return flux de sortie contenant le Ship formaté
     */
    virtual std::ostream& toStream(std::ostream& os) const;

private:

    const size_t id;
    const size_t speed; // unité MGLT
    const std::string model;
    std::string nickname;

protected:

    const double weight; // unité tonnes
};

#endif //BASE_SHIP_H