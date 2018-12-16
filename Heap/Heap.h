#ifndef __HEAP_H__

#define __HEAP_H__


typedef int type;

typedef int (*Compare)(type first,type end);//定一个函数指针
//注：compent表示类型，重定义的类型名,作用类似于C++中的仿函数
//int (*)(type first,type end);---->表示类型，可定义变量
//int (*p)(type first,type end);---->p表示变量，可赋值



typedef struct Heap//堆数据
{
	type* _data;
	int _size;
	int _capacity;
	Compare com ;//堆的类别
}Heap;

void CreatHeap(Heap* Hp,type* arr, int size,Compare com);//建堆
void AdjustDown(Heap* heap,int parent);//单步向下调整，（左右子树为堆）
void Swap(int* first,int* end);//交换数据
void Adjustheap(Heap* heap,int parent);//单步向上调整，（左右子树为堆）

void Insert(Heap* heap,type data);//插入
void AddCapacity(Heap* heap);//扩容
void Delete(Heap* heap);//删除
void PrintHeap(Heap* heap);//输出
void ClearHeap(Heap* heap);//清空

size_t HeapSize(Heap* heap);
int Empity(Heap* heap);
type HeapTop(Heap* heap);

int Less(type first,type end);//小于
int Greater(type first,type end);//大于

void Heap_test();

#endif