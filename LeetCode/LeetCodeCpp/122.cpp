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

���һ���㷨�����������ܻ�ȡ�������������Ծ����ܵ���ɸ���Ľ��ף��������һ֧��Ʊ����

ע�⣺�㲻��ͬʱ�����ʽ��ף���������ٴι���ǰ���۵�֮ǰ�Ĺ�Ʊ����

ʾ�� 1:

����: [7,1,5,3,6,4]
���: 7
����: �ڵ� 2 �죨��Ʊ�۸� = 1����ʱ�����룬�ڵ� 3 �죨��Ʊ�۸� = 5����ʱ������, ��ʽ������ܻ������ = 5-1 = 4 ��
����ڵ� 4 �죨��Ʊ�۸� = 3����ʱ�����룬�ڵ� 5 �죨��Ʊ�۸� = 6����ʱ������, ��ʽ������ܻ������ = 6-3 = 3 ��
ʾ�� 2:

����: [1,2,3,4,5]
���: 4
����: �ڵ� 1 �죨��Ʊ�۸� = 1����ʱ�����룬�ڵ� 5 �� ����Ʊ�۸� = 5����ʱ������, ��ʽ������ܻ������ = 5-1 = 4 ��
ע���㲻���ڵ� 1 ��͵� 2 ����������Ʊ��֮���ٽ�����������
��Ϊ��������ͬʱ�����˶�ʽ��ף���������ٴι���ǰ���۵�֮ǰ�Ĺ�Ʊ��
ʾ�� 3:

����: [7,6,4,3,1]
���: 0
����: �����������, û�н������, �����������Ϊ 0��
*/

class Solution {
private:
	int method1(vector<int>& prices)
	{
		int len = prices.size();
		//������2��������һ�齻��
		if (len < 2)
		{
			return 0;
		}

		int sum = 0;
		int buy = -1;
		if (prices[1]>prices[0])
		{
			buy = prices[0];
		}
		for (size_t i = 1; i < len - 1; i++)
		{
			if (prices[i] <= prices[i + 1] && prices[i] <= prices[i - 1])
			{
				//��Сֵ
				buy = prices[i];
			}
			if (prices[i] >= prices[i + 1] && prices[i] >= prices[i - 1])
			{
				//����ֵ
				sum += buy >= 0 ? prices[i] - buy : 0;
				buy = -1;
			}
		}
		if (prices[len - 1]>prices[len - 2])
		{
			sum += buy >= 0 ? prices[len - 1] - buy : 0;
			buy = -1;
		}
		return sum;
	}

	int method2(vector<int>& prices)
	{
		if (prices.empty()) {
			return 0;
		}

		int account = 0;
		for (vector<int>::iterator it = prices.begin() + 1; it != prices.end(); ++it) {
			account += max(*it - *(it - 1), 0);
		}
		return account;
	}
public:
	int maxProfit(vector<int>& prices) {
		return method2(prices);
	}
};

int test_122()
{
	Solution s;
	vector<int> vec({ 2, 1, 2, 0, 1 });
	int profit = s.maxProfit(vec);
	cout << profit << endl;
	return profit;
}