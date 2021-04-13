/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : main.cpp
 Auteur(s)   : Alessandro Parrino et Daniel Sciarra
 Date        : 08.04.2021
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
#include "squadron.h"

using namespace std;

int main() {
    LineFighter* blackLeader = new LineFighter();
    blackLeader->setNickname("Black leader");
    LineFighter* blackTwo = new LineFighter();
    Shuttle* shuttle = new Shuttle(23.4, "popol"); // 23.4 tonnes de marchandises
    Destroyer* rrh = new Destroyer(11000, "RRH");
    Interceptor* pdo = new Interceptor("PDO");
    Squadron squad("Black Squadron");
    squad += blackLeader;
    squad += blackTwo;
    squad += shuttle;
    squad.setLeader(blackLeader);
    Squadron squad2("VIP Team");
    squad2.addTo(blackLeader);
    squad2.addTo(rrh);
    squad2.addTo(pdo);

    cout << "## SQUAD 1: ----------------------------------------\n" << squad;

    cout << "Consommation des membres sur une distance de 10mio km : " <<
         blackLeader->consumption(10, squad.getSpeed()) << ", " <<
         blackTwo->consumption(10, squad.getSpeed()) << ", " <<
         shuttle->consumption(10, squad.getSpeed()) << endl;
    cout << "Consommation de SQUAD 1 sur une distance de 10mio km : " << setprecision(3)
         << fixed << squad.consumption(10) << endl << endl;

    // modifier le nom de black leader
    blackLeader->setNickname("White sheep");

    cout << "SQUAD 2: ----------------------------------------\n" << squad2 << endl;

    cout << "Suppression du leader : " << endl;
    squad.removeFrom(blackLeader);
    cout << "SQUAD 1: ----------------------------------------\n" << squad << endl;

    cout << "Ajout membre black leader : " << endl;
    squad = squad.add(blackLeader);
    cout << "SQUAD 1: ----------------------------------------\n" << squad << endl;

    cout << "Nouvelle squad en ajoutant un ship deja present : " << endl;
    Squadron squad3 = squad.add(blackLeader);
    cout << "SQUAD 3: ----------------------------------------\n" << squad3 << endl;

    cout << "Constructeur de copie (VIP team) : " << endl;
    Squadron squad4 = Squadron(squad2);
    cout << "SQUAD 4: ----------------------------------------\n" << squad4 << endl;

    cout << "Retourne nouvelle squad en supprimant un ship : " << endl;
    Squadron squad5 = squad4.remove(blackLeader);
    cout << "SQUAD 5: ----------------------------------------\n" << squad5;

    cout << "Modification de la VIP team : " << endl;
    squad5.setLeader(pdo);
    squad5.setName("HEIG VIP");
    rrh->setLoad(31000.5);
    cout << "SQUAD 5: ----------------------------------------\n" << squad5;
    cout << "Consommation de SQUAD 5 sur une distance de 20mio km : " << setprecision(3)
         << fixed << squad5.consumption(20) << endl << endl;


    // capacité cargo dépassée
    try {
        cout << endl << "On cree un vaisseau et on le bourre (> capacite cargo): " << endl;
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
