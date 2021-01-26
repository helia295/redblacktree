#define COLOR_RED 0
#define COLOR_BLACK 1

#include <iostream>

using namespace std;

struct RBTNode {
	RBTNode* left = nullptr;
	RBTNode* right = nullptr;
	RBTNode* parent = nullptr;
	int data;
	int color;
	
	//constructor
	RBTNode(int data) {
		this->data = data;
		left = right = parent = nullptr;
		this->color = COLOR_BLACK;
	}
};


class RedBlackTree {
	
	public:
		RedBlackTree() {
			root = nullptr;
			numItems = 0;
		};
		RedBlackTree(const RedBlackTree& rbt);
		
		
		void Insert(int num);
		/*
		bool Contains(int num);
		int GetMin();
		int GetMax();
		int Size();*/
		// ToString variants
		string ToInfixString() const { return ToInfixString(root); };
		string ToPrefixString() const { return ToPrefixString(root); };
		string ToPostfixString() const { return ToPostfixString(root); };
	
	private:
	
		RBTNode* root;
		unsigned long long int numItems;
	
		string getColorNode(RBTNode* node) const;
		string ToInfixString(RBTNode* node) const;
		string ToPrefixString(RBTNode* node) const;
		string ToPostfixString(RBTNode* node) const;
		
		RBTNode* InsertHelper(RBTNode* root, RBTNode* newNode);
		
};
