#include <iostream>

using namespace std;

template <class T>
class genstack
{
	public:
		genstack(int maxsize);
		~genstack();
		
		void push(T data);
		T pop();
		T peek(); //top()
		int isFull();
		int isEmpty();
		
		int top;
		int max;
		
		T *myArray;
};

template <class T>
genstack<T>::genstack(int maxsize)
{
	myArray = new T[maxsize];
	max = maxsize;
	top= -1;
}

template <class T>
genstack<T>::~genstack()
{
	delete [] myArray; 
}

template <class T>
void genstack<T>::push(T data)
{
	if(top != max-1)								//need to check if full
		myArray[++top] = data;
	else
		cout << "Your array is full" << endl;
}

template <class T>
T genstack<T>::pop()
{
	if(top != -1)						//need to check if empty
		return myArray[top--];
	else
		return myArray[0];
}

template <class T>
T genstack<T>::peek()
{
	if(top != -1)						//need to check if empty
		return myArray[top];
	else
		return myArray[0];
}

template <class T>
int genstack<T>::isFull()
{
	return (top == max-1);
}

template <class T>
int genstack<T>::isEmpty()
{
	return (top == -1);
}