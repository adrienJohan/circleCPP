#include <string>
#include "Circle.h"

Circle::Circle(Point& cent, double ra, std::string col)    //definition of the constructor prototype written in the .h file
{
    center = cent;
    radius = ra;
    color= col;
}

