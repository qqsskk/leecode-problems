#include "stdafx.h"
#include<iostream>
#include<list>
#include"link_list.h"
using namespace std;

SingleCircularLinkedList::SingleCircularLinkedList()
{
	//�յ���ѭ��������ͷ����д洢��ָ����Ȼָ�������ͷ���
	head = new NODE();
	head->next = head;
	cur = head;
	tail = head;
}

/*
���β�����½��
*/
void SingleCircularLinkedList::push_back(const int value)
{
	NODE *add;

	//β�巨����ѭ������
	add = new NODE(value);
	cur->next = add;
	cur = add;

	//�����һ���������һ���ڵ�ָ��ͷ
	cur->next = head->next;
	tail = head->next;
}

