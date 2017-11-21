#include <iostream>
#include "Faculty.h"

using namespace std;

Faculty::Faculty():Person()
{
	Departmant=" ";
}

Faculty::Faculty(string D):Person(int id, string name, string level)
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
void Faculty::addStudent(Student stu)
{
	Students.add(stu);
}
void Faculty::removeStudent(int studentID)
{
	for(int i = 0; i < Students.length(); ++i)
	{
		if(Students[i]!=NULL)
		{
			if((Students[i].getID())==studentID)
			{
				Students[i]=NULL;
			}
		}
	}
}
Student Faculty::findStudent(int studentID)
{
	for(int i = 0; i < Students.length(); ++i)
	{
		if(Students[i]!=NULL)
		{
			if((Students[i].getID())==studentID)
			{
				return Students[i];
			}
		}
	}
	return 0;
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
	printStudents()
}
void Faculty::printStudents()
{
	for(int i = 0; i < Students.length(); ++i)
	{
		if(Students[i]!=NULL)
			cout<< Students[i] <<endl;
	}
}