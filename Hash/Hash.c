#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include"Hash.h"

//������
static const unsigned long _Primelist[_pMax] =
{
	3ul,7ul,21ul,53ul, 97ul,193ul,389ul,769ul,
	1543ul,3097ul,6151ul,12289ul,
	49157ul,98317ul,196613ul,393241ul
};

void InitHashTableD(HTD* ht,size_t sz,Compare com)//��ʼ��
//void InitHashTableD(HTD* ht,size_t sz)//��ʼ��
{
	size_t i = 0;
	assert(ht);
	ht->_capacity = achievePrm(sz);//��ȡ����
	ht->_size = 0;
	ht->_com = com;
	ht->_Data = (EndmD*)malloc(sizeof(EndmD)*ht->_capacity);
	assert(ht->_Data);
	for(; i < ht->_capacity; i++)
		ht->_Data[i]._state = EmptyD;//״̬�ÿ�
}

size_t achievePrm(size_t sz)//��ȡ����
{
	size_t i = 0;
	size_t tmp = sz;
	for(; i < _pMax; i++)
	{
		if(sz < _Primelist[i] && tmp < _Primelist[i])
		  return _Primelist[i];
		sz = _Primelist[i];
	}
	return _Primelist[_pMax];
}

size_t DetectiveLineD(HTD* ht,size_t key)//����̽��
{
	key++;
	if(key >= ht->_capacity)
		key = 0;
	return key;
}

size_t DeletectiveTwoD(HTD* ht,size_t key1)//����̽��
{
	int i = 0;
	key1 = key1 + 2*i+1;
	while(ht->_Data[key1]._state == ExistD)
	{
		if(key1 >= ht->_capacity)
			key1 = key1%ht->_capacity;//����ֱ��ȡ0λ�ã�����Խ���һֱ����0��λ��
		i++;
		key1 = key1 + 2*i+1;
	}
	return key1;
}

void AddSeraveD(HTD* ht,size_t key)//����
{
	if(((ht->_size*10)/ht->_capacity) > 7)//����ƽ����������
	{
		size_t i = 0;
		HTD tmph ;//��ʱ��ϣ��
		//InitHashTableD(&tmph,ht->_capacity*2);
		InitHashTableD(&tmph,ht->_capacity*2,ht->_com);
		tmph._size = ht->_size;
		//��������
		//����ʹ�ô˷���,�������ݺ�������ͬ�����ݲ��ڶ�Ӧ���¿ռ��λ��(ӳ�䲻��ȷ)��Ӧ���²��룬����ӳ��
		//memcpy(tmph._Data,ht->_Data,sizeof(Endm)*ht->_size);
		for(; i < ht->_capacity; i++)
		{
			if(ht->_Data[i]._state == ExistD)//ֻ�ƶ���Ч����
				InsertHashTableD(&tmph,ht->_Data[i]._data);//����
		}
		//������ϣ�������
		Swap(ht,&tmph);

		free(tmph._Data);//���ֺ��ַ�������������ͬ������
		tmph._Data = NULL;
	}
}

void Swap(HTD*ht,HTD* tmph)//����
{
	size_t sz = 0;
	size_t i = 0;
	
	//���ݽ���
	for(; i < ht->_capacity; i++)
	{
		if(ht->_Data[i]._state == ExistD)
		{
			EndmD tmpe = ht->_Data[i];//ֱ�ӵ�ַ����
			ht->_Data[i] = tmph->_Data[i];
			tmph->_Data[i] = tmpe;
		}
	}
	/*
	EndmD* tmpe = ht->_Data;//ֱ�ӵ�ַ����
	ht->_Data = tmph->_Data;
	tmph->_Data = tmpe;
	*/
	//��������
	sz = ht->_capacity;
	ht->_capacity = tmph->_capacity;
	tmph->_capacity = ht->_capacity;
}

size_t HashFunkD(HTD* ht,type data)//��ϣ����(��ȡӳ���ַ)
{
	//����������Ϊ��������
	//return data % (ht->_capacity);//�˴�Ӧģȡ��ӽ�(<=����)����������
	return ht->_com(data) % (ht->_capacity);
}

