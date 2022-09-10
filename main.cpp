#include "Node/Node.hpp"
#include "Tree/Tree.hpp"
#include <iostream>

int main() {
	Tree<int> tree;
	tree.push(5);
	tree.push(4);
	tree.push(7);
	tree.push(6);
	tree.push(8);
	tree.push(9);

	std::cout << "FINAL FORM" << std::endl;
	tree.drawTree();
	
	//* Orders
	std::cout << "PreOrder" << std::endl;
	tree.preOrder();
	std::cout << std::endl << "InOrder" << std::endl;
	tree.inOrder();
	std::cout << std::endl<< "PostOrder" << std::endl;
	tree.postOrder();
}