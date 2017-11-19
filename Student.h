#include <iostream>
using namespace std;

class Student : public Person
{
	public:
		string Major;
		double GPA;
		int Advisor;
		
		Student();
		Student(string M, double gpa, int A);
		~Student();
		
		string getMajor();
		double getGPA();
		int getAdvisor();
		void setMajor(string major);
		void setGPA(double gpa);
		void setAdvisor(int A);
		
		void printAll();
		
};