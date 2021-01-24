//
//  Facultyclass.hpp
//  oopassignment1
//
//  Created by Ujjwal Sharma (BT18CSE021) on 26/09/20.
//  Copyright © 2020 Official. All rights reserved.
//

#ifndef Facultyclass_hpp
#define Facultyclass_hpp

#include "PersonClass.hpp"
#include "headers.hpp"



class Faculty : public Person {
private:
    int F_ID;
    string designation;
    int num_courses;
    string courses[10];
public:
    Faculty();
    Faculty(string name,string dept,string designation,string house_num,string street_name,string city_name);
    int getId(){
        return this->F_ID;
    }
    bool addCourse(string course);
    bool removeCourse(string course);
    virtual void print();
    void printcourses();
    virtual ~Faculty();
    
};


#endif /* Facultyclass_hpp */
