

/*

//�ݹ��ӡÿһλ
#include<stdio.h>
#include<stdlib.h>

void print(int num)//�ݹ����125->1 2 5

int main()
{
  int num=0;
  printf("put num:");
  scanf("%d",&num);
  print(num);

  system(" pause");
  return 0;
}

//ִ������
//�ݹ��ǰ�һ��һ���˳��ִ�е�.
//ֻ�е����ڲ�ִ�н������ִ����һ��δִ�е���䣬ÿһ�㶼Ϊ�ݹ麯�����壬��ÿ��ʵ�ʶ�����ͬ
//����(num=5)��
//��n��ִ�б�ʽ print��pn��ʽ
//��n��ִ�б�ʽ printf��pfn��ʽ
//����㵽�ڲ��˳��ִ�У�ֻ�е����ڲ�ִ�н�����Ž���ִ����һ��δִ�е���䣬�������������ִ�н����ġ�
//(p1->( p2->(p3->(p4->(p5->pf5)->pf4->pf3)pf2)pf1)
//p2->(p3->(p4->(p5->pf5)->pf4->pf3)pf2
//p3->(p4->(p5->pf5)->pf4->pf3
//p4->(p5->pf5)->pf4
//p5->pf5
void print(int num)//num=5
{
 if(num>10)
 {
  print(num/10);//digui. 54321-5432..->5
 }
 printf("%d  ",num%10);//5->4->3->2->1
}

*/


//             change(5)//���շ���5�����ô���Ϊ��������������1���Ĵ�����+1
//              /3+2    \
//	   change(4)         change(3)
//	   /  2+1  \           / 1+1  \
// change(3)  change(2)  change(2) change(1)
//   / 1+1  \     1         1         1
//change(2) change(1)
//   1         1   //����1�������ε���   



#include<stdio.h>
#include<stdlib.h>

int change(int num);//�ݹ������
int fbnqs(int num);//�ݹ���ڼ���������ֵ
int fbnqsy(int num);//�ǵݹ��쳲���������999��ȡģ��10007��
int fbnqs2(int num);//�ǵݹ���쳲�������

int main()
{
 int num=0;
 printf("put num:");
 scanf("%d",&num);
 
 printf("%d \n",change(num));
 printf("%d \n",fbnqs(num));
 printf("%d \n",fbnqs2(num));
 printf("%d \n",fbnqsy(num));

 system("pause");
 return 0;
}

//�ݹ���쳲���������1+1+2+3+5+8 ....
int fbnqs(int num)//��ڼ���������ֵ
{
	if(num<=2)//��num < 2
	{
		return 1%1007;
	}
	//return fbnqs(num-1)+fbnqs(num-2);
	return (fbnqs(num-1)+fbnqs(num-2));//쳲�������ȡģ ???

	//return (num <= 2) ?  1 : fbnqs(num-1)+fbnqs(num-2);
}

//��һ����ȡģ��ͬ�ڶԹ����Ǹ�����ÿ����ȡģ��
//�У�13%3=8%3+3%3+2%3=8%3+(3+2)%3
//Ϊ��ֹÿ����ȡģ�ĺʹ���ģ��������ÿ������ȡģ֮�ͺ��ٴ�ȡģ���ټ����¸������������Դ�����������
//�洢ÿ��쳲�������ȡģ�����������쳲�������
//��쳲�������ȡģ
int fbnqsy(int num){//��쳲���������999��ȡģ��10007��
	int a, b, c, i;
	a = 1;
	b = 1;
	if(num <= 2) return 1;
	for(i = 3; i <= num; i++){
		c = (a + b) %10007;//ǰ������������+��һ������������
		a = b % 10007;//��ȡģ���������ٴ�ȡģ��ֹ֮�ʹ���ģ��,
		b = c;//ǰ��������������
	}
	return c;
}

//����һ�����Ľ׳�
int change(int num)//������
{
  if(num==0 || num==1)//num==1ʱ���˳��ݹ� //����ע��num=0ʱ���������������
  {
  return num;
  }
  return num*change(num-1);//�ݹ飬�۳�
}
//�ǵݹ���쳲�������
int fbnqs2(int num)//�ǵݹ���쳲�������
{
	int i=0;
	int a=1;
	int b=1;
	int c=1;

	for(i=3;i<=num;i++)
	{
       c=a+b;//��¼�ڶ���ֵ��
	   a=b;//��¼��һ��ֵ
	   b=c;//��¼����ֵ�������
	}
	return c;
}




/*
//�ݹ����1235->1+2+3+5
#include<stdio.h>
#include<stdlib.h>

int change(int num);//�ݹ����1235->1+2+3+5

int main()
{
	int num=0;
	int num1=0;

	printf("�������֣�");
	scanf("%d",&num);

	printf("���Ϊ%d\n",change(num));
	system("pause");
	return 0;
}

int change(int num)
{
	static int n=0;
	if(num==0)//�˳�����
     return n;
	n+=num%10;//������ֵ
	change(num/10);//�ݹ�
}

*/


//4. ��дһ������reverse_string(char * string)���ݹ�ʵ�֣� 
//ʵ�֣��������ַ����е��ַ��������С� 
//Ҫ�󣺲���ʹ��C�������� 
//���ַ������������� 

/*

#include<stdio.h>
#include<stdlib.h>

int inoder(const char *arr);//�ݹ鵹������ַ���
int my_strlen(const char *arr);//�ݹ�ʵ��strlen����
int my_strlen2(const char *arr);//�ǵݹ�ʵ��strlen����

int main()
{
	char arr[]={"abcd1234"};
	inoder(arr);
	printf("\n�ַ�����Ϊ:%d \n",my_strlen(arr));
	printf("%d\n",my_strlen2(arr));
	system("pause");
	return 0;
}

int inoder(const char *arr)
{
	if(*arr=='\0')//�˳��ݹ�
	return ;
	inoder(arr+1);//ע����дarr++��++arr�������������
	printf("%c ",*arr);
}

int  my_strlen(const char *arr)//�ݹ����ַ�����
{
	static int count=0;
	if(*arr=='\0')
		return count;
	count++;
	my_strlen(arr+1);
}

int my_strlen2(const char *arr)//�ǵݹ����ַ�����
{
	int count=0;
	while(*arr)
	{
		count++;
		arr++;
	}
	return count;
}

*/

/*

//�ݹ���һ�����η�
#include<stdio.h>
#include<stdlib.h>

int calculation(const int num,const int k);//��η�����

int main()
{
	int num=0;
	int k=0;

	printf("�������ֺʹη���");
	scanf("%d %d",&num,&k);

	printf("���Ϊ:%d\n",calculation(num,k));
	system("pause");
	return 0;
}

int calculation(const int num,const int k)//��η�����
{
	static int temp=1;//������
	if(k==0)
		return temp;//���ؽ��
	temp*= num;//�۳�
	calculation(num,k-1);//�ݹ�
}

*/

/*
//����׳�
#include<stdio.h>
#include<stdlib.h>

int factorial(int num);//�ǵݹ���׳�
int change(int num);//�ݹ���׳�

int main()
{
	int num=0;
	printf("�������֣�");
	scanf("%d",&num);
	printf("�׳˽����%d\n",factorial(num));
	printf("�׳˽����%d\n",change(num));
	system("pause");
	return 0;
}

int factorial(int num)
{
	int n=1;
	while(num)
	{
		n*=num;
		num--;
	}
	return n;
}

int change(int num)//������
{
  if(num==1)//num==1ʱ���˳��ݹ�
  {
  return num;
  }
  return num*change(num-1);//�ݹ飬�۳�
}

*/