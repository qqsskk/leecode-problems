#pragma once
#ifndef _SORT_H_
#define _SORT_H_

#pragma region ͨ��

void swap(int* a,int* b);
bool IsEqual(int* a, const int* b, int length);

#pragma endregion

#pragma region ��������

void BubbleSort(int* data, int length);
void CocktailSort(int* A, int length);
void QuickSort(int* a, int low, int high);

#pragma endregion

#pragma region ѡ������

void SelectSort(int* data, int length);
void HeapSort(int* array, int len);

#pragma endregion

#pragma region ��������

void InsertionSort(int* data, int length);
void InsertionSort(int* data, int length, int dk);
void InsertionSortDichotomy(int* A, int len);
void ShellSort(int *data, int n);

#pragma endregion

#pragma region �鲢����

void MergeSort(int* a, int left, int right);

#pragma endregion


#endif // !_SORT_H_
