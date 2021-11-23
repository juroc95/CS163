#include "table.h"
using namespace std;

//Juhwan Lee
//Program #3
//In this program, we will create a program that will help us collect and catalog
//comics that we are interested in. We will be using hash table and external data
//files for this program.

//Constructor
table::table()
{
	table_size = 101;
	hash_table = new node* [table_size];
	for(int i = 0; i < table_size; ++i)
	{
		hash_table[i] = NULL;
	}
}

//Destructor
table::~table()
{
	for(int i = 0; i < table_size; ++i)
	{
		if(hash_table[i])
		{
			node * current = hash_table[i];
			while(current)
			{
				current = current->next;
				delete hash_table[i];
				hash_table[i] = current;
			}
		}
	}
	delete [] hash_table;
	hash_table = NULL;
}

//Read information from the file
int table::load(comic & mycomic)
{
	ifstream file_in;
	//number of comics
	int i = 0;

	file_in.open("Comic.txt");
	if(file_in) 	//we connected by not being false
	{
		do
		{
			char name[100];
			char publisher[100];
			char superhero[100];
			char issue[100];
			char review[100];
			char other_info[100];

			file_in.get(name, 100, '|');
			file_in.ignore(100, '|');
			file_in.get(publisher, 100, '|');
			file_in.ignore(100, '|');
			file_in.get(superhero, 100, '|');
			file_in.ignore(100, '|');
			file_in.get(issue, 100, '|');
			file_in.ignore(100, '|');
			file_in.get(review, 100, '|');
			file_in.ignore(100, '|');
			file_in.get(other_info, 100, '|');
			file_in.ignore(100, '|');
		
			mycomic.create(name, publisher, superhero, issue, review, other_info);
			add(superhero, mycomic);
			++i;
		} while(!file_in.eof());
		file_in.close();
	}
	return i;
}

//Hash function
int table::hash_function(char key[])
{
	int index = 0;
	for (int i = 0; i < strlen(key) + 1; ++i)
	{
		index = index + key[i] * key[i];
	}
	index = index * index;
	index = index % table_size;
	if(index < 0)
		index = -index;
	cout << "Index : " << index << endl;
	return index;
}

//Add comic into the table
int table::add(char superhero[], comic & mycomic)
{
	int index = 0;
	int flag = 0;
	index = hash_function(superhero);
	if(hash_table[index] == NULL)
	{
		hash_table[index] = new node;
		hash_table[index]->data = mycomic;
		hash_table[index]->next = NULL;
		flag = 1;
	}
	else
	{
		node * current = hash_table[index];
		while(current->next != NULL)
		{
			current = current->next;
		}
		current->next = new node;
		current = current->next;
		current->data = mycomic;
		current->next = NULL;
		flag = 1;
	}
	if(flag == 1)
		return 1;
	else
		return 0;
}

//Retrieve information about the comics entered by the superhero name
int table::retrieve(char superhero[])
{
	int index = 0;
	int flag = 0;
	index = hash_function(superhero);
	node * current = hash_table[index];
	while(current != NULL)
	{
		current->data.display();
		current = current->next;
		flag = 1;
	}
	if(flag == 1)
		return 1;
	else
		return 0;
}

//Remove a comic based on the name of the comic book
int table::remove(char name_search[])
{
	int flag = 0;
	for(int i = 0; i < table_size; ++i)
	{
		while(hash_table[i])
		{
			node * current = hash_table[i];
			node * previous = NULL;
			while(current)
			{
				if(current->data.is_match(name_search))
				{
					if(current == hash_table[i])
						hash_table[i] = current->next;
					else
						previous->next = current->next;
					current->data.~comic();	//delete data inside
					delete current; 	//delete node
					current = NULL; 	//set it to NULL
					flag = 1;
				}
				else
				{
					previous = current;
					current = current->next;
				}
			}
		}
	}
	if(flag == 1)
		return 1;
	else
		return 0;
}

//Display all comics featuring a superhero
int table::display_superhero()
{
	int flag = 0;
	for(int i = 0; i < table_size; ++i)
	{
		if(hash_table[i] != NULL && i != 95)
		//95 is the index value of empty space
		//which means index of 95 does not feature a superhero
		{
			flag = 1;
			node * current = hash_table[i];
			while(current != NULL)
			{
				current->data.display();
				current = current->next;
			}
		}
	}
	if(flag == 1)
		return 1;
	else
		return 0;
}

//Display all (not sorted)
int table::display_all()
{
	int flag = 0;
	for(int i = 0; i < table_size; ++i)
	{
		if(hash_table[i] != NULL)
		{
			flag = 1;
			node * current = hash_table[i];
			while(current != NULL)
			{
				current->data.display();
				current = current->next;
			}
		}
	}
	if(flag == 1)
		return 1;
	else
		return 0;
}
