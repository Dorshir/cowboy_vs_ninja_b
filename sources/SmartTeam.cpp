
#include "SmartTeam.hpp"

SmartTeam::SmartTeam(Character *leader) : Team(leader) {

}

// Print just like Team2
void SmartTeam::print() {

    for (const auto &member: getMembers()) {
        cout << member->print() << endl;
    }
}


void SmartTeam::attack(Team* enemyTeam) {
    if (enemyTeam == nullptr) {
        throw std::invalid_argument("Null pointer exception!");
    }

    if (!getLeader()->isAlive()) {
        setNextLeader();
    }

    Character* target = nextTarget(enemyTeam);

    // Analyze enemy team and team's own strength
    int enemyCowboys = countCowboys(enemyTeam);
    int enemyNinjas = countNinjas(enemyTeam);

    for (const auto& member : getMembers()) {
        Cowboy* cowboy = dynamic_cast<Cowboy*>(member);
        Ninja* ninja = dynamic_cast<Ninja*>(member);

        if (cowboy != nullptr && cowboy->isAlive()) {
            // Determine the optimal action for Cowboys based on strategy
            if (enemyNinjas > 0 && cowboy->hasboolets()) {
                // Prioritize shooting Ninjas if there are any
                target = findPriorityTarget(enemyTeam, "Ninja");
                if (target != nullptr) {
                    cowboy->shoot(target);
                }
            }
            else if (enemyCowboys > 0 && cowboy->hasboolets()) {
                // If there are no Ninjas, shoot Cowboys
                target = findPriorityTarget(enemyTeam, "Cowboy");
                if (target != nullptr) {
                    cowboy->shoot(target);
                }
            }
            else {
                // Reload if there are no targets or no bullets
                cowboy->reload();
            }
        }
        else if (ninja != nullptr && ninja->isAlive()) {
            // Determine the optimal action for Ninjas based on strategy
            if (enemyCowboys > 0 && ninja->distance(target) <= 1.0) {
                // Prioritize slashing Cowboys if there are any nearby
                target = findPriorityTarget(enemyTeam, "Cowboy");
                if (target != nullptr) {
                    ninja->slash(target);
                }
            }
            else if (enemyNinjas > 0 && ninja->distance(target) <= 1.0) {
                // If there are no nearby Cowboys, slash Ninjas
                target = findPriorityTarget(enemyTeam, "Ninja");
                if (target != nullptr) {
                    ninja->slash(target);
                }
            }
            else {
                // Move towards the nearest target
                ninja->move(target);
            }
        }

        // Update target in case it was eliminated during the attack
        target = nextTarget(enemyTeam);
    }
}

Character* SmartTeam::findPriorityTarget(Team* enemyTeam, const std::string& targetType) {
    Character* priorityTarget = nullptr;
    double currClosestTargetDist = std::numeric_limits<double>::max();

    for (const auto& member : enemyTeam->getMembers()) {
        if (member->isAlive()) {
            Cowboy* cowboy = dynamic_cast<Cowboy*>(member);
            Ninja* ninja = dynamic_cast<Ninja*>(member);

            if (targetType == "Cowboy" && cowboy != nullptr) {
                double distance = getLeader()->distance(member);
                if (distance < currClosestTargetDist) {
                    priorityTarget = member;
                    currClosestTargetDist = distance;
                }
            }
            else if (targetType == "Ninja" && ninja != nullptr) {
                double distance = getLeader()->distance(member);
                if (distance < currClosestTargetDist) {
                    priorityTarget = member;
                    currClosestTargetDist = distance;
                }
            }
        }
    }

    return priorityTarget;
}

int SmartTeam::countCowboys(Team* enemyTeam)  {
    int count = 0;
    for (const auto& member : enemyTeam->getMembers()) {
        if (dynamic_cast<Cowboy*>(member) != nullptr) {
            count++;
        }
    }
    return count;
}

int SmartTeam::countNinjas(Team* enemyTeam)  {
    int count = 0;
    for (const auto& member : enemyTeam->getMembers()) {
        if (dynamic_cast<Ninja*>(member) != nullptr) {
            count++;
        }
    }
    return count;
}




