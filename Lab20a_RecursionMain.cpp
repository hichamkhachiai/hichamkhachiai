#include "Lab20a_Recursion.h"
#include <iostream>
#include<string>

using namespace std;

void printOptions() {
	cout << "\t a" << "\t APPEND a value to the list." << endl;
	cout << "\t b" << "\tBACKWARDS RECURSIVE PRINT: use recursion to print the list backwards." << endl;
	cout << "\t c" << "\t COUNT nodes in the list, using a loop." << endl;
	cout << "\t d" << "\t DELETE a value from the list." << endl;
	cout << "\t i" << "\t INSERT a value into the list." << endl;
	cout << "\t l" << " \t (lower-case 'L') recursively determine LARGEST value in list." << endl;
	cout << "\t m" << " \t calculate MAXIMUM value in the list." << endl;
	cout << "\t n" << "\tuse RECURSION to count the NUMBER of nodes in the list." << endl;
	cout << "\t p" << "\t  PRINT the list contents." << endl;
	cout << "\t r" << "\tRECURSIVE PRINT: use recursion to print the list contents." << endl;
	cout << "\t s" << "\trecursively calculate SUM of all values in list." << endl;
	cout << "\t t" << "\tCalculate TOTAL of all values in the list." << endl;
	cout << "\t h" << "\t print help text." << endl;
	cout << "\t q " << "\tquit (end the program)." << endl;
}

int main() {

	char option;
	Lab20a_Recursion list;
	int num;

	while (true)
	{
		cout << " Enter a command or h for help" << endl;
		cin >> option;

		if (option == 'h') {
			cout << " Supported commands:" << endl;
			printOptions();
		}
		else if (option == 'a') {
			cout << " Enter number to insert into the list:";
			cin >> num;
			list.appendNode(num);
		}
		else if (option == 'c') {
			cout << "Length of list = " << list.length() << "  nodes" << endl;
		}

		else if (option == 'd') {
			cout << "Enter number to delete from the list :";
			cin >> num;
			list.deleteNode(num);
		}

		else if (option == 'i') {
			cout << " Enter number to insert into the list:";
			cin >> num;
			list.insertNode(num);
		}

		else if (option == 'm') {

			list.displayMaxValue();
		}

		else if (option == 'p') {
			list.print();
		}

		else if (option == 'q') {
			exit(0);
		}

		else if (option == 't') {
			cout << " Total of all list values = " << list.total();
		}

		else if (option == 'r') {
			cout << " the recursive print of the list ," << endl;
			cout << " head =   ";
			list.printHead();
			list.printRecursively();// function not working;
			cout << endl;
		}
		else if (option == 'n') {
			cout << " recursive Length of list =  "<<
			list.recursiveLengthCount();
			cout << endl;

		}
		else if (option == 'l') {
			cout << "  recursive large value in the  list ,  " <<
			list.recusiveFindMaxValue();
			cout << endl;
		}

		else if (option == 'b') {
			cout << " the Backword recursive print  list ," << endl;
			cout << " head =   "<<endl;
			list.printHead();
			list.backwordRecursivePrint();
		}

		else if (option == 's') {
			cout << " recursive Total of all list values =  "<<
			list.recursiveSum();
			cout << endl;
		}

		else
			cout << " Invalid Entry" << endl;

	}

	return 0;
}