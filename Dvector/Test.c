#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include"Test.h"

void seq_init(seqlist * q)//初始化
{
	q->n_size=0;//初始化开辟大小
	q->size=0;//初始化元素个数

	//强制将无符号类型转化成有符号，进行检测输入是否为负数
	while((int)q->n_size <= 0)
	{
	    printf("请输入需要的数字个数：");
	    scanf("%d",&q->n_size);
	}

	q->num=(type*)malloc(sizeof(type)*q->n_size);//开辟内存
	if(!q)//内存开辟检测
	{
		printf("malloc field!\n");
		exit(0);
	}

	while(q->size < q->n_size)
	{
		printf("输入%d个数值：",++q->size);
		scanf("%d",q->num++);//初始化数字

	}
	q->num -= q->n_size;//重新指向头位置
}

void print(const seqlist *q)//输出
{
	int i=0;
	assert(q);
	for(i=0;i<q->size;i++)
	{
		printf("第%d个数:%d\n",i+1,q->num[i]);
	}
	printf("\n");
}

int seq_delete(seqlist * q,const type data)//删除
{
	int i=0;
	int temp=seq_search(q,data);//查询
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

int seq_search(seqlist * q,const type data)//查找
{
	int count = 0;
	assert(q);
	while(count++ <= q->size)//count先+1
	{
		if(q->num[count-1] == data)//下标从0开始
			return count;
	}
	printf("未找到此数！\n");
	return -1;//未找到
}

int seq_delete_all(seqlist * q,const type data)//删除所有
{
	type * temp=(type *)malloc(sizeof(type)*q->size);
	int i=0;
	int j=0;
	int count =q->size;
	assert(q);
    if(count <= 0)
		printf("无数据！\n");
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

int seq_size(seqlist * q)//获取容量
{
	assert(q);
	return q->n_size;
}

void seq_addsize(seqlist * q)//增容
{
	type * temp=NULL;
	int new_nsize=(q->n_size+1)*2;//加1防止原容量为0
	temp=(type *)malloc(sizeof(type)*(new_nsize));//扩大二倍容量+1
	if(!temp)
	{
		printf("eorr!\n");
		return ;
	}
	else
	{
		memmove(temp,q->num,sizeof(type)*q->size);//注意此处是按字节复制，而不是元素个数
		free(q->num);//释放原有空间
		q->num=temp;//让原有地址指向新地址
		q->n_size=new_nsize;
	}
}

void seq_clear(seqlist * q)//清空
{
	assert(q);
    q->size=0;
}

void seq_clearseq(seqlist * q)//销毁
{
	assert(q);
	free(q->num);
	q->num=NULL;
	q->n_size=0;
	q->size=0;
}

void seq_put(seqlist * q, const int pos,const int data)//任意位置插入
{
	int i=0;
	assert(q);
	if(q->size+1 < pos )//添加最大位置在最后一个数的后面
		printf("pos eorr!\n");
	else
	{
		if(q->size == q->n_size)//容量已满
			seq_addsize(q);//扩容
		for(i=q->size;i>= pos;i--)
		{
			q->num[i]=q->num[i-1];
		}
		q->num[pos-1]=data;//添加在第pos个数处
		q->size++;
	}
}