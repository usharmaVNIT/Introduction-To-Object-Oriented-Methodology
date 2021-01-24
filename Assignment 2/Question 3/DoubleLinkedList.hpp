//
//  DoubleLinkedList.hpp
//  Question3
//
//  Created by  BT18CSE021 - UJJWAL SHARMA
//  ASSIGNMENT 2 , 27-NOVEMBER-2020

// As all the classes will be template classes so all the definitions will be done here
// the compiler will not generate code for them unless they are specifically called





#ifndef DoubleLinkedList_hpp
#define DoubleLinkedList_hpp

#include <stdio.h>
#include <exception>
#include <new>
#include <iostream>





//Initial declairations as they will be friend to DoubleLinkedNode
template <class T>
class Iterator;

template <class T>
class DoubleLinkedList;

// Double LinkedNode class
template <class T>
class DoubleLinkedNode {
    T element; // To store the values
    // The Pointers
    DoubleLinkedNode *next;
    DoubleLinkedNode *prev;
public:
    DoubleLinkedNode(T& element,DoubleLinkedNode *next = NULL , DoubleLinkedNode *prev = NULL){
        setElement(element); // Setting the element
        // Setting the pointers
        setNext(next);
        setPrevious(prev);
    }
    // Function to set element
    void setElement(T& element){
        this->element = element;
    }
    // Function to get element
    T& getElement(){
        return element;
    }
    // Functions to set pointers
    void setNext(DoubleLinkedNode *next){
        this->next=next;
    }
    void setPrevious(DoubleLinkedNode *prev){
        this->prev=prev;
    }
    // Friendship given to both as they will use private members
    friend Iterator<T>;
    friend DoubleLinkedList<T>;
    DoubleLinkedNode(const DoubleLinkedNode &obj){
        //Only copy the values not pointers
        element = obj.element;
        prev = NULL;
        next = NULL;
    }

};

// An Iterator class which will help is in iterating th doubly linked list

template <class T>
class Iterator {
public:
    DoubleLinkedNode<T> *node; // This variable will point to the actual node in the D.L.L
    Iterator(DoubleLinkedNode<T> *node = NULL){
        this->node=node;
    }
    // This is the destructor
    ~Iterator(){
        if(node!=NULL){
            node=NULL;
        }
    }
    // Function to return the value of the node
    T& value(){
        return node->getElement();
    }
    // This next node function sets the current node to its next node and then returns it
    // So dont start the conditions with it->nextNode() as you will skip the first node
    DoubleLinkedNode<T>* nextNode(){
        if(node==NULL){
            return NULL;
        }
        node=node->next;
        return node;
    };
    // Same(Vice-versa) logic as the nextNode given above
    DoubleLinkedNode<T>* prevNode(){
        if(node==NULL){
            return NULL;
        }
        node = node->prev;
        return node;
    }
};

