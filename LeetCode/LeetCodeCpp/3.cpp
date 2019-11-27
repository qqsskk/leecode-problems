#include "stdafx.h"
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;

/*
����һ���ַ������ҳ��������ظ��ַ�����Ӵ��ĳ��ȡ�

ʾ����

���� "abcabcbb" ��û���ظ��ַ�����Ӵ��� "abc" ����ô���Ⱦ���3��

���� "bbbbb" ������Ӵ����� "b" ��������1��

���� "pwwkew" ����Ӵ��� "wke" ��������3����ע��𰸱�����һ���Ӵ���"pwke" �� ������  �������Ӵ���
*/
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		set<char> t;
		int res = 0, left = 0, right = 0;

		while (right < s.size())
		{
			//������ظ�
			if (t.find(s[right]) == t.end())
			{
				t.insert(s[right]);
				right++;
				res = max(res, (int)t.size());
			}
			//���ظ�
			else
			{
				t.erase(s[left]);
				left++;
			}
		}
		return res;
	}
};