#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "CircleBehavior.h"
#include "Circle.h"
#include "Point.h"
#include "Utils.h"

int main() 
{
    //initialize the random generator 
    srand(static_cast<unsigned>(time(nullptr)));

    
    std::vector<Circle> circles;
    int circleNumber = generateRandomNumber(2, 7);        //number of circles randomly
    for(int i  = 0;i <circleNumber; ++i)
    {
        Circle randomCircle = generateRandomCircle();           
        circles.push_back(randomCircle);
    }

    int index = 1;                                      //to display circles following numbers
    std::cout << "Circles' initial attributes:" << std::endl;  
    for(const auto& circle : circles)
    {
        std::cout << "Circle " << index << std::endl;
        displayCircleAttributes(circle);                     ///to display all the circles
        std::cout << "\n\n";
        index++;
    }

    std::cout << "\nOverlapping circles:" << std::endl;
    for(size_t i = 0;i< circles.size();++i)
    {
        for(size_t j = i+1; j < circles.size(); ++j)
        {
            if(circlesOverlap(circles[i],circles[j]))
            {
                std::cout << "Circle " << i+1 << std::endl;
                displayCircleAttributes(circles[i]);                          ///to display all overlaps
                std::cout << "and\n";
                std::cout << "Circle " << j+1 << std::endl;
                displayCircleAttributes(circles[j]);
                std::cout << "\n\n";
            }
        }
    }

    separateOverlappingCircles(circles);

    index = 1;
    std::cout << "\nCircles' attribute after separation:" <<std::endl;
    for(const auto& circle : circles)
    {
        std::cout << "Circle " << index << std::endl;
        displayCircleAttributes(circle);                                    ///all the circles after the atttributes redefinition
        std::cout << "\n\n";
        index++;
    }

    return 0;
}