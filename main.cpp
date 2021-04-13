/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : main.cpp
 Auteur(s)   : Alessandro Parrino et Daniel Sciarra
 Date        : 08.04.2021
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
    Squadron squad2("Black Squadron2");
    squad += blackLeader;
    squad2 += blackLeader;
    squad += blackTwo;
    squad += shuttle;
    squad.setLeader(blackLeader);
    cout << "## SQUAD 1: ----------------------------------------\n" << squad;

    cout << "Consommation des membres sur une distance de 10mio km : " <<
    blackLeader->consumption(10, squad.getSpeed()) << ", " << blackTwo->consumption(10, squad
    .getSpeed()) << ", " << shuttle->consumption(10, squad.getSpeed()) << endl;
    cout << "Consommation de SQUAD 1 sur une distance de 10mio km : " << squad.consumption
    (10) << endl << endl;

    // modifier le nom de squad leader
    blackLeader->setNickname("White sheep");

    cout << "SQUAD 2: ----------------------------------------\n" << squad2 << endl;

    cout << "Suppression de shuttle (removeFrom) : " << endl;
    squad.removeFrom(shuttle);
    cout << "SQUAD 1: ----------------------------------------\n" <<  squad << endl;

    cout << "Suppression de shuttle (-=) : " << endl;
    squad -= blackLeader;
    cout << "SQUAD 1: ----------------------------------------\n" <<  squad << endl;

    cout << "Nouvelle squad en ajoutant un ship (+) : " << endl;
    squad = squad + blackLeader;
//    squad = squad.add(blackLeader);
    cout << "SQUAD 3: ----------------------------------------\n" <<  squad << endl;

    cout << "Nouvelle squad en ajoutant un ship deja present : " << endl;
    //squad = squad + blackLeader;
    squad = squad.add(blackLeader);
    cout << "SQUAD 4: ----------------------------------------\n" <<  squad << endl;

    cout << "Nouvelle squad en ajoutant un ship (add) : " << endl;
    //squad = squad + shuttle;
    squad = squad.add(shuttle);
    cout << "SQUAD 5: ----------------------------------------\n" <<  squad << endl;

    cout << "Nouvelle squad en supprimant un ship (-) : " << endl;
    squad = squad - shuttle;
//    squad = squad.remove(shuttle);
    cout << "SQUAD 6: ----------------------------------------\n" <<  squad << endl;

    cout << "Nouvelle squad en supprimant un ship (remove) : " << endl;
    // squad = squad - blackLeader;
    squad = squad.remove(blackLeader);
    cout << "SQUAD 7: ----------------------------------------\n" <<  squad << endl;

    // squad = squad - blackTwo;
    squad = squad.remove(blackTwo);
    cout << "SQUAD 8: ----------------------------------------\n" <<  squad << endl;


    // capacité cargo dépassée
    try {
        cout << endl << "On bourre le vaisseau : " << endl;
        auto* err = new Shuttle(90);
    } catch (invalid_argument& e) {
        cout << "Erreur : " << e.what() << endl;
    }

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
                ship->consumption(10, ship->getSpeed()) << " tonnes de carburant" << endl;
    }

    // capacité cargo dépassée
    try {
        cout << endl << "On bourre le vaisseau : " << endl;
        auto* err = new Shuttle(90);
    } catch (invalid_argument& e) {
        cout << "Erreur : " << e.what() << endl;
    }

    return 0;
}
*/
