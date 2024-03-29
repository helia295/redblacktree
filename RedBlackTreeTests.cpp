
#include <iostream>
#include <cassert>
#include <random>
#include "RedBlackTree.h"

using namespace std;

void TestSimpleConstructor(){
	cout << "Testing Simple Constructor... " << endl;
	RedBlackTree rbt = RedBlackTree();
	//cout << "empty r-b-tree: " << rbt->ToInfixString() << endl;
	assert(rbt.ToInfixString() == "");
	
	cout << "PASSED!"<< endl << endl;
}


void TestInsertFirstNode(){
	cout << "Testing Insert One Node..." << endl;
	RedBlackTree rbt = RedBlackTree();
	rbt.Insert(30);
	//cout << "rbt: " << rbt.ToPrefixString() << endl;
	assert(rbt.ToPrefixString() == " B30 ");

	cout << "PASSED!" << endl << endl;
}


void TestInsertSecondNode(){
	cout << "Testing Insert Second Node..." << endl;
	RedBlackTree *rbt = new RedBlackTree();
	rbt->Insert(30); // leak here
	rbt->Insert(15);
	//cout << "rbt: " << rbt->ToPrefixString() << endl;
	assert(rbt->ToPrefixString() == " B30  R15 ");
	delete rbt;
	
	rbt = new RedBlackTree();
	rbt->Insert(30);
	rbt->Insert(45);
	assert(rbt->ToPrefixString() == " B30  R45 ");	
	delete rbt;

	cout << "PASSED!" << endl << endl;
}


void TestInsertThirdNode(){
	cout << "Testing Insert Third Node..." << endl;
	RedBlackTree *rbt = new RedBlackTree();
	rbt->Insert(30);
	rbt->Insert(15);
	rbt->Insert(10); // Left Left
	//cout << "rbt: "  << rbt->ToPrefixString() << endl;
	assert(rbt->ToPrefixString() == " B15  R10  R30 ");
	delete rbt;
	
	rbt = new RedBlackTree(); 
	rbt->Insert(30);
	rbt->Insert(15);
	rbt->Insert(25); // Right Left
	assert(rbt->ToPrefixString() == " B25  R15  R30 ");
	delete rbt;
	
	rbt = new RedBlackTree();
	rbt->Insert(30);
	rbt->Insert(15);
	rbt->Insert(45); // Easy case
	assert(rbt->ToPrefixString() == " B30  R15  R45 ");
	delete rbt;
	
	// more tests go here
	// consider some symmetry!
	
	cout << "TESTS MISSING" << endl << endl;
	cout << "PASSED!" << endl << endl;
}

void TestInsertFourthNode(){
	cout << "Testing Insert Fourth Node..." << endl;

	cout << "TESTS MISSING" << endl << endl;
	
	cout << "PASSED!" << endl << endl;
}

void TestInsertFifthNode(){
	cout << "Testing Insert Fifth Node..." << endl;
	RedBlackTree *rbt = new RedBlackTree();
	rbt->Insert(30);
	rbt->Insert(15);
	rbt->Insert(45);
	rbt->Insert(10);
	rbt->Insert(25);
	//cout << "result: "  << rbt->ToPrefixString() << endl;
	assert(rbt->ToPrefixString() == " B30  B15  R10  R25  B45 ");
	delete rbt;
	
	cout << "TESTS MISSING" << endl << endl;
	
	cout << "PASSED!" << endl << endl;
}


void TestToStrings(){
	cout << "Testing ToString Methods..." << endl;

	RedBlackTree rbt = RedBlackTree();
	rbt.Insert(12);
	rbt.Insert(11);
	rbt.Insert(15);
	rbt.Insert(5);
	rbt.Insert(13);
	rbt.Insert(7);

	assert(rbt.ToPrefixString() == " B12  B7  R5  R11  B15  R13 ");
	assert(rbt.ToInfixString() == " R5  B7  R11  B12  R13  B15 ");
	assert(rbt.ToPostfixString() == " R5  R11  B7  R13  B15  B12 ");

	cout << "PASSED!" << endl << endl;
}

