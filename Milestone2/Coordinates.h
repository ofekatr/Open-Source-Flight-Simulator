//
// Created by jokereed on 1/12/19.
//

#ifndef MAILSTONE2_COORDINATES_H
#define MAILSTONE2_COORDINATES_H

#include <complex>

class Coordinates {
    double x = 0, y = 0;
public:
    Coordinates(double x, double y):x(x), y(y){}
    double getHeuristic(Coordinates goal){
        double count = 0;
        count += abs(this->x - goal.getX());
        count += abs(this->y - goal.getY());
        return count;
    }
    double getX(){
        return this->x;
    }
    double getY(){
        return this->y;
    }
};
#endif //MAILSTONE2_COORDINATES_H