


//浮点数存储:A=(-1)^S*M*2^E  ( 1<=M<2 存储时M只存储小数部分，E存储时 正数 数值+127 ， 负数 数值-127  全0为-127)
//列：9.0->(-1)^0*1.001*2^3 ( S=0  M=1.001 E=3)
//符号位(1位)   E(8位/11位)       M(23位/52位)
//   0          xxxx xxxx       xxx xxxx xxxx xxxx xxxx xxxx
//
//9.0
//   0         1000 0010        001 0000 0000 0000 0000 0000
//
//9.0->9(所有位合并在一起)
//   0 1000 0010 001 0000 0000 0000 0000 0000 ->109....
//
//整数：9
//   0000 0000 0000 0000 0000 0000 0000 1001

//浮点数：9->9.0(按顺序取位当作S,E,M)
//   0    0000 0000 |000  0000 0000 0000 0000 1001 
//   ->(-1)^0*0.000 0000 0000 0000 1001*2^(-126)=-1^0*1.001*2^(-146)=0
//
/*
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int num = 9;
	float *pFloat = (float *)&num;//将整型数（9）存储方式存储在浮点型数的空间中
	printf("numDt%d\n",num); 
	printf("*pFloat %f\n",*pFloat); 
    *pFloat = 9.0; //num存储的值被改变  浮点型数（9.0）存储方式存储在整型数中
	printf("num %d\n",num);  
	printf("*pFloat %f\n",*pFloat); 
	system("pause");
	return 0; 
}

*/

//输出浮点数二进值的每一位
//#include<stdio.h>
//#include<stdlib.h>
//
//void fnum(void);
//
//int main()
//{
//	fnum();
//	system("pause");
//	return 0;
//}
//void fnum(void)
//{
//	float fnum=111.111f;
//	//char *num;
//	//*num=((char*)fnum);
//	int i=0;
//	/*
//	for(i=31;i>=0;i++)
//	{
//		printf("%d ",fnum>>i&1)
//	}
//	*/
//	printf("%d \n",sizeof(float));
//}
//


#include<stdio.h>
#include<stdlib.h>

int main(void)
{
float a  = 33.993f; //-33.33f是个很有代表型的数字，它再一次证明了浮点数是不能精确存储的 
int *p = (int* )&a;//将浮点型存储转化成整型存储格式，并将转化后的地址赋给p,a没有被改变。
//p->0  1000 0010  01 ... 0。此时生成一个浮点数a存储方式对应整数存储方式的新一个整数*p
int len = sizeof(float);
int i;
char k;

printf("浮点数a=%f\n",a);
printf("对应的整数%d\n",*p);
for (i=31;i>=0;--i)//输出*p的二进制位，与a对应的二进制位相同
{
k = (*p)>>i&1;
printf("%d ",k);

if(31==i||23==i)//打印分隔-
printf(" - ");
} 
printf("\n");
system("pause");
return 0;
}



//1.调整数组使奇数全部都位于偶数前面。 
//题目： 
//输入一个整数数组，实现一个函数，来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，所有偶数位于数组的后半部分。 
//
//2. 
////杨氏矩阵 
//有一个二维数组. 
//数组的每行从左到右是递增的，每列从上到下是递增的. 
//在这样的数组中查找一个数字是否存在。 
//时间复杂度小于O(N); 
//数组： 
//1 2 3 
//2 3 4 
//3 4 5 
//
//1 3 4 
//2 4 5 
//4 5 6 

/*

#include<stdio.h>
#include<stdlib.h>

void change(int arr[],const int sz)
{
	int i=0;
	int z=0;
	int j=0;
	int arr1[9];//存放奇数
	int arr2[9];//存放偶数

	for(j=0;j<sz;j++)
	{
		if(arr[j]%2!=0)
		{
			arr1[i]=arr[j];
			i++;
		}
		else
		{
			arr2[z]=arr[j];
			z++;
				
		}
	}

	for(j=0;j<z;j++)//偶数拼接到奇数后
	{
		arr1[i+j]=arr2[j];
	}
	for(i=0;i<sz;i++)//交换后的值赋给原数组
	   arr[i]=arr1[i];
}

void print(int arr[],const int sz)
{
	int i=0;
	for(i=0;i<sz;i++)
		printf("%d ",arr[i]);
}
int main()
{
	int arr[]={1,5,2,6,9,7,8,3,4};
	int sz=sizeof(arr)/sizeof(arr[0]);

	print(arr,sz);
	printf("\n");
	change(arr,sz);
	print(arr,sz);
	system("pause");
	return 0;
}


*/


