/*************************************
Program: Culture.cpp (milestone2.cpp)
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
#include "Culture.h"

Culture::Culture(int id, int typeID, string name,double entranceFee,  string contact, string address )
    :Attraction( id,typeID, name, contact, address),entranceFee(entranceFee){}
void Culture::displaySpot(){cout<<"The attraction spot you chose is => "<<getName()<<endl<<"The entrance fee is = RM "<<entranceFee<<endl<<"Contact = "<<getcontact()<<endl<<"Address = "<<getaddress()<<endl;}
double Culture::getEntranceFee(){return entranceFee;}
int Culture::getAgeLimit(){}
