#include"stdafx.h"
#include<vector>
#include<iostream>
#include"stl_demo.h"
using namespace std;

VectorDemo::VectorDemo()
{
}

VectorDemo::~VectorDemo()
{
}

void VectorDemo::Initial()
{
	//1)���������Ĺ��캯����ʼ��
	//��ʼ��һ��sizeΪ0��vector
	vector<int> a;

	//2)�������Ĺ��캯����ʼ��
	//��ʼ��size,��ÿ��Ԫ��ֵΪĬ��ֵ
	//��ʼ����10��Ĭ��ֵΪ0��Ԫ��
	vector<int> b(10);    
	//��ʼ��size,�������ó�ʼֵ
	//��ʼ����10��ֵΪ1��Ԫ��
	vector<int> c(10,1);

	//3)ͨ�������ַ��ʼ��
	int d[5] = { 1,2,3,4,5 };
	//ͨ������a�ĵ�ַ��ʼ����ע���ַ�Ǵ�0��5������ҿ����䣩
	vector<int> e(d, d + 5);

	//4)ͨ��ͬ���͵�vector��ʼ��
	vector<int> f(5, 1);
	//ͨ��a��ʼ��
	vector<int> g(f);

	//5)ͨ��insert��ʼ��
	//insert��ʼ����ʽ��ͬ���͵ĵ�������Ӧ��ʼĩ���䣨����ҿ����䣩�ڵ�ֵ���뵽vector��
	vector<int> a5(6, 6);
	vector<int> b5;
	//��a[0]~a[2]���뵽b�У�b.size()��0��Ϊ3
	b5.insert(b5.begin(), a5.begin(), a5.begin() + 3);

	//insertҲ��ͨ�������ַ����ʵ�ֲ���
	int a5_2[6] = { 6,6,6,6,6,6 };
	//��a������Ԫ�ز��뵽b��
	b5.insert(b5.begin(), a5_2, a5_2 + 7);

	//���⣬insert�����Բ���m��ֵΪn��Ԫ��
	//��b��ʼλ�ô�����6��6
	b5.insert(b5.begin(), 6, 6);

	//6)ͨ��copy������ֵ
	vector<int> a6(5, 1);
	int a6_2[5] = { 2,2,2,2,2 };
	vector<int> b6(10);

	/*��a��Ԫ��ȫ��������b��ʼ��λ����,ע�⿽��������Ϊa.begin() ~ a.end()������ҿ�������*/
	copy(a6.begin(), a6.end(), b6.begin());

	//��������Ҳ�����������ַ���ɵ�����
	copy(a6_2, a6_2 + 5, b6.begin() + 5);
}

void VectorDemo::Add(int* data,int raw_len,int column_len)
{
	for (size_t i = 0; i < raw_len; i++)
	{
		for (size_t j = 0; j < column_len; j++)
		{
			arr[i].push_back(data[i*column_len +j]);
		}
	}
}

void VectorDemo::ErgodicOutput()
{
	for (size_t i = 0; i < arr.size(); i++)
	{
		for (size_t j = 0; j < arr[0].size();j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}