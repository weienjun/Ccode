//���ȼ�����---����ʹ�öѹ���
#ifndef __PRIORITYQUEUE_H__
#define __PRIORITYQUEUE_H__

/*
2. �öѷ�װ���ȼ����� 
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

3. �öѵ�˼��ʵ�ֶ����� 


*/


#include"Heap.h"
//���ȼ�����
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
