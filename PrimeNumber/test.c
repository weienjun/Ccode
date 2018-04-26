/*

//1~100的素数
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int i = 0;
	int j = 0;
	for(i = 1;i <= 100; i = i+2)//偶数不是素数
	{
		for(j = 2; j < sqrt((float)i); j++)//任何一个数可看作右两数相乘的到，两个数和最小即为两数相同
		//for(j = 2; j < i; j++)
		{
			if(i%j == 0)
			{
				break;
			}
		}
		if(j > sqrt((float)i))//未查找到
		//if(i == j)
	        printf("%d ",i);
	}
	system("pause");
	return 0;
}

*/



//最小公倍数
#include<stdio.h>
#include<stdlib.h>

int MAX_sum(int num1,int num2)//最大公约数
{
	int i = num1;
	if(num1 > num2)
		i = num2;
	for(; i > 0 ;i--)
	{
		if(num2%i == 0 && num1%i == 0)
			return i;
	}
	return 1;
}

//最大公约数
//方法1：辗转相除法；最大的数max%最小的数min = 余数1，最小的数min%余数1=余数2,最小的数为余数1%余数2.，，
//循环余数小于最小的数，最后的数即为结果
//方法2；相减法：最大得数-最小的数=差1，最小的数-差1=差2，最小的数差1-差2，，，
//循环差不为0，最后的数即为结果
//方法3：穷举法，大的数/小的数，小的数--，遍历直到两个数都可被整除，即为最大公约数

//最小公倍数=乘积/最大公约数
int MIN_sum2(int num1,int num2)//最小公倍数
{
	int min = num1;
	int max = num2;
	int num = 0;
	if(num1 > num2)//确定最大最小数
	{
		num = max;
		max = min;
		min = num;
	}

	while(num)//辗转相除
	{
		num = max%min;
		max = min;
		min = num;
	}
	return (num1*num2)/max;
}

int MIN_sum(int num1,int num2)//最小公倍数
{
	int num = 1;
	int i = num1;
	if(num1 > num2)
		i = num2;
	for(i; i > 1;i--)//思考如何优化
	{
		if(num2%i == 0 && num1%i == 0)
		{
			num1 /= i;
			num2 /= i;
			num *= i;
		}
	}
	return (num *= num1*num2);
}

int main()
{
	int num1 = 0;
	int num2 = 0;
	printf("输入num:");
	scanf("%d%d",&num1,&num2);

	printf("%d\n",MAX_sum(num1,num2));

	printf("%d\n",MIN_sum2(num1,num2));
	printf("%d\n",MIN_sum(num1,num2));
	system("pause");
	return 0;
}