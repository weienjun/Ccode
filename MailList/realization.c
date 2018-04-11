#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"realization.h"
extern int count;//Ӧ���ⲿ�ļ����������⴫��

void print(const people * head)//���
{
	int i=0;
	int n=count;//����ѭ�����
	people * ptemp;
	assert(head);
	ptemp=head;
	printf("\n����\t�Ա�\t����\t�绰\t��ַ\n");
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
		printf("\n����\t�Ա�\t����\t�绰\t��ַ\n");
		printf("\n%s\t%c\t%d\t%s\t%s\n",ptemp->name,ptemp->gender,ptemp->age,ptemp->number,ptemp->address);
		return ptemp;
		}
		ptemp=ptemp->Next;
	}
	printf("\nδ�ҵ���\n");
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

people* sorting(people *head)//����
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
			
			if(strcmp(pend->name,pnext->name)==1)//ǰ��
			{
				exchange(pend,pnext);
			}
			pend=pnext;
			pnext=pnext->Next;

		}
		
	}
	return head;
}


void exchange(people * pend,people * pnext)//����������������
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

people* modify(people *temp)//�޸�
{
	printf("�����޸ĵ���Ϣ��\n");
	printf("\n����(s)\t�Ա�(c)\t����(d)\t�绰(s)\t��ַ(s)\n");
	scanf("%s %c %d %s %s",temp->name,&temp->gender,&temp->age,temp->number,temp->address);
	return temp;
}

people* empty(people * head)//���
{
	people * det;//���ɾ���ڵ�

	while(count)
	{
	    det=head;//���ɾ���ڵ�
		head=det->Next;
		free(det);
		det=NULL;
		count--;
	}//�˳�ʱhead ָ��δ֪����
	head=NULL;//��headָ���
	return head;
}

people * creat(people * head)//��ʼ��,���
{
	people * pnew=NULL;
    people * pend;//���ڱ�ǵ�ǰβ���
	int n=count-1;//����Ѱ��β��㣬��ѭ������

	while(pnew==NULL)//�ڴ����ʧ�ܻ�δ����,���·���
	{
		pnew=(people*)malloc(sizeof(people));
	}

	pend=head;
	while((n--)>0)//ָ�����һ���ڵ㣬������������1���ڵ�ʱ
	{
		pend=pend->Next; 
	}

	if(! head)//ͨѶ¼Ϊ�գ�����ϵ��
	{
		pend=pnew;//����һ���ڵ�ʱ��ͷ�ڵ�����ڵ㶼ָ���½��ڵ�
	}

	pnew->Next=head;//����ڿ�ͷ���½ڵ�ָ��ͷ�ڵ�
	pend->Next=pnew;//���һ���ڵ�ָ��һ���ڵ㣬�γ�ѭ������
	head=pnew;//ͷ�ڵ�ָ���һ���ڵ�

	printf("\n����(s)\t�Ա�(c)\t����(d)\t�绰(s)\t��ַ(s)\n");
	scanf("%s %c %d %s %s",pnew->name,&pnew->gender,&pnew->age,pnew->number,pnew->address);
	count++;

	return head;//����ͷ�ڵ�
}

void pfile(people * head)//д���ļ���
{
	int i=0;
	int n=count;//����ѭ��д��
	people * ptemp;
	FILE * fp;//����һ���ļ�����
	assert(head);
	fp=fopen("rea.txt","wt");//��д��ʽ�򿪣��޴��ļ������´���һ��
	if(fp==NULL)
		printf("eorr!\n");
	else
	{
		ptemp=head;
		fprintf(fp,"\n����\t�Ա�\t����\t�绰\t��ַ\n");//д��
		while(n--)
		{
		fprintf(fp,"\n%s\t%c\t%d\t%s\t%s\n",ptemp->name,ptemp->gender,ptemp->age,ptemp->number,ptemp->address);//д��
		ptemp=ptemp->Next;
		}
		fclose(fp);//�ر��ļ�
	}
}
