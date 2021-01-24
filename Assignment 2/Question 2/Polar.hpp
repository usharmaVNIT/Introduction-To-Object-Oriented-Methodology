//
//  Polar.hpp
//  Question2
//
//  Created by  BT18CSE021 - UJJWAL SHARMA
//  ASSIGNMENT 2 , 27-NOVEMBER-2020

// Contains Declairations of Polar Class

#ifndef Polar_hpp
#define Polar_hpp
#include <cmath>
#include <iostream>
#include <stdio.h>

#define PI 3.142

class Polar{
    double radious;
    double angle;
    double angle_in_radians;
public:
    Polar(double radious,double angle);
    // Setter and getter methods for angle
    void setAngle(double angle);
    double getAngle(){
        return this->angle;
    }
    // Setter and getter methods for radious
    void setRadious(double radious);
    double getRadious(){
        return this->radious;
    }
    
    double calcX();
    double calcY();
    // for operator overloading
    Polar operator+(Polar &point);
    
    void print();
};

#endif /* Polar_hpp */
