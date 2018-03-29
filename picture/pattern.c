#include<stdio.h>
#include<stdlib.h>
#define N 7//行数
void patter(int n);
int main ()
{
	int n=0;//图形的标记
	n=1;//1表示图形上部分
	patter(n);
	n=2;//22表示图形下部分
	patter(n);
	system("pause");
	return 0;
}
void patter(int n)//打印图像函数
{
	int i=0;//控制行
	int j=0;//控制列
	int k=0;//控制空格
	int a=0;//控制图像的部分，a=i,打印上部分。a=t打印图像下部分。
	int t=N;//由于避免中间重复，打印上部分a=i<N省略最后行，t=N打印下部分时完整。

	for(i=0;i<N;i++,t--)//控制行
	{

		if(n==1)//判断打印那部分
			a=i;
		else
			a=t;

		for(k=N-a;k>0;k--)//控制空格
		{
			printf(" ");
		}

		for(j=a*2-1;j>0;j--)//控制列和打印*
		{
			printf("*");
		}

		printf("\n");//控制换行
	}
	
}