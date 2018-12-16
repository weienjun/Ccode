#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"Seqlest.h"

void Init(qseqlist arr,const int count)
{
	int i=0;
	assert(arr);

	arr->size=0; //��ʼsize
	for(i=0;i<count;i++)
	{
		arr->size++; //��ֵ������1
		printf("�����%d�����ݣ�",arr->size);
	    scanf("%d",&arr->arr[i]);
	}
}

void Print(const qseqlist arr)//���
{
	int i=0;
	assert(arr);
	if(arr->size==0)
		printf("�����ݣ�\n");
	else
	{
		for(i=0;i<arr->size;i++)
		{
			printf("��%d������Ϊ��%d\n",i+1,arr->arr[i]);
		}
	}
}

void Tail_Plug(qseqlist arr,const type data)//β��
{
	assert(arr);
	assert(arr->size < MAX_SIZE); //���Է�ֹ�����Ѵ���
	arr->arr[arr->size++]=data;//������sizeλ�ã���size+1
}

void Tail_Delete(qseqlist arr)//βɾ
{
	assert(arr);
	assert(arr->size > 0);//��ֹ����ֵ��ɾ������
	arr->size--; //��ֵ������һ����ɾ��һ����
}

void Head_Plug(qseqlist arr,const type data)//ͷ��
{
	int i=0;
	assert(arr);
	assert(arr->size < MAX_SIZE); //���Է�ֹ�����Ѵ���

	for(i=arr->size;i>0 ;i--)
	{
		arr->arr[i]=arr->arr[i-1];//��������ƶ�
	}//�˳�ʱi=0;
	arr->arr[i]=data;//����һ��Ԫ�ظ�ֵ������ԭ����ֵ��
	arr->size++; //��������
}

void Head_Delete(qseqlist arr)//ͷɾ
{
	int i=0;
	assert(arr);
	assert(arr->size > 0);//��ֹ����ֵ��ɾ������

	for(i=0;i<arr->size ;i++)
	{
		arr->arr[i]=arr->arr[i+1];//������ǰ�ƶ�
	}//�˳�ʱi=size;
	arr->size--; //������һ
}

void Plug(qseqlist arr,const int pos,const type data)//�����ڵڼ�����λ��
{
	int i=0;
	assert(arr);
	assert(arr->size < MAX_SIZE); //���Է�ֹ�����Ѵ���
	assert(pos <= arr->size+1); //����λ�ò��ɳ���������Ч��ֵ����+1

	for(i=arr->size;i>=pos ;i--)
	{
		arr->arr[i]=arr->arr[i-1];//��������ƶ�
	}//�˳�ʱi=pos+1;//�������ڵ�posλ��
	arr->arr[i]=data;//����pos��Ԫ�ظ�ֵ������ԭ����ֵ��
	arr->size++; //��������
}

void Delete(qseqlist arr,const int pos)//ɾ���ڼ�����
{
	int i=0;
	assert(arr);
	assert(arr->size > 0);//��ֹ����ֵ��ɾ������
	assert(pos <= arr->size);//ֻ��ɾ����Ч�������е���
	for(i=pos-1;i<arr->size ;i++)
	{
		arr->arr[i]=arr->arr[i+1];//������ǰ�ƶ�
	}//�˳�ʱi=size;
	arr->size--; //������һ
}

void Delete1(qseqlist arr,const type data)//ɾ������data
{
	int temp=0;
	int i=0;
	assert(arr);

	temp=search(arr,data);

	if(!arr->size && -1==temp)
		printf("�޴����ݣ�\n");
	else
	{
		for(i=temp;i<arr->size;i++)
		{
			arr->arr[i]=arr->arr[i+1];
		}
		arr->size--;
	}
}

void Delete2(qseqlist  arr,const type data)//ɾ����������data
{
	int i=0;//����ѭ��
	int j=0;
	int sz=arr->size; //����ѭ��
	type * temp=NULL;//�洢��data����
	assert(arr);

	if(sz <=0)
		printf("˳���Ϊ��!\n");
	else
	{
		temp=(type*)malloc(sizeof(type)*arr->size);
	    assert(temp);
		while(i < sz )//ѭ���ж�
		{
			if(arr->arr[i] != data)//��data���ݱ���
			{
				temp[j]=arr->arr[i];
				j++;
			}
			else
			arr->size--;//Ϊdata���ݸ�����һ
			i++;
		}
		i=arr->size;//����ѭ�����Ƶ�ԭ������
		while(i-- > 0)
		{
			arr->arr[i]=temp[i];
		}
		free(temp);
	}
}

int search(qseqlist arr,const type data)//��������
{
	int i=0;
	assert(arr);

	for(i=0;i<arr->size;i++)
	{
		if(arr->arr[i] == data)
			return i;//���ش����ݵ�ַ
	}
	return -1;//�޷��ؿ�
}

int SeqListEmpty(qseqlist arr)//�ж�˳����Ƿ�Ϊ��
{
	return !arr->size;//�շ���1
}

//ÿ�ҵ�һ��data���ݼ�ɾ�������dataλ�ü������ң�ֱ��ѭ��size�Σ����Ҳ���data����
void Remove_all(qseqlist arr,const type data)//ɾ����������data
{
	int cur=0;
	int n=arr->size;
	while(n--)
	{
      cur=search(arr,data);//�������ݣ�-1��ʾδ�ҵ����ҵ������±�
	  if(cur != -1)//�ҵ�
	  {
         Delete1(arr,data);//ɾ������data
	  }
	  else//δ�ҵ�
	  {
		  return ;
	  }
	}
}
