/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : squadron.cpp
 Auteur(s)   : Alessandro Parrino et Daniel Sciarra
 Date        : 08.04.2021
 But         :
 Remarque(s) :
 Compilateur : MinGW 6.3.0
 -----------------------------------------------------------------------------------
 */

#include <iomanip>
#include "squadron.h"

Squadron::Squadron(std::string name) : name(name), leader(nullptr) {}

Squadron operator+(Squadron lhs, Ship *const rhs) {
    return lhs += rhs;
}

Squadron operator-(Squadron lhs, Ship *const rhs) {
    return lhs -= rhs;
}

Squadron &Squadron::operator+=(Ship *const rhs) {
    if (!squad.contains(rhs))
        squad.insertAtEnd(rhs);
    return *this;
}

Squadron &Squadron::operator-=(Ship *const rhs) {
    if (squad.contains(rhs))
        squad.remove(rhs);

    if (rhs == leader)
        removeLeader();

    return *this;
}


double Squadron::consumption(size_t distance) {
    if(squad.isEmpty())
        return 0;

    double consumption = 0;
    LinkedList<Ship *>::Iterator i;
    for (i = squad.begin(); i != squad.end(); ++i)
        consumption += (*i)->consumption(distance);
    return consumption;

}

void Squadron::setLeader(Ship *leader) {
    if (squad.contains(leader))
        this->leader = leader;
    else {
        std::cout << "Error : the leader should be present in the squadron";
    }
}

void Squadron::removeLeader() {
    this->leader = nullptr;
}

double Squadron::getWeight() const {
    if(squad.isEmpty())
        return 0;

    double weight = 0;
    LinkedList<Ship *>::Iterator i;
    for (i = squad.begin(); i != squad.end(); ++i)
        weight += (*i)->getWeight();
    return weight;
}

size_t Squadron::getSpeed() const {
    if(squad.isEmpty())
        return 0;

    LinkedList<Ship *>::Iterator i = squad.begin();
    size_t minSpeed = (*i)->getSpeed();

    for (; i != squad.end(); ++i) {
        if (minSpeed > (*i)->getSpeed())
            minSpeed = (*i)->getSpeed();
    }
    return minSpeed;
}

std::ostream &operator<<(std::ostream &os, const Squadron &s) {
    os << std::setprecision(2) << std::fixed
       << "Squadron: " << s.name << "\n  "
       << "max speed : " << s.getSpeed() << " MGLT\n  "
       << "total weight : " << s.getWeight() << " tons\n\n";

    if (s.leader != nullptr) {
        os << "-- Leader:\n" << *s.leader << "\n\n";
    }

    if(!s.squad.isEmpty()) {
        os << "-- Members:\n";
        LinkedList<Ship *>::Iterator i;
        for (i = s.squad.begin(); i != s.squad.end(); ++i) {
            if (*i != s.leader)
                os << **i << "\n\n";
        }
    }
    return os;
}

Squadron Squadron::add(Ship *const rhs) {
    return *this + rhs;
}

Squadron &Squadron::addTo(Ship *const rhs) {
    return *this += rhs;
}

Squadron Squadron::remove(Ship *const rhs) {
    return *this - rhs;
}

Squadron &Squadron::removeFrom(Ship *const rhs) {
    return *this -= rhs;
}


