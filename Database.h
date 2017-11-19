#include <iostream>
#include "BinaryTree.h"
#include "Student.h"
#include "Faculty.h"

using namespace std;
class Student
{
	private:
		BinaryTree<T> *masterFaculty;
		BinaryTree<T> *masterStudent;
	
	
		BinaryTree<T> *studentPrev;				//Student Rollbacks
		BinaryTree<T> *studentPrev1;
		BinaryTree<T> *studentPrev2;
		BinaryTree<T> *studentPrev3;
		BinaryTree<T> *studentPrev4;
		
		BinaryTree<T> *facultyPrev;				//Faculty Rollbacks
		BinaryTree<T> *facultyPrev1;
		BinaryTree<T> *facultyPrev2;
		BinaryTree<T> *facultyPrev3;
		BinaryTree<T> *facultyPrev4;
	public:
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