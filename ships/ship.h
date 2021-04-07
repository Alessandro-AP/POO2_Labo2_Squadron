/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : ship.h
 Auteur(s)   : Alessandro Parrino et Daniel Sciarra
 Date        : 24.03.2021
 But         :
 Remarque(s) :
 Compilateur : MinGW 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef BASE_SHIP_H
#define BASE_SHIP_H

#include <ostream>

class Ship;
std::ostream& operator << (std::ostream& os, const Ship& ship);

class Ship
{
    friend std::ostream& operator << (std::ostream& os, const Ship& ship);
public:
    virtual ~Ship();

    void setNickname(const std::string &name);
    double consumption(size_t distance) const;
    virtual double getWeight() const = 0;
    virtual std::ostream& toStream(std::ostream& os) const;

protected:
    size_t id;
    size_t speed;
    double weight;
    std::string model;
    std::string nickname;
};


#endif //BASE_SHIP_H
