#include<stdio.h>
#include<stdlib.h>

void Conversion(char ch[]);
int main()
{
	char ch[10];

	while(1)
	{
	printf("�����ַ���:");
	scanf("%s",ch);
	Conversion(ch);
	}

	system("pause");
	return 0;
}

void Conversion(char ch[])
{
	int i=0;
	
	printf("ת����");
	while(ch[i]!='\0')//��Ϊ�ַ�����β
	{
		if(ch[i]>=97&&ch[i]<=122)
		{
	    ch[i]-=32;//ÿ���ַ�����ת��
		printf("%c",ch[i]);
		}

	    else if(ch[i]>=65&&ch[i]<=90)
		{
		ch[i]+=32;
		printf("%c",ch[i]);
		}

		else if(ch[i]>=48&&ch[i]<=57)//��������
		{
			i++;
			continue;
		}

		else//�����ַ��������
		printf("%c",ch[i]);
	
	i++;
	}
	printf("\n");//���н����¸��ַ���ת��
}