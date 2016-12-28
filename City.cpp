/*************************************
Program: City.cpp (milestone2.cpp)
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
#include "City.h"
#include "LinkedList.h"

City::City(int id, string name,LinkedList<Attraction*> attr)
     :id(id),name(name),attr(attr){}
void City::displayattr()
{
	for (int i=1; i<=attr.getLength(); i++)
		attr[i]->displayA();
};
	
void City::displayAttrTypeID(int b)
    {
        for(int i=1; i<=attr.getLength(); i++)
            if(b == attr[i]->gettypeID())
                attr[i]->displayA();
    }

void City::displayAttrSpot(int c)
{
	for(int i = 1; i<=attr.getLength(); i++)
		if(c == attr[i]->getID())
			attr[i]->displaySpot();
}
void City::displayC(){}
int City::getctyID(){return id;}
string City::getctyName(){return name;}

 int City::getFirstAttrLength(int d)
    {
        if(d!=4)
        {
            int temp;
            for(int i=1;i<=attr.getLength();i++)
            {
                if(attr[i]->gettypeID()==d)
                {
                    temp=i;
                    break;
                }
            }
            return attr[temp]->getID();
        }
        else
            return attr[1]->getID();
    }

int City::getLastAttrLength(int d)
    {
        if(d!=4)
        {
             int temp;
             for(int i=1;i<=attr.getLength();i++)
            {
                if(attr[i]->gettypeID()==d)
                {
                    temp=i;
                }
            }
            return attr[temp]->getID();
        }
        else
        {
            int temp = attr.getLength();
            return attr[temp]->getID();
        }
    }

int City::getAttrType(int f){return attr[f]->gettypeID();}
int City::gettypeID(int i){return attr[i]->gettypeID();}
int City::getID(int i){return attr[i]->getID();}
string City::getName(int i){return attr[i]->getName();}
string City::getcontact(int i){return attr[i]->getcontact();}
string City::getaddress(int i){return attr[i]->getaddress();}
int City::getAttrLength(){return attr.getLength();}
int City::getAgeLimit(int i){return attr[i]->getAgeLimit();}
double City::getEntranceFee(int i){return attr[i]->getEntranceFee();}
bool operator<=(const City& c1, const City& c2)
 {
    return c1.name <= c2.name;
 }
 bool operator>=(const City& c1, const City& c2)
 {
    return c1.name >= c2.name;
 }


