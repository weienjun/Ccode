//2���˷��ھ���
#include<stdio.h>
#include<stdlib.h>
int main ()
{
	int i;
	int j;
	for(i=1;i<=9;i++)//���Ƶ�һ��������
	{
		for(j=1;j<=i;j++)//���Ƶڶ�����
		   printf("%d*%d=%d   ",i,j,i*j);
	    printf("\n");
	}

	system("pause");
	return 0;
}