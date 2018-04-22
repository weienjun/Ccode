#include<stdio.h>
#include<assert.h>
#include"Queue.h"

void Queue_Init(Queue* q)//初始化
{
	q->front = 0 ;
	q->tail = 0 ;
	q->size = 0 ;
}

void Queue_Puch(Queue* q,const type data)//入队列
{
	if(q->size == N)
	{
		printf("队列已满！\n");
		return ;
	}
	if(q->tail == N)
		q->tail = 0 ;//从头插
	q->data[q->tail++] = data;
	q->size++;
}
type Queue_Front(Queue* q)//出队列
{
	assert(!Queue_Empty(q));//队不为空
	return q->data[q->front];
}

void Queue_Pop(Queue* q)//删除队头
{
	assert(q->size);
	if(q->front == N-1)
		q->front = 0 ;
	q->front++;
	q->size--;
}

size_t Queue_Size(Queue* q)//求元素个数
{
	return q->size; 
}
size_t Queue_Empty(Queue* q)//判空
{
	return q->size == 0 ;
}
