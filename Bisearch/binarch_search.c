/*
#include<stdio.h>
#include<stdlib.h>

int search(int arr[],int n,int snum);
int main()
{
	int num=0;
	int snum=0;
	int arr[]={1,2,3,4,5};
	int n=sizeof(arr)/sizeof(arr[0]);//计算组组大小

	printf("输入要查找的数：");
	scanf("%d",&snum);
	num=search(arr,n,snum);
	printf("结果%d\n",num);

	system("pause");
	return 0;

}

int search(int arr[],int n,int snum)
{

	int i=0;
	int start=0;
	int mid=0;
	while(start<=n)
	{
		mid=(start+n)/2;

		if (snum>arr[mid])//在后半部分查找
			start=mid+1;

		else if(snum<arr[mid])//在前半部分查找
			n=mid-1;

		else 
			return mid;//找到返回从下标
	}

	return -1;//未找到返回-1
}


*/

#include<stdio.h>
#include<stdlib.h>
//折半查找
int search(int arr[],int num,int sz);//找到返回下标，未找到返回-1
int main()
{
	int arr[]={1,2,4,5,6,7,8,9};
	int sz=0;//统计数组大小
	int i=0;//记录返回值
	int num=0;//要查找的数

	printf("输入要查找的数：");
	scanf("%d",&num);

	//因此数组不可在其他实现函数中求数组大小。
	sz=sizeof(arr)/sizeof(arr[0]);//计算数组大小，数组作为参数时，仅传递数组首地址。sizeof(arr)仅能求首个元素大小而不是数组总大小。
	i=search(arr,num,sz);//找到返回下标，未找到返回-1

	if(-1==i)
		printf("未找到！\n");
	else
		printf("下标为%d\n",i);

	system("pause");
	return 0;
}

int search(int arr[],int num,int sz)
{
	int light=0;//左值下标，下标从0开始
	int right=sz-1;//右值下标为数组大小-1；
	int mid=0;//中间值下标

	while(light<=right)//除找到那次。每循环一次，左或右下标和中间下标发生一次变化（左下标加，右下标减）
	{
		//找出中间值下标
		//mid=(light+right)/2;//求平均值，该方法可能存在两值和大于最大数值范围出错
		//mid=(light&right)+((light^right)>>1)//求平均值，该方法较难理解，a>>1相当于a/2
		mid=light+((right-light)>>1);//求平均值

		if(num<arr[mid])//数小于中间值
			right=mid-1;//右下标变为中间值下标的前一个
		else if(num>arr[mid])//数大于中间值
			light=mid+1;//左下标变为中间值下标的后一个
		else//数值等于中间值
			return mid;//返回下标

	}
	return -1;//未找到
}