void InsertHashTableD(HTD* ht,type data)//����
{
	size_t key = 0;
	AddSeraveD(ht,key);//���ݴ���
	key = HashFunkD(ht,data);//��ϣ����(��ȡӳ���ַ)
	//Ѱ�ҿɲ���λ�ã��գ���ɾ���ǿգ�
	while(ht->_Data[key]._state == ExistD)
	{
		//����̽��
		//key = DetectiveLineD(ht,key);
		//����̽��
		key = DeletectiveTwoD(ht,key);//����̽��
	}
	//ht->_Data[key]._data = 1;
	ht->_Data[key]._data = data;
	ht->_Data[key]._state = ExistD;
	ht->_size++;
}

int FindHashTableD(HTD* ht,type data)//����
{
	size_t key = HashFunkD(ht,data);//��ϣ����(��ȡӳ���ַ)
	size_t tmp = key;//�����ʼ���ҵ�ַ
	assert(ht);
	if(ht->_size == 0)
		return -1;

	while(ht->_Data[key]._state != EmptyD)
	{
		//if(key == data)//�ַ�Ӧ�ô������
		//return key;

		if(ht->_Data[key]._data == data)
			return key;
		//����̽��
		//key = DetectiveLineD(ht,key);
		//����̽��
		key = DeletectiveTwoD(ht,key);//����̽��

		if(key == tmp)//�ٴε���key--->δ�ҵ�
			break;
	}
	return -1;
}

void DeleteHashTableD(HTD* ht,type data)//ɾ��
{
	size_t key = 0;
	assert(ht);
	key = FindHashTableD(ht,data);//����
	if(key < 0)//δ�ҵ�
		return ;
	ht->_Data[key]._state = DExistD;
	ht->_size--;
}

void PrintHashTableD(HTD* ht)
{
	size_t i = 0;
	while(i < ht->_capacity)
	{
		if(ht->_Data[i]._state == ExistD)
			printf("%s ",ht->_Data[i]._data);
		i++;
	}
	printf("\n");
}

static size_t BKDRHash(const char* str)//�ַ�����ϣ�㷨(�ַ���ת��ֵ)
{
	unsigned int seed = 131;
	unsigned int hash = 0;
	while(*str)
	{
		hash = hash * seed + (*str++);
	}
	return (hash & 0x7FFFFFFF);
}

static size_t intBKDRHash(const type data)//�ַ����ִ���
{
	return (unsigned int)data;
}

void Hash_testD()//����
{
	HTD ht;
	
    InitHashTableD(&ht,2,BKDRHash);//��ʼ��,�����ַ���
    InsertHashTableD(&ht,"123");//    InsertHashTableD(&ht,"123");//����
    InsertHashTableD(&ht,"12");//����
    DeleteHashTableD(&ht,"123");//ɾ��
    InsertHashTableD(&ht,"11");//����
    InsertHashTableD(&ht,"456");//����
    InsertHashTableD(&ht,"4567");//����
    InsertHashTableD(&ht,"4567");//����
    InsertHashTableD(&ht,"489705");//����
	/*
    InitHashTableD(&ht,4,intBKDRHash);//��ʼ��
    InsertHashTableD(&ht,1);//����
    InsertHashTableD(&ht,3);//����
    DeleteHashTableD(&ht,1);//ɾ��
    InsertHashTableD(&ht,11);//����

	//PrintHashTableD(&ht);
	
    InsertHashTableD(&ht,1);//����
   // InsertHashTableD(&ht,9);//����
    InsertHashTableD(&ht,2);//����
    InsertHashTableD(&ht,8);

	PrintHashTableD(&ht);
	InsertHashTableD(&ht,17);//����

	InsertHashTableD(&ht,9);//����
    InsertHashTableD(&ht,12);//����
    InsertHashTableD(&ht,18);//����
    InsertHashTableD(&ht,20);//����

    //printf("%d\n",FindHashTableD(&ht,2));//����
    DeleteHashTableD(&ht,1);//ɾ��
    InsertHashTableD(&ht,21);//����
    InsertHashTableD(&ht,24);//����
	*/
	PrintHashTableD(&ht);
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
*/
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


//��ɢ��(������)
//��ϣͰ����ϣ���д�ŵĲ��������ݣ����Ǿ�����ͬӳ���ϵ������ı�ͷ
//��ϣ���д����һ���ṹ��ָ�����������ָ�룬���ڹ�ϣ������һ������(һ��ָ��)��ÿ��λ��Ϊһ������(����ָ��)
//ȱ�㣺����ͻ�Ƚϴ�ʱ���������ݵ�ʱ�临�Ӷ�����(����������)
//����ŷ����ռ�����---���¼���ӳ���ַ�����Ų�(����ʱ���������ӽ�Ͱ����ʱ����)


