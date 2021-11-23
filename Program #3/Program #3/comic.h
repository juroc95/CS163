#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>

//Juhwan Lee
//Program #3
//In this program, we will create a program that will help us collect and catalog
//comics that we are interested in. We will be using hash table and external data
//files for this program.

class comic
{
	public:
		comic();	//constructor
		~comic();	//destructor
		int create(char newname[], char newpublisher[], char newsuperhero[], char newissue[], char newreview[], char newother_info[]);
		int display();
		int is_match(char name_search[]);
	private:
		char * superhero;
		char * name;
		char * publisher;
		char * issue;
		char * review;
		char * other_info;
};
