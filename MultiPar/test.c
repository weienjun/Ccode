//1.理解函数指针和定义 
//2.理解函数指针数组和定义，转移表 
//3.理解指向函数指针数组的指针和定义 
//4.理解回调函数的使用  
//5.完成课堂代码和练习。 
//6.练习使用qsort函数排序各种类型的数据。 
//7.模仿qsort的功能实现一个通用的冒泡排序。

#include<stdio.h>
#include<stdlib.h>

void my_bubble(void *base,int count,int size);//排序控制
//int cmp(const void *p1,const int size,const int j);//排序判断
int cmp(const void *p1,const void *p2,const int size);//排序判断
void swap(void *before ,void *after,int size);//排序实现
int main()
{
	int j=0;
	int i=0;
	//char arr[]={'1','2','3','6','5','8','4','a'};
	int arr[]={1,2,5,6,78,98,1424,666,8};
	int sz=sizeof(arr)/sizeof(arr[0]);
	
	my_bubble(arr,sz,sizeof(int));

	for(i=0;i<sz;i++)
	printf("%d \n",arr[i]);

	system("pause");
	return 0;
}

void my_bubble(void *base,int count,int size)
{
	int i=0;
	int j=0;
	int n=0;//用于检验是否有序

	for(i=0;i<count-1;i++)
	{
		n=0;
		for(j=0;j<count-i-1;j++)
		{
			if(cmp(((char *)base+size*j),(char*)base+size*(j+1),size))//判断是否排序,每次传入的时当前元素的地址
			  //if(cmp(((char *)base),size,j))//判断是否排序，每次传入的是首地址
			{
				swap((char *)base+size*j,(char*)base+size*(j+1),size);//进行排序，每次传入的是当前的地址
			    n=1;
			}
		}
		if(n=0)//已有序，退出
			break;
	}
}

int cmp(const void *p1,const void *p2,const int size)
{
	if(size==1)//字符排序或数字为ASCLL的数
	return (*(char*)p1 > *(char*)p2);
	else//数字排序
	return (*(int*)p1 > *(int*)p2);//成立返回非0
}

void swap(void *before ,void *after,int size)
{
	int i=0;
	char tmp;
	for(i=0;i<size;i++)//地址中的内容进行交换，每次交换一个字节的内容
	{
		tmp=*((char*)before+i);
		*((char*)before+i)=*((char*)after+i);
		*((char*)after+i)=tmp;
	}
}

//int cmp(const void *p1,const int size,const int j)
//{
//	if(size==1)//只能排序字符或ASCLL码以内的数字，char类型只占一个字节，存储的数字大小有限
//	return (*((char*)p1+(size*j))) > (*((char*)p1+((j+1)*size)));//成立返回非0
//	else//数字排序
//	return (*((int*)p1+j)) > (*((int*)p1+(j+1)));//成立返回非0
//	
//}