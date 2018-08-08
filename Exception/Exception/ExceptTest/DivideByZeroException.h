#ifndef DIVIDE_ZERO
#define DIVIDE_ZERO
#include <stdexcpt.h>
using namespace std;

class DivideByZeroException : public runtime_error {
public:
	DivideByZeroException() :runtime_error("«Dªk°£¹s¿ù»~") {}
};

#endif // DIVIDE_ZERO