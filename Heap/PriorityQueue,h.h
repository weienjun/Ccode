//优先级队列---数据使用堆管理
#ifndef __PRIORITYQUEUE_H__
#define __PRIORITYQUEUE_H__

/*
2. 用堆封装优先级队列 
typedef struct PriorityQueue 
{ 
	Heap _heap; 
}PriorityQueue; 

/////////////////////////////////////////// 
void InitPriorityQueue(PriorityQueue* q, Compare com); 
void QueuePush(PriorityQueue* q, DataType data); 

void QueuePop(PriorityQueue* q); 
int QueueSize(PriorityQueue* q); 
int QueueEmpty(PriorityQueue* q); 
DataType QueueTop(PriorityQueue* q); 

3. 用堆的思想实现堆排序 


*/


#include"Heap.h"
//优先级队列
typedef struct PriorityQueue
{
	Heap _heap;
}PriorityQueue;

void InitPriorityQueue(PriorityQueue* q, Compare com); 
void QueuePush(PriorityQueue* q, type data); 
void QueuePop(PriorityQueue* q); 

int QueueSize(PriorityQueue* q); 
int QueueEmpty(PriorityQueue* q); 
type QueueTop(PriorityQueue* q); 
void QueueClear(PriorityQueue* q);

void Queue_test();
#endif
