#include <iostream>
#include "BinaryTree.h"
using namespace std;


int main(int argc, char **argv)
{
	BinaryTree<int> *g= new BinaryTree<int>();
	
	g->insert(4,4);
	g->insert(2,2);
	g->insert(6,6);
	g->insert(12, 12);
	g->insert(1, 1);
	g->insert(3, 3);
	g->insert(5, 5);


		
	return 0;
}