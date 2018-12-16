#ifndef __MAZE_H__

#define __MAZE_H__

#define ROW 6
#define LOW 6

typedef struct Position
{
	int _x;    
	int _y;
}Pos;

void Map_Init(int map[][LOW], const int mp[][LOW],Pos* enter);//��ͼ��ʼ��
void print_map(int map[][LOW]);//��ӡ��ͼ

int start(int map[][LOW],Pos* enter);//�Թ�
int Exit(const Pos* cur,const Pos* entre);//������ڣ�
int Run(int map[][LOW],const Pos* cur);//���ߣ�
int srun(int map[][LOW], Pos* ptmp,Pos* enter);//�ݹ���
//void Maze_Delete(stack* entry);//����
//void run_min(int map[][LOW],Pos* ptmp,Pos* enter,stack* s_cur);//�ݹ�+ջ �����·��
//void run_min(int map[][LOW],Pos* ptmp,Pos* enter,stack* s_cur);//���·��

void Min(int map[][LOW],Pos* enter);//���·��

void Maze_test();
//static void Compare(stack* s_cur,stack* s_min);//��ѡ���·��

#endif 