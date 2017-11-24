#include <iostream>
#include "Student.h"
using namespace std;

Student::Student()
{
	ID = 0;
	Name = " ";
	Level = " ";
	Major = " ";
	GPA = 0;
	Advisor = 0;
}

Student::Student(int id, string name, string level, string M, double gpa, int A)
{
	ID = id;
	Name= name;
	Level = level;
	Major=M;
	GPA=gpa;
	Advisor=A;
}
Student::~Student()
{
}
int Student::getID()
{
	return ID;
}

string Student::getName()
{
	return Name;
}

string Student::getLevel()
{
	return Level;
}

void Student::setID(int id)
{
	ID = id;
}

void Student::setName(string nm)
{
	Name = nm;
}

void Student::setLevel(string lvl)
{
	Level = lvl;
}
string Student::getMajor()
{
	return Major;
}

double Student::getGPA()
{
	return GPA;
}

int Student::getAdvisor()
{
	return Advisor;
}

void Student::setMajor(string major)
{
	Major = major;
}
		
void Student::setGPA(double gpa)
{
	GPA = gpa;
}

void Student::setAdvisor(int A)
{
	Advisor = A;
}

void Student::printAll()
{
	cout<<getMajor()<<endl;
	cout<<getGPA()<<endl;
	cout<<getAdvisor()<<endl;
}
void Student::empty()
{
	ID = 0;
	Name = " ";
	Level = " ";
	Major = " ";
	GPA = 0;
	Advisor = 0;
}
bool Student::operator==(Student &stu)
{
	if(ID==stu.getID() && Name==stu.getName() && Level==stu.getLevel() && Major==stu.getMajor()
   && GPA==stu.getGPA())
   		return true;
	else
   		return false;
}