/*

#include<stdio.h>
#include<windows.h>

#define ROW 4
#define COL 4

void print(int arr[ROW][COL]);
int judge(int arr[ROW][COL],const int value);

int main()
{

    int arr[ROW][COL] = { 1, 2, 3, 5, 4, 6, 7, 8, 9,10,11,13,12 ,14,15,16};
    int i = 0, j = 0;
    int value = 0;
    print(arr);
    printf("please input a number:");
    scanf_s("%d", &value);

    if (judge(arr, value))//返回1则找到，返回0则未找到
    {
        printf("%d is included.\n", value);
    }
    else
    {
        printf("%d is not included.\n", value);
    }
    system("pause");
    return 0;
}

void print(int arr[ROW][COL])
{
	int i=0;
	int j=0;

	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			printf("%-5d",arr[i][j]);
		}
		printf("\n");
	}
}

//
//
//int judge(int arr[ROW][COL], const int value)//按行和列查找都不是正确的，最多需ROW+COL次
//{
//    int i = 0;
//    int j = 0;
//   static int count=0 ;
//
//    while (i<ROW)//按行查找
//    {
//       if (arr[i][0] <= value && arr[i][COL-1] >= value)//可能在这一行中
//        {
//		   while(j<COL)//在此行循环查找
//		   {
//			   if(value==arr[i][j])
//				   return 1;//找到，退出
//			   else
//				   j++;
//		   }
//		   j=0;//不在此行，初始j值，换下行查找
//		   i++;
//        }
//        else //肯定不在此行
//        {
//			i++;//换下行
//        }
//    }
//	return 0;//所有行都未找到
//}
//


int judge(int arr[ROW][COL], const int value)//按对角线查找，正确算法，最多需ROW+COL次
{
	int i=0;
	int j=COL-1;

	while(j>=0||i<=ROW-1)
	{
	   if(value==arr[i][j])
		  return 1;
		else if(value<arr[i][j])
			j--;
		else
			i++;
	}
	return 0;

}

*/
//不同数据存储类型的操作要求
#include<stdio.h>
#include<stdlib.h>

int main()
{
	//char * 直接指向文字常量区，可赋值，赋值后不可修改，
	//*ch1="123";//文字常量区内容不可修改，ch存放文字常量区中存放字符串的地址
	//&ch变量地址在栈中，ch为文字常量区的地址。每次运行文字常量区的地址都不变
	//char *类型定义的变量若内容相同，则地址相同。且只有一份内容。其他的类型地址都是不同的，存多分内容
	char *ch2="3210";
	char *ch1="3210";
	//*ch1="123";//文字常量区内容不可修改，ch存放文字常量区中存放字符串的地址
	char ch[]="123";//ch地址在栈中，地址存放的是字符串（123\0），可修改

	//int *a;*a=1;//a随机指向栈中的某一地址，无内存空间，为野指针，无内存空间不可赋值

	int *b;//b随机指向栈中的某一地址，无内存空间，为野指针
	b=(int *)malloc (sizeof(int)*3);//为b开辟内存空间
	*b=1;//有内存空间可赋值

	ch[0]='3';

	printf("ch1=%p \n",ch1);
	printf("ch2=%p \n",ch2);
	printf("&ch1=%p \n",&ch1);
	printf("&ch2=%p \n",&ch2);
	printf("ch1=%s \n",ch1);
	printf("ch=%s \n",ch);
	printf("*b=%d \n",*b);

	system("pause");
	return 0;
}