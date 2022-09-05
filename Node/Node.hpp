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

		int leftHeight = -1;
		int rightHeight = -1;

		std::cout << "----------------" << std::endl;
		std::cout << "Data: " << data << std::endl;
		std::cout << "Left is null: " << left << std::endl;
		std::cout << "Right is null: " << right << std::endl;

		if(left == nullptr && right == nullptr) {
			height = 0;
			std::cout << "New height: " << height << std::endl;
			return;
		}

		if(left != nullptr) {
			leftHeight = left->height;
		}
		if(right != nullptr) {
			rightHeight = right->height;
		}

		int maxHeight = leftHeight > rightHeight ? leftHeight : rightHeight;
		height = maxHeight + 1;
		int balance = leftHeight - rightHeight;


		std::cout << "New height: " << height << std::endl;
		std::cout << "Balance: " << balance << std::endl;

		if(balance > 1 || balance < -1) {
			std::cout << data << " requires balancing" << std::endl;
			Tree t(this);
			t.balance();
		}
			
	}

	void printNode() {
		std::cout << "Data: " << data << std::endl;
		std::cout << "Height: " << height << std::endl;
		std::cout << "Left: " << left << std::endl;
		std::cout << "Right: " << right << std::endl;
	}

};

#endif