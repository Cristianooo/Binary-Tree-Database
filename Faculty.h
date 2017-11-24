#include <iostream>
#include "Student.h"
#include "SingleLinked.h"

using namespace std;

class Faculty 
{
	public:
		int ID;
		string Name;
		string Level;
		string Department;
		SingleLinked<Student> Students;
		
		Faculty();
		Faculty(int id, string name, string level, string D);
		~Faculty();
		
		int getID();
		string getName();
		string getLevel();
		void setID(int id);
		void setName(string nm);
		void setLevel(string lvl);
		string getDepartment();
		void addStudent(Student stu);
		void removeStudent(Student stu);
		void convertStudents(Faculty oldAdvisor);
		Student findStudent(Student stu);
		void setDepartment(string D);
		void printStudents();
		void printAll();
};