/*************************************
Program: Attraction.h (milestone2.cpp)
Course:  OOPDS
Year:    2016/02 Trimester 2
Name:    LIEW SOON PANG
ID:      1142700808
Lecture: TC02
Lab:     TT04
Email:   liewsoonpang111@gmail.com  
Phone:   011-10776470
*************************************/

#ifndef ATTRACTION_H
#define ATTRACTION_H

#include <iostream>
#include <string>
using namespace std;

class Attraction{
   int id, typeID;
   string name, contact, address;
public:
    Attraction(int id=0,int typeID=0,string name= "", string contact="",string address="");
    void displayA();
    virtual void displaySpot()=0;
    int gettypeID();
    int getID();
    string getName();
    string getcontact();
    string getaddress();
    virtual int getAgeLimit()=0;
    virtual double getEntranceFee()=0;
};

#endif