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

// Example(�R�W�Ŷ�)
namespace Example
{
	const double PI = 3.14159;
	const double E = 2.71828;
	int integer1 = 8; // Example(�R�W�Ŷ�) variable

	void printValues(); // Example(�R�W�Ŷ�) function�쫬

	// Inner(���R�W�Ŷ�)
	namespace Inner
	{
		// define enumeration
		enum Years { FISCAL1 = 1990, FISCAL2, FISCAL3 };
	} // end Inner namespace
} 
// (���w�q�R�W�Ŷ�)
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

	// const_cast�ഫ�ŬO�ΨӲ����ܶq��const��volatile���w��
	char *maxPtr = const_cast< char * >(maximum(s1, s2));

	cout << "The larger string is: " << maxPtr << endl;

	for (size_t i = 0; i < strlen(maxPtr); i++)
		maxPtr[i] = toupper(maxPtr[i]);   //�ର�j�g�r��

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
	cout << "\nIn printValues:\ninteger1 = " << integer1 << "\nPI = "  // integer1 : �w�bnamespace function�U�A�����s���Ӧ���
		<< PI << "\nE = " << E << "\ndoubleInUnnamed = " // doubleInUnnamed : �ݩ󥼩w�q�R�W�Ŷ��������A�i�����s���A�Ӥ��o�ͽĬ�
		<< doubleInUnnamed << "\n(global) integer1 = " << ::integer1   // ::integer1 : �bnamespace function�U�s�������ܼ�
		<< "\nFISCAL3 = " << Inner::FISCAL3 << endl;   // // Inner : �w�bnamespace function�U�A�����s���Ӥ��R�W�Ŷ�
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
	typedef void (Test::*Func)(); // �إߥi�H���VTest����ƫ��Ы��A(Func)
	Func funcObject = &Test::func; // �N�쥻Test��������Ʀ�}�A���w����ƫ����ܼ�funcObject
	(ptr->*funcObject)(); // ->* :�ΨөI�s���A�����禡
	
} // end arrowStar

  // access members of Test object data member using .*
void dotStar(Test *ptr)
{
	typedef int Test::*Value; // �إߥi�H���VTest���������Ы��A(Value)
	Value v = &Test::value; // // �N�쥻Test��������}�A���w�����������ܼ�v
	cout << *ptr.*v << endl; // .* : �ΨӦs�����A��Ʀ���

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

	// �L�X�즳����l�ƪ���
	cout << "Object base1 contains integer " << base1.getData()
		<< "\nObject base2 contains character " << base2.getData()
		<< "\nObject derived contains:\n" << derived << "\n\n";

	// �z�L.�B��l�������w���O�����禡
	cout << "Data members of Derived can be accessed individually:"
		<< "\n    Integer: " << derived.Base1::getData()
		<< "\n  Character: " << derived.Base2::getData()
		<< "\nReal number: " << derived.getReal() << "\n\n";
	cout << "Derived can be treated as an object of either base class:\n";

	// �Nderived���󪺦�}���w��base1��pointer
	base1Ptr = &derived;
	cout << "base1Ptr->getData() yields " << base1Ptr->getData() << '\n';

	// �Nderived���󪺦�}���w��base2��pointer
	base2Ptr = &derived;
	cout << "base2Ptr->getData() yields " << base2Ptr->getData() << endl;
}

void multipleInheritTest2()
{
	Multiple both; // instantiate Multiple object
	DerivedOne one; // instantiate DerivedOne object
	DerivedTwo two; // instantiate DerivedTwo object
	Base *array[3]; // create array of base-class pointers

	// �]both�~�Ӧh�Ӱ����O�A�ҥH�૬�������O�|�o�ͽsĶ���~

	// ��ϥε����~�ӮɡA�u�|�d�U�@�Ӱ����O�A
	// �G�૬�ɤ��|�o�Ϳ��~
	array[0] = &both; 
	array[1] = &one;
	array[2] = &two;

	// polymorphically invoke print
	for (int i = 0; i < 3; i++)
		array[i]->print();
			
}
