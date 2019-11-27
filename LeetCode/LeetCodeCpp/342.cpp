#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
	bool isPowerOfFour(int num) {
		if (num <= 0) return false;
		if (num & (num - 1)) return false; // ���ж��Ƿ��� 2 �� N �η�
		if (num & 0x55555555) return true; // �ٽ����� 4 �� N �η�������ȥ��
		return false;
	}
};