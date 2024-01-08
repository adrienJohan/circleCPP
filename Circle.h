#include <string>
#include "Point.h"

using namespace std;

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
    public:
        Point center;
        double radius;
        string color;

        Circle(Point& cent, double ra, string col);

};

#endif