/*
@brief Լɪ������

n����Χ��һ��Ȧ��ÿ���˷ֱ��עΪ1��2��...��n��Ҫ���1�Ŵ�1��ʼ������
����k���˳�Ȧ��������һ�����ִ�1��ʼ���������ѭ����ֱ��ֻʣ���һ����ʱ��
���˼�Ϊʤ���ߡ����統n=10,k=4ʱ�����γ��е��˷ֱ�Ϊ4��8��2��7��3��10��9��
1��6��5����5��λ�õ���Ϊʤ���ߡ�����n���ˣ������̼�������ʤ���߱������
��Ҫ���õ�ѭ��������ɡ���
*/

#include "stdafx.h"
#include<iostream>
#include<list>
#include"link_list.h"
using namespace std;

/*
@para
n=����
k=��Ҫ���еı���
*/
void josephu(int n,int k)
{
	NODE *head, *cur, *add, *tail;
	head = new NODE();
	cur = head;

	//β�巨����ѭ������
	for (int i = 1;i <= n;i++)
	{
		add = new NODE();
		add->data = i;
		cur->next = add;
		cur = add;
	}

	//�����һ���������һ���ڵ�ָ��ͷ
	cur->next = head->next;
	tail = head->next;

	//��ʼģ�⣨�ж�����Ҫע�⣺��Ϊ���϶�ʣ��һ���ˣ� �������һ�����ݵ�next����������
	while (tail->next != tail)
	{
		for (int i = 1;i<k - 1;i++)
		{
			//ÿk������һ����
			tail = tail->next;
		}
		//���ýڵ��������ɾ����
		tail->next = tail->next->next;
		tail = tail->next;
	}
	cout << "josephu(" << n << "," << k << ") = " << tail->data << endl;
}

