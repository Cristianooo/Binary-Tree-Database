#include <iostream>
using namespace std;

template <class T>
class TreeNode
{
	public:
		int key;
		T data;
		TreeNode *right;
		TreeNode *left;
		
		TreeNode();
		TreeNode(T data, int key);
		~TreeNode();
		
};
template <class T>
TreeNode<T>::TreeNode()
{
	key=0;
	right=NULL;
	left=NULL;
}

template <class T>
TreeNode<T>::TreeNode(T d, int k)
{
	key=k;
	data=d;
	right=NULL;
	left=NULL;
}

template <class T>
TreeNode<T>::~TreeNode()
{
	right=NULL;
	left=NULL;		
}
