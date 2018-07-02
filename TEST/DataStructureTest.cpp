#include <iostream>
#include <iomanip>
using namespace std;

#include "DataStructureTest/BinarySearch.h" // class BinarySearch definition
#include "DataStructureTest/MergeSort.h"
void BinarySearchTest();
void MergeSortTest();

#include <string>
#include "DataStructureTest/List.h" // List class definition
void instructions();
template< typename T > void testList(List< T > &, const string &);
void ListTest();
//#include "DataStructureTest/Stack.h"
void StackTest1();
#include "DataStructureTest/Stackcomposition.h"
void StackTest2();
#include "DataStructureTest/Queue.h"
void QueueTest();
#include "DataStructureTest/Tree.h"
#include <random>
void BSTest();

void DataStructureTest() {
	/*BinarySearch();
	MergeSort();*/
	//ListTest();
	//StackTest1();
	//StackTest2();
	//QueueTest();
	BSTest();
	system("pause");
}
void BinarySearchTest()
{
	int searchInt; // search key
	int position; // location of search key in vector

					// create vector and output it
	BinarySearch searchVector(15);
	searchVector.displayElements();

	// get input from user
	cout << "\nPlease enter an integer value (-1 to quit): ";
	cin >> searchInt; // read an int from user
	cout << endl;

	// repeatedly input an integer; -1 terminates the program
	while (searchInt != -1)
	{
		// use binary search to try to find integer
		position = searchVector.binarySearch(searchInt);

		// return value of -1 indicates integer was not found
		if (position == -1)
			cout << "The integer " << searchInt << " was not found.\n";
		else
			cout << "The integer " << searchInt
			<< " was found in position " << position << ".\n";

		// get input from user
		cout << "\n\nPlease enter an integer value (-1 to quit): ";
		cin >> searchInt; // read an int from user
		cout << endl;
	}
}
void MergeSortTest()
{
	// create object to perform merge sort
	MergeSort sortVector(10);

	cout << "Unsorted vector:" << endl;
	sortVector.displayElements(); // print unsorted vector
	cout << endl << endl;

	sortVector.sort(); // sort vector

	cout << "Sorted vector:" << endl;
	sortVector.displayElements(); // print sorted vector
	cout << endl;
}

// display program instructions to user
void instructions()
{
	cout << "Enter one of the following:\n"
		<< "  1 to insert at beginning of list\n"
		<< "  2 to insert at end of list\n"
		<< "  3 to delete from beginning of list\n"
		<< "  4 to delete from end of list\n"
		<< "  5 to end list processing\n";
} // end function instructions
  // function to test a List
template< typename T >
void testList(List< T > &listObject, const string &typeName)
{
	cout << "Testing a List of " << typeName << " values\n";
	instructions(); // display instructions

	int choice; // store user choice
	T value; // store input value

	do // perform user-selected actions
	{
		cout << "? ";
		cin >> choice;

		switch (choice)
		{
		case 1: // insert at beginning
			cout << "Enter " << typeName << ": ";
			cin >> value;
			listObject.insertAtFront(value);
			listObject.print();
			break;
		case 2: // insert at end
			cout << "Enter " << typeName << ": ";
			cin >> value;
			listObject.insertAtBack(value);
			listObject.print();
			break;
		case 3: // remove from beginning
			if (listObject.removeFromFront(value))
				cout << value << " removed from list\n";

			listObject.print();
			break;
		case 4: // remove from end
			if (listObject.removeFromBack(value))
				cout << value << " removed from list\n";

			listObject.print();
			break;
		} // end switch
	} while (choice < 5); // end do...while

	cout << "End list test\n\n";
} // end function testList
void ListTest()
{
	List< int > integerList;
	testList(integerList, "integer");

	// test List of double values
	List< double > doubleList;
	testList(doubleList, "double");
}

