#include "Lab20a_Recursion.h"

#include<iostream>
#include<string>

using namespace std;

void Lab20a_Recursion::appendNode(int num)
{
	ListNode* newNode;  // To point to a new node
	ListNode* nodePtr;  // To move through the list

	// Allocate a new node and store num there.
	newNode = new ListNode;
	newNode->value = num;
	newNode->next = nullptr;

	// If there are no nodes in the list
	// make newNode the first node.
	if (!head)
		head = newNode;
	else  // Otherwise, insert newNode at end.
	{
		// Initialize nodePtr to head of list.
		nodePtr = head;

		// Find the last node in the list.
		while (nodePtr->next)
			nodePtr = nodePtr->next;

		// Insert newNode as the last node.
		nodePtr->next = newNode;
	}
}

//**************************************************
// displayList shows the value                     *
// stored in each node of the linked list          *
// pointed to by head.                             *
//**************************************************

void Lab20a_Recursion::print()
{
	cout << " list contents = ";
	ListNode* nodePtr;  // To move through the list

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr points to a node, traverse
	// the list.
	cout << "head= " << nodePtr << endl;
	while (nodePtr)
	{
		// Display the value in this node.
		cout << nodePtr << " value = ";
		cout << nodePtr->value << "  ";

		// Move to the next node.
		nodePtr = nodePtr->next;
		cout << " next = " << nodePtr << endl;
	}
	cout << endl;
}

//**************************************************
// The insertNode function inserts a node with     *
// num copied to its value member.                 *
//**************************************************

void Lab20a_Recursion::insertNode(int num)
{
	ListNode* newNode;					// A new node
	ListNode* nodePtr;					// To traverse the list
	ListNode* previousNode = nullptr;	// The previous node

	// Allocate a new node and store num there.
	newNode = new ListNode;
	newNode->value = num;

	// If there are no nodes in the list
	// make newNode the first node
	if (!head)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else  // Otherwise, insert newNode
	{
		// Position nodePtr at the head of list.
		nodePtr = head;

		// Initialize previousNode to nullptr.
		previousNode = nullptr;

		// Skip all nodes whose value is less than num.
		while (nodePtr != nullptr && nodePtr->value < num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If the new node is to be the 1st in the list,
		// insert it before all other nodes.
		if (previousNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else  // Otherwise insert after the previous node.
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

//**************************************************
// The deleteNode function searches for a node     *
// with num as its value. The node, if found, is   *
// deleted from the list and from memory.          *
//**************************************************

void Lab20a_Recursion::deleteNode(int num)
{
	ListNode* nodePtr;       // To traverse the list
	ListNode* previousNode = nullptr;  // To point to the previous node

	// If the list is empty, do nothing.
	if (!head)
		return;

	// Determine if the first node is the one.
	if (head->value == num)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		// Initialize nodePtr to head of list
		nodePtr = head;

		// Skip all nodes whose value member is 
		// not equal to num.
		while (nodePtr != nullptr && nodePtr->value != num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If nodePtr is not at the end of the list, 
		// link the previous node to the node after
		// nodePtr, then delete nodePtr.
		if (nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************


int Lab20a_Recursion::length() {  // return the list length (number of nodes) to the caller.
	ListNode* nodePtr;
	int count = 0; // Initialize count
	nodePtr = head; // Initialize current
	while (nodePtr != NULL)
	{
		count++;
		nodePtr = nodePtr->next;
	}
	return count;
}
void Lab20a_Recursion::displayMaxValue() {// display the largest data value on the screen
	
	ListNode* nodePtr;
	nodePtr = head;
	int max = INT_MIN;

	if (nodePtr == NULL) {
		cout << "List is empty." << endl;
	}

	else {

		while (nodePtr != NULL)
		{

			if (max < nodePtr->value) {
				max = nodePtr->value;
			}
			nodePtr = nodePtr->next;
		}
	}
	cout << " the max value in the list : " << max << endl;
}
int Lab20a_Recursion::total() { // return the total (sum) of all list values to the caller.
	
	ListNode* nodePtr;
	nodePtr = head;
	int sum = 0;
	while (nodePtr != NULL) {
		sum += nodePtr->value;
		nodePtr = nodePtr->next;
	}
	return sum;
}
 Lab20a_Recursion::~Lab20a_Recursion() {
	
	 ListNode* nodePtr;   // To traverse the list
	ListNode* nextNode;  // To point to the next node

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr is not at the end of the list...
	while (nodePtr != nullptr)
	{
		// Save a pointer to the next node.
		nextNode = nodePtr->next;

		// Delete the current node.
		delete nodePtr;

		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
}
 

 

 int Lab20a_Recursion::sum(ListNode* nodePtr) {
	 if (nodePtr != nullptr) {
		 return  nodePtr->value + sum(nodePtr->next);
	 }
	 else
		 return 0;
 }
 // recursive backword print nodes
 void Lab20a_Recursion::backword(ListNode* nodePtr) {
	 if (nodePtr != nullptr)
	 {
		 backword(nodePtr->next);
		 cout << nodePtr << " value = " << "   " << nodePtr->value << "  ";
		 cout << " next = " <<nodePtr->next<< endl;
	 }
	 else
		 cout << "list empty , head = " << head << endl;
 }

 int Lab20a_Recursion::findMaxValue(ListNode* nodePtr)  {
	 if (nodePtr != nullptr)
		 // library function to findin the max.
		 return max(nodePtr->value, findMaxValue(nodePtr->next));
	 else
		 return 0;
 }

 int Lab20a_Recursion::recursiveLength(ListNode* nodePtr) {
	 if (nodePtr != nullptr) {
		 return 1 + recursiveLength(nodePtr->next);
	 }
	 else
		 return 0;
 }
 // recursive print nodes
 void Lab20a_Recursion::printRe(ListNode* nodePtr) {
	 if (nodePtr == nullptr) {
		 return;
	 }
		 // Display the value in this node.
		 cout << nodePtr << " value =  " << "   "<< nodePtr->value << "  ";
		 cout << " next =   " <<nodePtr->next<< endl;
		 printRe(nodePtr->next);
 }

 void Lab20a_Recursion::printHead() {
	 ListNode* nodePtr;
	 nodePtr = head;

	 cout << head << endl;
 }