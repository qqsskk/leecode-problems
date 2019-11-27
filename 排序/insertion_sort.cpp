#include "stdafx.h"
#include "sort.h"
#include<math.h>
using namespace std;

/*
@brief ֱ�Ӳ�������
@����˼��
�ͽ�������ͬ���������ý��н���������������һ����ʱ�����洢��ǰֵ��
��ǰ���Ԫ�رȺ����ʱ���ȰѺ����Ԫ�ش�����ʱ������ǰ��Ԫ�ص�ֵ�ŵ�����Ԫ��
λ�ã��ٵ�������ֵ���뵽���ʵ�����λ�á�

@����
�ʱ�临�Ӷ�Ϊ����Ϊ����ʱ��ΪO(n^2)������ʱ�临�Ӷ�Ϊ��������ʱ��ΪO(n)��
ƽ��ʱ�临�Ӷ�ΪO(n^2)�������ռ�O(1)���ȶ��ԣ��ȶ���
*/
void InsertionSort(int* data, int length)
{
	int preIndex;
	for (int i = 1; i < length; i++)
	{
		preIndex = i - 1;
		int current = data[i];
		while (preIndex >= 0 && (data[preIndex] > current))
		{
			data[preIndex + 1] = data[preIndex];//��������һλ���ճ��ռ�
			preIndex--;
		}
		data[preIndex + 1] = current;//��ȡ������������С������
	}
}

//    ϣ��������õ�ֱ�Ӳ������򣬵�dk=1ʱ��Ϊֱ�Ӳ�������
//    ���в�������
//    ��ʼʱ��dk��ʼ������ÿ�αȽϲ���Ϊdk
void InsertionSort(int* data, int length,int dk)
{
	int preIndex;
	for (int i = dk; i < length; i++)
	{
		preIndex = i - dk;
		int current = data[i];
		while (preIndex >= 0 && (data[preIndex] > current))
		{
			swap(&data[preIndex+dk], &data[preIndex]);//��������dkλ���ճ��ռ�
			preIndex -= dk;
		}
		data[preIndex + dk] = current;//��ȡ������������С������
	}
}

/*
@brief ���ֲ�������
����Ƚϲ����Ĵ��۱Ƚ���������Ļ������Բ��ö��ֲ��ҷ������ٱȽϲ����Ĵ���

// ���� -------------- �ڲ�����
// ���ݽṹ ---------- ����
// ���ʱ�临�Ӷ� ---- O(n^2)
// ����ʱ�临�Ӷ� ---- O(nlogn)
// ƽ��ʱ�临�Ӷ� ---- O(n^2)
// ���踨���ռ� ------ O(1)
// �ȶ��� ------------ �ȶ�
*/
void InsertionSortDichotomy(int* A, int len)
{
	for (int i = 1; i < len; i++)
	{
		int get = A[i];                  // ����ץ��һ���˿���
		int left = 0;                    // ���������ϵ�����������õģ����Կ����ö��ַ�
		int right = i - 1;               // �������ұ߽���г�ʼ��
		while (left <= right)            // ���ö��ַ���λ���Ƶ�λ��
		{
			int mid = (left + right) / 2;
			if (A[mid] > get)
				right = mid - 1;
			else
				left = mid + 1;
		}
		for (int j = i - 1; j >= left; j--)    // ������������λ���ұߵ������������ƶ�һ����λ
		{
			A[j + 1] = A[j];
		}
		A[left] = get;                    // ��ץ�����Ʋ�������
	}
}


/*
@brief ϣ������
@describe
�Ǽ򵥲�������ĸĽ��档ϣ�������ֽ���С��������

����˼��Ϊ��ֱ�Ӳ��������˼��������һ����С����dk,�տ�ʼdk����Ϊn/2��
���в��������������dk=dk/2,�ٽ��в�������ֱ��dkΪ1ʱ������һ�β������򣬴�ʱ�����������

�ʱ�临�Ӷ�ΪO(n^2)������ʱ�临�Ӷ�ΪO(n)��ƽ��ʱ�临�Ӷ�ΪO(n^1.3)�������ռ�O(1)���ȶ��ԣ����ȶ���
ϣ�������ʱ�临�Ӷ���ѡȡ�������йأ�ѡȡ���ʵ������ɼ���ʱ�临�Ӷȡ�

*/
void ShellSort(int* data, int n) 
{
	int dk = n / 2;        //    ���ó�ʼdk
	while (dk >= 1) 
	{
		InsertionSort(data, n, dk);
		dk /= 2;
	} 
}
