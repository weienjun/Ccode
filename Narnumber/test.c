#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int num=0;
	int num1=0;
	int num2=0;
	int num3=0;
	//水仙花数num=(num/%10)^3+((num/10)%10)^3+((num/100)%10)^3,冥函数pow(x,y) x为低，y为冥
	for(num=100;num<=999;num++)
	{
		num1=num%10;
		num2=(num/10)%10;
		num3=(num/100)%10;
		if(num==(pow(num1,3.0)+pow(num2,3.0)+pow(num3,3.0)))
		{
           printf(" %d ",num);
		}
	}
	system("pause");
	return 0;
}