#include "table.h"
using namespace std;

//Juhwan Lee
//Program #4
//The goal of the fourth program is to move from a hash table and implement a
//binary search tree. The advantage of a binary search tree is the ability to
//retrieve our data using a logarithmic performance if the tree is relatively
//balanced and be able to search for a range of information and obtain our data
//in sorted order.

//constructor
table::table()
{
	root = NULL;
}

//destructor
table::~table()
{
	destroy_recursive(root);
}

//destructor recursive function
void table::destroy_recursive(node * & root)
{
	if(!root)
		return;
	destroy_recursive(root->left);
	destroy_recursive(root->right);
	delete root;
	root = NULL;
	return;
}

//wrapper function
int table::add(comic & newcomic)
{
	return add(root, newcomic);
}

//add new comic into the table
int table::add(node * & root, comic & newcomic)
{
	//base case
	if(!root)
	{
		root = new node;
		root->data = newcomic;
		root->left = NULL;
		root->right = NULL;
		cout << "New comic added" << endl;
		return 1;
	}
	//declare local variables
	char data_value[100];
	char superhero[100];
	//get data values
	root->data.copy_superhero(data_value);
	newcomic.copy_superhero(superhero);
	//compare the data and call recursive function
	if(strcmp(superhero, data_value) < 0)
		add(root->left, newcomic);
	else
		add(root->right, newcomic);
}

//wrapper function
int table::retrieve(comic & newcomic, char search[])
{
	return retrieve(root, newcomic, search);
}

//retrieve information about the comics entered by the superhero name
int table::retrieve(node * root, comic & newcomic, char search[])
{
	//base case (no data found)
	if(!root)
	{	
		cout << "Data not found" << endl;
		return 0;
	}
	//get data value
	char data_value[100];
	root->data.copy_superhero(data_value);
	//if there is match, retrieve the data
	if(strcmp(search, data_value) == 0)
	{
		char name[100];
		char publisher[100];
		char superhero[100];
		char issue[100];
		char review[100];
		char other[100];
		root->data.copy(name, publisher, superhero, issue, review, other);
		newcomic.set(name, publisher, superhero, issue, review, other);
		newcomic.display();
		cout << "Data retrieved" << endl;
		return 1;
	}
	//compare the data and call recursive function
	if(strcmp(search, data_value) < 0)
		retrieve(root->left, newcomic, search);
	else
		retrieve(root->right, newcomic, search);
}

//wrapper function
int table::remove(char search[])
{
	return remove(root, search);
}

//remove a comic based on the name of the comic book
int table::remove(node * & root, char search[])
{
	//base case
	if(!root)
		return 0;
	//recursive calls
	remove(root->left, search);
	remove(root->right, search);
	//get data value
	char data_value[100];
	root->data.copy_name(data_value);
	cout << data_value << endl;
	//compare the data and remove the node
	if(strcmp(search, data_value) == 0)
	{
		//leaf
		if(!root->left && !root->right)
		{
			delete root;
			root = NULL;
			cout << "Data removed" << endl;
			return 1;
		}
		//internal node with only 1 child (left)
		if(root->left && !root->right)
		{
			node * hold = root->left;
			delete root;
			root = hold;
			cout << "Data removed" << endl;
			return 1;
		}
		//internal node with only 1 child (right)
		if(!root->left && root->right)
		{
			node * hold = root->right;
			delete root;
			root = hold;
			cout << "Data removed" << endl;
			return 1;
		}
		//internal node with 2 children
		if(root->left && root->right)
		{
			node * current = root->right;
			node * previous = root;
			//right child has no left child
			if(!current->left)
			{
				char name[100];
				char publisher[100];
				char superhero[100];
				char issue[100];
				char review[100];
				char other[100];
				current->data.copy(name, publisher, superhero, issue, review, other);
				root->data.set(name, publisher, superhero, issue, review, other);
				root->right = current->right;
				delete current;
				cout << "Data removed" << endl;
				return 1;
			}
			//right child has left child
			else
			{
				while(current->left)
				{
					previous = current;
					current = current->left;
				}
				char name[100];
				char publisher[100];
				char superhero[100];
				char issue[100];
				char review[100];
				char other[100];
				current->data.copy(name, publisher, superhero, issue, review, other);
				root->data.set(name, publisher, superhero, issue, review, other);
				//IOS has no child
				if(!current->right)
				{
					delete current;
					cout << "Data removed" << endl;
					return 1;
				}
				//IOS has right child
				else
				{
					previous->left = current->right;
					delete current;
					cout << "Data removed" << endl;
					return 1;
				}
			}
		}
	}
	return 0;
}

//wrapper function
int table::display_superhero()
{
	return display_superhero(root);
}

//display all comics featuring a superhero
int table::display_superhero(node * root)
{
	//base case
	if(!root)
		return 0;
	//go to left
	display_superhero(root->left);
	int flag = 0;
	//get data value
	char data_value[100];
	root->data.copy_superhero(data_value);
	//if it is not null, display
	if(data_value)
	{
		root->data.display();
		flag = 1;
	}
	//go to right
	display_superhero(root->right);
	if(flag == 1)
		return 1;
	else
		return 0;
}

//wrapper function
int table::display_all()
{
	return display_all(root);
}

//display all (sorted by superhero)
int table::display_all(node * root)
{
	//base case
	if(!root)
		return 0;
	//go to left
	display_all(root->left);
	//display
	root->data.display();
	//go to right
	display_all(root->right);
	return 1;
}
