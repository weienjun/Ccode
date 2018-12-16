#include<stdlib.h>
#include"Heap.h"
#include"Heapsort.h"
//������---���򣺽���ѣ�   ���򣺽�С��
//ʱ�临�Ӷȣ�N*lgN + NlgN
//1���Ƚ�һ�����
//2�����Ѷ����β����
void AdjustSort(Heap* heap,int end)
{
	int parent = 0;//�ȼ�������С
	int child = parent*2+1;
	while(child < end)
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

void sort(type* arr,size_t sz,Compare com)
{
	Heap h;
	int i = sz-1;
	CreatHeap(&h,arr,sz,com);//����
	while(i > 1)//ֻ��һ��Ԫ��ʱ�˳�
	{
		Swap(&h._data[0],&h._data[i]);
		i--;
		AdjustSort(&h,i);//�������µ���,ÿ�ֵ������´β��ڵ������һ��Ԫ��
	}
	 PrintHeap(&h);//���
	 ClearHeap(&h);//���
}

void sort_test()
{
	type arr[] = {1,2,9,8,5,6,3,4};
	size_t sz = sizeof(arr)/sizeof(arr[0]);
	sort(arr,sz,Less);//����
	sort(arr,sz,Greater);//����
}


//*****************************************************

//�ҳ���������е����K����
//���������
//1����ѡK��������������
//2�������������С����
//3��ȡ���������������е�һ��Ԫ�ؽ��бȽϣ���Ľ��н��������������½�������
//4��ѭ��3ֱ�����������ݱȽ��꣬���������ֵ��Ϊ����K������
//��ʹ�öѽ��а������������д���ʱ�临�ӶȽ�С��NlgK��
//���Ҵ����ݽ�С�ѣ�����С���ݽ����

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
	size_t K = 5;//��������5������
	type arr[5];
	for(i = 0; i < K; i++)
		arr[i] = num[i];

	CreatHeap(&heap,arr,K,Less);//��С��
	PrintHeap(&heap);//���

	while(i < sz)
	{
		type Top = HeapTop(&heap);//��ȡ�Ѷ�
		if(Top < num[i])
		{
			Swap(&num[i],HeapTopD(&heap));
		    AdjustDown(&heap,0);//�������µ���������������Ϊ�ѣ�
		}
		i++;
	}
	PrintHeap(&heap);//���
}

//˼�������Ѱ�ҳ��ִ�������K������
//���ݽṹ��ʹ�ýṹ�����ͱ�����Ϊ��������(���ͶѶ���ͬ)���������ݣ��ͳ��ֵĴ���
//ͳ�ƴ���----������
//����һ��������ͳ�ƴ�����ÿ��Ԫ��Ϊһ���ڵ�(����)���������ݽ�
//ȡԪ��������Ԫ�رȽϣ������У���Ӧ�����ݴ���+1���������У���ӵ�����

//���ҳ��ִ������------���ö�ʵ��
//��һ������K��Ԫ�صĶѣ��Դ�������
//����ȡ�����������ݵĴ�����Ѷ��Ƚϣ��ȶѶ��󽻻����ݺ����µ������ȶ�С����
//����ѭ��ֱ��ȡ�����е��������ݡ�
//�����м�Ϊ���ִ�������K������



//�Ѵ洢���ݽṹѡ�񣺽ṹ�壨���ݣ����ִ�����
//��һ����СΪ1�Ķѣ��Ѱ����ֵĴ�������(������K)
//ÿ����ֵ����е���ֵ�Ƚ�(�Ѳ���)
//�ҵ������ж�Ӧ�����ݵļ�����+1�� û�ҵ��Ҷ����� < K������ѣ�����(����)���е����м�������1
//����ѭ����������������

