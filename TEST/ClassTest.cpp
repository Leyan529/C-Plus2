#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "ClassTest/Time1.h"
#include "ClassTest/SalesPerson.h" 
#include "ClassTest/CreateAndDestroy.h" // include CreateAndDestroy class definition
#include "ClassTest/Date.h"
using namespace std;


void TimeTest1();
class Count
{
public:
	void setX(int value) {
		x = value;
	}
	void print() { cout << x << endl; }
private:
	int x;
};
void CountTest1();
void SalesTest();
void TimeTest2();

void CreateAndDestroyTest();
void create(void); // prototype
//CreateAndDestroy first(1, "(global before main)"); // global object

void TimeTest3();
void DateTest();

int ClassTest() {
	//TimeTest1();
	//CountTest();
	//SalesTest();
	//TimeTest2();
	//CreateAndDestroyTest();
	//TimeTest3();
	DateTest();
	system("pause");
	return 0;
}

void TimeTest1()
{
	//Time t;
	//// output Time object t's initial values
	//cout << "The initial universal time is ";
	//t.printUniversal(); // 00:00:00
	//cout << "\nThe initial standard time is ";
	//t.printStandard(); // 12:00:00 AM

	//t.setTime(13, 27, 6); // change time

	//					  // output Time object t's new values
	//cout << "\n\nUniversal time after setTime is ";
	//t.printUniversal(); // 13:27:06
	//cout << "\nStandard time after setTime is ";
	//t.printStandard(); // 1:27:06 PM

	//t.setTime(99, 99, 99); // attempt invalid settings

	//					   // output t's values after specifying invalid values
	//cout << "\n\n不合法的時間設定:"
	//	<< "\nUniversal time: ";
	//t.printUniversal(); // 00:00:00
	//cout << "\nStandard time: ";
	//t.printStandard(); // 12:00:00 AM
	//


	//Time *pointTime = &t;
	//pointTime->setTime(20, 35, 53); // attempt invalid settings
	//cout << "\n\nPointer Universal time after setTime is ";
	//pointTime->printUniversal(); // 13:27:06
	//cout << "\nPointer Standard time after setTime is ";
	//pointTime->printStandard(); // 1:27:06 PM
	//
	//cout << endl;
	
}
void CountTest1() {
	Count counter; // create counter object 
	Count *counterPtr = &counter; // create pointer to counter
	Count &counterRef = counter; // create reference to counter

	cout << "Set x to 1 and print using the object's name: ";
	counter.setX(1); // set data member x to 1
	counter.print(); // call member function print

	cout << "Set x to 2 and print using a reference to an object: ";
	counterRef.setX(2); // set data member x to 2
	counterRef.print(); // call member function print

	cout << "Set x to 3 and print using a pointer to an object: ";
	counterPtr->setX(3); // set data member x to 3
	counterPtr->print(); // call member function print
}

void SalesTest(){
	SalesPerson s; // create SalesPerson object s

	s.getSalesFromUser(); // note simple sequential code; there are
	s.printAnnualSales(); // no control statements in main
}

void TimeTest2(){
	//Time t1; // all arguments defaulted
	//Time t2(2); // hour specified; minute and second defaulted
	//Time t3(21, 34); // hour and minute specified; second defaulted 
	//Time t4(12, 25, 42); // hour, minute and second specified
	//Time t5(27, 74, 99); // all bad values specified

	//cout << "Constructed with:\n\nt1: all arguments defaulted\n  ";
	//t1.printUniversal(); // 00:00:00
	//cout << "\n  ";
	//t1.printStandard(); // 12:00:00 AM

	//cout << "\n\nt2: hour specified; minute and second defaulted\n  ";
	//t2.printUniversal(); // 02:00:00
	//cout << "\n  ";
	//t2.printStandard(); // 2:00:00 AM

	//cout << "\n\nt3: hour and minute specified; second defaulted\n  ";
	//t3.printUniversal(); // 21:34:00
	//cout << "\n  ";
	//t3.printStandard(); // 9:34:00 PM

	//cout << "\n\nt4: hour, minute and second specified\n  ";
	//t4.printUniversal(); // 12:25:42
	//cout << "\n  ";
	//t4.printStandard(); // 12:25:42 PM

	//cout << "\n\nt5: all invalid values specified\n  ";
	//t5.printUniversal(); // 00:00:00
	//cout << "\n  ";
	//t5.printStandard(); // 12:00:00 AM
	//cout << endl;
}

void CreateAndDestroyTest(){
	cout << "\nMAIN FUNCTION: EXECUTION BEGINS" << endl;
	CreateAndDestroy second(2, "(local automatic in main)");
	static CreateAndDestroy third(3, "(local static in main)");

	create(); // call function to create objects

	cout << "\nMAIN FUNCTION: EXECUTION RESUMES" << endl;
	CreateAndDestroy fourth(4, "(local automatic in main)");
	cout << "\nMAIN FUNCTION: EXECUTION ENDS" << endl;
}
void create(void)
{
	cout << "\nCREATE FUNCTION: EXECUTION BEGINS" << endl;
	CreateAndDestroy fifth(5, "(local automatic in create)");
	static CreateAndDestroy sixth(6, "(local static in create)");
	CreateAndDestroy seventh(7, "(local automatic in create)");
	cout << "\nCREATE FUNCTION: EXECUTION ENDS" << endl;
} // end function create

void TimeTest3(){
	//Time t; // create Time object

			// initialize hourRef with the reference returned by badSetHour
	//int &hourRef = t.badSetHour(20); // 20 is a valid hour

	//cout << "Valid hour before modification: " << hourRef;
	//hourRef = 30; // use hourRef to set invalid value in Time object t
	//cout << "\nInvalid hour after modification: " << t.getHour();

	//// Dangerous: Function call that returns
	//// a reference can be used as an lvalue!
	//t.badSetHour(12) = 74; // assign another invalid value to hour

	//cout << "\n\n*************************************************\n"
	//	<< "POOR PROGRAMMING PRACTICE!!!!!!!!\n"
	//	<< "t.badSetHour( 12 ) as an lvalue, invalid hour: "
	//	<< t.getHour()
	//	<< "\n*************************************************" << endl;
}

void DateTest(){
	//Date date1(7, 4, 2004);
	//Date date2; // date2 defaults to 1/1/2000

	//cout << "date1 = ";
	//date1.print();
	//cout << "\ndate2 = ";
	//date2.print();

	//date2 = date1; // default memberwise assignment

	//cout << "\n\nAfter default memberwise assignment, date2 = ";
	//date2.print();
	//cout << endl;
}
