#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"Test.h"

int binary_search(const int arr[],const int data,int left,int right)
{
	int mid=left+((right-left)>>1);
	assert(arr);//断言，arr不为空
	 if(arr[mid]==data)
		return mid;
	else if(left >= right)//未找到,由于right最大值为sz（数值个数），所以去等号，防止越界
	{
		return -1;
	}
	else if(arr[mid]<data)//右侧
	{
		binary_search(arr,data,mid+1,right);
	}
	else //左侧
	{  
		binary_search(arr,data,left,mid-1);
	}
}

//每次轮假设第一个数最大，遍历当前轮所有元素，标记出实际最大数位置
//找出最大数后，将当前此位置的数（最大数）与当前轮最后一个位置数交换（小—>大）
//循环加1，进行下一轮交换，（最后一个位置前移）
//比较N-1轮，每轮比较N-i次
int choose_search(int arr[],const int sz)//选择排序
{
	int i=0,j=0;
	int temp=0;
	int test;
	assert(arr);//断言，arr不为空
	for(i=0;i<sz-1;i++)//一个数不用比较
	{
		temp=0;//每轮假设第一个数最大
		for(j=0;j<sz-i;j++)//每次arr[j]都和temp比较，所以不减一
		{
			if(arr[j]>arr[temp])
				temp=j;//标记下标
		}
		if(sz-i-1 != temp)//不在当前轮最大位置
			change(&arr[sz-i-1],&arr[temp]);
	}
}

void print(const int arr[],const int sz)//输出
{
	int i=0;
	assert(arr);//断言，arr不为空
	for(i=0;i<sz;i++)
	printf("%d  ",arr[i]);
	printf("\n");
}


int choose_search1(int arr[],const int sz)//优化选择排序
{
	int max_num=sz-1;
	int min_num=0;
	int n=1;
	int i=0;
	int j=0;
	assert(arr);//断言，arr不为空
	//一次同时找出最大与最小的数
	while(min_num<max_num)
	{
		for(i=j+1;i<sz-j;i++)
		{
			if(arr[i] > arr[max_num])//找出最大数
				max_num=i;
			if(arr[i] < arr[min_num])//找出最小数
				min_num=i;
		}

		if(n)
			change(&max_num,&min_num);

		if(j != min_num)//最小数不在最小的位置，需交换
		change(&arr[j],&arr[min_num]);

		if(max_num==j)//最大数在最小数的位置，上属交换时，最大数已移动在min_num位置
		{
			max_num=min_num;//将max_num移动至新的位置
		}

		if(max_num != sz-1-j)//最大数不在最大位置，交换
		change(&arr[sz-j-1],&arr[max_num]);

		j++;//从下次开始排序
		max_num=sz-j-1;//max_num前移
		min_num=j;//min_num后移
	}
}

//每轮中，每相邻两个数比较，大的后移（或前移）
//共比较N-1轮，每轮比较N-1-i次
//优化：当一轮中无交换时，即有序直接退出
int bubble_sort(int arr[],const int sz)//优化冒泡排序
{
	int i=0,j=0;//循环控制
	int temp=0;
	int t;
	assert(arr);//断言，arr不为空

	for(i=0;i<sz-1;i++)
	{
		temp=0;
		for(j=0;j<sz-1-i;j++)
		{
			if(arr[j] > arr[j+1])
			{
				change(&arr[j],&arr[j+1]);
				temp=1;
			}
		}
		if(temp==0)
			return ;
	}
}

//设置一个标签，（当前轮第一个数或最后一个数）
//先从后往前（j--~0）与标签数比较，比标签小的数，将该数赋给第一个位置（覆盖），位置+1(变为第二个位置)退出循环
//从前（接上位置i）往后（i++~j）与标签比较，比标签大的，将此位置的数赋给j（覆盖），后j-1，退出循环
//由于采取覆盖，之后将标签值赋给i位置（覆盖）还原
//循环上步驻，直至左，右相遇，退出循环
//递归进行下次排序（传arr和i值）//保证当前轮最小数在最前作用
//递归进行下轮排序（传arr+i+1,sz-1-i）//下轮排序，排除当前第一个最小数

int selection_sort(int arr[],const int sz)//快速排序
{
	int left=0;//左
	int right=sz-1;//右
	int temp=arr[left];//标签
	assert(arr);//断言，arr不为空
	if(sz > 1)//退出排序条件
	{
		while(left < right)//当循环退出条件
		{
			for(;left<right;right--)//将比标签小的数放在前，left位置
				if(temp > arr[right])//left不变，right--
				{
				arr[left++]=arr[right];//left++是便于下次比较，标签不用与标签处（left）比较
				break;//退出
				}
			
			for(;left < right;left++)//将比标签大的数放在后，right位置
				if(temp < arr[left])//right不变，left++
			    {
				 arr[right--]=arr[left];//right--是便于下次比较，标签不用再与right比较
				 break;
				}
			arr[left]=temp;//还原覆盖的值（left处值覆盖成其它值）
		}//循环结束，小的数放在前，大的数放在后，不能保证第一个数最小
		//保证第一个数为当前轮为最小的数。
		selection_sort(arr,left);//从第一个数到退出循环时最小的数位置之间进行排序，第一轮结束
		selection_sort(arr+left+1,sz-left-1);//下轮循环，当前轮（left标记）第一个数已最小，去除不排
	}
}

static void change(int *arr,int *anum)//交换两个数
{
	int temp=0;
	assert(arr);//断言，arr不为空
	assert(anum);//断言，anum不为空
	temp=*arr;
	*arr=*anum;
	*anum=temp;
}

