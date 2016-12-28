/*************************************
Program: Attraction.cpp (milestone2.cpp)
Course:  OOPDS
Year:    2016/02 Trimester 2
Name:    LIEW SOON PANG
ID:      1142700808
Lecture: TC02
Lab:     TT04
Email:   liewsoonpang111@gmail.com  
Phone:   011-10776470
*************************************/

#include <string>
#include "Attraction.h"

Attraction::Attraction(int id,int typeID,string name , string contact,string address)
    :id(id), typeID(typeID), name(name), contact(contact),address(address) {}
void Attraction::displayA(){cout<<"ID= "<<id<<". Name=  "<<name<<endl;}
int Attraction::gettypeID(){return typeID;}
int Attraction::getID(){return id;}
string Attraction::getName(){return name;}
string Attraction::getcontact(){return contact;}
string Attraction::getaddress(){return address;}
