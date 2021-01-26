#define COLOR_RED 0
#define COLOR_BLACK 1
#include <iostream>

using namespace std;

struct RBTNode {
	RBTNode* left = nullptr;
	RBTNode* right = nullptr;
	int data;
	int color;
};


class RedBlackTree {
	
	public:
		RedBlackTree(){ root = nullptr; };
		RedBlackTree(const RedBlackTree& rbt);
	//	void Insert(int num);
	//	bool Contains(int num);
	//	int GetMin();
	//	int GetMax();
	//	int Size();
		// ToString variants
		string ToInfixString() const { return ToInfixString(root); };
		string ToInfixString(RBTNode* node);
	//	string ToPrefixString() const { return ToPrefixString(root); };
	//	string ToPostfixString() const { return ToPostfixString(root); };
	private:
		//string ToInfixString(RBTNode* node);
		unsigned long long int numItems;
		RBTNode* root;
	
};
