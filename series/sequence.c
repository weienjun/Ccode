#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int a=0;//Ҫ�����
	int num=0;//���
	int i=0;//ѭ������
	int n=0;//�м����

	printf("����Ҫ�������");
	scanf("%d",&a);

	for(i=1;i<=5;i++)
	{
		n=((pow(10.0,i)-1)/9)*a;
		num+=n;
	}
	printf("%d\n",num);
	system("pause");
	return 0;
}