#include "stdafx.h"

/*
����һ���ַ��� s�������ͨ�����ַ���ǰ������ַ�����ת��Ϊ���Ĵ����ҵ������ؿ��������ַ�ʽת������̻��Ĵ���

ʾ�� 1:

����: "aacecaaa"
���: "aaacecaaa"
ʾ�� 2:

����: "abcd"
���: "dcbabcd"

*/
/*
������Ҫ��Ӷ��ٸ��ַ�������ַ�����ǰ׺�Ӵ����ĵĳ����йأ�
Ҳ����˵ȥ����ǰ׺�Ļ����Ӵ�������ֻ��Ҫ����ʣ�µ��Ӵ�������
�����ˡ�
�ٸ����ӣ�aacecaaa����ǰ׺���������Ӵ���aacecaa��ʣ����һ��a��
�������ֻ��Ҫ��ǰ�����һ��a������a�����ˡ�

KMP�Ƚ�
*/
class Solution {
public:
	string shortestPalindrome(string s) {
		string str = s;
		reverse(str.begin(), str.end());
		str = s + "#" + str;
		int len1 = s.size(), len2 = str.size();
		vector<int> vec(len2, 0);

		for (int i = 1; i < len2; i++)
		{
			int k = vec[i - 1];
			while (k > 0 && str[k] != str[i])
				k = vec[k - 1];
			k += str[i] == str[k];
			vec[i] = k;
		}

		return str.substr(len1 + 1, len1 - vec[len2 - 1]) + s;
	}
};