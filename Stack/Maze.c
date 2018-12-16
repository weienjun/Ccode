/*
//��ʵ��̫���ӣ���Ӧ����ַ����ջ�У�����ÿ�����½�һ���ṹ��ָ�룬����ַ�����ջ�У���ʹջ��ָ��ͬ�ĵ�ַ
//Ӧֱ�ӽ��ṹ���������ջ�У���ֻ������Ԫ�أ����Դ���Ӱ�첻��
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"stack.h"
#include"Maze.h"

void Map_Init(int map[][LOW], const int mp[][LOW],Pos* enter)//��ͼ��ʼ��
{
	int i=0,j=0;
	assert(enter);
	enter->_x=5;//���
	enter->_y=1;
	for(i = 0;i < ROW ;i++)
	{
		for(j = 0;j < LOW ;j++)
		{
			map[i][j]=mp[i][j];
		}
	}
}

void print_map(int map[][LOW])
{
	int i=0,j=0;
	for(i = 0;i < ROW ;i++)
	{
		for(j = 0;j < LOW ;j++)
		{
			printf("%2d ",map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


void Maze_Delete(stack* entry)//����
{
	type del = NULL;
	if(entry == NULL)
		return ;
	while(!Stack_Empty(entry))
	{
		del = Stack_Top(entry);
 		free(del);//����ջ������ĵ�ַ�Ŀռ�
		Stack_Pop(entry);
	}
	del = NULL;
}
//ע��ջ�д���ǽṹ��ĵ�ַ������Ϊͬһ����ַ
//������ѹջʱ��ÿ�δ���һ���µĽṹ��ָ���ŵ�ǰ�ĵ�ַ���Դ˽�������
int start(int map[][LOW], Pos* enter)//�Թ�
{
	type tmp = (type)malloc(sizeof(Pos));
	stack entry;//��һ��ջ���洢·��
	Pos cur;
	Pos next;
	assert(map);
	assert(enter);
	Stack_Init(&entry);
	
	memmove(tmp,enter,sizeof(Pos));//��ڸ���tmp
	Stack_push(&entry,tmp);//��ڷ���ջ��(�������tmp�ĵ�ַ)

	map[enter->_x][enter->_y] = 2;
	while(!Stack_Empty(&entry))
	{
		type tmp = NULL;
		memmove(&cur,Stack_Top(&entry),sizeof(Pos));//��ջ��ֵ����cur
		if(Exit(&cur,enter))//������ڣ�
		{
			map[cur._x][cur._y] = 3;
			Maze_Delete(&entry);//����ջ�������ַ�Ŀռ�
			Stack_Delete(&entry);//����ջ
			return 1 ;
		}
		//up
		next = cur;//��cur���ݸ���next
		next._x -= 1;//�ı�ֵ
		if(Run(map,&next))//���ߣ�
		{
		    tmp = (type)malloc(sizeof(Pos)); 
			memmove(tmp,&next,sizeof(Pos));
			Stack_push(&entry,tmp);
			continue;
		}

		//left
		next = cur;//��ԭxԭֵ��ȡԭֵ��
		next._y -=1;
		if(Run(map,&next))//���ߣ�
		{
		    tmp = (type)malloc(sizeof(Pos)); 
			memmove(tmp,&next,sizeof(Pos));
			Stack_push(&entry,tmp);
			continue;
		}
		//right
		next = cur;//��ԭxԭֵ
		next._y += 1;
		if(Run(map,&next))//���ߣ�
		{
		    tmp = (type)malloc(sizeof(Pos)); 
			memmove(tmp,&next,sizeof(Pos));
			Stack_push(&entry,tmp);
			continue;
		}
		//down
		next = cur;//��ԭxԭֵ
		next._x += 1;
		if(Run(map,&next))//���ߣ�
		{
		    tmp = (type)malloc(sizeof(Pos)); 
			memmove(tmp,&next,sizeof(Pos));	
			Stack_push(&entry,tmp);
			continue;
		}
		//��������
		{  
			type del = Stack_Top(&entry);
			free(del);//���ٳ�ջ�ĵ�ַ���ڴ�ռ�
		    Stack_Pop(&entry);
		}
	}
	Maze_Delete(&entry);//����ջ�������ַ�Ŀռ�
	Stack_Delete(&entry);//����ջ
	return 0;
}

int srun(int map[][LOW], Pos* ptmp,Pos* enter)//�ݹ���
{
	Pos cur ;
	Pos next;
	assert(map);
	memmove(&cur,ptmp,sizeof(Pos));
	map[cur._x][cur._y] = 2 ;
	if(Exit(&cur,enter))//������ڣ�
	{
		map[cur._x][cur._y] = 3;
		return 1;
	}
	//up
	next = cur ;
	next._x -= 1;
	if(Run(map,&next))//����
	{
		//�з���ֵ���ҵ�һ��ͨ·�Ͳ���������·��
		//if(srun(map,&next,enter));//�ݹ���
		//return 1;
		srun(map,&next,enter);
	}
	//left
    next = cur ;
	next._y -= 1;
	if(Run(map,&next))//����
	{
		//if(srun(map,&next,enter));//�ݹ���
		//return 1;
		srun(map,&next,enter);
	}
	//right  
    next = cur; 
	next._y += 1;
	if(Run(map,&next))//����
	{
		//if(srun(map,&next,enter));//�ݹ���
		//return 1;
		srun(map,&next,enter);
	}
	//down
    next = cur; 
	next._x += 1;
	if(Run(map,&next))//����
	{
		//if(srun(map,&next,enter));//�ݹ���
		//return 1;
		srun(map,&next,enter);
	}
	//return 0 ;
}

static void Compare(stack* s_cur,stack* s_min)//��ѡ���·��
{
	size_t i = 0;
	assert(s_cur||s_min);
	if(s_cur->_size < s_min->_size || s_min->_size == 0)//�ж�·���Ƿ��֮ǰС
	{
		if(!Stack_Empty(s_min))
			Maze_Delete(s_min);//����ջ������ĵ�ַ�Ŀռ䣬����s_minջ�е�·��
		for(i = 0;i < s_cur->_size;i++)//��s_curջ��ÿ������ĵ�ַ����һ���������ٴ���s_minջ��
		{
			type temp = (type)malloc(sizeof(Pos));
			memmove(temp,s_cur->_data[i],sizeof(Pos));
			Stack_push(s_min,temp);//����s_minջ��
		}
	}
	//memmove(s_min,s_cur,sizeof(s_cur->_size));//��ջ�д洢��·����ַ������s_minջ��ָ��ͬһ���ַ��
	//�˳��˺�����ջs_min��ȻΪ��
}

int Run1(int map[][LOW],const Pos* next,const Pos* cur)//���ߣ�
{
	if((cur->_x >= 0 && cur->_x <= ROW-1 && cur->_y >= 0 && cur->_y <= LOW-1)&&
		(map[cur->_x][cur->_y] == 1 || map[next->_x][next->_y] < map[cur->_x][cur->_y]))
	{
		return 1;
	}
	else
		return 0;
}

void run_min(int map[][LOW],Pos* ptmp,Pos* enter,stack* s_cur,stack* s_min)//���·��
{
	Pos cur ;
	Pos ncur ;
	type tmp = (type)malloc(sizeof(Pos));
	Pos next ;
	assert(map);

	memmove(&cur,ptmp,sizeof(Pos));
	if(!Stack_Empty(s_cur))
	{
	    next = *(Stack_Top(s_cur));
		map[cur._x][cur._y] = map[next._x][next._y]+1;
	}

	memmove(tmp,&cur,sizeof(Pos));//�����п��ߵ�·����ջ
    Stack_push(s_cur,tmp); //����ջ���ж��Ƿ񵽴���ڣ���������޷���ջ

	if(Exit(&cur,enter))//������ڣ�
	{
		Compare(s_cur,s_min);//��ѡ���·��
	}

	//up
	ncur = cur;
	ncur._x -= 1;
	if(Run1(map,&cur,&ncur))//����
	{
		 //memmove(tmp,&cur,sizeof(Pos));
		 //Stack_push(s_cur,tmp);
		 run_min(map,&ncur,enter,s_cur,s_min);//�ݹ�+ջ �����·��
	}

	//right  
	ncur = cur;
	ncur._y += 1;
	if(Run1(map,&cur,&ncur))//����
	{
		 //memmove(tmp,&cur,sizeof(Pos));
		 //Stack_push(s_cur,tmp);
		run_min(map,&ncur,enter,s_cur,s_min);//�ݹ�+ջ �����·��
	}

	//left
	ncur = cur;
	ncur._y -= 1;
	if(Run1(map,&cur,&ncur))//����
	{
		 //memmove(tmp,&cur,sizeof(Pos));
		 //Stack_push(s_cur,tmp);
		run_min(map,&ncur,enter,s_cur,s_min);//�ݹ�+ջ �����·��
	}
	
	//down 
	ncur = cur;
	ncur._x += 1;
	if(Run1(map,&cur,&ncur))//����
	{
		 //memmove(tmp,&cur,sizeof(Pos));
		 //Stack_push(s_cur,tmp);
		run_min(map,&ncur,enter,s_cur,s_min);//�ݹ�+ջ �����·��
	}

	free(tmp);//���߲�ͬ�����꣬��ռ�Ŀռ�������٣�����ǰջ����
	Stack_Pop(s_cur);//�����ߵ������ַ��ջ
	//ע��������߲�ͨ�ĵ�ַ���г�ջ���������򲻿���������·��������
}

void Min(int map[][LOW],Pos* enter)//���·��
{
	stack s_cur;
	stack s_min;
	size_t i = 0;
	//type tmp = (type)malloc(sizeof(Pos));
	//memmove(tmp,enter,sizeof(Pos));

	Stack_Init(&s_cur);
	Stack_Init(&s_min);
	//Stack_push(&s_cur,tmp);
	//Stack_push(&s_cur,enter);//��ڷ���ջ��(�������cur�ĵ�ַ)
    run_min(map,enter,enter,&s_cur,&s_min);//�ݹ�+ջ �����·��

	printf("ջ�����·����%d\n",s_min._size);
	for(i=0;i<s_min._size;i++)
	{
		printf("%d %d\n",s_min._data[i]->_x,s_min._data[i]->_y);
	}

	Maze_Delete(&s_min);//����ջ������ĵ�ַ�Ŀռ�
	Stack_Delete(&s_min);//����ջ
	Maze_Delete(&s_cur);//����ջ������ĵ�ַ�Ŀռ�
	Stack_Delete(&s_cur);//����ջ
}

int Run(int map[][LOW],const Pos* cur)//���ߣ�
{
	if(map[cur->_x][cur->_y] == 1)
	{
		map[cur->_x][cur->_y] = 2;
		return 1;
	}
	else
		return 0;
}

int Exit(const Pos* cur,const Pos* entre)//������ڣ�
{
	if((cur->_x != entre->_x )||//��Ϊ���
		(cur->_y != entre->_y))
	{
		if(	cur->_x == 0 || cur->_x == ROW-1 ||
			cur->_y == 0 || cur->_y == LOW-1)
		{
			return 1;
		}
		else
			return 0;
	}
	else//Ϊ���
		return 0;
}

void Maze_test()
{
	int map[ROW][LOW];
	Pos enter;
	int mp[][LOW]={
		{0,0,0,0,0,0},
		{0,1,1,1,1,0},
		{0,1,0,0,1,0},
		{1,1,0,0,1,1},
		{0,1,1,1,1,0},
		{0,2,0,1,0,0}};

	Map_Init(map,mp,&enter);
	print_map(map);
	printf("\n");
  	//printf("%d\n",start(map,&enter));//�Թ�
	//srun(map,&enter,&enter);//�ݹ���
    //print_map(map);//��ӡ��ͼ

	Min(map,&enter);//���·��
    print_map(map);//��ӡ��ͼ
}
*/