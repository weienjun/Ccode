#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include"HashT.h"

void InitHashBucket(HTT* ht, int capacity, Comp com) //��ʼ��
{
	size_t i = 0;
	assert(ht);
	ht->_com = com;
	ht->_size = 0;
	ht->_capacity = capacity;
	ht->_Data = (pNode*)malloc(sizeof(Node*)*ht->_capacity);//��ϣ��ĳ��ȴ�С
	for(; i < ht->_capacity; i++)//��ʼ��ÿ��ͰΪNULL
		ht->_Data[i] = NULL;
}

int InsertHashBucketUnique(HTT* ht, typeT key, typeV v) //����
{
	size_t idx = 0;
	pNode prev = NULL;
	pNode cur = NULL;
	assert(ht);
	idx = HashFunc(ht, key);
	cur = ht->_Data[idx];
	//��λ��������---����������
	if(cur == NULL)
	{
		ht->_Data[idx] = BuyNode(key, v);//�����½ڵ�
		ht->_size++;
		return 1;
	}
	//��λ��������---����������
	while(cur)//���뵽Ϊ�յ�λ��
	{
		if(cur->_cell._data == key)//�����Ѵ���
			return 0;//�������ظ�����
		prev = cur;
		cur = cur->Next;
	}
	cur = BuyNode(key, v);//�����½ڵ�
	prev->Next = cur;
	ht->_size++;
	return 1;
}

int DeleteHashBucketUnique(HTT* ht, typeT key)//ɾ��
{
	size_t idx = 0;
	pNode cur = NULL;
	pNode del = NULL;
	assert(ht);
	idx = HashFunc(ht, key);
	cur = ht->_Data[idx];
	//��λ��������---�Ա��Ƿ�ɾ��
	while(cur)//λ��������
	{
		//�����Ƿ���ͬ---��ͬɾ��
		del = cur;
		cur = cur->Next;
		if(strcmp(del->_cell._data , key) == 0)
		{
			ht->_Data[idx] = cur;
			free(del);
			del = NULL;
			ht->_size--;
			return 1;//�������ظ�����
		}
	}
	return 0;
}

size_t HashFunc(HTT* ht, typeT key)
{
	return ht->_com(key)%ht->_capacity;
}
//����һ���ڵ�
pNode BuyNode(typeT key, typeV value)
{
	pNode newNode = (pNode)malloc(sizeof(Node));
	newNode->_cell._data = key;
	newNode->_cell._value = value;
	newNode->Next = NULL;
	return newNode;
}
void PrintHashBucket(HTT* ht)
{
	size_t i = 0;
	size_t j = 0;
	assert(ht);

	for(; i < ht->_capacity; i++)
	{
		pNode cur = ht->_Data[i];
		while(cur)
		{
			printf("%s %s\n",cur->_cell._data,cur->_cell._value);
			cur = cur->Next;
		}
	}
}

void InsertHashBucketEqual(HTT* ht, typeT key, typeV v)
{
	size_t idx = 0;
	pNode prev = NULL;
	pNode cur = NULL;
	assert(ht);
	idx = HashFunc(ht, key);
	cur = ht->_Data[idx];
	//��λ��������---����������
	if(cur == NULL)
	{
		ht->_Data[idx] = BuyNode(key, v);//�����½ڵ�
		return ;
	}
	//��λ��������---����������
	while(cur)//���뵽Ϊ�յ�λ��
	{
		prev = cur;
		cur = cur->Next;
	}
	cur = BuyNode(key, v);//�����½ڵ�
	prev->Next = cur;
	ht->_size++;
}

int DeleteHashBucketEqual(HTT* ht, typeT key)
{
	size_t sz = ht->_size;
	size_t idx = 0;
	pNode del = NULL;
	pNode cur = NULL;
	assert(ht);
	idx = HashFunc(ht, key);
	cur = ht->_Data[idx];
	//��λ��������---�Ա��Ƿ�ɾ��
	while(cur)//λ��������
	{
		//�����Ƿ���ͬ---��ͬɾ��
		del = cur;//ͷɾ
		cur = cur->Next;
		if(strcmp(del->_cell._data , key) == 0)
		{
			if(del == ht->_Data[idx])//����ɾͷ����
			    ht->_Data[idx] = cur;//����ͷ�ڵ�
			free(del);
			del = NULL;
			ht->_size--;
		}
	}

	if(sz < ht->_size)//�ж��Ƿ�ɾ��������
		return 1;
	return 0;
}
pNode FindHashBucket(HTT* ht, typeT key)
{
	size_t idx = 0;
	pNode cur = NULL;
	assert(ht);
	idx = HashFunc(ht, key);
	cur = ht->_Data[idx];
	//��λ��������---�Ա��Ƿ���ͬ
	while(cur)//λ��������
	{
		//�����Ƿ���ͬ---��ͬ��ַ
		if(strcmp(cur->_cell._data , key) == 0)
		{
			return cur;
		}
		cur = cur->Next;
	}
	return NULL;
}

int CheckCapacity(HTT* ht)
{
	return ht->_capacity;
}
void DestroyHashBucket(HTT* ht)//����
{
	CleanHashBucket(ht); //���
	free(ht->_Data);
	ht->_Data = NULL;
}

void CleanHashBucket(HTT* ht) //���
{
	pNode cur = NULL;
	size_t i = 0;
	pNode del =NULL;
	assert(ht);
	for(; i < ht->_capacity ;i++)//��չ�ϣ��(���ÿ��Ͱ)
	{
		del = ht->_Data[i];
		while(cur)//���ÿ��Ͱ�е�����
		{
			/*
			del = cur->Next;
			cur = del->Next;
			free(del);
			del = NULL;
			*/
			del = cur;
			cur = del->Next;
			free(del);
			del = NULL;
		}
	}
}

static size_t BKDRHashT(const char* str)//�ַ�����ϣ�㷨(�ַ���ת��ֵ)
{
	unsigned int seed = 131;
	unsigned int hash = 0;
	while(*str)
	{
		hash = hash * seed + (*str++);
	}
	return (hash & 0x7FFFFFFF);
}

static size_t intBKDRHashT(const typeT data)//�ַ����ִ���
{
	return (unsigned int)data;
}

void HashT_test()
{
	HTT ht;
	InitHashBucket(&ht, 100, BKDRHashT); //��ʼ��
    InsertHashBucketUnique(&ht, "123", "����"); //����
    InsertHashBucketEqual(&ht, "25", "����"); 
    InsertHashBucketUnique(&ht, "123", "����"); //����
    DeleteHashBucketUnique(&ht, "25"); //ɾ��

    InsertHashBucketEqual(&ht, "256", "����"); 
    InsertHashBucketEqual(&ht, "26", "����"); 
    InsertHashBucketEqual(&ht, "26", "����"); 
    InsertHashBucketEqual(&ht, "256", "����"); 
    DeleteHashBucketEqual(&ht, "26"); 
    printf("%p\n",FindHashBucket(&ht, "256")); 
    printf("%d\n",CheckCapacity(&ht)); //�������
    PrintHashBucket(&ht); 

    CleanHashBucket(&ht); //���
	DestroyHashBucket(&ht); //����


}