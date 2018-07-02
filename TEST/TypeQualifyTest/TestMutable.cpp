#include "TestMutable.h"



TestMutable::TestMutable(int v = 0) {
	value = v;
}
int TestMutable::getValue() const
{
	return value++; // increments value
}

