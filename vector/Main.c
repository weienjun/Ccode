#include<stdio.h>
#include<stdlib.h>
#include"Seqlest.h"

int main()
{
	seqlist arr;
	int count=0;
	type data=0;
	int n=0;
	printf("输入初始化个数：");
	scanf("%d",&count);

	Init(&arr,count);//初始化
	printf("初始化后：\n");
	Print(&arr);

	/*
	printf("头删除后\n");
	Head_Delete(&arr);//头删
	Print(&arr);

	printf("尾删除后\n");
	Tail_Delete(&arr);//尾删
	Print(&arr);

	printf("输入插入的位置和数据:");//插入在第几个数位置
	scanf("%d%d",&n,&data);
	printf("第%d数插入%d后\n",n,data);
	Plug(&arr,n,data);
	Print(&arr);

	printf("第%d数删除后\n",n);
	Delete(&arr,n);//删除第几个数
	Print(&arr);

	printf("输入插入的数据:");//尾插
	scanf("%d",&data);
	printf("尾插入%d后\n",data);
	Tail_Plug(&arr,data);
	Print(&arr);

	printf("输入插入的数据:");//头插
	scanf("%d",&data);
	printf("头插入%d后\n",data);
	Head_Plug(&arr,data);
	Print(&arr);

	printf("输入删除的数据:");//删除数据data
	scanf("%d",&data);
	Delete1(&arr,data);
	printf("data删除%d后\n",data);
	Print(&arr);

	printf("输入查找的数据:");//删除数据data
	scanf("%d",&data);
	printf("结果：%d\n",search(&arr,data));//-1表示未找到
	
	
	printf("输入删除的数据:");//删除数据data
	scanf("%d",&data);
	Delete2(&arr,data);
	printf("data删除%d后\n",data);
	Print(&arr);
	*/
	printf("输入删除的数据:");//删除数据data,方法2
	scanf("%d",&data);
	Remove_all(&arr,data);//删除所有数据data
	Print(&arr);

    printf("结果：%d\n",SeqListEmpty(&arr));//判断顺序表是否为空

	system("pause");
	return 0;
}