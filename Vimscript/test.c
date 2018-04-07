
//1.将可变参数列表源码的剖析和你自己的理解写一篇【漂亮】的博客。 
/*

//2.使用可变参数，实现函数，求函数参数的平均值。
#include<stdio.h>
#include<stdarg.h>//可变参数头文件
#include<assert.h>
#include<stdlib.h>

int averge(int count,...);//计算n个数值平均值
int Max_num(int count,...);

int main()
{
	int add=0;
	int max_num=0;

	add=averge(3,1,2,3);
	printf("结果为:%d\n",add);

	max_num=Max_num(6,6,5,9,4,-1,8);
	printf("最大数：%d\n",max_num);
	system("pause");
	return 0;
}

int averge(int count,...)//计算n个数值平均值
{
	int i=0;
	int num=0;
	va_list arg;//定义一个va_list类型变量（指针）
	assert(count);
	va_start(arg,count);//初始化arg,既让arg指向第一个参数（非数值个数参数），个数不提取
	for(i=0;i<count;i++)
	{
		num+=va_arg(arg,int);//提取数值和类型赋给num（一次提取一个参数）；num进行累加
	}
	va_end(arg);//释放arg;
	return num>>1;
}
//3.使用可变参数，实现函数，求函数参数的最大值。 
int Max_num(int count,...)//求最大数
{
	int num=0;
	int temp=0;
	int i=0;
	va_list arg;//定义变量

	assert(count);
	va_start(arg,count);//初始化

	temp=va_arg(arg,int);
	for(i=1;i<count;i++)
	{
		num=va_arg(arg,int);//提取数值
		if(num>temp)//数值比较
		{
			temp=num;
		}
	}
	va_end(arg);
	return temp;
}


*/


//4.1.模拟实现printf函数，可完成下面的功能 
//能完成下面函数的调用。 
//print("s ccc d.\n","hello",'b','i','t'，100); 
//函数原型： 
//print(char *format, ...) 
//

//仿写输出函数

#include<stdio.h>
#include<stdarg.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>

int my_printf(char *format, ...);
 int change(const int num);//整数输出
 int float_num(const float fnum);//浮点数输出

int main()
{
	int n=0;

	n=printf("put输出: %s %c%c%c %%100 \n %d\t %lf %d" , "hello" , 'y' , 'o','u',101,-12.251,12);
	printf("  返回值：%d\n",n);

	n=my_printf("put输出: %s %c%c%c %%100 \n %d\t %f %d" , "hello" , 'y' , 'o','u',101,-12.251,12);
	my_printf("  返回值：%d\n",n);
	system("pause");
	return 0;
}
////根据*format的字符判断将要输出的是那中类型，%s->字符串，%c->字符，%d->整数...
int my_printf(char *format,...)//模拟printf函数
{
	va_list arg;//定义arg变量（指针类型）
	char *p=format;//用于标识字符
	char * ch=NULL;//用于存储输出的字符串
	int num=0;//用于存储输出的数字
	float fnum;
	char c;//用于存储输出的字符
	int count=0;
	int a=0;

	assert(format);//判空
	va_start(arg,format);//初始化arg
	while(*format)//不为'\0'
	{
		if(*format=='%')
		{
			format++;
			switch(*format)
			{
				case 's':
					{
						ch=va_arg(arg,char*);
						while(*ch)
						{
							putchar(*ch);
						    ch++;
							count++;
						}
					}
					break;
				case 'c':
					{
						c=va_arg(arg,char);
					    putchar(c);
						count++;
					}
					break;
				case 'd':
					{
						num=va_arg(arg,int);
					    count+= change(num);//将整数输出
					}
					break;
				case 'f':
					{
					   fnum=va_arg(arg,double);
                       count+= float_num(fnum);
					}
					break;
				case '%':
					putchar('%');
					count++;
					break;
					
			
				default:
				count++;
				puts("eorr");
		  }

		}//跳出if
		else if((int)*format<0&&(int)*format>255)//对汉字进行处理
		{
			puts(format);//输出汉字
			count++;
		}
		else//输出其他字符
		{
			putchar(*format);
			count++;
		}

		format++;
	}
	va_end(arg);
	return count;
}

