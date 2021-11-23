#include "person.h"
using namespace std;

//Juhwan Lee
//CS-163
//Program #5
//The goal of this program is to explore graphs using an adjacency list

person::person()
{
	name = NULL;
	phone_number = NULL;
}

void person::destructor()
{
	if(!name)
		return;
	if(!phone_number)
		return;
	delete [] name;
	delete [] phone_number;
	name = NULL;
	phone_number = NULL;
}

int person::set(char new_name[], char new_phone_number[])
{
	name = new char [strlen(new_name) + 1];
	strcpy(name, new_name);
	phone_number = new char [strlen(new_phone_number) + 1];
	strcpy(phone_number, new_phone_number);
	return 1;
}

int person::display()
{
	cout << "--------------------" << endl
	<< "Name : " << name << endl
	<< "Phone Number : " << phone_number << endl
	<< "--------------------" << endl;
	return 1;
}

int person::compare(char key_value[])
{
	if(strcmp(name, key_value) == 0)
		return 1;
	else
		return 0;
}

int person::is_empty()
{
	if(!name || !phone_number)
		return 1;
	else
		return 0;
}
