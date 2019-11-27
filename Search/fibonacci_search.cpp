/*
4��쳲���������.cpp

@����˼��
Ҳ�Ƕ��ֲ��ҵ�һ�������㷨��ͨ�����ûƽ�����ĸ�����������ѡ����ҵ���в��ң�
��߲���Ч�ʡ�ͬ���أ�쳲���������Ҳ����һ����������㷨��

������۰���ң�һ�㽫���Ƚϵ�keyֵ���mid=��low+high��/2λ�õ�Ԫ�رȽϣ�
�ȽϽ�������������

1����ȣ�midλ�õ�Ԫ�ؼ�Ϊ����
2��>��low=mid+1;
3��<��high=mid-1��

쳲������������۰���Һ����ƣ����Ǹ���쳲��������е��ص���������зָ�ġ�
��Ҫ��ʼ���м�¼�ĸ���Ϊĳ��쳲�������С1����n=F(k)-1;

��ʼ��kֵ���F(k-1)λ�õļ�¼���бȽ�(��mid=low+F(k-1)-1),�ȽϽ��Ҳ��Ϊ����

1����ȣ�midλ�õ�Ԫ�ؼ�Ϊ����
2��>��low=mid+1,k-=2;
˵����low=mid+1˵�������ҵ�Ԫ����[mid+1,high]��Χ�ڣ�
k-=2 ˵����Χ[mid+1,high]�ڵ�Ԫ�ظ���Ϊ
n-(F(k-1))= Fk-1-F(k-1)=Fk-F(k-1)-1=F(k-2)-1
�������Կ��Եݹ��Ӧ��쳲��������ҡ�
3��<��high=mid-1,k-=1��
˵����low=mid+1˵�������ҵ�Ԫ����[low,mid-1]��Χ�ڣ�
k-=1 ˵����Χ[low,mid-1]�ڵ�Ԫ�ظ���ΪF(k-1)-1����
���Կ��Եݹ��Ӧ��쳲��������ҡ�

@���Ӷȷ���
�����£�ʱ�临�Ӷ�ΪO(log2n)�������������Ӷ�ҲΪO(log2n)��
*/

#include "stdafx.h"
#include <memory>
#include  <iostream>
#include<search.h>
using namespace std;

const int max_size = 20;//쳲���������ĳ���

/*����һ��쳲���������*/
void Fibonacci(int * F)
{
	F[0] = 0;
	F[1] = 1;
	for (int i = 2;i<max_size;++i)
		F[i] = F[i - 1] + F[i - 2];
}

/*
@brief 쳲��������ҷ�
@����
para=aΪҪ���ҵ�����
para=nΪҪ���ҵ����鳤
para=keyΪҪ���ҵĹؼ���
*/
int FibonacciSearch(int *a, int n, int key)  
{
	int low = 0;
	int high = n - 1;

	int F[max_size];
	Fibonacci(F);//����һ��쳲���������F 

	int k = 0;
	while (n>F[k] - 1)//����nλ��쳲��������е�λ��
		++k;

	int  * temp;//������a��չ��F[k]-1�ĳ���
	temp = new int[F[k] - 1];
	memcpy(temp, a, n * sizeof(int));

	for (int i = n;i<F[k] - 1;++i)
		temp[i] = a[n - 1];

	while (low <= high)
	{
		int mid = low + F[k - 1] - 1;
		if (key<temp[mid])
		{
			high = mid - 1;
			k -= 1;
		}
		else if (key>temp[mid])
		{
			low = mid + 1;
			k -= 2;
		}
		else
		{
			if (mid<n)
				return mid; //�������˵��mid��Ϊ���ҵ���λ��
			else
				return n - 1; //��mid>=n��˵������չ����ֵ,����n-1
		}
	}
	delete[] temp;
	return -1;
}