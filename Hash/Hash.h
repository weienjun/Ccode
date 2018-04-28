#ifndef __HASH_H__

#define __HASH_H__

#define _pMax 18

typedef char* type;
//typedef int type;


enum stateD{EmptyD,ExistD,DExistD};

typedef size_t (*Compare)(const type str);

typedef struct EndmD//λ��
{
	type _data;//����ֵ
	enum stateD _state;//λ��״̬
}EndmD;

typedef struct HashTableD//��ϣ��
{
	EndmD* _Data;//�ṹ��ָ�����ͣ���̬˳���洢
	size_t _size;//���ݸ���
	size_t _capacity;//����
	Compare _com;//�ַ���ת��ֵ
}HTD;

void InitHashTableD(HTD* ht,size_t sz,Compare com);//��ʼ��
//void InitHashTableD(HTD* ht,size_t sz);//��ʼ��

size_t achievePrm(size_t sz);//��ȡ����
void AddSeraveD(HTD* ht,size_t key);//����,key����ָ���ռ��С
void Swap(HTD*ht,HTD* tmph);//����
void InsertHashTableD(HTD* ht,type data);//����
size_t HashFunkD(HTD* ht,type data);//��ϣ����(��ȡӳ���ַ)
int FindHashTableD(HTD* ht,type data);//����
void DeleteHashTableD(HTD* ht,type data);//ɾ��
void PrintHashTableD(HTD* ht);

size_t DetectiveLineD(HTD* ht,size_t key);//����̽��
size_t DeletectiveTwoD(HTD* ht,size_t key1);//����̽��

static size_t BKDRHash(const char* str);//�ַ�����ϣ�㷨(�ַ���ת��ֵ)
static size_t intBKDRHash(const type data);//�ַ����ִ���

//��������

void Hash_testD();//����

void Application_testD();

#endif