/*************************************
Program: Flight.cpp (milestone2.cpp)
Course:  OOPDS
Year:    2016/02 Trimester 2
Name:    LIEW SOON PANG
ID:      1142700808
Lecture: TC02
Lab:     TT04
Email:   liewsoonpang111@gmail.com  
Phone:   011-10776470
*************************************/
#include<iostream>
#include "Flight.h"

int Flight::getflightData()
{
	int a=ctyPos.getEntry(1);
	ctyPos.remove(1);
	return a;
}
bool Flight::getctyEmpty(){return ctyPos.isEmpty();}


 
Flight::Flight(int V)
{
    this->V = V;
    adj = new LinkedStack<int>[V];
}
 
void Flight::addEdge(int v, int w)
{
    adj[v].push(w); 
}
 
bool Flight::isReachable(int s, int d)
{
	bool check;
    if (s == d)
      return true;
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    LinkedStack<int> stack;
    visited[s] = true;
    stack.push(s);
 
    while (!stack.isEmpty())
    {
        s = stack.peek();
		ctyPos.insert(ctyPos.getLength()+1,s);
        stack.pop();
		check =false;
        while (!adj[s].isEmpty())
        {
            if (adj[s].peek() == d)
			{
				ctyPos.insert(ctyPos.getLength()+1,adj[s].peek());
				return true;
			}      
		if (!visited[adj[s].peek()])
            {
				check = true;
                visited[adj[s].peek()] = true;
                stack.push(adj[s].peek());
				adj[s].pop();
            }
			else
				adj[s].pop();
        }
		if(!check)
			ctyPos.remove(ctyPos.getLength());
    }
    return false;
}
 

