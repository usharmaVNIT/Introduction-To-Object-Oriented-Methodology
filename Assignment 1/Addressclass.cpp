//
//  Addressclass.cpp
//  oopassignment1
//
//  Created by Ujjwal Sharma (BT18CSE021) on 26/09/20.
//  Copyright © 2020 Official. All rights reserved.
//

#include "Addressclass.hpp"

// *******************  ADDRESS CLASS  **********************

// Defining Constructer For Address Class
Address::Address(string house_name,string street_name,string city_name){
    //Setting the address using member function
    setAddress(house_name, street_name, city_name);
}
//Defining the setAddress funct as it will be used in constructor
void Address::setAddress(string house, string street, string city){
    setHouse_num(house);
    setStreet_name(street);
    setCity_name(city);
}

void Address::setCity_name(string city){
    city_name = city;
}

void Address::setStreet_name(string street){
    street_name = street;
}

void Address::setHouse_num(string house){
    house_num = house;
}



// *******************  ADDRESS CLASS  **********************
