#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"PriorityQueue,h.h"

void InitPriorityQueue(PriorityQueue* q, Compare com)
{
	q->_heap._data = (type*)malloc(sizeof(type)*3);//开辟3个空间
	q->_heap._capacity = 3;
	q->_heap._size = 0;
	q->_heap.com = com;
}

void QueuePush(PriorityQueue* q, type data)
{
	assert(q);
	Insert(&q->_heap,data);//插入
}

void QueuePop(PriorityQueue* q)
{
	Delete(&q->_heap);//删除
}

int QueueSize(PriorityQueue* q)
{
	return HeapSize(&q->_heap);
}
int QueueEmpty(PriorityQueue* q)
{
	return Empity(&q->_heap);
}
type QueueTop(PriorityQueue* q)
{
	 return HeapTop(&q->_heap);
}

void QueueClear(PriorityQueue* q)
{
	 ClearHeap(&q->_heap);//清空
}

void Queue_test()
{
	PriorityQueue q;
	InitPriorityQueue(&q,Less);
    QueuePush(&q,1); 
    QueuePush(&q,5); 
    QueuePush(&q,2); 
    QueuePush(&q,0); 
    QueuePush(&q,4); 

    printf("%d\n",QueueSize(&q)); 
    printf("%d\n",QueueEmpty(&q)); 
    printf("%d\n",QueueTop(&q)); 

    QueuePop(&q);

	printf("%d \n",QueueSize(&q)); 
    printf("%d\n",QueueEmpty(&q)); 
    printf("%d\n",QueueTop(&q));

    QueueClear(&q);
}
