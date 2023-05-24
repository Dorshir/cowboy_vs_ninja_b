
#ifndef COWBOY_VS_NINJA_A_CHARACTER_HPP
#define COWBOY_VS_NINJA_A_CHARACTER_HPP

#include "Point.hpp"
#include <string>
#include <sstream>

using namespace std;

class Character {
    
private:

    Point location;
    int hitpoints;
    string name;
    bool teamFlag;
    
public:

    Character(string name, int hitpoints, Point& location);

    [[nodiscard]] bool isAlive() const;
    double distance(Character* other);
    void hit(int hitNum);

    // Getters
    [[nodiscard]] int getHitPoints() const;
    [[maybe_unused]] string getName();
    [[maybe_unused]] Point& getLocation();
    [[nodiscard]] bool getTeamFlag() const;

    // Setters
    void setName(const string& newName);
    void setHitPoints(int newHitPoints);
    void setLocation(const Point& newLocation);
    void setTeamFlag();


    virtual string print() = 0;
    virtual ~Character() = default;

    Character(const Character& other) = default;
    Character& operator=(const Character& other) = default;
    Character(Character&& other) = default;
    Character& operator=(Character&& other) = default;

};

#endif //COWBOY_VS_NINJA_A_CHARACTER_HPP
