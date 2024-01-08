#include <string>
#include <cstdlib>  //for the rand function 
#include <ctime> //for time function 
#include <iostream>
#include <vector>
#include "Utils.h"

///generates a random number between a predefined intervamm
int generateRandomNumber(int min , int max)
{
    return rand() % (max - min + 1) +min;         //random's algorithm 
}

///generates a random color between seven predefined colors
std::string generateRandomColor(){
    std::vector<std::string> colors = {"Red","Green","Blue","Yellow","Purple","Orange","Pink"};
    int index = generateRandomNumber(0, colors.size() -1);
    return colors[index];
}