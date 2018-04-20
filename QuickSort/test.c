#include<stdio.h>
#include<stdlib.h>
/*
int main()
{
	int arr[5] = {1,2,3,4,5};
	int * p = arr;
	int i = 0;

	*(p++) += 1;//同于*p = *(p++) + 1; *p = 2，优先级 * > p++,  *同于++，但*是从右向左运算，所以先执行++p  arr[0] = 2
	printf("%d,%d\n",*p,*++p);//3 3---形参实例化从右向左，先执行++p  *p = 3

	p = arr;
	*(p++) = *(p++) + 1; //arr[0] = 2; *p = 3
	printf("%d,%d\n",*p,*p++);//4 3 ---先执行*p后++ 值为3,再*p值为4  arr[0] = 3

	p =arr;
	*p = *(p++) + 1;//arr[0] = 4
	printf("%d,%d\n",*p,*++p);//3 3

	for(; i < 5; i++)
		printf("%d ",arr[i]);//4 2 3 4 5
	system("pause");
	return 0;
}
*/

int q_sort(int arr[],int sz);
void FSort(int arr[],int sz);
 void FSort2(int* arr,int right);


 void Swap(int* L,int* R)
 {
     int tmp = *L;
     *L = *R;
     *R = tmp;
 }


int _FastSort3(int*arr,int left,int right)
{
     int cur = left;
     int prev = left-1;//注此处要减一，因为prev标记的是前一个，下面都是先加++后比较的
     int key = arr[right-1];
	while(cur < right)
	{
		if(arr[cur] < key && ++prev != cur)
			Swap(&arr[cur],&arr[prev]);
		cur++;
	}
      
	if(++prev != right)
		Swap(&arr[prev],&arr[right-1]);
     return prev;
}

void FastSort(int* arr,size_t left,size_t right)
{

    if(arr && left < right)//递归出口
    {
        //size_t dev = _FastSort(arr,left,right);
        size_t dev = 0;
        //dev = _FastSort2(arr,left,right);//单轮处理
        dev = _FastSort3(arr,left,right);//单轮处理
        FastSort(arr,left,dev);//处理前面部分
        FastSort(arr,dev+1,right);//处理后面部分
    }

}

//堆向下调整
void AdjustDown(int* arr,int size,int parent)
{
	int child = parent*2+1;
	while(child < size)
	{
		if(child+1 < size && arr[child] < arr[child+1])
			child++;
		if(arr[parent] < arr[child])
		{
			Swap(&arr[parent],&arr[child]);
			parent = child;
			child = parent*2+1;
		}
		else
			return ;
	}
}

//堆排序
void HeapSort(int* arr,int size)
{
	int parent = (size-2) >> 1;
	int i = 0;
	if(!arr || size < 1)
		return ;
	
	//堆调整
	for(i = parent; i >= 0;i--)
		AdjustDown(arr,size,i);
	//堆排序	
	for(i = size-1; i > 0;)
	{
		Swap(&arr[0],&arr[i]);//将堆顶与当前最后一个元素交换
		AdjustDown(arr,i,0);//从堆顶向下调整(调整i个元素),注此处是一个开区间，所以i在之后--
		i--;
	}
}

 void Mrege(int* arr,int size);

int main()
{
	int i=0;
	//int arr[]={1,3,4,6,9,8,2,5,5,6,8,2,31,23,98,100,25,10,87};
	 int arr[] = {1,9,9,9,4,6,9,8,2,0};
	int sz=sizeof(arr)/sizeof(arr[0]);
	for(i=0;i<sz;i++)
	{
		printf("%d  ",arr[i]);
	}
	printf("\n");
	//q_sort(arr,sz);
	//FSort2(arr,sz);
	 Mrege(arr,sz);
	//FastSort(arr,0,sz);
	//HeapSort(arr,sz);

	for(i=0;i<sz;i++)
	{
		printf("%d  ",arr[i]);
	}
	system("pause");
	return 0;
}

int q_sort(int arr[],int sz)
{
	int i=0;
	int j=sz-1;
	int key=arr[0];//保存左值
	
	if(sz>1)//1个数不排序
	{
		while(i < j)
		{
			while(i<j && key<=arr[j])
				j--;
			if(i<j)
			arr[i++]=arr[j];//赋给左值（左值被赋盖）

			while(i<j && key>=arr[i])
				i++;
			if(i<j)
			arr[j--]=arr[i];//赋给右值（右值被赋盖）

			arr[i]=key;//还原赋盖值
		}
		q_sort(arr,i);
		q_sort(arr+i+1,sz-i-1);
	}
}

//获取中间值，并将中间值调到最前
int In(int* arr,int L,int R)
{
	int mid = L+((R-L)>>1);
	if(arr[mid] > arr[R])
		Swap(&arr[mid],&arr[R]);
	if(arr[L] > arr[R])
		Swap(&arr[L],&arr[R]);
	if(arr[mid] > arr[L])
		Swap(&arr[mid],&arr[L]);

	return arr[L];//最左侧值作为参考值
}


