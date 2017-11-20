#include <iostream>
#include "BinaryTree.h"
#include "Student.h"
#include "Faculty.h"

using namespace std;
class Database
{
	private:
		BinaryTree<Faculty> *masterFaculty;
		BinaryTree<Student> *masterStudent;
		
		BinaryTree<Faculty> *facultyPrev;				//Faculty Rollbacks
		BinaryTree<Faculty> *facultyPrev1;
		BinaryTree<Faculty> *facultyPrev2;
		BinaryTree<Faculty> *facultyPrev3;
		BinaryTree<Faculty> *facultyPrev4;
	
	
		BinaryTree<Student> *studentPrev;				//Student Rollbacks
		BinaryTree<Student> *studentPrev1;
		BinaryTree<Student> *studentPrev2;
		BinaryTree<Student> *studentPrev3;
		BinaryTree<Student> *studentPrev4;
		
	public:
		Database();
		~Database();
		
		void printStudents();
		void printFaculty();
		
		void findStudent();
		void findFaculty();
		
		void findStudentAdv(int ID);
		void printAdvStudents(int ID);
		
		void switchStudentAdv();
		void removeAdv();
		
		void rollback();
		
		void mainLoop();
		
};