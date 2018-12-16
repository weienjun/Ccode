
#ifndef __TEST_H__

#define __TEST_H__

typedef enum{add,sub,mul,_div,data,yk,zk}tech;//运算符

typedef enum{Yk=0,Add=1,Sub=1,Mul=2,Div=2,Zk=3}symbol;//符号优先级表


typedef struct Cell
{
	int size;//存数字，或字符
	tech oper;//类型
	symbol sy;//优先级
}cell;

cell Reverse_Polishu_Notation(cell * nota,const int size);//逆波兰表达式
void Kuohao(char * arr);//括号判断

//void RPN_test();//测试
//void Kuohao_test();//测试

void change(cell* cur,cell* next,const int size);//中缀转后缀
void change_test();//测试

void Handle(char* ch,cell** chu,size_t sz);//处理

#endif