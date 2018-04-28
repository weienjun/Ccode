/*
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include"HashTable.h"

void InitHashTable(HT* ht)//��ʼ��
{
	size_t i = 0;
	assert(ht);
	ht->_capacity = 3;//�������ռ�
	ht->_size = 0;
	ht->_Data = (Endm*)malloc(sizeof(Endm)*ht->_capacity);
	assert(ht->_Data);
	for(; i < ht->_capacity; i++)
		ht->_Data[i]._state = Empty;//״̬�ÿ�
}

size_t DetectiveLine(HT* ht,size_t key)//����̽��
{
	key++;
	if(key >= ht->_capacity)
		key = 0;
	return key;
}

void AddSerave(HT* ht,size_t key)//����
{
	if(ht->_size == ht->_capacity || key >= ht->_capacity)
	{
		size_t i = 0;
		Endm* newData = NULL;

		ht->_capacity = key;//����key
		while(ht->_capacity < key || ht->_size >= ht->_capacity)
			ht->_capacity *= 2;//��������2��

		newData = (Endm*)malloc(sizeof(Endm)*ht->_capacity);
		assert(newData);
		memcpy(newData,ht->_Data,sizeof(Endm)*ht->_size);
		free(ht->_Data);
		ht->_Data = newData;
		//��ʼ������λ��״̬
		for(i = ht->_size; i < ht->_capacity; i++)
			ht->_Data[i]._state = Empty;
	}
}

size_t HashFunk(HT* ht,type data)//��ϣ����(��ȡӳ���ַ)
{
	return data % (ht->_capacity);//�˴�Ӧģȡ��ӽ�(<=����)����������
}

void InsertHashTable(HT* ht,type data)//����
{
	size_t key = 0;
	key = HashFunk(ht,data);//��ϣ����(��ȡӳ���ַ)
	AddSerave(ht,key);//���ݴ���
	//Ѱ�ҿɲ���λ�ã��գ���ɾ���ǿգ�
	while(ht->_Data[key]._state == Exist)
	{
		//����̽��
		key = DetectiveLine(ht,key);
	}
	//ht->_Data[key]._data = 1;
	ht->_Data[key]._data = data;
	ht->_Data[key]._state = Exist;
	ht->_size++;
}

int FindHashTable(HT* ht,type data)//����
{
	size_t key = HashFunk(ht,data);//��ϣ����(��ȡӳ���ַ)
	size_t tmp = key;//�����ʼ���ҵ�ַ
	assert(ht);
	if(ht->_size == 0)
		return -1;

	while(ht->_Data[key]._state != Empty)
	{
		//if(key == data)//�ַ�Ӧ�ô������
		//return key;

		if(ht->_Data[key]._data == data)
			return key;
		//����̽��
		key = DetectiveLine(ht,key);

		if(key == tmp)//�ٴε���key--->δ�ҵ�
			break;
	}
	return -1;
}

void DeleteHashTable(HT* ht,type data)//ɾ��
{
	size_t key = 0;
	assert(ht);
	key = FindHashTable(ht,data);//����
	if(key < 0)//δ�ҵ�
		return ;
	ht->_Data[key]._state = DExist;
	ht->_size--;
}

void PrintHashTable(HT* ht)
{
	size_t i = 0;
	while(i < ht->_capacity)
	{
		if(ht->_Data[i]._state == Exist)
		printf("%d ",ht->_Data[i]);
		i++;
	}
	printf("\n");
}

void Hash_test()//����
{
	HT ht;
    InitHashTable(&ht);//��ʼ��
	AddSerave(&ht,10);//����
    InsertHashTable(&ht,1);//����
    InsertHashTable(&ht,3);//����
    DeleteHashTable(&ht,1);//ɾ��
    InsertHashTable(&ht,11);//����

    InsertHashTable(&ht,1);//����
    InsertHashTable(&ht,9);//����
    InsertHashTable(&ht,2);//����
    InsertHashTable(&ht,8);//����
	InsertHashTable(&ht,9);//����
    InsertHashTable(&ht,2);//����
    InsertHashTable(&ht,8);//����
    InsertHashTable(&ht,0);//����

    printf("%d\n",FindHashTable(&ht,2));//����
    DeleteHashTable(&ht,1);//ɾ��
    InsertHashTable(&ht,1);//����
    InsertHashTable(&ht,4);//����

    PrintHashTable(&ht);
}

/*
//�ַ�Ӧ�ô���
void Application_test()
{
	char ch[] = {"ahabccdssdfzkycbabcsd"};
	int i = 0;
	size_t sz = sizeof(ch)/sizeof(ch[0]);
	HT hc;
	InitHashTable(&hc);//��ʼ��
	AddSerave(&hc,255);//����
	//�����ַ���Ӧ����ֵ�����ڶ�Ӧ�Ĺ�ϣ���ַ��,���д洢���Ǹ���
	for(; i < sz; i++)
	{
		//int c = FindHashTable(&hc,2);//�����±�---�±꼴Ϊ�ַ���ASCLL
		if(FindHashTable(&hc,ch[i]) == ch[i])
			hc._Data[ch[i]]._data++;
		else
			 InsertHashTable(&hc,ch[i]);//����
	}
	//�����ַ������ҳ����ִ���Ϊ1���ַ�
	for(i = 0; i < sz; i++)
	{
		int key = FindHashTable(&hc,ch[i]);
		if(hc._Data[key]._data == 1)
		{
			printf("%c ",ch[i]);
			//break;
		}
	}
}

//��ϣ��
//�����ݴ洢��˳����У��洢ʱ��ĳ��ӳ���ϵ(��ϣ����)�洢�ڶ�Ӧ���±괦��
//��ϣ������hf(Key) = A*Key+1;
//��ϣ������
//1��ֱ�Ӷ��Ʒ���
//ֱ�Ӹ����������±�Ĺ�ϵ��ȷ��ӳ��

//Ӧ�ã���һ���ַ����е�һ��ֻ����һ�ε��ַ�
//�⣺��һ����СΪ256(�����256���ַ�)�Ĺ�ϣ��
//�����ַ�����ֵ����Ϊ��Ӧ���±꣬�����зų��ֵĴ�����ѭ������һ���������ݣ�
//�����ַ����е��ַ���ȷ���Ǹ��ַ���һ�γ��֣������ַ�����

//������������
//��ַ(�±�) = ���� % p��(p����ӽ���ϣ��С��������p <= max_size��)

//��ϣ��ͻ��
//ԭ�򣺹�ϣ�����Ĳ�����
//��ϣ��ͻ���޷�����ģ�
//�������ɢ��
//��ͻ��⣺ʹ��λ��״̬��ǵķ���������״̬���գ��ǿգ�ɾ���ǿ�
//��������ͻ�󣬽����ݷ��ڳ�ͻλ�õĺ���Ŀ�λ��(ÿ��λ��������״̬���գ����գ�ɾ������)
//����̽�⣺����ʱ��ӳ��ĵ�ַ����ʼ����ң�ֱ���ҵ�(������ͬ)��������λ�˳�
//ע�����������һ��Ԫ�ػ�δ�Ҵ��򷵻ص������ʼλ�ã����������
//���룺ӳ��ĵ�ַ״̬Ϊ��--->ֱ�Ӳ��룬��Ϊ��--->���ҴӸõ�ַ����Ҳ���λ��
//����λ�ò�����������ƣ������ڿ�(��ɾ���ǿ�)λ�ô�������ǰ�߼���Ƿ��������������
//���ң�����ӳ���ַ����ӳ���ַ����ʼ���ң�ֱ���ҵ����ݻ�������λ���˳�(ע�⣺�ص���ʼ����λ��ҲӦ�˳�)
//ɾ������ɾ��Ϊλ��״̬����Ϊ ɾ������ ��ע���˳�������ֹ������ѭ�����ص���ʼλ��ҲӦ�˳���

//����̽��ȱ�ݣ����ݶѻ�(һ��������ͻ���ͻ���������������ͻ)
//����Խ��Ҳ���׷�����ͻ��
//���������1��ʹ�ø������ӿ������ݣ�2�����ö���̽�ⲻʹ��˳��̽��
//�������ӣ�size/capacity <= 0.7~0.8 Ч�ʽϸ�
//          size*10/capacity <= 7~8��*10�Ǵ������ͳ������⣩
//����̽�⣺
//H(i+1) = Hi + (2*i+1);(i = 0, 1,2,3...)
//ȱ�ݣ�����������ʱ����һֱ���ҿ�λ������Ч�ʵ�
//���������ʹ�ÿ��Ƹ�����������--->�Կռ任ʱ��


//���ϴ���������
//1����̬����----���ʹ�ø�����������
//��ν����ݷŻص��¿ռ䣬����ֱ���ڴ渴�ƣ���ʹ���¸�����ķ���(ֻ������ЧԪ��)��������ϣ������ݣ��ͷžɿռ�
//2����ϣ�����У�%������������β���
//
//3���洢�ַ�����ʱ�����ӳ���ַ��
//��������������δ��� �ַ���ȡģ���⣿
//����������ַ���ת��������
//1����ÿ���ַ���Ӧ��ASCLL��ֵ���
//2���ַ���ϣ�㷨�����ַ���ת��������
//3��ʹ�ú���ָ�룬�������ַ�����������ת��������
//ע����ϣ��ṹ���У����һ������ָ�����ͱ���������ת����������

*/