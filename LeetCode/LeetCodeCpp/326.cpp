#include "stdafx.h"
#include <vector>
using namespace std;

/*
3����
����һ��������дһ���������ж����Ƿ��� 3 ���ݴη���

ʾ�� 1:

����: 27
���: true
ʾ�� 2:

����: 0
���: false
ʾ�� 3:

����: 9
���: true
ʾ�� 4:

����: 45
���: false
���ף�
���ܲ�ʹ��ѭ�����ߵݹ�����ɱ�����
*/
class Solution {
private:
	bool method1(int n)
	{
		if (n <= 1) {
			return n >= 1;
		}
		while (n % 3 == 0) {
			n /= 3;
		}
		return n == 1;
	}

	/*
	���е�int��Χ��3��n������int��Χ����3��n������
	(��3^((int)log3(MAXINT)) =  1162261467)��Լ��
	��3^19=0100 0101 0100 0110 1011 0011 1101 1011
	*/
	bool method2(int n)
	{
		if (n>0) return 1162261467 % n == 0;
		else return false;
	}
public:

	bool isPowerOfThree(int n) {
		return method2(n);
	}
};