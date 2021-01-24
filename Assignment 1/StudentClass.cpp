//
//  StudentClass.cpp
//  oopassignment1
//
//  Created by Ujjwal Sharma (BT18CSE021) on 26/09/20.
//  Copyright © 2020 Official. All rights reserved.
//

#include "StudentClass.hpp"


// ********************  DERIVED CLASS  1*************************
// Defining the constructor for Students Class
Student::Student(string name,string dept,string house_num,string street_name,string city_name):Person(name, dept, house_num, street_name, city_name){
    num_courses=0;
    STUD_ID = getPersonId();
}
bool Student::addCourse(string course){
    if(num_courses==getMAX()){//If courses are already full
        cout<<"Maximum Courses enrolled\n";
        return false;
    }
    else{
        courses[num_courses] = course;
        num_courses++;
        cout<<"SuccessFully Added course - "<<course<<"\n";
        return true;
    }
}
bool Student::addCoursesGrade(string course, int grade){
    int i=0;
    for(i=0;i<num_courses;i++){// Linear search through the course array and setting the corresponding grade
        if(courses[i]==course){
            this->grade[i] = grade;
            return true;
        }
    }
    cout<<"No Course Found\n";
    return false;
}

bool Student::dropCourse(string course){
    int i;
    for(i=0;i<getnumCourses();i++){//Searching for the course
        if(courses[i]==course){//If found the reorder the  courses to delete the desired course
            int j=i+1;
            while(j<getnumCourses()){
                grade[j-1] = grade[j];
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

void Student::printgrade(){
    int i;
    for(i=0;i<getnumCourses();i++){
        cout<<"Course - "<<courses[i]<<" < Grade = "<<grade[i]<<"\n";
    }
}

void Student::print(){
    // Printing the relevent information of Student (v.i.a polymorphism )
    cout<<"Student Class\n";
    cout<<"Name - "<<getName()<<", Department - "<<getDept()<<"\n";
    cout<<"Student's id - "<<getId()<<"\n";
    cout<<"Address is\n";
    cout<<"House Num - "<<address->getHouse_num()<<" , Street Name - "<<address->getStreet_name()<<" , City Name - "<<address->getCity_name()<<"\n";
    cout<<"Course and Grades are\n";
    printgrade();
}

Student::~Student(){
    cout<<"destructor For Studdent Class\n";
}
// ********************  DERIVED CLASS  1*************************

