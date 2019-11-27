#pragma once

#ifndef BITREE_H_INCLUDED
#define BITREE_H_INCLUDED

#include<iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

/*
�����ǰ�����������д�ģ����������˹�ѡ��������Һ���
*/
template<typename T>
class BinaryTreeNode
{
public:
	T value;
	BinaryTreeNode<T>* left_node;
	BinaryTreeNode<T>* right_node;

	BinaryTreeNode() :left_node(nullptr), right_node(nullptr) {};
	BinaryTreeNode(const T &e) :value(e), left_node(nullptr), right_node(nullptr){};
	BinaryTreeNode(const T &e, BinaryTreeNode* left, BinaryTreeNode* right) :
		value(e), left_node(left), right_node(right) {};
};
template<typename T>
using SearchTreeNode = BinaryTreeNode<T>;

template< typename T>
class BinaryTree
{
public:
	BinaryTree() :m_root(nullptr) {};
	BinaryTree(T data) { m_root = new BinaryTreeNode<T>(data); };
	//C++���м̳�ʱ��������������Ϊ�麯��
	//��������麯������ʹ��ʱ���ܴ�������й©�����⡣
	virtual ~BinaryTree() {
		Destroy(m_root);
		m_root = nullptr;
	};

	//�ж��Ƿ��ǿ���
	bool IsEmpty() const { return m_root == nullptr ? true : false; };

	BinaryTreeNode<T>* GetRoot() const { return m_root; };

	//����һ��ֵ
	void Insert(const T &value);
	//�����Һ��ӵ���ǰ�ڵ���
	void InsertRightChild(BinaryTreeNode<T> *p, const T &d) const;
	//�������ӵ���ǰ�ڵ���
	void InsertLeftChild(BinaryTreeNode<T> *p, const T &d) const;
	BinaryTreeNode<T>* Remove(const T value, BinaryTreeNode<T>* p);

	//�ڶ��������ҵ�node->value==data
	SearchTreeNode<T>* Find(T data, BinaryTreeNode<T>* node)const;
	//�ڶ��������ҵ���Сֵ
	SearchTreeNode<T>* FindMin(BinaryTreeNode<T>* node)const;
	//�ڶ��������ҵ����ֵ
	SearchTreeNode<T>* FindMax(BinaryTreeNode<T>* node)const;
	//�ڶ��������ҵ����ٽ�ֵ(node->value<=data)
	SearchTreeNode<T>* FindFloor(T data, BinaryTreeNode<T>* node)const;

	//�������������
	void PreOrderTraverse() const;
	//�������������
	void InOrderTraverse() const;
	//�������������
	void PostOrderTraverse() const;
	//����������������ݹ鷨��
	void PreOrderTraverseRecursion() const;
	//����������������ݹ鷨��
	void InOrderTraverseRecursion() const;
	//����������������ݹ鷨��
	void PostOrderTraverseRecursion() const;
	//��α���
	void LevelOrderTraverse() const;
	//��ȡ����
	int GetHeight(BinaryTreeNode<T>* node);
protected:
	//�������������
	virtual void PreOrderTraverse(BinaryTreeNode<T> *root) const;
	//�������������
	virtual void InOrderTraverse(BinaryTreeNode<T> *root) const;
	//�������������
	virtual void PostOrderTraverse(BinaryTreeNode<T> *root) const; 
	//����������������ݹ鷨��
	virtual void PreOrderTraverseRecursion(BinaryTreeNode<T> *root) const;
	//����������������ݹ鷨��
	virtual void InOrderTraverseRecursion(BinaryTreeNode<T> *root) const;
	//����������������ݹ鷨��
	virtual void PostOrderTraverseRecursion(BinaryTreeNode<T> *root) const; 
	//�������������
	virtual void LevelOrderTraverse(BinaryTreeNode<T> *root) const;

	BinaryTreeNode<T>* Destroy(BinaryTreeNode<T> *p);
private:
	BinaryTreeNode<T> *m_root;
};

