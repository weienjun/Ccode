/*
//1.写一个函数返回参数二进制中 1 的个数 
#include<stdio.h>
#include<stdlib.h>

int count_one_bit(int num);

int main()
{
	int num=0;
	int count=0;
	printf("输入数字：");
	scanf("%d",&num);
	count=count_one_bit(num);
	printf("二进制为一的有%d位\n",count);
	system("pause");
	return 0;
}

int count_one_bit(int num)
{
	int n=0;
	int i=0;
	int num1=num;

	while(num1>0)
	{
     num1=num>>i;
	if((num1&1)==1)
	{
		n++;
	}
	i++;
	}
	return n;
}

*/


/*
//2.获取一个数二进制序列中所有的偶数位和奇数位，分别输出二进制序列。 
#include<stdio.h>
#include<stdlib.h>

void bit_search(int num);
int main()
{
	int num=0;
	printf("输入数字：");
	scanf("%d",&num);
	bit_search(num);
	system("pause");
	return 0;
}

void bit_search(int num)
{
	int n1=15;//奇数位下标
	int n2=15;//偶数位下标
	int i=0;//移位变量
	int bit_odd[16]={0};//保存二进制数，奇数位最多有16位（共32位）
	int bit_even[16]={0};
	int num1=num;//移位后数值，用于判断终止

	while(num1>0)
	{
		num1=num>>i;
		if(i%2==0)
		{
		bit_odd[n1]=(num1&1);
		n1--;
		}
		else
		{
			bit_even[n2]=(num1&1);
			n2--;
		}
		i++;
		//n--;
	}
	printf("奇数位二进制：");
	for(i=0;i<16;i++)
	printf("%d",bit_odd[i]);

	printf("\n偶数位二进制：");
	for(i=0;i<16;i++)
	printf("%d",bit_even[i]);
}

*/


/*
//3. 输出一个整数的每一位。 
#include<stdio.h>
#include<stdlib.h>

void bit_print(int num);
int main()
{
	int num=0;
	printf("输入数字:");
	scanf("%d",&num);
	bit_print(num);
	system("pause");
	return 0;

}

void bit_print(int num)
{
	int num1=num;
	int i=0;
	int n=0;//数组下标从0-31
	int bit[32]={0};

	if(num<0)//负数化为正数计算
	{
	num=-num;
	num1=num;
	}

	while(num1>0)
	{
	num1=num>>i;
	bit[n]=num1&1;
	n++;
	i++;
	}

	for(n=i-1;n>=0;n--)
	printf("%d",bit[n]);

}

*/


//两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？ 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int compare(int num1,int num2 );
int main()
{
	int num1=0;
	int num2=0;
	int count=0;

	printf("输入数字num1:");
	scanf("%d",&num1);
	printf("输入数字num2:");
	scanf("%d",&num2);

	count=compare(num1,num2);
	printf("有%d位不同\n",count);

	system("pause");
	return 0;
}

int compare(int num1,int num2)
{
   int i=0;
   int n=0;
   //保证为正数比较，计算机存储的是二进制的补码，正数补码=原码，负数补码=原码取反+1
  // num1=sqrt(pow(num1,2.0));//sqrt开根号函数，qow次方函数
   //num2=sqrt(pow(num2,2.0));

   for(i=0;i<32;i++)
   {
	   if(((num1>>i)&1)!=((num2>>i)&1))//比较位是否相同
		   n++;
   }
   return n;
}


/*

//判断一个数是正数还是负数
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int num=01;
    printf("输入数字：");
	scanf("%d",&num);

	if((num>>31)&1)//32位最高位表示正负数，1表示负数，0表示正数
		printf("负数\n");
	else
		printf("正数\n");

	system("pause");
	return 0;

}

*/

/*

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int num1=3;
	float num2=3.3;
	double num3=3.5;
	printf("整型num1=%d\t单精度浮点型num2=%f\t双精度浮点型num3=%lf\n",num1,num2,num3);

	printf("\n整型除法num1/2=%d\n",num1/2);//整数除法
	printf("整型除以浮点数运算num1/2.0=%d\n",num1/2.0);//（输出整型，浮点数运算）错误结果0
	printf("整数浮点型输出num1/2=%f\n",num1/2);//整型运算，后转换成浮点型数输出
	printf("整数除以浮点型数，浮点型输出num1/2.0=%f\n",num1/2.0);//整型数浮点型运算输出，至少有一变量为浮点型，2.0即为浮点型数//

	printf("\n单精度浮点型运算输出num2/2=%f\n",num2/2);//单精度浮点型除法
	printf("双精度浮点型运算输出num3/2=%lf\n",num3/2);//双精度浮点型除法
	printf("浮点型转换整型运算整型输出(int)num3/2=%d\n",(int)num3/2);//浮点型强制转换成整型除法运算后输出
	printf("浮点型运算整型输出num3/2=%d\n",num3/2);//浮点型除法，转换成整型输出，结果错误

	printf("\n整型取模运算num1%%2=%d\n",num1%2);//取模运算仅能为整运算，注%%表示打印%
	printf("浮点型转换整型取模运算(int)num2%%2=%d\n",(int)num2%2);//整型变量强制转换成整型，变量仅保留整数部分，可进行取模运算
	//printf("%d\n",num2%2);//浮点数不可进行取模运算

	system("pause");
	return 0;
}

*/


///*
//
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int num1=0;
//	int num2=0;
//	int num3=0;
//
//	num2=num1++;//先将num1赋给num2,后num1加1。即num2=0,num1=1;
//	num3=++num2;//先num2加1，后将num2值赋给num3。即num2=1,num3=1;
//
//	printf("num1=%d\tnum2=%d\tnum3=%d\n",num1,num2,num3);
//	system("pause");
//	return 0;
//}
//
///*
