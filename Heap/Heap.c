#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include"Heap.h"

int Less(type first,type end)//大于
{
	return first > end;
}

int Greater(type first,type end)//小于
{
	return first < end;
}

void CreatHeap(Heap* Hp,type* arr, int size,Compare com)
{
	int i = 0;
	//堆初始化---开辟空间
	Hp->_data = (type*)malloc(sizeof(type)*size+3);//+3是为了多预留空间防止越界
	assert(Hp->_data);
	Hp->_size = size;
	Hp->_capacity = size+3;
	Hp->com = com;
	//堆数据存放
	for(i = 0; i < size; i++)
	{
		Hp->_data[i] = arr[i];
	}
	//整体从下向上调整（即从最后一个节点的父节点开始向上调整），单步从上向下调整
	i = (size-2)>>1;//最后一个节点的父节点
	for(; i >= 0; i--)//整体从下向上调整
		AdjustDown(Hp,i);//单步从上向下调整
}

void Swap(int* first,int* end)
{
	int tmp = *first;
	*first = *end;
	*end = tmp;
}
void AdjustDown(Heap* heap,int parent)//单步向下调整，（左右子树为堆）
{
	int child = parent*2 + 1;//先假设左孩子小
	while(child < heap->_size)
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

void AddCapacity(Heap* heap)//扩容
{
	if(heap->_size == heap->_capacity)
	{
		type* newheap = NULL;
		heap->_capacity *= 2;//扩容
		newheap = (type*)malloc(sizeof(type)*heap->_capacity);
		assert(newheap);
		memcpy(newheap,heap->_data,sizeof(type)*heap->_size);
		free(heap->_data);
		heap->_data = newheap;
	}
}
//插入在末尾，后向上调整
void Insert(Heap* heap,type data)//插入
{
	 assert(heap);
	 AddCapacity(heap);//容量处理
	 heap->_data[heap->_size++] = data;
	 if(heap->_size == 1)//原来无元素，不用调整
		 return ;
	 Adjustheap(heap,heap->_size);
}

void Adjustheap(Heap* heap,int size)//单步向上调整，（左右子树为堆）
{
	int child = size-1;
	int parent = (child-1)>>1;
	while(parent >= 0)
	{
		if(child+1 < heap->_size && heap->com(heap->_data[child] , heap->_data[child+1]))
			child++;
		if(heap->com(heap->_data[parent] , heap->_data[child]))
		{
			Swap(&heap->_data[parent],&heap->_data[child]);
			child = parent;
			parent = (child-1)>>1;//取父节点
		}
		else
			return ;
	}
}

void PrintHeap(Heap* heap)
{
	int sz = 0;
	while(sz < heap->_size)
	{
		printf("%d ",heap->_data[sz++]);
	}
	printf("\n");
}

void ClearHeap(Heap* heap)//清空
{
	free(heap->_data);
	heap->_data = NULL;
	heap->_size = 0;
	heap->_capacity = 0;
}

size_t HeapSize(Heap* heap)
{
	assert(heap);
	return heap->_size;
}
int Empity(Heap* heap)
{
	assert(heap);
	return heap->_size != 0;
}
type HeapTop(Heap* heap)
{
	assert(heap);
	return heap->_data[0];
}

//删除----将尾与头交换，删除尾，在进行一次向下调整
void Delete(Heap* heap)//删除
{
	assert(heap || heap->_size > 0);
	Swap(&heap->_data[0],&heap->_data[heap->_size-1]);
	heap->_size--;
	AdjustDown(heap,0);//单步从上向下调整
}

void Heap_test()
{
	int arr[] ={9,1,5,3,4,8,6,7,0};
	int size = sizeof(arr)/sizeof(arr[0]);
	Heap heap;
	CreatHeap(&heap,arr,size,Greater);//建大堆
	Insert(&heap,2);//插入
	Delete(&heap);//删除
	PrintHeap(&heap);

	CreatHeap(&heap,arr,size,Less);//建小堆
	Insert(&heap,2);//插入
	PrintHeap(&heap);
	Delete(&heap);//删除
	PrintHeap(&heap);
 }