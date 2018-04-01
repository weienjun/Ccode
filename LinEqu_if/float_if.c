#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define ENP 0.0000000001//无限接近0的数

//计算二元一次方程的解 ax^2+bx+c=0;
float Calculation(float a,float b,float c);
float Judgement(float a,float b,float num);

int main ()
{
	float num=0.0;
	float a=0;
	float b=0;
	float c=0;

	printf("输入a,b,c的值:");
	scanf("%f%f%f",&a,&b,&c);

	num=Calculation(a,b,c);
	Judgement(a,b,num);//求根

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

  if(a>-ENP&&a<ENP)//无限接近0，即看作0
  {
	printf("不是二元一次方程！\n");
	return 0;//用于跳出函数
  }

  else if(num<-ENP)
	  printf("无解\n");

  else if(num>-ENP&&num<ENP)
  {
	  num1=num2=(-b-sqrt(num))/(2*a);
	  printf("有一解:%f\n",num1);
  }

  else if(num>ENP)
  {
	  num1=(-b-sqrt(num))/(2*a);
	  num2=(-b+sqrt(num))/(2*a);
	  printf("有两解：%f\t%f\n",num1,num2);
  }
  return 0;
}