// Now finally a class of Doubly Linked List ..
template <class T>
class DoubleLinkedList {
    // Pointers To first (head) and last (tail) of the linked list
    DoubleLinkedNode<T> *first;
    DoubleLinkedNode<T> *last;
public:
    // Constructor
    DoubleLinkedList(){
        first = last = NULL;
    }
    // To check if the DLL is Empty or not
    bool isEmpty(){
        return first==NULL;
    }
    // Function to insert before a specified Node if present
    void insertBefore(DoubleLinkedNode<T> *nd, T& ele){
            if(isEmpty()){ // If the DLL is empty then add the first node
                first = new DoubleLinkedNode<T>(ele);
                if(first==NULL){// if ths new fails we throw runtime errror with following message
                    std::bad_alloc exception;
                    throw exception;
                }
                
                last = first;
                return; // return after adding
            }
            DoubleLinkedNode<T> *ptr;
            ptr = first;
            // while the specified node is not found then simply search
            while(ptr!=NULL && ptr!=nd){
                ptr = ptr->next;
            }
            if(ptr==NULL){// If the node
                throw std::runtime_error("Given Node is not found so CANNOT INSERT before\n");
            }
            if(ptr->prev==NULL){ // inserting in head position
                DoubleLinkedNode<T> *np = new DoubleLinkedNode<T>(ele);
                if(np==NULL){// if ths new fails we throw runtime errror with following message
                    std::bad_alloc exception;
                    throw exception;
                }
                first->prev = np;
                np->next = first;
                first = np;
            }
            else{
                DoubleLinkedNode<T> *previous = ptr->prev;
                DoubleLinkedNode<T> *np = new DoubleLinkedNode<T>(ele,ptr,previous);
                if(np==NULL){// if ths new fails we throw runtime error
                    std::bad_alloc exception;
                    throw exception;
                }
                previous->next = np;
                ptr->prev = np;
            }
    }
    void insertAfter(DoubleLinkedNode<T> *nd,T& ele){
        if(isEmpty()){
            first = new DoubleLinkedNode<T>(ele);
            if(first==NULL){// if ths new fails we throw runtime error
                std::bad_alloc exception;
                throw exception;
            }
            last = first;
            return;
        }
        DoubleLinkedNode<T> *ptr;
        ptr = first;
        while(ptr!=NULL && ptr!=nd){
            ptr = ptr->next;
        }
        if(ptr==NULL){ // If not found then throw runtime error with following message
            throw std::runtime_error("Given Node is not found so CANNOT INSERT after\n");
        }
        DoubleLinkedNode<T> *nxt = ptr->next;
        DoubleLinkedNode<T> *np = new DoubleLinkedNode<T>(ele,nxt,ptr); // Set the next pointer to next of the ptr and prev to ptr itself
        if(np==NULL){// if ths new fails we throw runtime error
            std::bad_alloc exception;
            throw exception;
        }
        ptr->next = np;
        if(nxt==NULL){
            last = np;
            return;
        }
        nxt->prev = np;
    }
    void deleteNode(DoubleLinkedNode<T> *nd){
            DoubleLinkedNode<T> *ptr = first;
            while(ptr!=NULL && ptr!=nd){ // This condition will help finding if the node is actually present or not
                ptr = ptr->next;
            }
            if(ptr==NULL){ // If not found then throw runtime error with following message
                throw std::runtime_error("Cannot delete the node as it is not present\n");
            }
            if(first==last){ // if found and only element then set both ptrs to null
                free(first);
                first=last=NULL;
            }
            else if(ptr->prev==NULL){ // If it is the first one to remove then make the next one head
                first = first->next;
                first->prev = NULL;
                free(ptr);
            }
            else if(ptr->next==NULL){ // If it is the last one to remove then make the previous one Tail
                last = last->prev;
                last->next = NULL;
                free(ptr);
            }
            else{ // Else (more than 1 nodes and in b/w) do necessary pointer arrangements
                DoubleLinkedNode<T> *previous,*nxt;
                previous = ptr->prev;
                nxt = ptr->next;
                previous->next = nxt;
                nxt->prev = previous;
                free(ptr);
            }
    }
    // Getting the iterator starting with head
    Iterator<T>* getIteratorHead(){
        Iterator<T> *it = new Iterator<T>(first);
        return it;
    }
    // Getting The iterator from the end
    Iterator<T>* getIteratorTail(){
        Iterator<T> *it = new Iterator<T>(last);
        return it;
    }
    
    DoubleLinkedNode<T>* getFirst(){
        return first;
    }
    
    DoubleLinkedNode<T>* getLast(){
        return last;
    }
    // A simple function to print DLL using iterator class
    void printDLL(){
        Iterator<T> *it = getIteratorHead();
        while(it->node){
            std::cout<<it->value()<<" , ";
            it->nextNode();
        }
        std::cout<<"\n";
    }
    // A simple function to print DLL in reverse using iterator class
    void printDLLreverse(){
        Iterator<T> *it = getIteratorTail();
        while(it->node){
            std::cout<<it->value()<<" , ";
            it->prevNode();
        }
        std::cout<<"\n";
    }
    // Destructor for DoubleLinkedList
    ~DoubleLinkedList(){
        Iterator<T> *it = getIteratorHead(); // get iterator head
        while(it->node){ // While we do not reach the end
            DoubleLinkedNode<T> *nd = it->node; // Mark the node
            std::cout<<it->value()<<" ";
            it->nextNode(); // set iterator to next node
            free(nd); // Free the node
        }
        first=last=NULL;
    }
};



#endif /* DoubleLinkedList_hpp */
