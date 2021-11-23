#include "comic.h"
using namespace std;

//Juhwan Lee
//Program #3
//In this program, we will create a program that will help us collect and catalog
//comics that we are interested in. We will be using hash table and external data
//files for this program.

//Constructor
comic::comic()
{
	name = NULL;
	publisher = NULL;
	superhero = NULL;
	issue = NULL;
	review = NULL;
	other_info = NULL;
}

//Destructor
comic::~comic()
{
	if(name)
		delete [] name;
	if(publisher)
		delete [] publisher;
	if(superhero)
		delete [] superhero;
	if(issue)
		delete [] issue;
	if(review)
		delete [] review;
	if(other_info)
		delete [] other_info;
	name = NULL;
	publisher = NULL;
	superhero = NULL;
	issue = NULL;
	review = NULL;
	other_info = NULL;
}

//Create new comic
int comic::create(char newname[], char newpublisher[], char newsuperhero[], char newissue[], char newreview[], char newother_info[])
{
	name = new char[strlen(newname) + 1];
	strcpy(name, newname);
	publisher = new char[strlen(newpublisher) + 1];
	strcpy(publisher, newpublisher);
	superhero = new char[strlen(newsuperhero) + 1];
	strcpy(superhero, newsuperhero);
	issue = new char[strlen(newissue) + 1];
	strcpy(issue, newissue);
	review = new char[strlen(newreview) + 1];
	strcpy(review, newreview);
	other_info = new char[strlen(newother_info) + 1];
	strcpy(other_info, newother_info);
	return 1;
}

//Display comic
int comic::display()
{
	cout << "--------------------" << endl;
	cout << "Name : " << name << endl;
	cout << "Publisher : " << publisher << endl;
	cout << "Superhero : " << superhero << endl;
	cout << "Issue : " << issue << endl;
	cout << "Review : " << review << endl;
	cout << "Other informations : " << other_info << endl;
	cout << "--------------------" << endl;
	return 1;
}

//Remove a comic based on the name of the comic book
int comic::is_match(char name_search[])
{
	if(strcmp(name, name_search) == 0)
		return 1;
	else
		return 0;
}
