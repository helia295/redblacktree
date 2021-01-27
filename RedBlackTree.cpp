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
	result += ToInfixString((node->left));
	result += " " + getColorNode(node) + to_string(node->data) + " ";
	result += ToInfixString(node->right);
		
	return result;
}


string RedBlackTree::ToPrefixString(RBTNode* node) const {
	
	string result;
	
	if (node == nullptr){
		return result;
	} 
	result += " " + getColorNode(node) + to_string(node->data) + " ";
	
	result += ToPrefixString((node->left));
	
	result += ToPrefixString(node->right);
		
	return result;
	
}


string RedBlackTree::ToPostfixString(RBTNode* node) const {
	
	string result;
	
	if (node == nullptr){
		return result;
	}
	
	result += ToPostfixString((node->left));
	
	result += ToPostfixString(node->right);
	
	result += " " + getColorNode(node) + to_string(node->data) + " ";
		
	return result;
	
}



void RedBlackTree::rotateRight(RBTNode* &root, RBTNode* &aNode) {
	
	/*rotate on 7 in the video L6 part 1's example at 10:06. tree:
			10
		7		15
	  5   8
	2   6
	*/
	
	//first, leftnode = 5, aNode = 7
	RBTNode* leftNode = aNode->left;
	
	//	5				6
	aNode->left = leftNode->right;
	
	//		6
	if (aNode->left != nullptr) { 	//if it's Null we dont have to do anything
		//		6's parent		7
		aNode->left->parent = aNode;
		
	}
	//		5's parent 		10
	leftNode->parent = aNode->parent;
	
	//		7's parent (== 10)
	if (aNode->parent == nullptr) {
		
		root = leftNode; //let say, in case 7 is the root and we rotate right so now 5 is the root
	
	//			7		10 's left (== 7)	
	} else if (aNode == aNode->parent->left) {
	//		10's left			5
		aNode->parent->left = leftNode;
		
	} else {
		
		aNode->parent->right = leftNode;
	}
	// 5's right 		7
	leftNode->right = aNode;
	
	// 7's parent 		5
	aNode->parent = leftNode;
	
}



//Reverse left and right with function rotateRight
void RedBlackTree::rotateLeft(RBTNode* &root, RBTNode* &aNode) {
	
	RBTNode* rightNode = aNode->right;
	
	aNode->right = rightNode->left;
	
	if (aNode->right != nullptr) {
		
		aNode->right->parent = aNode;
	}
	rightNode->parent = aNode->parent;
	
	if (aNode->parent == nullptr) {
		
		root = rightNode;
		
	} else if (aNode == aNode->parent->left) {
		
		aNode->parent->left = rightNode;
		
	} else {
		
		aNode->parent->right = rightNode;
	}
	
	rightNode->left = aNode;
	aNode->parent = rightNode;
	
	
}



RBTNode* RedBlackTree::BSTInsert(RBTNode* root, RBTNode* newNode) {
	
	//if tree is empty, return new node
	if (root == nullptr) {
		
		return newNode;
	}
	//else move down the tree (works the same as BST)
	if (newNode->data < root->data) {
		
		root->left = BSTInsert(root->left, newNode);
		root->left->parent = root;
		
	} else if (newNode->data > root->data) {
		
		root->right = BSTInsert(root->right, newNode);
		root->right->parent = root;
		
	} else { //if new node = root
		
		throw invalid_argument("Duplicate arguments not allowed: " + to_string(newNode->data));
	}
	
	return root; //this is the root we added the new node to (the parent node)
}



void RedBlackTree::Insert(int num) {
	
	RBTNode* newNode = new RBTNode(num);
		
	root = BSTInsert(this->root, newNode);	
	
	//RBTconditions(root, newNode);
	RBTNode *parentNode = nullptr;
	RBTNode *grandPaNode = nullptr;
	
	//step 3 said if new node's parent is Black (1) then we don't have to do anything
	//so this while loop happens only when parent is Red but the new node is not Black
	//and newNode is not the root ---> we now pass step 3.
	while ((newNode != root) && (newNode->color != 1) && (newNode->parent->color == 0)) {
		
		parentNode = newNode->parent;
		grandPaNode = newNode->parent->parent;
		
		//step 4: check uncle's color, if Black or Null then Rotate and Recolor, if Red then Recolor.
		if (parentNode == grandPaNode->left) {
			
			RBTNode *uncleNode = grandPaNode->right;
			
			//If uncle is RED ----step6
			if ((uncleNode != nullptr) && (uncleNode->color == 0)) {
				
				grandPaNode->color = 0;
				parentNode->color = 1;
				uncleNode->color = 1;
				newNode = grandPaNode;
				
			} else {  //if uncle is Black or Null ---step 5
				
				if (newNode == parentNode->right) {
					
					newNode = parentNode;
					rotateLeft(root, newNode);
					
				} else { 	//if (newNode == parentNode->left) 
					
					newNode = parentNode;
					int tmp = parentNode->color;
					parentNode->color = grandPaNode->color;
					grandPaNode->color = tmp;
					
					rotateRight(root, grandPaNode);
	
				}
			}
		} else { 	//if( parentNode == grandPaNode->right)
			
			RBTNode *uncleNode = grandPaNode->left;
			
			//If uncle is RED ---step6
			if ((uncleNode != nullptr) && (uncleNode->color == 0)) {
				
				grandPaNode->color = 0;
				parentNode->color = 1;
				uncleNode->color = 1;
				newNode = grandPaNode;
				
			} else {  //if uncle is Black or Null --step 5
				
				if (newNode == parentNode->left) {
					
					newNode = parentNode;
					rotateRight(root, newNode);
					
				} else { 	//if (newNode == parentNode->right) 
					
					newNode = parentNode;
					
					int tmp = parentNode->color;
					parentNode->color = grandPaNode->color;
					grandPaNode->color = tmp;
					
					rotateLeft(root, grandPaNode);

				}
			}
		}
	}
	root->color = 1;

}


/*
bool RedBlackTree::Contains(int num) {
	
	RBTNode* tmp = new RBTNode(num);
	
	if (num < (root->data)) {
		
		while (
	}
	
}



RedBlackTree::RedBlackTree(const RedBlackTree& rbt){
	
	rbt = this;
}
*/

