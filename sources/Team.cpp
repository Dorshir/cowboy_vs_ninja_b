#include "Team.hpp"
#include <algorithm>

using namespace std;

void Team::add(Character *newMember) {

    if (members.size() == 10) throw runtime_error("10 members already in team.\n");
    else if (find(members.begin(), members.end(), newMember) != members.end())
        throw invalid_argument("Member is already assigned to this team.\n");
    else if (newMember->getTeamFlag()) throw runtime_error("Member is already assigned to another team!\n");
    else {
        members.push_back(newMember);
    }
}

Team::Team(Character *leader) : leader(leader) {
    members.reserve(10);
    members.push_back(leader);
}

void Team::attack(Team *enemyTeam) {



}

int Team::stillAlive() {

    int counter = 0;
    for (const auto &member: members) {
        if (member->isAlive()) counter++;
    }
    return counter;
}

void Team::print() {

    for (const auto& member : members) {
        Cowboy* cowboy = dynamic_cast<Cowboy *>(member);
        if (cowboy != nullptr) {
            cout << member->print() << endl;
        }
    }
    for (const auto& member : members) {
        Ninja* ninja = dynamic_cast<Ninja*>(member);
        if (ninja != nullptr) {
            cout << member->print() << endl;
        }
    }
}

Team::~Team() {

    for (const auto& member: members) {
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

