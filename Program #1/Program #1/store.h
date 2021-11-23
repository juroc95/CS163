#include <iostream>
#include <cctype>
#include <cstring>

//Juhwan Lee
//Program #1
//This program is an exercise in building, traversing, and destroying
//liner linked lists. There are two linear linked lists, one with store, 
//and one with items for each store. The user can add store as much as the
//user wants and the user can add items as much as the user wants for each
//store. Also the user can remove items, display store with all the items, 
//and all the items that has same category.

//Item
struct item
{
	char * item_name;
	char * category;
	float price;
};

//Store
struct store
{
	char * store_name;
	char * website;
};

//Node for item
struct item_node
{
	item an_item;
	item_node * next;
};

//Node for store
struct store_node
{
	store a_store;
	item_node * head;
	store_node * next;
};

//Store list
class store_list
{
	public:
		store_list();	//default constructor
		~store_list();	//destructor
		int new_store(store & newstore);
		int new_item(item & newitem, char store_name[]);
		int remove_item(char item_name[]);
		int display_store(char store_name[]);
		int display_category(char category[]);
	private:
		store_node * head;	//Head pointer for store LLL
};
