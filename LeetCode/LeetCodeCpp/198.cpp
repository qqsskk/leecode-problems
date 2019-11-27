#include"stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݡ�ÿ�䷿�ڶ�����һ�����ֽ�Ӱ����͵�Ե�Ψһ��Լ���ؾ������ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ�������

����һ������ÿ�����ݴ�Ž��ķǸ��������飬�������ڲ���������װ�õ�����£��ܹ�͵�Ե�����߽�

ʾ�� 1:

����: [1,2,3,1]
���: 4
����: ͵�� 1 �ŷ��� (��� = 1) ��Ȼ��͵�� 3 �ŷ��� (��� = 3)��
͵�Ե�����߽�� = 1 + 3 = 4 ��
ʾ�� 2:

����: [2,7,9,3,1]
���: 12
����: ͵�� 1 �ŷ��� (��� = 2), ͵�� 3 �ŷ��� (��� = 9)������͵�� 5 �ŷ��� (��� = 1)��
͵�Ե�����߽�� = 2 + 9 + 1 = 12 ��
*/
class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() <= 1)
			return nums.empty() ? 0 : nums[0];

		vector<int> dp = { nums[0], max(nums[0], nums[1]) };
		for (int i = 2; i < nums.size(); ++i)
		{
			dp.push_back(max(nums[i] + dp[i - 2], dp[i - 1]));
		}
		return dp.back();
	}
};