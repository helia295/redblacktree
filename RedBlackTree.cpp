#include "RedBlackTree.h"
#include <iostream>
#include <sstream>

using namespace std;

RedBlackTree::RedBlackTree(){
	root = nullptr;
}

string RedBlackTree::getColor(RBTNode* node) const{
	if (node->color == COLOR_RED){
		return "R";
	}
	return "B";
}

RBTNode* RedBlackTree::ParentOf(RBTNode* rn){
	RBTNode* p = root;
	if (isLeaf(p)){
		return p;
	}
	else if (hasLeft(p) && p->data > rn->data){
		p = p->left;
		if (p->left->data == rn->data){
			return p;
		}
	}
	else if (hasRight(p) && p->data < rn->data){
		p = p->right;
		if (p->right->data == rn->data){
			return p;
		}
	}
	else if (hasLeft(p) && hasRight(p)){
		if (p->data < rn->data){
			p = p->right;
		} else {
			p = p->left;
		}
	}
	return p;
}

void RedBlackTree::BSTInsert(RBTNode* rn){
	RBTNode* tmp = root;
	RBTNode* parent = nullptr;
	while (tmp != nullptr)
	{
		parent = tmp;
		if (rn->data < tmp->data)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}
	rn->parent = parent;
	if (rn->data < parent->data)
		parent->left = rn;
	else
		parent->right = rn;
}

void RedBlackTree::Insert(int num){
	RBTNode *n = new RBTNode(num);
	n->color = COLOR_RED;
	// Case 1: if tree is empty.
	if (root == nullptr){
		n->color = COLOR_BLACK;
		root = n;
	} else {
	// Case 2: if the node to be insert has black parent node.
		if (ParentOf(n)->color == COLOR_BLACK){
			BSTInsert(n);
		}

	}
/*	if (num->parent->color = COLOR_BLACK){
		
	{
		
	}*/
}

bool RedBlackTree::hasLeft(RBTNode* node) const{
	if (node->left != nullptr){
		return true;
	}
	return false;
}
bool RedBlackTree::hasRight(RBTNode* node) const{
	if (node->right != nullptr){
		return true;
	} 
	return false;
}

bool RedBlackTree::isLeaf(RBTNode* node) const{
	if (!hasLeft(node) && !hasRight(node)){
		return true;
	}
	return false;
}

string RedBlackTree::ToInfixString (RBTNode* node) const{
	stringstream ss;
	if (node == nullptr){
		ss << "";
	} else {
		ss << ToInfixString(node->left);
		ss << " " << getColor(node) << node->data << " ";
		ss << ToInfixString(node->right);
	}
	return ss.str();
}

string RedBlackTree::ToPrefixString (RBTNode* node) const{
	stringstream ss;
	if (node == nullptr){
		ss << "";
	} else {
		ss << " " << getColor(node) << node->data << " ";
		ss << ToPrefixString(node->left);
		ss << ToPrefixString(node->right);
	}
	return ss.str();
}
/*
RedBlackTree::RedBlackTree(const RedBlackTree& rbt){
	rbt.root = this->root;
	rbt.numItems = this->numItems;
}*/
