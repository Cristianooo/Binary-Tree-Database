#include <iostream>
#include "Person.h"



using namespace std;

class Faculty : public Person
{
	public:
		string Department;
		Student Students[100];
		
		Faculty();
		Faculty(string D);
		~Faculty();
		
		string getDepartment();
		void addStudent(Student *stu);
		void removeStudent(int studentID);
		void setDepartment(string D);
		void printStudents();
		void printAll();
};