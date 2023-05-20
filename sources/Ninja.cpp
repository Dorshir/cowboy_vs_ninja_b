#include "Ninja.hpp"


Ninja::Ninja(string name, int hitpoints, Point &location, int speed) : speed(speed),
                                                                       Character(std::move(name), hitpoints,
                                                                                 location) {}
void Ninja::move(Character *enemy) {

    if (enemy == this) throw invalid_argument("Same ninja as argument.\n");
    else if (getHitPoints() < 0) throw runtime_error("Ninja is already dead, cannot move anywhere.\n");
    else if (!enemy->isAlive()) throw runtime_error("Enemy is already dead.\n");
    else if (getLocation().distance(enemy->getLocation()) <= getSpeed()) {

        setLocation(enemy->getLocation());
    } else {

        double distance = getLocation().distance(enemy->getLocation());

        // Calculate the movement ratio
        double ratio = getSpeed() / distance;

        // Calculate the movement increments for x and y coordinates
        double movementX = (enemy->getLocation().getX() - getLocation().getX()) * ratio;
        double movementY = (enemy->getLocation().getY() - getLocation().getY()) * ratio;

        // Update the ninja's location
        setLocation(Point(getLocation().getX() + movementX, getLocation().getY() + movementY));
    }
}

void Ninja::slash(Character *enemy) {

    if (enemy == this) throw runtime_error("Cannot slash yourself!\n");
    else if (getHitPoints() <= 0) throw runtime_error("Ninja is already dead, cannot slash anyone.\n");
    else if (!enemy->isAlive()) throw runtime_error("Enemy is already dead.\n");
    else if (getLocation().distance(enemy->getLocation()) <= 1.0) {
        enemy->hit(40);
    }
}

void Ninja::setSpeed(int newSpeed) {
    speed = newSpeed;
}

int Ninja::getSpeed() const {
    return speed;
}

string Ninja::print() {

    std::stringstream ss;
    if (getHitPoints() >= 0) {
        ss << "Name: C " << getName() << endl << "Hitpoints: " << getHitPoints() << endl << "Location: "
           << getLocation().print() << endl;
    } else {
        ss << "Name: N (" << getName() << ")" << endl << "Location: " << getLocation().print() << endl;
    }
    return ss.str();
}
