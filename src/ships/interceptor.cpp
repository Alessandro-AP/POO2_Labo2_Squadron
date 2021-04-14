/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : interceptor.cpp
 Auteur(s)   : Alessandro Parrino et Daniel Sciarra
 Date        : 24.03.2021
 Compilateur : MinGW 6.3.0
 -----------------------------------------------------------------------------------
 */

#include "interceptor.h"

size_t Interceptor::counter = 0;

Interceptor::Interceptor(const std::string& nickname) : TIE(++counter, 110, 5,
                                                            "TIE/IN", nickname) {
}
