/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : main.cpp
 Auteur(s)   : Alessandro Parrino et Daniel Sciarra
 Date        : 24.03.2021
 But         :
 Remarque(s) :
 Compilateur : MinGW 6.3.0
 -----------------------------------------------------------------------------------
 */

#include <iostream>
#include "ships/tie.h"
#include "ships/lineFighter.h"
#include "ships/shuttle.h"

using namespace std;

int main() {

//    TIE* blackLeader = new TIE();
    LineFighter* blackLeader = new LineFighter();
    blackLeader->setNickname("Black leader");
    LineFighter* blackTwo = new LineFighter();
    Shuttle* shuttle = new Shuttle(23.4); // 23.4 tonnes de marchandises
//    Squadron squad("Black Squadron");
//    squad += blackLeader;
//    squad += blackTwo;
//    squad += shuttle;
//    squad.setLeader(blackLeader);
//    cout << squad << endl;


    cout << *blackLeader << endl;
    cout << *blackTwo << endl;
    cout << *shuttle << endl;

    return 0;
}
