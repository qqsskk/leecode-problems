#include "stdafx.h"
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version)
{
	return version >= 1792997410;
}

class Solution {
public:
	int BinarySearch(int n)
	{
		int low, high, mid;
		low = 1;
		high = n;
		while (low <= high)
		{
			//���֣��۰룩����mid=low+1/2*(high-low);
			mid = low + (high - low) / 2;
			if (isBadVersion(mid) == true)
			{
				//˵����һ��û�У������������յ�
				high = mid - 1;
			}
			else
			{
				//˵��ǰһ��û�У��������������
				low = mid + 1;
			}
		}
		//˵��û��
		return low;
	}

	int firstBadVersion(int n) {
		return BinarySearch(n);
	}
};

/*
//��ӽ�int�ӷ������
//0x7FFF FFFF + 0x7FFF FFFF = 0xFFFF FFFE
*/
int test_278(int n)
{
	Solution s;
	int bad = s.firstBadVersion(n);
	cout << " " << bad << " " << endl;
	return bad;
}