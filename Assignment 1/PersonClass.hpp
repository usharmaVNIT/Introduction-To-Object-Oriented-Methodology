//
//  PersonClass.hpp
//  oopassignment1
//
//  Created by Ujjwal Sharma (BT18CSE021) on 26/09/20.
//  Copyright © 2020 Official. All rights reserved.
//

#ifndef PersonClass_hpp
#define PersonClass_hpp

#include "Addressclass.hpp"
#include "headers.hpp"

// *******************  PERSON CLASS  **********************
class Person{
private:
    string name;
    static int count;
    const int MAX;
    string dept;
    
public:
    Address *address;
    Person();
    Person(string name ,string dept,string house_num,string street_name,string city_name);
    
    //Getter Methods
    string getName(){
        return this->name;
    }
    static int getPersonId(){
        return count;
    }
    
     string getDept(){
     return this->dept;
     }
    int getMAX(){
        return this->MAX;
    }
    //Setter Methods
    void setName(string name);
    void setDept(string dept);
    void changeName(string name);
    void changeAddress(string house_num,string street_name,string city_name);
    
    virtual void print();
    virtual ~Person();
};


#endif /* PersonClass_hpp */
