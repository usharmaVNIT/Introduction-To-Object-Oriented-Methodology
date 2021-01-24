//
//  Complex.hpp
//  Question4
//
//  Created by  BT18CSE021 - UJJWAL SHARMA
//  ASSIGNMENT 2 , 27-NOVEMBER-2020

#ifndef Complex_hpp
#define Complex_hpp

#include <stdio.h>
#include <exception>

class Complex {
    double real;
    double imaginary;
public:
    Complex(double re,double img);
    // Setter and getter function for real part
    void setReal(double re);
    double getReal(){
        return real;
    }
    // Setter and getter function for imaginary part
    void setImaginary(double img);
    double getImaginary(){
        return imaginary;
    }
    
    // For overloading
    Complex operator / (Complex& cmp);
    Complex(const Complex& obj);
    
    void print();
    
    
};


#endif /* Complex_hpp */
