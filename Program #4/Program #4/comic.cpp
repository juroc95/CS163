#include "comic.h"
using namespace std;

//Juhwan Lee
//Program #4
//The goal of the fourth program is to move from a hash table and implement a
//binary search tree. The advantage of a binary search tree is the ability to
//retrieve our data using a logarithmic performance if the tree is relatively
//balanced and be able to search for a range of information and obtain our data
//in sorted order.

comic::comic()
{
	name = NULL;
	publisher = NULL;
	superhero = NULL;
	issue = NULL;
	review = NULL;
	other = NULL;
}

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
	if(other)
		delete [] other;
	name = NULL;
	publisher = NULL;
	superhero = NULL;
	issue = NULL;
	review = NULL;
	other = NULL;
}

int comic::set(char newname[], char newpublisher[], char newsuperhero[], char newissue[], char newreview[], char newother[])
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
	other = new char[strlen(newother) + 1];
	strcpy(other, newother);
	return 1;
}

int comic::display()
{
	cout << "--------------------" << endl
	<< "The name of the comic : " << name << endl
	<< "The publisher : " << publisher << endl
	<< "The superhero : " << superhero << endl
	<< "The issue : " << issue << endl
	<< "A review : " << review << endl
	<< "Other items you are interested in : " << other << endl
	<< "--------------------" << endl;
	return 1;
}

int comic::copy_superhero(char copy[])
{
	if(!superhero)
		return 0;
	strcpy(copy, superhero);
	return 1;
}

int comic::copy(char newname[], char newpublisher[], char newsuperhero[], char newissue[], char newreview[], char newother[])
{
	strcpy(newname, name);
	strcpy(newpublisher, publisher);
	strcpy(newsuperhero, superhero);
	strcpy(newissue, issue);
	strcpy(newreview, review);
	strcpy(newother, other);
	return 1;
}

int comic::copy_name(char copy[])
{
	if(!name)
		return 0;
	strcpy(copy, name);
	return 1;
}
