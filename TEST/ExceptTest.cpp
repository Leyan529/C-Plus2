#include <iomanip>
#include <iostream>
using namespace std;
#include "ExceptTest/DivideByZeroException.h"
#include <new>
#include <cstdlib>
#include <memory>
#include "ExceptTest/Integer.h"
double quotient(int num, int q)
{
	if (q == 0)
		throw DivideByZeroException(); // terminate function
									   // return division result
	return static_cast< double > (num )/ q; //���Nnum �૬��double�A�۰�
} 
void ExcepTest1();

void throwException() {
	try {
		cout << "���throwException�ߥX�@��Exception\n";
		throw exception();
	}
	catch (exception &) {
		cout << "���throwExceptiont�B�z���ߪ�exception\n";
		throw;
	}
	cout << "(throwException)\n";
}
void ExcepTest2();

void UnWindingTest();
void function3() throw (runtime_error)
{
	cout << "In function 3" << endl;

	// no try block, stack unwinding occurs, return control to function2
	throw runtime_error("runtime_error in function3"); // no print
} // end function3
void function2() throw (runtime_error)
{
	cout << "function3 is called inside function2" << endl;
	function3(); // stack unwinding occurs, return control to function1
} // end function2
void function1() throw (runtime_error)
{
	cout << "function2 is called inside function1" << endl;
	function2(); // stack unwinding occurs, return control to main
} // end function1

void BadAllocTest();

void HandlerTest();
// memory allocation ���~�B�z���
void customNewHandler()
{
	cerr << "customNewHandler was called";
	abort();
} 
void AutoPtrTest();

  //ch16 - 86/107
void ExceptTest() {
	//ExcepTest1();
	//ExcepTest2();
	//UnWindingTest();
	//BadAllocTest();
	//HandlerTest();
	AutoPtrTest();
	system("pause");
}

void ExcepTest1()
{
	int number1; // user-specified numerator
	int number2; // user-specified denominator
	double result; // result of division

	cout << "Enter two integers (end-of-file to end): ";

	// enable user to enter two integers to divide
	while (cin >> number1 >> number2)
	{
		// try block contains code that might throw exception
		// and code that should not execute if an exception occurs
		try
		{
			result = quotient(number1, number2);
			cout << "The quotient is: " << result << endl;
		} // end try
		catch (DivideByZeroException &divideByZeroException)
		{
			cout << "Exception occurred: "
				<< divideByZeroException.what() << endl; //�^�ǹ��Exception������
		} // end catch

		cout << "\nEnter two integers (end-of-file to end): ";
	} // end while

	cout << endl;
}

void ExcepTest2()
{
	try {
		cout << "\n ExcepTest2�I�sthrowException\n";
		throwException();
		cout << "(ExcepTest2)\n";
	}
	catch (exception &) {
		cout << "�bExcepTest2���B�zException\n";		
	}
	cout << "�bcatch�B�z�����~���᭫�s���o�����v\n";
}

void UnWindingTest()
{
	try
	{
		cout << "function1 is called inside main" << endl;
		function1(); // call function1 which throws runtime_error
	} // end try
	catch (runtime_error &error) // handle runtime error
	{
		cout << "Exception occurred: " << error.what() << endl;
		cout << "Exception handled in main" << endl;
	} // end catch
}

void BadAllocTest()
{
	double *ptr[50];

	try
	{
		for (int i = 0; i < 50; i++)
		{
			ptr[i] = new double[5000000]; // may throw exception
			cout << "ptr[" << i << "] points to 50,000,000 new doubles\n";
		} // end for
	} // end try
	catch (bad_alloc &memoryAllocationException)
	{
		cerr << "Exception occurred: "
			<< memoryAllocationException.what() << endl;
	} // end catch
}

void HandlerTest()
{
	double *ptr[50];

	set_new_handler(customNewHandler); //�]�wcustomNewHandler�����~�B�z���

	for (int i = 0; i < 50; i++)
	{
		ptr[i] = new double[50000000]; // may throw exception
		cout << "ptr[" << i << "] points to 50,000,000 new doubles\n";
	} // end for
}

void AutoPtrTest()
{
	cout << "Creating an auto_ptr object that points to an Integer\n";

	// "aim" auto_ptr at Integer object
	auto_ptr< Integer > ptrToInteger(new Integer(7));

	cout << "\nUsing the auto_ptr to manipulate the Integer\n";
	ptrToInteger->setInteger(99); // use auto_ptr to set Integer value

								  // use auto_ptr to get Integer value
	cout << "Integer after setInteger: " << (*ptrToInteger).getInteger()
		<< "\n\nTerminating program" << endl;
}
