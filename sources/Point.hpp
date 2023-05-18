
#ifndef COWBOY_VS_NINJA_A_POINT_HPP
#define COWBOY_VS_NINJA_A_POINT_HPP
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>

class Point {

    double x;
    double y;

public:

    Point(double newX, double newY) : x(newX), y(newY) {}

    [[nodiscard]] double distance(Point point) const;

    [[nodiscard]] std::string print() const;

    [[maybe_unused]] static Point moveTowards(Point &source, Point &dest, double dist);

    [[nodiscard]] double getX() const;

    [[nodiscard]] double getY() const;

    [[maybe_unused]] void setX(double newX);

    [[maybe_unused]] void setY(double newY);


};


#endif //COWBOY_VS_NINJA_A_POINT_HPP