//快排优化---三数取中法(尽量进行平均划分)
void FSort2(int* arr,int right)
{
	int left = 0;
	int end = right-1;
	
	//if(!arr || left >= end)
	//	return ;
	//int key = arr[0];
	int key = In(arr,left,end);
	if(right > 1)
	{
		while(left < end)//循环处理至左与右相遇，才一轮处理完毕
		{

			//处理右侧小于key的值
			while(left < end && arr[end] >= key)
				end--;
			if(left < end)
				arr[left++] = arr[end];

			//处理左侧小于key的值
			while(left < end && arr[left] <= key)
				left++;
			if(left < end)
				arr[end--] = arr[left];//key处的值被覆盖
		
			arr[left] = key;
		}
		//arr[left] = key;//还原key值
		FSort2(arr,left);
		FSort2(arr+left+1,right-left-1);
	}
}

void FSort(int* arr,int right)
{
	int left = 0;
	int end = right-1;
	//if(!arr || left >= end)
	//	return ;
	int key = arr[0];
	if(right >1)
	{
		while(left < end)//循环处理至左与右相遇，才一轮处理完毕
		{

			//处理右侧小于key的值
			while(left < end && arr[end] >= key)
				end--;
			if(left < end)
				arr[left++] = arr[end];

			//处理左侧小于key的值
			while(left < end && arr[left] <= key)
				left++;
			if(left < end)
				arr[end--] = arr[left];//key处的值被覆盖
		
			arr[left] = key;
		}
		//arr[left] = key;//还原key值
		FSort(arr,left);
		FSort(arr+left+1,right-left-1);
	}
}

#include<string.h>
//桶排序
static int Maxnum(int* arr,int size)
{
	int i = 1;
	int max = arr[0];
	for(; i < size; i++)
	{
		if(max < arr[i])
			max = arr[i];
	}
	return max;
}
void Mrege(int* arr,int size)
{
	
	int* bulack = (int*)malloc(sizeof(int)*size);
	int i = 0;
	int bitnum = 1;
	int maxnum = Maxnum(arr,size);//最大数据
	while(bitnum < maxnum*10)//循环次数(位)
	{
		int count[10] = {0};//统计每个桶的元素个数
		int startadds[10] = {0};//统计每个桶的起始地址

		////统计每个桶中的数据个数
		for(i = 0; i < size; i++)
			count[(arr[i]/bitnum)%10]++;

		//桶及每个桶的起始位置
		for(i = 1; i < 10; i++)
			startadds[i] = startadds[i-1]+count[i-1];

		//将数据放在对应的桶中
		for(i = 0; i < size; i++)
		{
			int n = arr[i]/bitnum%10;//数据映射位置
			bulack[startadds[n]++] = arr[i];
		}
		//将数据放回数组中
		memmove(arr,bulack,sizeof(int)*size);
		//处理更高位
		bitnum *= 10;
	}
	free(bulack);
}



/*
template<class T>
size_t _FastSort2(T* arr,size_t left,size_t right)
{
	int begin = left;
	int end = right-1;
	if(!arr && left >= right)
	return 0;
	T key = arr[end];
	while(begin < end)
	{
		//T key = arr[end];
		while(begin < end && arr[begin] <= key)
			begin++;
		if(begin < end)
		arr[end--] = arr[begin];
		while(begin < end && arr[end] >= key)
			end--;
		if(begin < end)
		arr[begin++] = arr[end];
	//	if(begin < right-1)
		arr[begin] = key;
	}
	return begin;
}

*/
//
//#include<stdio.h>
//#include<stdlib.h>
//int partition(int arr[],int left,int right);
//void qsort(int arr[],int left,int right);
//int main()
//{
//	int arr[]={32,12,7,78,23,45};
//    int i=0;
//	qsort(arr,0,5);
//	for(i=0;i<6;i++)
//		printf("%d  ",arr[i]);
//	system("pause");
//	return 0;
//}
//
//void qsort(int arr[],int left,int right)
//{
//	int dp;
//	if(left<right)
//	{
//		dp=partition(arr,left,right);
//		qsort(arr,left,dp-1);
//		qsort(arr,dp+1,right);
//	}
//}
//
//int partition(int arr[],int left,int right)
//{
//	int temp=arr[left];
//
//	while(left < right)
//	{
//		while(left<right && arr[right]>=temp)
//			right--;
//			if(left<right)
//			arr[left++]=arr[right];
//		while(left<right && arr[left]<=temp)
//			left++;
//			if(left<right)
//			arr[right--]=arr[left];
//	}
//	arr[left]=temp;
//    return left;
//}


//#include <stdio.h>
//#include <stdlib.h>
//#define N 6
//int partition(int arr[], int low, int high)
//{
//    int key;
//    key = arr[low];
//    while(low<high)
//	{
//        while(low <high && arr[high]>= key )
//            high--;
//        if(low<high)
//            arr[low++] = arr[high];
//        while( low<high && arr[low]<=key )
//            low++;
//        if(low<high)
//            arr[high--] = arr[low];
//    }
//    arr[low] = key;
//    return low;
//}
//
//void quick_sort(int arr[], int left, int right){
//    int pos;
//    if (left<right){
//        pos = partition(arr, left, right);
//        quick_sort(arr,left,pos-1);
//        quick_sort(arr,pos+1,right);
//    }
//    return;
//}
//
//int main(void){
//    int i;
//    int arr[N]={32,12,7, 78, 23,45};
//    printf("排序前 \n");
//    for(i=0;i<N;i++)
//        printf("%d\t",arr[i]);
//    quick_sort(arr,0,N-1);
//    printf("\n 排序后 \n");
//    for(i=0; i<N; i++)
//        printf("%d\t", arr[i]);
//    printf ("\n");
//    system("pause");
//    return 0;
//}

