#include "Character.hpp"

#include <utility>

Character::Character(string name, int hitpoints, Point &location) : teamFlag(false), location(location), hitpoints(hitpoints),
                                                                    name(std::move(name)) {}

Point &Character::getLocation() {
    return location;
}

string Character::getName() {
    return name;
}

int Character::getHitPoints() const{
    return hitpoints;
}

void Character::hit(int hitNum) {
    if(hitNum < 0) throw invalid_argument("Negative hit number is not allowed.");
    else if(hitpoints > 0) hitpoints -= hitNum;
    else{
        throw runtime_error("Character is already dead.\n");
    }
}

double Character::distance(Character *other) {
    return location.distance(other->getLocation());
}

bool Character::isAlive() const {
    if(hitpoints > 0) return true;
    else{return false;}
}

void Character::setName(const string& newName){
    name = newName;
}

void Character::setHitPoints(int newHitPoints){
    hitpoints = newHitPoints;
}

void Character::setLocation(const Point& newLocation){
    location.setX(newLocation.getX());
    location.setY(newLocation.getY());
}

bool Character::getTeamFlag() const {
    return teamFlag;
}

void Character::setTeamFlag() {
    teamFlag = true;
}






