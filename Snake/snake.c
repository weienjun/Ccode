#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include"snake.h"

void SetPos(int x,int y)
{
	HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);//获取句柄

	COORD pos;//设置光标位置
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(handle,pos);//移动光标           
}

void menu(void)//菜单
{
	pSnake  snake=NULL;//蛇初始化
	int speed=0;
	frame fra;;
	SetPos(10,8);
	printf("欢迎进入游戏!\n");

	SetPos(10,10);
    printf("请输入边界大小：");
	SetPos(10,12);
    printf("MAX_X=");
	scanf("%d",&fra.MAX_X);
	fra.MAX_X =fra.MAX_X + fra.MAX_X%2;//保证为偶数
	SetPos(20,12);
    printf("  MAX_Y=");
	scanf("%d",&fra.MAX_Y);

	SetPos(10,14);
    printf("输入速度500 + ");
	scanf("%d",&speed);

	SetPos(10,16);
	printf("按任意键进入！\n");
	system("pause");
	system("cls");
	CreateMap(fra);
	Init_all(snake,fra,speed);//蛇初始化
}


void CreateMap(frame fra)//构建边界
{
	int i=0;
	int j=0;

	for(i=0;i<=fra.MAX_X;i=i+2)//行
	{
		SetPos(i,0);
	    printf(FOOD);
		SetPos(i,fra.MAX_Y);
	    printf(FOOD);
	}
	for(i=0;i<=fra.MAX_Y;i++)//列
	{
		SetPos(0,i);
	    printf(FOOD);
		SetPos(fra.MAX_X,i);
	    printf(FOOD);
	}
}

void Snake_Init(pSnake_Node * snake)//蛇初始化
{
	int i=0;;
	for(i=INIT_X;i<INIT_X*4 ;i=i+2)
	{
		Push_front(snake,i,INIT_Y);//头插
		SetPos((*snake)->x,(*snake)->y);
	    printf(FOOD);
	}
}

void Push_front(pSnake_Node * phead,const int x,const int y)//头插
{
	pSnake_Node pnew=(pSnake_Node)malloc(sizeof(Snake_Node));
	pnew->x=x;
	pnew->y=y;
	pnew->Next=*phead;
	*phead=pnew;
}


pSnake_Node Snake_run(pSnake pSnake,pSnake_Node newhead)//运动头插
{
	pSnake_Node ptemp=NULL;
	pSnake_Node del=NULL;

	newhead->Next=pSnake->_pSnake;
	pSnake->_pSnake=newhead;

	ptemp=pSnake->_pSnake;
	while(ptemp->Next)
	{
		del=ptemp;
		SetPos(ptemp->x,ptemp->y);
		printf(FOOD);
		ptemp=ptemp->Next;
	}
	return del;
}

void Init_all(pSnake  Snake,frame fra,const int speed)//初始化所有信息
{
	int i=0;
	Snake=(pSnake)malloc(sizeof(Snake));//构造蛇
	Snake->_pFood=(pSnake_Node)malloc(sizeof(Snake_Node));//创建食物容器
	Snake->_pSnake=NULL;
	Snake_Init(&(Snake)->_pSnake);//初始化蛇身
	Snake->_status=OK;
	Snake->SleepTime=500+speed;
	Snake_move(Snake,fra);//移动
}

void Init_food(pSnake  snake,frame fra)//初始化食物
{
	int x=0;
	int y=0;
	srand((int)time(0));//以时间为种子产生随机数
	while(1)
	{
		while((x=rand()%(fra.MAX_X-3)+2)%2 != 0);//2~54
		y=rand()%(fra.MAX_Y-1)+1;
		if(snake->_pSnake->x != x && snake->_pSnake->y !=y)
			break;
	}
	snake->_pFood->x=x;
	snake->_pFood->y=y;
	SetPos(x,y);
    printf(FOOD);
}

