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



void main() {
	//constCastTest();
	const TestMutable test(99);

	cout << "Initial value: " << test.getValue();
	cout << "\nModified value: " << test.getValue() << endl;


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
