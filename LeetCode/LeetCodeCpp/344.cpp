#include "stdafx.h"
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;

/*
���дһ���������书���ǽ�������ַ�����ת������

ʾ����

���룺s = "hello"
���أ�"olleh"
*/

class Solution {
public:
	string reverseString(string s) {
		int left = 0, right = s.size() - 1;
		while (left < right)
		{
			char t = s[left];
			s[left++] = s[right];
			s[right--] = t;
		}
		return s;
	}
};