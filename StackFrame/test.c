#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void light_change(char arr[],int n,int sz);//左旋
void right_change(char arr[],int n,int sz);//右旋
int determin(char arr[],char arr2[],int sz);//判断是否为旋转字符

int main()
{
	char arr[]={"ABCDE"};//目标字符串
	char arr2[]={"BCDEA"};//判断字符串
	int sz=sizeof(arr)/sizeof(arr[0]);
	int n=1;//旋转个数

	char temp[100];//保存原字符串
	strcpy(temp,arr);

	printf("原字符串：%s\n",arr);
	printf("比较值为：%d\n",determin(arr,arr2,sz));//1是旋转字符，0不是旋转字符

	strcpy(arr,temp);//还原字符串
	light_change(arr,n,sz);
	printf("左旋后结果：%s\n",arr);

	strcpy(arr,temp);//还原字符串
	right_change(arr,n,sz);
	printf("右旋后结果：%s\n",arr);

	system("pause");
	return 0;
}

void light_change(char arr[],int n,int sz)//字符串左旋转
{
	char *p=NULL;//用于指向第一个字符
	char *q=NULL;//用于指向下一个字符
	char temp;//用于暂存当前第一个字符
	int i=0;//循环

	while(n)//旋转n个字符，即左移交换n次
	{
	temp=arr[0];//暂存当前第一个字符
	p=arr;//指向当前第一个字符
	q=&arr[1];//用于指向当前第二个字符
	for(i=0;i<sz/2+1;i++)//字符左移
	{
		*p=*q;
		p++;
		q++;
	}//p指向'\0'前一个字符，q指向最后一个字符'\0'
	*p=temp;//给最后个字符（'\0'前一个）赋给一个字符
	n--;
	}
}

void right_change(char arr[],int n,int sz)//右旋
{
    char *p=NULL;//用于指向第一个字符
	char *q=NULL;//用于指向下一个字符
	char temp;//用于暂存当前最后一个字符
	int i=0;//循环

	while(n>0)//旋转n个字符，即左移交换n次进行查找
	{
		{
		//注：'\0'不可旋转，且数组下标从0开始，所以最后个字母下标为sz-2
		temp=arr[sz-2];//暂存当前第最后一个字符
		p=&arr[sz-2];//指向当前最后一个字符
		q=&arr[sz-3];//用于指向当倒数第二个字符
		for(i=0;i<sz/2+1;i++)//字符左移
		{
			*p=*q;
			p--;
			q--;
		}//p指向'\0'前一个字符，q指向最后一个字符'\0'
		*p=temp;//给第一个字符（'\0'前一个）赋最后一个字符
		n--;
		}
	}
}
	
int determin(char arr[],char arr2[],int sz)//判断是否为旋转后的字符串
{
	char *p=NULL;//用于指向第一个字符
	char *q=NULL;//用于指向下一个字符
	char temp;//用于暂存当前第一个字符
	int i=0;//循环
	int n=sz-1;//循环检测，最多除n-1次

	while(n>0)//旋转n个字符，即左移交换n次进行查找
	{
	if(strcmp(arr,arr2)==0)
		return 1;
	else
		{
		temp=arr[0];//暂存当前第一个字符
		p=arr;//指向当前第一个字符
		q=&arr[1];//用于指向当前第二个字符
		for(i=0;i<sz/2+1;i++)//字符左移
		{
			*p=*q;
			p++;
			q++;
		}//p指向'\0'前一个字符，q指向最后一个字符'\0'
		*p=temp;//给最后个字符（'\0'前一个）赋给一个字符
		n--;
		}
	}
	return 0;
}