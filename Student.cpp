#include <iostream>
#include "Student.h"
using namespace std;

Student::Student():Person()
{
	Major = " ";
	GPA = 0;
	Advisor = 0;
}

Student::Student(string M, double gpa, int A):Person(int id, string name, string level)
{
	Major=M;
	GPA=gpa;
	Advisor=A;
}
Student::~Student()
{
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
	getMajor();
	getGPA();
	getAdvisor();
}


