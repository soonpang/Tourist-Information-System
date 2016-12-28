/*************************************
Program: milestone2.cpp
Course:  OOPDS
Year:    2016/02 Trimester 2
Name:    LIEW SOON PANG
ID:      1142700808
Lecture: TC02
Lab:     TT04
Email:   liewsoonpang111@gmail.com  
Phone:   011-10776470
*************************************/

#include <iostream>
#include <string>
#include "linkedlist.h"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "City.h"
#include "Attraction.h"
#include "Sport.h"
#include "Culture.h"
#include "Shopping.h"
#include "Flight.h"

using namespace std;

int stringchgint(string str)        //Change string to integer function
{
    int i;
    if(atoi(str.c_str()))
    {
        i=atoi(str.c_str());
    }
    else
    {
        i=0;
    }
    return i;

}

int tour(LinkedList<City> &cts)                      //Tourist mode
{
    int inputCty, inputTA, AttrSpot, position,inputCF,ctyfID,ctysID,ctyfPos,ctysPos;
    string s_inputCty,s_inputTA,s_AttrSpot,s_inputCF,s_ctyfID,s_ctysID,ctyfName,ctysName;
    bool errorChecking = false;                            //Error checking

    cout<<"City or Flight selection"<<endl;					//City or Flight selection menu
    cout<<"1.City"<<endl;
    cout<<"2.Flight"<<endl;
    cout<<"Please choose city or flight"<<endl;
	cout<<"To go back  to menu type back"<<"\n"<<"=>";
    getline(cin,s_inputCF);
    inputCF=stringchgint(s_inputCF);


    if(inputCF==1)									//Input 1 to enter City
    {
        while(!errorChecking)					//Error checking loop for City
        {
            cout<<"CITY SELECTION LIST"<<endl;
            for(int i=1;i<=cts.getLength();i++)
            cout<<cts[i].getctyID()<<" "<<cts[i].getctyName()<<endl;
            cout<<"Please chose a city by typing in the proper id"<<endl;
            cout<<"To go back  to menu type back"<<"\n"<<"=>";

            getline(cin,s_inputCty);
            if(s_inputCty=="back")
                return 0;
            inputCty=stringchgint(s_inputCty);

            for(int i=1; i<=cts.getLength(); i++)
                if(inputCty == cts[i].getctyID())
                    errorChecking = true;     			//To exit this error checking loop
            for(int i=1;i<=cts.getLength();i++)
                if(inputCty==cts[i].getctyID())
                    position=i;

            if(!errorChecking)										//To continue ask if wrong input
                cout<<"Please chose a city by typing in the proper id"<<endl;
        }

        cout<<endl;
        cout<<"TYPE SELECTION AND ALL ATTRACTION SELECTION LIST"<<endl;      //Type selection and all attraction selection list
        cout<<"1.Sport"<<endl;
        cout<<"2.Culture"<<endl;
        cout<<"3.Shopping"<<endl;
        cout<<"4.All Attractions"<<endl;
        cout<<"Choose whether you want the type of attraction or all the attractions"<<endl;
        cout<<"To go back  to menu type back"<<"\n"<<"=>";
        getline(cin,s_inputTA);
        if(s_inputTA=="back")
            return 0;
        inputTA=stringchgint(s_inputTA);
        cout<<endl;
        while (inputTA<1 || inputTA>4)
        {
            cout<<"Please chose an attraction by typing in the id"<<endl;      //Prevent error
            cout<<"=>";
            getline(cin,s_inputTA);
            if(s_inputTA=="back")                               //used to go back menu
                return 0;
            inputTA=stringchgint(s_inputTA);
        }
        if(inputTA == 4)                                //Input for showing all attractions
        {
            cout<<"LIST OF ALL THE ATTRACTIONS"<<endl;
            cts[position].displayattr();
        }

        else
        {
            cout<<"THE ATTRACTIONS"<<endl;                     //To show the attractions after selecting type
            cts[position].displayAttrTypeID(inputTA);
        }


        cout<<"Please choose a attraction spot by typing in the id for more information"<<endl;      //To go into further information
        cout<<"To go back type back"<<"\n"<<"=>";
        getline(cin,s_AttrSpot);
        if(s_AttrSpot=="back")
            return 0;
        AttrSpot=stringchgint(s_AttrSpot);
        cout<<endl;
        while ((AttrSpot<cts[position].getFirstAttrLength(inputTA) || AttrSpot>cts[position].getLastAttrLength(inputTA))) //Error prevention for attraction spot input
        {
            cout<<"Please enter the proper attraction spot id"<<"\n"<<"=>";
            getline(cin,s_AttrSpot);
            if(s_AttrSpot=="back")
                return 0;
            AttrSpot=stringchgint(s_AttrSpot);
            cout<<endl;
        }
        cts[position].displayAttrSpot(AttrSpot);
        cout<<endl;
    }
	else if(inputCF==2)
	{
		cout<<"Choose the city you want to start"<<endl;
		for(int i=1;i<=cts.getLength();i++)
			cout<<cts[i].getctyID()<<"\t"<<cts[i].getctyName()<<endl;
		getline(cin,s_ctyfID);
		ctyfID=stringchgint(s_ctyfID);
		cout<<"Choose the city you want to reach"<<endl;
			for(int i=1;i<=cts.getLength();i++)
				if(ctyfID!=cts[i].getctyID())
				cout<<cts[i].getctyID()<<"\t"<<cts[i].getctyName()<<endl;
		getline(cin,s_ctysID);
		ctysID=stringchgint(s_ctysID);
		
		for(int i=1;i<=cts.getLength();i++)
					if(ctyfID==cts[i].getctyID())
						ctyfPos=i;
		for(int i=1;i<=cts.getLength();i++)
					if(ctysID==cts[i].getctyID())
						ctysPos=i;
		for(int i=1;i<=cts.getLength();i++)					
                    if(ctyfID==cts[i].getctyID())
                        ctyfName=cts[i].getctyName();
		for(int i=1;i<=cts.getLength();i++)					
                    if(ctysID==cts[i].getctyID())
                        ctysName=cts[i].getctyName();
			
		
		Flight g(cts.getLength());
		if(g.isReachable(ctyfPos, ctysPos))
		{
			  cout<< "\n There is a path from " <<ctyfName<< " to " <<ctysName;
			 while(!g.getctyEmpty())
			 {
				 for(int i=1;i<=cts.getLength();i++)
				 {
					 if(g.getflightData()==cts[i].getctyID())
						 cout<<cts[i].getctyName()<<"to"<<endl;
				 }
			 }
		}
		else
			cout<< "\n There is no path from " << ctyfName<< " to " <<ctysName<<endl;
	}
		
}

		
	
	
	
	

