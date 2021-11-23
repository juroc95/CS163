#include "queue.h"
using namespace std;

//Juhwan Lee
//Program #2
//This program uses queue to keep track of everyone in line and uses stack
//to hold the alerts as they are sent out from the store, restaurant, or 
//doctor's office to let people know when it is their turn.

//Default constructor
queue::queue()
{
	rear = NULL;
}

//Destructor
queue::~queue()
{
	if(rear)
	{
		q_node * previous = rear->next;
		q_node * current = previous->next;
		while(current != rear)
		{
			delete [] previous->data.name;
			delete [] previous->data.phone;
			delete previous;
			previous = current;
			current = current->next;
			rear->next = previous;
		}
		delete [] previous->data.name;
		delete [] previous->data.phone;
		delete previous;
		delete [] current->data.name;
		delete [] current->data.phone;
		delete current;
		rear = NULL;
	}
}

//Adding new data to the queue
int queue::enqueue(person & newperson)
{
	if(!rear)
	{
		rear = new q_node;
		rear->data = newperson;
		rear->next = rear;
		return 1;
	}
	q_node * current = rear->next;
	rear->next = new q_node;
	rear = rear->next;
	rear->data = newperson;
	rear->next = current;
	return 1;
}

//Removing first data from the queue
int queue::dequeue()
{
	if(!rear)
		return 0;
	if(rear->next == rear)
	{
		delete [] rear->data.name;
		delete [] rear->data.phone;
		delete rear;
		rear = NULL;
		return 1;
	}
	q_node * current = rear->next;
	current = current->next;
	delete [] rear->next->data.name;
	delete [] rear->next->data.phone;
	delete rear->next;
	rear->next = current;
	return 1;
}

//Displaying first data of the queue
int queue::peek()
{
	if(!rear)
		return 0;
	cout << endl << "--------------------" << endl;
	cout << "Next turn: " << rear->next->data.name << endl;
	cout << "Phone number: " << rear->next->data.phone << endl;
	cout << "--------------------" << endl;
	return 1;
}

//Displaying the whole queue
int queue::display()
{
	if(!rear)
		return 0;
	q_node * current = rear->next;
	while(current != rear)
	{
		cout << endl << "--------------------" << endl;
		cout << "Person in line: " << current->data.name << endl;
		cout << "Phone number: " << current->data.phone << endl;
		cout << "--------------------" << endl;
		current = current->next;
	}
	cout << endl << "--------------------" << endl;
	cout << "Person in line: " << rear->data.name << endl;
	cout << "Phone number: " << rear->data.phone << endl;
	cout << "--------------------" << endl;
	return 1;
}
