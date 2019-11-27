#include "stdafx.h"

/*
��һ�������������е��������飬ת��Ϊһ�ø߶�ƽ�������������

�����У�һ���߶�ƽ���������ָһ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������ 1��

ʾ��:

������������: [-10,-3,0,5,9],

һ�����ܵĴ��ǣ�[0,-3,9,-10,null,5]�������Ա�ʾ��������߶�ƽ�������������

0
/ \
-3   9
/   /
-10  5
*/
class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.empty()) return nullptr;

		return Insert(nums, 0, nums.size() - 1);
	}

	TreeNode* Insert(vector<int>& nums, int low, int high)
	{
		if (low>high)
		{
			return nullptr;
		}

		int mid = low + round((high - low) / 2.0);
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = Insert(nums, low, mid - 1);
		root->right = Insert(nums, mid + 1, high);
		return root;
	}
};
