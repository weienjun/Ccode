//2、乘法口诀表
#include<stdio.h>
#include<stdlib.h>
int main ()
{
	int i;
	int j;
	for(i=1;i<=9;i++)//控制第一个数和行
	{
		for(j=1;j<=i;j++)//控制第二个数
		   printf("%d*%d=%d   ",i,j,i*j);
	    printf("\n");
	}

	system("pause");
	return 0;
}