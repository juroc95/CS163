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

int main()
{

	//declaration
	store_list object;
	store newstore;
	item newitem;
	int result = 0;
	char response = 'y';
	int menu = 0;

	while(menu != 6)
	{
		cout << "Menu: " << endl;
		cout << "1. Add new store to the store list" << endl;
		cout << "2. Add new item to the store" << endl;
		cout << "3. Remove item" << endl;
		cout << "4. Display store with all the items" << endl;
		cout << "5. Display all the items that has same category" << endl;
		cout << "6. Quit" << endl;
		cout << "What do you want to do? (1-6) ";
		cin >> menu;
		cin.ignore(100, '\n');
	
		//Adding new store to the store list
		if(menu == 1)
		{	
			cout << "Do you want to add new store to the store list? ";
			cin >> response;
			cin.ignore(100, '\n');
			while(tolower(response) == 'y')
			{
				char store_name[100];
				char website[100];
				cout << "Please enter store name: ";
				cin.get(store_name, 100, '\n');
				cin.ignore(100, '\n');
				newstore.store_name = new char[strlen(store_name) + 1];
				strcpy(newstore.store_name, store_name);
				cout << "Please enter website: ";
				cin.get(website, 100, '\n');
				cin.ignore(100, '\n');
				newstore.website = new char[strlen(website) + 1];
				strcpy(newstore.website, website);
				result = object.new_store(newstore);
				if(result == 1)
					cout << "new store is added." << endl;
				else
					cout << "store could not be added." << endl;
				cout << "Do you want to add another store? ";
				cin >> response;
				cin.ignore(100, '\n');
			}
		}
	
		//Adding new item to the store
		if(menu == 2)
		{
			cout << "Do you want to add new item to the store? ";
			cin >> response;
			cin.ignore(100, '\n');
			while(tolower(response) == 'y')
			{
				char store_name[100];
				char item_name[100];
				char category[100];
				cout << "Please enter store name: ";
				cin.get(store_name, 100, '\n');
				cin.ignore(100, '\n');
				cout << "Please enter item name: ";
				cin.get(item_name, 100, '\n');
				cin.ignore(100, '\n');
				newitem.item_name = new char[strlen(item_name) + 1];
				strcpy(newitem.item_name, item_name);
				cout << "Please enter its category: ";
				cin.get(category, 100, '\n');
				cin.ignore(100, '\n');
				newitem.category = new char[strlen(category) + 1];
				strcpy(newitem.category, category);
				cout << "Please enter its price(USD): ";
				cin >> newitem.price;
				cin.ignore(100, '\n');
				result = object.new_item(newitem, store_name);
				if(result == 1)
					cout << "item has been added." << endl;
				else
					cout << "item could not be added." << endl;
				cout << "Do you want to add another item? ";
				cin >> response;
				cin.ignore(100, '\n');
			}
		}
	
		//Removing item
		if(menu == 3)
		{
			cout << "Do you want to remove item? ";
			cin >> response;
			cin.ignore(100, '\n');
			while(tolower(response) == 'y')
			{
				char item_name[100];
				cout << "Please enter item name: ";
				cin.get(item_name, 100, '\n');
				cin.ignore(100, '\n');
				result = object.remove_item(item_name);
				if(result == 1)
					cout << "The item has been removed." << endl;
				else
					cout << "The item could not be removed." << endl;
				cout << "Do you want to remove another item? ";
				cin >> response;
				cin.ignore(100, '\n');
			}
		}
	
		//Displaying store with all the items
		if(menu == 4)
		{
			cout << "Do you want to display store with all the items? ";
			cin >> response;
			cin.ignore(100, '\n');
			while(tolower(response) == 'y')
			{
				char store_name[100];
				cout << "Please enter store name: ";
				cin.get(store_name, 100, '\n');
				cin.ignore(100, '\n');
				result = object.display_store(store_name);
				if(result == 1)
					cout << "store displayed." << endl;
				else
					cout << "store could not be displayed." << endl;
				cout << "Do you want to display another store? ";
				cin >> response;
				cin.ignore(100, '\n');
			}
		}

		//Displaying all the items that has same category
		if(menu == 5)
		{
			cout << "Do you want to display all the items that has same category? ";
			cin >> response;
			cin.ignore(100, '\n');
			while(tolower(response) == 'y')
			{
				char category[100];
				cout << "Please enter category: ";
				cin.get(category, 100, '\n');
				cin.ignore(100, '\n');
				result = object.display_category(category);
				if(result == 1)
					cout << "category displayed." << endl;
				else
					cout << "category could not be displayed." << endl;
				cout << "Do you want to display another category? ";
				cin >> response;
				cin.ignore(100, '\n');
			}
		}
	}

	return 0;

}
