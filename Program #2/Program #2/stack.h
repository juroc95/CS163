#include <iostream>
#include <cctype>
#include <cstring>

//Juhwan Lee
//Program #2
//This program uses queue to keep track of everyone in line and uses stack
//to hold the alerts as they are sent out from the store, restaurant, or 
//doctor's office to let people know when it is their turn.

const int MAX = 5;

struct alert
{
	char * name;
	int time;
};

struct s_node
{
	alert * data;
	s_node * next;
};

class stack
{
	public:
		stack(); 	//default constructor
		~stack(); 	//destructor
		int push(alert & newalert);
		int pop();
		int peek();
		int display();
	private:
		s_node * head;
		int index;
};
