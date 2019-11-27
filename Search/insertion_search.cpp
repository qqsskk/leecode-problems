#include "stdafx.h"
#include<search.h>
#include<math.h>

/*
@brief 3����ֵ����
@����˼��
���ڶ��ֲ����㷨�������ҵ��ѡ��Ľ�Ϊ����Ӧѡ�񣬿�����߲���Ч�ʡ�
��Ȼ����ֵ����Ҳ����������ҡ�

@ע�����ڱ��ϴ󣬶��ؼ��ֲַ��ֱȽϾ��ȵĲ��ұ���˵����ֵ�����㷨
��ƽ�����ܱ��۰����Ҫ�õĶࡣ��֮������������ֲ��ǳ������ȣ���ô��
ֵ����δ���Ǻܺ��ʵ�ѡ��

@���Ӷȷ���
���ҳɹ�����ʧ�ܵ�ʱ�临�ӶȾ�ΪO(log2(log2n))��

@˼��
�ڽ��ܲ�ֵ����֮ǰ�����ȿ���һ�������⣬Ϊʲô�����㷨һ��Ҫ���۰룬
���������ķ�֮һ�����۸����أ�

����ȷ�����Ӣ���ֵ�����顰apple����������ʶ�����ֵ��Ƿ�ǰ�����ҳ
���Ǻ������ҳ�أ����������顰zoo����������ô�飿����Ȼ��������
���Բ����Ǵ��м俪ʼ���𣬶�����һ��Ŀ�ĵ���ǰ�����󷭡�

ͬ���ģ�����Ҫ��ȡֵ��Χ1 ~ 10000 ֮�� 100 ��Ԫ�ش�С������ȷֲ���
�����в���5�� ������Ȼ�ῼ�Ǵ������±��С�Ŀ�ʼ���ҡ�

�������Ϸ������۰�������ֲ��ҷ�ʽ����������Ӧ�ģ�Ҳ����˵��ɵ��ʽ�ģ���
���ֲ����в��ҵ�������£�

mid=(low+high)/2, ��mid=low+1/2*(high-low);

ͨ����ȣ����ǿ��Խ����ҵĵ�Ľ�Ϊ���£�

mid=low+(key-a[low])/(a[high]-a[low])*(high-low)��

Ҳ���ǽ������ı�������1/2�Ľ�Ϊ����Ӧ�ģ����ݹؼ��������������������
��λ�ã���midֵ�ı仯�������ؼ���key������Ҳ�ͼ�ӵؼ����˱Ƚϴ�����

*/
int InsertionSearch(int a[], int value, int low, int high)
{
	//��ʱ��a[high] - a[low]=1���쳣�������ǰ�ж�
	if (low==high&&a[low]==value)
	{
		return low;
	}
	while (low<high)
	{
		//��Ҫ��double���㣬����
		//(value - a[low])*1.0 / (a[high] - a[low])�ܿ�����0
		//������û�и�ֵʱ��offset���������󸺣���ֵ˵��û��
		int offset = (value - a[low])*1.0 / (a[high] - a[low])*(high - low);
		int mid = low + floor(offset);
		if (offset<0)
		{
			return -1;
		}
		if (a[mid] == value)
		{
			return mid;
		}
		if (a[mid] > value)
		{
			high = mid - 1;
		}
		if (a[mid] < value)
		{
			low = mid + 1;
		}
	}
	//˵��û��
	return -1;
}

int InsertionSearch_Recursion(int a[], int value, int low, int high)
{
	if (low>high)
	{
		//˵��û��
		return -1;
	}
	int offset = (value - a[low])*1.0 / (a[high] - a[low])*(high - low);
	int mid = low + floor(offset);
	if (offset<0)
	{
		//˵��û��
		return -1;
	}
	if (a[mid] == value)
		return mid;
	if (a[mid]>value)
		return InsertionSearch_Recursion(a, value, low, mid - 1);
	if (a[mid]<value)
		return InsertionSearch_Recursion(a, value, mid + 1, high);
}