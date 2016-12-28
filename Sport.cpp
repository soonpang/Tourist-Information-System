/*************************************
Program: Sport.cpp (milestone2.cpp)
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
#include "Sport.h"
 
 Sport::Sport(int id, int typeID, string name, int ageLimit, string contact, string address )
    :Attraction( id,typeID, name, contact, address),ageLimit(ageLimit){}
 void Sport::displaySpot(){cout<<"The attraction spot you chose is => "<<getName()<<endl<<"The age limit is = "<<ageLimit<<endl<<"Contact = "<<getcontact()<<endl<<"Address = "<<getaddress()<<endl;}
 int Sport::getAgeLimit(){return ageLimit;}
 double Sport::getEntranceFee(){}