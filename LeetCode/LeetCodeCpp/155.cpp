#include "stdafx.h"
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;

/*
���һ��֧�� push��pop��top �����������ڳ���ʱ���ڼ�������СԪ�ص�ջ��

push(x) -- ��Ԫ�� x ����ջ�С�
pop() -- ɾ��ջ����Ԫ�ء�
top() -- ��ȡջ��Ԫ�ء�
getMin() -- ����ջ�е���СԪ�ء�
ʾ��:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> ���� -3.
minStack.pop();
minStack.top();      --> ���� 0.
minStack.getMin();   --> ���� -2.
*/
class MinStack {
public:
	std::stack<int> data;
	std::stack<int> minValue;

	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		data.push(x);
		/*
		1���յģ�����ֵΪ��С
		2���ǿգ�x <= minValue.top()��ע����=�ţ���Ϊdataջ���ֵ��ջ��
		dataջ����ܻ������ֵ
		*/
		if (minValue.size() <= 0 || x <= minValue.top())
		{
			minValue.push(x);
		}
	}

	void pop() {
		if (minValue.size()>0 && minValue.top() == data.top())
		{
			minValue.pop();
		}
		data.pop();

	}

	int top() {
		return data.top();
	}

	int getMin() {
		return minValue.top();
	}
};
