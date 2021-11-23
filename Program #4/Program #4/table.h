#include "comic.h"

//Juhwan Lee
//Program #4
//The goal of the fourth program is to move from a hash table and implement a
//binary search tree. The advantage of a binary search tree is the ability to
//retrieve our data using a logarithmic performance if the tree is relatively
//balanced and be able to search for a range of information and obtain our data
//in sorted order.

struct node
{
	comic data;
	node * left;
	node * right;
};

class table
{
	public:
		table(); 	//default constructor
		~table(); 	//destructor
		void destroy_recursive(node * & root);
		int add(comic & newcomic);
		int add(node * & root, comic & newcomic);
		int retrieve(comic & newcomic, char search[]);
		int retrieve(node * root, comic & newcomic, char search[]);
		int remove(char search[]);
		int remove(node * & root, char search[]);
		int display_superhero();
		int display_superhero(node * root);
		int display_all();
		int display_all(node * root);
	private:
		node * root;
};

