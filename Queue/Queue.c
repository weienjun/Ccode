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
	else
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
void Queue_test()
{
	Queue q ;
	Queue_Init(&q);
	Queue_Puch(&q,1);
	Queue_Puch(&q,2);
	Queue_Puch(&q,3);
	Queue_Puch(&q,4);
	Queue_Puch(&q,5);
	Queue_Puch(&q,6);
	Queue_Puch(&q,7);
	Queue_Puch(&q,8);
	Queue_Puch(&q,9);
	Queue_Puch(&q,10);
	
	printf("%d\n",Queue_Front(&q));
	Queue_Pop(&q);
	Queue_Pop(&q);
	Queue_Pop(&q);
	Queue_Pop(&q);
	Queue_Pop(&q);
	Queue_Pop(&q);
	Queue_Pop(&q);
	Queue_Pop(&q);
	Queue_Pop(&q);
	Queue_Pop(&q);

	printf("%d\n",Queue_Size(&q));
	Queue_Puch(&q,1);
	Queue_Puch(&q,2);
	Queue_Puch(&q,3);

	printf("%d\n",Queue_Front(&q));
	printf("%d\n",Queue_Size(&q));
}