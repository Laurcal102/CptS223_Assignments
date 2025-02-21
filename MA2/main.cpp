#include <iostream>
#include "BST.h" 

int main(){

	/* MA TODO: Implement */
	/* Create a BST string tree (bst_test) ; add the following string values to the bst_test in order: "C", "p", "t", "s", "2", "3" , "B", "S", "T"*/
	BST<string> bst_test;
	bst_test.add("C");
	bst_test.add("p");
	bst_test.add("t");
	bst_test.add("s");
	bst_test.add("2");
	bst_test.add("3");
	bst_test.add("B");
	bst_test.add("S");
	bst_test.add("T");

	/* MA TODO: Implement */
	// Test1: Test printLevelOrder()
	/* Print the tree you created using
	    a. In-order print
	    a. Level-order print
	    a. Post-order print
	    a. Pre-order print */
	cout << "In order print:" << endl;
	bst_test.printInOrder();
	cout << endl;
	cout << "Level order print:" << endl;
	bst_test.printLevelOrder();
	cout << endl;
	cout << "Post order print:" << endl;
	bst_test.printPostOrder();
	cout << endl;
	cout << "Pre order print:" << endl;
	bst_test.printPreOrder();
	cout << endl;

	/* MA TODO: Implement */
	// Test2: Test copy constructor -1
	/* Create a new BST tree (bst_copy1) ; initialize bst_copy1 with 'bst_test's data, using the copy constructor */
	BST<string> bst_copy1 = bst_test;
	/* Test condition: Check if the size of bst_copy1 is same as bst_test; and  bst_copy1 contains the values "B", "S", "T" 
	    * if so, print the mesaage: "Copy constructor test-1 passed!"";
		* else *print the message: "Copy constructor test-1 failed!"" and print both bst_test and bst_copy1 using level order print.*/
	if(bst_test.size() == bst_copy1.size() && bst_copy1.getNode("B") && bst_copy1.getNode("S") && bst_copy1.getNode("T"))
	{
		cout << "Copy constructor test-1 passed" << endl;
	}
	else{
		cout << "Copy constructor test-1 failed" << endl;
	}

	/* MA TODO: Implement */
	// Test3: Test copy constructor - 2
	/* Update one of the strings in bst_copy1 tree using the following statement:  */
	   bst_copy1.getNode("B")->setValue("A");
	/* Assuming copy constructor does a deep copy, the above statement should update bst_copy1 only, and not bst_test. */
	/* Test condition: 
	    * if bst_test contains "B" and it doesn't contain "A", test passes. Print the message: "Copy constructor test-2 passed!"";
		* else *print the message: "Copy constructor test-2 failed!"" and print bst_test using level order print.*/
	if(bst_test.getNode("A")){
		cout << "Copy constructor test-2 failed" << endl;
	}
	else{
		cout << "Copy constructor test-2 passed" << endl;
	}
	
	/* MA TODO: Implement */
	// Test4: Test copy assignment
	/* Create a new BST tree (bst_copy2) ; initialize bst_copy2 with 'bst_test's data, using the copy assignment operator. */
	BST<string> bst_copy2;
	bst_copy2 = bst_test;
	/* Test condition: Check if the size of bst_copy2 is same as bst_test and  bst_copy2 contains the values "B", "S", "T" 
	    * if so, print the mesaage: "Copy assignment operator test passed!"";
		* else *print the message: "Copy assignment operator test failed!"" and print both bst_test and bst_copy2 using level order print.*/
	if(bst_test.size() == bst_copy2.size() && bst_copy2.getNode("B") && bst_copy2.getNode("S") && bst_copy2.getNode("T"))
	{
		cout << "Copy assignment operator test passed" << endl;
	}
	else{
		cout << "Copy assignment operator test failed" << endl;
		bst_test.printLevelOrder();
		bst_copy2.printLevelOrder();
	}

	/* MA TODO: Implement */
	// Test5: Test move constructor
	/* Create a new BST tree (bst_move1) ; initialize bst_move1 with 'bst_test's data, using the move constructor */
	BST<string> bst_move1 = std::move(bst_test);
	/* Test condition: Check if the size of bst_move1 is 9 and  bst_move1 contains the values "B", "S", "T", and bst_test is empty (use the empty() function of BST to check if bst_test is empty.).  
	    * if so, print the mesaage: "Move constructor test passed!"";
		* else *print the message: "Move constructor test failed!"" and print bst_move1 using level order print.*/
	if(bst_move1.size() == 9 && bst_move1.getNode("B") && bst_move1.getNode("S") && bst_move1.getNode("T") && bst_test.empty()){
		cout << "Move constructor test passed!" << endl;
	}
	else{
		cout << "Move constructor test failed!" << endl;
		bst_move1.printLevelOrder();
	}



	/* MA TODO: Implement */
	// Test6: Test move assignment 
	/* Create a new BST tree (bst_move2) ; initialize bst_move2 with rvalue BST<string>({"B","S","T"}), using the move assignment operator */
	BST<string> bst_move2 = BST<string>{"B","S","T"};
	/* Test condition: Check if the size of bst_move2 is 3 and  bst_move2 contains the values "B", "S", "T". 
	    * if so, print the mesaage: "Move assignment operator test passed!"";
		* else *print the message: "Move assignment operator test failed!"" and print  bst_move2  using level order print.*/
	if(bst_move2.size() == 3 && bst_move2.getNode("B") && bst_move2.getNode("S") && bst_move2.getNode("T")){
		cout << "Move assignment operator test passed!" << endl;
	}
	else{
		cout << "Move assignment operator test failed!" << endl;
		bst_move2.printLevelOrder();
	}



	return 0;
}