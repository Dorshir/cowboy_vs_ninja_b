#include "Team.hpp"

using namespace std;

void Team::add(Character *newMember) {

    if (members.size() == 10) throw runtime_error("10 members already in team.\n");
    else if (find(members.begin(), members.end(), newMember) != members.end())
        throw invalid_argument("Member is already assigned to this team.\n");
    else if (newMember->getTeamFlag()) throw runtime_error("Member is already assigned to another team!\n");
    else {
        members.push_back(newMember);
        newMember->setTeamFlag();
    }
}

Team::Team(Character *newLeader) {

    if(newLeader->getTeamFlag()) throw runtime_error("Leader is already assigned to another team!");
    else {
        leader = newLeader;
        members.reserve(10);
        members.push_back(newLeader);
        newLeader->setTeamFlag();
    }
}

void Team::setNextLeader() {

    Character *potentialLeader = nullptr;
    double currClosestTargetDist = numeric_limits<double>::max();
    for (const auto &member: members) {
        if (member->isAlive() && leader->distance(member) < currClosestTargetDist) {
            potentialLeader = member;
            currClosestTargetDist = leader->distance(member);
        }
    }
    leader = potentialLeader;
}

Character *Team::nextTarget(Team *enemyTeam) {

    Character *potentialTarget = nullptr;
    double currClosestTargetDist = numeric_limits<double>::max();
    for (const auto &member: enemyTeam->members) {
        if (member->isAlive() && leader->distance(member) < currClosestTargetDist) {
            potentialTarget = member;
            currClosestTargetDist = leader->distance(member);
        }
    }
    return potentialTarget;
}

void Team::attack(Team *enemyTeam) {

    if(enemyTeam == nullptr) throw invalid_argument("Null pointer exception!");
    else if(enemyTeam->stillAlive() < 1) throw runtime_error("Enemy team is dead.") ;
    else if(stillAlive() < 1) throw runtime_error("Team is dead.");
    else if (!leader->isAlive()) {
        setNextLeader();
    }
    if(leader == nullptr) return;

    Character *target = nextTarget(enemyTeam);

    for (const auto &member: members) { // Cowboys
        Cowboy *cowboy = dynamic_cast<Cowboy *>(member);
        if (cowboy != nullptr) {
            if(!cowboy->isAlive()) continue;
            if (target->isAlive()) {
                if (cowboy->hasboolets()) cowboy->shoot(target);
                else cowboy->reload();
            } else {
                target = nextTarget(enemyTeam);
                if (target == nullptr) return;
                else if (cowboy->hasboolets()) cowboy->shoot(target);
                else cowboy->reload();
            }
        }
    }

    for (const auto &member: members) { // Ninjas
        Ninja *ninja = dynamic_cast<Ninja *>(member);
        if (ninja != nullptr) {
            if(!ninja->isAlive()) continue;
            if (target->isAlive()){
                if(ninja->distance(target) <= 1.0) ninja->slash(target);
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

int Team::stillAlive() {

    int counter = 0;
    for (const auto &member: members) {
        if (member->isAlive()) counter++;
    }
    return counter;
}

void Team::print() {

    for (const auto &member: members) {
        Cowboy *cowboy = dynamic_cast<Cowboy *>(member);
        if (cowboy != nullptr) {
            cout << member->print() << endl;
        }
    }
    for (const auto &member: members) {
        Ninja *ninja = dynamic_cast<Ninja *>(member);
        if (ninja != nullptr) {
            cout << member->print() << endl;
        }
    }
}

Team::~Team() {

    for (const auto &member: members) {
        delete member;
    }
}

void Team::setLeader(Character *newLeader) {
    leader = newLeader;
}

Character *Team::getLeader() {
    return leader;
}

vector<Character *> Team::getMembers() {
    return members;
}

