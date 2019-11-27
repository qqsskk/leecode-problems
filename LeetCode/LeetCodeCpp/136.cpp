#include "stdafx.h"
using namespace std;

/*
����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�

˵����

����㷨Ӧ�þ�������ʱ�临�Ӷȡ� ����Բ�ʹ�ö���ռ���ʵ����

ʾ�� 1:

����: [2,2,1]
���: 1
ʾ�� 2:

����: [4,1,2,1,2]
���: 4
*/
class Solution {
public:
	int method_1(vector<int>& nums)
	{
		if (nums.size() == 1)
		{
			return nums[0];
		}

		sort(nums.begin(), nums.end());
		for (int i = 0;i<nums.size() - 1;)
		{
			if (nums[i] == nums[i + 1])
			{
				i += 2;
			}
			else
			{
				//�������2�Σ���i=0��i=1һ��һ��
				if (i == 0)
				{
					return nums[i];
				}
				//�����������һ��Ҳ��������һ��
				else if (nums[i] != nums[i - 1])
				{
					return nums[i];
				}
				else
				{
					i++;
				}
			}
		}
		//ǰnums.size()-1������������
		//��ô���һ�����ǵ�����
		return nums[nums.size() - 1];
	}

	int method_2(vector<int>& nums)
	{
		int result = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			result = result ^ nums[i];
		}

		return result;
	}

	int singleNumber(vector<int>& nums) {
		return method_2(nums);
	}
};