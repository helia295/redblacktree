#include "RedBlackTree.h"
#include <iostream>
#include <sstream>

using namespace std;


string RedBlackTree::getColorNode(RBTNode* node) const {
	
	if (node->color == 0) {
		return "R";
	} else {
		return "B";
	}
}

string RedBlackTree::ToInfixString(RBTNode* node) const {
	
	string result;
	
	if (node == nullptr){
		return result;
	} 
	ToInfixString((node->left));
	result += " " + getColorNode(node) + to_string(node->data) + " ";
	ToInfixString(node->right);
		
	return result;
}


string RedBlackTree::ToPrefixString(RBTNode* node) const {
	
	string result;
	
	if (node == nullptr){
		return result;
	} 
	result += " " + getColorNode(node) + to_string(node->data) + " ";
	
	ToPrefixString((node->left));
	
	ToPrefixString(node->right);
		
	return result;
	
}


string RedBlackTree::ToPostfixString(RBTNode* node) const {
	
	string result;
	
	if (node == nullptr){
		return result;
	}
	
	ToPostfixString((node->left));
	
	ToPostfixString(node->right);
	
	result += " " + getColorNode(node) + to_string(node->data) + " ";
		
	return result;
	
}


RBTNode* RedBlackTree::InsertHelper(RBTNode* root, RBTNode* newNode) {
	
	//if tree is empty, return new node
	if (root == nullptr) {
		
		return newNode;
	}
	//else move down the tree (works the same as BST)
	if (newNode->data < root->data) {
		
		root->left = InsertHelper(root->left, newNode);
		root->left->parent = root;
		
	} else if (newNode->data > root->data) {
		
		root->right = InsertHelper(root->right, newNode);
		root->right->parent = root;
		
	} else { //if new node = root
		
		throw invalid_argument("Duplicate arguments not allowed: " + to_string(newNode->data));
	}
	
	return root; //this is the root we added the new node to (the parent node)
}



void RedBlackTree::Insert(int num) {
	
	RBTNode* newNode = new RBTNode(num);
	
	root = InsertHelper(root, newNode);
	
}

/*
RedBlackTree::RedBlackTree(const RedBlackTree& rbt){
	rbt.root = this->root;
	rbt.numItems = this->numItems;
}


void RedBlackTree::Insert(int num) {
	
	
	
}
*/
