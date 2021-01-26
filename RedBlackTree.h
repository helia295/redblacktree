#define COLOR_RED 0
#define COLOR_BLACK 1
#include <iostream>

using namespace std;

struct RBTNode {
	int data;
	unsigned short int color;
	RBTNode* left = nullptr;
	RBTNode* right = nullptr;
	RBTNode* parent = nullptr;
	// Constructor
	RBTNode(int data){
		this->data = data;
		left = right = parent = nullptr;
		this->color = COLOR_BLACK;
	}
};


class RedBlackTree {
	
	public:
		RedBlackTree();
		RedBlackTree(const RedBlackTree& rbt);
		void Insert(int num);
		void BSTInsert (RBTNode* rn);
	//	bool Contains(int num);
	//	int GetMin();
	//	int GetMax();
	//	int Size();
		bool isLeaf(RBTNode* node) const;
		bool hasLeft(RBTNode* node) const;
		bool hasRight(RBTNode* node) const;
		RBTNode* ParentOf(RBTNode* node);
		string getColor(RBTNode* node) const;
		// ToString variants
		string ToInfixString() const { return ToInfixString(root); };
		string ToPrefixString() const { return ToPrefixString(root); };

	//	string ToPostfixString() const { return ToPostfixString(root); };
	private:
		string ToInfixString (RBTNode* node) const;
		string ToPrefixString (RBTNode* node) const;
		unsigned long long int numItems;
		RBTNode* root;
};
