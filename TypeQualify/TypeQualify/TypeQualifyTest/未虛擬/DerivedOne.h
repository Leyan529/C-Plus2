#ifndef DERRIVEONE_H
#define DERRIVEONE_H
#include "Base.h"
class DerivedOne : public Base
{
public:
	// override print function
	void print() const
	{
		cout << "DerivedOne\n";
	} // end function print
}; // end class DerivedOne

#endif // !DERRIVEONE_H