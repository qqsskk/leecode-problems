// 
//

#include "stdafx.h"
#include"link_list.h"
#include<iostream>
using namespace std;

/*
��������
*/
LinkList::~LinkList()
{
	//�����һ��
	NODE *p = head;
	while (head)
	{
		p = head;
		head = head->next;
		delete(p);
	}
}

/*
��պ�����������һ��
*/
bool LinkList::clearSqList()
{
	NODE *p = head;
	while (head!=nullptr)
	{
		p = head;
		head = head->next;
		delete(p);
	}
	return true;
}

/*
��ȡ������
*/
int LinkList::Length()
{
	NODE *p = head;
	int len = 0;
	while (p != nullptr)
	{
		len++;
		p = p->next;
	}
	return len;
}


/*
@brief
��ȡָ��λ�õ�Ԫ��
@para
para=*e�Ƿ��ص�Ԫ��
*/
bool LinkList::GetElem(int i, int *e)
{
	NODE *p = head;
	int j = 0;
	while (p&&j < i)
	{
		p = p->next;
		j++;
	}
	if (p == NULL) return false;
	*e = p->data;
	return true;
}

/*
����Ԫ��e������ʲôλ�ã��±�λ�ã���0��ʼ��
*/
int LinkList::find(const int e)
{
	int i = 0;
	NODE *p = head;
	while (p != nullptr)
	{
		if (p->data == e)
		{
			return i;
		}
		else 
		{ 
			p = p->next; 
		}
		i++;
	}
	throw new exception("���в�����ָ��Ԫ��");
}

/*
ȡ��һ��Ԫ��
*/
bool LinkList::PriorElem(int cur_e, int *pre_e)
{
	NODE *p = head;
	if (p->data == cur_e) return false;//��ͷ��㣬��������һ��Ԫ��
	while (p->next != nullptr)
	{
		if (p->next->data == cur_e)
		{
			*pre_e = p->data;
			return true;
		}
		else
			p = p->next;
	}
	return false;//�����겻���ڻ���ֻ��һ��ͷ���

}

/*
ȡ��һ��Ԫ��
*/
bool LinkList::NextElem(int cur_e, int *next_e)
{
	NODE *p = head;
	if (head == nullptr || head->next == nullptr) return false;
	while (p->next != nullptr)
	{
		if (p->data == cur_e)
		{
			*next_e = p->next->data;
			return true;
		}
		else
			p = p->next;
	}
	return false;
}

/*
��ָ��λ�ò���Ԫ��e
*/
bool LinkList::Insert(const int i, const int e)
{
	NODE *p = head;
	NODE *s;
	int j = 0;
	if (i == 0)
	{
		s = (NODE *)new NODE[1];
		s->data = e;
		s->next = p;
		head = s;
		return true;
	}
	while (p&&j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (p == NULL)
		return false;//����β��
	s = (NODE *)new NODE[1];
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

/*
ɾ��ָ��λ�õ�Ԫ�أ�����ɾ����Ԫ�ظ���*e
*/
bool LinkList::Delete(int i, int *e)
{
	NODE *p = head, *s;
	if (p == NULL) return false;
	int j = 0;
	if (i == 0)
	{
		head = head->next;
		*e = p->data;
		delete p;
		p = NULL;
		return true;
	}
	while (p&&j < i - 1)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	s = p->next;
	p->next = p->next->next;
	*e = s->data;
	delete s;
	s = NULL;
	return true;
}

/*
��תһ������
*/
NODE* LinkList::Reverse()
{
	if (head == nullptr || head->next == nullptr)
	{
		return head;
	}

	NODE *pre = head, *cur = head->next, *next;
	head->next = nullptr;

	while (cur!=nullptr)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	head = pre;
	return head;
}