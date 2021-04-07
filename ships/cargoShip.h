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
    CargoShip(size_t id, size_t speed, double weight, const std::string& model,
              const std::string& nickname, double maxLoad, double load);
    ~CargoShip() override = default;
    void setLoad(double newLoad);
    double getWeight() const override;
    std::ostream &toStream(std::ostream &os) const override;

private:
    const double maxLoad;
    double load;
};


#endif //POO2_LABO2_SQUADRON_CARGOSHIP_H
