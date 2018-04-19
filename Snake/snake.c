#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include"snake.h"

void SetPos(int x,int y)
{
	HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ���

	COORD pos;//���ù��λ��
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(handle,pos);//�ƶ����           
}

void menu(void)//�˵�
{
	pSnake  snake=NULL;//�߳�ʼ��
	int speed=0;
	frame fra;;
	SetPos(10,8);
	printf("��ӭ������Ϸ!\n");

	SetPos(10,10);
    printf("������߽��С��");
	SetPos(10,12);
    printf("MAX_X=");
	scanf("%d",&fra.MAX_X);
	fra.MAX_X =fra.MAX_X + fra.MAX_X%2;//��֤Ϊż��
	SetPos(20,12);
    printf("  MAX_Y=");
	scanf("%d",&fra.MAX_Y);

	SetPos(10,14);
    printf("�����ٶ�500 + ");
	scanf("%d",&speed);

	SetPos(10,16);
	printf("����������룡\n");
	system("pause");
	system("cls");
	CreateMap(fra);
	Init_all(snake,fra,speed);//�߳�ʼ��
}


void CreateMap(frame fra)//�����߽�
{
	int i=0;
	int j=0;

	for(i=0;i<=fra.MAX_X;i=i+2)//��
	{
		SetPos(i,0);
	    printf(FOOD);
		SetPos(i,fra.MAX_Y);
	    printf(FOOD);
	}
	for(i=0;i<=fra.MAX_Y;i++)//��
	{
		SetPos(0,i);
	    printf(FOOD);
		SetPos(fra.MAX_X,i);
	    printf(FOOD);
	}
}

void Snake_Init(pSnake_Node * snake)//�߳�ʼ��
{
	int i=0;;
	for(i=INIT_X;i<INIT_X*4 ;i=i+2)
	{
		Push_front(snake,i,INIT_Y);//ͷ��
		SetPos((*snake)->x,(*snake)->y);
	    printf(FOOD);
	}
}

void Push_front(pSnake_Node * phead,const int x,const int y)//ͷ��
{
	pSnake_Node pnew=(pSnake_Node)malloc(sizeof(Snake_Node));
	pnew->x=x;
	pnew->y=y;
	pnew->Next=*phead;
	*phead=pnew;
}


pSnake_Node Snake_run(pSnake pSnake,pSnake_Node newhead)//�˶�ͷ��
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

void Init_all(pSnake  Snake,frame fra,const int speed)//��ʼ��������Ϣ
{
	int i=0;
	Snake=(pSnake)malloc(sizeof(Snake));//������
	Snake->_pFood=(pSnake_Node)malloc(sizeof(Snake_Node));//����ʳ������
	Snake->_pSnake=NULL;
	Snake_Init(&(Snake)->_pSnake);//��ʼ������
	Snake->_status=OK;
	Snake->SleepTime=500+speed;
	Snake_move(Snake,fra);//�ƶ�
}

void Init_food(pSnake  snake,frame fra)//��ʼ��ʳ��
{
	int x=0;
	int y=0;
	srand((int)time(0));//��ʱ��Ϊ���Ӳ��������
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

void Snake_move(pSnake snake,frame fra)//�ƶ�
{
	pSnake_Node newhead = NULL;
	snake->_Dir=right;
	Init_food(snake,fra);
	while(snake->_status == OK)
	{
		newhead=(pSnake_Node)malloc(sizeof(Snake_Node));//�����µĽڵ�
		//if(GetAsyncKeyState(VK_UP) && snake->_Dir != down)
		//	snake->_Dir=up;
		//else if(GetAsyncKeyState(VK_DOWN) && snake->_Dir != up)
		//	snake->_Dir=down;
		//else if(GetAsyncKeyState(VK_LEFT) && snake->_Dir != right)
		//	snake->_Dir=left;
		//else if(GetAsyncKeyState(VK_RIGHT) && snake->_Dir != left)
		//	snake->_Dir=right;
		Snake_fx(snake);//����
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

		Snake_zt(snake,newhead,fra);//�ߵ�״̬,
		xx(snake,fra);//��ӡ��Ϣ 
        Snake_eat(snake,newhead,fra);//��ʳ�ﴦ��,���ƶ�����
	
		Sleep(snake->SleepTime);
	}
}

void Snake_eat(pSnake snake,pSnake_Node newhead,frame fra)//��ʳ�ﴦ��
{
if((newhead->x == snake->_pFood->x) && (newhead->y == snake->_pFood->y))//�Ե�ʳ��
	{
		snake->count++;
        Snake_run(snake,newhead);//�˶�ͷ��
	    Init_food(snake,fra);
	}
	else
	{
		pSnake_Node del=NULL;
		pSnake_Node ptemp=NULL;
        del=Snake_run(snake,newhead);//�˶�ͷ��
		ptemp=del->Next;
		SetPos(ptemp->x,ptemp->y);
        printf("  ");//βɾ
	    del->Next=NULL;
	    free(ptemp);
	}
}

void Snake_zt(pSnake snake,pSnake_Node newhead,frame fra)//�ߵ�״̬
{
	pSnake_Node ptemp=snake->_pSnake;

	while(ptemp)
	{
		if((ptemp->x == newhead->x)&&
		   (ptemp->y == newhead->y))
		{
			snake->_status=MY_DES;//ҧ��
			printf("ҧ��\n");
			return ;
		}
		ptemp=ptemp->Next;
	}

	if((newhead->x == 0  || newhead->x == fra.MAX_X)||
	   (newhead->y == 0  || newhead->y == fra.MAX_Y))
	{
		snake->_status=PUT_DES;//ײ��
		SetPos(fra.MAX_X/2,fra.MAX_Y/2);
		printf("you over!\n");
		return ;
	}
}

void Snake_fx(pSnake snake)//����
{

	//if((GetAsyncKeyState(VK_UP)   && snake->_Dir==up ))
	//	snake->SleepTime -= 10;//����
	//else if(GetAsyncKeyState(VK_DOWN) && snake->_Dir==down)
	//	snake->SleepTime -= 10;//����

	//else if((GetAsyncKeyState(VK_LEFT) && snake->_Dir==left))
	//	snake->SleepTime -= 10;//����
	//else if((GetAsyncKeyState(VK_RIGHT)&& snake->_Dir)==right)
	//{
	//	snake->SleepTime -= 10;//����
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

void xx(pSnake snake,frame fra)//��ӡ��Ϣ 
{
	int x=fra.MAX_X+10;
	int y=2;

	SetPos(x,y++);
	switch(snake->_status)
	{
	case OK:
		printf("�ߵ�״̬������\n");
		break;
	case PUT_DES://ײ��
		printf("�ߵ�״̬��ײ��\n");
		break;
	case MY_DES://ҧ��
		printf("�ߵ�״̬��ҧ��\n");
		break;
	}

	SetPos(x,y++);
	printf("�н��ٶȣ�%d\n",snake->SleepTime);

	SetPos(x,y++);
	printf("��ȡʳ�%d\n",snake->count);
    SetPos(x,y++);
	switch(snake->_Dir)
	{
	case up:
		printf("ǰ��������\n");
		break;
	case down:
		printf("ǰ��������\n");
		break;
	case left:
		printf("ǰ��������\n");
		break;
	case right:
		printf("ǰ��������\n");
		break;
	}
}