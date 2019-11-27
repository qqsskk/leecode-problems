#pragma once
#ifndef _MATRIX_UDG_H_
#define _MATRIX_UDG_H_

#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100;

class MatrixUDG {
private:
	char mVexs[MAX];    // ���㼯��
	int mVexNum;             // ������
	int mEdgNum;             // ����
	int mMatrix[MAX][MAX];   // �ڽӾ���

public:
	// ����ͼ(�Լ���������)
	MatrixUDG();
	// ����ͼ(�����ṩ�ľ���)
	MatrixUDG(char vexs[], int vlen, char edges[][2], int elen);
	~MatrixUDG();

	// ���������������ͼ
	void DFS();
	// ����������������������Ĳ�α�����
	void BFS();
	// ��ӡ�������ͼ
	void print();

private:
	// ��ȡһ�������ַ�
	char readChar();
	// ����ch��mMatrix�����е�λ��
	int getPosition(char ch);
	// ���ض���v�ĵ�һ���ڽӶ����������ʧ���򷵻�-1
	int firstVertex(int v);
	// ���ض���v�����w����һ���ڽӶ����������ʧ���򷵻�-1
	int nextVertex(int v, int w);
	// ���������������ͼ�ĵݹ�ʵ��
	void DFS(int i, int *visited);

};

int matrix_udg_main();

#endif // !_MATRIX_UDG_H_
