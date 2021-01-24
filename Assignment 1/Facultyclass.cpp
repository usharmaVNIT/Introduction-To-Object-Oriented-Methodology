//
//  Facultyclass.cpp
//  oopassignment1
//
//  Created by Ujjwal Sharma (BT18CSE021) on 26/09/20.
//  Copyright © 2020 Official. All rights reserved.
//

#include "Facultyclass.hpp"

// ********************  DERIVED CLASS  2*************************

Faculty::Faculty(string name,string dept,string designation,string house_num,string street_name,string city_name):Person(name, dept, house_num, street_name, city_name){
    this->designation = designation;
    F_ID = getPersonId();
    num_courses=0;
}

bool Faculty::addCourse(string course){
    if(num_courses==getMAX()){//Maximum courses affilated
        cout<<"Already affilated to maximum no. of courses\n";
        return false;
    }
    courses[num_courses]=course;
    num_courses++;
    cout<<"Successfully added course - "<<course<<"\n";
    return true;
}


bool Faculty::removeCourse(string course){
    int i;
    for(i=0;i<num_courses;i++){//Searching for the course
        if(courses[i]==course){//If found the reorder the  courses to delete the desired course
            int j=i+1;
            while(j<num_courses){
                courses[j-1]=courses[j];
                j++;
            }
            num_courses--;
            cout<<"Successfully removed course - "<<course<<"\n";
            return true;
        }
    }
    cout<<"Course not enrolled\n";
    return false;
}
void Faculty::printcourses(){
    int i;
    for(i=0;i<num_courses;i++){
        cout<<i+1<<" - "<<courses[i]<<"\n";
    }
    
    
}
void Faculty::print(){
    // Printing the relevent information of Faculty (v.i.a polymorphism )
    cout<<"Faculty Class\n";
    cout<<"Name - "<<getName()<<", Department - "<<getDept()<<"\n";
    cout<<"Designation is - "<<designation<<"\n";
    cout<<"Faculty Id - "<<getId()<<"\n";
    cout<<"Address is\n";
    cout<<"House Num - "<<address->getHouse_num()<<" , Street Name - "<<address->getStreet_name()<<" , City Name - "<<address->getCity_name()<<"\n";
    cout<<"Courses are - \n";
    printcourses();
}

Faculty::~Faculty(){
    cout<<"destructor For Faculty Class\n";
}
// ********************  DERIVED CLASS  2*************************

