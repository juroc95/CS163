#include "store.h"
using namespace std;

//Juhwan Lee
//Program #1
//This program is an exercise in building, traversing, and destroying
//liner linked lists. There are two linear linked lists, one with store, 
//and one with items for each store. The user can add store as much as the
//user wants and the user can add items as much as the user wants for each
//store. Also the user can remove items, display store with all the items, 
//and all the items that has same category.

//default constructor
store_list::store_list()
{
	head = NULL;
}

//destructor
store_list::~store_list()
{
	while(head)
	{
		store_node * temp = head;
		temp = temp->next;
		while(head->head)
		{
			item_node * current = head->head;
			current = current->next;
			if(head->head->an_item.item_name)
			{
				delete [] head->head->an_item.item_name;
				head->head->an_item.item_name = NULL;
			}
			if(head->head->an_item.category)
			{
				delete [] head->head->an_item.category;
				head->head->an_item.category = NULL;
			}
			delete head->head;
			head->head = current;
		}
		if(head->a_store.store_name)
		{
			delete [] head->a_store.store_name;
			head->a_store.store_name = NULL;
		}
		if(head->a_store.website)
		{
			delete [] head->a_store.website;
			head->a_store.website = NULL;
		}
		delete head;
		head = temp;
	}
}

//Adding new store in the store list
int store_list::new_store(store & newstore)
{
	if(!head)
	{
		head = new store_node;
		head->a_store = newstore;
		head->next = NULL;
		return 1;
	}
	if(head)
	{
		store_node * temp = head;
		while(temp->next)
		{
			temp = temp->next;
		}
		temp->next = new store_node;
		temp = temp->next;
		temp->a_store = newstore;
		temp->next = NULL;
		return 1;
	}
	else
		return 0;
}

//Adding new item to the store
int store_list::new_item(item & newitem, char store_name[])
{
	store_node * temp = head;
	while(temp)
	{
		if(strcmp(temp->a_store.store_name, store_name) == 0)
		{
			if(!temp->head)
			{
				temp->head = new item_node;
				temp->head->an_item = newitem;
				temp->head->next = NULL;
				return 1;
			}
			else
			{
				item_node * current = temp->head;
				while(current->next)
				{
					current = current->next;
				}
				current->next = new item_node;
				current = current->next;
				current->an_item = newitem;
				current->next = NULL;
				return 1;
			}
		}
		temp = temp->next;
	}
	return 0;
}

//Removing item
int store_list::remove_item(char item_name[])
{
	store_node * temp = head;
	//No store
	if(!temp)
		return 0;
	while(temp)
	{
		//No item
		while(!temp->head)
		{
			//Go to next store
			temp = temp->next;
			//No more store
			if(!temp)
				return 0;
		}
		//Guaranteed that the store has item
		//Only one item
		if(!temp->head->next)
		{
			if(strcmp(temp->head->an_item.item_name, item_name) == 0)
			{
				delete [] temp->head->an_item.item_name;
				temp->head->an_item.item_name = NULL;
				delete [] temp->head->an_item.category;
				temp->head->an_item.category = NULL;
				delete temp->head;
				temp->head = NULL;
				return 1;
			}
		}
		//Many items
		item_node * current = temp->head->next;
		item_node * previous = temp->head;
		//If it is the first item
		if(strcmp(previous->an_item.item_name, item_name) == 0)
		{
			temp->head = current;
			delete [] previous->an_item.item_name;
			previous->an_item.item_name = NULL;
			delete [] previous->an_item.category;
			previous->an_item.item_name = NULL;
			delete previous;
			previous = NULL;
			return 1;
		}
		//If it is not the first item
		while(current)
		{
			if(strcmp(current->an_item.item_name, item_name) == 0)
			{
				previous->next = current->next;
				delete [] current->an_item.item_name;
				current->an_item.item_name = NULL;
				delete [] current->an_item.category;
				current->an_item.category = NULL;
				delete current;
				current = NULL;
				return 1;
			}
			previous = current;
			current = current->next;
		}
		temp = temp->next;
	}
	return 0;
}

//Displaying store and all the items
int store_list::display_store(char store_name[])
{
	if(!head)
		return 0;
	store_node * temp = head;
	while(temp)
	{
		if(strcmp(temp->a_store.store_name, store_name) == 0)
		{	
			cout << "--------------------" << endl;
			cout << "Store Name: ";
			cout << temp->a_store.store_name << endl;
			cout << "Website: ";
			cout << temp->a_store.website << endl;
			if(temp->head)
			{
				cout << "--------------------" << endl;
				item_node * current = temp->head;
				while(current)
				{
					cout << "Item Name: ";
					cout << current->an_item.item_name << endl;
					cout << "Category: ";
					cout << current->an_item.category << endl;
					cout << "Price: ";
					cout << current->an_item.price << " $" << endl;
					current = current->next;
				}
				cout << "--------------------" << endl;
			}
			return 1;
		}
		else
			temp = temp->next;
	}
	return 0;
}

//Displaying all the items that has same category
int store_list::display_category(char category[])
{
	int flag = 0;
	if(!head)
		return 0;
	store_node * temp = head;
	while(temp)
	{
		item_node * current = temp->head;
		while(current)
		{
			if(strcmp(current->an_item.category, category) == 0)
			{
				cout << "--------------------" << endl;
				cout << "Item Name: ";
				cout << current->an_item.item_name << endl;
				cout << "Category: ";
				cout << current->an_item.category << endl;
				cout << "Price: ";
				cout << current->an_item.price << " $" << endl;
				cout << "--------------------" << endl;
				flag = 1;
			}
			current = current->next;
		}
		temp = temp->next;
	}
	if(flag == 1)
		return 1;
	if(flag == 0)
		return 0;
}