void Snake_move(pSnake snake,frame fra)//移动
{
	pSnake_Node newhead = NULL;
	snake->_Dir=right;
	Init_food(snake,fra);
	while(snake->_status == OK)
	{
		newhead=(pSnake_Node)malloc(sizeof(Snake_Node));//创建新的节点
		//if(GetAsyncKeyState(VK_UP) && snake->_Dir != down)
		//	snake->_Dir=up;
		//else if(GetAsyncKeyState(VK_DOWN) && snake->_Dir != up)
		//	snake->_Dir=down;
		//else if(GetAsyncKeyState(VK_LEFT) && snake->_Dir != right)
		//	snake->_Dir=left;
		//else if(GetAsyncKeyState(VK_RIGHT) && snake->_Dir != left)
		//	snake->_Dir=right;
		Snake_fx(snake);//方向
		switch(snake->_Dir)
		{
		case up:
			newhead->y=snake->_pSnake->y-1;
			newhead->x=snake->_pSnake->x;
			break;
		case down:
			newhead->y=snake->_pSnake->y+1;
			newhead->x=snake->_pSnake->x;
			break;
		case left:
			newhead->x=snake->_pSnake->x-2;
			newhead->y=snake->_pSnake->y;
			break;
		case right:
			newhead->x=snake->_pSnake->x+2;
			newhead->y=snake->_pSnake->y;
			break;
		default:
			break;
		}

		Snake_zt(snake,newhead,fra);//蛇的状态,
		xx(snake,fra);//打印信息 
        Snake_eat(snake,newhead,fra);//吃食物处理,及移动处理
	
		Sleep(snake->SleepTime);
	}
}

void Snake_eat(pSnake snake,pSnake_Node newhead,frame fra)//吃食物处理
{
if((newhead->x == snake->_pFood->x) && (newhead->y == snake->_pFood->y))//吃到食物
	{
		snake->count++;
        Snake_run(snake,newhead);//运动头插
	    Init_food(snake,fra);
	}
	else
	{
		pSnake_Node del=NULL;
		pSnake_Node ptemp=NULL;
        del=Snake_run(snake,newhead);//运动头插
		ptemp=del->Next;
		SetPos(ptemp->x,ptemp->y);
        printf("  ");//尾删
	    del->Next=NULL;
	    free(ptemp);
	}
}

void Snake_zt(pSnake snake,pSnake_Node newhead,frame fra)//蛇的状态
{
	pSnake_Node ptemp=snake->_pSnake;

	while(ptemp)
	{
		if((ptemp->x == newhead->x)&&
		   (ptemp->y == newhead->y))
		{
			snake->_status=MY_DES;//咬死
			printf("咬死\n");
			return ;
		}
		ptemp=ptemp->Next;
	}

	if((newhead->x == 0  || newhead->x == fra.MAX_X)||
	   (newhead->y == 0  || newhead->y == fra.MAX_Y))
	{
		snake->_status=PUT_DES;//撞死
		SetPos(fra.MAX_X/2,fra.MAX_Y/2);
		printf("you over!\n");
		return ;
	}
}

void Snake_fx(pSnake snake)//方向
{

	//if((GetAsyncKeyState(VK_UP)   && snake->_Dir==up ))
	//	snake->SleepTime -= 10;//加速
	//else if(GetAsyncKeyState(VK_DOWN) && snake->_Dir==down)
	//	snake->SleepTime -= 10;//加速

	//else if((GetAsyncKeyState(VK_LEFT) && snake->_Dir==left))
	//	snake->SleepTime -= 10;//加速
	//else if((GetAsyncKeyState(VK_RIGHT)&& snake->_Dir)==right)
	//{
	//	snake->SleepTime -= 10;//加速
	//	return ;
	//}
	if(GetAsyncKeyState(VK_UP) && snake->_Dir != down)
		snake->_Dir=up;
	else if(GetAsyncKeyState(VK_DOWN) && snake->_Dir != up)
		snake->_Dir=down;
	else if(GetAsyncKeyState(VK_LEFT) && snake->_Dir != right)
		snake->_Dir=left;
	else if(GetAsyncKeyState(VK_RIGHT) && snake->_Dir != left)
		snake->_Dir=right;
}

void xx(pSnake snake,frame fra)//打印信息 
{
	int x=fra.MAX_X+10;
	int y=2;

	SetPos(x,y++);
	switch(snake->_status)
	{
	case OK:
		printf("蛇的状态：良好\n");
		break;
	case PUT_DES://撞死
		printf("蛇的状态：撞死\n");
		break;
	case MY_DES://咬死
		printf("蛇的状态：咬死\n");
		break;
	}

	SetPos(x,y++);
	printf("行进速度：%d\n",snake->SleepTime);

	SetPos(x,y++);
	printf("获取食物：%d\n",snake->count);
    SetPos(x,y++);
	switch(snake->_Dir)
	{
	case up:
		printf("前进方向：上\n");
		break;
	case down:
		printf("前进方向：下\n");
		break;
	case left:
		printf("前进方向：左\n");
		break;
	case right:
		printf("前进方向：右\n");
		break;
	}
}