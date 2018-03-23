#include<stdio.h>
#include<stdlib.h>
#define N 9  //队列总个数
#define OVERFLOW 0 //
int Key[N]={4,7,5,9,3,2,6,1,8};//队列
typedef struct LNode
{
	int n;
	struct LNode *next;
}LNode,*num;//LNode=struct LNode代表结构体类型.*num是结构体指针
void Joseph(num p,int m,int x);
void out (num p,int a);
int main()
{
	int i,m;
	num Lhead ,p,q;//结构体变量
	for(i=0;i<9;i++)
		printf("%d ",Key[i]);
	Lhead=(num)malloc(sizeof(LNode));
    if(!Lhead)//内存开辟失败
		return OVERFLOW;
	Lhead->n=Key[0];//指针指向数组首地址
	Lhead->next=NULL;
	p=Lhead;
	for(i=1;i<9;i++)
	{
		if(!(q=(num)malloc(sizeof(LNode))))//内存开辟失败
			return OVERFLOW;//退出
		q->n=Key[i];//给变量赋值
		p->next=q;//p的指向下一个地址为指向新开辟节点
		p=q;//p指向新开辟节点
	}
	p->next=Lhead;//重新让指针p指向头节点
	printf("\n输入第一次计数值m:\n");
	scanf("%d",&m);
	printf("输出的队列是:\n");
	Joseph(p,m,N);
	system("pause");
	return 0;
}
void Joseph(num p,int m,int x)
{
	num q;//临时指针
	int i;
	if(x==0)//数组长为0(结束)
		return ;//退出
	q=p;//指针指向头节点
	m%=x;//判断是否为此轮最后一个
	if(m==0)//是最后一个
		m=x;
	for(i=1;i<=m;i++)
	{
		p=q;//从第一个节点开始遍历到此节点
		q=p->next;
	}
	p->next=q->next;
	i=q->n;//记录此节点中的值
	printf("\n");
	if(q->next==NULL) return;
	printf("删除%d  ",q->n);
	//out(q,x-1);
	free(q);
	
	Joseph(p,i,x-1);//递归，p为头节点，i为所删去中的值，总结点个数-1
}

/*void out(num p,int a)
{
	int i;
	int b[10];
	printf("\n");
	for(i=0;i<=a;i++)
	{
		if(p->n==b[i])continue;
		 b[i]=Key[i];
		printf("%d ",b[i]);

	}
}*/