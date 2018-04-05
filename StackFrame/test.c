#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void light_change(char arr[],int n,int sz);//����
void right_change(char arr[],int n,int sz);//����
int determin(char arr[],char arr2[],int sz);//�ж��Ƿ�Ϊ��ת�ַ�

int main()
{
	char arr[]={"ABCDE"};//Ŀ���ַ���
	char arr2[]={"BCDEA"};//�ж��ַ���
	int sz=sizeof(arr)/sizeof(arr[0]);
	int n=1;//��ת����

	char temp[100];//����ԭ�ַ���
	strcpy(temp,arr);

	printf("ԭ�ַ�����%s\n",arr);
	printf("�Ƚ�ֵΪ��%d\n",determin(arr,arr2,sz));//1����ת�ַ���0������ת�ַ�

	strcpy(arr,temp);//��ԭ�ַ���
	light_change(arr,n,sz);
	printf("����������%s\n",arr);

	strcpy(arr,temp);//��ԭ�ַ���
	right_change(arr,n,sz);
	printf("����������%s\n",arr);

	system("pause");
	return 0;
}

void light_change(char arr[],int n,int sz)//�ַ�������ת
{
	char *p=NULL;//����ָ���һ���ַ�
	char *q=NULL;//����ָ����һ���ַ�
	char temp;//�����ݴ浱ǰ��һ���ַ�
	int i=0;//ѭ��

	while(n)//��תn���ַ��������ƽ���n��
	{
	temp=arr[0];//�ݴ浱ǰ��һ���ַ�
	p=arr;//ָ��ǰ��һ���ַ�
	q=&arr[1];//����ָ��ǰ�ڶ����ַ�
	for(i=0;i<sz/2+1;i++)//�ַ�����
	{
		*p=*q;
		p++;
		q++;
	}//pָ��'\0'ǰһ���ַ���qָ�����һ���ַ�'\0'
	*p=temp;//�������ַ���'\0'ǰһ��������һ���ַ�
	n--;
	}
}

void right_change(char arr[],int n,int sz)//����
{
    char *p=NULL;//����ָ���һ���ַ�
	char *q=NULL;//����ָ����һ���ַ�
	char temp;//�����ݴ浱ǰ���һ���ַ�
	int i=0;//ѭ��

	while(n>0)//��תn���ַ��������ƽ���n�ν��в���
	{
		{
		//ע��'\0'������ת���������±��0��ʼ������������ĸ�±�Ϊsz-2
		temp=arr[sz-2];//�ݴ浱ǰ�����һ���ַ�
		p=&arr[sz-2];//ָ��ǰ���һ���ַ�
		q=&arr[sz-3];//����ָ�򵱵����ڶ����ַ�
		for(i=0;i<sz/2+1;i++)//�ַ�����
		{
			*p=*q;
			p--;
			q--;
		}//pָ��'\0'ǰһ���ַ���qָ�����һ���ַ�'\0'
		*p=temp;//����һ���ַ���'\0'ǰһ���������һ���ַ�
		n--;
		}
	}
}
	
int determin(char arr[],char arr2[],int sz)//�ж��Ƿ�Ϊ��ת����ַ���
{
	char *p=NULL;//����ָ���һ���ַ�
	char *q=NULL;//����ָ����һ���ַ�
	char temp;//�����ݴ浱ǰ��һ���ַ�
	int i=0;//ѭ��
	int n=sz-1;//ѭ����⣬����n-1��

	while(n>0)//��תn���ַ��������ƽ���n�ν��в���
	{
	if(strcmp(arr,arr2)==0)
		return 1;
	else
		{
		temp=arr[0];//�ݴ浱ǰ��һ���ַ�
		p=arr;//ָ��ǰ��һ���ַ�
		q=&arr[1];//����ָ��ǰ�ڶ����ַ�
		for(i=0;i<sz/2+1;i++)//�ַ�����
		{
			*p=*q;
			p++;
			q++;
		}//pָ��'\0'ǰһ���ַ���qָ�����һ���ַ�'\0'
		*p=temp;//�������ַ���'\0'ǰһ��������һ���ַ�
		n--;
		}
	}
	return 0;
}