#include "stdafx.h"
#include "sort.h"

/*
@brief ��ѡ������
// ���� -------------- �ڲ��Ƚ�����
// ���ݽṹ ---------- ����
// ���ʱ�临�Ӷ� ---- O(n^2)
// ����ʱ�临�Ӷ� ---- O(n^2)
// ƽ��ʱ�临�Ӷ� ---- O(n^2)
// ���踨���ռ� ------ O(1)
// �ȶ��� ------------ ���ȶ�

ѡ�������ǲ��ȶ��������㷨�����ȶ���������СԪ����A[i]������ʱ�̡�
*/
void SelectSort(int* data, int length)
{
	int minIndex = 0;
	for (int i = 0; i < length - 1; i++)
	{
		minIndex = i;
		for (int j = i + 1; j < length; j++)
		{
			if (*(data + j)<*(data + minIndex))
			{
				minIndex = j;
			}
		}
		// �ŵ����������е�ĩβ���ò������п��ܰ��ȶ��Դ��ң�
		// ����ѡ�������ǲ��ȶ��������㷨
		swap((data + i), (data + minIndex));

	}
}

#pragma region ������

void Swap(int A[], int i, int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

void Heapify(int A[], int i, int size)  // ��A[i]���½��жѵ���
{
	int left_child = 2 * i + 1;         // ��������
	int right_child = 2 * i + 2;        // �Һ�������
	int max = i;                        // ѡ����ǰ����������Һ�������֮�е����ֵ
	if (left_child < size && A[left_child] > A[max])
		max = left_child;
	if (right_child < size && A[right_child] > A[max])
		max = right_child;
	if (max != i)
	{
		Swap(A, i, max);                // �ѵ�ǰ�����������(ֱ��)�ӽڵ���н���
		Heapify(A, max, size);          // �ݹ���ã������ӵ�ǰ������½��жѵ���
	}
}

int BuildHeap(int A[], int n)           // ���ѣ�ʱ�临�Ӷ�O(n)
{
	int heap_size = n;
	for (int i = heap_size / 2 - 1; i >= 0; i--) // ��ÿһ����Ҷ��㿪ʼ���½��жѵ���
		Heapify(A, i, heap_size);
	return heap_size;
}

void HeapSort(int* A, int len)
{
	int heap_size = BuildHeap(A, len);    // ����һ������
	while (heap_size > 1)
	{
		// �ѣ���������Ԫ�ظ�������1��δ�������
		// ���Ѷ�Ԫ����ѵ����һ��Ԫ�ػ��������Ӷ���ȥ�����һ��Ԫ��
		// �˴������������п��ܰѺ���Ԫ�ص��ȶ��Դ��ң����Զ������ǲ��ȶ��������㷨
		Swap(A, 0, --heap_size);
		Heapify(A, 0, heap_size);     // ���µĶѶ�Ԫ�ؿ�ʼ���½��жѵ�����ʱ�临�Ӷ�O(logn)
	}
}

#pragma endregion