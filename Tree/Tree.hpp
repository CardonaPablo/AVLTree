#ifndef TREE_H
#define TREE_H

template <typename T> 
class Node;

#include <iostream>

template <typename T> 
class Tree {
	private: 
		Node<T>* root = nullptr;
		int depth = 0;
	
	public:
		Tree() {}
		Tree(Node<T>* _root) {
			root = _root;
		}

		void push(const T& value) {
			if(root == nullptr) {
				root = new Node(value);
			} else {
				root->push(value);
			}
		}

		void balance() {
			// Follow the path with max height 3 levels to find rotation
			char route[3] = { 'N' , 'N', 'N' }; 
			// std::cout << "Checking balance for " << std::endl;
			root -> printNode();
			// std::cout << std::endl;
			Node<T>* selected = root;
			for (int i = 0; i < 3; i++)
			{
				if(selected->left == nullptr || selected->right->height  > selected->left->height) {
					route[i] = 'R';
					selected = root->right;
				}
				if(selected->right == nullptr || selected->left->height  > selected->right->height) {
					route[i] = 'L';
					selected = root->left;
				}
				// std::cout << "Determining imbalance: Level " << i << " is " << route[i] << std::endl;
			}

			std::cout << "Detected imbalance" << std::endl;
			for (int j = 0; j < 3; j++)
			{
				std::cout << route[j];
			}
			std::cout << std::endl;
		}

};

#endif