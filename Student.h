#include <iostream>

using namespace std;

#ifndef STUDENT_H
#define STUDENT_H
class Student
{
	public:
		int ID;
		string Name;
		string Level;
		string Major;
		double GPA;
		int Advisor;
		
		Student();
		Student(int id, string name, string level, string M, double gpa, int A);
		~Student();
		
		int getID();
		string getName();
		string getLevel();
		void setID(int id);
		void setName(string nm);
		void setLevel(string lvl);
		string getMajor();
		double getGPA();
		int getAdvisor();
		void setMajor(string major);
		void setGPA(double gpa);
		void setAdvisor(int A);
		
		void printAll();
		void empty();
		bool operator==(Student &stu);
		friend ostream& operator<<(ostream& os, const Student& stu);
		
};
#endif