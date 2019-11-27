#include "stdafx.h"

/*
����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��

˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���

ʾ�� 1:

����: "A man, a plan, a canal: Panama"
���: true
ʾ�� 2:

����: "race a car"
���: false
*/
class Solution {
public:
	bool isPalindrome(string s) {
		string tmp = "";
		for (int i = 0;i<s.size();i++)
		{
			if (isdigit(s[i]))
				tmp += s[i];
			else if (isupper(s[i]))
				tmp += s[i] - 'A' + 'a';
			else if (islower(s[i]))
				tmp += s[i];
		}
		if (tmp.size() <= 1) return true;

		int i = 0, j = tmp.size() - 1;
		while (i<j)
		{
			if (tmp[i++] != tmp[j--])
				return false;
		}
		return true;
	}
};