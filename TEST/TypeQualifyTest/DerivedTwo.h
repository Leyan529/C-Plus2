#ifndef DERRIVETWO_H
#define DERRIVETWO_H
#include "Base.h"
class DerivedTwo : virtual public Base
{
public:
	// override print function
	void print() const
	{
		cout << "DerivedTwo\n";
	} // end function print
}; // end class DerivedTwo

#endif // !DERRIVETWO_H