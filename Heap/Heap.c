#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include"Heap.h"

int Less(type first,type end)//����
{
	return first > end;
}

int Greater(type first,type end)//С��
{
	return first < end;
}

void CreatHeap(Heap* Hp,type* arr, int size,Compare com)
{
	int i = 0;
	//�ѳ�ʼ��---���ٿռ�
	Hp->_data = (type*)malloc(sizeof(type)*size+3);//+3��Ϊ�˶�Ԥ���ռ��ֹԽ��
	assert(Hp->_data);
	Hp->_size = size;
	Hp->_capacity = size+3;
	Hp->com = com;
	//�����ݴ��
	for(i = 0; i < size; i++)
	{
		Hp->_data[i] = arr[i];
	}
	//����������ϵ������������һ���ڵ�ĸ��ڵ㿪ʼ���ϵ������������������µ���
	i = (size-2)>>1;//���һ���ڵ�ĸ��ڵ�
	for(; i >= 0; i--)//����������ϵ���
		AdjustDown(Hp,i);//�����������µ���
}

void Swap(int* first,int* end)
{
	int tmp = *first;
	*first = *end;
	*end = tmp;
}
void AdjustDown(Heap* heap,int parent)//�������µ���������������Ϊ�ѣ�
{
	int child = parent*2 + 1;//�ȼ�������С
	while(child < heap->_size)
	{     //+1��Ϊ���ж��Ƿ�����к���
		if(child+1 < heap->_size && heap->com(heap->_data[child] , heap->_data[child+1]))//С��
			child++;
		if(heap->com(heap->_data[parent] , heap->_data[child]))
		{
			Swap(&heap->_data[child],&heap->_data[parent]);
			parent = child;
		    child = parent*2 + 1;//�ȼ�������С
		}
		else
			return ;
	}
}

void AddCapacity(Heap* heap)//����
{
	if(heap->_size == heap->_capacity)
	{
		type* newheap = NULL;
		heap->_capacity *= 2;//����
		newheap = (type*)malloc(sizeof(type)*heap->_capacity);
		assert(newheap);
		memcpy(newheap,heap->_data,sizeof(type)*heap->_size);
		free(heap->_data);
		heap->_data = newheap;
	}
}
//������ĩβ�������ϵ���
void Insert(Heap* heap,type data)//����
{
	 assert(heap);
	 AddCapacity(heap);//��������
	 heap->_data[heap->_size++] = data;
	 if(heap->_size == 1)//ԭ����Ԫ�أ����õ���
		 return ;
	 Adjustheap(heap,heap->_size);
}

void Adjustheap(Heap* heap,int size)//�������ϵ���������������Ϊ�ѣ�
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
			parent = (child-1)>>1;//ȡ���ڵ�
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

void ClearHeap(Heap* heap)//���
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

//ɾ��----��β��ͷ������ɾ��β���ڽ���һ�����µ���
void Delete(Heap* heap)//ɾ��
{
	assert(heap || heap->_size > 0);
	Swap(&heap->_data[0],&heap->_data[heap->_size-1]);
	heap->_size--;
	AdjustDown(heap,0);//�����������µ���
}

void Heap_test()
{
	int arr[] ={9,1,5,3,4,8,6,7,0};
	int size = sizeof(arr)/sizeof(arr[0]);
	Heap heap;
	CreatHeap(&heap,arr,size,Greater);//�����
	Insert(&heap,2);//����
	Delete(&heap);//ɾ��
	PrintHeap(&heap);

	CreatHeap(&heap,arr,size,Less);//��С��
	Insert(&heap,2);//����
	PrintHeap(&heap);
	Delete(&heap);//ɾ��
	PrintHeap(&heap);
 }