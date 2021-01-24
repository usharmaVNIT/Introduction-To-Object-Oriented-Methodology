//
//  Polar.cpp
//  Question2
//
//  Created by  BT18CSE021 - UJJWAL SHARMA
//  ASSIGNMENT 2 , 27-NOVEMBER-2020
//

// Contains Definitions of Polar Class



#include "Polar.hpp"

Polar::Polar(double radious,double angle){
    setRadious(radious);
    setAngle(angle);
}

void Polar::setRadious(double radious){
    this->radious = radious;
}
void Polar::setAngle(double angle){
    this->angle = angle; // Setting the angle in degrees
    this->angle_in_radians = angle*PI/180; // Setting the angle in radians
}
// function to calculate x co-ordinate
double Polar::calcX(){
    double x;
    x = radious*cos(angle_in_radians); // cos takes angle in radians so..
    return x;
}
// function to calculate y co-ordinate
double Polar::calcY(){
    double y;
    y = radious*sin(angle_in_radians); // sin takes angle in radians so..
    return y;
}
// overloading + 
Polar Polar::operator+(Polar &point){
    double x,y; // First calculate both x and y
    x = this->calcX()+point.calcX();
    y = this->calcY()+point.calcY();
    double sq_val = x*x + y*y;
    double r = sqrt(sq_val); // calculate the radious √(x**2 + y**2)
    double tan = y/x; // This is the value of tan(œ)
    double ang_in_rad = atan(tan); // This is the value of œ in radians
    double ang = ang_in_rad*180/PI; // Converting to degrees
    Polar retval {r,ang}; // Creating new polar object
    return retval;
}
// Simple print function to print
void Polar::print(){
    std::cout<<"radious = " << radious << " , angle = " << angle << "\nX = " << calcX() << " , Y = " << calcY() << "\n";
}
