/*
a.
Cristiano Firmani
Yiftach Nachman
b.
2272725 (Cristiano)
2270838	(Yiftach)
c.
firma103
nachm100
d.
CSPC-350 Section 2
e.
Assignment 2
*/

#include <iostream>
#include "Database.h"
#include <fstream>

using namespace std;
      
Database::Database()
{
	
}
Database::~Database()
{
	
}  
void Database::printStudents()
{
	masterStudent.InOrder();
}

void Database::printFaculty()
{
	masterFaculty.InOrder();
}

void Database::findStudent(int ID)
{
	cout<<masterStudent.find(ID).printAll()<<endl;					//Finds the student, uses a function to show all his data.
}

void Database::findFaculty(int ID)
{
	cout<<masterFaculty.find(ID).printAll()<<endl;
}

void Database::findStudentAdv(int ID)
{
	int AdvisorID=masterStudent.find(ID).getAdvisor();
	cout<<masterFaculty.find(AdvisorID).printAll()<<endl;
}

void Database::printAdvStudents(int ID)
{
	cout<<masterFaculty.find(ID).printStudents();
}

void Database::addStudent(string M, double gpa, int A, int id, string name, string level)
{
	Student *tempStudent;
	tempStudent->Name=name;
	tempStudent->Level=level;
	tempStudent->ID=id;
	tempStudent->Advisor=A;
	tempStudent->GPA=gpa;
	tempStudent->Major=M;
	
	masterStudent.insert(id, tempStudent);
	
	masterFaculty.find(A).addStudent(tempStudent);
}	
void Database::removeStudent(int studentID, int advisorID)
{
	masterFaculty.find(advisorID).removeStudent(studentID);
	masterStudent.deleteNode(studentID);
}	
void Database::addAdvisor(string D, int id, string name, string level)
{
	Faculty *tempAdvisor;
	tempAdvisor->Name=name;
	tempAdvisor->Level=level;
	tempAdvisor->ID=id;
	tempAdvisor->Department=D;
	
	masterFaculty.insert(id, tempAdvisor);
}
void Database::removeAdvisor(int advisorID, int newAdvisorID)
{
	Faculty *oldAdvisor=masterFaculty.find(advisorID);				//Finds the necessary advisors and then moves any of the students from the advisor being deleted
	Faculty *newAdvisor=masterFaculty.find(newAdvisorID);
	
	int loopAmt=oldAdvisor->Students.length();
	for(int i = 0; i < loopAmt; ++i)
	{
		if(oldAdvisor->Students[i]!=NULL)
		{
			newAdvisor->Students.add(Students[i];
		}
	}

}
void Database::changeStudentAdv(int studentID, int advisorID)
{
	int currentAdvisorID=masterStudent.find(studentID).getAdvisor();
	
	if(masterFaculty.find(currentAdvisorID).findStudent(studentID)!=0)
	{
		Student *tempStudent=masterFaculty.find(currentAdvisorID).findStudent(studentID);
		Faculty *oldAdvisor=masterFaculty.find(currentAdvisorID);	
		Faculty *newAdvisor=masterFaculty.find(advisorID);
		
		newAdvisor->addStudent(tempStudent);
		
		
	}
	else
		cout<<"Student not found." <<endl;
}
void Database::removeAdvStudent(int advisorID, int studentID)
{
	
}
void Datalbase::rollback()
{
	
}
void Database::mainLoop()
{
	string keepGoing="yes";
	while(keepGoing=="yes")
	{
		if(ifstream("facultyTable.txt") && ifstream("studentTable.txt"))
		{
			string option;
			cout<<"Which option would you like to complete: "<<endl;
			cout<< "1. Print all students and their information "<<endl;
			cout<< "2. Print all faculty and their information " <<endl;
			cout<< "3. Find and display student information given the students id " <<endl;
			cout<< "4. Find and display faculty information given the faculty id " <<endl;
			cout<< "5. Given a student’s id, print the name and info of their faculty advisor " <<endl;
			cout<< "6. Given a faculty id, print ALL the names and info of his/her advisees " <<endl;
			cout<< "7. Add a new student " <<endl;
			cout<< "8. Delete a student given the id " <<endl;
			cout<< "9. Add a new faculty member " <<endl;
			cout<< "10. Delete a faculty member given the id " <<endl;
			cout<< "11. Change a student’s advisor given the student id and the new faculty id " <<endl;
			cout<< "12. Remove an advisee from a faculty member given the ids " <<endl;
			cout<< "13. Rollback " <<endl;
			cout<< "14. Exit " <<endl;
			
			cout<< "\n Simply type the number you would like to complete. ('1' or '2 or '3' etc.)" <<endl;
			cin>> option;
		
			if(option == "1")
			{
				printStudents();
			}
			else if(option == "2")
			{
				printFaculty();
			}
			else if(option == "3")
			{
				int studentID;
				cout<< "Please input the ID of the student you would like to find: " <<endl;
				cin>>studentID;
				
				findStudent(studentID);
				
			}
			else if(option == "4")
			{
				int advisorID;
				cout<< "Please input the ID of the advisor you would like to find: "<<endl;
				cin<<advisorID;
				
				findFaculty(advisorID);
			}
			else if(option == "5")
			{
				int studentID;
				cout<<"Please input the ID of the student that you would like to find the advisor to." <<endl;
				findStudentAdv(studentID);
			}
			else if(option == "6")
			{
		
			}
			else if(option == "7")
			{
		
			}
			else if(option == "8")
			{
		
			}
			else if(answer == "9")
			{
		
			}
			else if(option == "10")
			{
		
			}
			else if(option == "11")
			{
		
			}
			else if(option == "12")
			{
		
			}
			else if(option == "13")
			{
		
			}
			else if(option == "14")
			{
		
			}
			else
			{
				cout<< "Invalid entry" << endl;
			}
		}
		else
		{
			ofstream outfile ("FacultyTable.txt");

			outfile << "Faculty Table" << endl;

			outfile.close();
		
			ofstream outifle("StudentTable.txt");
		
			outfile<< "Student Table"<< endl;
		
			outfile.close();
		
		}
		cout<< "Would you like to complete another operation? ('yes'/'no')" <<endl;
		cin>> keepGoing;
	}
}