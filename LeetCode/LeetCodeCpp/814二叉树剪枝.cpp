#include "stdafx.h"
#include <vector>
using namespace std;

/*
https://leetcode-cn.com/problems/binary-tree-pruning/description/
��������������� root ����������ÿ������ֵҪô�� 0��Ҫô�� 1��

�����Ƴ������в����� 1 ��������ԭ��������

( �ڵ� X ������Ϊ X �����Լ����� X �ĺ����)

ʾ��1:
����: [1,null,0,0,1]
���: [1,null,0,null,1]

����:
ֻ�к�ɫ�ڵ��������������в����� 1 ����������
��ͼΪ���صĴ𰸡�


ʾ��2:
����: [1,0,1,0,0,0,1]
���: [1,null,1,null,1]



ʾ��3:
����: [1,1,0,1,1,0,1,0]
���: [1,1,0,1,1,null,1]



˵��:

�����Ķ���������� 100 ���ڵ㡣
ÿ���ڵ��ֵֻ��Ϊ 0 �� 1 ��
*/
/**
* Definition for a binary tree node.
*/
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};

class Solution {
public:
	/*
	���100���ڵ㣬�����7��
	1��root->val==0�������ڵ���1������֦
	2��root->val==0�������ڵ�û��1����֦
	*/
	TreeNode* pruneTree(TreeNode* root) {
		if (root == nullptr)
		{
			return root;
		}

		//ɾ����������Ҷ�ӽڵ�Ϊ0�ģ�ɾ����ˢ��ԭ��
		root->left = pruneTree(root->left);
		//����������
		root->right = pruneTree(root->right);
		//��-��-��
		if (!root->left && !root->right&&root->val == 0)
		{
			delete root;
			root = nullptr;
		}

		return root;
	}
};