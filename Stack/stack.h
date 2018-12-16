#ifndef __STACK_H__

#define __STACK_H__

#define MALLOC(type,num) \
	(type*)malloc(sizeof(type)*num)

#include"Maze.h"//��дextern Pos;
#include"Maze2.h"
#include"test.h"
//typedef char type;//����ƥ��
//typedef Pos* type;//�Թ�
//typedef pos type;

typedef cell type;//���ʽ

typedef struct Stack//��̬˳���
{
	type* _data;//�������
	size_t _size;//���ݸ������±꣨ջ����
	size_t _nsize;//����
}stack;

void Stack_Init(stack * entry);//��ʼ��ջ
void Stack_push(stack * entry,const type data);//ѹջ(β��)
void Stack_add(stack * entry);//ջ����
void Stack_Pop(stack * entry);//��ջ,ɾ��ջ��
type Stack_Top(stack * entry);//�鿴ջ��
int Stack_Empty(stack * entry);//�п�
void Stack_Delete(stack * entry);//����
#endif