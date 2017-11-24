#include "BinaryTree.h"
#include "Student.h"
#include "Faculty.h"
#include "genstack.h"

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
		
		//genstack<BinaryTree<Faculty>*> Rollbacks= new genstack<BinaryTree<Faculty>*>;
		
	public:
		Database();
		~Database();
		
		void printStudents();
		void printFaculty();
		
		void findStudent(int ID);
		void findFaculty(int ID);
		
		void findStudentAdv(int ID);
		void printAdvStudents(int ID);
		
		void addStudent(string M, double gpa, int A, int id, string name, string level);
		void removeStudent(int studentID);
		
		void addAdvisor(string D, int id, string name, string level);
		void removeAdvisor(int advisorID, int newAdvisorID);
		
		void changeStudentAdv(int studentID, int advisorID);
		void removeAdvStudent(int advisorID, int studentID);
		void rollback();
		
		void mainLoop();
};
