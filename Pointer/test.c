
/*
//冒泡优化，
#include<stdio.h>
#include<stdlib.h>

void change(int arr[],int sz);
void print(int arr[],int sz);

int main()
{
	int arr[]={1,3,6,5,7,9,8,4,21,96,50,78,89,65};
	int sz=sizeof(arr)/sizeof(arr[0]);
	print(arr,sz);
	change(arr,sz);
	print(arr,sz);
	system("pause");
	return 0;
}

void change_num(int *x,int *y)//交换
{
	*x ^=*y;
	*y ^=*x;
	*x ^=*y;
}

void change(int arr[],int sz)
{
	int i=0;
	int j=0;
	int z=0;//标记是否排好

	for(i=0;i<sz-1;i++)
	{
		z=0;//假设排好
		for(j=0;j<sz-1-i;j++)
		{
			if(arr[j]<arr[j+1])
			{
				change_num(&arr[j],&arr[j+1]);
				z=1;//未排好，存在交换
			}
		}
		if(z==0)//确认排好，无任何两数进行交换
		break;
	}
}

void print(int arr[],int sz)//输出
{
	int i=0;
	for(i=0;i<sz;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

*/



//1.一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。 
// 找出这两个数字，编程实现。 

/*

#include<stdio.h>
#include<stdlib.h>

int search(int arr[],int sz);

int main()
{
	int arr[]={1,2,3,5,2,3,6,1,7,6,8,9,9};
	int sz=sizeof(arr)/sizeof(arr[0]);

	search(arr,sz);
	system("pause");
	return 0;
}

//设置两个指针，一指针指定数，另一指针从最后个数向前进行遍历查找，
//若有相同的数，p指向下个数，q从最后个数再查找，直到第一个数任无相同的，则将此数输出，
//如此循环，直至p查找完所有数，结束
int search(int arr[],int sz)
{
	int num=0;
	int *p=arr;//用于指定某个数
	int *q=&arr[sz-1];//用于对某数进行查找是否有相同的

	while(1)
	{
		q=&arr[sz-1];//q从最后个数进行比较
		while(q!=arr)//未比较完所有数
		{
			if(*p==*q&&p!=q)//两数相同且不在同一位置（同一数）
			{
				if(p==&arr[sz-1])//p指向最后一个数，退出
				{
					return 0;
				}
				else//p不为最后一个数，进行下个数比较
				{
					p++;
					q=&arr[sz-1];
				}
			}
			else//两数不同，q指向下个数比较
				q--;
		}//q找至第一个数都未与p数相同的

		if(p!=q&&*p!=*q)//两数不同
		{
		printf("%d \n",*p);
		}

		if(p==&arr[sz-1])//所有数都已比较
		{
			return 0;
		}
		else//数未比较完，p 继续下个数比较
		p++;
	}
}

*/

/*
//2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水。编程实现。 
#include<stdio.h>
#include<stdlib.h>

int jisuan(int menioy);

int main()
{
	int menoy=0;
	int num=0;
	printf("输入钱数：");
	scanf("%d",&menoy);
	num=jisuan(menoy);
	printf("%d \n",num);

	system("pause");
	return 0;
}

int jisuan(int menoy)
{
	int num=menoy;
	int n=menoy;

	while(num>1)//剩于瓶数少于2时结束
	{
		n+=num/2;//个数
		num=(num%2+num/2);//剩余瓶数
	}
	return n;
}


*/


/*

//3.模拟实现strcpy 
//4.模拟实现strcat 

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

char * my_strcpy(char *ch, const char *ch1);//复制函数
char * my_strcat(char *ch, const char *ch2);//字符串拼接 。注：ch必须可存储下ch1，否则越界
char * my_strstr(const char *ch,const char *ch1);//判断子串

int main()
{
	char ch[20]={"abc123"};
	char ch1[]={"456"};
	char *ch2;

	my_strcpy(ch,"def");
	printf("复制结果：%s \n",ch);

	my_strcat(ch,ch1);//注：ch必须可存储下ch1，否则越界
	printf("拼接结果：%s \n",ch);

    printf("判断结果：%s \n",my_strstr(ch,"f4"));
	system("pause");
	return 0;
}

char *my_strcpy(char *ch,const char *ch1)
{
	char  *srt=ch;
	assert(ch!=NULL);//断言，检测
	assert(ch1!=NULL);
	while(*ch++=*ch1++)	;//复制
	return srt;//返回ch地址，便于链式反应
}

char *my_strcat(char *ch,const char *ch2)//字符串拼接
{
    char *srt=ch;//便于链式反应
	assert(ch);//判空
	assert(ch2);

	while(*ch)//使ch指向'\0'
	{
		ch++;
	}
	while(*ch2)//从ch的'\0'处拼接
	{
		*ch=*ch2;
		ch++;
		ch2++;
	}
	return srt;
}

char * my_strstr(char *ch,const char *ch1)//判断字串
{
	assert(ch);//判空
	assert(ch1);
	
	if(*ch1=='\0')
	  return NULL;

	while(*ch)
	{
		const char *start=ch;//start指向ch(原字符串中的当前字符)
	    const char *target=ch1;//target一直指向比较字符串的第一个字符
		//（比较成功是，连续字符相同，直到ch1='\0'，即内循环跳出时，ch1='\0’，
		//否则若有一个字符不同，ch1重新从第一个字符开始比较，start位置不变。）

		while(*ch1)//原字符串未比较结束
		{
			if(*start==*target&&*start&&*target)//字符相同，且任一不为'\0'
			{
				start++; target++;//进行比较下个字符
			}
			else//不想同，跳出
				break;
		}
		
		if(*target=='\0')//字符为'\0'，比较结束
			return ch;//是子串，返回从子串之后的字符串

		ch++;//进行字符串中的下个字符比较。
	}
	return NULL;//不是返回NULL（0）
}

*/