static int change(int num)//非递归以字符输出整数
{
	int n[20];//记录每位数
	int i=0;//数组下标
	int count=0;//统计位数
    if(num<0)
	{
		putchar('-');
		num=-num;
		count++;
	}
	while(num>0)
	{
		n[i]=num%10;
		num/=10;
		i++;
	}
	count+=i;
	for(;i>0;i--)
	{
		putchar((char)(n[i-1]%10)+'0');//以字符形式输出
	}
	return count;
}

static int float_num(const float fnum)//浮点数输出
{
int count =0;//统计参数
int dec, sign, i;
char * str;
int bit=6;//保留位数
//利用浮点数转化成字符函数，获取浮点数中的数值对应的字符
// fcvt(d, 2, &dec, &sign);//d表示要转化的数，2表示保留2位小数，dec表示小数点的位置，sing表示符号位
str = fcvt(fnum, bit, &dec, &sign);

if (sign)//符号位，1表示负数
{
putchar('-');
count++;
}

for (i = 0; i != strlen(str); ++i)
	{
		if (i == dec)//小数点位置
		putchar('.');
		putchar(str[i]);//输出数字，字符
	}
	return count+=i+1;
}



/*
//根据*format的字符判断将要输出的是那中类型，s->字符串，c->字符，d->整数
int my_printf(char *format,...)
{
	char c ;//保存字符
	char *ch=NULL;//保存字符串
	int num=0;//保存整数
	va_list arg;

	va_start(arg,format);

	while(*format!='\0')
	{
		if(*format=='s')//输出字符串
		{
			ch=va_arg(arg,char*);
			while(*ch)
			{
			putchar(*ch);
			ch++;
			}
		}

		else if(*format=='c')//输出字符
		{
		c=va_arg(arg,char);
		printf(" %c",c);
		}

		else if(*format=='d')//输出数值
		{
			num=va_arg(arg,int);
			printf(" %d ",num);
		}

		else//直接打印其他类型（formate）
			printf("%c",*format);

		format++;//指向下一个类型
	}
	va_end(arg);
}

*/
/*

int my_printf(char *format,...)//模拟printf函数
{
	va_list arg;//定义arg变量（指针类型）
	char *p=format;//用于标识字符
	char * ch=NULL;//用于存储输出的字符串
	int num=0;//用于存储输出的数字
	char c;//用于存储输出的字符

	va_start(arg,format);//初始化arg
	while(*format)//不为'\0'
	{
		p=format;//p指向当前的字符位置
		
		if(*p=='%')//为%表示将可能有对应的变量
		{
			if(*++p=='s')//s表示字符串
			{ 
				ch=va_arg(arg,char*);//提取字符串中的字符
				while(*ch)//输出字符串
				{
					putchar(*ch);
					ch++;
				}
				format++;//跳过%
			}
			
			else if(*p=='c')//c表示字符
			{
				c=va_arg(arg,char);//提取字符
				putchar(c);//输出字符
				format++;
			}

			else if(*p=='d')//d表示整型数字
			{
				num=va_arg(arg,int);//提取数字
				printf("%d ",num);
				format++;
			}
			else//只有一个%，打印 %
			{
			 putchar(*format);
			}
		}

		else//无对应变量，输出字符
			putchar(*format);
		format++;
	}

}

*/




/*

//以字符输出浮点数的每一位，包括'.'
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
double d;
int dec, sign, i;
char * str;
scanf("%lf", &d);
//利用浮点数转化成字符函数，获取浮点数中的数值对应的字符
// fcvt(d, 2, &dec, &sign);//d表示要转化的数，2表示保留位数，dec表示小数点的位置，sing表示符号位
str = fcvt(d, 6, &dec, &sign);
if (sign)//符号位，1表示负数
putchar('-');
for (i = 0; i != strlen(str); ++i)
{
if (i == dec)//小数点位置
putchar('.');
putchar(str[i]);//输出数字，字符
}
system("PAUSE>NUL");
return 0;
}

*/

