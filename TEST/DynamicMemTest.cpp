#include <iomanip>
#include <iostream>
using namespace std;
#include "DynamicMemTest/Array.h";
#include "DynamicMemTest/Date2.h"
#include "DynamicMemTest/Proxy.h"
void NormalTest();
void ArrayTest1();
void DateTest2();

void ArrayTest2();
void outputArray(const Array &);

void ProxyClassTest();

int DynamicMemTest() {
	//NormalTest();
	//ArrayTest1();
	//DateTest2();
	//ArrayTest2();
	ProxyClassTest();
	system("pause");
	return 0;
}

void NormalTest()
{
	double *ptr1 = new double(3.14159);
	int *ptr2 = new int[5];
	cout << *ptr1 << " , " << *ptr2 << endl;
	delete ptr1;
	delete[]ptr2;
}
void ArrayTest1()
{
	Array integer1(2); //size = 2
	Array integer2; //size = 5

	cout << "輸入陣列1大小 " << integer1.getSize() <<
		"\n陣列之後初始化:\n" << integer1;

	cout << "輸入陣列1大小 " << integer2.getSize() <<
		"\n陣列之後初始化:\n" << integer2;

	cout << "輸入17個數字" << endl;
	cin >> integer1 >> integer2;

	cout << "\nAfter input, the Arrays contain:\n"
		<< "integer1:\n" << integer1
		<< "integer2:\n" << integer2;

	// use overloaded inequality (!=) operator
	cout << "\n計算: integer1 != integer2" << endl;

	if (integer1 != integer2)
		cout << "integer1 and integer2 are not equal" << endl;

	// create Array integers3 using integer1 as an
	// initializer; print size and contents
	Array integers3(integer1); // invokes copy constructor

	cout << "\nSize of Array integers3 is "
		<< integers3.getSize()
		<< "\nArray after initialization:\n" << integers3;

	// use overloaded assignment (=) operator
	cout << "\n指派 integer2 to integer1:" << endl;
	integer1 = integer2; // note target Array is smaller

	cout << "integer1:\n" << integer1
		<< "integer2:\n" << integer2;

	// use overloaded equality (==) operator
	cout << "\n計算: integer1 == integer2" << endl;

	if (integer1 == integer2)
		cout << "integer1 and integer2 are equal" << endl;

	// use overloaded subscript operator to create rvalue
	cout << "\ninteger1[1] is " << integer1[1];

	// use overloaded subscript operator to create lvalue
	cout << "\n\n指派 1000 to integer1[1]" << endl;
	integer1[1] = 1000;
	cout << "integer1:\n" << integer1;

	// attempt to use out-of-range subscript
	cout << "\nAttempt to assign 1000 to integer1[15]" << endl;
	integer1[15] = 1000; // ERROR: out of range

	

}
void DateTest2()
{
	Date2 d1; // defaults to January 1, 1900
	Date2 d2(12, 27, 1992); // December 27, 1992
	Date2 d3(0, 99, 8045); // invalid date

	cout << "d1 is " << d1 << "\nd2 is " << d2 << "\nd3 is " << d3;
	cout << "\n\nd2 += 7 is " << (d2 += 7);

	d3.setDate(2, 28, 1992);
	cout << "\n\n  d3 is " << d3;
	cout << "\n++d3 is " << ++d3 << " (leap year allows 29th)";

	Date2 d4(7, 13, 2002);

	cout << "\n\nTesting the prefix increment operator:\n"
		<< "  d4 is " << d4 << endl;
	cout << "++d4 is " << ++d4 << endl;
	cout << "  d4 is " << d4;

	cout << "\n\nTesting the postfix increment operator:\n"
		<< "  d4 is " << d4 << endl;
	cout << "d4++ is " << d4++ << endl;
	cout << "  d4 is " << d4 << endl;
}

void ArrayTest2()
{
	Array integers1(7); // 7-element array
	outputArray(integers1); // output Array integers1
	//outputArray(3); // error 不能將int轉換成Array
	outputArray(Array(3)); // explicit single-argument constructor call
}
void outputArray(const Array &arrayToOutput)
{
	cout << "The Array received has " << arrayToOutput.getSize()
		<< " elements. The contents are:\n" << arrayToOutput << endl;
} // end outputArray

void ProxyClassTest()
{
	Proxy p(5); // 建立代理人物件

	cout << "Proxy contains: " << p.getValue()
		<< " before setValue" << endl;

	p.setValue(10);

	cout << "Proxy contains: " << p.getValue()
		<< " after setValue" << endl;
}
