#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"game.h"

void Game(const int count)
{
	char arr1[Column+2][Line+2]={' '};//����ף�#��
	char arr2[Column+2][Line+2];//����������ʹ�ӡ��ѡ��λ�ã��ո�,0��column+2�к������ڼ��㲻��ӡ
	//memset(arr,0,sizeof(arr));//��������ֵ�滻����memset(���������滻����sizeof(������))
	memset(arr2,'*',sizeof(arr2));//����������Ԫ�س�ʼ��
	Position(count,Column,Line,arr1);//����

	while(1)
	{
		system("cls");
		Board(Column,Line,arr2);
		if(0==Choose(count,Column,Line,arr1,arr2))//0��ʾʧ��,
		{
		 printf("\tʧ�ܣ�\n\n");
		 Board1(Column,Line,arr1);//��ӡ����
		 break;
		}
		else if(num(count,Column,Line,arr2))//��0��ʾ�ɹ�
		{
			printf("\t�ɹ���\n\n");
			Board(Column,Line,arr2);//��ӡ���
			break;
		}
			
	}
	
}

void Board(const int column,const int line,char arr2[][Line+2])
{
	int i=0;
	printf("\t  -1 -2- 3 -4 -5 -6 -7 -8 -9 -10- \n");
	for(i=1;i<=column;i++)
	{
		printf("\t%2d|%c |%c |%c |%c |%c |%c |%c |%c |%c |%c |\n",i,arr2[i][1],arr2[i][2],
		arr2[i][3],arr2[i][4],arr2[i][5],arr2[i][6],arr2[i][7],arr2[i][8],arr2[i][9],arr2[i][10]);
		printf("\t  |--|--|--|--|--|--|--|--|--|--|\n");
	}
}

int Position(const int count,const int column,const int line,char arr1[][Line+2])
{
	int i=0;
	int x=0;
	int y=0;

	while(i<count)
	{
		x=rand()%column+1;
		y=rand()%line+1;
		if(arr1[x][y]!='#')
		{
			arr1[x][y]='#';
			i++;         
		}
	}		
}

int Choose(const int count,const int column,const int line,char arr1[][Line+2],char arr2[][Line+2])
{
	int x=0;
	int y=0;
	int i=0;
	int j=0;
	static int n=1;//��ǵ�һ��

	while(1)//���ڼ��������Ƿ���ȷ
	{
		printf("\n\t����λ�ã�x,y����");
		scanf("%d %d",&x,&y);
		printf("\n");
		if(x<1||x>column||y<1||y>line)
		{
		  printf("�������룡\n");
		}
		else
			break;
	}
	i=x;
	j=y;
	while(arr1[i][j]=='#'&&n==1)//��֤��һ�β���
	{
		arr1[x][y]=' ';
		i=rand()%column+1;
		j=rand()%line+1;
		if(arr1[i][j]=='#')//����λ��Ϊ�ף�����Ѱ��λ��
		 continue;
		else
		{
		arr1[i][j]='#';
		break;
		}
	}
	n++;
	
	while(1)
	{
		if(arr1[x][y]=='#')
		{
			return 0;//ʧ�ܣ���
		}
		else if(arr1[x][y]!='#')
		{
			print(x,y,arr1,arr2);
			if(x-1!=1&&y-1!=1)
			print(x-1,y-1,arr1,arr2);
			if(x+1!=column&&y+1!=line)
            print(x+1,y+1,arr1,arr2);
			return 1;//δʧ�ܣ�����
		}
	}
}

static void print(const int x,const int y,char arr1[][Line+2],char arr2[][Line+2])
{
	int n=0;
	int i=0;
	int j=0;

	if(arr1[x][y]!='#')
	{
		for(i=x-1;i<=x+1;i++)
		{
			for(j=y-1;j<=y+1;j++)
			{
				if(arr1[i][j]=='#')
				{
					n++;
				}
				else if ((arr2[i][y-1]=='*'&&arr2[i][y]=='*'&&arr2[i][y+1]=='*')||
						 (arr2[y-1][i]=='*'&&arr2[y][i]=='*'&&arr2[y+1][i]=='*'))
						 arr2[i][j]=' ';
			}
		}
		arr2[x][y]=n+'0';
	}
}

void Board1(const int column,const int line,char arr1[][Line+2])
{
	int i=0;
	printf("\t  -1 -2- 3 -4 -5 -6 -7 -8 -9 -10- \n");
	for(i=1;i<=column;i++)
	{
		printf("\t%2d|%c |%c |%c |%c |%c |%c |%c |%c |%c |%c |\n",i,arr1[i][1],arr1[i][2],
		arr1[i][3],arr1[i][4],arr1[i][5],arr1[i][6],arr1[i][7],arr1[i][8],arr1[i][9],arr1[i][10]);
		printf("\t  |--|--|--|--|--|--|--|--|--|--|\n");
	}
}

static int num(const int count,const int column,const int line,char arr2[][Line+2])
{
	int i=0;
	int j=0;
    int n=0;

	for(i=1;i<=column;i++)
	{
		for(j=1;j<=line;j++)
		{
			if(arr2[i][j]=='*')
				n ++; 
		}
	}
		if(n==count)
		{
			return 1;
		}
		else
			return 0;
}