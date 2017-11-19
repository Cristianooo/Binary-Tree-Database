#include <iostream>
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
		void setDepartment(string D);
		void printAll();
};