//
//  StudentClass.hpp
//  oopassignment1
//
//  Created by Ujjwal Sharma (BT18CSE021) on 26/09/20.
//  Copyright © 2020 Official. All rights reserved.
//

#ifndef StudentClass_hpp
#define StudentClass_hpp

#include "headers.hpp"
#include "PersonClass.hpp"



class Student : public Person {
private:
    int STUD_ID;
    int num_courses;
    string courses[10];
    int grade[10];
    string dept;
    
public:
    Student();
    Student(string name,string dept,string house_num,string street_name,string city_name);
    int getId(){
        return STUD_ID;
    }
    int getnumCourses(){
        return this->num_courses;
    }
    double getAvg(){
        double sm=0;
        for(int i=0;i<num_courses;i++){
            sm+=grade[i];
        }
        if(num_courses==0){
            return 0.0;
        }
        return sm/num_courses;
    }
    bool addCourse(string course);
    bool addCoursesGrade(string course,int grade);
    bool dropCourse(string course);
    void printgrade();
    virtual void print();
    virtual ~Student();
 
};

#endif /* StudentClass_hpp */
