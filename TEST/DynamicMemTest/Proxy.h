#pragma once
class RealObj; //���ݪ���
class Proxy //�N�z���O => �Ψӭקﻷ�ݪ���
{
public:
	Proxy(int);
	void setValue(int); 
	int getValue() const; 
	~Proxy();
private:
	RealObj * ptr;	
};

