/*
��Ϥ��ɢ�е�ԭ��ʵ�ֹ�ϣͰ 
Ҫ�� 
1. �������Ͷ����Դ��� 
2. ���ݽ��͹�ϣ��ͻ 

typedef char* K; 
typedef char* V; 

typedef struct Pair 
{ 
	K _key; 
	V _value; 
}Pair; 

typedef struct Node 
{ 
	struct Node* _pNext; 
	Pair _data; 
}Node, *PNode; 


typedef struct HashTable 
{ 
	PNode* _table; 
	unsigned long _capacity; 
	unsigned long _size; 
	PHF _DateToInt; 
}HT; 


////////////////////////////////////////////////////////// 
// .h 
void InitHashBucket(HT* ht, int capacity, PHF dataToInt); 
int InsertHashBucketUnique(HT* ht, K key, V v); 
int DeleteHashBucketUnique(HT* ht, K key); 

void InsertHashBucketEqual(HT* ht, K key, V v); 
int DeleteHashBucketEqual(HT* ht, K key); 
PNode FindHashBucket(HT* ht, K key); 
int CheckCapacity(HT* ht); 
void DestroyHashBucket(HT* ht); 

int HashFunc(HT* ht, K key); 
PNode BuyNode(K key, V value); 
void PrintHashBucket(HT* ht); 

��ϣ���ֵ����ݣ����дһƪ���� 
*/

#ifndef __HASHT_H__

#define __HASHT_H__


typedef char* typeT;
typedef char* typeV;

typedef size_t (*Comp)(const typeT str);

typedef struct Pari//���ݵ�Ԫ
{
	typeT _data;
	typeV _value;
}Pair;

typedef struct List//������
{
	Pair _cell;
	struct List* Next;
}Node,*pNode;

typedef struct HashTableT//��ϣ��
{
	pNode* _Data;//��ϣ���ݼ�������ָ��
	size_t _size;//���ݸ���
	size_t _capacity;//����
	Comp _com;//�ַ���ת��ֵ
}HTT;

void InitHashBucket(HTT* ht, int capacity, Comp com); //��ʼ��
int InsertHashBucketUnique(HTT* ht, typeT key, typeV v); //����
int DeleteHashBucketUnique(HTT* ht, typeT key); //ɾ��
void InsertHashBucketEqual(HTT* ht, typeT key, typeV v); 
int DeleteHashBucketEqual(HTT* ht, typeT key); 
pNode FindHashBucket(HTT* ht, typeT key); 
int CheckCapacity(HTT* ht); //�������
void DestroyHashBucket(HTT* ht); //����
void CleanHashBucket(HTT* ht); //���

size_t HashFunc(HTT* ht, typeT key); 
pNode BuyNode(typeT key, typeV value); 
void PrintHashBucket(HTT* ht); 

static size_t BKDRHashT(const char* str);//�ַ�����ϣ�㷨(�ַ���ת��ֵ)
static size_t intBKDRHashT(const typeT data);//�ַ����ִ���

void HashT_test();

#endif

//��ɢ��(������)
//��ϣͰ����ϣ���д�ŵĲ��������ݣ����Ǿ�����ͬӳ���ϵ������ı�ͷ
//��ϣ���д����һ���ṹ��ָ�����������ָ�룬���ڹ�ϣ������һ������(һ��ָ��)��ÿ��λ��Ϊһ������(����ָ��)
//��ϣ������key = ����%����
//ע���������ظ�����,�����ݵ�λ��ͰΪ�ա�
//ȱ�㣺����ͻ�Ƚϴ�ʱ���������ݵ�ʱ�临�Ӷ�����(����������)	
//����ŷ����ռ�����---���¼���ӳ���ַ�����Ų�(����ʱ���������ӽ�Ͱ����ʱ����)

//���ݣ�(size == capacity)
//����1����֮ǰ��ͬ
//����2��
//1����ȡ�¿ռ��С
//����һ���µĹ�ϣ������ݼ���(ԭ����2��)
//�����ɹ�ϣ��ѭ��������i < capacity;
//��ǰͰ��Ϊ��(ĳһλ��)
//{
//����ǰͰ�е�Ԫ�ط����µ�Ͱ�У�
//����һ���ڵ㣬�������ݿ����ڵ���
//��ȡӳ���ַ(%������)
//���ڵ���ӵ�ӳ���ַ��
//}
//ע��������Ͱ�е�����������⣺������ת����һ�������