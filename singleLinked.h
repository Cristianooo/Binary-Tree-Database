#include <iostream>
#include "ListNode.h"

using namespace std;

template <class T>
class SingleLinked
{
	private:
		unsigned int size;
		ListNode<T> *front;
		ListNode<T> *back;
	public:
		SingleLinked();
		~SingleLinked();
		
		unsigned int getSize();
		void insertBack(T data);
		void insertFront(T data);
		void printList();
		T removeFront();
		T returnData(int pos);
		T deletePos(int pos);
		int find(T value);

		bool isEmpty();
		
};
template <class T>
SingleLinked<T>::SingleLinked()
{
	front=NULL;
	back=NULL;
	size=0;
}

template <class T>
SingleLinked<T>::~SingleLinked()
{
	
}
template <class T>
unsigned int SingleLinked<T>::getSize()
{
	return size;
}
template <class T>
void SingleLinked<T>::insertBack(T data)
{
	++size;
	ListNode<T> *node = new ListNode<T>(data);
	
	if(front==NULL)
		front=back;
	else
	{
		back->next=node;
		back=node;
	}
}

template <class T>
void SingleLinked<T>::insertFront(T data)
{
	++size;
	ListNode<T> *node = new ListNode<T>(data);
	node->next=front;
	front=node;
	
}

template <class T>
T SingleLinked<T>::removeFront()
{
	--size;
	int temp=front->data;
	ListNode<T> *ft = front;
	front=front->next;
	ft->next=NULL;
	delete ft;
	return temp;
}

template <class T>
void SingleLinked<T>::printList()
{
	ListNode<T> *curr = front;
	while(curr->data!=NULL)
	{
		std::cout<<curr->data<<std::endl;
		curr=curr->next;
	}

}

template <class T>
int SingleLinked<T>::find(T value)
{
	int idx=-1;
	
	ListNode<T> *curr = front;
	
	while(curr != NULL)		//Start searching for value
	{	
		++idx;
		if(curr->data == value)		
			break;
		else
			curr=curr->next;
	}
	if(curr==NULL)
		idx=-1;
	
	return idx;
	
}

template <class T>
T SingleLinked<T>::returnData(int pos)
{
	int idx=0;
	ListNode<T> *curr=front;
	while(idx!=pos)
	{
		curr=curr->next;
		++idx;
	}
	return curr->data;
}
template <class T>
T SingleLinked<T>::deletePos(int pos)
{
	int idx=0;
	ListNode<T> *curr = front;
	ListNode<T> *prev = front;
	
	while(idx!=pos)
	{
		prev=curr;
		curr=curr->next;
		++idx;
			
	}
	
	
	prev->next=curr->next;
	curr->next=NULL;
	T d= curr->data;
	delete curr;
	
	size--;
	return d;
	
}

