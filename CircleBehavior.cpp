#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstddef>
#include "Circle.h"
#include "Point.h"
#include "Utils.h"


///identify overlaps
bool circlesOverlap(Circle circle1 , Circle circle2)
{
    double distance = sqrt(pow(circle1.center.x-circle2.center.x,2) + pow(circle1.center.y-circle2.center.y, 2));
    return distance < circle1.radius + circle2.radius;
}

///separate circles that overlap
void separateOverlappingCircles(std::vector<Circle>& circles)
{
    //test a circle with the others one by one until there is no more overlap
    for(size_t i = 0; i< circles.size(); ++i)
    {
        for(size_t j = i+1; j < circles.size(); ++j)
        {
            if(circlesOverlap(circles[i], circles[j]))
            {
                Point separationVector;                                       //will contain the coordinates of the vector between the centers of the circles
                separationVector.x = circles[i].center.x - circles[j].center.x;
                separationVector.y = circles[i].center.y - circles[j].center.y;
                double combinedRadius = circles[i].radius + circles[j].radius;             //combine radiusonf the circles
                double distance = sqrt(pow(circles[i].center.x-circles[j].center.x,2) + pow(circles[i].center.y-circles[j].center.y, 2));   //calculate distance between the centers of the circles 
                double translationDistance = combinedRadius - distance;   //contain the distance of overlap
                double angle = acos(separationVector.x/distance);        
                Point distanceVector;                                      ///using here trygonometry to find the coordinates of the distance of the overlap
                distanceVector.x = cos(angle) * translationDistance;
                distanceVector.y = sin(angle) * translationDistance;

                if(circles[i].center.x < circles[j].center.x)
                {
                    circles[i].center.x -= distanceVector.x;
                }
                else
                {
                    circles[i].center.x += distanceVector.x;
                }

                if(circles[i].center.y < circles[j].center.y)
                {
                    circles[i].center.y -= distanceVector.y;
                }
                else
                {
                    circles[i].center.y += distanceVector.y;
                }
            }
        }
    }
}

///generates a random coordinates circle
Circle generateRandomCircle() 
{
    double abs = generateRandomNumber(0,9);
    double ord = generateRandomNumber(0,9);
    Point center;                                    
    center.x = abs;
    center.y = ord;
    double radius = generateRandomNumber(1, 5);
    std::string color = generateRandomColor();
    return Circle(center, radius, color);
} 


///display attributes of a circle
void displayCircleAttributes(Circle circle)                      
{
    std::cout << "Center: (" << circle.center.x << ", " << circle.center.y << ")\n";
    std::cout << "Radius: " << circle.radius << "\n";                                  //this will allow to display the cleanest way 
    std::cout << "Color: " << circle.color << std::endl;
}