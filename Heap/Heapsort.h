//������
#ifndef __HEAPSORT_H__

#define __HEAPSORT_H__

#include"Heap.h"

void AdjustSort(Heap* heap,int end);//���µ�����end
void sort(type* arr,size_t sz,Compare com);//������
void sort_test();//���������

type* HeapTopD(Heap* heap);//ȡ�Ѷ���ַ
void test();//�������ݲ������K������


HN* Search(Heap* heap);//����

#endif