/*

//1.使用main函数的参数，实现一个整数计算器，程序可以接受三个参数，第一个参数“-a”选项执行加法，“-s”选项执行减法，“-m”选项执行乘法，“-d”选项执行除法，后面两个参数为操作数。 
//例如：命令行参数输入：test.exe -a 1 2 
//执行1+2输出3 
//


#include<stdio.h>
#include<assert.h>
#include<stdarg.h>
#include<stdlib.h>

int calculation(const char* ch,...);

int main()
{
	int a=0;
	int b=0;
	char ch[5];
	char *ch1=(char*)malloc(sizeof(char)*10);//指针需分配内存空间或有内存空间，不然就是野指针
	printf("输入操作符:");
	//字符串输入输出方法
	//scanf("%s",&ch);//数组名可表示地址所以可加&，也可不加
	//printf("%s\n",ch);
	scanf("%s",ch1);//ch1为指针，不可再加&
	printf("输入数值;");
	scanf("%d %d",&a,&b);
	printf("输入：%s %d %d \n",ch1,a,b);//变量名为ch1，不可加*
	printf("计算结果：%d \n",calculation(ch1,a,b));
	system("pause");
	return 0;
}


int calculation(const char* ch,...)
{
	int num=0;
	va_list arg;

	assert(ch);
	va_start(arg,ch);
	if(*ch=='-')
	{
		ch++;
		switch(*ch)
		{
		case 'a':
			num=va_arg(arg,int);
			return num+=va_arg(arg,int);
			break;
		case 's':
			num=va_arg(arg,int);
			return num-=va_arg(arg,int);
			break;
		case 'm':
			num=va_arg(arg,int);
			return num*=va_arg(arg,int);
			break;
		case 'd':
			num=va_arg(arg,int);
			return num/=va_arg(arg,int);
			break;
		}
	}
	else
		printf("eorr\n");
		va_end(arg);
	return NULL;
}


*/

/*

//2.写冒泡排序可以排序多个字符串中的字符。
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void sorting(char *ch[],int sz);

int main()
{
	char *ch[]={"125673","acb","DS12A","cba"};//数组指针存放的都是每个字符串的地址
	//sizeof(ch[0]),计算的是一个地址所占字节
	//sizeof(ch),统计的是所有地址所占总字节数，一个地址占4个字节
	int sz=sizeof(ch)/sizeof(ch[0]);//计算字符串个数，
	sorting(ch,4);
	printf("%d \n",sz);
//	printf("%s \n",*ch[3]);
	system("pause");
    return 0;
}


void sorting(char  *ch[],int sz)
{
	int i=0;
	int j=0;
	int n=3;

	char *ch2="3210";
	char *ch1="3210";//char * 直接指向文字常量区，可赋值，赋值后不可修改，
	 //*ch1="123";//文字常量区内容不可修改，ch存放文字常量区中存放字符串的地址
	//&ch变量地址在栈中，ch为文字常量区的地址。每次运行文字常量区的地址都不变
	//char *类型定义的变量若内容相同，则地址相同。且只有一份内容。其他的类型地址都是不同的，存多分内容
	char ch[]="123";//ch地址在栈中，地址存放的是字符串（123\0），可修改
	ch[0]='3';

	int *a;*a=1;//a随机指向栈中的某一地址，无内存空间，为野指针，无内存空间不可赋值

	int *b;//b随机指向栈中的某一地址，无内存空间，为野指针
	b=(int *)malloc (sizeof(int)*3)//为b开辟内存空间
	*b=1;//有内存空间可赋值
	
	//a=(int*)malloc(100);
	//*a=12;
	//*a=13;
	// n=strlen(ch1);
 //      for(i=0;i<n;i++)
	//	{
	//		for(j=0;j<n-i-1;j++)
	//		{
	//			if(ch1[j]>ch1[j+1])
	//			{
	//				ch1[j] ^=ch1[j+1];
	//				ch1[j+1] ^=ch1[j];
	//				ch1[j] ^=ch1[j+1];
	//			}
	//		}
	//	}
	   printf("%s \n",ch1);
}

//
//void sorting(char  *ch[],int sz)
//{
//	char temp;
//	int i=0;
//	int n=0;
//	char *ch1="321";
//	char ch3;
//	int j=0;
//	//ch1=ch[3];
//	//printf("%s \n",ch1);
//	while(sz)
//	{
//	    //ch1=ch[sz-1];
//		printf("%d \n",strlen(ch1));
//		n=strlen(ch1);
//		temp=ch1[1];
//
//		for(i=0;i<n;i++)
//		{
//			for(j=0;j<n-i-1;j++)
//			{
//				/*if(temp<ch1[j])
//				{
//					temp=ch1[j];
//					ch1[j]=ch1[j+1];
//					ch1[j+1]=temp;
//				}*/
//				if(ch1[j]>ch1[j+1])
//				{
//					ch1[j] ^=ch1[j+1];
//					ch1[j+1] ^=ch1[j];
//					ch1[j] ^=ch1[j+1];
//				}
//			}
//		}
//	//	{
//	//			 /*  *ch1 ^=*++ch1;
//	//			   *ch1 ^=*--ch1;
//	//			   *ch1 ^=*++ch1;
//	//*/
//	//			}
//	//			ch1--;
//	//		}
//	//		//ch1++;
//	//	//ch1=ch[sz-1];
//		printf("%s \n",ch1);
//		sz--;
//	}
//}





