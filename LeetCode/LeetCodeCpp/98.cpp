#include "stdafx.h"

/*
����һ�����������ж����Ƿ���һ����Ч�Ķ�����������

����һ��������������������������

�ڵ��������ֻ����С�ڵ�ǰ�ڵ������
�ڵ��������ֻ�������ڵ�ǰ�ڵ������
�������������������������Ҳ�Ƕ�����������
ʾ�� 1:

����:
2
/ \
1   3
���: true
ʾ�� 2:

����:
5
/ \
1   4
	/ \
	3   6
���: false
����: ����Ϊ: [5,1,4,null,null,3,6]��
���ڵ��ֵΪ 5 �����������ӽڵ�ֵΪ 4 ��
*/
/**
* Definition for a binary tree node.
*/
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		//��long����int����Ϊ�˰���int�ı߽�����
		return isValidBST(root, LONG_MIN, LONG_MAX);
	}

	bool isValidBST(TreeNode *root, long mn, long mx) {
		if (!root) return true;
		if (root->val <= mn || root->val >= mx) return false;

		bool ret;
		ret = isValidBST(root->left, mn, root->val);
		ret = ret&&isValidBST(root->right, root->val, mx);
		return ret;
	}
};
