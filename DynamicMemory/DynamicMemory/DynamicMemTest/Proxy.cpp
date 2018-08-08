#include "stdafx.h"
#include "Proxy.h"
#include "RealObj.h"


Proxy::Proxy(int v) : ptr(new RealObj(v))
{
}

void Proxy::setValue(int v)
{
	ptr->setValue(v);
}

int Proxy::getValue() const
{
	return ptr->getValue();
}

Proxy::~Proxy()
{
	delete ptr;
}
