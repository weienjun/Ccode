/*
#include<stdio.h>
#include<stdlib.h>
#include"hdy.h"//���ú궨�庯��
int main ()
{
	int x=0,y=0;
	printf("����x,y:");
	scanf("%d%d",&x,&y);
    if(x==0)
		printf("xΪ0\n");

	while(1)
	{
		#if x<0//Ϊ��#if�ж�x<0 ��׼ȷ?#if��ɲ��ã���
		{
		printf("��������x:");
		scanf("%d",&x);
		}
		#else//#else #if...#endif��ͬ��#elif...
		#if(x==0)//Ϊ��#if�ж�x==0 ��׼ȷ?
			printf("***************\n");break;
		#else
		  break;	
		#endif
		#endif
	}

#ifdef MIX//����˺궨������
	printf("���MIX=%d\n",MIX(x,y));
#else
	printf("δ�����\n");
#endif

#undef MIX//ʹ��MIX��Ч����ȡ������

#ifndef MIX//���δ����˺�
	printf("�˴����¶����\n");
#define MIX(x,y) ((x)*(y))//�����������
#else
	printf("���mix=%d\n",MIX(x,y));
#endif

  printf("���MIX=%d\n",MIX(x,y));
	system("pause");
	return 0;
}*/


#include<stdio.h>
#include<stdlib.h>
#define UPPERCASE 1
int main()
{
	int i=0;
	char *str ="c pROGRAM";
	char ch;
	while((ch=str[i])!='\0')//�ж��Ƿ�Ϊ��ֹ�ַ�
	{
		i++;
#if UPPERCASE
    if(ch>='a'&&ch<='z')//Сдת���ɴ�д
        ch-=32;
	else if(ch>='A'&&ch<='Z')//��дת����Сд
		ch+=32;
#endif
	printf("%c",ch);
	}
	printf("\n");
	system("pause");
	return 0;
}

