#pragma once
#ifndef _BITOPERATION_H_
#define _BITOPERATION_H_

class BitOperation
{
public:
	BitOperation();
	~BitOperation();

	bool IsEven(int a);
	int Multiply2(int a);
	int Divide2(int a);
	int SingleNumber(int A[], int n);
	//����temp������������  
	void Swap(int& x, int& y);
};

#endif // !_BITOPERATION_H_
