/*

//1~100������
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int i = 0;
	int j = 0;
	for(i = 1;i <= 100; i = i+2)//ż����������
	{
		for(j = 2; j < sqrt((float)i); j++)//�κ�һ�����ɿ�����������˵ĵ�������������С��Ϊ������ͬ
		//for(j = 2; j < i; j++)
		{
			if(i%j == 0)
			{
				break;
			}
		}
		if(j > sqrt((float)i))//δ���ҵ�
		//if(i == j)
	        printf("%d ",i);
	}
	system("pause");
	return 0;
}

*/



//��С������
#include<stdio.h>
#include<stdlib.h>

int MAX_sum(int num1,int num2)//���Լ��
{
	int i = num1;
	if(num1 > num2)
		i = num2;
	for(; i > 0 ;i--)
	{
		if(num2%i == 0 && num1%i == 0)
			return i;
	}
	return 1;
}

//���Լ��
//����1��շת�������������max%��С����min = ����1����С����min%����1=����2,��С����Ϊ����1%����2.����
//ѭ������С����С��������������Ϊ���
//����2���������������-��С����=��1����С����-��1=��2����С������1-��2������
//ѭ���Ϊ0����������Ϊ���
//����3����ٷ��������/С������С����--������ֱ�����������ɱ���������Ϊ���Լ��

//��С������=�˻�/���Լ��
int MIN_sum2(int num1,int num2)//��С������
{
	int min = num1;
	int max = num2;
	int num = 0;
	if(num1 > num2)//ȷ�������С��
	{
		num = max;
		max = min;
		min = num;
	}

	while(num)//շת���
	{
		num = max%min;
		max = min;
		min = num;
	}
	return (num1*num2)/max;
}

int MIN_sum(int num1,int num2)//��С������
{
	int num = 1;
	int i = num1;
	if(num1 > num2)
		i = num2;
	for(i; i > 1;i--)//˼������Ż�
	{
		if(num2%i == 0 && num1%i == 0)
		{
			num1 /= i;
			num2 /= i;
			num *= i;
		}
	}
	return (num *= num1*num2);
}

int main()
{
	int num1 = 0;
	int num2 = 0;
	printf("����num:");
	scanf("%d%d",&num1,&num2);

	printf("%d\n",MAX_sum(num1,num2));

	printf("%d\n",MIN_sum2(num1,num2));
	printf("%d\n",MIN_sum(num1,num2));
	system("pause");
	return 0;
}