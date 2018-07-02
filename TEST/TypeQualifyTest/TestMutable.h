#pragma once
class TestMutable
{
public:
	TestMutable(int);
	int getValue() const;
private:
	mutable int value; // mutable member
};

