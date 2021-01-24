//
//  Students.cpp
//  Question1
//
//  Created by  BT18CSE021 - UJJWAL SHARMA
//  ASSIGNMENT 2 , 27-NOVEMBER-2020
//

// Contains Definitions of Student Class and StudentDatabase Class

#include "Students.hpp"

Student::Student(char* name,char* branch,int roll_no){
    setName(name);
    setBranch(branch);
    setRollNo(roll_no);
}

void Student::setName(char *name){
    if(this->name==NULL){ // If the name is null i.e constructor called for stack allocation (not by new)
        this->name = (char*)malloc(32*sizeof(char)); // Allocate some memory
    }
    strcpy(this->name,name);
}
void Student::setBranch(char *branch){
    if(this->branch==NULL){// If the branch is null i.e constructor called for stack allocation (not by new)
        this->branch = (char*)malloc(32*sizeof(char)); // Allocate some memory
    }
    strcpy(this->branch, branch);
}

void Student::setRollNo(int roll_no){
    this->roll_no = roll_no;
}

void* Student::operator new(size_t size){
    void *ptr;
    // Allocate memory for p
    ptr = malloc(size);
    // Now we will use a predefined function to interpret ( tell the  compiler ) ptr as Student * but currently it is void *. we need ptr to be of Student * to manupulate the name and branch
    (reinterpret_cast<Student *>(ptr))->name = (reinterpret_cast<char*>(malloc(32)));
    (reinterpret_cast<Student *>(ptr))->branch = (reinterpret_cast<char*>(malloc(32)));
    return ptr;
}

void Student::operator delete(void *ptr){
    // Again as the pointer is void * so we need to tell the compiler to reinterpret it as Student *
    // Same argument as above
    free(reinterpret_cast<Student *>(ptr)->name);
    free(reinterpret_cast<Student*>(ptr)->branch);
    // Finally Free this ptr
    free(ptr);
}
// A function to print the details
void Student::print(){
    std::cout<<" Name - "<<name << " , Branch - "<<branch << " , Roll No - "<<roll_no << "\n";
}
// Copy constructor for Student Class
Student::Student(const Student &obj){
    strcpy(name, obj.name);
    strcpy(branch, obj.branch);
    roll_no = obj.roll_no;
}
// Destructor for Student Class
Student::~Student(){
    if(name!=NULL){
        free(name);
        name = NULL;
    }
    if(branch!=NULL){
        free(branch);
        branch = NULL;
    }
}

// Constructor For StudentDatabase
StudentDatabase::StudentDatabase(int size){
    this->size = size;
    array = (Student **)malloc(size*sizeof(Student *));
    for(int i=0;i<size;i++){
        array[i] = NULL;
    }
}
// Overloading Subscript [] operator
Student*& StudentDatabase::operator[](int i){
    if(i>=size || i<0){
        std::string msg ="Array Out of index , range = ["+std::to_string(0)+" ,"+std::to_string(size-1)+"]\n";
        throw std::runtime_error(msg);
    }
    return array[i];
    
}
// To print the details of students
void StudentDatabase::print(){
    std::cout<<"Print Called\n";
    for(int i=0;i<size;i++){
        if(array[i]!=NULL){
            std::cout<<"Student - "<<i<< ":";
            array[i]->print();
        }
    }
}