/*
@brief
���һ���ڵ㵽ԭ����
@���ԭ��
С�ڸ��ڵ��ֵ���������������ڸ��ڵ��ֵ����������
*/
template<typename T>
void BinaryTree<T>::Insert(const T &value)
{
	if (nullptr==m_root)
	{
		m_root = new BinaryTreeNode<T>(value);
		return;
	}

	SearchTreeNode<T>* nearNode = FindFloor(value, m_root);
	SearchTreeNode<T>* next = nullptr;
	if (value < nearNode->value)
	{
		next = new BinaryTreeNode<T>(value);
		nearNode->left_node = next;
	}
	else if (value > nearNode->value)
	{
		next = new BinaryTreeNode<T>(value);
		nearNode->right_node = next;
	}
	else
	{
		return;//�Ѿ����ڵĲ��ظ����
	}
}

template<typename T>
void BinaryTree<T>::InsertRightChild(BinaryTreeNode<T>* p, const T & d) const
{
	BinaryTreeNode<T> *q = new BinaryTreeNode<T>(d);
	q->right_node = p->right_node;
	p->right_node = q;
}

template<typename T>
void BinaryTree<T>::InsertLeftChild(BinaryTreeNode<T>* p, const T & d) const
{
	BinaryTreeNode<T> *q = new BinaryTreeNode<T>(d);
	q->left_node = p->left_node;
	p->left_node = q;
}

/*
@brief ɾ��
@˵��
1��T��Ҷ�ӽڵ㡣
ֱ���ͷŸýڵ�Ŀռ䣬����Ǹ��ڵ㣬��ֱ�Ӹ�ֵΪNULL��
2��T��һ�÷ǿ�������
����Ǹ��ڵ㣬��T��Ψһ������Ϊ���ڵ㣬����Ǹ��ڵ㣬��ʹ�丸�ڵ�ָ���ƹ�
�ýڵ�ָ����Ψһ�ӽڵ㣬�ͷſռ䡣
3��T�����÷ǿ�������
һ������ǽ��ýڵ��Ԫ���滻�����������������Ԫ�ػ�����������СԪ��
�������в��õ��Ǻ��ߣ���������������СԪ���滻��ɾ���Ľڵ㣩��Ȼ����
ɾ�����滻��Ԫ�ء�
*/
template<typename T>
BinaryTreeNode<T>* BinaryTree<T>::Remove(const T data, BinaryTreeNode<T>* node)
{
	BinaryTreeNode<T>* tmpNode;

	if (node == nullptr) 
	{
		return node;
	}
	else if (data < node->value)
	{
		node->left_node = BinaryTree<T>::Remove(data, node->left_node);
	}
	else if (data > node->value) 
	{
		node->right_node = BinaryTree<T>::Remove(data, node->right_node);
	}
	//�ҵ���Ԫ�أ���ʼɾ��
	else if (node->left_node != nullptr && node->right_node != nullptr)
	{
		//���������������
		tmpNode = BinaryTree<T>::FindMin(node->right_node);
		node->value = tmpNode->value;
		node->right_node = BinaryTree<T>::Remove(node->value, node->right_node);
	}
	else 
	{
		//��һ����û�����������
		tmpNode = node;
		//�ƹ���ɾ���Ľڵ�
		if (node->left_node == nullptr)
		{
			node = node->right_node;
		}  
		else if (node->right_node == nullptr)
		{
			node = node->left_node;
		}
		delete tmpNode;
		tmpNode = nullptr;
	}

	return node;
}

template<typename T>
SearchTreeNode<T> * BinaryTree<T>::Find(T data, BinaryTreeNode<T>* node) const
{
	if (node ==nullptr)
	{
		return nullptr;
	}

	if (data== node->value)
	{
		return node;
	}
	else if(data<node->value)
	{
		return Find(data, node->left_node);//С�ڸ��ڵ����������
	}
	else
	{
		return Find(data, node->right_node);//���ڸ��ڵ�����Һ�����
	}
}

