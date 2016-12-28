/*************************************
Program: City.h (milestone2.cpp)
Course:  OOPDS
Year:    2016/02 Trimester 2
Name:    LIEW SOON PANG
ID:      1142700808
Lecture: TC02
Lab:     TT04
Email:   liewsoonpang111@gmail.com  
Phone:   011-10776470
*************************************/
#ifndef CITY_H
#define CITY_H

#include <iostream>
#include <string>
#include "Attraction.h"
#include "LinkedList.h"
using namespace std;

class City {
    int id;
    string name;
    LinkedList<Attraction*> attr;

 public:
	friend bool operator<=(const City& c1, const City& c2);
    friend bool operator>=(const City& c1, const City& c2);
     City(int id, string name,LinkedList<Attraction*> attr);

    void displayattr();
    void displayAttrTypeID(int b);
    void displayAttrSpot(int c);
    void displayC();
    int getctyID();
    string getctyName();
    int getFirstAttrLength(int d);
    int getLastAttrLength(int d);
    int getAttrType(int f);
    int gettypeID(int i);
    int getID(int i);
    string getName(int i);
    string getcontact(int i);
    string getaddress(int i);
    int getAttrLength();
    int getAgeLimit(int i);
    double getEntranceFee(int i);
};

#endif
