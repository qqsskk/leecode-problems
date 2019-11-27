/*
@introduce
�ڲ����ݽṹ���������Red-Black Tree����ƽ����������

�ڲ���Ԫ��ʱ�������Զ����������������У��Ѹ�Ԫ�طŵ��ʵ���λ�ã���ȷ��
ÿ���������ڵ�ļ�ֵ�������������нڵ�ļ�ֵ����С�����������нڵ�ļ�ֵ��
���⣬����ȷ�����ڵ���������ĸ߶����������ĸ߶���ȣ���������������
�߶���С���Ӷ������ٶ���졣

@attention
�����ظ�������ͬ��ֵ��Ԫ�أ�����ȡ���Դ���

@function
c++ stl����set��Ա����:begin()--����ָ���һ��Ԫ�صĵ�����
c++ stl����set��Ա����:clear()--�������Ԫ��
c++ stl����set��Ա����:count()--����ĳ��ֵԪ�صĸ���
c++ stl����set��Ա����:empty()--�������Ϊ�գ�����true
c++ stl����set��Ա����:end()--����ָ�����һ��Ԫ�صĵ�����
c++ stl����set��Ա����:equal_range()--���ؼ����������ֵ��ȵ������޵�����������
c++ stl����set��Ա����:erase()--ɾ�������е�Ԫ��
c++ stl����set��Ա����:find()--����һ��ָ�򱻲��ҵ�Ԫ�صĵ�����
c++ stl����set��Ա����:get_allocator()--���ؼ��ϵķ�����
c++ stl����set��Ա����:insert()--�ڼ����в���Ԫ��
c++ stl����set��Ա����:lower_bound()--����ָ����ڣ�����ڣ�ĳֵ�ĵ�һ��Ԫ�صĵ�����
c++ stl����set��Ա����:key_comp()--����һ������Ԫ�ؼ�ֵ�Ƚϵĺ���
c++ stl����set��Ա����:max_size()--���ؼ��������ɵ�Ԫ�ص������ֵ
c++ stl����set��Ա����:rbegin()--����ָ�򼯺������һ��Ԫ�صķ��������
c++ stl����set��Ա����:rend()--����ָ�򼯺��е�һ��Ԫ�صķ��������
c++ stl����set��Ա����:size()--������Ԫ�ص���Ŀ
c++ stl����set��Ա����:swap()--�����������ϱ���
c++ stl����set��Ա����:upper_bound()--���ش���ĳ��ֵԪ�صĵ�����
c++ stl����set��Ա����:value_comp()--����һ�����ڱȽ�Ԫ�ؼ��ֵ�ĺ���
*/

#include"stdafx.h"
#include<set>
#include<iostream>
#include"stl_demo.h"
using namespace std;

SetDemo::SetDemo()
{
}

SetDemo::~SetDemo()
{
}

void SetDemo::Insert(int* value,int len)
{
	for (int i = 0; i < len; i++)
	{
		s.insert(value[i]);
	}
}

/*
ǰ���������
*/
void SetDemo::IteratorOutput()
{
	//����ǰ�������
	//������������е�����Ԫ��
	for (it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

/*
�����������
*/
void SetDemo::ReverseIteratorOutput()
{
	//����ǰ�������
	//������������е�����Ԫ��
	for (rit = s.rbegin(); rit != s.rend(); rit++)
	{
		cout << *rit << " ";
	}
	cout << endl;
}

/*
ɾ��ĳ��Ԫ��
*/
int SetDemo::ElementDelete(int i)
{
	cout << "before SetDemo::ElementDelete()" << endl;
	this->IteratorOutput();
	s.erase(i);
	return s.size();
}

/*
ɾ��ĳ��Ԫ��
*/
int SetDemo::IteratorElementDelete()
{
	cout << "before SetDemo::ElementDelete()" << endl;
	this->IteratorOutput();
	s.erase(it);
	return s.size();
}

/*
���set
*/
int SetDemo::Clear()
{
	cout << s.size() << endl;
	s.clear();
	cout << s.size() << endl;
	return s.size();
}

/*
��ѯvalue�Ƿ���ڣ������򷵻�һ��������it��itֵΪfing�Ľ��
*/
bool SetDemo::Find(int value)
{
	set<int>::iterator it;
	it = s.find(value); //���Ҽ�ֵΪ6��Ԫ��
	if (it != s.end())
	{
		cout << "Find(" << value << "): " << *it << endl;
		return true;
	}
	else
	{
		cout << "not find it" << endl;
		return false;
	}
}

/*
�ҵ���⣺��ѯvalue������������set�ǲ��ظ��ģ���˵���find��
������result>0����������=0
*/
int SetDemo::Count(int value)
{
	auto result = s.count(value);
	if (!result)
	{
		cout << "does not exist" << endl;
	}
	else
	{
		cout << "Count(" << value << "):" << result << endl;
	}
	return result;
}

bool SetDemo::IsEqual(std::set<int> out)
{
	if (s.size()!=out.size())
	{
		return false;
	}

	std::set<int>::iterator itout;
	itout = out.begin();
	for (it=s.begin(); (it!=s.end())&& (itout!=out.end()); it++, itout++)
	{
		if (*it!=*itout)
		{
			return false;
		}
	}
	return true;
}

std::set<int> SetDemo::GetInnerSet()
{
	return s;
}
