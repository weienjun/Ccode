#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"game.h"

void Game(const int count)
{
	char arr1[Column+2][Line+2]={' '};//存放雷（#）
	char arr2[Column+2][Line+2];//存放雷数，和打印所选的位置（空格）,0，column+2行和列用于计算不打印
	//memset(arr,0,sizeof(arr));//数组所有值替换函数memset(数组名，替换数，sizeof(数组名))
	memset(arr2,'*',sizeof(arr2));//给数组所有元素初始化
	Position(count,Column,Line,arr1);//布雷

	while(1)
	{
		system("cls");
		Board(Column,Line,arr2);
		if(0==Choose(count,Column,Line,arr1,arr2))//0表示失败,
		{
		 printf("\t失败！\n\n");
		 Board1(Column,Line,arr1);//打印雷区
		 break;
		}
		else if(num(count,Column,Line,arr2))//非0表示成功
		{
			printf("\t成功！\n\n");
			Board(Column,Line,arr2);//打印结果
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
	static int n=1;//标记第一次

	while(1)//用于检验输入是否正确
	{
		printf("\n\t输入位置（x,y）：");
		scanf("%d %d",&x,&y);
		printf("\n");
		if(x<1||x>column||y<1||y>line)
		{
		  printf("重新输入！\n");
		}
		else
			break;
	}
	i=x;
	j=y;
	while(arr1[i][j]=='#'&&n==1)//保证第一次不死
	{
		arr1[x][y]=' ';
		i=rand()%column+1;
		j=rand()%line+1;
		if(arr1[i][j]=='#')//重新位置为雷，重新寻找位置
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
			return 0;//失败，雷
		}
		else if(arr1[x][y]!='#')
		{
			print(x,y,arr1,arr2);
			if(x-1!=1&&y-1!=1)
			print(x-1,y-1,arr1,arr2);
			if(x+1!=column&&y+1!=line)
            print(x+1,y+1,arr1,arr2);
			return 1;//未失败，非雷
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