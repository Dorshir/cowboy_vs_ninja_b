#include "Team2.hpp"

Team2::Team2(Character *leader) : Team(leader) {}

void Team2::print() {

    for (const auto &member: getMembers()) {
        cout << member->print() << endl;
    }
}


void Team2::attack(Team *enemyTeam) {

    if(enemyTeam == nullptr) throw invalid_argument("Null pointer exception!");

    if (!getLeader()->isAlive()) {
        setNextLeader();
    }

    Character *target = nextTarget(enemyTeam);

    for (const auto &member: getMembers()) { // Cowboys
        Cowboy *cowboy = dynamic_cast<Cowboy *>(member);
        if (cowboy != nullptr) {
            if (!cowboy->isAlive()) continue;
            if (target->isAlive()) {
                if (cowboy->hasboolets()) cowboy->shoot(target);
                else cowboy->reload();
            } else {
                target = nextTarget(enemyTeam);
                if (target == nullptr) return;
                else if (cowboy->hasboolets()) cowboy->shoot(target);
                else cowboy->reload();
            }
        } else {

            Ninja *ninja = dynamic_cast<Ninja *>(member);
            if (!ninja->isAlive()) continue;
            if (target->isAlive()) {
                if (ninja->distance(target) <= 1.0) ninja->slash(target);
                else ninja->move(target);
            } else {
                target = nextTarget(enemyTeam);
                if (target == nullptr) return;
                else if (ninja->distance(target) <= 1.0) ninja->slash(target);
                else {
                    ninja->move(target);
                }
            }
        }
    }
}


