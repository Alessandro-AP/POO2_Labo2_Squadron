/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : interceptor.cpp
 Auteur(s)   : Alessandro Parrino et Daniel Sciarra
 Date        : 24.03.2021
 But         :
 Remarque(s) :
 Compilateur : MinGW 6.3.0
 -----------------------------------------------------------------------------------
 */

#include "interceptor.h"

size_t Interceptor::counter = 0;

Interceptor::Interceptor(const std::string &nickname) {
    model = "TIE/IN";
    this->nickname = nickname;
    id = ++counter;
    speed = 110;
    weight = 5;
}
