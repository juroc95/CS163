#include "stack.h"
using namespace std;

//Juhwan Lee
//Program #2
//This program uses queue to keep track of everyone in line and uses stack
//to hold the alerts as they are sent out from the store, restaurant, or 
//doctor's office to let people know when it is their turn.

//Default constructor
stack::stack()
{
	head = NULL;
	index = 0;
}

//Destructor
stack::~stack()
{
	if(head)
	{	
		s_node * current = head->next;
		while(current)
		{
			for(int i = 0; i < MAX; ++i)
			{
				delete [] head->data[i].name;
			}
			delete [] head->data;
			delete head;
			head = current;
			current = current->next;
		}
		for(int i = 0; i < MAX; ++i)
		{
			delete [] head->data[i].name;
		}
		delete [] head->data;
		delete head;
		head = NULL;
	}
}

//Adding new data to the stack
int stack::push(alert & newalert)
{
	s_node * current = head;
	if(index == MAX)
		index = 0;
	if(index == 0)
	{
		head = new s_node;
		head->data = new alert[MAX];
		head->next = current;
	}
	head->data[index] = newalert;
	++index;
	return 1;
}

//Removing last data from the stack
int stack::pop()
{
	if(!head)
		return 0;
	if(index != 0)
		index = index - 1;
	if(index == 0)
	{
		s_node * current = head->next;
		for(int i = 0; i < MAX; ++i)
		{
			delete [] head->data[i].name;
		}
		delete [] head->data;
		delete head;
		head = current;
		index = MAX;
	}
	return 1;
}

//Displaying last data of the stack
int stack::peek()
{
	if(!head)
		return 0;
	int i = index - 1;
	cout << endl << "--------------------" << endl;
	cout << "Person alerted: " << head->data[i].name << endl;
	cout << "Alerted time: " << head->data[i].time << endl;
	cout << "--------------------" << endl;
	return 1;
}

//Displaying the whole stack
int stack::display()
{
	if(!head)
		return 0;
	int i = index - 1;
	s_node * current = head;
	while(current)
	{
		cout << endl << "--------------------" << endl;
		cout << "Person alerted: " << current->data[i].name << endl;
		cout << "Alerted time: " << current->data[i].time << endl;
		cout << "--------------------" << endl;	
		--i;
		if(i < 0)
		{
			i = 4;
			current = current->next;
		}
	}
	return 1;
}
