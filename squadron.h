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

class Squadron {
    friend std::ostream& operator<<(std::ostream& os, const Squadron& m);
    friend Squadron operator+(Squadron lhs, const Ship* rhs);
    friend Squadron operator-(Squadron lhs, const Ship* rhs);

public:

    explicit Squadron(const std::string& name);
    Squadron(const Squadron& copy);

    Squadron& operator=(const Squadron& rhs);

    Squadron& operator+=(const Ship* rhs);
    Squadron& operator-=(const Ship* rhs);

    Squadron add(const Ship* rhs) const;
    Squadron& addTo(const Ship* rhs);
    Squadron remove(const Ship* rhs) const;
    Squadron& removeFrom(const Ship* rhs);


    double consumption(size_t distance) const;
    void setLeader(Ship* newLeader);
    void removeLeader();
    double getWeight() const;
    size_t getSpeed() const;

private:

    std::string name;
    Ship* leader;
    LinkedList<const Ship*> squad;

    /**
     * Swap de 2 Squadron
     * @param squadron Autre Squadron à "swaper"
     */
    void swap(Squadron& squadron);
};

#endif //POO2_LABO2_SQUADRON_SQUADRON_H