//
//  PersonClass.cpp
//  oopassignment1
//
//  Created by Ujjwal Sharma (BT18CSE021) on 26/09/20.
//  Copyright © 2020 Official. All rights reserved.
//

#include "PersonClass.hpp"
using namespace std;
#include <iostream>


// ********************  PERSON CLASS  *************************
//Setting up the static member of Person Class
int Person::count = 0;
Person::Person(string name ,string dept,string house_num,string street_name,string city_name):MAX(6){
    //Setting the relevent info by member methods
    setName(name);
    setDept(dept);
    address = new Address(house_num,street_name,city_name);
    count++;
}
void Person::setName(string name){
    this->name = name;
}
void Person::changeName(string name){
    setName(name);
}
void Person::setDept(string dept){
    this->dept= dept;
}
void Person::changeAddress(string house_num, string street_name, string city_name){
    //Changing the address by invoking set address contained in address object
    address->setAddress(house_num, street_name, city_name);
}
void Person::print(){
    //Printing The relevent information regarding the Person
    
    cout<<"Person Class\n";
    cout<<"Name - "<<getName()<<", Department - "<<getDept()<<"\n";
    cout<<"Address is\n";
    cout<<"House Num - "<<address->getHouse_num()<<" , Street Name - "<<address->getCity_name()<<" , City Name - "<<address->getStreet_name()<<"\n";
}

Person::~Person(){
    cout<<"destructor For Person Class\n";
}
// ********************  PERSON CLASS  *************************
