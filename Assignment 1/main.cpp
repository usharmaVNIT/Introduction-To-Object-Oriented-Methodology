//
//  main.cpp
//  oopassignment1
//
//  Created by Ujjwal Sharma (BT18CSE021) on 24/09/20.
//  Copyright © 2020 Official. All rights reserved.
//

#include <iostream>
#include "headers.hpp"
#include "StudentClass.hpp"
#include "Facultyclass.hpp"
#include "PersonClass.hpp"

void print_all(Person *person){
    person->print();
}

int main(int argc, const char * argv[]) {
    Person p1("Name1","C.S.E","House 1","Stree 1","City 1");
    Student s1("Student1","C.S.E","House 1","Stree 1","City 1");
    Faculty f1("Faculty1","C.S.E","Professor","House 1","Stree 1","City 1");
    s1.addCourse("I.O.O.M");
    s1.addCourse("O.S");
    s1.addCourse("N.F.T");
    s1.addCourse("D.A.A");
    s1.addCourse("T.O.C");
    s1.addCourse("S.L");
    s1.addCourse("S.L.2");
    s1.addCoursesGrade("I.O.O.M", 95);
    s1.addCoursesGrade("O.S", 96);
    s1.addCoursesGrade("N.F.T", 93);
    s1.addCoursesGrade("D.A.A", 97);
    s1.addCoursesGrade("S.L", 99);
    s1.addCoursesGrade("T.O.C", 100);
    s1.dropCourse("T.O.C");
    s1.addCoursesGrade("S.L.2", 96);
    cout<<s1.getnumCourses();
    
    cout<<"AVG IS - "<<s1.getAvg()<<endl;
    s1.dropCourse("I.O.O.M");
    s1.printgrade();
    s1.dropCourse("I.O.O.M");
    s1.printgrade();
    
    f1.addCourse("I.O.O.M");
    f1.addCourse("O.S");
    f1.removeCourse("ls");
    
    
    cout<<"********* Print All **********\n";
    print_all(&p1);
    print_all(&s1);
    print_all(&f1);
    
    
    
    
    s1.changeAddress("changed house 1", "changed street 1", "changed city 1");
    s1.print();
    return 0;
}
