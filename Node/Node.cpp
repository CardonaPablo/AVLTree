#include "Node.hpp"

// Node::Node(T _data) {
// 	data = _data;
// }

// Node<int>::Node() {

// }

// const T& Node::getData() {
// 	return data;
// }

// void setData(T _data) {
// 	data = _data;
// }

// void push(const T& value) {
// 	if(value > data) {
// 		if(right == nullptr) {
// 			right = new Node(value);
// 		} else {
// 			right->push(value);
// 		}
// 	} else {
// 		if(left == nullptr) {
// 			left = new Node(value);
// 		} else {
// 			left->push(value);
// 		}
// 	}
// }

// T postOrder() {
// 	if(left != nullptr) 
// 		std::cout <<	left->postOrder();
// 	if(right != nullptr)
// 		std::cout <<	right->postOrder();
// 	return data;
// }

// T inOrder() {
// 	if(left != nullptr) 
// 		std::cout <<	left->postOrder();
// 	return data;
// 	if(right != nullptr)
// 		std::cout <<	right->postOrder();
// }

// T preOrder() {
// 	if(right != nullptr)
// 		std::cout <<	right->postOrder();
// 	if(left != nullptr) 
// 		std::cout <<	left->postOrder();
// 	return data;
// }