/*
//
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void arr_bubble_sort(char(*p)[10],const int sz)//数组指针，即指向大小为10的数组的指针
{
     int i = 0;
     int j = 0;
	 char *temp;

	 temp=(char*)malloc (sizeof(char)*100);//为temp分配内存空间
	 for(j=0;j<sz;j++)
	 {
		 for(i=0;i<sz-j-1;i++)
		 {
			 if (strcmp(p[i], p[i+1])>0)//使用字符串比较函数，进行比较，排序
			 {
				  strcpy(temp, p[i]);//使用字符串复制函数，进行字符串排序
				  strcpy(p[i],p[i+1]);
				  strcpy(p[i+1], temp);
			 }
		 }
	 }
	 free(temp);  
}
int main()
{
	 int i=0;
     char ch[3][10] = { "adacd", "aaers", "baiu" };
     //sizeof(ch[0]),计算的是一个地址所占字节
	//sizeof(ch),统计的是所有地址所占总字节数，一个地址占4个字节
	int sz=sizeof(ch)/sizeof(ch[0]);//计算字符串个数，

     arr_bubble_sort(ch,sz);
     for (i = 0; i < sz; i++)
     {
        printf("%s\n", ch[i]);//按行输出
     }
     system("pause");
     return 0;
}

*/
//
//#include<stdio.h>
//#include<stdlib.h>
//#define D(x) x+x
//
//int (*foo(int(*a)[3]))[3]
//{
//	return ++a;
//}
//
//int main()
//{
//	char *a[]={"123","321","abc","dbf"};
//	char *s="\ta\x0f0g";
//	char *p="abcd";
//	int i=0;
//	/*int j=i++;
//	int w[2][3]={1,2,3,4,5,6};
//	int (*pw) [3];
//	int a[3][3]={2,-1,3,4,8,1,20,7,6};
//	int (*p)[3]=foo(a);
//	void *q=malloc(100);
//	printf("%d\n",sizeof(q));
//	printf("\n\n %d \n\n",*1[p]);*/
//
//	//pw=w;
//	//printf("%d\n",*(pw+1)[2]);
//	//printf("%d\n",*(pw[1]+2));
//	//while((i>j++)&&(i++==j))
//	//{
//	//	i+=j;
//	//}
//	//printf("\n %d \n",i);
//	for(;*s!='\0';s++)
//	{
//		i++;
//		printf("%d\n",i);
//	}
//	/*printf("%d\n",sizeof(p));
//	printf("%p \n",a[2]);
//	printf("%d\n",5*D(2+3));*/
//	system("pause");
//	return 0;
//}

//内存对齐
#include<stdio.h>
#include<stdlib.h>
#define value(Structure,Field) ((unsigned int )&(((Structure*)0)->Field))//将0转成地址
typedef struct //0转成地址后结构体地址从0开始
	{
		short a;//short占2个字节，即按2对齐
		char b;//char占一个字节 1<2 按2对齐则地址为3
		char* c;//char*占4个字节，4>2 按4对齐，原则为3+4=7,按4对齐，即4的倍数变为8
		long (*d)[3];//long占4个字节，4==4按四对齐，8+4=12是4的倍数
		float e;//到e时即为12
	}init;

int main()
{
	printf("%d", value(init,e));//12
	system("PAUSE");
	return 0;
}