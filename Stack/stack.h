#ifndef __STACK_H__

#define __STACK_H__

#define MALLOC(type,num) \
	(type*)malloc(sizeof(type)*num)

#include"Maze.h"//或写extern Pos;
#include"Maze2.h"
#include"test.h"
//typedef char type;//括号匹配
//typedef Pos* type;//迷宫
//typedef pos type;

typedef cell type;//表达式

typedef struct Stack//动态顺序表
{
	type* _data;//存放数据
	size_t _size;//数据个数，下标（栈顶）
	size_t _nsize;//容量
}stack;

void Stack_Init(stack * entry);//初始化栈
void Stack_push(stack * entry,const type data);//压栈(尾插)
void Stack_add(stack * entry);//栈扩容
void Stack_Pop(stack * entry);//出栈,删除栈顶
type Stack_Top(stack * entry);//查看栈顶
int Stack_Empty(stack * entry);//判空
void Stack_Delete(stack * entry);//销毁
#endif