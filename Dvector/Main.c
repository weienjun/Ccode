
#include<stdio.h>
#include<stdlib.h>
#include"Test.h"

int main()
{
	seqlist q;
	type data=0;
	int n=0;
	seq_init(&q);//初始化
	print(&q);

	printf("put search data:");
	scanf("%d",&data);//查找数
	printf("第%d个数\n",seq_search(&q,data));

	printf("put delete data:");
	scanf("%d",&data);
	seq_delete(&q,data);//删除data数
	print(&q);

	printf("put delete data:");
	scanf("%d",&data);
	seq_delete_all(&q,data);//删除所有data
	print(&q);

	printf("put  n and data:");//data位置添加data
	scanf("%d%d",&n,&data);
	seq_put(&q,n,data);
	print(&q);

	seq_clear(&q);//清空

	seq_clearseq(&q);//销毁

	printf("之前容量%d\n",seq_size(&q));
	seq_addsize(&q);//增容
	printf("之后容量%d\n",seq_size(&q));

	seq_clearseq(&q);//销毁

	system("pause");
	return 0;
}


/*

#include<stdio.h>
#include<stdlib.h>

typedef int type;
typedef struct Seqlist//动态顺序表
{
	type * num;//存储数据
	unsigned int size; //统计数据个数
    unsigned int n_size; //容量，一次开辟内存空间大小
}seqlist;

int a;
int b=0;

int main()
{
	seqlist p1;
	seqlist * p2=NULL;
	int i=0;

	type * temp;

	printf("p2=%p\n",p2);
	//printf("p1=%p\n",p1);
	printf("&p1=%p\n",&p1);//结构体首地址。结构体变量的地址在栈上
	printf("&p1.num=%p\n",&p1.num);
	printf("&p2=%p\n",&p2);


	p1.size=0;
	p1.n_size=5;
	scanf("%u",&p1.n_size);
	if((int)p1.n_size <= 0)
	 printf("put eorr!\n");
	else 
	p1.num=(type *)malloc(sizeof(type)*p1.n_size);//为num开辟空间
	if(! p1.num)
	{
		printf("eorr!\n");
		exit(0);
	}

	for(i=0;i<p1.n_size;i++)//初始化num
	{
		p1.num[i]=i;
		p1.size++;
	}

	temp=p1.num;//获取堆上地址
	p2=&p1;//将p1地址赋给p2（栈地址）
	printf("*%d\n",sizeof(p1));
	printf("*%d\n",sizeof(p2));


	printf("%p\n",&p1.num);//存取指向堆上的地址（栈上）（p1.num地址在堆上)

	//p2=(seqlist*)malloc(sizeof(seqlist));
	printf("p2=%p\n",p2);
	printf("p1=%p\n",p1);
	printf("&p1=%p\n",&p1);//结构体首地址。结构体变量的地址在栈上
	printf("&p2=%p\n",&p2);
	printf("%p\n",p1.num);//p1.num为堆上开辟的首地址
	printf("%p\n",&(p1.num[0]));//堆上开辟的第一个元素地址

	printf("%d\n",*p1.num++);//0
	printf("%d\n",*p2->num++);//1

	printf("%d\n",*temp++);//0
	printf("%d\n",*temp++);//1

	printf("%d\n",*p1.num);//2
	//free(p1.num);

	p2=(seqlist *)malloc(sizeof(seqlist));
	p2->num=(type*)malloc(sizeof(type)*3);
	*p2->num=10;

	printf("%p\n",&p2);//存放结构体的地址。该地址在栈上

	printf("p2=%p\n",p2);//结构体的地址（结构体首地址），p2地址在堆上
	printf("%p\n",&p2->num);//取存num的变量地址
	
	printf("%p\n",p2->num);//取num的首地址
	printf("%p\n",&(p2->num[0]));//取num中的第一个元素地址

	printf("%p\n",++p2->num);//num中的第二个元素地址

	printf("%p\n",&p2->size);
	printf("%p\n",&p2->n_size);
	printf("%p\n",++p2);//结构体堆上下一个变量地址

//	printf("%d\n",*p2->num);//1

	system("pause");
	return 0;
}

*/

//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	char *ch="123";
//	//int *a;
//	char *arr[4]={"123","456","789","147"};
//	//a=(int *)malloc(20);
//	//*a=1;
//	//*a=2;
//	//arr[1]="000";
//	char a[20];
//
//	printf("%p\n",arr[1]);
//	arr[1]="000";
//	printf("%p\n",arr[1]);
//
//	printf("%p\n",arr[2]);
//	printf("%s\n",arr[2]);
//
//	printf("pch=%p\n",ch);
//	printf("&ch=%p\n",&ch);
//	ch="1213";
//	printf("ch=%s\n",ch);
//
//	printf("pch=%p\n",ch);
//	printf("&ch=%p\n",&ch);
//	printf("&arr=%p\n",&arr);
//	printf("arr=%p\n",arr);
//	printf("arr[0]=%p\n",arr[0]);
//	printf("&arr[0]=%p\n",&arr[0]);
//
//	printf("arr[1]=%p\n",arr[1]);
//	printf("&arr[1]=%p\n",&arr[1]);
//
//	printf("%p\n",arr[2]);
//
//	free(&a[0]);
//
//	system("pause");
//	return 0;
//}
//
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	
//	int i=0;
//	int arr[5]={1,1,2,3,5};
//
//	for(i=0;i<=10;i++)
//	{
//		printf("****\n");
//		arr[i]=0;
//	}
//
//	system("pause");
//	return 0;
//}