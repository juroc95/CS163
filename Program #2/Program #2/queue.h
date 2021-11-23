#include <iostream>
#include <cctype>
#include <cstring>

//Juhwan Lee
//Program #2
//This program uses queue to keep track of everyone in line and uses stack
//to hold the alerts as they are sent out from the store, restaurant, or 
//doctor's office to let people know when it is their turn.

struct person
{
	char * name;
	char * phone;
};

struct q_node
{
	person data;
	q_node * next;
};

class queue
{
	public:
		queue(); 	//default constructor
		~queue(); 	//destructor
		int enqueue(person & newperson);
		int dequeue();
		int peek();
		int display();
	private:
		q_node * rear;
};
