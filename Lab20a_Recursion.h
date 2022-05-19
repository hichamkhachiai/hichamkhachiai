#pragma once
#ifndef RECURSIN_H
#define RECURSION_H
#include <string>

class Lab20a_Recursion
{
private:

	// Declare a structure for the list
	struct ListNode
	{
		int value;              // The value in this node
		struct ListNode* next;  // To point to the next node
	};
	ListNode* head; // List head pointer

	// private recursive function
	int sum(ListNode*);//-------------------------------------
	int findMaxValue(ListNode*) ;
	int recursiveLength(ListNode*);
	void printRe(ListNode*);
	void backword(ListNode*);


public:
	// Constructor
	Lab20a_Recursion()
	{
		head = nullptr;
	}

	// Destructor
	~Lab20a_Recursion();

	// Linked list operations
	void appendNode(int);  // Append a new node at the end of the list.
	void insertNode(int); // Insert a new node into the list, maintaining a sorted order.
	void deleteNode(int); // remove a node from the list.
	void print(); // output the contents of the list to the screen
	int length(); // return the list length (number of nodes) to the caller.
	void displayMaxValue(); // display the largest data value on the screen
	int total(); // return the total (sum) of all list values to the caller.
	//-------------------------------------------------------------------
	void printRecursively() { 
		printRe(head); 
	}//r------------------------------
	void backwordRecursivePrint() {
		backword(head);
	}//b---------------------------
	int recursiveLengthCount() { return recursiveLength(head); }//n----------------------------
	int recursiveSum() { return sum(head); }//s--//
	int recusiveFindMaxValue() { return findMaxValue(head); }//l

	void printHead();
	
	
};
#endif;
