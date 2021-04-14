/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : cargoShip.h
 Auteur(s)   : Alessandro Parrino et Daniel Sciarra
 Date        : 24.03.2021
 Compilateur : MinGW 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef POO2_LABO2_SQUADRON_CARGOSHIP_H
#define POO2_LABO2_SQUADRON_CARGOSHIP_H

#include "ship.h"

/**
 * Classe représentant un CargoShip
 */
class CargoShip : public Ship {

public:

    /**
     * Constructeur
     * @param id ID du CargoShip
     * @param speed Vitesse du CargoShip
     * @param weight Poids total du CargoShip
     * @param model Modèle du CargoShip
     * @param nickname Surnom du CargoShip
     * @throw invalid_argument si le chargement dépasse la capacité max
     */
    CargoShip(size_t id, size_t speed, double weight, const std::string& model,
              const std::string& nickname, double maxLoad, double load);

    /**
     * Modifie le poids du chargement
     * @param newLoad Nouveau poids
     */
    void setLoad(double newLoad);

    /**
     * @return le poids total du CargoShip, incluant le chargement
     */
    double getWeight() const override;

    /**
     * Formate et écrit un CargoShip sur un flux de sortie
     * @param os Flux de sortie
     * @return flux de sortie contenant le CargoShip formaté
     */
    std::ostream& toStream(std::ostream& os) const override;

private:

    const double maxLoad;
    double load;
};

#endif //POO2_LABO2_SQUADRON_CARGOSHIP_H