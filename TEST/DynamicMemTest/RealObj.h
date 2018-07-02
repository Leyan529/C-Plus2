#pragma once
class RealObj
{
public:
	RealObj(int v) :value(v) {}
	void setValue(int v) { value = v; }
	int getValue() const { return value; }
private:
	int value; //hide private data
};

