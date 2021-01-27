#define COLOR_RED 0
#define COLOR_BLACK 1

#include <iostream>

using namespace std;

struct RBTNode {
	RBTNode* left;
	RBTNode* right;
	RBTNode* parent;
	int data;
	int color;
	
	//constructor
	RBTNode(int data) {
		this->data = data;
		left = right = parent = nullptr;
		this->color = COLOR_RED;
	};
	
	void operator=(const RBTNode* other) {
		data = other->data;
		color = other->color;
		left = other->left;
		right = other->right;
		parent = other->parent;
	};
};


class RedBlackTree {
	
	public:
		RedBlackTree() {
			root = nullptr;
			numItems = 0;
		};
		
		RedBlackTree(const RedBlackTree& rbt);
		/*void operator=(RedBlackTree* other) const {
			other->root = root;
			other->numItems = numItems;
		};*/
		
		~RedBlackTree();
		
		void Insert(int num);
		
		bool Contains(int num);
		int GetMin();
		int GetMax();
		int Size();
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
		
		void rotateLeft(RBTNode* &root, RBTNode* &newNode);
		void rotateRight(RBTNode* &root, RBTNode* &newNode);
		RBTNode* BSTInsert(RBTNode* root, RBTNode* newNode);
		
		RBTNode* deepcopy(RBTNode* nd);
		void deleteRBT(RBTNode* curr);
		
};
