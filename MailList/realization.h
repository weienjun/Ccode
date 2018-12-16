#ifdef __REALIZATION_H__

#define __REALIZATION_H__

#endif 

#define N 10

typedef struct	People{//结构体中的成员不可在定义时初始化
	char name[N];
	char gender;
	char number[12];
	char address[20];
	int age;
	struct People *Next;
}people,*Head;

int Menu(people *  head);//菜单
people * creat(people * head);//初始化及添加
void print(const people * head);//输出
people* search(const people * head ,const char *ch);//查找
people* dete(people * temp);//删除
people* sorting(people * head);//排序
people* modify(people * temp);//修改
people* empty(people * head);//清空
void pfile(people * head);//写入文件中
void exchange(people * pend,people * pnext);//交换两个链表内容