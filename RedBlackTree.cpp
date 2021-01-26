#include "RedBlackTree.h"
#include <iostream>
#include <sstream>

using namespace std;

const string RedBlackTree::ToInfixString(RBTNode* node){
	stringstream ss;
	if (node == nullptr){
		ss << "";
	} else {
		if (node->left != nullptr){
			ss << node->left->data << " ";
		}
		if (node->right != nullptr){
			ss << node->right->data << " ";
		}
	}
		
	return ss.str();
}
RedBlackTree::RedBlackTree(const RedBlackTree& rbt){
	rbt.root = this->root;
	rbt.numItems = this->numItems;
}
