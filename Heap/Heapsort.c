#include<stdlib.h>
#include"Heap.h"
#include"Heapsort.h"
//堆排序---升序：建大堆，   降序：建小堆
//时间复杂度：N*lgN + NlgN
//1、先建一个大堆
//2、将堆顶与堆尾交换
void AdjustSort(Heap* heap,int end)
{
	int parent = 0;//先假设左孩子小
	int child = parent*2+1;
	while(child < end)
	{     //+1是为了判断是否存右有孩子
		if(child+1 < heap->_size && heap->com(heap->_data[child] , heap->_data[child+1]))//小堆
			child++;
		if(heap->com(heap->_data[parent] , heap->_data[child]))
		{
			Swap(&heap->_data[child],&heap->_data[parent]);
			parent = child;
		    child = parent*2 + 1;//先假设左孩子小
		}
		else
			return ;
	}
}

void sort(type* arr,size_t sz,Compare com)
{
	Heap h;
	int i = sz-1;
	CreatHeap(&h,arr,sz,com);//建堆
	while(i > 1)//只有一个元素时退出
	{
		Swap(&h._data[0],&h._data[i]);
		i--;
		AdjustSort(&h,i);//单步向下调整,每轮调整后，下次不在调整最后一个元素
	}
	 PrintHeap(&h);//输出
	 ClearHeap(&h);//清空
}

void sort_test()
{
	type arr[] = {1,2,9,8,5,6,3,4};
	size_t sz = sizeof(arr)/sizeof(arr[0]);
	sort(arr,sz,Less);//降序
	sort(arr,sz,Greater);//升序
}


//*****************************************************

//找出极多个数中的最大K个数
//解决方法：
//1、先选K个数放在数组中
//2、对数组排序从小到大
//3、取其它的数与数组中第一个元素进行比较，大的进行交换，交换后重新进行排序
//4、循环3直到将所有数据比较完，最终数组的值即为最大的K个数据
//即使用堆进行按上述方法进行处理时间复杂度较小（NlgK）
//查找大数据建小堆，查找小数据建大堆

type* HeapTopD(Heap* heap)
{
	return &heap->_data[0];
}

void test()
{
	type num[] = {10,2,3,5,6,9,8,7,4,11,22,33,66,55,99,88,66,4,0,12,100};
	size_t sz = sizeof(num)/sizeof(num[0]);
	size_t i = 0;
	Heap heap;
	size_t K = 5;//查找最大的5个数据
	type arr[5];
	for(i = 0; i < K; i++)
		arr[i] = num[i];

	CreatHeap(&heap,arr,K,Less);//建小堆
	PrintHeap(&heap);//输出

	while(i < sz)
	{
		type Top = HeapTop(&heap);//获取堆顶
		if(Top < num[i])
		{
			Swap(&num[i],HeapTopD(&heap));
		    AdjustDown(&heap,0);//单步向下调整，（左右子树为堆）
		}
		i++;
	}
	PrintHeap(&heap);//输出
}

//思考：如何寻找出现次数最多的K个数据
//数据结构：使用结构体类型变量作为数据类型(树和堆都相同)，包含数据，和出现的次数
//统计次数----搜索树
//创建一个搜索树统计次数，每中元素为一个节点(数据)，根据数据建
//取元素与树中元素比较，在树中，对应的数据次数+1，不在树中，添加到树中

//查找出现次数最多------采用堆实现
//建一个具有K个元素的堆，以次数建堆
//依次取搜索树中数据的次数与堆顶比较，比堆顶大交换数据后向下调整，比堆小不变
//依次循环直至取完所有的树中数据。
//最后堆中即为出现次数最多的K个数据



//堆存储数据结构选择：结构体（数据，出现次数）
//建一个大小为1的堆，堆按出现的次数排序(堆增大到K)
//每个数值与堆中的数值比较(堆查找)
//找到将堆中对应的数据的计数器+1， 没找到且堆数据 < K个，入堆，否则(堆满)堆中的所有计数器减1
//依次循环遍历完所有数据

