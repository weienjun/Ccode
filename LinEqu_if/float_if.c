#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define ENP 0.0000000001//���޽ӽ�0����

//�����Ԫһ�η��̵Ľ� ax^2+bx+c=0;
float Calculation(float a,float b,float c);
float Judgement(float a,float b,float num);

int main ()
{
	float num=0.0;
	float a=0;
	float b=0;
	float c=0;

	printf("����a,b,c��ֵ:");
	scanf("%f%f%f",&a,&b,&c);

	num=Calculation(a,b,c);
	Judgement(a,b,num);//���

	system("pause");
	return 0;
}

float Calculation(float a,float b,float c)
{
	return ((b*b)-4*a*c);
}

float Judgement(float a,float b,float num)
{
	float num1=0;
	float num2=0;

  if(a>-ENP&&a<ENP)//���޽ӽ�0��������0
  {
	printf("���Ƕ�Ԫһ�η��̣�\n");
	return 0;//������������
  }

  else if(num<-ENP)
	  printf("�޽�\n");

  else if(num>-ENP&&num<ENP)
  {
	  num1=num2=(-b-sqrt(num))/(2*a);
	  printf("��һ��:%f\n",num1);
  }

  else if(num>ENP)
  {
	  num1=(-b-sqrt(num))/(2*a);
	  num2=(-b+sqrt(num))/(2*a);
	  printf("�����⣺%f\t%f\n",num1,num2);
  }
  return 0;
}