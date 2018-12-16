/*
//二进制寄偶位交换思路：
//1、取所有的奇数位，让偶数位为0，然后左移1位。此时所有奇数位都变为偶数位
//2、取所有的偶数位，让奇数位为0，然后右移1位。此时所有偶数位都变为奇数位
// & 0x5555 5555=0101 0101 0101 0101 0101 0101 0101 0101 （取所有的奇数位）
// & 0xAAAA AAAA=1010 1010 1010 1010 1010 1010 1010 1010 （取所有的偶数位）

#include<stdio.h>
#include<stdlib.h>
#define CHANGE(num)\
(((num&(0x55555555))<<1)|((num&(0xAAAAAAAA))>>1))//二进制奇偶位交换

int main()
{
	int i=0;
	int n=2;
	int num=5;//交换的数字

	
	printf("改变前位为\n");
	for(i=31;i>=0;i--)//从高位到低位输出二进制位
	{
		printf("%d ",num>>i&1);
	}
	
	num=CHANGE(num);
	printf("\n改变后位为\n");
	for(i=31;i>=0;i--)//输出二进制每一位
	{
		printf("%d ",num>>i&1);
	}

	system("pause");
	return 0;
}

*/

//1.编写函数： 
//unsigned int reverse_bit(unsigned int value); 
//这个函数的返回值value的二进制位模式从左到右翻转后的值。 
//
//如： 
//在32位机器上25这个值包含下列各位： 
//00000000000000000000000000011001 
//翻转后：（2550136832） 
//10011000000000000000000000000000 
//程序结果返回： 
//2550136832 

/*

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int change(int unsigned num)
{
	int i=0;
    int num1=0;
	int bit=0;

	for(i=0;i<32;i++)
	{   
		bit=num>>i&1;//取二进制位，按低到高的顺序取
		num1=(num1+bit*pow(2.0,31-i));//计算所取得每位反转后的值，并相加
	}
	return num1;
}

int main()
{
	int unsigned num=0;
	printf("输入数字: ");
	scanf("%d",&num);
	printf("反转后%u\n",change(num));
	system("pause");
	return 0;
}

*/

/*

//2.不使用（a+b）/2这种方式，求两个数的平均值。
#include<stdio.h>
#include<stdlib.h>

int averge(const int num1,const int num2)
{
	//注：num1+(num2-num1>>1)num的顺序不可写反，即num1+(num1-num2>>1)错误
	return num1+((num2-num1)>>1);//移位只可为整数类型
	//return (num1&num2)+((num1^num2)>>1);//各自相同部分加上不同部分的一半，即为两数的平均值
}
int main()
{
	int num1=0;
	int num2=0;
	printf("输入两个数值：");
	scanf("%d %d",&num1,&num2);
	printf("平均值为%d\n",averge(num1,num2));
	
    system("pause");
    return 0;	
}

*/

/*

//3.编程实现： 
//一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。 
//请找出这个数字。（使用位运算） 
#include<stdio.h>
#include<stdlib.h>
#define N 100 //假设数最多都有N位

int search( int num)
{
	int num2=0;
	int i=0;//数组下标
	int num1[N]={0};

	while(num)//整个数字拆分成多个数
	{
		num1[i]=num%10;
		num=num/10;
		i++;
		
	}
	num2=num1[0];
	for(i=1;i<N;i++)
	{
		//根据a^a=0; 0^a=a; 所以最终剩余的那个数便是一个或奇数个
		num2=num2^num1[i];
	}
	return num2;
}

int main()
{
	int num=243545020;
	printf("非两次出现数：%d\n",search(num));
	system("pause");
	return 0;
}

*/

/*

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


*/

/*

//输出二进制的每一位并统计有多少位为1

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int num=0;
	int count =0;
	int i=0;

	printf("输入数值：");
	scanf("%d",&num);

	for(i=31;i>=0;i--)//输出每一位
	{
	   printf("%d ",(num>>i)&1);
	}

	while(num)//统计1数
	{
	num&=(num-1);
	count ++;
	}
	printf("\n 为一的有%d位\n",count );
	system("pause");
	return 0;
}


*/


//4. 
//有一个字符数组的内容为:"student a am i",请你将数组的内容改为"i am a student". 
//要求： 
//不能使用库函数。只能开辟有限个空间（空间个数和字符串的长度无关）。 

/*

#include <stdio.h>
#include<stdlib.h>

char* word_reversal(char* str);
char* char_reversal(char ch[],const int sz);

char* char_reversal(char ch[],const int sz)//字符串反转
{
	int i=0;

	for(i=0;i<sz/2;i++)
	{
		ch[i]=ch[i]^ch[sz-i-1];//末尾'\0'不可反转，所以-1
		ch[sz-i-1]=ch[i]^ch[sz-i-1];
		ch[i]=ch[i]^ch[sz-i-1];
	}
   
	word_reversal(ch);//单词反转
}

char* word_reversal(char* str)
{
	//pi,p2指向字符串的首地址
	char *p1=str;
	char *p2=str;
	char *p=NULL;
    
    while(*p2 != '\0')//不为字符串结束位置
    {
		//使p2指向单词的最后那个字符的地址
        while(*p2 != ' ' && *p2 != '\0')//不为空格,且不为字符串结尾
        {   
            p2++;
        }
       
	    p = p2;//将单词最后那个字符的地址，赋值给p
		//每个单词中的字符进行位置交换，前与后交换
        while(p1 < p2-1)//p1指向单词的第一个字符地址，p2指向单词的最后一个字符地址
        {
		    //char tmp = *p1;
            //*p1 = *(p2-1);
            //*(p2-1) = tmp;

		    *p1=*p1^*(p2-1);
			*(p2-1)=*p1^*(p2-1);
			*p1=*p1^*(p2-1);
            p1++;//p1指向下一个字符地址
            p2--;//p2指向上一个字符地址
        }
        
        if(*p == '\0')//到达字符串结尾，即所有的单词都已反转
        {
            return str;//退出
        }
        p1 = p+1;//p1指向下一个单词的第一个字符地址
        p2 = p+1;//p2指向下一个单词的第一个字符地址
    }
	return str;//退出
}

int main ()
{
    char ch[] = "student a am i";
	int sz=sizeof(ch)/sizeof(ch[0])-1;//计算字符串长，不包含'\0'
    char *ret = char_reversal(ch,sz);
    printf("%s\n",ret);
	system("pause");
    return 0;
}


*/

