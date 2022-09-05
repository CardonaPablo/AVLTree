#ifndef _NODE_HPP_
#define _NODE_HPP_

#include <iostream>

template <typename T> 
class Tree;

template <typename T> 
class Node {

private:
	T data;
public:
	Node* left = nullptr;
	Node* right = nullptr;
	int height = 0;

	Node() {}
	Node(T _data) {
		data = _data;
	}

	const T& getData() {
		return data;
	}

	void setData(T _data) {
		data = _data;
	}

	void push(const T& value) {
		if(value > data) {
			if(right == nullptr) {
				right = new Node(value);
				std::cout << "PUSH R: " << value << std::endl;
			} else {
				right->push(value);
			}
		} else {
			if(left == nullptr) {
				left = new Node(value);
				std::cout << "PUSH L: " << value << std::endl;
			} else {
				left->push(value);
			}
		}
		std::cout << "Updating height" << std::endl;
		updateHeight();
	}
	
	void postOrder() {
		if(left != nullptr) 
			left->postOrder();
		if(right != nullptr)
			right->postOrder();
		printNode();
	}

	void inOrder() {
		if(left != nullptr) 
			left->inOrder();
		printNode();
		if(right != nullptr)
			right->inOrder();
	}

	void preOrder() {
		printNode();
		if(left != nullptr) 
			left->preOrder();
		if(right != nullptr)
			right->preOrder();
	}

	void updateHeight() {

		int leftHeight = 0;
		int rightHeight = 0;

		std::cout << "----------------" << std::endl;
		std::cout << "Data: " << data << std::endl;
		std::cout << "Left is null: " << left << std::endl;
		std::cout << "Right is null: " << right << std::endl;

		if(left == nullptr && right == nullptr) {
			height = 0;
			std::cout << "Height: " << height << std::endl;
			return;
		}

		if(left != nullptr) {
			leftHeight = left->height;
			left = left->checkBalanceFactor(); 
			std::cout << "Left height: " << leftHeight << std::endl;
		}
		if(right != nullptr) {
			rightHeight = right->height;
			right = right->checkBalanceFactor(); 
			std::cout << "Right height: " << rightHeight << std::endl;
		}

		int maxHeight = leftHeight > rightHeight ? leftHeight : rightHeight;
		height = maxHeight + 1;

		std::cout << "New height: " << height << std::endl;

	}

	Node<T>* checkBalanceFactor() {

		std::cout << "Checking sub node:" << this->data << std::endl;
		std::cout << "Left:" << left << std::endl;
		// left->printNode();
		std::cout << "Right:" << right << std::endl;
		// right->printNode();
		int leftHeight = 0;
		int rightHeight = 0;
		if(left != nullptr)
			leftHeight = left->height + 1;
		if(right != nullptr)
			rightHeight = right->height + 1;
		std::cout << "Left height:" << leftHeight << std::endl;
		std::cout << "Right height:" << rightHeight << std::endl;
		int balance = leftHeight - rightHeight;
		std::cout << "Balance: " << balance << std::endl;
		if(balance > 1 || balance < -1) {
			std::cout << data << " requires balancing" << std::endl;
			Tree t(this);
			return t.balance();
		}
		return this;
	}

	void printNode() {
		std::cout << "Data: " << data << std::endl;
		std::cout << "Height: " << height << std::endl;
		std::cout << "Left: " << left << std::endl;
		std::cout << "Right: " << right << std::endl;
	}

};

#endif