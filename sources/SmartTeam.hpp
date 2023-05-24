
#ifndef COWBOY_VS_NINJA_A_SMARTTEAM_HPP
#define COWBOY_VS_NINJA_A_SMARTTEAM_HPP

#include "Team.hpp"

class SmartTeam : public Team {

public:

    explicit SmartTeam(Character *leader);

    void print() override;

    void attack(Team *enemyTeam) override;


    double calculateTeamStrength();

    int countNinjas(Team* enemyTeam);

    int countCowboys(Team* enemyTeam);

    Character *findPriorityTarget(Team *enemyTeam, const string &targetType);

    int countCowboys();

    int countNinjas();
};
#endif //COWBOY_VS_NINJA_A_SMARTTEAM_HPP
