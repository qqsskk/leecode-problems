#include "stdafx.h"
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;

/*
��дһ�������������ַ��������е������ǰ׺��

��������ڹ���ǰ׺�����ؿ��ַ��� ""��

ʾ�� 1:

����: ["flower","flow","flight"]
���: "fl"
ʾ�� 2:

����: ["dog","racecar","car"]
���: ""
����: ���벻���ڹ���ǰ׺��
˵��:

��������ֻ����Сд��ĸ a-z ��
*/
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string ret = "";
		if (strs.size() == 0)
			return ret;
		else if (strs.size() == 1)
			return strs[0];

		for (int i = 0; i < strs[0].size(); ++i) {
			for (int j = 0; j < strs.size(); ++j) {
				if (strs[0][i] != strs[j][i])
					return ret;
			}
			ret += strs[0][i];
		}
		return ret;
	}
};