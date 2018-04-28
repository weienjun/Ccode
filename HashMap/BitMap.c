#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include"BitMap.h"

void Init_BitMap(BitMap* mp,size_t size)
{
	assert(mp);
	mp->_capacity = (size>>5)+1;
	mp->_size = 0;
	mp->_data = (typeB*)malloc(sizeof(typeB)*mp->_capacity);
	memset(mp->_data,0,sizeof(typeB)*mp->_capacity);//����������0
	assert(mp->_data);
}

int Insert_BitMap(BitMap* mp,typeB data)
{
	size_t idx = 0;//�±�
	assert(mp);
	idx = data >> 5;//���ݴ�ŵ��±�λ��(������ӳ��)
	//�����Ѵ洢
	if(Test(mp,data))
		return 0;
	Set(mp, data); //λ����1
	mp->_size++;
	return 1;
}

//���ݶ�Ӧ��bitλ��1
void Set(BitMap* mp, size_t data)
{
	size_t idx = data >> 5;
	mp->_data[idx] |= 1 << (data%32);
}

//����bitλ��0
void ReSet(BitMap* mp, size_t data)
{
	size_t idx = data >> 5;
	mp->_data[idx] &= ~(1 << (data%32));
}

//�ж�λ�Ƿ�Ϊ1
int Test(BitMap* mp, size_t data)
{
	size_t count = 0;
	size_t idx = data >> 5;
	if(idx >= mp->_capacity)//Խ�粻����
		return -1;
	assert(mp);
	return (mp->_data[idx] &(1 << (data%32)));	
}

size_t CountBitMap(BitMap* mp)
{
	size_t i = 0;
	size_t j = 0;
	size_t count =0;
	char* bitCount = "\0\1\1\2\1\2\2\3\1\2\2\3\2\3\3\4";//�ĸ�bitλ��Ӧ1���ֵĴ����Ŀ���
	assert(mp);
	for(; i < mp->_capacity; i++)//�����������
	{
		typeB tmp = mp->_data[i];
	    j = 0;
		while(j < 4)//���һ������
		{
			unsigned char ch = tmp;//ȡ1���ֽ�
			count += bitCount[ch&0x0F];//����0~3bitλ��1�ĸ���
			ch =  ch >> 4;
			count += bitCount[ch&0x0F];//����4~7bitλ��1�ĸ���
			tmp = tmp >> 8;//ȡ��һ���ֽڵĵ�0bitλ
			j++;//ȡ��һ���ֽ�
		}
	}
	return count;
}

size_t SizeBitMap(BitMap* mp)
{
	assert(mp);
	return mp->_size;
}

void DestroyBitMap(BitMap* mp)
{
	assert(mp);
	free(mp->_data);
	mp->_data = NULL;
	mp->_capacity = 0;
	mp->_size = 0;
}

void BitMap_test()
{
	BitMap mp;
	typeB num [] = {0,1,3,6,5,9,8,7,32,26,5,36,63,65,66};
	size_t sz = sizeof(num)/sizeof(num[0]);
	size_t i = 0;

	Init_BitMap(&mp,66);//��ʼ�������������
	for(i = 0; i < sz; i++)
    Insert_BitMap(&mp,num[i]);

	//���ĳ������λ�Ƿ�Ϊ1 
	if(Test(&mp, 100))
		printf("����\n");
	else
		printf("������\n");

	if(Test(&mp, 10))
		printf("����\n");
	else
		printf("������\n");
	printf("%d \n",SizeBitMap(&mp)); 
	// λͼ��1�ĸ��� 
	printf("%d\n",CountBitMap(&mp)); 
	DestroyBitMap(&mp); 

}