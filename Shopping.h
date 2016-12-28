/*************************************
Program: Shopping.h (milestone2.cpp)
Course:  OOPDS
Year:    2016/02 Trimester 2
Name:    LIEW SOON PANG
ID:      1142700808
Lecture: TC02
Lab:     TT04
Email:   liewsoonpang111@gmail.com  
Phone:   011-10776470
*************************************/

#ifndef SHOPPING_H
#define SHOPPING_H

#include <iostream>
#include <string>
#include "Attraction.h"
using namespace std;

class Shopping:public Attraction
{
public:
    Shopping(int id, int typeID, string name, string contact, string address );
    void displaySpot();
	int getAgeLimit();
    double getEntranceFee();

};
#endif