#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include"Test.h"

void seq_init(seqlist * q)//��ʼ��
{
	q->n_size=0;//��ʼ�����ٴ�С
	q->size=0;//��ʼ��Ԫ�ظ���

	//ǿ�ƽ��޷�������ת�����з��ţ����м�������Ƿ�Ϊ����
	while((int)q->n_size <= 0)
	{
	    printf("��������Ҫ�����ָ�����");
	    scanf("%d",&q->n_size);
	}

	q->num=(type*)malloc(sizeof(type)*q->n_size);//�����ڴ�
	if(!q)//�ڴ濪�ټ��
	{
		printf("malloc field!\n");
		exit(0);
	}

	while(q->size < q->n_size)
	{
		printf("����%d����ֵ��",++q->size);
		scanf("%d",q->num++);//��ʼ������

	}
	q->num -= q->n_size;//����ָ��ͷλ��
}

void print(const seqlist *q)//���
{
	int i=0;
	assert(q);
	for(i=0;i<q->size;i++)
	{
		printf("��%d����:%d\n",i+1,q->num[i]);
	}
	printf("\n");
}

int seq_delete(seqlist * q,const type data)//ɾ��
{
	int i=0;
	int temp=seq_search(q,data);//��ѯ
	assert(q);
	if(temp >= 0)
	{
		for(i=temp-1;i<q->size;i++)
		{
			q->num[i]=q->num[i+1];
		}
		q->size--;
	}
}

int seq_search(seqlist * q,const type data)//����
{
	int count = 0;
	assert(q);
	while(count++ <= q->size)//count��+1
	{
		if(q->num[count-1] == data)//�±��0��ʼ
			return count;
	}
	printf("δ�ҵ�������\n");
	return -1;//δ�ҵ�
}

int seq_delete_all(seqlist * q,const type data)//ɾ������
{
	type * temp=(type *)malloc(sizeof(type)*q->size);
	int i=0;
	int j=0;
	int count =q->size;
	assert(q);
    if(count <= 0)
		printf("�����ݣ�\n");
	else
	{
		for(i=0;i<q->size;i++)
		{
			if(q->num[i] != data)
			{
				temp[j]=q->num[i];
				j++;
			}
			else
				count--;
		}
		q->size=count;
		for(i=count-1;i>=0;i--)
		{
			q->num[i]=temp[i];
		}
		free(temp);
	}
}

int seq_size(seqlist * q)//��ȡ����
{
	assert(q);
	return q->n_size;
}

void seq_addsize(seqlist * q)//����
{
	type * temp=NULL;
	int new_nsize=(q->n_size+1)*2;//��1��ֹԭ����Ϊ0
	temp=(type *)malloc(sizeof(type)*(new_nsize));//�����������+1
	if(!temp)
	{
		printf("eorr!\n");
		return ;
	}
	else
	{
		memmove(temp,q->num,sizeof(type)*q->size);//ע��˴��ǰ��ֽڸ��ƣ�������Ԫ�ظ���
		free(q->num);//�ͷ�ԭ�пռ�
		q->num=temp;//��ԭ�е�ַָ���µ�ַ
		q->n_size=new_nsize;
	}
}

void seq_clear(seqlist * q)//���
{
	assert(q);
    q->size=0;
}

void seq_clearseq(seqlist * q)//����
{
	assert(q);
	free(q->num);
	q->num=NULL;
	q->n_size=0;
	q->size=0;
}

void seq_put(seqlist * q, const int pos,const int data)//����λ�ò���
{
	int i=0;
	assert(q);
	if(q->size+1 < pos )//������λ�������һ�����ĺ���
		printf("pos eorr!\n");
	else
	{
		if(q->size == q->n_size)//��������
			seq_addsize(q);//����
		for(i=q->size;i>= pos;i--)
		{
			q->num[i]=q->num[i-1];
		}
		q->num[pos-1]=data;//����ڵ�pos������
		q->size++;
	}
}