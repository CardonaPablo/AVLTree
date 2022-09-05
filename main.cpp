#include "Node/Node.hpp"
#include "Tree/Tree.hpp"
#include <iostream>

int main() {
	Node<int> root;
	Tree<int> tree;
	//* Normal Tree
	// root.setData(60);
	// root.push(20);
	// root.push(70);
	// root.push(10);
	// root.push(40);
	// root.push(30);
	// root.push(50);

	//* LL Rotation
	// tree.push(30);
	// tree.push(20);
	// tree.push(10);

	//* RR Rotation
	// tree.push(20);
	// tree.push(30);
	// tree.push(40);

	//* LR Rotation
	tree.push(30);
	tree.push(20);
	tree.push(25);

	std::cout << "FINAL FORM" << std::endl;
	tree.drawTree();
	
	//* Orders
	// std::cout << "PreOrder" << std::endl;
	// root.preOrder();
	// std::cout << std::endl << "InOrder" << std::endl;
	// root.inOrder();
	// std::cout << std::endl<< "PostOrder" << std::endl;
	// root.postOrder();
}