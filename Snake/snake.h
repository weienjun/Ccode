#ifndef __STAKE_H__

#define __STAKE_H__

#define FOOD "□"
#define INIT_X  4 //初始x,y(2的倍数)
#define INIT_Y 5
//#define MAX_X 56 //偶数
//#define MAX_Y 25

typedef struct Frame
{
	size_t MAX_X;
	size_t MAX_Y;
}frame;

typedef struct Node_ //蛇有关位置
{
	int x;
	int y;
	struct Node_ * Next;
}Snake_Node,*pSnake_Node;//单向链表

enum Dir//方向
{
   up,
   down,
   left,
   right,
};

enum Status//蛇状态
{
	OK,//正常
	PUT_DES,//撞死
	MY_DES,//咬死
	OVER,//退出
};

typedef struct Snake //状态信息
{

	pSnake_Node _pSnake;//指向蛇
	pSnake_Node _pFood;//蛇食物
	enum Status _status;//状态
	enum Dir _Dir;//行走方向
	int SleepTime;//时间
	size_t count;//获取食物数
}Snake,*pSnake;

void SetPos(int x,int y);
void menu(void);//菜单
void CreateMap(frame fra);//构建边界
void Snake_Init(pSnake_Node * snake);//蛇初始化
void Push_front(pSnake_Node * phead,const int x,const int y);//头插
pSnake_Node Snake_run(pSnake pSnake,pSnake_Node newhead);//运动头插
void Init_all(pSnake  Snake,frame fra,const int speed);//初始化所有信息
void Init_food(pSnake  snake,frame fra);//初始化食物
void Snake_move(pSnake snake,frame fra);//移动
void Snake_eat(pSnake snake,pSnake_Node newhead,frame fra);//吃食物处理,及运动
void Snake_zt(pSnake snake,pSnake_Node newhead,frame fra);//蛇的状态
void Snake_fx(pSnake snake);//方向
void xx(pSnake snake,frame fra);//打印信息 

#endif