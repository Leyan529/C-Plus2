#include <iostream>
#include <iomanip>
#include "OverLoadTest/PhoneNumber.h"
using namespace std;

int OverLoadTest() {
	PhoneNumber phone;
	cout << "Enter phone number in the form (123) 456-7890:" << endl;
	cin >> phone;
	cout << "The Phone number entered was: ";
	cout << phone << endl;
	system("pause");
	return 0;
}
 