template<typename T>
SearchTreeNode<T>* BinaryTree<T>::FindMin(BinaryTreeNode<T>* node) const
{
	if (node==nullptr)
	{
		return nullptr;
	}

	////�ݹ�ʵ��
	//if (node->left_node==nullptr)
	//{
	//	return node;
	//}
	//else
	//{
	//	return FindMin(node->left_node);
	//}

	while (node->left_node!=nullptr)
	{
		node = node->left_node;
	}
	return node;
}

template<typename T>
SearchTreeNode<T>* BinaryTree<T>::FindMax(BinaryTreeNode<T>* node) const
{
	if (node == nullptr)
	{
		return nullptr;
	}

	while (node->right_node != nullptr)
	{
		node = node->right_node;
	}
	return node;
}

template<typename T>
SearchTreeNode<T>* BinaryTree<T>::FindFloor(T data, BinaryTreeNode<T>* node) const
{
	if (m_root==nullptr)
	{
		return nullptr;
	}
	while (node->left_node!=nullptr|| node->right_node!=nullptr)
	{
		if(data<node->value && node->left_node!=nullptr)
		{
			node = node->left_node;
		}
		else if (data > node->value && node->right_node != nullptr)
		{
			node = node->right_node;
		}
		else 
		{
			return node;
		}
	}
	return node;
}

template<typename T>
void BinaryTree<T>::PreOrderTraverse() const
{
	PreOrderTraverse(m_root);
}

template<typename T>
void BinaryTree<T>::InOrderTraverse() const
{
	InOrderTraverse(m_root);
}

template<typename T>
void BinaryTree<T>::PostOrderTraverse() const
{
	PostOrderTraverse(m_root);
}

template<typename T>
void BinaryTree<T>::PreOrderTraverseRecursion() const
{
	PreOrderTraverseRecursion(m_root);
}

template<typename T>
void BinaryTree<T>::InOrderTraverseRecursion() const
{
	InOrderTraverseRecursion(m_root);
}

template<typename T>
void BinaryTree<T>::PostOrderTraverseRecursion() const
{
	PostOrderTraverseRecursion(m_root);
}

template<typename T>
void BinaryTree<T>::LevelOrderTraverse() const
{
	LevelOrderTraverse(m_root);
}

template<typename T>
int BinaryTree<T>::GetHeight(BinaryTreeNode<T>* node)
{
	int height = 0;

	if (node!=nullptr)
	{
		height++;
		int max_left = GetHeight(node->left_node);
		int max_right = GetHeight(node->right_node);
		height += max(max_left, max_right);
	}

	return height;
}

#pragma region ����

template<typename T>
void BinaryTree<T>::PreOrderTraverse(BinaryTreeNode<T>* curNode) const
{
	stack<BinaryTreeNode<T>*> s;
	BinaryTreeNode<T> *p = curNode;
	while (!s.empty()||p!=nullptr)
	{
		while (p!=nullptr)
		{
			s.push(p);
			cout << " " << p->value << " ";
			p = p->left_node;
		}
		p = s.top();
		s.pop();
		p = p->right_node;
	}
}

template<typename T>
void BinaryTree<T>::InOrderTraverse(BinaryTreeNode<T>* curNode) const
{
	stack<BinaryTreeNode<T>*> s;
	BinaryTreeNode<T> *p = curNode;
	while (!s.empty() || p != nullptr)
	{
		while (p != nullptr)
		{
			s.push(p);
			p = p->left_node;
		}
		p = s.top();
		s.pop();
		cout << " " << p->value << " ";
		p = p->right_node;
	}
}

