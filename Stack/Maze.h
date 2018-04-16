#ifndef __MAZE_H__

#define __MAZE_H__

#define ROW 6
#define LOW 6

typedef struct Position
{
	int _x;    
	int _y;
}Pos;

void Map_Init(int map[][LOW], const int mp[][LOW],Pos* enter);//地图初始化
void print_map(int map[][LOW]);//打印地图

int start(int map[][LOW],Pos* enter);//迷宫
int Exit(const Pos* cur,const Pos* entre);//到达出口？
int Run(int map[][LOW],const Pos* cur);//可走？
int srun(int map[][LOW], Pos* ptmp,Pos* enter);//递归走
//void Maze_Delete(stack* entry);//销毁
//void run_min(int map[][LOW],Pos* ptmp,Pos* enter,stack* s_cur);//递归+栈 求最短路径
//void run_min(int map[][LOW],Pos* ptmp,Pos* enter,stack* s_cur);//最短路径

void Min(int map[][LOW],Pos* enter);//最短路径

void Maze_test();
//static void Compare(stack* s_cur,stack* s_min);//挑选最短路径

#endif 