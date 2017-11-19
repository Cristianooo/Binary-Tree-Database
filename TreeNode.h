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
