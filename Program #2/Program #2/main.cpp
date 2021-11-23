#include "stack.h"
#include "queue.h"
using namespace std;

//Juhwan Lee
//Program #2
//This program uses queue to keep track of everyone in line and uses stack
//to hold the alerts as they are sent out from the store, restaurant, or 
//doctor's office to let people know when it is their turn.

int main()
{
	queue myqueue;
	stack mystack;
	person newperson;
	alert newalert;
	int menu = 0;

	while(menu != 8)
	{
		cout << endl << "Menu: " << endl;
		cout << "1. Adding person in line " << endl;
		cout << "2. Alert person " << endl;
		cout << "3. Remove alert " << endl;
		cout << "4. Display next turn " << endl;
		cout << "5. Display alerted person " << endl;
		cout << "6. Display everyone in line " << endl;
		cout << "7. Display list of alert " << endl;
		cout << "8. Quit " << endl << endl;
	
		cout << "What do you want to do?: ";
		cin >> menu;
		cin.ignore(100, '\n');

		//Adding person in line
		if(menu == 1)
		{
			char name[100];
			char phone[100];
			cout << endl << "Please enter name: ";
			cin.get(name, 100, '\n');
			cin.ignore(100, '\n');
			newperson.name = new char [strlen(name) + 1];
			strcpy(newperson.name, name);
			cout << "Please enter phone number: ";
			cin.get(phone, 100, '\n');
			cin.ignore(100, '\n');
			newperson.phone = new char [strlen(phone) + 1];
			strcpy(newperson.phone, phone);
			if(myqueue.enqueue(newperson) == 1)
				cout << endl << "The person is now in line" << endl;
		}

		//Alert person
		if(menu == 2)
		{
			char name[100];
			if(myqueue.peek() == 1)
			{
				if(myqueue.dequeue() == 1)
				{
					cout << endl << "Please enter name: ";
					cin.get(name, 100, '\n');
					cin.ignore(100, '\n');
					newalert.name = new char [strlen(name) +1];
					strcpy(newalert.name, name);
					cout << "Please enter current time(ex. 6pm -> 1800): ";
					cin >> newalert.time;
					cin.ignore(100, '\n');
					if(mystack.push(newalert) == 1)
						cout << endl << "The person has been alerted" << endl;
				}
			}
			else
				cout << endl << "There is no one in line" << endl;
		}
		
		//Remove alert
		if(menu == 3)
		{
			if(mystack.pop() == 1)
				cout << endl << "The alert has been removed" << endl;
			else
				cout << endl << "The alert list is empty" << endl;
		}

		//Display next turn
		if(menu == 4)
		{
			if(myqueue.peek() == 1)
				cout << endl << "Next person displayed" << endl;
			else
				cout << endl << "There is no one in line" << endl;
		}

		//Display alerted person
		if(menu == 5)
		{
			if(mystack.peek() == 1)
				cout << endl << "Alerted person displayed" << endl;
			else
				cout << endl << "The alert list is empty" << endl;
		}

		//Display everyone in line
		if(menu == 6)
		{
			if(myqueue.display() == 1)
				cout << endl << "Everyone in line displayed" << endl;
			else
				cout << endl << "There is no one in line" << endl;
		}

		//Display list of alert
		if(menu == 7)
		{
			if(mystack.display() == 1)
				cout << endl << "The list of alert displayed" << endl;
			else
				cout << endl << "The alert list is empty" << endl;
		}
	}

	return 0;
}

