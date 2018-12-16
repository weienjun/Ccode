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
start:	printf("\n**********欢迎进入三子棋游戏！**********\n");
	printf("\n1->进入游戏  2->游戏说明  0->退出游戏\n");
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
				Game();//游戏实现函数
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
				printf("\n*开始电脑先走！\n");
				printf("\n*玩家根据棋盘坐标，输入对应的位置，若此处已放棋子则重新输入！\n");
				printf("\n*祝你玩的愉快！\n");
				getchar();
				printf("\n是否继续游戏！ Y or N \n");
				printf("输入选择：");
				scanf("%c",&ch);
				system("cls");
				if(ch=='Y'||ch=='y')
				goto start;
				printf("\n************退出游戏！************\n");
				break;
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