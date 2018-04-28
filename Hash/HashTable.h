/*
#ifndef __HASHTABLD_H__

#define __HASHTABLD_H__

typedef int type;

enum state{Empty,Exist,DExist};

typedef struct Endm//λ��
{
	type _data;//����ֵ
	enum state _state;//λ��״̬
}Endm;

typedef struct HashTable//��ϣ��
{
	Endm* _Data;//�ṹ��ָ�����ͣ���̬˳���洢
	size_t _size;//���ݸ���
	size_t _capacity;//����
}HT;

void InitHashTable(HT* ht);//��ʼ��
void AddSerave(HT* ht,size_t key);//����,key����ָ���ռ��С
void InsertHashTable(HT* ht,type data);//����
size_t HashFunk(HT* ht,type data);//��ϣ����(��ȡӳ���ַ)
int FindHashTable(HT* ht,type data);//����
void DeleteHashTable(HT* ht,type data);//ɾ��
void PrintHashTable(HT* ht);
size_t DetectiveLine(HT* ht,size_t key);//����̽��

//��������

void Hash_test();//����

void Application_test();

#endif

*/