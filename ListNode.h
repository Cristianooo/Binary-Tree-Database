#include <iostream>

template <class T>
class ListNode
{
	public:
		T data;
		ListNode *next;
		ListNode *prev;
		
		ListNode();
		ListNode(T data);
		~ListNode();
		
};

template <class T>
ListNode<T>::ListNode()
{
}

template <class T>
ListNode<T>::ListNode(T d)
{
	data=d;
	next=NULL;
	prev=NULL;
}
template <class T>
ListNode<T>::~ListNode()
{
	next=NULL;
	prev=NULL;		
}