/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : squadron.cpp
 Auteur(s)   : Alessandro Parrino et Daniel Sciarra
 Date        : 08.04.2021
 Compilateur : MinGW 6.3.0
 -----------------------------------------------------------------------------------
 */

#include <iomanip>
#include "squadron.h"

Squadron::Squadron(const std::string& name) : name(name),
                                              leader(nullptr),
                                              squad(LinkedList<const Ship*>()) {}

Squadron::Squadron(const Squadron& rhs) : Squadron(rhs.name) {
    leader = rhs.leader;

    LinkedList<const Ship*>::Iterator i;
    for (i = rhs.squad.begin(); i != rhs.squad.end(); ++i)
        squad.insertAtEnd(*i);
}

Squadron& Squadron::operator=(const Squadron& other) {
    if (this != &other) {
        Squadron tmp(other);
        swap(tmp);
    }
    return *this;
}

double Squadron::consumption(size_t distance) const {
    if (squad.isEmpty())
        return 0;

    double consumption = 0;
    LinkedList<const Ship*>::Iterator i;
    for (i = squad.begin(); i != squad.end(); ++i)
        consumption += (*i)->consumption(distance, getSpeed());
    return consumption;

}

void Squadron::setLeader(Ship* newLeader) {
    if (squad.contains(newLeader))
        this->leader = newLeader;
    else {
        std::cout << "Error : the newLeader should be present in the squadron";
    }
}

void Squadron::removeLeader() {
    this->leader = nullptr;
}

double Squadron::getWeight() const {
    if (squad.isEmpty())
        return 0;

    double weight = 0;
    LinkedList<const Ship*>::Iterator i;
    for (i = squad.begin(); i != squad.end(); ++i)
        weight += (*i)->getWeight();
    return weight;
}

size_t Squadron::getSpeed() const {
    if (squad.isEmpty())
        return 0;

    LinkedList<const Ship*>::Iterator i = squad.begin();
    size_t minSpeed = (*i)->getSpeed();

    for (; i != squad.end(); ++i) {
        if (minSpeed > (*i)->getSpeed())
            minSpeed = (*i)->getSpeed();
    }
    return minSpeed;
}

void Squadron::setName(const std::string& name) {
    this->name = name;
}

std::ostream& operator<<(std::ostream& os, const Squadron& s) {
    os << std::setprecision(2) << std::fixed
       << "Squadron: " << s.name << "\n  "
       << "max speed : " << s.getSpeed() << " MGLT\n  "
       << "total weight : " << s.getWeight() << " tons\n\n";

    if (s.leader != nullptr) {
        os << "-- Leader:\n" << *s.leader << "\n\n";
    }

    if (!s.squad.isEmpty()) {
        os << "-- Members:\n";
        LinkedList<const Ship*>::Iterator i;
        for (i = s.squad.begin(); i != s.squad.end(); ++i) {
            if (*i != s.leader)
                os << **i << "\n\n";
        }
    }
    return os;
}

Squadron operator+(Squadron lhs, const Ship* rhs) {
    return lhs += rhs;
}

Squadron operator-(Squadron lhs, const Ship* rhs) {
    return lhs -= rhs;
}

Squadron& Squadron::operator+=(const Ship* rhs) {
    if (!squad.contains(rhs))
        squad.insertAtEnd(rhs);
    return *this;
}

Squadron& Squadron::operator-=(const Ship* rhs) {
    if (squad.contains(rhs))
        squad.remove(rhs);

    if (rhs == leader)
        removeLeader();

    return *this;
}

Squadron Squadron::add(const Ship* rhs) const {
    return *this + rhs;
}

Squadron& Squadron::addTo(const Ship* rhs) {
    return *this += rhs;
}

Squadron Squadron::remove(const Ship* rhs) const {
    return *this - rhs;
}

Squadron& Squadron::removeFrom(const Ship* rhs) {
    return *this -= rhs;
}

void Squadron::swap(Squadron& other) {
    std::swap(name, other.name);
    std::swap(leader, other.leader);
    squad.swap(other.squad);
}



