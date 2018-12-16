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
start:	printf("\n**********欢迎进入扫雷游戏！**********\n");
	printf("\n1->进入游戏  2->游戏说明  3->游戏设置  0->退出游戏\n");
	printf("\n输入选择:");
	scanf("%d",&choose);
		switch(choose)
		{
			while(ch=='Y'||ch=='Y')
	     {
			case 0:
				system("cls");
				printf("\n************退出游戏！************\n");
				ch='N';
				break;
			case 1:
				system("cls");
				while(ch=='Y'||ch=='y')
				{
				printf("\n************游戏开始！************\n");
				Game(count);//游戏实现函数
				getchar();
				printf("是否继续游戏！ Y or N \n");
				printf("输入选择：");
				scanf("%c",&ch);
				}
				system("cls");
				printf("\n************退出游戏！************\n");
				break;
			case 2:
				system("cls");
				printf("\n************游戏说明！************\n");
				printf("\n*搜索非雷的位置，直至找出所有的非雷区！\n");
				printf("\n*找到雷区，则失败！\n");
				printf("\n*可以设置雷的数目！\n");
				getchar();
				printf("\n是否继续游戏！ Y or N \n");
				printf("输入选择：");
				scanf("%c",&ch);
				system("cls");
				if(ch=='Y'||ch=='y')
				goto start;
				printf("\n************退出游戏！************\n");
				break;
			case 3:
				printf("\n输入雷的数目(1~99)：");
				scanf("%d",&n);
				getchar();
			    printf("是确认！ Y or N \n");
				printf("输入选择：");
		        scanf("%c",&ch);
				system("cls");
				if(ch=='Y'||ch=='y')
			    count=n;
				goto start;

			default:
				system("cls");
				getchar();
				printf("输入错误！\n");
			    printf("是否继续游戏！ Y or N \n");
				printf("输入选择：");
		        scanf("%c",&ch);
				system("cls");
				if(ch=='Y'||ch=='y')
				{
				goto start;
				}
				printf("\n************退出游戏！************\n");
				break;
		}
	}

}