
#ifndef COWBOY_VS_NINJA_A_COWBOY_HPP
#define COWBOY_VS_NINJA_A_COWBOY_HPP


#include "Character.hpp"

class Cowboy : public Character {

private:

    int booletsNum;

public:

    Cowboy(string name, Point &&location);

    Cowboy(string name, Point &location);

    void shoot(Character *enemy);

    [[nodiscard]] bool hasboolets() const;

    void reload();

    string print() override;

};

#endif //COWBOY_VS_NINJA_A_COWBOY_HPP
