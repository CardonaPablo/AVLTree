#include "Node/Node.hpp"
#include "Tree/Tree.hpp"
#include <iostream>

int main() {
	Node<int> root;
	Tree<int> t(&root);
	//* Normal Tree
	// root.setData(60);
	// root.push(20);
	// root.push(70);
	// root.push(10);
	// root.push(40);
	// root.push(30);
	// root.push(50);

	//* LL Rotation
	// root.setData(30);
	// root.push(20);
	// root.push(10);

	//* RR Rotation
	root.setData(30);

	root.push(20);
	root.push(40);
	root.push(35);
	root.push(50);

	std::cout << "FINAL FORM" << std::endl;
	t.drawTree();
	
	//* Orders
	// std::cout << "PreOrder" << std::endl;
	// root.preOrder();
	// std::cout << std::endl << "InOrder" << std::endl;
	// root.inOrder();
	// std::cout << std::endl<< "PostOrder" << std::endl;
	// root.postOrder();
}