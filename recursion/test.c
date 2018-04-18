

/*

//递归打印每一位
#include<stdio.h>
#include<stdlib.h>

void print(int num)//递归输出125->1 2 5

int main()
{
  int num=0;
  printf("put num:");
  scanf("%d",&num);
  print(num);

  system(" pause");
  return 0;
}

//执行流程
//递归是按一层一层的顺序执行的.
//只有当最内层执行结束后才执行上一层未执行的语句，每一层都为递归函数整体，但每层实际都不相同
//下列(num=5)：
//第n次执行表式 print用pn表式
//第n次执行表式 printf用pfn表式
//从外层到内层的顺序执行，只有当最内层执行结束后才接着执行上一层未执行的语句，因此最外层是最后执行结束的。
//(p1->( p2->(p3->(p4->(p5->pf5)->pf4->pf3)pf2)pf1)
//p2->(p3->(p4->(p5->pf5)->pf4->pf3)pf2
//p3->(p4->(p5->pf5)->pf4->pf3
//p4->(p5->pf5)->pf4
//p5->pf5
void print(int num)//num=5
{
 if(num>10)
 {
  print(num/10);//digui. 54321-5432..->5
 }
 printf("%d  ",num%10);//5->4->3->2->1
}

*/


//             change(5)//最终返回5，调用次数为满足条件（返回1）的次数和+1
//              /3+2    \
//	   change(4)         change(3)
//	   /  2+1  \           / 1+1  \
// change(3)  change(2)  change(2) change(1)
//   / 1+1  \     1         1         1
//change(2) change(1)
//   1         1   //返回1结束本次调用   



#include<stdio.h>
#include<stdlib.h>

int change(int num);//递归计算结成
int fbnqs(int num);//递归求第几个数的数值
int fbnqsy(int num);//非递归对斐波那契数（999）取模（10007）
int fbnqs2(int num);//非递归求斐波那契数

int main()
{
 int num=0;
 printf("put num:");
 scanf("%d",&num);
 
 printf("%d \n",change(num));
 printf("%d \n",fbnqs(num));
 printf("%d \n",fbnqs2(num));
 printf("%d \n",fbnqsy(num));

 system("pause");
 return 0;
}

//递归求斐波那契数：1+1+2+3+5+8 ....
int fbnqs(int num)//求第几个数的数值
{
	if(num<=2)//改num < 2
	{
		return 1%1007;
	}
	//return fbnqs(num-1)+fbnqs(num-2);
	return (fbnqs(num-1)+fbnqs(num-2));//斐波那契数取模 ???

	//return (num <= 2) ?  1 : fbnqs(num-1)+fbnqs(num-2);
}

//对一个数取模等同于对构成那个数的每个数取模，
//列：13%3=8%3+3%3+2%3=8%3+(3+2)%3
//为防止每个数取模的和大于模数，所以每两个数取模之和后再次取模，再加上下个数的余数，以此类推求出结果
//存储每个斐波那契数取模后的数而不是斐波那契数
//求斐波那契数取模
int fbnqsy(int num){//对斐波那契数（999）取模（10007）
	int a, b, c, i;
	a = 1;
	b = 1;
	if(num <= 2) return 1;
	for(i = 3; i <= num; i++){
		c = (a + b) %10007;//前两个数的余数+下一个数的余数，
		a = b % 10007;//对取模的两个数再次取模防止之和大于模数,
		b = c;//前两个数的余数，
	}
	return c;
}

//计算一个数的阶乘
int change(int num)//计算结成
{
  if(num==0 || num==1)//num==1时，退出递归 //必须注意num=0时的情况否则程序崩溃
  {
  return num;
  }
  return num*change(num-1);//递归，累乘
}
//非递归求斐波那契数
int fbnqs2(int num)//非递归求斐波那契数
{
	int i=0;
	int a=1;
	int b=1;
	int c=1;

	for(i=3;i<=num;i++)
	{
       c=a+b;//记录第二数值和
	   a=b;//记录第一数值
	   b=c;//记录第三值（结果）
	}
	return c;
}




/*
//递归计算1235->1+2+3+5
#include<stdio.h>
#include<stdlib.h>

int change(int num);//递归计算1235->1+2+3+5

int main()
{
	int num=0;
	int num1=0;

	printf("输入数字：");
	scanf("%d",&num);

	printf("结果为%d\n",change(num));
	system("pause");
	return 0;
}

int change(int num)
{
	static int n=0;
	if(num==0)//退出函数
     return n;
	n+=num%10;//计算求值
	change(num/10);//递归
}

*/


//4. 编写一个函数reverse_string(char * string)（递归实现） 
//实现：将参数字符串中的字符反向排列。 
//要求：不能使用C函数库中 
//的字符串操作函数。 

/*

#include<stdio.h>
#include<stdlib.h>

int inoder(const char *arr);//递归倒序输出字符串
int my_strlen(const char *arr);//递归实现strlen函数
int my_strlen2(const char *arr);//非递归实现strlen函数

int main()
{
	char arr[]={"abcd1234"};
	inoder(arr);
	printf("\n字符串长为:%d \n",my_strlen(arr));
	printf("%d\n",my_strlen2(arr));
	system("pause");
	return 0;
}

int inoder(const char *arr)
{
	if(*arr=='\0')//退出递归
	return ;
	inoder(arr+1);//注不可写arr++或++arr，否则输出出错
	printf("%c ",*arr);
}

int  my_strlen(const char *arr)//递归求字符串长
{
	static int count=0;
	if(*arr=='\0')
		return count;
	count++;
	my_strlen(arr+1);
}

int my_strlen2(const char *arr)//非递归求字符串长
{
	int count=0;
	while(*arr)
	{
		count++;
		arr++;
	}
	return count;
}

*/

/*

//递归求一个数次方
#include<stdio.h>
#include<stdlib.h>

int calculation(const int num,const int k);//求次方函数

int main()
{
	int num=0;
	int k=0;

	printf("输入数字和次方：");
	scanf("%d %d",&num,&k);

	printf("结果为:%d\n",calculation(num,k));
	system("pause");
	return 0;
}

int calculation(const int num,const int k)//求次方函数
{
	static int temp=1;//保存结果
	if(k==0)
		return temp;//返回结果
	temp*= num;//累乘
	calculation(num,k-1);//递归
}

*/

/*
//计算阶乘
#include<stdio.h>
#include<stdlib.h>

int factorial(int num);//非递归求阶乘
int change(int num);//递归求阶乘

int main()
{
	int num=0;
	printf("输入数字：");
	scanf("%d",&num);
	printf("阶乘结果：%d\n",factorial(num));
	printf("阶乘结果：%d\n",change(num));
	system("pause");
	return 0;
}

int factorial(int num)
{
	int n=1;
	while(num)
	{
		n*=num;
		num--;
	}
	return n;
}

int change(int num)//计算结成
{
  if(num==1)//num==1时，退出递归
  {
  return num;
  }
  return num*change(num-1);//递归，累乘
}

*/