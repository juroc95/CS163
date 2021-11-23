#include "graph.h"
using namespace std;

//Juhwan Lee
//CS-163
//Program #5
//The goal of this program is to explore graphs using an adjacency list

int main()
{
	table mytable;
	person newperson;
	char response = 'y';
	int menu = 0;

	while(menu != 5)
	{
		cout << "*** MENU ***" << endl;
		cout << "1. Create vertex " << endl
		<< "2. Insert edge between two vertices" << endl
		<< "3. Display all adjacent vertices" << endl
		<< "4. Display all vertices" << endl
		<< "5. Quit" << endl
		<< "What do you want to do? 1-4 : ";
	
		cin >> menu;
		cin.ignore(100, '\n');
	
		while(menu == 1 && tolower(response) == 'y')
		{
			char name[100];
			char phone_number[100];
	
			cout << "*** Creating vertex ***" << endl;
			cout << "Please enter a name of the person : ";
			cin.get(name, 100, '\n');
			cin.ignore(100, '\n');
			cout << "Please enter the person's phone number : ";
			cin.get(phone_number, 100, '\n');
			cin.ignore(100, '\n');
	
			newperson.set(name, phone_number);
			if(mytable.insert_vertex(newperson))
				cout << "Vertex created" << endl;
			else
				cout << "Vertex not created" << endl;
	
			cout << "Again? Y or N : ";
			cin >> response;
			cin.ignore(100, '\n');
		}
	
		response = 'y';
	
		while(menu == 2 && tolower(response) == 'y')
		{
			char name_one[100];
			char name_two[100];
	
			cout << "*** Insert a connection between two vertices ***"
			<< endl;
			cout << "Please enter two names : " << endl;
			cin.get(name_one, 100, '\n');
			cin.ignore(100, '\n');
			cin.get(name_two, 100, '\n');
			cin.ignore(100, '\n');
	
			if(mytable.insert_edge(name_one, name_two))
				cout << "Connection completed" << endl;
			else
				cout << "There was no match" << endl;
	
			cout << "Again? Y or N : ";
			cin >> response;
			cin.ignore(100, '\n');
		}
	
		response = 'y';
	
		while(menu == 3 && tolower(response) == 'y')
		{
			char name[100];
	
			cout << "*** Displaying all adjacent vertices ***" << endl;
			cout << "Please enter a name of the person : ";
			cin.get(name, 100, '\n');
			cin.ignore(100, '\n');
	
			if(mytable.display_adjacent(name))
				cout << "All adjacent vertices displayed" << endl;
			else
				cout << "There was no match" << endl;
	
			cout << "Again? Y or N : ";
			cin >> response;
			cin.ignore(100, '\n');
		}
	
		response = 'y';
	
		while(menu == 4 && tolower(response) == 'y')
		{
			cout << "*** Displaying all ***" << endl;
	
			if(mytable.display_all())
				cout << "All vertices displayed" << endl;
			else
				cout << "There is no vertex" << endl;
	
			cout << "Again? Y or N : ";
			cin >> response;
			cin.ignore(100, '\n');
		}
	
		response = 'y';
	}
	return 0;
}

	
