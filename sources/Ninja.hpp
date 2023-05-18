
#ifndef COWBOY_VS_NINJA_A_NINJA_HPP
#define COWBOY_VS_NINJA_A_NINJA_HPP


#include "Character.hpp"

class Ninja : public Character {

private:

    int speed;

public:

    Ninja(string name, int hitpoints, Point &location, int speed);

    void setSpeed(int newSpeed);

    [[nodiscard]] int getSpeed() const;

    void move(Character *enemy);

    void slash(Character *enemy);

    string print() override;

};

#endif //COWBOY_VS_NINJA_A_NINJA_HPP
