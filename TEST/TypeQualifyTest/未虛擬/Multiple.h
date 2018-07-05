#ifndef MULTIPLE_H
#define MULTIPLE_H
#include "Base.h"
#include "DerivedOne.h"
#include "DerivedTwo.h"

class Multiple : public DerivedOne, public DerivedTwo
{
public:
	// qualify which version of function print
	void print() const
	{
		DerivedTwo::print();
	} // end function print
}; // end class Multiple

#endif // !MULTIPLE_H