void loadFunc(LinkedList<City> &cts, LinkedList<Attraction*>& attr)             //Function for load
{
    cts.clear();
    attr.clear();
    string input,s_cityID,cityName,s_attrID,s_attrType,attrName,s_attrAgelimit,s_attrEntrancefee,attrContact,attrAddress,name;
    int cityC=1,attrC=1,cityID,attrID,attrType,attrAgelimit,attrEntrancefee;

    ifstream infile;
    infile.open("loadIN.txt");
    if(infile.is_open())
    {
        while(getline(infile,input))
        {
            istringstream ci(input);
            getline(ci,s_cityID,'\t');
            cityID=atoi(s_cityID.c_str());
            getline(ci,cityName,'\t');
            while(getline(infile,input))
            {
                if(input.empty())                                  //If file empty break;
                    break;
                istringstream ci(input);
                getline(ci,s_attrID,'\t');
                getline(ci,s_attrType,'\t');
                getline(ci,attrName,'\t');
                attrID=atoi(s_attrID.c_str());
                attrType=atoi(s_attrType.c_str());
                if(attrType==1)
                {
                    getline(ci,s_attrAgelimit,'\t');
                    getline(ci,attrContact,'\t');
                    getline(ci,attrAddress,'\t');
                    attrAgelimit=atoi(s_attrAgelimit.c_str());
                    attr.insert(attrC,new Sport(attrID,attrType,attrName,attrAgelimit,attrContact,attrAddress));
                }
                else if(attrType==2)
                {
                    getline(ci,s_attrEntrancefee,'\t');
                    getline(ci,attrContact,'\t');
                    getline(ci,attrAddress,'\t');
                    attrEntrancefee=atof(s_attrEntrancefee.c_str());
                    attr.insert(attrC,new Culture(attrID,attrType,attrName,attrEntrancefee,attrContact,attrAddress));
                }
                else if(attrType==3)
                {
                    getline(ci,attrContact,'\t');
                    getline(ci,attrAddress,'\t');
                    attr.insert(attrC,new Shopping(attrID,attrType,attrName,attrContact,attrAddress));
                }
                attrC++;
            }
            cts.sortInsert(City(cityID,cityName,attr));
            attrC=1;
            attr.clear();
        }

        infile.close();
    }
    else
        cout << "Cannot open file" << endl;
}
void saveFunc(LinkedList<City> &cts)            //Save function
{
    ofstream myfile;
    myfile.open("loadIN.txt");
    int i=1;
    while (i <= cts.getLength())
    {
        myfile<<cts[i].getctyID()<<"\t"<<cts[i].getctyName()<<"\t"<<"\n";
        for(int j=1;j<=cts[i].getAttrLength();j++)
        {
            myfile<<cts[i].getID(j)<<"\t"<<cts[i].gettypeID(j)<<"\t"<<cts[i].getName(j)<<"\t";
            int attrType=cts[i].gettypeID(j);
            if(attrType==1)
            {
             myfile<<cts[i].getAgeLimit(j)<<"\t";

            }
            else if(attrType==2)
            {
              myfile<<cts[i].getEntranceFee(j)<<"\t";
            }
            myfile<<cts[i].getcontact(j)<<"\t"<<cts[i].getaddress(j)<<"\n";

        }
        i = i + 1;
        myfile<<"\n";
    }

     myfile.close();
}



 

