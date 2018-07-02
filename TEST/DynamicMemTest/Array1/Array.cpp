#include "Array.h"

#include <iomanip>
#include <iostream>
Array::Array(int arraySize)
{
	size = (arraySize > 0 ? arraySize : 5);
	ptr = new int[size];

	for (int i = 0; i < size; i++)
		ptr[i] = 0;
}

Array::Array(const Array &arrayToCopy):size(arrayToCopy.size)
{
	ptr = new int[size];
	for (int i = 0; i < size; i++)
		ptr[i] = arrayToCopy.ptr[i];
}

Array::~Array()
{
	delete[]ptr;
}

int Array::getSize() const
{
	return size;
}

const Array & Array::operator=(const Array &right) //Overload = �B��l
{
	if (&right!= this) {
		if (size != right.size) {
			delete[]ptr;  //�M�����쥻�O����
			size = right.size;
			ptr = new int[size];
		}
		for (int i = 0; i < size; i++)
			ptr[i] = right.ptr[i];
	}
	return *this;
}

bool Array::operator==(const Array &right) const  //Overload ==�B��l
{
	if (size != right.size)
		return false;
	for (int i = 0; i < size; i++)
		if (ptr[i] != right.ptr[i])
			return false;

	return true;
}

int & Array::operator[](int subscript) //Overload []�B��l
{
	if (subscript < 0 || subscript >= size) {
		cerr << "\nError: Subscript " << subscript << " out of range" << endl;
		exit(1);
	}
	return ptr[subscript];
}

int Array::operator[](int subscript) const //Overload []�B��l
{
	if (subscript < 0 || subscript >= size) {
		cerr << "\nError : Subscript" << subscript << " out of range" << endl;
	}
	exit(1);
	return ptr[subscript];
}

ostream & operator<<(ostream &output, const Array &a)
{
	int i;
	for (i = 0; i < a.size; i++) {
		output << setw(12) << a.ptr[i];
		if ((i + 1) % 4 == 0)
			output << endl;
	}
	if (i % 4 != 0)
		output << endl;
	return output;
}

istream & operator>>(istream & input, Array &a)
{
	for (int i = 0; i < a.size; i++) {
		input >> a.ptr[i];
	}
	return input;
}
