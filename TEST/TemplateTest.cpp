#include <iomanip>
#include <iostream>
#include <random>
#include <time.h>
#include "TemplateTest/Stack.h"
#include <string>
using namespace std;

//Function template
template <typename T> // T:使用者定義型態
void printArray(const T * array,int count) {
	for (int i = 0; i < count; i++) {
		cout << array[i] <<" , ";
	}
	cout << endl;
}
void func_template();


void class_template();

void test_template();
//template< typename T = int>
//void testStack( //定義測試自定義堆疊的方法
//	Stack< T,20 > &theStack, // reference to Stack< T >         
//	T value, // initial value to push                        
//	T increment, // increment for subsequent values          
//	const string stackName) // name of the Stack< T > object
//{
//	cout << "Pushing elements onto " << stackName << endl;
//
//	// push element onto Stack                               
//	while (theStack.push(value))
//	{
//		cout << value << ' ';
//		value += increment;
//	} // end while                                           
//
//	cout << "\nStack is full. Cannot push " << value
//		<< "\n\nPopping elements from " << stackName << '\n';
//
//	// pop elements from Stack                               
//	while (theStack.pop(value))
//		cout << value << ' ';
//
//	cout << "\nStack is empty. Cannot pop" << endl;
//} // end function template testStack  



//ch14 38/45
void TemplateTest() {
	//func_template();
	//class_template();
	test_template();

	system("pause");
}

void func_template()
{
	srand(time(0));
	const int size_a = 3;
	int a[size_a];
	for (int i = 0; i < size_a; i++) {
		a[i] = rand() % 8 + 1;
	}
	cout << "Array a contains" << endl;
	printArray(a, size_a);

	const int size_b = 5;
	double b[size_b];
	for (int i = 0; i < size_b; i++) {
		b[i] = (double)(rand() / (double)RAND_MAX) + (rand() % 8 + 1);
	}
	cout << "Array b contains" << endl;
	printArray(b, size_b);

	const int size_c = 7;
	char c[size_c];
	for (int i = 0; i < size_c; i++) {
		c[i] = 'A' + rand() % 26 + 1;
	}
	cout << "Array c contains" << endl;
	printArray(c, size_c);
}

void class_template()
{
	/*srand(time(0));

	Stack<double> doubleStack(5);
	double dbl_value = (double)(rand() / (double)RAND_MAX) + (rand() % 8 + 1);
	cout << "push values" << endl;
	while (doubleStack.push(dbl_value)) {
		cout << dbl_value << " has been pushed " << endl;
		dbl_value = (double)(rand() / (double)RAND_MAX) + rand();
	}
	cout << "Stack Full" << endl<<endl;

	while (doubleStack.pop(dbl_value)) {
		cout << dbl_value << " has been poped"<<endl;
	}
	cout << "Stack empty" << endl<<endl;
	cout << "-------------------------" << endl<<endl;

	Stack<int> intStack(5);
	int value =  (rand() % 8 + 1);
	cout << "push values" << endl;
	while (intStack.push(value)) {
		cout << value << " has been pushed " << endl;
		value = (rand() % 8 + 1);
	}
	cout << "Stack Full" << endl << endl;

	while (intStack.pop(value)) {
		cout << value << " has been poped" << endl;
	}
	cout << "Stack empty" << endl;*/
}
void test_template()
{
	//Stack< double,20> doubleStack(5); // size 5 , default = 20 

	//testStack(doubleStack, 1.1, 1.1, "doubleStack");

}




