#include<stdio.h>
#include<stdlib.h>
int binary_search(const int arr[],const int data,int left,int right);//递归二分查找
int choose_search(int arr[],const int sz);//选择排序
int choose_search1(int arr[],int sz);//优化选择排序
static void change(int *arr,int *anum);
void print(const int arr[],const int sz);//输出
int main()
{

	int arr[]={2,1,3,5,9,8,6,7,0,12,65,98,32,11,22,33,41,11};
	int sz=sizeof(arr)/sizeof(arr[0]);
	int data=0;
	int num=0;

	print(arr,sz);
	choose_search1(arr,sz);
	print(arr,sz);

	print(arr,sz);
	choose_search(arr,sz);
	print(arr,sz);

	printf("put data:");
	scanf("%d",&data);
	
	num=binary_search(arr,data,0,sz);
	printf("下标为：%d\n",num);
	choose_search(arr,sz);
	system("pause");
	return 0;
}

int binary_search(const int arr[],const int data,int left,int right)
{
	int mid=left+((right-left)>>1);
	if(left >= right)//未找到,由于传参时sz未减一，所以取等号
	{
		return -1;
	}
	else if(arr[mid]<data)//右侧
	{
		binary_search(arr,data,mid+1,right);
	}
	else if(arr[mid]>data)//左侧
	{
		binary_search(arr,data,left,mid-1);
	}
	else//找到
		return mid;
}

int choose_search(int arr[],const int sz)//选择排序
{
	int i=0,j=0;
	int temp=0;
	int test;
	for(i=0;i<sz-1;i++)//一个数不用比较
	{
		temp=0;//每轮假设第一个数最大
		for(j=0;j<sz-i;j++)//每次arr[j]都和temp比较，所以不减一
		{
			if(arr[j]>arr[temp])
				temp=j;//标记下标
		}
		//交换两个数，不可用异或交换，应为不交换位置时出错
		test=arr[sz-i-1];
		arr[sz-i-1]=arr[temp];
		arr[temp]=test;
	}
}

void print(const int arr[],const int sz)//输出
{
	int i=0;
	for(i=0;i<sz;i++)
	printf("%d  ",arr[i]);
	printf("\n");
}


int choose_search1(int arr[],int sz)//优化选择排序
{
	int max_num=sz-1;
	int min_num=0;
	int i=0;
	int j=0;
	//一次同时找出最大与最小的数
	while(min_num<max_num)
	{
		for(i=j+1;i<sz-j;i++)
		{
			if(arr[i]>arr[max_num])//找出最大数
				max_num=i;
			if(arr[i]<arr[min_num])//找出最小数
				min_num=i;
		}

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

static void change(int *arr,int *anum)
{
	int temp=0;
	temp=*arr;
	*arr=*anum;
	*anum=temp;
}

