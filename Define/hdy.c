/*
#include<stdio.h>
#include<stdlib.h>
#include"hdy.h"//调用宏定义函数
int main ()
{
	int x=0,y=0;
	printf("输入x,y:");
	scanf("%d%d",&x,&y);
    if(x==0)
		printf("x为0\n");

	while(1)
	{
		#if x<0//为何#if判断x<0 不准确?#if后可不用（）
		{
		printf("重新输入x:");
		scanf("%d",&x);
		}
		#else//#else #if...#endif等同于#elif...
		#if(x==0)//为何#if判断x==0 不准确?
			printf("***************\n");break;
		#else
		  break;	
		#endif
		#endif
	}

#ifdef MIX//如果此宏定义了则
	printf("输出MIX=%d\n",MIX(x,y));
#else
	printf("未定义宏\n");
#endif

#undef MIX//使宏MIX无效，即取消定义

#ifndef MIX//如果未定义此宏
	printf("此处重新定义宏\n");
#define MIX(x,y) ((x)*(y))//带参数定义宏
#else
	printf("输出mix=%d\n",MIX(x,y));
#endif

  printf("输出MIX=%d\n",MIX(x,y));
	system("pause");
	return 0;
}*/


#include<stdio.h>
#include<stdlib.h>
#define UPPERCASE 1
int main()
{
	int i=0;
	char *str ="c pROGRAM";
	char ch;
	while((ch=str[i])!='\0')//判断是否为终止字符
	{
		i++;
#if UPPERCASE
    if(ch>='a'&&ch<='z')//小写转化成大写
        ch-=32;
	else if(ch>='A'&&ch<='Z')//大写转化成小写
		ch+=32;
#endif
	printf("%c",ch);
	}
	printf("\n");
	system("pause");
	return 0;
}

