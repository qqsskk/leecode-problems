#include "stdafx.h"

/*
��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�

ʾ����

���룺1->2->4, 1->3->4
�����1->1->2->3->4->4
*/

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;

		ListNode* node1 = l1;
		ListNode* node2 = l2;
		ListNode* ret;
		if (l1->val < l2->val) {
			ret = l1;
			l1 = l1->next; //����Ҫ�У���Ȼ����ÿ������ֻ��һ�����Ĳ������� [2] [1]��ѭ��
		}
		else {
			ret = l2;
			l2 = l2->next;
		}
		ListNode* head = ret;

		while (l1 != nullptr&&l2 != nullptr)
		{
			if (l1->val <= l2->val)
			{
				ret->next = l1;
				ret = ret->next;
				l1 = l1->next;
			}
			else
			{
				ret->next = l2;
				ret = ret->next;
				l2 = l2->next;
			}
		}
		if (l1 != nullptr)
		{
			ret->next = l1;
		}
		else
		{
			ret->next = l2;
		}
		return head;
	}
};
