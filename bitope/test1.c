/*
//1.дһ���������ز����������� 1 �ĸ��� 
#include<stdio.h>
#include<stdlib.h>

int count_one_bit(int num);

int main()
{
	int num=0;
	int count=0;
	printf("�������֣�");
	scanf("%d",&num);
	count=count_one_bit(num);
	printf("������Ϊһ����%dλ\n",count);
	system("pause");
	return 0;
}

int count_one_bit(int num)
{
	int n=0;
	int i=0;
	int num1=num;

	while(num1>0)
	{
     num1=num>>i;
	if((num1&1)==1)
	{
		n++;
	}
	i++;
	}
	return n;
}

*/


/*
//2.��ȡһ�������������������е�ż��λ������λ���ֱ�������������С� 
#include<stdio.h>
#include<stdlib.h>

void bit_search(int num);
int main()
{
	int num=0;
	printf("�������֣�");
	scanf("%d",&num);
	bit_search(num);
	system("pause");
	return 0;
}

void bit_search(int num)
{
	int n1=15;//����λ�±�
	int n2=15;//ż��λ�±�
	int i=0;//��λ����
	int bit_odd[16]={0};//�����������������λ�����16λ����32λ��
	int bit_even[16]={0};
	int num1=num;//��λ����ֵ�������ж���ֹ

	while(num1>0)
	{
		num1=num>>i;
		if(i%2==0)
		{
		bit_odd[n1]=(num1&1);
		n1--;
		}
		else
		{
			bit_even[n2]=(num1&1);
			n2--;
		}
		i++;
		//n--;
	}
	printf("����λ�����ƣ�");
	for(i=0;i<16;i++)
	printf("%d",bit_odd[i]);

	printf("\nż��λ�����ƣ�");
	for(i=0;i<16;i++)
	printf("%d",bit_even[i]);
}

*/


/*
//3. ���һ��������ÿһλ�� 
#include<stdio.h>
#include<stdlib.h>

void bit_print(int num);
int main()
{
	int num=0;
	printf("��������:");
	scanf("%d",&num);
	bit_print(num);
	system("pause");
	return 0;

}

void bit_print(int num)
{
	int num1=num;
	int i=0;
	int n=0;//�����±��0-31
	int bit[32]={0};

	if(num<0)//������Ϊ��������
	{
	num=-num;
	num1=num;
	}

	while(num1>0)
	{
	num1=num>>i;
	bit[n]=num1&1;
	n++;
	i++;
	}

	for(n=i-1;n>=0;n--)
	printf("%d",bit[n]);

}

*/


//����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ�� 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int compare(int num1,int num2 );
int main()
{
	int num1=0;
	int num2=0;
	int count=0;

	printf("��������num1:");
	scanf("%d",&num1);
	printf("��������num2:");
	scanf("%d",&num2);

	count=compare(num1,num2);
	printf("��%dλ��ͬ\n",count);

	system("pause");
	return 0;
}

int compare(int num1,int num2)
{
   int i=0;
   int n=0;
   //��֤Ϊ�����Ƚϣ�������洢���Ƕ����ƵĲ��룬��������=ԭ�룬��������=ԭ��ȡ��+1
  // num1=sqrt(pow(num1,2.0));//sqrt�����ź�����qow�η�����
   //num2=sqrt(pow(num2,2.0));

   for(i=0;i<32;i++)
   {
	   if(((num1>>i)&1)!=((num2>>i)&1))//�Ƚ�λ�Ƿ���ͬ
		   n++;
   }
   return n;
}


/*

//�ж�һ�������������Ǹ���
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int num=01;
    printf("�������֣�");
	scanf("%d",&num);

	if((num>>31)&1)//32λ���λ��ʾ��������1��ʾ������0��ʾ����
		printf("����\n");
	else
		printf("����\n");

	system("pause");
	return 0;

}

*/

/*

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int num1=3;
	float num2=3.3;
	double num3=3.5;
	printf("����num1=%d\t�����ȸ�����num2=%f\t˫���ȸ�����num3=%lf\n",num1,num2,num3);

	printf("\n���ͳ���num1/2=%d\n",num1/2);//��������
	printf("���ͳ��Ը���������num1/2.0=%d\n",num1/2.0);//��������ͣ����������㣩������0
	printf("�������������num1/2=%f\n",num1/2);//�������㣬��ת���ɸ����������
	printf("�������Ը������������������num1/2.0=%f\n",num1/2.0);//���������������������������һ����Ϊ�����ͣ�2.0��Ϊ��������//

	printf("\n�����ȸ������������num2/2=%f\n",num2/2);//�����ȸ����ͳ���
	printf("˫���ȸ������������num3/2=%lf\n",num3/2);//˫���ȸ����ͳ���
	printf("������ת�����������������(int)num3/2=%d\n",(int)num3/2);//������ǿ��ת�������ͳ�����������
	printf("�����������������num3/2=%d\n",num3/2);//�����ͳ�����ת��������������������

	printf("\n����ȡģ����num1%%2=%d\n",num1%2);//ȡģ�������Ϊ�����㣬ע%%��ʾ��ӡ%
	printf("������ת������ȡģ����(int)num2%%2=%d\n",(int)num2%2);//���ͱ���ǿ��ת�������ͣ������������������֣��ɽ���ȡģ����
	//printf("%d\n",num2%2);//���������ɽ���ȡģ����

	system("pause");
	return 0;
}

*/


///*
//
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int num1=0;
//	int num2=0;
//	int num3=0;
//
//	num2=num1++;//�Ƚ�num1����num2,��num1��1����num2=0,num1=1;
//	num3=++num2;//��num2��1����num2ֵ����num3����num2=1,num3=1;
//
//	printf("num1=%d\tnum2=%d\tnum3=%d\n",num1,num2,num3);
//	system("pause");
//	return 0;
//}
//
///*
