//
//  Addressclass.hpp
//  oopassignment1
//
//  Created by Ujjwal Sharma (BT18CSE021) on 26/09/20.
//  Copyright © 2020 Official. All rights reserved.
//

#ifndef Addressclass_hpp
#define Addressclass_hpp

#include "headers.hpp"
// *******************  ADDRESS CLASS  **********************
// Declairatin Of Address Class
class Address {
private:
    string house_num,street_name,city_name;
    
public:
    Address(string house_name,string street_name,string city_name);
    // Getter Methods
    string getHouse_num(){
        return this->house_num;
    }
    string getStreet_name(){
        return this->street_name;
    }
    string getCity_name(){
        return this->city_name;
    }
    // Setter Methods
    void setAddress(string house,string street, string city);
    void setHouse_num(string house);
    void setStreet_name(string street);
    void setCity_name(string city);
};

#endif /* Addressclass_hpp */
