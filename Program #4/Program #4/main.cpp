#include "table.h"
using namespace std;

//Juhwan Lee
//Program #4
//The goal of the fourth program is to move from a hash table and implement a
//binary search tree. The advantage of a binary search tree is the ability to
//retrieve our data using a logarithmic performance if the tree is relatively
//balanced and be able to search for a range of information and obtain our data
//in sorted order.

int main()
{
	comic newcomic;
	table mytable;

	char response = 'y';

	while(tolower(response) == 'y')
	{
		cout << "*** Add new comic into the table ***" << endl;

		char name[100];
		char publisher[100];
		char superhero[100];
		char issue[100];
		char review[100];
		char other[100];
	
		cout << "Please enter the name of the comic : ";
		cin.get(name, 100, '\n');
		cin.ignore(100, '\n');
		cout << "Please enter the publisher : ";
		cin.get(publisher, 100, '\n');
		cin.ignore(100, '\n');
		cout << "Please enter the superhero : ";
		cin.get(superhero, 100, '\n');
		cin.ignore(100, '\n');
		cout << "Please enter the issue : ";
		cin.get(issue, 100, '\n');
		cin.ignore(100, '\n');
		cout << "Please enter a review : ";
		cin.get(review, 100, '\n');
		cin.ignore(100, '\n');
		cout << "Please enter other items you are interested in : ";
		cin.get(other, 100, '\n');
		cin.ignore(100, '\n');
	
		newcomic.set(name, publisher, superhero, issue, review, other);
		mytable.add(newcomic);

		cout << "Again? Y or N : ";
		cin >> response;
		cin.ignore(100, '\n');
	}
	
	response = 'y';

	while(tolower(response) == 'y')
	{
		cout << "*** Retrieve information about the comics entered by the superhero name ***" << endl;

		char superhero[100];
		cout << "Please enter the superhero : ";
		cin.get(superhero, 100, '\n');
		cin.ignore(100, '\n');

		mytable.retrieve(newcomic, superhero);
		
		cout << "Again? Y or N : ";
		cin >> response;
		cin.ignore(100, '\n');
	}

	response = 'y';

	while(tolower(response) == 'y')
	{
		cout << "*** Remove a comic based on the name of the comic book ***" << endl;

		char name[100];
		cout << "Please enter the name of the comic book : ";
		cin.get(name, 100, '\n');
		cin.ignore(100, '\n');

		mytable.remove(name);

		cout << "Again? Y or N : ";
		cin >> response;
		cin.ignore(100, '\n');
	}

	response = 'y';

	while(tolower(response) == 'y')
	{
		cout << "*** Display all comics featuring a superhero ***" << endl;

		mytable.display_superhero();

		cout << "Again? Y or N : ";
		cin >> response;
		cin.ignore(100, '\n');
	}

	response = 'y';

	while(tolower(response) == 'y')
	{
		cout << "*** Display all (sorted by superhero) ***" << endl;

		mytable.display_all();

		cout << "Again? Y or N : ";
		cin >> response;
		cin.ignore(100, '\n');
	}
	
	return 0;
}
