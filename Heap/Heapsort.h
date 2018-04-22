//堆排序
#ifndef __HEAPSORT_H__

#define __HEAPSORT_H__

#include"Heap.h"

void AdjustSort(Heap* heap,int end);//向下调整至end
void sort(type* arr,size_t sz,Compare com);//堆排序
void sort_test();//堆排序测试

type* HeapTopD(Heap* heap);//取堆顶地址
void test();//海量数据查找最大K个数据


HN* Search(Heap* heap);//查找

#endif