/*
//2

#include <stdio.h>
#include<stdlib.h>

char* word_reversal(char* str);

char * char_reversal(char *str)
{
	char *p1=str;//指针p1指向str的首地址
    char *p2 = str;//指针p2指向str
   // char *p;//指针p
     
    while(*p2 != '\0')//p2指向\0
    {
        p2++;
    }
    //所有字符整体反转，注，'\0'位置未改变
    while(p1 < p2-1)//p1不指向最后那个字符地址
    {
        char tmp = *p1;//temp保存当前p1的字符
        *p1 = *(p2-1);//前一个字符与后面的地址交换
        *(p2-1) = tmp;
        p1++;//p1指向下一个字符的地址
        p2--;//p2指向上一个字符的地址
    }
    
	word_reversal(str);//单词反转
}

char* word_reversal(char* str)
{
	//pi,p2重新指向字符串的首地址
	char *p1=str;
	char *p2=str;
	char *p;
	//pi,p2重新指向字符串的首地址
   // p1 = str;//指向第一个单词第一个字符地址
   // p2 = str;
    
    while(*p2 != '\0')//不为字符串结束位置
    {
		//使p2指向单词的最后那个字符的地址
        while(*p2 != ' ' && *p2 != '\0')//不为空格,且不为字符串结尾
        {   
            p2++;
        }
       
	    p = p2;//将单词最后那个字符的地址，赋值给p
		//每个单词中的字符进行位置交换，前与后交换
        while(p1 < p2-1)//p1指向单词的第一个字符地址，p2指向单词的最后一个字符地址
        {
            char tmp = *p1;
            *p1 = *(p2-1);
            *(p2-1) = tmp;
            p1++;//p1指向下一个字符地址
            p2--;//p2指向上一个字符地址
        }
        
        if(*p == '\0')//到达字符串结尾，即所有的单词都已反转
        {
            return str;//退出
        }
        p1 = p+1;//p1指向下一个单词的第一个字符地址
        p2 = p+1;//p2指向下一个单词的第一个字符地址
    }
	return str;//退出
}

int main ()
{
    char a[] = "student a am i";
    char *ret = char_reversal(a);
    printf("%s\n",ret);
	system("pause");
    return 0;
}

*/



#include<stdio.h>
#include<assert.h>
#include<ctype.h>
#include<stdlib.h>

void change2(char *q1, char *q2)
{
	while(q1 < q2)
	{
	*q1 ^=  *q2;
	*q2 ^=  *q1;
	*q1 ^=  *q2;
	q1++;//指向下个字符
	q2--;//指向上个字符
	}
}

void change(char arr[])
{
	char * p = arr;//用于指向单词尾部
	char * q = arr;//用于指向单词头部
	
	assert(arr);//检测函数，检测arr是否为NULL，头文件#include<assert.h>

	while(*p)//*p不为'\0'，字符串中的单词交换
	{
		//if(*p1==' ') 
		if(isspace(*p))//判断单词是否结束，isspace(*p)如果*p为空格返回1,头文件#include<ctype.h>
		{               //单词结束，即交换单词内容顺序
			change2(q,p-1);//交换此单词内容顺序，由于p1进入时指向的为空格，所以-1
			p++;   //p指向下个单词的头部
			q=p; //q指向下个单词的头部（第一个字母）
		}
		else //单词未结束
			p++;//指针指向下个字母
 	}//结束时p1指向'\0'

	change2(arr,p-1);// 字符串整体交换 '\0'不可交换 p-1
}

int main()
{
	char arr[]="student a am i";
	printf("转换前：%s \n",arr);
	change(arr);
	printf("转换后：%s \n",arr);
	system("pause");
	return 0;
}



/*

//将数组组中的奇数排在前边

#include<stdio.h>
#include<stdlib.h>

int change(int arr[],int sz)
{
	int *p=arr;//指向前边的数
	int *q=&arr[sz-1];//指向后边的数

	while(p<q)
	{
		//注：所有数都是由2^n+2^k+...组成，偶数则无2^0,
		//所以二进制最低位为0则为偶数，为1则为奇数，判断奇偶数，使用位操作效率更高
		if((*p&1)==0&&(*q&1)!=0)//前为奇数，后为偶数，交换
		{
	    	*p=*p^*q;
			*q=*p^*q;
			*p=*p^*q;
		}
		if(*p&1)//前边为奇数前指针后移
			p++;
		if((*q&1)==0)//后边为偶数后指针前移,注'=='优先级高于&，所以必须有括号
            q--;
	}
}

void print(int arr[],int sz)//输出数组
{
	int i=0;
	for(i=0;i<sz;i++)
	printf("%d ",arr[i]);
	printf("\n");
}
int main()
{
	int arr[]={1,2,3,4,5,6,9,8,7};
	int sz=sizeof(arr)/sizeof(arr[0]);

	print(arr,sz);
	change(arr,sz);
	printf("交换后\n");
	print(arr,sz);

	system("pause");
	return 0;
}

*/