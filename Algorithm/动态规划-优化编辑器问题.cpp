#include "stdafx.h"
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_set>
using namespace std;

/*
��Ŀ����:
���������ַ���A��B��������Ҫ���в��롢ɾ�����޸Ĳ�����A����ΪB����
����ic��dc��rc�ֱ�Ϊ���ֲ����Ĵ��ۣ������һ����Ч�㷨�������A����ΪB������Ҫ�����ٴ��ۡ�
���������ַ���A��B�������ǵĳ��Ⱥ����ֲ������ۣ��뷵�ؽ�A����ΪB������Ҫ����С���ۡ���֤�������Ⱦ�С�ڵ���300.
1
2
3
4
������:
���ɴ�СΪ(N+1)*(M+1)�ľ���dp. dp[x][y]��ʾAǰx���ַ����༭�� Bǰy���ַ������ѵĴ���.
���ڵ�һ����˵,dp[0][y]��ʾ��һ���մ���ΪB��ǰy���ַ���ɵ��Ӵ�,���ѵĴ���Ϊic*y;
ͬ��,���ڵ�һ��dp[x][0] = x*dc;

����������λ��,dp[x][y]���������¼���ȡֵ:
dp[x-1][y-1]+rc;//A[x-1]!=B[y-1] ��ǰx-1���ַ���ΪBǰy-1���ַ�,�ٽ����һ���ַ��滻.
dp[x-1][y-1];//A[x-1]==B[y-1] ��ǰx-1���ַ���ΪBǰy-1���ַ�,���һ�������޸�.
dp[x-1][y]+dc;//ɾ��һ���ַ�,��ǰx-1���ַ���ΪB��ǰy���ַ�
dp[x][y-1]+ic;//��Aǰx-1���ַ���ΪB��ǰy���ַ�,�ٲ���һ���ַ�
dp[x][y]��ֵ��Ϊ����������С��һ��.
������,dp[n][m]��Ϊ����.
*/
class MinCost {
public:
	int findMinCost(string A, int n, string B, int m, int ic, int dc, int rc)
	{
		vector< vector<int> > dp(n + 1, vector<int>(m + 1, 0));
		for (int i = 1; i <= m; ++i)
			dp[0][i] = ic*i;
		for (int i = 1; i <= n; ++i)
			dp[i][0] = dc*i;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				int case1 = dp[i - 1][j] + dc;
				int case2 = dp[i][j - 1] + ic, case3 = dp[i - 1][j - 1];
				if (A[i - 1] != B[j - 1])
					case3 += rc;
				dp[i][j] = min(min(case1, case2), case3);
			}
		}
		return dp[n][m];
	}
};