#pragma once

#ifndef BITREE_H_INCLUDED
#define BITREE_H_INCLUDED

#include<iostream>
#include <string>
using namespace std;

template<typename T>
class BinaryTreeNode
{
public:
	T value;
	BinaryTreeNode<T>* left_node;
	BinaryTreeNode<T>* right_node;

	BinaryTreeNode() :left_node(nullptr), right_node(nullptr) {};
	BinaryTreeNode(const T &e, BinaryTreeNode* left= nullptr, BinaryTreeNode* right= nullptr) :
		value(e), left_node(left), right_node(right) {};
};

template< typename T>
class BinaryTree
{
private:
	BinaryTreeNode<T> *m_root;
public:
	BinaryTree():m_root(nullptr) {};
	BinaryTree(T data) { m_root = new BinaryTreeNode<T>(data); };
	//C++���м̳�ʱ��������������Ϊ�麯��
	//��������麯������ʹ��ʱ���ܴ�������й©�����⡣
	virtual ~BinaryTree() {
		Destroy3();
		m_root = nullptr;
	};

	/*
	��Դ��
	https://bbs.csdn.net/topics/30355854
	ģ����Ķ������������������һ���ļ��У�����ģ����Ķ���������������ɾ��������෽����
	���Ǹ��߱�����Ӧ������ʲô��������෽����ֻ����ʵ����֮�󣬲Ż����ɾ����������䷽����
	Ҫ���뽫ģ����Ķ������䷽���ֿ�����Ҫ�õ�exprot�ؼ���

	������������֧��exprot������ϰ���ϰ�ģ�嶨�����header�ļ��С�
	*/
	void Destroy3();
};

template<typename T>
void BinaryTree<T>::Destroy3()
{
}

#endif // BITREE_H_INCLUDED


