
/*
//дһ����ӡ�����С�ĳ˷��ھ�����
#include<stdio.h>
#include<stdlib.h>

void multiply(int num1);
int main()
{
	int num1=0;
	
	printf("����ھ����С��");
	scanf("%d",&num1);

	multiply(num1);//��ӡ�˷��ھ�����
    system("pause");
    return 0;
}

void multiply(int num1)
{
	int num=0;//���
	int i=0,j=0;//����ѭ��
	
	for(i=1;i<=num1;i++)//������
	{
		for(j=1;j<=i;j++)//������
		{
			num=i*j;//������˽��
			printf("%d*%d=%-4d",i,j,num);//%-4d��ʾ����룬4���ַ�
		}
		printf("\n");//����
	}
}

*/

/*

//����������
#include<stdio.h>
#include<stdlib.h>

void exchange(int *num1,int *num2);//ͨ����ַ�����������ĺ���
int main()
{
	int num1=0;
	int num2=0;

	printf("����num1,num2��ֵ��");
	scanf("%d%d",&num1,&num2);

	exchange(&num1,&num2);//ͨ����ַ����������
	printf("������:num1=%d\tnum2=%d\n",num1,num2);

	system("pause");
	return 0;

}

void exchange(int* num1,int* num2)
{
	*num1=*num1^*num2;
	*num2=*num1^*num2;//num1
	*num1=*num1^*num2;//num2
}

*/

/*
//�ж�����
#include<stdio.h>
#include<stdlib.h>

int leap(int n);//���귵��1�����Ƿ���0
int main()
{
	int year=0;
	int n=0;
	
	printf("�����꣺");
	scanf("%d",&year);
	
	n=leap(year);//���귵��1�����Ƿ���0

	if(1==n)
		printf("����%d\n",year);
	else
		printf("�������꣡\n");

	system("pause");
	return 0;
}

int leap(int year)
{
	return ((year%400==0)||((year%4==0)&(year%100!=0)));//�߼����㣬����Ϊ1��������Ϊ0
}

*/



//
//����һ�����飬 
//ʵ�ֺ���init������ʼ�����顢 
//ʵ��empty����������顢 
//ʵ��reverse���������������Ԫ�ص����á� 
//Ҫ���Լ���ƺ����Ĳ���������ֵ�� 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10//�����С

void init(int arr[],int sz);//�����ʼ��
void reverse(int arr[],int sz);//��������
void print(int *parr,int sz);//�������
void empty(int arr[],int sz);//�������

int main()
{
	int arr[N];

	init(arr,N);
	printf("\n����ǰ���\n");
	print(arr,N);
	reverse(arr,N);//����
	printf("\n���ú����\n");
	print(arr,N);
	empty(arr,N);//���,���ú���memset
	//memset(arr,0,sizeof(arr));//��������ֵ�滻����memset(���������滻����sizeof(������))
	system("pause");
	return 0;
}

void init(int arr[],int sz)
{
	int i=0;
	for(i=0;i<sz;i++)
	{
		printf("�����%d��ֵ:",i);
		scanf("%d",&arr[i]);
	}
}

void reverse(int arr[],int sz)
{
	int i=0;
	int j=sz-1;//�����С��һΪ����±�

	for(i=0,j=sz-1;i<sz/2;i++,j--)//ǰ�󽻻�ֻ����һ��Ĵ���
	{
		arr[i]=arr[i]^arr[j];//ǰֵ���ֵ����
		arr[j]=arr[i]^arr[j];
		arr[i]=arr[i]^arr[j];
	}
}

void print(int *parr,int sz)
{
	int i=0;
	for(i=0;i<sz;i++)
	{
		printf("%d  ",*parr);//*parr�൱��arr[i]
		parr++;//ָ����һ��ַ��Ϊ�����һֵ��׼��
	}
}

void empty(int arr[],int sz)
{
	int i=0;
	for(i=0;i<sz;i++)
		arr[i]=0;//�������
}



/*

//�ж��Ƿ�Ϊ����
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int prime_num(int num);
int main()
{
	int num=0;
	int n=0;
	printf("��������:");
	scanf("%d",&num);

	n=prime_num(num);
	if(n==1)
		printf("%d������\n",num);
	else
		printf("%d��������\n",num);

	system("pause");
	return 0;
}

int prime_num(int num)
{
	int i=0;
	for(i=2;i<=sqrt((float)num);i++)//float�����Ž����Ż�
	{
		if(0==num%i)
			return 0;
	}//����ѭ��ʱ��num=i��num��������
	return 1;
}

*/