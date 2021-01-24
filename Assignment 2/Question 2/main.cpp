//
//  main.cpp
//  Question2
//
//  Created by  BT18CSE021 - UJJWAL SHARMA
//  ASSIGNMENT 2 , 27-NOVEMBER-2020
//

#include <iostream>
#include "Polar.hpp"

int main(int argc, const char * argv[]) {
    Polar p1 {8,0.0};
    Polar p2 {6,90.0};
    p1.print();
    p2.print();
    Polar p3 = p1+p2;
    p3.print();
    return 0;
}
