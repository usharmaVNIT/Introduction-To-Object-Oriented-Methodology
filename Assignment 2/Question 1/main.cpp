//
//  main.cpp
//  Question1
//
//  Created by  BT18CSE021 - UJJWAL SHARMA
//  ASSIGNMENT 2 , 27-NOVEMBER-2020
//

#include <iostream>
#include "Students.hpp"
int main(int argc, const char * argv[]) {

    
    Student st1 ((char*)"name1",(char*)"branch1",3);
    st1.print();
    Student *s2;
    s2 = new Student((char*)"name2",(char*)"branch2",1);
    s2->print();
    StudentDatabase sd(5); // creating database for 5 students
    try{ // error handling
        for (int i=0; i<5; i++) {
            sd[i] = new Student((char*)"name",(char*)"branch",i);
        }
    } catch(std::runtime_error &err){
        std::cerr<<err.what();
    }
    sd.print();
    try {
        sd[5];
    } catch (std::runtime_error &err) {
        std::cerr<<err.what();
    }
    try { // deleting
        for (int i=0; i<5; i++) {
            delete sd[i];
        }
    } catch (std::runtime_error &err) {
        std::cerr<<err.what();
    }
    
    std::cout << "Hello, World!\n";
    return 0;
}
