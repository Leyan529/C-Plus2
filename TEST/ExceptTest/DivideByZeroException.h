#ifndef DIVIDE_ZERO
#define DIVIDE_ZERO
#include <stdexcpt.h>
using namespace std;

class DivideByZeroException : public runtime_error {
public:
	DivideByZeroException() :runtime_error("�D�k���s���~") {}
};

#endif // DIVIDE_ZERO