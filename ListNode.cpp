#include "ListNode.h"

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