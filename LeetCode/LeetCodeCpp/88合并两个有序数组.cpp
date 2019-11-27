#include "stdafx.h"

/*
https://leetcode-cn.com/problems/merge-sorted-array/description/
�������������������� nums1 �� nums2���� nums2 �ϲ��� nums1 �У�ʹ�� num1 ��Ϊһ���������顣

˵��:

��ʼ�� nums1 �� nums2 ��Ԫ�������ֱ�Ϊ m �� n��
����Լ��� nums1 ���㹻�Ŀռ䣨�ռ��С���ڻ���� m + n�������� nums2 �е�Ԫ�ء�
ʾ��:

����:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

���: [1,2,2,3,5,6]
*/
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int size = m + n;
		m--;
		n--;
		for (int i = size - 1;i >= 0;i--)
		{
			if (m<0)
			{
				nums1[i] = nums2[n];
				n--;
			}
			else if (n<0)
			{
				nums1[i] = nums1[m];
				m--;
			}
			else if (nums1[m]>nums2[n])
			{
				nums1[i] = nums1[m];
				m--;
			}
			else
			{
				nums1[i] = nums2[n];
				n--;
			}
		}
	}
};