void TestInsertRandomTests(){
	cout << "Testing Random Insert Stuff..." << endl;
	cout << "\t This test passes if it doesn't crash and valgrind reports no issues" << endl;
	RedBlackTree *rbt = new RedBlackTree();
	rbt->Insert(15);
	rbt->Insert(13);
	rbt->Insert(20);
	rbt->Insert(12);
	
	try {
		
		rbt->Insert(15);
		assert(false);
		
	} catch( const invalid_argument& e ) {
		//cout << e.what() << endl;
	}
	
	cout << endl;
	//cout << "tree: " << rbt->ToInfixString() << endl;
	delete rbt;
	
	
	// probably should have a delete or something here
	rbt = new RedBlackTree();
	//cout << endl << "NEW TREE" << endl;
	rbt->Insert(12);
	//cout << "tree: "  << rbt->ToInfixString() << endl;
	rbt->Insert(11);
	//cout << "tree: "  << rbt->ToInfixString() << endl;
	rbt->Insert(15);
	//cout << "tree: "  << rbt->ToInfixString() << endl;
	
	try {
		
		rbt->Insert(15);
		assert(false);
		
	} catch( const invalid_argument& e ) {
		//cout << e.what() << endl;
	}
	
	rbt->Insert(5);
	//cout << "tree: "  << rbt->ToInfixString() << endl;
	rbt->Insert(13);
	//cout << "tree: "  << rbt->ToInfixString() << endl;
	
	try {
		
		rbt->Insert(12);
		assert(false);
		
	} catch( const invalid_argument& e ) {
		//cout << e.what() << endl;
	}
	
	rbt->Insert(7);
	//cout << "tree: "  << rbt->ToInfixString() << endl;
	delete rbt;
	
	
	rbt = new RedBlackTree();
	//cout << endl << "NEW TREE" << endl;
	rbt->Insert(12);
	//cout << "tree: "  << rbt->ToPrefixString() << endl;
	rbt->Insert(10);
	//cout << "tree: "  << rbt->ToPrefixString() << endl;
	rbt->Insert(8);
	//cout << "tree: "  << rbt->ToPrefixString() << endl;
	delete rbt;
	
	cout << "PASSED!" << endl << endl;
}

void TestCopyConstructor(){
	cout << "Testing Copy Constructor..." << endl;

	RedBlackTree rbt1 = RedBlackTree();
	rbt1.Insert(11);
	rbt1.Insert(23);
	rbt1.Insert(9);
	rbt1.Insert(52);
	rbt1.Insert(31);
	rbt1.Insert(4);

	assert(rbt1.ToPrefixString() == " B11  B9  R4  B31  R23  R52 ");

	RedBlackTree rbt2 = RedBlackTree(rbt1);

	assert(rbt2.ToPrefixString() == rbt1.ToPrefixString());
	
	//cout << rbt2.ToPrefixString() << endl;
	//cout << rbt1.ToPrefixString() << endl;
	
	rbt1.Insert(200);
	//cout << rbt2.ToPrefixString() << endl;
	//cout << rbt1.ToPrefixString() << endl;
	assert(rbt2.ToPrefixString() != rbt1.ToPrefixString());
	
	rbt2.Insert(200);
	assert(rbt2.ToPrefixString() == rbt1.ToPrefixString());

	cout << "PASSED!" << endl << endl;
}






void TestContains(){
	cout << "Testing Contains..." << endl;
	RedBlackTree *rbt = new RedBlackTree();
	rbt->Insert(40);
	rbt->Insert(22);
	rbt->Insert(15);
	rbt->Insert(31);
	rbt->Insert(55);
	rbt->Insert(12);
	rbt->Insert(17);
	rbt->Insert(29);
	rbt->Insert(34);
	
	assert(!rbt->Contains(3));
	assert(rbt->Contains(34));
	assert(rbt->Contains(40));
	assert(rbt->Contains(31));
	assert(rbt->Contains(22));
	assert(rbt->Contains(17));
	assert(!rbt->Contains(349));
	delete rbt;
	cout << "PASSED!" << endl << endl;
}




