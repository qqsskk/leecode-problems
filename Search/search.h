#pragma once
#ifndef _SEARCH_H_
#define _SEARCH_H_

//1. ˳�����
int SequenceSearch(int a[], int value, int n);

//2. ���ֲ���
int BinarySearch(int a[], int value, int n);
int BinarySearch_Recursion(int a[], int value, int low, int high);

//3. ��ֵ����
int InsertionSearch(int a[], int value, int low, int high);
int InsertionSearch_Recursion(int a[], int value, int low, int high);

//4. 쳲���������
int FibonacciSearch(int *a, int n, int key);

//5. �������

//6. �ֿ����

//7. ��ϣ����

#endif // !_SEARCH_H_
