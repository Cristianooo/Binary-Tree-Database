#include <iostream>
#include "Person.h"
using namespace std;

Person::Person()
{
	ID = 0;
	Name = " ";
	Level = " ";
}

Person::Person(int id, string name, string level)
{
	ID = id;
	Name= name;
	Level = level;
}

Person::~Person()
{
	ID = 0;
	Name = "";
	Level = "";
}

int Person::getID()
{
	return ID;
}

string Person::getName()
{
	return Name;
}

string Person::getLevel()
{
	return Level;
}

void Person::setID(int id)
{
	ID = id;
}

void Person::setName(string nm)
{
	Name = nm;
}

void Person::setLevel(string lvl)
{
	Level = lvl;
}