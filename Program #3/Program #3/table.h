#include "comic.h"

//Juhwan Lee
//Program #3
//In this program, we will create a program that will help us collect and catalog
//comics that we are interested in. We will be using hash table and external data
//files for this program.

struct node
{
	comic data;
	node * next;
};

class table
{
	public:
		table();	//constructor
		~table();	//destructor
		int load(comic & mycomic);	//read information from the file
		int hash_function(char key[]);
		int add(char superhero[], comic & mycomic);
		int retrieve(char superhero[]);
		int remove(char name_search[]);
		int display_superhero();
		int display_all();
	private:
		node ** hash_table;
		int table_size;
};
