#define COLOR_RED 0

#include <iostream>

class RedBlackTree {
	
	public:
		RedBlackTree() {};
		RedBlackTree(const RedBlackTree& rbt);
		
		void Insert();
		
	
	private:
	
		RBTNode* root;
		unsigned long long int numItems;
	
	
}
