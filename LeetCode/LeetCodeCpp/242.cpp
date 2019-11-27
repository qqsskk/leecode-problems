#include "stdafx.h"

/*
���������ַ��� s �� t ����дһ���������ж� t �Ƿ��� s ��һ����ĸ��λ�ʡ�

ʾ�� 1:

����: s = "anagram", t = "nagaram"
���: true
ʾ�� 2:

����: s = "rat", t = "car"
���: false
˵��:
����Լ����ַ���ֻ����Сд��ĸ��

����:
��������ַ������� unicode �ַ���ô�죿���ܷ������Ľⷨ��Ӧ�����������
*/
class Solution {
public:
	/*�������ȣ�o(nlogn)*/
	bool method_1(string s, string t)
	{
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		return s == t;
	}

	/*���������,o(n)*/
	bool method_2(string s, string t)
	{
		if (s.size() != t.size())
			return false;

		vector<int> vec(26, 0);
		for (int i = 0;i<s.size();i++)
		{
			vec[s[i] - 'a']++;
			vec[t[i] - 'a']--;
		}
		for (int i = 0;i<vec.size();i++)
		{
			if (vec[i] != 0)
			{
				return false;
			}
		}

		return true;
	}

	bool isAnagram(string s, string t) {
		return method_2(s, t);
	}
};