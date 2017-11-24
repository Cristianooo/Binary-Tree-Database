#include <iostream>
#include "TreeNode.h"
using namespace std;


template <class T>
class BinaryTree 
{
	private:
		TreeNode<T> *root;
	public:
		BinaryTree();
		~BinaryTree();
		
		int find(int key);
		T returnData(int key);
		void insert(int key, T data);
		int remove(int key);
		bool deleteNode(int k);
		TreeNode<T>* getSuccessor(TreeNode<T> *d);
		TreeNode<T>* getRoot();
		
		void InOrder(TreeNode<T> *n);				//Print Methods
		void PreOrder(TreeNode<T> *n);
		void PostOrder(TreeNode<T> *n);
		
		T getMin();
		T getMax();
};
template <class T>
BinaryTree<T>::BinaryTree()
{
	root=NULL;
}

template <class T>
BinaryTree<T>::~BinaryTree()
{
}

template <class T>
int BinaryTree<T>::find(int key)                  
{
	TreeNode<T> *curr=root;
	if(curr==NULL)
		return 0;
	else
	{
		while(true)
		{
			if(key<curr->key)
			{
				curr=curr->left;
			}
			else if(key>curr->key)
			{
				curr=curr->right;
			}
			else if(key==curr->key)
			{
				return 1;
			}
			else if(curr==NULL)
			{	
				return 0;
			}
		}
	}
}
template <class T>
T BinaryTree<T>::returnData(int key)                  
{
	TreeNode<T> *curr=root;
	while(true)
	{
		if(key<curr->key)
		{
			curr=curr->left;
		}
		else if(key>curr->key)
		{
			curr=curr->right;
		}
		else if(key==curr->key)
		{
			return curr->data;
		}
	}
}


template <class T>
void BinaryTree<T>::insert(int key, T data)
{
	TreeNode<T> *node;
	node->data=data;
	node->key=key;

	
	if(root==NULL)
		node=root;
	else
	{
		TreeNode<T> *parent;
		TreeNode<T> *curr=root;
		while(true)
		{
			parent=curr;
			if(key<curr->key)
			{
				curr=curr->left;
				if(curr==NULL)
				{
					parent->left=node;
					break;
				}
			}
			else
			{
				curr=curr->right;
				if(curr==NULL)
				{
					parent->right=node;
					break;
				}
			}
		}
	}
	 
}

template <class T>
bool BinaryTree<T>::deleteNode(int k)
{
	if(root == NULL) //tree is empty
		return false;
		
	TreeNode<T> *curr = root;
	TreeNode<T> *parent = root;
	bool isLeft = true;
	
	while(curr->key != k) //look for the key
	{
		parent = curr;
		
		if(k < curr->key)
		{
			isLeft = true;
			curr = curr->left;
		}
		else
		{
			isLeft = false;
			curr = curr->right;
		}
		
		if(curr == NULL)
			return false;	
	}
	//found the node we want to delete
	
	//deleting a node with no children
	if(curr->left == NULL && curr->right == NULL)
	{
		if(curr == root)
			root= NULL;
		else if(isLeft)
			parent->left = NULL;
		else
			parent->right = NULL;
	}
	//deleting node with 1 child
	else if(curr->right == NULL) //left child
	{
		if(curr == root)
			root = curr->left;
		else if(isLeft)
			parent->left = curr->left;
		else
			parent->right = curr->right;
	}
	else if(curr->left == NULL) //right child
	{
		if(curr == root)
			root = curr->right;
		else if(isLeft)
			parent->left = curr->right;
		else
			parent->right = curr->right;
	}
	//has 2 children
	else
	{
		TreeNode<T> *successor = getSuccessor(curr);
		
		if(curr == root)
			root = successor;
		else if(isLeft)
			parent->left = successor;
		else
			parent->right = successor;
			
		successor->left = curr->left;
	}
	return true;
}

template <class T>
TreeNode<T>* BinaryTree<T>::getSuccessor(TreeNode<T> *d)
{
	TreeNode<T> *sp = d;
	TreeNode<T> *successor = d;
	TreeNode<T> *curr = d->right;
	
	while(curr != NULL)
	{
		sp = successor;
		successor = curr;
		curr = curr->left;
	}
	
	if(successor != d->right)
	{
		sp->left = successor->right;
		successor->right = d->right;
	}
	return successor;
}

template <class T>
TreeNode<T>* BinaryTree<T>::getRoot()
{
	return root;
}

template <class T>
void BinaryTree<T>::InOrder(TreeNode<T> *n)
{
		if(n!=NULL)
		{
			InOrder(n->left);
			cout<<n->data<<endl;
			InOrder(n->right);
		}
}

template <class T>
void BinaryTree<T>::PreOrder(TreeNode<T> *n)
{
	if(n!=NULL)
	{
		cout<<n->key<<n->data<<endl;
		PreOrder(n->left);
		PreOrder(n->right);
	}
}

template <class T>
void BinaryTree<T>::PostOrder(TreeNode<T> *n)
{
	if(n!=NULL)
	{
		PostOrder(n->left);
		PostOrder(n->right);
		cout<<n->key<<n->data<<endl;
	}
}

template <class T>
T BinaryTree<T>::getMin()
{
	TreeNode<T> c=root;
	if(root==NULL)
		return NULL;
	while(c->left!=NULL)
	{
		c=c->left;
	}
	return c->data;
}

template <class T>
T BinaryTree<T>::getMax()
{
	TreeNode<T> c=root;
	while(c->right!=NULL)
	{
		c=c->right;
	}
	return c->data;
}


