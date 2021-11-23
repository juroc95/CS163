#include "person.h"

//Juhwan Lee
//CS-163
//Program #5
//The goal of this program is to explore graphs using an adjacency list

struct vertex
{
	person data;
	struct node * head;
};

struct node
{
	vertex * adjacent;
	node * next;
};

class table
{
	public:
		table();
		~table();
		int insert_vertex(person & to_add);
		int find_location(char key_value[]);
		int insert_edge(char current_vertex[], char to_attach[]);
		int display_adjacent(char key_value[]);
		int display_all();
	private:
		vertex * adjacency_list;
		int size;
};

