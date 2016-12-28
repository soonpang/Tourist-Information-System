/*************************************
Program: Shopping.cpp (milestone2.cpp)
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
#include "Shopping.h"

Shopping::Shopping(int id, int typeID, string name, string contact, string address )
    :Attraction( id,typeID, name, contact, address){}
void Shopping::displaySpot(){cout<<"The attraction spot you chose is => "<<getName()<<endl<<"Contact = "<<getcontact()<<endl<<"Address = "<<getaddress()<<endl;}
int Shopping::getAgeLimit(){}
double Shopping::getEntranceFee(){}