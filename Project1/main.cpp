// University of Arkansas at Little Rock
// Department of Computer Science
// CPSI 28003 - 01 and 9S1: Algorithms
// Spring 2026
// Project 1: Doubly Linked List
// Due Date: March 10, 2026, Tuesday
// Name: Aiden Christopher
// Workday Number:1000499995
/*
Description of the Program: 
This program implements doubly linked list and displays various operations with it. The test cases include:
	displaying linked list,
	checking if the list is a palindrome, 
	splitting the list into sub-lists, 
	and adding a new node before a target node. 
*/

// Date Written: 3/4/2026
// Date Revised: 3/7/2026

#include <iostream>
#include "doublylinkedlist.cpp"
#include "Node.cpp"

using namespace std;

int main()
{
	// test case 1
	// Create a doubly linked list
	DoublyLinkedList Dll_1;
	// Each node contains only one integer of a string
	Node n11(10);
	Node n12(30);
	Node n13(50);
	Node n14(40);
	Node n15(50);
	// a doubly linked list of integers by inserting nodes
	Dll_1.addNewNodeToFront(&n11);
	Dll_1.addNewNodeToBack(&n12);
	Dll_1.addNewNodeToBack(&n13);
    Dll_1.addNewNodeToBack(&n14);
    Dll_1.addNewNodeToBack(&n15);
	//output
	std::string line = "-----------------------------";
	std::cout << line << endl;
	std::cout << "Doubly Linked List: " << endl;
	Dll_1.drawDoublyLinkedList();
	
	std::cout << line << endl;

	//Palindrome Test Case 1
	std::cout << line << endl;
	std::cout << "Palindrome Check: " << endl;
	cout << Dll_1.isPalindrome() << endl;

	DoublyLinkedList Dll_2;
	// Each node contains only one integer of a string
	Node n21(10);
	Node n22(20);
	Node n23(20);
	Node n24(10);
	// a doubly linked list of integers by inserting nodes
	Dll_2.addNewNodeToFront(&n21);
	Dll_2.addNewNodeToFront(&n22);
	Dll_2.addNewNodeToFront(&n23);
	Dll_2.addNewNodeToFront(&n24);
	//output
	cout << Dll_2.isPalindrome() << endl;
	std::cout << line << endl;

	//Palindrome Test Case 2
	//split a doubly linked list
	std::cout << line << endl;
	std::cout << "Split Doubly Linked List Test 1: " << endl;
	DoublyLinkedList *Dll_3;
	Dll_3 = new DoublyLinkedList;

	// Each node contains only one integer of a string
	Node n30(1);
	Node n31(2);
	Node n32(3);
	Node n33(4);
	Node n34(5);
	Node n35(6);

	// a doubly linked list of integers by inserting nodes
	Dll_3->addNewNodeToBack(&n30);
	Dll_3->addNewNodeToBack(&n31);
	Dll_3->addNewNodeToBack(&n32);
	Dll_3->addNewNodeToBack(&n33);
	Dll_3->addNewNodeToBack(&n34);
	Dll_3->addNewNodeToBack(&n35);
	Dll_3->split(3);

	// Split Test Case 1
	// Create a doubly linked list
	std::cout << "\nSplit Doubly Linked List Test 2: " << endl;

	DoublyLinkedList *Dll_4;
	Dll_4 = new DoublyLinkedList;
	// Each node contains only one character of a string
	Node n36(1);
	Node n37(2);
	Node n38(3);
	Node n39(4);
	Node n40(5);
	Node n41(6);
	Node n42(7);
	// a doubly linked list of characters by inserting nodes
	Dll_4->addNewNodeToBack(&n36);
	Dll_4->addNewNodeToBack(&n37);
	Dll_4->addNewNodeToBack(&n38);
	Dll_4->addNewNodeToBack(&n39);
	Dll_4->addNewNodeToBack(&n40);
	Dll_4->addNewNodeToBack(&n41);
	Dll_4->addNewNodeToBack(&n42);
	Dll_4->split(3);
	cout << line << endl;

	// Add New Node Before Target Node Test Case 1
	std::cout << line << endl;
	std::cout << "Add New Node Before Target Node Test 1: " << endl;
	DoublyLinkedList *Dll_5;
	Dll_5 = new DoublyLinkedList;
	// Each node contains only one character of a string
	Node n50(11);
	Node n51(22);
	Node n52(33);
	Node n53(44);
	Node n54(55);
	Node n55(66);
	// a doubly linked list of characters by inserting nodes
	Dll_5->addNewNodeToBack(&n50);
	Dll_5->addNewNodeToBack(&n51);
	Dll_5->addNewNodeToBack(&n52);
	Dll_5->addNewNodeToBack(&n53);
	Dll_5->addNewNodeToBack(&n54);
	Dll_5->addNewNodeToBack(&n55);

	Node n56(77);
	Dll_5->addNewNodeBeforeTargetNode(&n56, 44);
	Node n57(88);
	Dll_5->addNewNodeBeforeTargetNode(&n57, 29); //non existent target value
	Dll_5->displayDoublyLinkedList();
	cout << line << endl;




	system("PAUSE");
	return 0;
}
