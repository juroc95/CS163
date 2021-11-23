#include <iostream>
#include <cctype>
#include <cstring>

//Juhwan Lee
//Program #4
//The goal of the fourth program is to move from a hash table and implement a
//binary search tree. The advantage of a binary search tree is the ability to
//retrieve our data using a logarithmic performance if the tree is relatively
//balanced and be able to search for a range of information and obtain our data
//in sorted order.

class comic
{
	public:
		comic(); 	//default constructor
		~comic(); 	//destructor
		int set(char name[], char publisher[], char superhero[], char issue[], char review[], char other[]);
		int display();
		int copy_superhero(char copy[]);
		int copy_name(char copy[]);
		int copy(char name[], char publisher[], char superhero[], char issue[], char review[], char other[]);
	private:
		char * name;
		char * publisher;
		char * superhero;
		char * issue;
		char * review;
		char * other;
};
