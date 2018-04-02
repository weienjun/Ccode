
/*
//写一个打印任意大小的乘法口诀表函数
#include<stdio.h>
#include<stdlib.h>

void multiply(int num1);
int main()
{
	int num1=0;
	
	printf("输入口诀表大小：");
	scanf("%d",&num1);

	multiply(num1);//打印乘法口诀表函数
    system("pause");
    return 0;
}

void multiply(int num1)
{
	int num=0;//结果
	int i=0,j=0;//控制循环
	
	for(i=1;i<=num1;i++)//控制行
	{
		for(j=1;j<=i;j++)//控制列
		{
			num=i*j;//计算相乘结果
			printf("%d*%d=%-4d",i,j,num);//%-4d表示左对齐，4个字符
		}
		printf("\n");//换行
	}
}

*/

/*

//交换两个数
#include<stdio.h>
#include<stdlib.h>

void exchange(int *num1,int *num2);//通过地址交换两个数的函数
int main()
{
	int num1=0;
	int num2=0;

	printf("输入num1,num2的值：");
	scanf("%d%d",&num1,&num2);

	exchange(&num1,&num2);//通过地址交换两个数
	printf("交换后:num1=%d\tnum2=%d\n",num1,num2);

	system("pause");
	return 0;

}

void exchange(int* num1,int* num2)
{
	*num1=*num1^*num2;
	*num2=*num1^*num2;//num1
	*num1=*num1^*num2;//num2
}

*/

/*
//判断闰年
#include<stdio.h>
#include<stdlib.h>

int leap(int n);//闰年返回1，不是返回0
int main()
{
	int year=0;
	int n=0;
	
	printf("输入年：");
	scanf("%d",&year);
	
	n=leap(year);//闰年返回1，不是返回0

	if(1==n)
		printf("闰年%d\n",year);
	else
		printf("不是闰年！\n");

	system("pause");
	return 0;
}

int leap(int year)
{
	return ((year%400==0)||((year%4==0)&(year%100!=0)));//逻辑运算，成立为1，不成立为0
}

*/



//
//创建一个数组， 
//实现函数init（）初始化数组、 
//实现empty（）清空数组、 
//实现reverse（）函数完成数组元素的逆置。 
//要求：自己设计函数的参数，返回值。 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10//数组大小

void init(int arr[],int sz);//数组初始化
void reverse(int arr[],int sz);//数组逆置
void print(int *parr,int sz);//数组输出
void empty(int arr[],int sz);//数组清空

int main()
{
	int arr[N];

	init(arr,N);
	printf("\n逆置前输出\n");
	print(arr,N);
	reverse(arr,N);//逆置
	printf("\n逆置后输出\n");
	print(arr,N);
	empty(arr,N);//清空,或用函数memset
	//memset(arr,0,sizeof(arr));//数组所有值替换函数memset(数组名，替换数，sizeof(数组名))
	system("pause");
	return 0;
}

void init(int arr[],int sz)
{
	int i=0;
	for(i=0;i<sz;i++)
	{
		printf("输入第%d个值:",i);
		scanf("%d",&arr[i]);
	}
}

void reverse(int arr[],int sz)
{
	int i=0;
	int j=sz-1;//数组大小减一为最大下标

	for(i=0,j=sz-1;i<sz/2;i++,j--)//前后交换只交换一半的次数
	{
		arr[i]=arr[i]^arr[j];//前值与后值交换
		arr[j]=arr[i]^arr[j];
		arr[i]=arr[i]^arr[j];
	}
}

void print(int *parr,int sz)
{
	int i=0;
	for(i=0;i<sz;i++)
	{
		printf("%d  ",*parr);//*parr相当于arr[i]
		parr++;//指向下一地址，为输出下一值做准备
	}
}

void empty(int arr[],int sz)
{
	int i=0;
	for(i=0;i<sz;i++)
		arr[i]=0;//数组清空
}



/*

//判断是否为素数
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int prime_num(int num);
int main()
{
	int num=0;
	int n=0;
	printf("输入数字:");
	scanf("%d",&num);

	n=prime_num(num);
	if(n==1)
		printf("%d是素数\n",num);
	else
		printf("%d不是素数\n",num);

	system("pause");
	return 0;
}

int prime_num(int num)
{
	int i=0;
	for(i=2;i<=sqrt((float)num);i++)//float开根号进行优化
	{
		if(0==num%i)
			return 0;
	}//跳出循环时即num=i，num不是素数
	return 1;
}

*/