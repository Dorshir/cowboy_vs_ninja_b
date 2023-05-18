
#ifndef COWBOY_VS_NINJA_A_TEAM2_HPP
#define COWBOY_VS_NINJA_A_TEAM2_HPP

#include "Team.hpp"

class Team2 : public Team {

public:

    explicit Team2(Character *leader);

    void print() override;

    void attack(Team *enemyTeam) override;

};





#endif //COWBOY_VS_NINJA_A_TEAM2_HPP
