#include "stdafx.h"

/*
����һ������ɾ������ĵ����� n ���ڵ㣬���ҷ��������ͷ��㡣

ʾ����

����һ������: 1->2->3->4->5, �� n = 2.

��ɾ���˵����ڶ����ڵ�������Ϊ 1->2->3->5.
˵����

������ n ��֤����Ч�ġ�

���ף�

���ܳ���ʹ��һ��ɨ��ʵ����
*/

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		//n�������֤��Ч����Ҫ�ж�
		//1��n<=0
		//2��n����������
		ListNode* pre = head;
		ListNode* cur = head;
		ListNode* tmp = pre;
		//��Ϊnһ����Ч�����Կ�����ѭ����ô���
		//cur��ǰpreλ��Ϊn
		for (int i = 0;i<n;i++)
		{
			cur = cur->next;
		}
		//curָ���ָ���ʱ��,pre���ǵ�����n��
		while (cur != nullptr&&cur->next != nullptr)
		{
			cur = cur->next;
			pre = pre->next;
		}
		//��������n��
		if (cur == nullptr)
		{
			pre = pre->next;
			delete head;
			head = nullptr;
			return pre;
		}
		//С��n��
		else
		{
			tmp = pre->next;
			pre->next = tmp->next;
			delete tmp;
			tmp = nullptr;
		}

		return head;
	}
};
