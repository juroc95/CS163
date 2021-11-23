#include <iostream>
#include <cctype>
#include <cstring>

//Juhwan Lee
//CS-163
//Program #5
//The goal of this program is to explore graphs using an adjacency list

class person
{
	public:
		person();
		void destructor();
		int set(char name[], char phone_number[]);
		int compare(char key_value[]);
		int is_empty();
		int display();
	private:
		char * name;
		char * phone_number;
};
