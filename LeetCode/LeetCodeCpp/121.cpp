#include "stdafx.h"
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;

/*
����һ�����飬���ĵ� i ��Ԫ����һ֧������Ʊ�� i ��ļ۸�

��������ֻ�������һ�ʽ��ף������������һ֧��Ʊ�������һ���㷨�����������ܻ�ȡ���������

ע���㲻���������Ʊǰ������Ʊ��

ʾ�� 1:

����: [7,1,5,3,6,4]
���: 5
����: �ڵ� 2 �죨��Ʊ�۸� = 1����ʱ�����룬�ڵ� 5 �죨��Ʊ�۸� = 6����ʱ��������������� = 6-1 = 5 ��
ע���������� 7-1 = 6, ��Ϊ�����۸���Ҫ��������۸�
ʾ�� 2:

����: [7,6,4,3,1]
���: 0
����: �����������, û�н������, �����������Ϊ 0��
*/
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int size = prices.size();
		if (size<2) return 0;

		//��С�۸���������
		int minPrice = prices[0];
		int ret = 0;
		for (int i = 1;i<size;i++)
		{
			if (prices[i]<minPrice)
			{
				minPrice = prices[i];
			}
			else
			{
				if (prices[i] - minPrice>ret)
				{
					ret = prices[i] - minPrice;
				}
			}
		}
		return ret;
	}
};