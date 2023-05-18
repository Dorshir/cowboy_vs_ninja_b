
#ifndef COWBOY_VS_NINJA_A_SMARTTEAM_HPP
#define COWBOY_VS_NINJA_A_SMARTTEAM_HPP

#include "Team.hpp"

class SmartTeam : public Team {

public:

    explicit SmartTeam(Character *leader);

    void print() override;

    void attack(Team *enemyTeam) override;



};
#endif //COWBOY_VS_NINJA_A_SMARTTEAM_HPP
