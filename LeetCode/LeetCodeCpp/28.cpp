#include "stdafx.h"

/*
ʵ�� strStr() ������

����һ�� haystack �ַ�����һ�� needle �ַ������� haystack �ַ������ҳ� needle �ַ������ֵĵ�һ��λ�� (��0��ʼ)����������ڣ��򷵻�  -1��

ʾ�� 1:

����: haystack = "hello", needle = "ll"
���: 2
ʾ�� 2:

����: haystack = "aaaaa", needle = "bba"
���: -1
˵��:

�� needle �ǿ��ַ���ʱ������Ӧ������ʲôֵ�أ�����һ���������кܺõ����⡣

���ڱ�����ԣ��� needle �ǿ��ַ���ʱ����Ӧ������ 0 ������C���Ե� strstr() �Լ� Java�� indexOf() ���������
*/
class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty() || haystack == needle) return 0;
		if (haystack.size()<needle.size()) return -1;

		bool flag = false;
		for (int i = 0;i<haystack.size() - needle.size() + 1;i++)
		{
			if (haystack[i] == needle[0])
			{
				flag = true;
				for (int j = 0;j<needle.size();j++)
				{
					if (haystack[i + j] != needle[j])
					{
						flag = false;
						break;
					}
				}
				if (flag)
				{
					return i;
				}
			}
		}
		return -1;
	}
};
