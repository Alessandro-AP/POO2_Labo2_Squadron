/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : squadron.h
 Auteur(s)   : Alessandro Parrino et Daniel Sciarra
 Date        : 08.04.2021
 But         :
 Remarque(s) :
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
    friend Squadron operator+(Squadron lhs, Ship* const rhs);
    friend Squadron operator-(Squadron lhs, Ship* const rhs);
public:
    Squadron(std::string name);
    Squadron(const Squadron& copy);

    Squadron& operator+=(Ship* const rhs);
    Squadron& operator-=(Ship* const rhs);

    Squadron add(Ship* const rhs);
    Squadron& addTo(Ship* const rhs);
    Squadron remove(Ship* const rhs);
    Squadron& removeFrom(Ship* const rhs);


    double consumption(size_t distance);
    void setLeader(Ship* leader);
    void removeLeader();
    double getWeight() const;
    size_t getSpeed() const;

private:
    std::string name;

    Ship* leader;
    LinkedList<Ship*> squad;
};


#endif //POO2_LABO2_SQUADRON_SQUADRON_H
