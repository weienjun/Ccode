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
	int choose=0;
	char ch='Y';
start:	printf("\n**********��ӭ������������Ϸ��**********\n");
	printf("\n1->������Ϸ  2->��Ϸ˵��  0->�˳���Ϸ\n");
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
				Game();//��Ϸʵ�ֺ���
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
				printf("\n*��ʼ�������ߣ�\n");
				printf("\n*��Ҹ����������꣬�����Ӧ��λ�ã����˴��ѷ��������������룡\n");
				printf("\n*ף�������죡\n");
				getchar();
				printf("\n�Ƿ������Ϸ�� Y or N \n");
				printf("����ѡ��");
				scanf("%c",&ch);
				system("cls");
				if(ch=='Y'||ch=='y')
				goto start;
				printf("\n************�˳���Ϸ��************\n");
				break;
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