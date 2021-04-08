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
#include <iomanip>
#include "ships/tie.h"
#include "ships/lineFighter.h"
#include "ships/interceptor.h"
#include "ships/shuttle.h"
#include "ships/destroyer.h"
#include "Squadron.h"

using namespace std;

int main(){
    LineFighter* blackLeader = new LineFighter();
    blackLeader->setNickname("Black leader");
    LineFighter* blackTwo = new LineFighter();
    Shuttle* shuttle = new Shuttle(23.4); // 23.4 tonnes de marchandises
    Squadron squad("Black Squadron");
    squad += blackLeader;
    squad += blackTwo;
    squad += shuttle;
    squad.setLeader(blackLeader);
    cout << squad << endl;

    squad -= shuttle;
    cout << squad << endl;

    squad -= blackLeader;
    cout << squad << endl;

    squad = squad + blackLeader;
    cout << squad << endl;

}



/*
int main() {

    //TIE* blackLeader = new TIE();
    LineFighter* blackLeader = new LineFighter();
    blackLeader->setNickname("Black leader");
    LineFighter* blackTwo = new LineFighter();
    TIE* blackOne = new Interceptor();
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
    cout << *blackOne << endl;

    Ship* list[] = {new LineFighter(), new LineFighter("popol"), new Interceptor("Izi"),
                    new Destroyer(11000, "ho boy"), new Shuttle(12)};
    list[0]->setNickname("rrh");
    ((Shuttle*) list[4])->setLoad(23);

    for (Ship* ship : list) {
        cout << endl << *ship << endl;
        cout << "  Consommation sur une distance de 10mio km : " << setprecision(3) << fixed <<
                ship->consumption(10) << " tonnes de carburant" << endl;
    }

    // capacité cargo dépassée
    try {
        cout << endl << "On bourre le vaisseau : " << endl;
        auto* err = new Shuttle(90);
    } catch (invalid_argument& e) {
        cout << "Erreur : " << e.what() << endl;
    }

    return 0;
}*/
