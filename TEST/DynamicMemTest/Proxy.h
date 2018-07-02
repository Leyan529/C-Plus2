#pragma once
class RealObj; //遠端物件
class Proxy //代理類別 => 用來修改遠端物件
{
public:
	Proxy(int);
	void setValue(int); 
	int getValue() const; 
	~Proxy();
private:
	RealObj * ptr;	
};