/*
1����ʵ���˲�������⣬���ַ�ʽ�ı��������Կ����ǵݹ�˼���������
�������ѵ�Ҫ�������������Ϊ�������ķ���״̬��һ�����Ѵ���ĵ㡣
���ǹ۲췢�֣�������������ɺ���һ���Ƿ��������������ʱ���м���
�����
* 1.������Ϊ�� �����ʱ������ֱ�ӷ��ʸ���㣻
* 2 �������Ѿ����ʹ��ˣ����ʱ��������1���ƣ�����ֱ�ӷ��ʸ���㣻
* 3 ��������Ϊ����δ�����ʹ������ʱ�����Ǿͷ��������������ݹ鴦��

2����׼����ʩ��
�ǵݹ�����ı������������õ�ջ������������⣩���������Ҳ�����⡣
�����У�����˼·1��2��3����ȷ��Ҳ������ջ�ṹ�����Ƿ��ʹ���Ԫ�رض�
��ջ��Ԫ�أ���һ����ջ�����Ա�֤��˼�������ĺ���������̣������⣬
������һ������Ľ��������ѷ��ʹ���Ԫ�أ���ջ��Ԫ�����Ƚϡ�
*/
template<typename T>
void BinaryTree<T>::PostOrderTraverse(BinaryTreeNode<T>* curNode) const
{
	if (nullptr == curNode)
	{
		return;
	}

	stack<BinaryTreeNode<T>*> s;
	BinaryTreeNode<T>* p = curNode;
	BinaryTreeNode<T>* pre = nullptr;
	while (!s.empty() || p) 
	{
		//��ȡ��ǰ��ʱ���ĸ��ڵ�������������ӣ�ֱ��һ��Ҷ�ӽڵ��ֻ��right_node�Ľڵ�
		while (p != nullptr)
		{
			s.push(p);
			p = p->left_node;
		}
		//��ʱ���ڵ㣬������Ϊ����ʱ���������û����֧
		BinaryTreeNode<T>* top = s.top();
		//* 1�������ʱ��ͬʱû��right_node����top��һ��Ҷ�ӽڵ㣬ֱ�ӷ��ʸ��ڵ�
		//* 2�������ʱ����right_node��ǰһ��ѭ��ֵһ�������ʾ�������Ѿ��������ˣ�
		//*    ֱ�ӷ��ʸ��ڵ�
		if (top->right_node == nullptr || top->right_node == pre)
		{
			pre = top;
			cout << " " << top->value << " ";
			p = nullptr;
			s.pop();
		}
		//�����ʱ����right_node����δ������
		else 
		{
			p = top->right_node;
		}
	}
}

template<typename T>
void BinaryTree<T>::PreOrderTraverseRecursion(BinaryTreeNode<T>* curNode) const
{
	if (nullptr == curNode)
	{
		return;
	}
	cout << " " << curNode->value << " ";

	PreOrderTraverse(curNode->left_node);
	PreOrderTraverse(curNode->right_node);
}

template<typename T>
void BinaryTree<T>::InOrderTraverseRecursion(BinaryTreeNode<T>* curNode) const
{
	if (nullptr == curNode)
	{
		return;
	}

	InOrderTraverseRecursion(curNode->left_node);
	cout << " " << curNode->value << " ";
	InOrderTraverseRecursion(curNode->right_node);
}

template<typename T>
void BinaryTree<T>::PostOrderTraverseRecursion(BinaryTreeNode<T>* curNode) const
{
	if (nullptr == curNode)
	{
		return;
	}

	PostOrderTraverseRecursion(curNode->left_node);
	PostOrderTraverseRecursion(curNode->right_node);
	cout << " " << curNode->value << " ";
}

template<typename T>
void BinaryTree<T>::LevelOrderTraverse(BinaryTreeNode<T>* curNode) const
{
	queue<BinaryTreeNode<T>*> q;
	if (nullptr != curNode)
	{
		q.push(curNode);
	}
	while (!q.empty())
	{
		curNode = q.front();
		q.pop();
		cout << " " << curNode->value << " ";
		if (nullptr != curNode->left_node)
		{
			q.push(curNode->left_node);
		}
		if (nullptr != curNode->right_node)
		{
			q.push(curNode->right_node);
		}
	}
	cout << endl;
}

#pragma endregion

template<typename T>
BinaryTreeNode<T>* BinaryTree<T>::Destroy(BinaryTreeNode<T>* p)
{
	if (nullptr != p)
	{
		p->left_node = Destroy(p->left_node);
		p->right_node = Destroy(p->right_node);
		delete p;
		p = nullptr;
	}
	return nullptr;
}

#endif // BITREE_H_INCLUDED