void TestGetMinimumMaximum(){
	cout << "Testing Get Minimum and Get Maximum..." << endl;
	
	RedBlackTree *rbt = new RedBlackTree();
	
	try {
		
		rbt->GetMax();
		assert(false);
		
	} catch( const invalid_argument& e ) {
		//cout << e.what() << endl;
	}
	
	try {
		
		rbt->GetMin();
		assert(false);
		
	} catch( const invalid_argument& e ) {
		//cout << e.what() << endl;
	}
	
	rbt->Insert(40);
	rbt->Insert(22);
	rbt->Insert(32);
	rbt->Insert(11);
	rbt->Insert(15);
	rbt->Insert(31);
	
	//cout << "Max: " << rbt->GetMax() << endl;
	assert(rbt->GetMax() == 40);
	//cout << "Min: " << rbt->GetMin() << endl;
	assert(rbt->GetMin() == 11);
	
	rbt->Insert(155);
	rbt->Insert(41);
	rbt->Insert(2);
	rbt->Insert(17);
	rbt->Insert(29);
	rbt->Insert(34);
	rbt->Insert(45);
	
	//cout << "Max: " << rbt->GetMax() << endl;
	assert(rbt->GetMax() == 155);
	//cout << "Min: " << rbt->GetMin() << endl;
	assert(rbt->GetMin() == 2);
	
	delete rbt;
	cout << "PASSED!" << endl << endl;
}


void TestSize(){
	cout << "Testing get Size..." << endl;
	
	RedBlackTree *rbt = new RedBlackTree();
	
	//cout << "Size: " << rbt->Size() << endl;
	assert(rbt->Size() == 0);
	
	rbt->Insert(40);
	rbt->Insert(22);
	rbt->Insert(15);
	rbt->Insert(31);
	
	//cout << "Size: " << rbt->Size() << endl;
	assert(rbt->Size() == 4);
	
	rbt->Insert(55);
	rbt->Insert(12);
	rbt->Insert(17);
	rbt->Insert(29);
	rbt->Insert(112);
	rbt->Insert(34);
	
	//cout << "Size: " << rbt->Size() << endl;
	assert(rbt->Size() == 10);
	
	delete rbt;
	cout << "PASSED!" << endl << endl;
}


void PrivateTests() { 
	
	cout << "Testing left rotate..." << endl;
	
	RedBlackTree *rbt = new RedBlackTree();
	
	rbt->Insert(10);
	rbt->Insert(7);
	rbt->Insert(15);
	rbt->Insert(5);
	rbt->Insert(8);
	rbt->Insert(2);
	rbt->Insert(6);
	
	RBTNode* toRotate = rbt->findNode(7);
	
	//cout << "rbt: " << rbt->ToPrefixString() << endl;
	assert(rbt->ToPrefixString() == " B10  R7  B5  R2  R6  B8  B15 ");
	
	rbt->PrivateTests(toRotate);
	
	//cout << "rbt: " << rbt->ToPrefixString() << endl;
	assert(rbt->ToPrefixString() == " B10  B5  R2  R7  R6  B8  B15 ");
	
	delete rbt;
	
	cout << "PASSED!" << endl << endl;
	
}



int main(){

	
	TestSimpleConstructor();
	
	TestInsertFirstNode();
	TestInsertSecondNode();
	TestInsertThirdNode();
	TestInsertFourthNode();
	TestInsertFifthNode();

	TestToStrings();
	TestInsertRandomTests();

	TestCopyConstructor();

	TestContains();
	TestGetMinimumMaximum();
	TestSize();
	
	PrivateTests();

	
	cout << "ALL TESTS PASSED!!" << endl;
	return 0;
}
