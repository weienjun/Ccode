#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int a=0;//要求的数
	int num=0;//结果
	int i=0;//循环变量
	int n=0;//中间变量

	printf("输入要求的数：");
	scanf("%d",&a);

	for(i=1;i<=5;i++)
	{
		n=((pow(10.0,i)-1)/9)*a;
		num+=n;
	}
	printf("%d\n",num);
	system("pause");
	return 0;
}