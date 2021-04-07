/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : cargoShip.h
 Auteur(s)   : Alessandro Parrino et Daniel Sciarra
 Date        : 24.03.2021
 But         :
 Remarque(s) :
 Compilateur : MinGW 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef POO2_LABO2_SQUADRON_CARGOSHIP_H
#define POO2_LABO2_SQUADRON_CARGOSHIP_H

#include "ship.h"

class CargoShip : public Ship {
public:
    ~CargoShip() override = default;
    void setLoad(double newLoad);
    double getWeight() const override;
    std::ostream &toStream(std::ostream &os) const override;
protected:
    double maxLoad;
    double load;
};


#endif //POO2_LABO2_SQUADRON_CARGOSHIP_H
