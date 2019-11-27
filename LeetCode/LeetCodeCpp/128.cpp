#include "stdafx.h"
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_set>
using namespace std;

/*
����һ��δ������������飬�ҳ���������еĳ��ȡ�

Ҫ���㷨��ʱ�临�Ӷ�Ϊ O(n)��

ʾ��:

����: [100, 4, 200, 1, 3, 2]
���: 4
����: ����������� [1, 2, 3, 4]�����ĳ���Ϊ 4��
*/
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		//�ڲ��ǹ�ϣʵ�֣�O(1)�������O(n)
		unordered_set<int> uset;
		for (int num : nums)
			uset.insert(num);

		//������O(n)
		int longest = 0;
		for (int num : uset)
		{
			//����Ѿ���һ�������е���Сֵ��
			if (uset.find(num - 1) == uset.end())
			{
				int cnt = 1;
				//ѭ���ҵ����������Ĵ���
				while (uset.find(num + 1) != uset.end())
				{
					num++;
					cnt++;
				}
				longest = max(longest, cnt);
			}
		}
		return longest;
	}
};