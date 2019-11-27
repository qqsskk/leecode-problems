#include "stdafx.h"
#include<search.h>

/*
@brief ���ֲ���
���ֲ��ң��۰���ң���ѭ��д��
@˵��
Ԫ�ر���������ģ�������������Ҫ�Ƚ������������

@����˼��
Ҳ��Ϊ���۰���ң�������������㷨���ø���ֵk�����м���Ĺؼ��ֱȽϣ��м�������α�ֳ������ӱ����������ҳɹ���������ȣ��ٸ���k����м���ؼ��ֵıȽϽ��ȷ����һ�������ĸ��ӱ������ݹ���У�ֱ�����ҵ�����ҽ������ֱ���û�������Ľ�㡣

@���Ӷȷ���
�����£��ؼ��ʱȽϴ���Ϊlog2(n+1)��������ʱ�临�Ӷ�ΪO(log2n)��

@ע:�۰���ҵ�ǰ����������Ҫ�����˳��洢�����ھ�̬���ұ�
һ��������ٱ仯���۰�����ܵõ������Ч�ʡ���������ҪƵ��
ִ�в����ɾ�����������ݼ���˵��ά�����������������С�Ĺ�
�������ǾͲ�����ʹ�á������������ݽṹ��
*/
int BinarySearch(int a[], int value, int n)
{
	int low, high, mid;
	low = 0;  
	high = n - 1;
	while (low <= high)
	{
		//���֣��۰룩����mid=low+1/2*(high-low);
		//��mid=(low+high)/2�����������
		//1/2=0��mid=low+1/2*(high-low)=low
		mid = low + (high - low) / 2;
		if (a[mid] == value)
		{
			//˵����������
			return mid;
		}
		if (a[mid] > value)
		{
			//˵����һ��û�У������������յ�
			high = mid - 1;
		}
		if (a[mid] < value)
		{
			//˵��ǰһ��û�У��������������
			low = mid + 1;
		}
	}
	//˵��û��
	return -1;
}

/*
@brief ���ֲ���
���ֲ��ң��ݹ�汾
*/
int BinarySearch_Recursion(int a[], int value, int low, int high)
{
	if (low>high)
	{
		//˵��û��
		return -1;
	}
	int mid = low + (high - low) / 2;
	if (a[mid] == value)
		return mid;
	if (a[mid]>value)
		return BinarySearch_Recursion(a, value, low, mid - 1);
	if (a[mid]<value)
		return BinarySearch_Recursion(a, value, mid + 1, high);
}