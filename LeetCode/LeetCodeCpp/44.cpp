#include "stdafx.h"
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
����һ���ַ��� (s) ��һ���ַ�ģʽ (p) ��ʵ��һ��֧�� '?' �� '*' ��ͨ���ƥ�䡣

'?' ����ƥ���κε����ַ���
'*' ����ƥ�������ַ������������ַ�������
�����ַ�����ȫƥ�����ƥ��ɹ���

˵��:

s ����Ϊ�գ���ֻ������ a-z ��Сд��ĸ��
p ����Ϊ�գ���ֻ������ a-z ��Сд��ĸ���Լ��ַ� ? �� *��
ʾ�� 1:

����:
s = "aa"
p = "a"
���: false
����: "a" �޷�ƥ�� "aa" �����ַ�����
ʾ�� 2:

����:
s = "aa"
p = "*"
���: true
����: '*' ����ƥ�������ַ�����
ʾ�� 3:

����:
s = "cb"
p = "?a"
���: false
����: '?' ����ƥ�� 'c', ���ڶ��� 'a' �޷�ƥ�� 'b'��
ʾ�� 4:

����:
s = "adceb"
p = "*a*b"
���: true
����: ��һ�� '*' ����ƥ����ַ���, �ڶ��� '*' ����ƥ���ַ��� "dce".
ʾ�� 5:

����:
s = "acdcb"
p = "a*c?b"
����: false
*/

class Solution {
public:
	
	/*
	ֱ��ѭ���жϣ�û��ͨ��
	s="abefcdgiescdfimde"
    p="ab*cd?i*de"
	ʱ��ͨ����Ӧ��ƥ��ڶ���cd���ǵ�һ��
	*/
	bool method1(string s, string p)
	{
		size_t i = 0;
		size_t j = 0;
		string ss, pp;
		bool flag_star = false;
		bool ret = true;
		while (i < s.size() && j<p.size())
		{
			//�ض���ƥ�䵱ǰ�ַ�
			if ('?' == p[j])
			{
				i++;
				j++;
				flag_star = false;
			}
			//ȷ��ƥ�䵽��ǰ�ַ�
			else if (s[i] == p[j])
			{
				i++;
				j++;
				flag_star = false;
			}
			//����*ƥ��
			//**
			//*?
			//*
			//*a
			else if ('*' == p[j])
			{
				flag_star = true;
				//��**תΪ����3�����
				while ('*' == p[j])
				{
					j++;
				}
				if (j == p.size())
				{
					ret = true;
					return ret;
				}
			}
			else
			{
				if (flag_star)
				{
					i++;
					if (i == s.size())
					{
						ret = false;
						return ret;
					}
				}
				else
				{
					ret = false;
					return ret;
				}
			}
		}

		if (i<s.size())
		{
			ret = false;
			return ret;
		}

		while (j<p.size())
		{
			if (p[j] != '*')
			{
				return false;
			}
			j++;
		}

		return ret;
	}

	/*
	��̬�滮����
	*/
	bool method2(string s, string p)
	{
		//p������Ҫƥ�䵽���ַ�����=p����-'*'����
		int cnt_star=0;
		for (auto& it : p)
		{
			if (it == '*')
			{
				cnt_star++;
			}
		}
		if (p.size() - cnt_star > s.size())
			return false;

		vector<bool> vec_s(s.size() + 1);
		vector<vector<bool>> dp(p.size() + 1, vec_s);

		dp[0][0] = true;

		for (size_t i = 1; i <= p.size(); i++)
		{
			//����ÿ��ѭ���ĳ�ֵ�������ǺŲ���������λʱ��ƥ���ַ����ĳ�ֵ��Ϊfalse
			dp[i][0] = dp[i - 1][0] && p[i - 1] == '*';
		}
		for (size_t j = 1; j <= s.size(); j++)
		{
			//��0��pΪ�գ���ʱû�ж�����ƥ�����
			dp[0][j] = false;
		}

		for (size_t i = 1; i <= p.size(); i++)
		{
			for (size_t j = 1; j <= s.size(); j++)
			{
				if (s[j - 1] == p[i - 1]|| p[i - 1] == '?')
				{
					dp[i][j] = dp[i - 1][j - 1];
				}
				else if (p[i-1]=='*')
				{
					//��̬�滮����ʽ���Ǻţ� ��ʾ�Ǻſ���ƥ��
					//0�����������ϴ���ѭ���Ľ��������
					//����������ڸղ���ѭ���Ľ����
					dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
				}
			}
		}

		return dp[p.size()][s.size()];
	}

	bool isMatch(string s, string p) 
	{
		return method2(s, p);
	}
};

bool test_44(string s, string p)
{
	Solution so;
	return so.isMatch(s, p);
}