/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : interceptor.h
 Auteur(s)   : Alessandro Parrino et Daniel Sciarra
 Date        : 24.03.2021
 But         :
 Remarque(s) :
 Compilateur : MinGW 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef POO2_LABO2_SQUADRON_INTERCEPTOR_H
#define POO2_LABO2_SQUADRON_INTERCEPTOR_H


#include "tie.h"

class Interceptor : public TIE {

public:
    explicit Interceptor(const std::string& nickname = "");
    ~Interceptor() override = default;

private:
    static size_t counter;
};


#endif //POO2_LABO2_SQUADRON_INTERCEPTOR_H
