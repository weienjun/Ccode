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
	(entry)->_data=MALLOC(type,(entry)->_nsize);//¿ª±Ù¿Õ¼ä
}

void Stack_push(stack * entry,const type data)//Ñ¹Õ»(Î²²å)
{
	if(entry->_size == entry->_nsize)//Õ»Âú
	Stack_add(entry);//Õ»À©Èİ
    entry->_data[entry->_size] = data;
	entry->_size++;
}

void Stack_Pop(stack * entry)//³öÕ»
{
	if(entry->_size == 0 )
		return ;
	entry->_size--;
}

type Stack_Top(stack * entry)//²é¿´Õ»¶¥
{
	assert(entry->_size);//Õ»²»Îª¿Õ
    return entry->_data[entry->_size-1];
}

void Stack_add(stack * entry)//Õ»À©Èİ
{
	type * ptemp=NULL;
	int newsize=(entry)->_nsize*2;
	ptemp=MALLOC(type,newsize);

	if(NULL == ptemp)
	{
		printf("À©ÈİÊ§°Ü£¡\n");
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

int Stack_Empty(stack * entry)//ÅĞ¿Õ
{
	return (0 == entry->_size);
}

void Stack_Delete(stack * entry)//Ïú»Ù
{
	free(entry->_data);//Ïú»ÙÕ»µÄ¿Õ¼ä
	entry = NULL;
}