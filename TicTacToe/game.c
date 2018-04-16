#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>
#include"game.h"

void Game()
{
	int n=0;//���˭�� 0 ƽ�� 1����Ӯ 2���Ӯ 
    int count=0;//������
	char arr[Column][Line]={' '};//�������λ��
	while(1)//����δ����count<Column*Line
	{
		system("cls");
		printf("\n*************������*************\n");
		Sleep(1000);
		C_Piece(Column,Line,arr);//��������
		count++;
		Board(Column,Line,&arr[0]);//���������׵�ַ
		n=P_Judge(Column,Line,&arr[0]);//n=1,����Ӯ
		if(n==1)
		{
			 printf("����Ӯ��\n");
		     break;
		}
		
		if(count==(Column*Line))//���̷����˳�
		 break;

		printf("\n*************�����**************\n");
		U_piece(Column,Line,&arr[0]);
		count++;
		Board(Column,Line,&arr[0]);
		Sleep(2000);
	    n=U_Judge(Column,Line,&arr[0]);//n=1,���Ӯ
		if(n==2)
		{
			 printf("���Ӯ��\n");
		     break;
		}
	}

	if(n==0)
	printf("ƽ�֣�\n");
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

	while(1)  //���ƻ��Ƿ���ѡλ��
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
						 printf("\n��������λ�ã�%d,%d��",x,y);
						 return 0;//�˳�
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

	while(1)  //�����Ƿ���ѡλ��
	{
		getchar();
		printf("\n�������λ�ã�x,y����");
		scanf("%d %d",&x,&y);
		for(i=0;i<column;i++)
		{
			for(j=0;j<line;j++)
			{
					if ((i==x)&&(j==y))
						if((arr[i][j]!='*')&&(arr[i][j]!='#'))
						{
						 arr[i][j]='#';
						 return 0;//�˳�
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
			if((arr[0][i]=='*'&&arr[i+1][i+1]=='*'&&arr[i+2][i+2]=='*')||//�Խ���1
				(arr[i][i+2]=='*'&&arr[i+1][i+1]=='*'&&arr[i+2][i]=='*')||//�Խ���2
				(arr[i][0]=='*'&&arr[i][1]=='*'&&arr[i][2]=='*')||//ͬһ��
				(arr[0][i]=='*'&&arr[1][i]=='*'&&arr[2][i]=='*'))//ͬһ��
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
			if((arr[0][i]=='#'&&arr[i+1][i+1]=='#'&&arr[i+2][i+2]=='#')||//�Խ���1
				(arr[i][i+2]=='#'&&arr[i+1][i+1]=='#'&&arr[i+2][i]=='#')||//�Խ���2
				(arr[i][0]=='#'&&arr[i][1]=='#'&&arr[i][2]=='#')||//ͬһ��
				(arr[0][i]=='#'&&arr[1][i]=='#'&&arr[2][i]=='#'))//ͬһ��
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