int main()
{
    LinkedList<City>cts;
    LinkedList<Attraction*>attr;
    bool done=false;
    string input,s_cityID,cityName,s_attrID,s_attrType,attrName,s_attrAgelimit,s_attrEntrancefee,attrContact,attrAddress,name;

    loadFunc(cts, attr);
    while(!done)
    {
        system("cls");
        int inputS;
        string s_inputS;
        cout<<"TOURIST INFORMATION SYSTEM"<<endl;                      //Menu to choose tourist or system administrator
        cout<<"Please select which type you are"<<endl;
        cout<<"1.Tourist"<<endl;
        cout<<"2.System administrator"<<endl;
        cout<<"3.To quit"<<"\n"<<"=>";
        getline(cin,s_inputS);
        inputS=stringchgint(s_inputS);
        cout<<endl;

        if(inputS==1) //To enter the Tourist part of the system
        {
            loadFunc(cts, attr);
            tour(cts);
        }
        else if(inputS==2)   //To enter administrator part of the system
        {
            loadFunc(cts, attr);
            int inputSA;
            string s_inputSA,newctyName,newattrName,s_chgctyID,mdfyctyName,cityName,s_addattrID,s_addnewAttr;
            cout<<"THE LIST OF OPTIONS"<<endl;
            cout<<"1.Add city"<<endl;
            cout<<"2.Remove city"<<endl;
            cout<<"3.Modify city"<<endl;
            cout<<"4.Add attraction"<<endl;
            cout<<"5.Remove attraction"<<endl;
            cout<<"6.Modify attraction"<<endl;
            cout<<"7.Add flight"<<endl;
            cout<<"8.Remove flight"<<endl;
            cout<<"9.Modify flight"<<endl;
            cout<<"10.Save data to text file"<<endl;
            cout<<"11.Load data from text file"<<endl;

            getline(cin,s_inputSA);
            inputSA=stringchgint(s_inputSA);
            if(inputSA==1)                      //Add city
            {
                cout<<"Please enter the city name you want to add"<<"\n"<<"=>";                   //Ask for a new city name
                getline(cin,newctyName);
                cts.sortInsert(City(cts.getLength()+1,newctyName,attr));
                cout<<"City has been added successfully please continue"<<endl;
                saveFunc(cts);

            }
            else if(inputSA==2)                     //Remove city
            {
                int ctyID,position;
                string s_Position,s_ctyID;
                for(int i=1;i<=cts.getLength();i++)
                cout<<cts[i].getctyID()<<" "<<cts[i].getctyName()<<endl;
                cout << "Please enter the id of the city you want to remove"<<"\n"<<"=>";    //Ask for the id of the city to be removed
                getline(cin,s_ctyID);
                ctyID=stringchgint(s_ctyID);
                for(int i=1;i<=cts.getLength();i++)
                    if(ctyID==cts[i].getctyID())
                    {
                        position=i;
                        cts.remove(position);
                    }
                saveFunc(cts);
                cout<<"City successfully removed please continue"<<endl;


            }
            else if(inputSA==3)                    //Modify city
            {
                 int chgctyID,position;
                string findctyName,newctyName,cty_Info,f_Info;
                for(int i=1;i<=cts.getLength();i++)
                cout<<cts[i].getctyID()<<" "<<cts[i].getctyName()<<endl;
                cout<<"Please enter the id of the city you want to modify"<<"\n"<<"=>";      //Ask for the id of the city to  be modified
                getline(cin,s_chgctyID);
                chgctyID=stringchgint(s_chgctyID);
                for(int i=1;i<=cts.getLength();i++)					//Loop to find the name of the city using city id
                    if(chgctyID==cts[i].getctyID())
                        findctyName=cts[i].getctyName();
                stringstream scty_Info;                                             //String scty_Info to store city id and city name
                scty_Info<<chgctyID<<"\t"<<findctyName<<"\t";
                cty_Info=scty_Info.str();
                cout<<"Please enter the new city name=>"<<"\n"<<"=>";  //To get the new city name
                getline(cin,newctyName);

                ifstream myfile;												//read my file
                ofstream  tempsavefile;                                   //write tempsavefile
                myfile.open("loadIN.txt");								//open loadIN file
                tempsavefile.open("Temp.txt");						//open tempsavefile file
                while(getline(myfile, f_Info)) 						//f_Info is to get the lines of the text file
                    if(f_Info != cty_Info)            						//cty_Info is the programs city information
                        tempsavefile << f_Info << endl;				//save f_Info into tempsavefile if it is not equal
                    else
                    {
                        tempsavefile<<chgctyID<<"\t"<<newctyName<<"\t"<<endl;      //save new city id and new city name into tempsavefile if equal
                    }
                tempsavefile.close();                                                                 //close tempsavefile
                myfile.close();																		//close myfile
                remove("loadIN.txt");															//remove the loadIN file
                rename("Temp.txt", "loadIN.txt");										//rename the temp file with loadIN
                loadFunc(cts, attr);
            }

            else if(inputSA==4)                           //Add attraction
            {
                int addattrID,addnewAttr;
                for(int i=1;i<=cts.getLength();i++)
                cout<<cts[i].getctyID()<<" "<<cts[i].getctyName()<<endl;
                cout<<"Please chose the city id you want to add the attraction"<<"\n"<<"=>";    //Get the city id
                getline(cin,s_addattrID);
                addattrID=stringchgint(s_addattrID);
                for(int i = 1; i<= cts.getLength(); i++)
                    if(addattrID==cts[i].getctyID())
                    {
                        cout<<"Please choose an attraction type"<<endl;
                        cout<<"1.Sport"<<endl;
                        cout<<"2.Culture"<<endl;
                        cout<<"3.Shopping"<<endl;
                        getline(cin,s_addnewAttr);
                        addnewAttr=stringchgint(s_addnewAttr);
                        cout<<"Please type in the attraction's name"<<"\n"<<"=>";          //Get  attraction name
                        getline(cin,newattrName);
                        if(addnewAttr==1)
                        {
                            cout<<"Please type in the attraction's age limit"<<"\n"<<"=>";        //Get age limit
                            getline(cin,s_attrAgelimit);
                        }
                        else if(addnewAttr==2)
                        {
                            cout<<"Please type in the attraction's entrance fee"<<"\n"<<"=>";   //Get entrance fee
                            getline(cin,s_attrEntrancefee);
                        }
                        cout<<"Please type in the attraction's contact"<<"\n"<<"=>";				//Get contact
                        getline(cin,attrContact);
                        cout<<"Please type in the attraction's address"<<"\n"<<"=>";			//Get address
                        getline(cin,attrAddress);
                        ofstream myfile;																					
                        myfile.open("loadIN.txt");																	//Open text file and save the information
                        int i=1;
                        while (i <= cts.getLength())
                        {
                            myfile<<cts[i].getctyID()<<"\t"<<cts[i].getctyName()<<"\t"<<"\n";
                            for(int j=1;j<=cts[i].getAttrLength();j++)
                            {
                                myfile<<cts[i].getID(j)<<"\t"<<cts[i].gettypeID(j)<<"\t"<<cts[i].getName(j)<<"\t"; //Save the attraction id,typeid and name
                                int attrType=cts[i].gettypeID(j);
                                if(attrType==1)													//If attraction type is 1 get age limit and save it
                                {
                                 myfile<<cts[i].getAgeLimit(j)<<"\t";

                                }
                                else if(attrType==2)											//If attraction type is 2 get entrance fee and save it
                                {
                                  myfile<<cts[i].getEntranceFee(j)<<"\t";
                                }
                                myfile<<cts[i].getcontact(j)<<"\t"<<cts[i].getaddress(j)<<"\n";
                            }
                            if(addattrID==cts[i].getctyID())                                         //Compare the input to find the right city
                            {
                                myfile <<cts[i].getAttrLength()+1<<"\t"<<addnewAttr<<"\t"<<newattrName<<"\t";   //Get the information and save it
                                if(addnewAttr==1)
                                {
                                 myfile<<s_attrAgelimit<<"\t";

                                }
                                else if(addnewAttr==2)
                                {
                                  myfile<<s_attrEntrancefee<<"\t";
                                }
                                myfile<<attrContact<<"\t"<<attrAddress<<"\n";
                            }
                            i = i + 1;
                            myfile<<"\n";
                        }
                         myfile.close();
                    }
            }
            else if(inputSA==5)                           //Remove an attraction
            {
                string s_posAttr,p_Info,f_Info;
                int posAttr,cityID,attrID,position;
                for(int i=1;i<=cts.getLength();i++)
                cout<<cts[i].getctyID()<<" "<<cts[i].getctyName()<<endl;
                cout << "Please choose a city"<<"\n"<<"=>";
                getline(cin,s_cityID);
                cityID=stringchgint(s_cityID);
                for(int i=1;i<=cts.getLength();i++)
                    if(cityID==cts[i].getctyID())
                        position=i;
                cout<<"LIST OF ALL THE ATTRACTIONS"<<endl;
                cts[position].displayattr();
                cout<<"Choose the attraction id you want to remove"<<"\n"<<"=>";
                getline(cin,s_attrID);
                attrID=stringchgint(s_attrID);
                for(int i=1;i<=cts[position].getAttrLength();i++)
                    if(attrID==cts[position].getID(i))
                        posAttr=i;
                int attrType=cts[position].gettypeID(posAttr);
                stringstream s_Info;
                if(attrType==1)
                    s_Info<<cts[position].getID(posAttr)<<"\t"<<cts[position].gettypeID(posAttr)<<"\t"<<cts[position].getName(posAttr)<<"\t"<<cts[position].getAgeLimit(posAttr)<<"\t"<<cts[position].getcontact(posAttr)<<"\t"<<cts[position].getaddress(posAttr);
                else if(attrType==2)
                    s_Info<<cts[position].getID(posAttr)<<"\t"<<cts[position].gettypeID(posAttr)<<"\t"<<cts[position].getName(posAttr)<<"\t"<<cts[position].getEntranceFee(posAttr)<<"\t"<<cts[position].getcontact(posAttr)<<"\t"<<cts[position].getaddress(posAttr);
                else if(attrType==3)
                    s_Info<<cts[position].getID(posAttr)<<"\t"<<cts[position].gettypeID(posAttr)<<"\t"<<cts[position].getName(posAttr)<<"\t"<<cts[position].getcontact(posAttr)<<"\t"<<cts[position].getaddress(posAttr);
                p_Info=s_Info.str();
                ifstream myfile;
                ofstream  tempsavefile;
                myfile.open("loadIN.txt");
                tempsavefile.open("Temp.txt");
                while(getline(myfile, f_Info)) //f_Info is the getline of the text file
                    if(f_Info != p_Info)            //p_Info is program info
                        tempsavefile << f_Info << endl;
                tempsavefile.close();
                myfile.close();
                remove("loadIN.txt");
                rename("Temp.txt", "loadIN.txt");
                loadFunc(cts, attr);
            }
            else if(inputSA==6)      //Modify Attraction
            {
                int ctyID,position,attrID,posAttr,addnewAttr;
                string s_ctyID,newattrName,attr_Info,f_Info,p_Info;
                for(int i=1;i<=cts.getLength();i++)
                cout<<cts[i].getctyID()<<" "<<cts[i].getctyName()<<endl;
                cout<<"Please enter the id of the city"<<"\n"<<"=>";
                getline(cin,s_ctyID);
                ctyID=stringchgint(s_ctyID);
                for(int i=1;i<=cts.getLength();i++)
                    if(ctyID==cts[i].getctyID())
                        position=i;
                cout<<"LIST OF ALL THE ATTRACTIONS"<<endl;
                cts[position].displayattr();
                cout<<"Choose the attraction you want to modify"<<"\n"<<"=>";
                getline(cin,s_attrID);
                attrID=stringchgint(s_attrID);
                for(int i=1;i<=cts[position].getAttrLength();i++)
                    if(attrID==cts[position].getID(i))
                        posAttr=i;
                int attrType=cts[position].gettypeID(posAttr);
                stringstream s_Info;
                if(attrType==1)
                    s_Info<<cts[position].getID(posAttr)<<"\t"<<cts[position].gettypeID(posAttr)<<"\t"<<cts[position].getName(posAttr)<<"\t"<<cts[position].getAgeLimit(posAttr)<<"\t"<<cts[position].getcontact(posAttr)<<"\t"<<cts[position].getaddress(posAttr);
                else if(attrType==2)
                    s_Info<<cts[position].getID(posAttr)<<"\t"<<cts[position].gettypeID(posAttr)<<"\t"<<cts[position].getName(posAttr)<<"\t"<<cts[position].getEntranceFee(posAttr)<<"\t"<<cts[position].getcontact(posAttr)<<"\t"<<cts[position].getaddress(posAttr);
                else if(attrType==3)
                    s_Info<<cts[position].getID(posAttr)<<"\t"<<cts[position].gettypeID(posAttr)<<"\t"<<cts[position].getName(posAttr)<<"\t"<<cts[position].getcontact(posAttr)<<"\t"<<cts[position].getaddress(posAttr);
                p_Info=s_Info.str();

                cout<<"Please choose an attraction type"<<endl;
                cout<<"1.Sport"<<endl;
                cout<<"2.Culture"<<endl;
                cout<<"3.Shopping"<<endl;
                getline(cin,s_addnewAttr);
                addnewAttr=stringchgint(s_addnewAttr);
                cout<<"Please type in the attraction's name"<<"\n"<<"=>";
                getline(cin,newattrName);
                if(addnewAttr==1)
                {
                    cout<<"Please type in the attraction's age limit"<<"\n"<<"=>";
                    getline(cin,s_attrAgelimit);
                }
                else if(addnewAttr==2)
                {
                    cout<<"Please type in the attraction's entrance fee"<<"\n"<<"=>";
                    getline(cin,s_attrEntrancefee);
                }
                cout<<"Please type in the attraction's contact"<<endl;
                getline(cin,attrContact);
                cout<<"Please type in the attraction's address"<<endl;
                getline(cin,attrAddress);

                ifstream myfile;
                ofstream  tempsavefile;
                myfile.open("loadIN.txt");
                tempsavefile.open("Temp.txt");
                while(getline(myfile, f_Info)) //f_Info is the getline of the text file
                    if(f_Info != p_Info)            //p_Info is program info
                        tempsavefile << f_Info << endl;
                    else
                    {
                        if(addnewAttr==1)
                        {
                           tempsavefile<<posAttr<<"\t"<<addnewAttr<<"\t"<<newattrName<<"\t"<<s_attrAgelimit<<"\t"<<attrContact<<"\t"<<attrAddress<<endl;
                        }
                        else if(addnewAttr==2)
                        {
                            tempsavefile<<posAttr<<"\t"<<addnewAttr<<"\t"<<newattrName<<"\t"<<s_attrEntrancefee<<"\t"<<attrContact<<"\t"<<attrAddress<<endl;
                        }
                        else if(addnewAttr==3)
                        {
                            tempsavefile<<posAttr<<"\t"<<addnewAttr<<"\t"<<newattrName<<"\t"<<attrContact<<"\t"<<attrAddress<<endl;
                        }
                    }
                tempsavefile.close();
                myfile.close();
                remove("loadIN.txt");
                rename("Temp.txt", "loadIN.txt");
                loadFunc(cts, attr);
            }
            else if(inputSA==10)
            {
                 saveFunc(cts);
                 cout<<"Saved successfully"<<endl;
            }
            else if(inputSA==11)           //load for system administrator
            {
                loadFunc(cts, attr);
            }
        }
        else if(inputS==3)                //To quit in main menu
        {
            cout<<"Thank you for  using this program."<<endl;
            return 0;
        }
        else
            cout<<"invalid input"<<endl;
        system("pause");
    }
}
