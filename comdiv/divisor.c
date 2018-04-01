#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num1=0,num2=0;
	int num=0;

	printf("输入两个数:");
	scanf("%d %d",&num1,&num2);
	//求出最小数
	if(num1>num2)
        num=num2;
	else
		num=num1;

	for(num;num>0;num--)//从大到小找出最大公约数
	{
		if((num1%num==0)&&(num2%num==0))
		{
			printf("最大公因数为：%d\n",num);
		    break;
		}
	}
	
	system ("pause");
	return 0;
}
