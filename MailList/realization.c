#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"realization.h"
extern int count;//应用外部文件参数，避免传参

void print(const people * head)//输出
{
	int i=0;
	int n=count;//用于循环输出
	people * ptemp;
	assert(head);
	ptemp=head;
	printf("\n姓名\t性别\t年龄\t电话\t地址\n");
	while(n--)
	{
	printf("\n%s\t%c\t%d\t%s\t%s\n",ptemp->name,ptemp->gender,ptemp->age,ptemp->number,ptemp->address);
	ptemp=ptemp->Next;
	}
}

people* search(const people * head ,const char *ch)
{
	people * ptemp;
	int n=count;
	ptemp=head;
	assert(head);
	while(n--)
	{
		if(strcmp(ptemp->name,ch)==0)
		{
		printf("\n姓名\t性别\t年龄\t电话\t地址\n");
		printf("\n%s\t%c\t%d\t%s\t%s\n",ptemp->name,ptemp->gender,ptemp->age,ptemp->number,ptemp->address);
		return ptemp;
		}
		ptemp=ptemp->Next;
	}
	printf("\n未找到！\n");
	return NULL;
}

people* dete(people *temp)
{
	people * tnext;
	tnext=temp->Next;
	strcpy(temp->name,tnext->name);
	temp->gender=tnext->gender;

	temp->Next=tnext->Next;
	count--;
	free(tnext);
	return temp;
}

people* sorting(people *head)//排序
{
	people * pnext;
	people * pend;
	int i=0;
	int j=0;

	for(i=0;i<count-1;i++)
	{
		pend=head;
	    pnext=pend->Next;
		for(j=0;j<count-i-1;j++)
		{
			
			if(strcmp(pend->name,pnext->name)==1)//前大
			{
				exchange(pend,pnext);
			}
			pend=pnext;
			pnext=pnext->Next;

		}
		
	}
	return head;
}


void exchange(people * pend,people * pnext)//交换两个链表内容
{
	people * temp;
	temp=(people*)malloc(sizeof(people));
	assert(temp);

	strcpy(temp->name,pnext->name);
	temp->gender=pnext->gender;
	temp->age=pnext->age;
	strcpy(temp->address,pnext->address);
	strcpy(temp->number,pnext->number);

	strcpy(pnext->name,pend->name);
	pnext->gender=pend->gender;
	temp->age=pnext->age;
	strcpy(pnext->address,pend->address);
	strcpy(pnext->number,pend->number);

	strcpy(pend->name,temp->name);
	pend->gender=temp->gender;
	pend->age=temp->age;
	strcpy(pend->address,temp->address);
	strcpy(pend->number,temp->number);

	free(temp);
	temp=NULL;
}

people* modify(people *temp)//修改
{
	printf("输入修改的信息：\n");
	printf("\n姓名(s)\t性别(c)\t年龄(d)\t电话(s)\t地址(s)\n");
	scanf("%s %c %d %s %s",temp->name,&temp->gender,&temp->age,temp->number,temp->address);
	return temp;
}

people* empty(people * head)//清空
{
	people * det;//标记删除节点

	while(count)
	{
	    det=head;//标记删除节点
		head=det->Next;
		free(det);
		det=NULL;
		count--;
	}//退出时head 指向未知区域
	head=NULL;//让head指向空
	return head;
}

people * creat(people * head)//初始化,添加
{
	people * pnew=NULL;
    people * pend;//用于标记当前尾结点
	int n=count-1;//用于寻找尾结点，的循环控制

	while(pnew==NULL)//内存分配失败或未分配,重新分配
	{
		pnew=(people*)malloc(sizeof(people));
	}

	pend=head;
	while((n--)>0)//指向最后一个节点，用于至少已有1个节点时
	{
		pend=pend->Next; 
	}

	if(! head)//通讯录为空，无联系人
	{
		pend=pnew;//建第一个节点时，头节点和最后节点都指向新建节点
	}

	pnew->Next=head;//添加在开头，新节点指向头节点
	pend->Next=pnew;//最后一个节点指第一个节点，形成循环链表
	head=pnew;//头节点指向第一个节点

	printf("\n姓名(s)\t性别(c)\t年龄(d)\t电话(s)\t地址(s)\n");
	scanf("%s %c %d %s %s",pnew->name,&pnew->gender,&pnew->age,pnew->number,pnew->address);
	count++;

	return head;//返回头节点
}

void pfile(people * head)//写入文件中
{
	int i=0;
	int n=count;//用于循环写入
	people * ptemp;
	FILE * fp;//创建一个文件变量
	assert(head);
	fp=fopen("rea.txt","wt");//以写方式打开，无此文件，重新创建一个
	if(fp==NULL)
		printf("eorr!\n");
	else
	{
		ptemp=head;
		fprintf(fp,"\n姓名\t性别\t年龄\t电话\t地址\n");//写入
		while(n--)
		{
		fprintf(fp,"\n%s\t%c\t%d\t%s\t%s\n",ptemp->name,ptemp->gender,ptemp->age,ptemp->number,ptemp->address);//写入
		ptemp=ptemp->Next;
		}
		fclose(fp);//关闭文件
	}
}
