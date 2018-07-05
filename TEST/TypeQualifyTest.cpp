#include <iostream>
#include <cstring> 
#include <cctype> 
#include "TypeQualifyTest\TestMutable.h"
using namespace std;


const char *maximum(const char *first, const char *second)
{
	return (strcmp(first, second) >= 0 ? first : second);
}
void constCastTest();

void mutableTest();

int integer1 = 98; // global variable

// Example(命名空間)
namespace Example
{
	const double PI = 3.14159;
	const double E = 2.71828;
	int integer1 = 8; // Example(命名空間) variable

	void printValues(); // Example(命名空間) function原型

	// Inner(內命名空間)
	namespace Inner
	{
		// define enumeration
		enum Years { FISCAL1 = 1990, FISCAL2, FISCAL3 };
	} // end Inner namespace
} 
// (未定義命名空間)
namespace
{
	double doubleInUnnamed = 88.22; // variable
}
void nameSpaceTest();

#include <ciso646>
void operKeyTest();

class Test
{
public:
	void func()
	{
		cout << "In func\n";
	} // end function func

	int value; // public data member
}; // end class Test
void arrowStar(Test *); // prototype
void dotStar(Test *); // prototype
void pointToMemberTest();

#include "TypeQualifyTest\Base1.h"
#include "TypeQualifyTest\Base2.h"
#include "TypeQualifyTest\Derived.h"
void muitipleInheritTest1();

#include "TypeQualifyTest\Base.h"
#include "TypeQualifyTest\DerivedOne.h"
#include "TypeQualifyTest\DerivedTwo.h"
#include "TypeQualifyTest\Multiple.h"
void multipleInheritTest2();

//ch24 81/104
void main() {
	//constCastTest();
	//mutableTest();
	//nameSpaceTest();
	//operKeyTest();
	//pointToMemberTest1();
	//muitipleInheritTest1();
	multipleInheritTest2();
	system("pause");
}

void constCastTest()
{
	char s1[] = "hello";
	char s2[] = "goodbye";

	// const_cast轉換符是用來移除變量的const或volatile限定符
	char *maxPtr = const_cast< char * >(maximum(s1, s2));

	cout << "The larger string is: " << maxPtr << endl;

	for (size_t i = 0; i < strlen(maxPtr); i++)
		maxPtr[i] = toupper(maxPtr[i]);   //轉為大寫字母

	cout << "The larger string capitalized is: " << maxPtr << endl;
}

void mutableTest()
{
	const TestMutable test(99);

	cout << "Initial value: " << test.getValue();
	cout << "\nModified value: " << test.getValue() << endl;
}

void Example::printValues()
{
	cout << "\nIn printValues:\ninteger1 = " << integer1 << "\nPI = "  // integer1 : 已在namespace function下，直接存取該成員
		<< PI << "\nE = " << E << "\ndoubleInUnnamed = " // doubleInUnnamed : 屬於未定義命名空間的成員，可直接存取，而不發生衝突
		<< doubleInUnnamed << "\n(global) integer1 = " << ::integer1   // ::integer1 : 在namespace function下存取全域變數
		<< "\nFISCAL3 = " << Inner::FISCAL3 << endl;   // // Inner : 已在namespace function下，直接存取該內命名空間
} // end printValues
void nameSpaceTest()
{
	// output value doubleInUnnamed of unnamed namespace
	cout << "doubleInUnnamed = " << doubleInUnnamed;

	// output global variable
	cout << "\n(global) integer1 = " << integer1;

	// output values of Example namespace
	cout << "\nPI = " << Example::PI << "\nE = " << Example::E
		<< "\ninteger1 = " << Example::integer1 << "\nFISCAL3 = "
		<< Example::Inner::FISCAL3 << endl;

	Example::printValues(); // invoke printValues function
}

void operKeyTest()
{
	bool a = true;
	bool b = false;
	int c = 2;
	int d = 3;

	// sticky setting that causes bool values to display as true or false
	cout << boolalpha;

	cout << "a = " << a << "; b = " << b
		<< "; c = " << c << "; d = " << d;

	cout << "\n\nLogical operator keywords:";
	cout << "\n   a and a: " << (a and a);
	cout << "\n   a and b: " << (a and b);
	cout << "\n    a or a: " << (a or a);
	cout << "\n    a or b: " << (a or b);
	cout << "\n     not a: " << (not a);
	cout << "\n     not b: " << (not b);
	cout << "\na not_eq b: " << (a not_eq b);

	cout << "\n\nBitwise operator keywords:";
	cout << "\nc bitand d: " << (c bitand d);
	cout << "\nc bit_or d: " << (c bitor d);
	cout << "\n   c xor d: " << (c xor d);
	cout << "\n   compl c: " << (compl c);
	cout << "\nc and_eq d: " << (c and_eq d);
	cout << "\n c or_eq d: " << (c or_eq d);
	cout << "\nc xor_eq d: " << (c xor_eq d) << endl;
}

void arrowStar(Test *ptr)
{
	typedef void (Test::*Func)(); // 建立可以指向Test的函數指標型態(Func)
	Func funcObject = &Test::func; // 將原本Test的成員函數位址，指定給函數指標變數funcObject
	(ptr->*funcObject)(); // ->* :用來呼叫型態成員函式
	
} // end arrowStar

  // access members of Test object data member using .*
void dotStar(Test *ptr)
{
	typedef int Test::*Value; // 建立可以指向Test的成員指標型態(Value)
	Value v = &Test::value; // // 將原本Test的成員位址，指定給成員指標變數v
	cout << *ptr.*v << endl; // .* : 用來存取型態資料成員

} // end dotStar

void pointToMemberTest()
{
	Test test;
	test.value = 8; // assign value 8
	arrowStar(&test); // pass address to arrowStar
	dotStar(&test); // pass address to dotStar
}

void muitipleInheritTest1()
{
	Base1 base1(10), *base1Ptr = 0; // create Base1 object
	Base2 base2('Z'), *base2Ptr = 0; // create Base2 object
	Derived derived(7, 'A', 3.5); // create Derived object

	// 印出原有的初始化物件
	cout << "Object base1 contains integer " << base1.getData()
		<< "\nObject base2 contains character " << base2.getData()
		<< "\nObject derived contains:\n" << derived << "\n\n";

	// 透過.運算子間接指定類別成員函式
	cout << "Data members of Derived can be accessed individually:"
		<< "\n    Integer: " << derived.Base1::getData()
		<< "\n  Character: " << derived.Base2::getData()
		<< "\nReal number: " << derived.getReal() << "\n\n";
	cout << "Derived can be treated as an object of either base class:\n";

	// 將derived物件的位址指定給base1型pointer
	base1Ptr = &derived;
	cout << "base1Ptr->getData() yields " << base1Ptr->getData() << '\n';

	// 將derived物件的位址指定給base2型pointer
	base2Ptr = &derived;
	cout << "base2Ptr->getData() yields " << base2Ptr->getData() << endl;
}

void multipleInheritTest2()
{
	Multiple both; // instantiate Multiple object
	DerivedOne one; // instantiate DerivedOne object
	DerivedTwo two; // instantiate DerivedTwo object
	Base *array[3]; // create array of base-class pointers

	// 因both繼承多個基底類別，所以轉型為基底類別會發生編譯錯誤

	// 改使用虛擬繼承時，只會留下一個基底類別，
	// 故轉型時不會發生錯誤
	array[0] = &both; 
	array[1] = &one;
	array[2] = &two;

	// polymorphically invoke print
	for (int i = 0; i < 3; i++)
		array[i]->print();
			
}
