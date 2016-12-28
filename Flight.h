/*************************************
Program: Flight.h (milestone2.cpp)
Course:  OOPDS
Year:    2016/02 Trimester 2
Name:    LIEW SOON PANG
ID:      1142700808
Lecture: TC02
Lab:     TT04
Email:   liewsoonpang111@gmail.com  
Phone:   011-10776470
*************************************/
#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include "LinkedList.h"
#include "LinkedStack.h"


class Flight
{
    int V;    
    LinkedStack<int> *adj;    
	LinkedList<int>ctyPos;
public:
    Flight(int V);  
    void addEdge(int v, int w); 
    bool isReachable(int s, int d);  
	int getflightData();
	bool getctyEmpty();
};

#endif

 

