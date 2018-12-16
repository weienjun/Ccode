#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"

void Stack_Init(stack * entry)
{
	(entry)->_size=0;
	(entry)->_nsize=10;
	if((int)(entry)->_nsize <= 0 )
	{
		printf("eorry!\n");
		return ;
	}
//	(*entry)->_data=(type*)malloc(sizeof(type)*(*entry)->_nsize);
	(entry)->_data=MALLOC(type,(entry)->_nsize);//���ٿռ�
}

void Stack_push(stack * entry,const type data)//ѹջ(β��)
{
	if(entry->_size == entry->_nsize)//ջ��
	Stack_add(entry);//ջ����
    entry->_data[entry->_size] = data;
	entry->_size++;
}

void Stack_Pop(stack * entry)//��ջ
{
	if(entry->_size == 0 )
		return ;
	entry->_size--;
}

type Stack_Top(stack * entry)//�鿴ջ��
{
	assert(entry->_size);//ջ��Ϊ��
    return entry->_data[entry->_size-1];
}

void Stack_add(stack * entry)//ջ����
{
	type * ptemp=NULL;
	int newsize=(entry)->_nsize*2;
	ptemp=MALLOC(type,newsize);

	if(NULL == ptemp)
	{
		printf("����ʧ�ܣ�\n");
		exit(0);
	}
	else
	{
		memmove(ptemp,(entry)->_data,sizeof(type)*(entry)->_size);
		free((entry)->_data);
		(entry)->_data=ptemp;
		(entry)->_nsize=newsize;
	}
}

int Stack_Empty(stack * entry)//�п�
{
	return (0 == entry->_size);
}

void Stack_Delete(stack * entry)//����
{
	free(entry->_data);//����ջ�Ŀռ�
	entry = NULL;
}