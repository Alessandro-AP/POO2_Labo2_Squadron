/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : squadron.h
 Auteur(s)   : Alessandro Parrino et Daniel Sciarra
 Date        : 08.04.2021
 Compilateur : MinGW 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef POO2_LABO2_SQUADRON_SQUADRON_H
#define POO2_LABO2_SQUADRON_SQUADRON_H

#include <iostream>
#include "ships/ship.h"
#include "utils/linkedList.h"
/**
 * Classe représentant une escadrille
 */
class Squadron {

    /**
     * Surcharge de l'opérateur de lecture dans un flux pour les escadrilles.
     * Permet l'affichage d'une escadrille
     *
     * @return Squadron sous forme de ostream&
     */
    friend std::ostream& operator<<(std::ostream& os, const Squadron& m);

    /**
     * Surcharge de l'opérateur d'addition "+"
     * Permet d'ajouter un vaisseau à une escadrille, si le vaisseau est déjà présent
     * dans l'escadrille, aucune opération n'est effectuée.
     *
     * @param lhs l'escadrille
     * @param rhs le vaisseau ajouté
     * @return une copie de l'escadrille avec le vaisseau ajouté
     */
    friend Squadron operator+(Squadron lhs, const Ship* rhs);

    /**
     * Surcharge de l'opérateur de soustraction "-"
     * Permet de retirer un vaisseau à une escadrille, si le vaisseau n'est pas présent
     * dans l'escadrille, aucune opération n'est effectuée.
     *
     * @param lhs l'escadrille
     * @param rhs le vaisseau retiré
     * @return une copie de l'escadrille avec le vaisseau retiré
     */
    friend Squadron operator-(Squadron lhs, const Ship* rhs);

public:

    /**
     * Constructeur de la classe Squadron
     *
     * @param name le nom de l'escadrille
     *
     * Remarque: Il n'est pas possible de déclarer une escadrille avec la forme :
     * Squadron s = "Black leader";
     */
    explicit Squadron(const std::string& name);

    /**
     * Constructeur de copie
     * Permet de créer une copie d'une escadrille, à partir d'un autre.
     *
     * @param rhs escadrille a copier
     */
    Squadron(const Squadron& rhs);

    /**
     * Surcharge de l'opérateur d'affectation "="
     *
     * @param rhs escadrille a copier
     * @return une référence sur l'escadrille copié
     */
    Squadron& operator=(const Squadron& rhs);

    /**
     * Surcharge de l'opérateur "+="
     * Permet d'ajouter un vaisseau à une escadrille, si le vaisseau est déjà présent
     * dans l'escadrille, aucune opération n'est effectuée.
     *
     * @param rhs le vaisseau ajouté
     * @return une référence d'une escadrille avec le vaisseau ajouté
     */
    Squadron& operator+=(const Ship* rhs);

    /**
     * Surcharge de l'opérateur "-="
     * Permet de retirer un vaisseau à une escadrille, si le vaisseau n'est pas présent
     * dans l'escadrille, aucune opération n'est effectuée.
     *
     * @param rhs le vaisseau retiré
     * @return une référence d'une escadrille avec le vaisseau retiré
     */
    Squadron& operator-=(const Ship* rhs);

    /**
     * Fonction qui permet d'ajouter un vaisseau (utilise l'opérateur +)
     *
     * @param rhs le vaisseau ajouté
     * @return une copie d'une escadrille avec le vaisseau ajouté
     */
    Squadron add(const Ship* rhs) const;

    /**
     * Fonction qui permet d'ajouter un vaisseau (utilise l'opérateur +=)
     *
     * @param rhs le vaisseau ajouté
     * @return une référence d'une escadrille avec le vaisseau ajouté
     */
    Squadron& addTo(const Ship* rhs);

    /**
     * Fonction qui permet de retirer un vaisseau (utilise l'opérateur -)
     *
     * @param rhs le vaisseau retiré
     * @return une copie d'une escadrille avec le vaisseau retiré
     */
    Squadron remove(const Ship* rhs) const;

    /**
     * Fonction qui permet de retirer un vaisseau (utilise l'opérateur -=)
     *
     * @param rhs le vaisseau retiré
     * @return une référence d'une escadrille avec le vaisseau retiré
     */
    Squadron& removeFrom(const Ship* rhs);

    /**
     * Calcul de la consommation de carburant de l’escadrille pour une certaine distance
     *
     * @param distance
     * @return la consommation de l’escadrille
     */
    double consumption(size_t distance) const;

    /**
     * Définit le chef de l’escadrille
     *
     * @param newLeader
     */
    void setLeader(Ship* newLeader);

    /**
     * Supprime le chef de l’escadrille
     */
    void removeLeader();

    /**
     * Fonction qui fournit le poids total de l’escadrille
     *
     * @return le poids
     */
    double getWeight() const;

    /**
     * Fonction qui fournit la vitesse maximale de l’escadrille
     *
     * @return la vitesse maximale
     */
    size_t getSpeed() const;

    /**
     * Fonction qui permet de modifier le nom de l’escadrille
     * @param name
     */
    void setName(const std::string& name);

private:
    /** Nom de l’escadrille*/
    std::string name;

    /** Leader */
    Ship* leader;

    /** les vaisseaux appartenant à l’escadrille */
    LinkedList<const Ship*> squad;

    /**
     * Swap de 2 Squadron
     * @param squadron Autre Squadron à "swaper"
     */
    void swap(Squadron& squadron);
};

#endif //POO2_LABO2_SQUADRON_SQUADRON_H