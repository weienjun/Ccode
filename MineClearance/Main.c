#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "game.h"

void Menu();
int main()
{

	Menu();
	system("pause");
	return 0;
}

void Menu()
{
	int count=10;
	int n=0;
	int choose=0;
	char ch='Y';
start:	printf("\n**********��ӭ����ɨ����Ϸ��**********\n");
	printf("\n1->������Ϸ  2->��Ϸ˵��  3->��Ϸ����  0->�˳���Ϸ\n");
	printf("\n����ѡ��:");
	scanf("%d",&choose);
		switch(choose)
		{
			while(ch=='Y'||ch=='Y')
	     {
			case 0:
				system("cls");
				printf("\n************�˳���Ϸ��************\n");
				ch='N';
				break;
			case 1:
				system("cls");
				while(ch=='Y'||ch=='y')
				{
				printf("\n************��Ϸ��ʼ��************\n");
				Game(count);//��Ϸʵ�ֺ���
				getchar();
				printf("�Ƿ������Ϸ�� Y or N \n");
				printf("����ѡ��");
				scanf("%c",&ch);
				}
				system("cls");
				printf("\n************�˳���Ϸ��************\n");
				break;
			case 2:
				system("cls");
				printf("\n************��Ϸ˵����************\n");
				printf("\n*�������׵�λ�ã�ֱ���ҳ����еķ�������\n");
				printf("\n*�ҵ���������ʧ�ܣ�\n");
				printf("\n*���������׵���Ŀ��\n");
				getchar();
				printf("\n�Ƿ������Ϸ�� Y or N \n");
				printf("����ѡ��");
				scanf("%c",&ch);
				system("cls");
				if(ch=='Y'||ch=='y')
				goto start;
				printf("\n************�˳���Ϸ��************\n");
				break;
			case 3:
				printf("\n�����׵���Ŀ(1~99)��");
				scanf("%d",&n);
				getchar();
			    printf("��ȷ�ϣ� Y or N \n");
				printf("����ѡ��");
		        scanf("%c",&ch);
				system("cls");
				if(ch=='Y'||ch=='y')
			    count=n;
				goto start;

			default:
				system("cls");
				getchar();
				printf("�������\n");
			    printf("�Ƿ������Ϸ�� Y or N \n");
				printf("����ѡ��");
		        scanf("%c",&ch);
				system("cls");
				if(ch=='Y'||ch=='y')
				{
				goto start;
				}
				printf("\n************�˳���Ϸ��************\n");
				break;
		}
	}

}