#include "Circle.h"
#include <vector>

#ifndef CIRCLEBEHAVIOR_H
#define CIRCLEBEHAVIOR_H

bool circlesOverlap(Circle circle1 , Circle circle2);
void separateOverlappingCircles(std::vector<Circle>& circles);
Circle generateRandomCircle();
void displayCircleAttributes(Circle circle);


#endif