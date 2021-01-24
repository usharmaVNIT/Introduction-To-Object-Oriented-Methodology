//
//  main.cpp
//  Question3
//
//  Created by  BT18CSE021 - UJJWAL SHARMA
//  ASSIGNMENT 2 , 27-NOVEMBER-2020//

#include <iostream>
#include <string>
#include "DoubleLinkedList.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    DoubleLinkedList<int> dll;
    if(dll.isEmpty()){
        std::cout<<"Empty\n";
    }
    int tst = 1000;
    DoubleLinkedNode<int> testnode {tst};
    int i = 5;
    try {
        dll.insertAfter(NULL, i);
        dll.printDLL();
        int j = 10;
        dll.insertAfter(dll.getFirst(), j);
        dll.printDLL();
        dll.printDLLreverse();
        int tmp = 9;
        dll.insertBefore(dll.getFirst(), tmp);
        dll.printDLL();
        dll.insertAfter(dll.getLast(), tmp);
        dll.printDLL();
    } catch (std::runtime_error &err){
        std::cerr<<err.what();
    } catch (std::bad_alloc &err){
        std::cerr<<err.what();
    }
    // Now Error will occur in both the cases
    
    try {
        int j = 15;
        dll.insertAfter(NULL, j);
    } catch (std::runtime_error &err){
        std::cerr<<err.what();
    } catch (std::bad_alloc &err){
        std::cerr<<err.what();
    }
    
    try {
        int tmp = 15;
        dll.insertBefore(&testnode, tmp);
    } catch (std::runtime_error &err){
        std::cerr<<err.what();
    } catch (std::bad_alloc &err){
        std::cerr<<err.what();
    }
    
    Iterator<int> *it = dll.getIteratorHead();
    while(it->node && it->node->getElement()!=10){
        it->nextNode();
    }
    try{
        dll.deleteNode(it->node);
        dll.printDLL();
        dll.deleteNode(NULL);
    } catch (std::runtime_error &err){
        std::cerr<<err.what();
    }
    
    DoubleLinkedList<std::string> strdll;
    std::string s = "new",s1 = "new 1",s2 = "new 2";
    try{
        strdll.insertAfter(NULL, s);
        strdll.insertAfter(strdll.getFirst(), s1);
        strdll.printDLL();
        strdll.insertBefore(strdll.getLast(), s2);
        strdll.printDLL();
    } catch (std::runtime_error &err){
        std::cerr<<err.what();
    } catch (std::bad_alloc &err){
        std::cerr<<err.what();
    }
    try {
        strdll.deleteNode(strdll.getFirst());
        strdll.printDLL();
    } catch (std::runtime_error &err){
        std::cerr<<err.what();
    }
    std::cout << "\n";
    return 0;
}
