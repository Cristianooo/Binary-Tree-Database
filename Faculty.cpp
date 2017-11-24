#include <iostream>
#include "Faculty.h"

using namespace std;

Faculty::Faculty()
{
	Department=" ";
	ID = 0;
	Name = " ";
	Level = " ";
}

Faculty::Faculty(int id, string name, string level, string D)
{
	ID = id;
	Name= name;
	Level = level;
	Department=D;
}

Faculty::~Faculty()
{
	Department = " ";
}

int Faculty::getID()
{
	return ID;
}

string Faculty::getName()
{
	return Name;
}

string Faculty::getLevel()
{
	return Level;
}

void Faculty::setID(int id)
{
	ID = id;
}

void Faculty::setName(string nm)
{
	Name = nm;
}

void Faculty::setLevel(string lvl)
{
	Level = lvl;
}

string Faculty::getDepartment()
{
	return Department;
}
void Faculty::addStudent(Student stu)
{
	Students.insertBack(stu);
}
void Faculty::removeStudent(Student stu)
{
	if(Students.find(stu)!=-1)
	{
		int deleteIndex=Students.find(stu);
		Students.deletePos(deleteIndex);
	}
	else
		cout<<"Student not found"<<endl;
		
	
}
void Faculty::convertStudents(Faculty newAdvisor)
{
	
	for(int i=0; i<Students.getSize();++i)
	{
		Student tempStudent=Students.returnData(i);
		newAdvisor.Students.insertBack(tempStudent);
	}
}

Student Faculty::findStudent(Student stu)
{
	if(Students.find(stu)!=-1)
	{
		int foundIndex=Students.find(stu);
		return Students.returnData(foundIndex);
	}
	else
	{
		Student tempStudent;
		return tempStudent;
	}
}
void Faculty::setDepartment(string D)
{
	Department=D;
}

void Faculty::printAll()
{
	cout<<getDepartment()<<endl;
	cout<<getID()<<endl;
	cout<<getName()<<endl;
	cout<<getLevel()<<endl;
	printStudents();
}
void Faculty::printStudents()
{
	for(int i = 0; i < Students.getSize(); ++i)
	{
			Student tempStudent=Students.returnData(i);
			cout<< tempStudent.getName() <<endl;
	}
}