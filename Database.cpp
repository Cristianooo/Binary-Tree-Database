#include <iostream>

using namespace std;

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
	TreeNode<T> *curr=root;
	if(curr==NULL)
		cout<< "Database is empty"<<endl;
	else
	{
		while(true)
		{
			if(ID<curr->key)
			{
				curr=curr->left;
			}
			else if(ID>curr->key)
			{
				curr=curr->right;
			}
			else if(ID==curr->key)
			{
				cout<< curr->data.printAll()<< endl;
			}
			else if(curr==NULL)
			{	
				cout<< "Student not found."<<endl;
			}
		}
	}
}
void Database::findFaculty(int ID)
{
	TreeNode<T> *curr=masterStudent->root;
	if(curr==NULL)
		cout<< "Database is empty"<<endl;
	else
	{
		while(true)
		{
			if(ID<curr->key)
			{
				curr=curr->left;
			}
			else if(ID>curr->key)
			{
				curr=curr->right;
			}
			else if(ID==curr->key)
			{
				cout<< curr->data.printAll()<< endl;
			}
			else if(curr==NULL)
			{	
				cout<< "Advisor not found."<<endl;
			}
		}
	}
}
		
void Databse::findStudentAdv(int ID)
{
	if(
}
void Database::printAdvStudents(int ID)
{
	
}
		
void Database::switchStudentAdv()
{
	
}
void Database::removeAdv(int ID)
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
			string answer;
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
			cin>> answer;
		
			if(answer == "1")
			{
		
			}
			else if(answer == "2")
			{
		
			}
			else if(answer == "3")
			{
		
			}
			else if(answer == "4")
			{
		
			}
			else if(answer == "5")
			{
		
			}
			else if(answer == "6")
			{
		
			}
			else if(answer == "7")
			{
		
			}
			else if(answer == "8")
			{
		
			}
			else if(answer == "9")
			{
		
			}
			else if(answer == "10")
			{
		
			}
			else if(answer == "11")
			{
		
			}
			else if(answer == "12")
			{
		
			}
			else if(answer == "13")
			{
		
			}
			else if(answer == "14")
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