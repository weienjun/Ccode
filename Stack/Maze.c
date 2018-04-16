/*
//此实现太复杂，不应将地址存入栈中，导致每次需新建一个结构体指针，将地址存放在栈中，以使栈的指向不同的地址
//应直接将结构体变量存在栈中，因只有两个元素，所以传参影响不大
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"stack.h"
#include"Maze.h"

void Map_Init(int map[][LOW], const int mp[][LOW],Pos* enter)//地图初始化
{
	int i=0,j=0;
	assert(enter);
	enter->_x=5;//入口
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


void Maze_Delete(stack* entry)//销毁
{
	type del = NULL;
	if(entry == NULL)
		return ;
	while(!Stack_Empty(entry))
	{
		del = Stack_Top(entry);
 		free(del);//销毁栈中所存的地址的空间
		Stack_Pop(entry);
	}
	del = NULL;
}
//注：栈中存的是结构体的地址，即都为同一个地址
//所以在压栈时需每次创建一个新的结构体指针存放当前的地址，以此进行区分
int start(int map[][LOW], Pos* enter)//迷宫
{
	type tmp = (type)malloc(sizeof(Pos));
	stack entry;//定一个栈，存储路径
	Pos cur;
	Pos next;
	assert(map);
	assert(enter);
	Stack_Init(&entry);
	
	memmove(tmp,enter,sizeof(Pos));//入口赋给tmp
	Stack_push(&entry,tmp);//入口放入栈中(放入的是tmp的地址)

	map[enter->_x][enter->_y] = 2;
	while(!Stack_Empty(&entry))
	{
		type tmp = NULL;
		memmove(&cur,Stack_Top(&entry),sizeof(Pos));//将栈顶值赋给cur
		if(Exit(&cur,enter))//到达出口？
		{
			map[cur._x][cur._y] = 3;
			Maze_Delete(&entry);//销毁栈中所存地址的空间
			Stack_Delete(&entry);//销毁栈
			return 1 ;
		}
		//up
		next = cur;//将cur内容赋给next
		next._x -= 1;//改变值
		if(Run(map,&next))//可走？
		{
		    tmp = (type)malloc(sizeof(Pos)); 
			memmove(tmp,&next,sizeof(Pos));
			Stack_push(&entry,tmp);
			continue;
		}

		//left
		next = cur;//还原x原值（取原值）
		next._y -=1;
		if(Run(map,&next))//可走？
		{
		    tmp = (type)malloc(sizeof(Pos)); 
			memmove(tmp,&next,sizeof(Pos));
			Stack_push(&entry,tmp);
			continue;
		}
		//right
		next = cur;//还原x原值
		next._y += 1;
		if(Run(map,&next))//可走？
		{
		    tmp = (type)malloc(sizeof(Pos)); 
			memmove(tmp,&next,sizeof(Pos));
			Stack_push(&entry,tmp);
			continue;
		}
		//down
		next = cur;//还原x原值
		next._x += 1;
		if(Run(map,&next))//可走？
		{
		    tmp = (type)malloc(sizeof(Pos)); 
			memmove(tmp,&next,sizeof(Pos));	
			Stack_push(&entry,tmp);
			continue;
		}
		//都不可走
		{  
			type del = Stack_Top(&entry);
			free(del);//销毁出栈的地址的内存空间
		    Stack_Pop(&entry);
		}
	}
	Maze_Delete(&entry);//销毁栈中所存地址的空间
	Stack_Delete(&entry);//销毁栈
	return 0;
}

int srun(int map[][LOW], Pos* ptmp,Pos* enter)//递归走
{
	Pos cur ;
	Pos next;
	assert(map);
	memmove(&cur,ptmp,sizeof(Pos));
	map[cur._x][cur._y] = 2 ;
	if(Exit(&cur,enter))//到达出口？
	{
		map[cur._x][cur._y] = 3;
		return 1;
	}
	//up
	next = cur ;
	next._x -= 1;
	if(Run(map,&next))//可走
	{
		//有返回值则找到一条通路就不在走其它路径
		//if(srun(map,&next,enter));//递归走
		//return 1;
		srun(map,&next,enter);
	}
	//left
    next = cur ;
	next._y -= 1;
	if(Run(map,&next))//可走
	{
		//if(srun(map,&next,enter));//递归走
		//return 1;
		srun(map,&next,enter);
	}
	//right  
    next = cur; 
	next._y += 1;
	if(Run(map,&next))//可走
	{
		//if(srun(map,&next,enter));//递归走
		//return 1;
		srun(map,&next,enter);
	}
	//down
    next = cur; 
	next._x += 1;
	if(Run(map,&next))//可走
	{
		//if(srun(map,&next,enter));//递归走
		//return 1;
		srun(map,&next,enter);
	}
	//return 0 ;
}

static void Compare(stack* s_cur,stack* s_min)//挑选最短路径
{
	size_t i = 0;
	assert(s_cur||s_min);
	if(s_cur->_size < s_min->_size || s_min->_size == 0)//判断路径是否比之前小
	{
		if(!Stack_Empty(s_min))
			Maze_Delete(s_min);//销毁栈中所存的地址的空间，更新s_min栈中的路径
		for(i = 0;i < s_cur->_size;i++)//将s_cur栈中每个坐标的地址拷贝一份下来，再存在s_min栈中
		{
			type temp = (type)malloc(sizeof(Pos));
			memmove(temp,s_cur->_data[i],sizeof(Pos));
			Stack_push(s_min,temp);//放入s_min栈中
		}
	}
	//memmove(s_min,s_cur,sizeof(s_cur->_size));//将栈中存储的路劲地址拷贝给s_min栈（指向同一块地址）
	//退出此函数后栈s_min依然为空
}

int Run1(int map[][LOW],const Pos* next,const Pos* cur)//可走？
{
	if((cur->_x >= 0 && cur->_x <= ROW-1 && cur->_y >= 0 && cur->_y <= LOW-1)&&
		(map[cur->_x][cur->_y] == 1 || map[next->_x][next->_y] < map[cur->_x][cur->_y]))
	{
		return 1;
	}
	else
		return 0;
}

void run_min(int map[][LOW],Pos* ptmp,Pos* enter,stack* s_cur,stack* s_min)//最短路径
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

	memmove(tmp,&cur,sizeof(Pos));//将所有可走的路径入栈
    Stack_push(s_cur,tmp); //先入栈后判断是否到达出口，否则出口无法入栈

	if(Exit(&cur,enter))//到达出口？
	{
		Compare(s_cur,s_min);//挑选最短路径
	}

	//up
	ncur = cur;
	ncur._x -= 1;
	if(Run1(map,&cur,&ncur))//可走
	{
		 //memmove(tmp,&cur,sizeof(Pos));
		 //Stack_push(s_cur,tmp);
		 run_min(map,&ncur,enter,s_cur,s_min);//递归+栈 求最短路径
	}

	//right  
	ncur = cur;
	ncur._y += 1;
	if(Run1(map,&cur,&ncur))//可走
	{
		 //memmove(tmp,&cur,sizeof(Pos));
		 //Stack_push(s_cur,tmp);
		run_min(map,&ncur,enter,s_cur,s_min);//递归+栈 求最短路径
	}

	//left
	ncur = cur;
	ncur._y -= 1;
	if(Run1(map,&cur,&ncur))//可走
	{
		 //memmove(tmp,&cur,sizeof(Pos));
		 //Stack_push(s_cur,tmp);
		run_min(map,&ncur,enter,s_cur,s_min);//递归+栈 求最短路径
	}
	
	//down 
	ncur = cur;
	ncur._x += 1;
	if(Run1(map,&cur,&ncur))//可走
	{
		 //memmove(tmp,&cur,sizeof(Pos));
		 //Stack_push(s_cur,tmp);
		run_min(map,&ncur,enter,s_cur,s_min);//递归+栈 求最短路径
	}

	free(tmp);//将走不同的坐标，所占的空间进行销毁（即当前栈顶）
	Stack_Pop(s_cur);//不可走的坐标地址出栈
	//注：必须对走不通的地址进行出栈操作，否则不可再走其它路径！！！
}

void Min(int map[][LOW],Pos* enter)//最短路径
{
	stack s_cur;
	stack s_min;
	size_t i = 0;
	//type tmp = (type)malloc(sizeof(Pos));
	//memmove(tmp,enter,sizeof(Pos));

	Stack_Init(&s_cur);
	Stack_Init(&s_min);
	//Stack_push(&s_cur,tmp);
	//Stack_push(&s_cur,enter);//入口放入栈中(放入的是cur的地址)
    run_min(map,enter,enter,&s_cur,&s_min);//递归+栈 求最短路径

	printf("栈的最短路径：%d\n",s_min._size);
	for(i=0;i<s_min._size;i++)
	{
		printf("%d %d\n",s_min._data[i]->_x,s_min._data[i]->_y);
	}

	Maze_Delete(&s_min);//销毁栈中所存的地址的空间
	Stack_Delete(&s_min);//销毁栈
	Maze_Delete(&s_cur);//销毁栈中所存的地址的空间
	Stack_Delete(&s_cur);//销毁栈
}

int Run(int map[][LOW],const Pos* cur)//可走？
{
	if(map[cur->_x][cur->_y] == 1)
	{
		map[cur->_x][cur->_y] = 2;
		return 1;
	}
	else
		return 0;
}

int Exit(const Pos* cur,const Pos* entre)//到达出口？
{
	if((cur->_x != entre->_x )||//不为入口
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
	else//为入口
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
  	//printf("%d\n",start(map,&enter));//迷宫
	//srun(map,&enter,&enter);//递归走
    //print_map(map);//打印地图

	Min(map,&enter);//最短路径
    print_map(map);//打印地图
}
*/