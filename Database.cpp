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
	//masterStudent->InOrder(masterStudent->root);
}

void Database::printFaculty()
{
	//masterFaculty->InOrder(masterFaculty->root);
}

void Database::findStudent(int ID)
{
	if(masterStudent->find(ID)==1)
		masterStudent->returnData(ID).printAll();					//Finds the student, uses a function to show all his data.
}

void Database::findFaculty(int ID)
{
	if(masterFaculty->find(ID)==1)	
		masterFaculty->returnData(ID).printAll();
}

void Database::findStudentAdv(int ID)
{
	if(masterStudent->find(ID)==1)
	{
		int AdvisorID=masterStudent->returnData(ID).getAdvisor();
		masterFaculty->returnData(AdvisorID).printAll();
	}
}

void Database::printAdvStudents(int ID)
{
	if(masterFaculty->find(ID)==1)
		masterFaculty->returnData(ID).printStudents();
	else
		cout<<"Advisor not found."<<endl;
}

void Database::addStudent(string M, double gpa, int A, int id, string name, string level)
{
	Student *tempStudent=new Student(id, name, level, M, gpa, A);
	
	masterStudent->insert(id, *tempStudent);
	
	if(masterFaculty->find(A)==1)
		masterFaculty->returnData(A).addStudent(*tempStudent);
	else
		cout<<"Advisor not found."<<endl;
		
}	
void Database::removeStudent(int studentID)
{
	Student tempStudent=masterStudent->returnData(studentID);
	int advisorID=tempStudent.getAdvisor();
	masterFaculty->returnData(advisorID).removeStudent(tempStudent);
	masterStudent->deleteNode(studentID);
}	
void Database::addAdvisor(string D, int id, string name, string level)
{
	Faculty *tempAdvisor= new Faculty(id, name, level, D);
	
	masterFaculty->insert(id, *tempAdvisor);
}
void Database::removeAdvisor(int advisorID, int newAdvisorID)
{
	Faculty oldAdvisor=masterFaculty->returnData(advisorID);				//Finds the necessary advisors and then moves any of the students from the advisor being deleted
	Faculty newAdvisor=masterFaculty->returnData(newAdvisorID);
	
	oldAdvisor.convertStudents(newAdvisor);
	
	
}
void Database::changeStudentAdv(int studentID, int advisorID)
{
	if(masterStudent->find(studentID)==1)
	{
		int currentAdvisorID=masterStudent->returnData(studentID).getAdvisor();
		Student tempStudent=masterStudent->returnData(studentID);
		Faculty oldAdvisor=masterFaculty->returnData(currentAdvisorID);	
		Faculty newAdvisor=masterFaculty->returnData(advisorID);
		if(tempStudent.getAdvisor()!=oldAdvisor.getID())
			cout<<"That student is not an advisee to the given advisor. " <<endl;
		else
		{
			newAdvisor.addStudent(tempStudent);
			oldAdvisor.removeStudent(tempStudent);
		}

	

	}
	else
		cout<<"Student not found."<<endl; 	

}
void Database::removeAdvStudent(int advisorID, int studentID)
{
	if(masterStudent->find(studentID)==1)
	{
		Student tempStudent=masterStudent->returnData(studentID);
		Faculty tempAdvisor=masterFaculty->returnData(advisorID);
		if(tempStudent.getAdvisor()!=advisorID)
			cout<<"That student is not an advisee to the given advisor. " <<endl;
		else
		{
			tempAdvisor.removeStudent(tempStudent);
		}
	}
}
void Database::rollback()
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
				cin>>advisorID;
				
				findFaculty(advisorID);
			}
			else if(option == "5")
			{
				int studentID;
				cout<<"Please input the ID of the student that you would like to find the advisor to." <<endl;
				cin>>studentID;
				findStudentAdv(studentID);
			}
			else if(option == "6")
			{
				int advisorID;
				cout<<"Please input the ID of the advisor that you would like to print the students of. " <<endl;
				cin>>advisorID;
				printAdvStudents(advisorID);
			}
			else if(option == "7")
			{
				studentPrev4=studentPrev3;
				studentPrev3=studentPrev2;
				studentPrev2=studentPrev1;
				studentPrev1=studentPrev;
				studentPrev=masterStudent;
				
				
				int studentID;
				string studentName;
				string studentLevel;
				string studentMajor;
				double studentGPA;
				int advisorID;
				
				cout<<"Please input the ID of the student"<<endl;
				cin>>studentID;
				cout<<"Please input the name of the student"<<endl;
				cin>>studentName;
				cout<<"Please input the level (grade) of the student"<<endl;
				cin>>studentLevel;
				cout<<"Please input the student's major"<<endl;
				cin>>studentMajor;
				cout<<"Please input the student's GPA"<<endl;
				cin>>studentGPA;
				cout<<"Please input the ID of the student's advisor"<<endl;
				cin>>advisorID;
				
				addStudent(studentMajor, studentGPA, advisorID, studentID, studentName, studentLevel);
			}
			else if(option == "8")
			{
				studentPrev4=studentPrev3;
				studentPrev3=studentPrev2;
				studentPrev2=studentPrev1;
				studentPrev1=studentPrev;
				studentPrev=masterStudent;
			
			
				int studentID;
				cout<<"Please input the ID of the student you would like to remove."<<endl;
				cin>>studentID;
				
				removeStudent(studentID);
			}
			else if(option == "9")
			{
				facultyPrev4=facultyPrev3;
				facultyPrev3=facultyPrev2;
				facultyPrev2=facultyPrev1;
				facultyPrev1=facultyPrev;
				facultyPrev=masterFaculty;
			
				int advisorID;
				string advisorName;
				string advisorLevel;
				string advisorDepartment;

				
				cout<<"Please input the ID of the advisor"<<endl;
				cin>>advisorID;
				cout<<"Please input the name of the advisor"<<endl;
				cin>>advisorName;
				cout<<"Please input the level (lecturer, assistant prof, associate prof, etc) of the advisor"<<endl;
				cin>>advisorLevel;
				cout<<"Please input the advisor's department"<<endl;
				cin>>advisorDepartment;


								
				addAdvisor(advisorDepartment, advisorID, advisorName, advisorLevel);
			}
			else if(option == "10")
			{
				int advisorID;
				int newAdvisorID;
				cout<<"Please input the ID of the advisor you would like to remove."<<endl;
				cin>>advisorID;
				cout<<"Please input the ID of the advisor you would like to move the students to."<<endl;
				cin>>newAdvisorID;
				
				removeAdvisor(advisorID, newAdvisorID);
			}
			else if(option == "11")
			{
				int studentID;
				int newAdvisorID;
				cout<<"Please input the ID of the student you would like to change the advisor of"<<endl;
				cin>>studentID;
				cout<<"Please input the ID of the new advisor you would like to move the student to"<<endl;
				cin>>newAdvisorID;
				
				changeStudentAdv(studentID, newAdvisorID);
			}
			else if(option == "12")
			{
				int advisorID;
				int studentID;
				cout<<"Please input the ID of the Advisor you would like to remove a student from"<<endl;
				cin>>advisorID;
				cout<<"Please input the ID of the student you would like to remove"<<endl;
				cin>>studentID;
				removeAdvStudent(advisorID, studentID);
			}
			else if(option == "13")
			{
				rollback();
			}
			else if(option == "14")
			{
				break;
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
int main(int argc, char **argv)
{
	Database myDatabase;
	myDatabase.mainLoop();
}