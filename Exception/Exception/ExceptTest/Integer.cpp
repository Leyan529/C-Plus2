#include "stdafx.h"
#include "Integer.h"
#include <iostream>
using namespace std;





Integer::Integer(int i):value(i)
{
	cout << "Constructor for Integer : " << value << endl;
}

Integer::~Integer()
{
	cout << "Destructor for Integer : " << value << endl;
}

void Integer::setInteger(int i)
{
	value = i;
}

int Integer::getInteger() const
{
	return value;
}

