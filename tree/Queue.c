#include<stdio.h>
#include<assert.h>
#include"Queue.h"

void Queue_Init(Queue* q)//��ʼ��
{
	q->front = 0 ;
	q->tail = 0 ;
	q->size = 0 ;
}

void Queue_Puch(Queue* q,const type data)//�����
{
	if(q->size == N)
	{
		printf("����������\n");
		return ;
	}
	if(q->tail == N)
		q->tail = 0 ;//��ͷ��
	q->data[q->tail++] = data;
	q->size++;
}
type Queue_Front(Queue* q)//������
{
	assert(!Queue_Empty(q));//�Ӳ�Ϊ��
	return q->data[q->front];
}

void Queue_Pop(Queue* q)//ɾ����ͷ
{
	assert(q->size);
	if(q->front == N-1)
		q->front = 0 ;
	q->front++;
	q->size--;
}

size_t Queue_Size(Queue* q)//��Ԫ�ظ���
{
	return q->size; 
}
size_t Queue_Empty(Queue* q)//�п�
{
	return q->size == 0 ;
}
