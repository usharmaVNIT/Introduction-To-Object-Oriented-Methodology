//
//  Complex.cpp
//  Question4
//
//  Created by  BT18CSE021 - UJJWAL SHARMA
//  ASSIGNMENT 2 , 27-NOVEMBER-2020

#include "Complex.hpp"
#include <stdexcept>
#include <iostream>

Complex::Complex(double re,double img){
    setReal(re);
    setImaginary(img);
}

void Complex::setReal(double re){
    real = re;
}
void Complex::setImaginary(double img){
    imaginary = img;
}

Complex Complex::operator / (Complex& cmp){
    // if both real and imaginary are zero means denominator will become zero so we will throw a runtime errror eith the following message
    if((cmp.getReal()==0)&&(cmp.getImaginary()==0)){
        throw std::runtime_error("Math error: Cannot divide as division by 0 (real=imag=0)\n");
    }
    double cmpreal = cmp.getReal(); // getting real part of the divident
    double cmpimg = cmp.getImaginary(); // getting imaginary part of the divident
    double deno = cmpreal*cmpreal + cmpimg*cmpimg;
    //div = (a+ib)(c-id)/(c^2+d^2)
    // = ( (ac+bd) + i(bc-ad) ) / (c^2+d^2)
    
    double re = real*cmpreal + imaginary*cmpimg; // ac + bd
    double img = imaginary*cmpreal - real*cmpimg; // bc - ad
    re = re/deno; // Actual real component
    img = img/deno; // Actual imaginary Component
    Complex divided {re,img};
    return divided;
}
// Copy constructor
Complex::Complex(const Complex& obj){
    real = obj.real;
    imaginary = obj.imaginary;
}


void Complex::print(){
    std::cout<< " real = " << real << ", imaginary = " << imaginary << "\n";
}
