#include <iostream>
#include "Faculty.h"

using namespace std;

Faculty:Faculty()
{
	Departmant=" ";
}

Faculty::Faculty(string D)
{
	Department=D;
}

Faculty::~Faculty()
{
	Department = " ";
}

string Faculty::getDepartment()
{
	return Department;
}

void Faculty::setDepartment(string D)
{
	Department=D;
}

void Faculty::printAll()
{
	getDepartment();
	getID();
	getName();
	getLevel();
	for(int i = 0; i < Students.length(); ++i)
	{
		cout<< Students[i] <<endl;
	}
}
void Faculty::printStudents()
{
	for(int i = 0; i < Students.length(); ++i)
	{
		if(Students[i]!=NULL)
			cout<< Students[i] <<endl;
	}
}