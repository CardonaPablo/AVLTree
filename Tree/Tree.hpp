#ifndef TREE_H
#define TREE_H

template <typename T> 
class Node;

#include <iostream>
#include <cstring>

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
				std::cout << "Checking balance factor of root";
				root = root->checkBalanceFactor();
			}
		}

		Node<T>* balance() {
			// Follow the path with max height 3 levels to find rotation
			char route[2] = { 'N' , 'N' }; 
			std::cout << "Checking balance for " << std::endl;
			root -> printNode();
			std::cout << std::endl;
			drawTree();
			Node<T>* selected = root;
			for (int i = 0; i < 2; i++)
			{
				int lHeight = 0;
				int rHeight = 0;
				if(selected->left != nullptr)
					lHeight = selected->left->height;
				if(selected->right != nullptr)
					rHeight = selected->right->height;

				if(selected->left == nullptr || rHeight  > lHeight) {
					route[i] = 'R';
					selected = root->right;
				} else if(selected->right == nullptr || lHeight  > rHeight) {
					route[i] = 'L';
					selected = root->left;
				} else
					break;
			}

			std::cout << "Detected " << route << " imbalance" << std::endl;
			if(strcmp(route, "LL") == 0)
				rotationLL();
			else if(strcmp(route, "RR") == 0)
				rotationRR();
			else if(strcmp(route, "LR") == 0)
				rotationLR();
			else if(strcmp(route, "RL") == 0)
				rotationRL();
			
			drawTree();
			return root;
		}

		void drawTree() {
			std::cout << "\t\t" << root->getData() << std::endl;
			if(root->left != nullptr)
				std::cout << "\t" << root->left->getData();
			else
				std::cout  << "\t" << "NULL";

			std::cout << "\t\t";

			if(root->right != nullptr)
				std::cout << root->right->getData() << std::endl;
			else
				std::cout << "NULL" << std::endl;

			// Draw left children
			if(root->left != nullptr && root->left->left != nullptr)
				std::cout << root->left->left->getData() << "\t";
			else
				std::cout << "NULL\t";

			if(root->left != nullptr && root->left->right != nullptr)
				std::cout << root->left->right->getData() << "\t\t";
			else
				std::cout << "NULL\t\t";

			// Draw right children
			if(root->right != nullptr && root->right->left != nullptr)
				std::cout << root->right->left->getData() << "\t";
			else
				std::cout << "NULL" << "\t";

			if(root->right != nullptr && root->right->right != nullptr)
				std::cout << root->right->right->getData();
			else
				std::cout << "NULL";
			
			std::cout << std::endl << "---------------------------------------------" << std::endl;
		}



		void rotationLL() {
			std::cout << "Performing LL rotation" << std::endl;
			// Guardar raíz→L→ R 
			Node<T>* buffer = root->left->right;
			// Copiar el puntero de raíz hacia la raíz→L→R
			root->left->right= root;
			// Hacer raíz→L la nueva raíz
			root = root->left;
			// Reemplazar raíz→R→L con el valor guardado en (1)
			root->right->left = buffer;
		}

		void rotationRR() {
			std::cout << "Performing RR rotation" << std::endl;
			// Guardar raíz→L→ R 
			Node<T>* buffer = root->right->left;
			// Copiar el puntero de raíz hacia la raíz→L→R
			root->right->left= root;
			// Hacer raíz→L la nueva raíz
			root = root->right;
			// Reemplazar raíz→R→L con el valor guardado en (1)
			root->left->right = buffer;
		}

		void rotationLR() {
			std::cout << "Performing LR rotation" << std::endl;
			// 1. Raíz→L→R debe ser raíz→L
			Node<T>* buffer = root->left;
			Node<T>* buffer2 = root->left->right->left;
			root->left = root->left->right;

			// 2. Raíz →L debe ser raíz→L→L
			buffer->right = buffer2;
			root->left->left = buffer;
			// 3. Se convierte en una rotación LL
			drawTree();
			std::cout << "Below 20" << std::endl;
			buffer->printNode();
			rotationLL();
		}
		void rotationRL() {
			std::cout << "Performing RL rotation" << std::endl;
			// 1. Raíz→L→R debe ser raíz→L
			Node<T>* buffer = root->right;
			Node<T>* buffer2 = root->right->left->right;
			root->right= root->right->left;

			// 2. Raíz →L debe ser raíz→L→L
			buffer->left = buffer2;
			root->right->right= buffer;
			// 3. Se convierte en una rotación RR
			drawTree();
			// std::cout << "Below 20" << std::endl;
			// buffer->printNode();
			rotationRR();
		}
		
};

#endif