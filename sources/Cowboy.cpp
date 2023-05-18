#include "Cowboy.hpp"

#include <utility>

Cowboy::Cowboy(string name, Point &location) : booletsNum(6), Character(std::move(name), 110, location) {}

Cowboy::Cowboy(string name, Point &&location) : booletsNum(6), Character(std::move(name), 110, location) {}

void Cowboy::shoot(Character *enemy) {

    if (enemy == this) throw invalid_argument("Cannot shoot yourself!\n");
    else if(!enemy->isAlive()) throw runtime_error("Enemy is already dead.\n");
    else if(!isAlive()) throw runtime_error("Cowboy is already dead. Cannot shoot anyone.\n");
    else if(hasboolets()) {
        enemy->hit(10);
        booletsNum--;
    }
}

bool Cowboy::hasboolets() const {
    return (booletsNum >= 0);
}

void Cowboy::reload() {

    if (isAlive()) {
        booletsNum = 6;
    }
}

string Cowboy::print() {

    std::stringstream ss;
    if (getHitPoints() >= 0) {
        ss << "Name: C " << getName() << endl << "Hitpoints: " << getHitPoints() << endl << "Location: "
           << getLocation().print() << endl;
    } else {
        ss << "Name: C (" << getName() << ")" << endl << "Location: " << getLocation().print() << endl;
    }
    return ss.str();
}