void StackTest1()
{
	Stack< int > intStack; // create Stack of ints

	cout << "processing an integer Stack" << endl;

	// push integers onto intStack
	for (int i = 0; i < 3; i++)
	{
		intStack.push(i);
		intStack.printStack();
	} // end for

	int popInteger; // store int popped from stack

					// pop integers from intStack
	while (!intStack.isStackEmpty())
	{
		intStack.pop(popInteger);
		cout << popInteger << " popped from stack" << endl;
		intStack.printStack();
	} // end while

	Stack< double > doubleStack; // create Stack of doubles
	double value = 1.1;

	cout << "processing a double Stack" << endl;

	// push floating-point values onto doubleStack
	for (int j = 0; j < 3; j++)
	{
		doubleStack.push(value);
		doubleStack.printStack();
		value += 1.1;
	} // end for

	double popDouble; // store double popped from stack

					  // pop floating-point values from doubleStack
	while (!doubleStack.isStackEmpty())
	{
		doubleStack.pop(popDouble);
		cout << popDouble << " popped from stack" << endl;
		doubleStack.printStack();
	} // end while
}

void StackTest2()
{
	Stack< int > intStack; // create Stack of ints

	cout << "processing an integer Stack" << endl;

	// push integers onto intStack
	for (int i = 0; i < 3; i++)
	{
		intStack.push(i);
		intStack.printStack();
	} // end for

	int popInteger; // store int popped from stack

					// pop integers from intStack
	while (!intStack.isStackEmpty())
	{
		intStack.pop(popInteger);
		cout << popInteger << " popped from stack" << endl;
		intStack.printStack();
	} // end while

	Stack< double > doubleStack; // create Stack of doubles
	double value = 1.1;

	cout << "processing a double Stack" << endl;

	// push floating-point values onto doubleStack
	for (int j = 0; j < 3; j++)
	{
		doubleStack.push(value);
		doubleStack.printStack();
		value += 1.1;
	} // end for

	double popDouble; // store double popped from stack

					  // pop floating-point values from doubleStack
	while (!doubleStack.isStackEmpty())
	{
		doubleStack.pop(popDouble);
		cout << popDouble << " popped from stack" << endl;
		doubleStack.printStack();
	} // end while
}

void QueueTest()
{
	Queue< int > intQueue; // create Queue of integers

	cout << "processing an integer Queue" << endl;

	// enqueue integers onto intQueue
	for (int i = 0; i < 3; i++)
	{
		intQueue.enqueue(i);
		intQueue.printQueue();
	} // end for

	int dequeueInteger; // store dequeued integer

						// dequeue integers from intQueue
	while (!intQueue.isQueueEmpty())
	{
		intQueue.dequeue(dequeueInteger);
		cout << dequeueInteger << " dequeued" << endl;
		intQueue.printQueue();
	} // end while

	Queue< double > doubleQueue; // create Queue of doubles
	double value = 1.1;

	cout << "processing a double Queue" << endl;

	// enqueue floating-point values onto doubleQueue
	for (int j = 0; j < 3; j++)
	{
		doubleQueue.enqueue(value);
		doubleQueue.printQueue();
		value += 1.1;
	} // end for

	double dequeueDouble; // store dequeued double

						  // dequeue floating-point values from doubleQueue
	while (!doubleQueue.isQueueEmpty())
	{
		doubleQueue.dequeue(dequeueDouble);
		cout << dequeueDouble << " dequeued" << endl;
		doubleQueue.printQueue();
	} // end while
}

void BSTest()
{
	Tree< int > intTree; // create Tree of int values
	int intValue;

	cout << "Enter 10 integer values:\n";
	srand(time(NULL));
	// insert 10 integers to intTree
	for (int i = 0; i < 10; i++)
	{		
		//cin >> intValue;
		intTree.insertNode(rand() % 50 + 1);
	} // end for

	cout << "\nPreorder traversal\n";
	intTree.preOrderTraversal();

	cout << "\nInorder traversal\n";
	intTree.inOrderTraversal();

	cout << "\nPostorder traversal\n";
	intTree.postOrderTraversal();

	Tree< double > doubleTree; // create Tree of double values
	double doubleValue;

	cout << fixed << setprecision(1)
		<< "\n\n\nEnter 10 double values:\n";

	/* «ü©w¶Ã¼Æ½d³ò */
	double min = 1;
	double max = 20;
	// insert 10 doubles to doubleTree
	for (int j = 0; j < 10; j++)
	{
		//cin >> doubleValue;
		doubleTree.insertNode((max - min) * rand() / (RAND_MAX + 1.0) + min);
	} // end for

	cout << "\nPreorder traversal\n";
	doubleTree.preOrderTraversal();

	cout << "\nInorder traversal\n";
	doubleTree.inOrderTraversal();

	cout << "\nPostorder traversal\n";
	doubleTree.postOrderTraversal();

	cout << endl;
}
