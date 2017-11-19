#include <iostream>
using namespace std;

class Person
{
	public:
		int ID;
		string Name;
		string Level;
		
		Person();
		Person(int id, string name, string level);
		~Person();
		int getID();
		string getName();
		string getLevel();
		void setID(int id);
		void setName(string nm);
		void setLevel(string lvl);
		
};