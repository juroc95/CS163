#include "table.h"
using namespace std;

//Juhwan Lee
//Program #3
//In this program, we will create a program that will help us collect and catalog
//comics that we are interested in. We will be using hash table and external data
//files for this program.

int main()
{
	comic mycomic;
	table mytable;

	int menu = 0;
	char response = 'y';

	int num_of_comics = 0;
	num_of_comics = mytable.load(mycomic);
	cout << num_of_comics << " comics loaded" << endl;

	while(menu != 6)
	{
		cout << "Menu : " << endl
		<< "1. Add my comic into the table" << endl
		<< "2. Retrieve information about the comics entered by the superhero name" << endl
		<< "3. Remove a comic based on the name of the comic book" << endl
		<< "4. Display all comics featuring a superhero" << endl
		<< "5. Display all (not sorted)" << endl
		<< "6. Quit" << endl
		<< "What do you want to do? ";

		cin >> menu;
		cin.ignore(100, '\n');

		if(menu == 1)
		{
			char newname[100];	
			char newpublisher[100];
			char newsuperhero[100];
			char newissue[100];
			char newreview[100];
			char newother_info[100];
	
			cout << "Please enter the name of the comic : ";
			cin.get(newname, 100, '\n');
			cin.ignore(100, '\n');
			cout << "Please enter the publisher : ";
			cin.get(newpublisher, 100, '\n');
			cin.ignore(100, '\n');
			cout << "Please enter the superhero : ";
			cin.get(newsuperhero, 100, '\n');
			cin.ignore(100, '\n');
			cout << "Please enter the issue : ";
			cin.get(newissue, 100, '\n');
			cin.ignore(100, '\n');
			cout << "Please enter a review : ";
			cin.get(newreview, 100, '\n');
			cin.ignore(100, '\n');
			cout << "Please enter other informations : ";
			cin.get(newother_info, 100, '\n');
			cin.ignore(100, '\n');
	
			mycomic.create(newname, newpublisher, newsuperhero, newissue, newreview, newother_info);
			if(mytable.add(newsuperhero, mycomic))
				cout << "Comic added" << endl;
		}

		if(menu == 2)
		{
			char superhero[100];
			cout << "Please enter the superhero : ";
			cin.get(superhero, 100, '\n');
			cin.ignore(100, '\n');
			if(mytable.retrieve(superhero))
				cout << "Comic retrieved" << endl;
			else
				cout << "There is no match" << endl;
		}

		if(menu == 3)
		{
			char name_search[100];
			cout << "Please enter the name of the comic book : ";
			cin.get(name_search, 100, '\n');
			cin.ignore(100, '\n');
			if(mytable.remove(name_search))
				cout << "Comic removed" << endl;
			else
				cout << "There is no match" << endl;
		}
	
		if(menu == 4)
		{
			if(mytable.display_superhero())
				cout << "All superhero comics displayed" << endl;
			else
				cout << "There is no superhero comic" << endl;
		}

		if(menu == 5)
		{
			if(mytable.display_all())
				cout << "All comics displayed" << endl;
			else
				cout << "Table is empty" << endl;
		}
	}

	return 0;
}

