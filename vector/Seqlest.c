#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"Seqlest.h"

void Init(qseqlist arr,const int count)
{
	int i=0;
	assert(arr);

	arr->size=0; //初始size
	for(i=0;i<count;i++)
	{
		arr->size++; //数值个数加1
		printf("输入第%d个数据：",arr->size);
	    scanf("%d",&arr->arr[i]);
	}
}

void Print(const qseqlist arr)//输出
{
	int i=0;
	assert(arr);
	if(arr->size==0)
		printf("无数据！\n");
	else
	{
		for(i=0;i<arr->size;i++)
		{
			printf("第%d个数据为：%d\n",i+1,arr->arr[i]);
		}
	}
}

void Tail_Plug(qseqlist arr,const type data)//尾插
{
	assert(arr);
	assert(arr->size < MAX_SIZE); //断言防止数组已存满
	arr->arr[arr->size++]=data;//插入在size位置，后size+1
}

void Tail_Delete(qseqlist arr)//尾删
{
	assert(arr);
	assert(arr->size > 0);//防止无数值，删除出错
	arr->size--; //数值个数减一，及删除一个数
}

void Head_Plug(qseqlist arr,const type data)//头插
{
	int i=0;
	assert(arr);
	assert(arr->size < MAX_SIZE); //断言防止数组已存满

	for(i=arr->size;i>0 ;i--)
	{
		arr->arr[i]=arr->arr[i-1];//数据向后移动
	}//退出时i=0;
	arr->arr[i]=data;//给第一个元素赋值（覆盖原来数值）
	arr->size++; //个数加以
}

void Head_Delete(qseqlist arr)//头删
{
	int i=0;
	assert(arr);
	assert(arr->size > 0);//防止无数值，删除出错

	for(i=0;i<arr->size ;i++)
	{
		arr->arr[i]=arr->arr[i+1];//数据向前移动
	}//退出时i=size;
	arr->size--; //个数减一
}

void Plug(qseqlist arr,const int pos,const type data)//插入在第几个数位置
{
	int i=0;
	assert(arr);
	assert(arr->size < MAX_SIZE); //断言防止数组已存满
	assert(pos <= arr->size+1); //插入位置不可超过数组有效数值个数+1

	for(i=arr->size;i>=pos ;i--)
	{
		arr->arr[i]=arr->arr[i-1];//数据向后移动
	}//退出时i=pos+1;//即插入在第pos位置
	arr->arr[i]=data;//给第pos个元素赋值（覆盖原来数值）
	arr->size++; //个数加以
}

void Delete(qseqlist arr,const int pos)//删除第几个数
{
	int i=0;
	assert(arr);
	assert(arr->size > 0);//防止无数值，删除出错
	assert(pos <= arr->size);//只能删除有效的数组中的数
	for(i=pos-1;i<arr->size ;i++)
	{
		arr->arr[i]=arr->arr[i+1];//数据向前移动
	}//退出时i=size;
	arr->size--; //个数减一
}

void Delete1(qseqlist arr,const type data)//删除数据data
{
	int temp=0;
	int i=0;
	assert(arr);

	temp=search(arr,data);

	if(!arr->size && -1==temp)
		printf("无此数据！\n");
	else
	{
		for(i=temp;i<arr->size;i++)
		{
			arr->arr[i]=arr->arr[i+1];
		}
		arr->size--;
	}
}

void Delete2(qseqlist  arr,const type data)//删除所有数据data
{
	int i=0;//用于循环
	int j=0;
	int sz=arr->size; //用于循环
	type * temp=NULL;//存储非data数据
	assert(arr);

	if(sz <=0)
		printf("顺序表为空!\n");
	else
	{
		temp=(type*)malloc(sizeof(type)*arr->size);
	    assert(temp);
		while(i < sz )//循环判断
		{
			if(arr->arr[i] != data)//非data数据保存
			{
				temp[j]=arr->arr[i];
				j++;
			}
			else
			arr->size--;//为data数据个数减一
			i++;
		}
		i=arr->size;//用于循环复制到原变量中
		while(i-- > 0)
		{
			arr->arr[i]=temp[i];
		}
		free(temp);
	}
}

int search(qseqlist arr,const type data)//查找数据
{
	int i=0;
	assert(arr);

	for(i=0;i<arr->size;i++)
	{
		if(arr->arr[i] == data)
			return i;//返回此数据地址
	}
	return -1;//无返回空
}

int SeqListEmpty(qseqlist arr)//判断顺序表是否为空
{
	return !arr->size;//空返回1
}

//每找到一个data数据即删除，后从data位置继续查找，直到循环size次，或找不到data数据
void Remove_all(qseqlist arr,const type data)//删除所有数据data
{
	int cur=0;
	int n=arr->size;
	while(n--)
	{
      cur=search(arr,data);//查找数据，-1表示未找到，找到返回下标
	  if(cur != -1)//找到
	  {
         Delete1(arr,data);//删除数据data
	  }
	  else//未找到
	  {
		  return ;
	  }
	}
}
