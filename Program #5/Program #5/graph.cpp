#include "graph.h"
using namespace std;

//Juhwan Lee
//CS-163
//Program #5
//The goal of this program is to explore graphs using an adjacency list

table::table()
{
	size = 10;
	adjacency_list = new vertex [size];
	for(int i = 0; i < size; ++i)
	{
		adjacency_list[i].head = NULL;
	}
}

table::~table()
{
	for(int i = 0; i < size; ++i)
	{
		adjacency_list[i].data.destructor();
		if(adjacency_list[i].head != NULL)
		{
			node * temp = adjacency_list[i].head;
			while(adjacency_list[i].head != NULL)
			{
				adjacency_list[i].head = adjacency_list[i].head->next;
				delete temp;
				temp = adjacency_list[i].head;
			}
		}
	}
	delete [] adjacency_list;
}

int table::insert_vertex(person & to_add)
{
	int flag = 0;
	for(int i = 0; i < size; ++i)
	{
		if(adjacency_list[i].data.is_empty() == 1)
		{
			adjacency_list[i].data = to_add;
			i = size;
			flag = 1;
		}
	}
	if(flag == 1)
		return 1;
	else
		return 0;
}

int table::insert_edge(char current_vertex[], char to_attach[])
{
	int i = 0;
	int j = 0;
	i = find_location(current_vertex);
	j = find_location(to_attach);
	if(i == 99 || j == 99)
		return 0;
	if(adjacency_list[i].head == NULL)
	{
		adjacency_list[i].head = new node;
		adjacency_list[i].head->adjacent = &adjacency_list[j];
		adjacency_list[i].head->next = NULL;
	}
	else
	{
		node * temp = adjacency_list[i].head;
		while(temp->next)
		{
			temp = temp->next;
		}
		temp->next = new node;
		temp = temp->next;
		temp->adjacent = &adjacency_list[j];
		temp->next = NULL;
	}
	if(adjacency_list[j].head == NULL)
	{
		adjacency_list[j].head = new node;
		adjacency_list[j].head->adjacent = &adjacency_list[i];
		adjacency_list[j].head->next = NULL;
	}
	else
	{
		node * temp = adjacency_list[j].head;
		while(temp->next)
		{
			temp = temp->next;
		}
		temp->next = new node;
		temp = temp->next;
		temp->adjacent = &adjacency_list[i];
		temp->next = NULL;
	}
	return 1;
}
		
int table::find_location(char key_value[])
{
	int flag = 0;
	int index = 0;
	for(int i = 0; i < size; ++i)
	{
		if(adjacency_list[i].data.is_empty() == 0)
		{
			if(adjacency_list[i].data.compare(key_value))
			{
				index = i;
				i = size;
				flag = 1;
			}
		}
	}
	if(flag == 1)
		return index;
	else
		return 99;
}

int table::display_adjacent(char key_value[])
{
	int flag = 0;
	for(int i = 0; i < size; ++i)
	{
		if(adjacency_list[i].data.is_empty() == 0)
		{
			if(adjacency_list[i].data.compare(key_value) == 1)
			{
				adjacency_list[i].data.display();
				node * temp = adjacency_list[i].head;
				if(!temp)
					cout << "*** Was in contact with no one ***" << endl;
				else
					cout << "*** Was in contact with ***" << endl;
				while(temp)
				{
					temp->adjacent->data.display();
					temp = temp->next;
				}
				flag = 1;
			}
		}
	}
	if(flag == 1)
		return 1;
	else
		return 0;
}

int table::display_all()
{
	int flag = 0;
	for(int i = 0; i < size; ++i)
	{
		if(adjacency_list[i].data.is_empty() == 0)
		{
			adjacency_list[i].data.display();
			flag = 1;
		}
	}
	if(flag == 1)
		return 1;
	else
		return 0;
}
