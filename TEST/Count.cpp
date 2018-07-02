#include "DeepClassTest/Count.h"
#include <iostream>
using namespace std;

void setX(Count &c, int val)
{
	c.x = val; // allowed because setX is a friend of Count
} // end function setX

void Count::print() const
{
	cout << x << endl;
} // end function print
