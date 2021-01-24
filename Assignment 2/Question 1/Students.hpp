//
//  Students.hpp
//  Question1
//
//  Created by  BT18CSE021 - UJJWAL SHARMA
//  ASSIGNMENT 2 , 27-NOVEMBER-2020
//


// Contains Declairation of Student Class and StudentDatabase Class

#ifndef Students_hpp
#define Students_hpp

#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>
#include <stdexcept>



class Student{
    char *name,*branch;
    int roll_no;
public:
    Student(char* name,char* branch,int roll_no);
    // Setter and getter methods for Name
    void setName(char *name);
    char* getName(){
        return this->name;
    }
    // Setter and getter methods for branch
    void setBranch(char* branch);
    char* getBranch(){
        return this->branch;
    }
    // Setter and getter methods for Roll no
    void setRollNo(int rollno);
    int getRollNo(){
        return this->roll_no;
    }
    // For operator overloading
    void* operator new(size_t size);
    void operator delete (void* ptr);
    void print();
    Student(const Student& obj);
    ~Student();
};


class StudentDatabase {
public:
    Student **array;
    int size;
    // Constructor
    StudentDatabase(int size);
    // for operator overloading
    Student*& operator[] (int i);
    void print();
    
};

#endif /* Students_hpp */
