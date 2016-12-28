/*************************************
Program: Culture.h (milestone2.cpp)
Course:  OOPDS
Year:    2016/02 Trimester 2
Name:    LIEW SOON PANG
ID:      1142700808
Lecture: TC02
Lab:     TT04
Email:   liewsoonpang111@gmail.com  
Phone:   011-10776470
*************************************/

#ifndef CULTURE_H
#define CULTURE_H

#include <iostream>
#include <string>
#include "Attraction.h"
using namespace std;

class Culture:public Attraction
{
    double entranceFee;
public:
    Culture(int id, int typeID, string name,double entranceFee,  string contact, string address );
    void displaySpot();
    double getEntranceFee();
	int getAgeLimit();
    
};

#endif