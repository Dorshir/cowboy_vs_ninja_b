#include "Point.hpp"
using namespace std;

double Point::distance(Point point) const {

        double dx = x - point.x;
        double dy = y - point.y;
        return sqrt(dx * dx + dy * dy);
}

string Point::print() const {

    stringstream ss;
    ss << "(" << x << "," << y << ")";
    return ss.str();
}

[[maybe_unused]] Point Point::moveTowards(Point &source, Point &dest, double dist) {

    if(dist < 0) throw invalid_argument("Negative distance is not allowed!");
    double pointsDistance = source.distance(dest);
    if(dist >= pointsDistance){
        return {dest.getX(), dest.getY()};
    }
    else {
        double ratio = dist / pointsDistance;
        double dx = dest.x - source.x;
        double dy = dest.y - source.y;
        double newX = source.x + ratio * dx;
        double newY = source.y + ratio * dy;
        return { newX, newY };
    }
}

double Point::getX() const {
    return x;
}

double Point::getY() const{
    return y;
}

[[maybe_unused]] void Point::setX(double newX) {
    x = newX;
}

[[maybe_unused]] void Point::setY(double newY) {
    y = newY;
}
