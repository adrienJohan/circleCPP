#include <string>

using namespace std;

#ifndef POINT_H
#define POINT_H

class Point
{
    public:
        double x, y;
        
        Point() = default;
        Point(double abs, double ord);
        

};

#endif