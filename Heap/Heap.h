#ifndef __HEAP_H__

#define __HEAP_H__


typedef int type;

typedef int (*Compare)(type first,type end);//��һ������ָ��
//ע��compent��ʾ���ͣ��ض����������,����������C++�еķº���
//int (*)(type first,type end);---->��ʾ���ͣ��ɶ������
//int (*p)(type first,type end);---->p��ʾ�������ɸ�ֵ



typedef struct Heap//������
{
	type* _data;
	int _size;
	int _capacity;
	Compare com ;//�ѵ����
}Heap;

void CreatHeap(Heap* Hp,type* arr, int size,Compare com);//����
void AdjustDown(Heap* heap,int parent);//�������µ���������������Ϊ�ѣ�
void Swap(int* first,int* end);//��������
void Adjustheap(Heap* heap,int parent);//�������ϵ���������������Ϊ�ѣ�

void Insert(Heap* heap,type data);//����
void AddCapacity(Heap* heap);//����
void Delete(Heap* heap);//ɾ��
void PrintHeap(Heap* heap);//���
void ClearHeap(Heap* heap);//���

size_t HeapSize(Heap* heap);
int Empity(Heap* heap);
type HeapTop(Heap* heap);

int Less(type first,type end);//С��
int Greater(type first,type end);//����

void Heap_test();

#endif