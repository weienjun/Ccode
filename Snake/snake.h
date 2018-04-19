#ifndef __STAKE_H__

#define __STAKE_H__

#define FOOD "��"
#define INIT_X  4 //��ʼx,y(2�ı���)
#define INIT_Y 5
//#define MAX_X 56 //ż��
//#define MAX_Y 25

typedef struct Frame
{
	size_t MAX_X;
	size_t MAX_Y;
}frame;

typedef struct Node_ //���й�λ��
{
	int x;
	int y;
	struct Node_ * Next;
}Snake_Node,*pSnake_Node;//��������

enum Dir//����
{
   up,
   down,
   left,
   right,
};

enum Status//��״̬
{
	OK,//����
	PUT_DES,//ײ��
	MY_DES,//ҧ��
	OVER,//�˳�
};

typedef struct Snake //״̬��Ϣ
{

	pSnake_Node _pSnake;//ָ����
	pSnake_Node _pFood;//��ʳ��
	enum Status _status;//״̬
	enum Dir _Dir;//���߷���
	int SleepTime;//ʱ��
	size_t count;//��ȡʳ����
}Snake,*pSnake;

void SetPos(int x,int y);
void menu(void);//�˵�
void CreateMap(frame fra);//�����߽�
void Snake_Init(pSnake_Node * snake);//�߳�ʼ��
void Push_front(pSnake_Node * phead,const int x,const int y);//ͷ��
pSnake_Node Snake_run(pSnake pSnake,pSnake_Node newhead);//�˶�ͷ��
void Init_all(pSnake  Snake,frame fra,const int speed);//��ʼ��������Ϣ
void Init_food(pSnake  snake,frame fra);//��ʼ��ʳ��
void Snake_move(pSnake snake,frame fra);//�ƶ�
void Snake_eat(pSnake snake,pSnake_Node newhead,frame fra);//��ʳ�ﴦ��,���˶�
void Snake_zt(pSnake snake,pSnake_Node newhead,frame fra);//�ߵ�״̬
void Snake_fx(pSnake snake);//����
void xx(pSnake snake,frame fra);//��ӡ��Ϣ 

#endif