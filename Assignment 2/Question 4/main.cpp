//
//  main.cpp
//  Question4
//
//  Created by  BT18CSE021 - UJJWAL SHARMA
//  ASSIGNMENT 2 , 27-NOVEMBER-2020

#include <iostream>
#include "Complex.hpp"

int main(int argc, const char * argv[]) {
    Complex c {4,2};
    Complex c2 {2,2};
    Complex c3 = c/c2;
    c3.print();
    Complex c4 {0,0};
    try {
        Complex c5 = c3/c4;
        // Here the division by zero exception will occur and the program will exit
        c5.print();
    } catch (std::runtime_error &err) {
        std::cerr<<err.what();
    }
    std::cout << "\n";
    return 0;
}
