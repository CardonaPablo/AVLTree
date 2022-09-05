#include "Node/Node.hpp"
#include "Tree/Tree.hpp"
#include <iostream>

int main() {
	Tree<int> tree;
	//* Normal Tree
	tree.push(1);
	tree.push(2);
	tree.push(3);
	tree.push(4);
	tree.push(5);
	tree.push(6);
	tree.push(7);
	tree.push(8);

	//* LL Rotation
	// tree.push(30);
	// tree.push(20);
	// tree.push(10);

	//* RR Rotation
	// tree.push(20);
	// tree.push(30);
	// tree.push(40);

	//* LR Rotation
	// tree.push(30);
	// tree.push(20);
	// tree.push(25);

	//* RL Rotation
	// tree.push(30);
	// tree.push(50);
	// tree.push(40);

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