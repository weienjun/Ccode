
#ifndef __TEST_H__

#define __TEST_H__

typedef enum{add,sub,mul,_div,data,yk,zk}tech;//�����

typedef enum{Yk=0,Add=1,Sub=1,Mul=2,Div=2,Zk=3}symbol;//�������ȼ���


typedef struct Cell
{
	int size;//�����֣����ַ�
	tech oper;//����
	symbol sy;//���ȼ�
}cell;

cell Reverse_Polishu_Notation(cell * nota,const int size);//�沨�����ʽ
void Kuohao(char * arr);//�����ж�

//void RPN_test();//����
//void Kuohao_test();//����

void change(cell* cur,cell* next,const int size);//��׺ת��׺
void change_test();//����

void Handle(char* ch,cell** chu,size_t sz);//����

#endif