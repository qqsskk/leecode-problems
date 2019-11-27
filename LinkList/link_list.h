#pragma once
#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_

typedef struct node {
	int data;
	struct node *next;
	node() :data(0), next(nullptr) {}
	node(const int& d) :data(d), next(nullptr) {}
}NODE;

class LinkList
{
private:
	NODE *head;
public:
	LinkList() { head = nullptr; }
	~LinkList() ;
	bool clearSqList();
	bool isEmpty() { return head == nullptr; }
	int Length();
	bool GetElem(int i, int *e);
	int find(const int e);
	bool PriorElem(int cur_e, int *pre_e);
	bool NextElem(int cur_e, int *next_e);
	bool Insert(const int i, const int e);
	bool Delete(int i, int *e);
	NODE * Reverse();
};

/*
��ѭ������
δ���ԣ�Ӧ������ôд��
*/
class SingleCircularLinkedList
{
public:
	SingleCircularLinkedList();
	~SingleCircularLinkedList() {};

	void push_back(const int value);
	void clear();
	

private:
	NODE* head;
	NODE* tail;
	NODE* cur;
};

#pragma region Ӧ����

void josephu(int n, int k);

#pragma endregion


#endif // !_LINK_LIST_H_
