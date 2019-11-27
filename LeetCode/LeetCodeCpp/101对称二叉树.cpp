#include "stdafx.h"

/*
����һ����������������Ƿ��Ǿ���ԳƵġ�

���磬������ [1,2,2,3,4,4,3] �ǶԳƵġ�

1
/ \
2   2
/ \ / \
3  4 4  3
����������� [1,2,2,null,3,null,3] ���Ǿ���ԳƵ�:

1
/ \
2   2
\   \
3    3
˵��:

�����������õݹ�͵������ַ������������⣬��ܼӷ֡�
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
	//����1�����ݹ�,���������������
	bool isSame(TreeNode* r0, TreeNode* r1)
	{
		//����������ǿյģ�˵�����
		if (!r0 && !r1) return true;
		//ֻ��һ����
		if (!r0 || !r1) return false;

		bool ret = false;
		if (r0->val == r1->val)
		{
			ret = isSame(r0->left, r1->right);
			ret = ret&&isSame(r0->right, r1->left);
		}
		return ret;
	}

	//����2��������
	bool method_2(TreeNode* root)
	{
		if (!root) return true;   //�����ǶԳƵ�
		stack<TreeNode *> s;
		TreeNode *p = root->left, *q = root->right;
		s.push(p);
		s.push(q);        //��ʹ�ǿսڵ㣬Ҳ�ǿ���push��ջ��ģ�ջ����Ϊ�ա�
		while (!s.empty())
		{
			p = s.top();s.pop();
			q = s.top();s.pop();

			if (!p && !q) continue;            //p��q���ǿսڵ�
			if (!p || !q) return false;        //��һ��Ϊ�գ����Գ�
			if (p->val != q->val) return false;  //ֵ����ȣ����Գ�

			s.push(p->left);s.push(q->right);
			s.push(p->right);s.push(q->left);
		}
		return true;
	}

	bool isSymmetric(TreeNode* root) {
		if (!root) return true;

		return method_2(root);
	}
};