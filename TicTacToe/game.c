#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>
#include"game.h"

void Game()
{
	int n=0;//标记谁嬴 0 平局 1电脑赢 2玩家赢 
    int count=0;//棋子数
	char arr[Column][Line]={' '};//存放棋子位置
	while(1)//棋盘未放满count<Column*Line
	{
		system("cls");
		printf("\n*************电脑走*************\n");
		Sleep(1000);
		C_Piece(Column,Line,arr);//电脑先下
		count++;
		Board(Column,Line,&arr[0]);//传输数组首地址
		n=P_Judge(Column,Line,&arr[0]);//n=1,电脑赢
		if(n==1)
		{
			 printf("电脑赢！\n");
		     break;
		}
		
		if(count==(Column*Line))//棋盘放满退出
		 break;

		printf("\n*************玩家走**************\n");
		U_piece(Column,Line,&arr[0]);
		count++;
		Board(Column,Line,&arr[0]);
		Sleep(2000);
	    n=U_Judge(Column,Line,&arr[0]);//n=1,玩家赢
		if(n==2)
		{
			 printf("玩家赢！\n");
		     break;
		}
	}

	if(n==0)
	printf("平局！\n");
}

void Board(const int column,const int line,char arr[][Line])
{
	int i=0;
	int j=0;
	    printf("\n\t -0 - 1- 2-\n");
	for(i=0;i<Column;i++)
	{
		printf("\t |--|--|--|\n");
		printf("\t%d|%c |%c |%c |\n",i,arr[i][0],arr[i][1],arr[i][2]);
	}
	    printf("\t |--|--|--|\n");
}

int  C_Piece(const int column,const int line,char arr[][Line])
{
	int i=0,j=0;
	int x=0;
	int y=0;

	while(1)  //控制获是否重选位置
	{
		x=tnum(column);
		y=tnum(line);
		for(i=0;i<column;i++)
		{
			for(j=0;j<line;j++)
			{
					if ((i==x)&&(j==y))
						if((arr[i][j]!='*')&&(arr[i][j]!='#'))
						{
						 arr[i][j]='*';
						 printf("\n电脑输入位置（%d,%d）",x,y);
						 return 0;//退出
						}		
			}	
		}
	}
}

int U_piece(const int column,const int line,char arr[][Line])
{
	int i=0,j=0;
	int x=0;
	int y=0;

	while(1)  //控制是否重选位置
	{
		getchar();
		printf("\n玩家输入位置（x,y）：");
		scanf("%d %d",&x,&y);
		for(i=0;i<column;i++)
		{
			for(j=0;j<line;j++)
			{
					if ((i==x)&&(j==y))
						if((arr[i][j]!='*')&&(arr[i][j]!='#'))
						{
						 arr[i][j]='#';
						 return 0;//退出
						}		
			}	
		}
	}
}


int P_Judge(const int column,const int line,char arr[][Line])
{
	int i=0;
	int j=0;
	
	
	for(i=0;i<column;i++)
	{
			if((arr[0][i]=='*'&&arr[i+1][i+1]=='*'&&arr[i+2][i+2]=='*')||//对角线1
				(arr[i][i+2]=='*'&&arr[i+1][i+1]=='*'&&arr[i+2][i]=='*')||//对角线2
				(arr[i][0]=='*'&&arr[i][1]=='*'&&arr[i][2]=='*')||//同一行
				(arr[0][i]=='*'&&arr[1][i]=='*'&&arr[2][i]=='*'))//同一列
			   return 1;       
	}
	return 0;
}

int U_Judge(const int column,const int line,char arr[][Line])
{
	int i=0;
	int j=0;
	
	for(i=0;i<column;i++)
	{
			if((arr[0][i]=='#'&&arr[i+1][i+1]=='#'&&arr[i+2][i+2]=='#')||//对角线1
				(arr[i][i+2]=='#'&&arr[i+1][i+1]=='#'&&arr[i+2][i]=='#')||//对角线2
				(arr[i][0]=='#'&&arr[i][1]=='#'&&arr[i][2]=='#')||//同一行
				(arr[0][i]=='#'&&arr[1][i]=='#'&&arr[2][i]=='#'))//同一列
			{
			  return 2;       
			}
	}
	return 0;
}

int tnum(const int n)
{
	return (rand()%2*rand()%7)%n;
}