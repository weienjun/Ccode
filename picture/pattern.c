#include<stdio.h>
#include<stdlib.h>
#define N 7//����
void patter(int n);
int main ()
{
	int n=0;//ͼ�εı��
	n=1;//1��ʾͼ���ϲ���
	patter(n);
	n=2;//22��ʾͼ���²���
	patter(n);
	system("pause");
	return 0;
}
void patter(int n)//��ӡͼ����
{
	int i=0;//������
	int j=0;//������
	int k=0;//���ƿո�
	int a=0;//����ͼ��Ĳ��֣�a=i,��ӡ�ϲ��֡�a=t��ӡͼ���²��֡�
	int t=N;//���ڱ����м��ظ�����ӡ�ϲ���a=i<Nʡ������У�t=N��ӡ�²���ʱ������

	for(i=0;i<N;i++,t--)//������
	{

		if(n==1)//�жϴ�ӡ�ǲ���
			a=i;
		else
			a=t;

		for(k=N-a;k>0;k--)//���ƿո�
		{
			printf(" ");
		}

		for(j=a*2-1;j>0;j--)//�����кʹ�ӡ*
		{
			printf("*");
		}

		printf("\n");//���ƻ���
	}
	
}