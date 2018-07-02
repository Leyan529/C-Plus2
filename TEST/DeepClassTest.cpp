#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "DeepClassTest/Time2.h"
#include "DeepClassTest/Increment1.h"
#include "DeepClassTest/Employee1.h"
#include "DeepClassTest/Count.h"

using namespace std;
void TimeTest4();
void IncrementTest1();
void IncrementTest2();
void DPTest();
void CountTest();
void ThisTest();


class Test{
public:
	Test(int = 0); // default constructor
	void print() const;
private:
	int x;
}; // end class Test
Test::Test(int value): x(value) // initialize x to value
{
	// empty body 
} // end constructor Test
void Test::print() const
{
	// implicitly use the this pointer to access the member x
	cout << "        x = " << x;

	// explicitly use the this pointer and the arrow operator
	// to access the member x
	cout << "\n  this->x = " << this->x;

	// explicitly use the dereferenced this pointer and 
	// the dot operator to access the member x
	cout << "\n(*this).x = " << (*this).x << endl;
} // end function print

void TimeTest5();
void EmployeeTest2();

int DeepClassTest() {

	//TimeTest4();
	//IncrementTest2();
	//DPTest();
	//CountTest();
	//ThisTest();
	//TimeTest5();
	EmployeeTest2();
	system("pause");
	return 0;

}

void TimeTest4(){
	Time2 wakeUp(6, 45, 0); // non-constant object
	const Time2 noon(12, 0, 0); // constant object

							   // OBJECT      MEMBER FUNCTION
	wakeUp.setHour(18);  // non-const   non-const

	//noon.setHour(12);    // const       non-const (compile error)

	wakeUp.getHour();      // non-const   const

	noon.getMinute();      // const       const
	noon.printUniversal(); // const       const

	//noon.printStandard();  // const       non-const (compile error)
}

void IncrementTest1()
{
	Increment1 value(10, 5);

	cout << "Before incrementing: ";
	value.print();

	for (int j = 1; j <= 3; j++)
	{
		value.addIncrement();
		cout << "After increment " << j << ": ";
		value.print();
	} // end for
}

void IncrementTest2()
{
	Increment1 value(10, 5);

	cout << "Before incrementing: ";
	value.print();

	for (int j = 10; j <= 3; j++)
	{
		value.addIncrement();
		cout << "After increment " << j << ": ";
		value.print();
	} // end for
}

void DPTest(){
	//Date birth(7, 24, 1949);
	//Date hire(3, 12, 1988);
	//Employee manager("Bob", "Blue", birth, hire);

	//cout << endl;
	//manager.print();

	//cout << "\nTest Date constructor with invalid values:\n";
	//Date lastDayOff(14, 35, 1994); // invalid month and day
	//cout << endl;
}

void CountTest()
{
	Count counter; // create Count object

	cout << "counter.x after instantiation: ";
	counter.print();

	setX(counter, 8); // set x using a friend function
	cout << "counter.x after call to setX friend function: ";
	counter.print();
}

void ThisTest()
{
	Test testObject(12); // instantiate and initialize testObject
	testObject.print();
}

void TimeTest5()
{
	Time2 t; // create Time object

			// cascaded function calls
	t.setHour(18).setMinute(30).setSecond(22);

	// output time in universal and standard formats
	cout << "Universal time: ";
	t.printUniversal();

	cout << "\nStandard time: ";
	t.printStandard();

	cout << "\n\nNew standard time: ";

	// cascaded function calls
	t.setTime(20, 20, 20).printStandard();
	cout << endl;
}

void EmployeeTest2()
{
	//cout << "Number of employees before instantiation of any objects is "
	//	<< Employee::getCount() << endl; // use class name

	//									 // the following scope creates and destroys 
	//									 // Employee objects before main terminates
	//{
	//	Employee e1("Susan", "Baker");
	//	Employee e2("Robert", "Jones");

	//	// two objects exist; call static member function getCount again 
	//	// using the class name and the binary scope resolution operator
	//	cout << "Number of employees after objects are instantiated is "
	//		<< Employee::getCount();

	//	cout << "\n\nEmployee 1: "
	//		<< e1.getFirstName() << " " << e1.getLastName()
	//		<< "\nEmployee 2: "
	//		<< e2.getFirstName() << " " << e2.getLastName() << "\n\n";
	//} // end nested scope in main

	//  // no objects exist, so call static member function getCount again 
	//  // using the class name and the binary scope resolution operator
	//cout << "\nNumber of employees after objects are deleted is "
	//	<< Employee::getCount() << endl;
}