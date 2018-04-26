#ifndef __QUEUE_H__

#define  __QUEUE_H__

#define N 10
typedef int type;

typedef struct Queue{
	size_t front;//头位置
	size_t tail;//尾位置
	size_t size;//元素个数
	type data[N];
}Queue;

void Queue_Init(Queue* q);//初始化
void Queue_Puch(Queue* q,const type data);//入队列
type Queue_Front(Queue* q);//出队列
void Queue_Pop(Queue* q);//删除队头
size_t Queue_Size(Queue* q);//求元素个数
size_t Queue_Empty(Queue* q);//判空
void Queue_test();
#endif