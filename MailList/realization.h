#ifdef __REALIZATION_H__

#define __REALIZATION_H__

#endif 

#define N 10

typedef struct	People{//�ṹ���еĳ�Ա�����ڶ���ʱ��ʼ��
	char name[N];
	char gender;
	char number[12];
	char address[20];
	int age;
	struct People *Next;
}people,*Head;

int Menu(people *  head);//�˵�
people * creat(people * head);//��ʼ�������
void print(const people * head);//���
people* search(const people * head ,const char *ch);//����
people* dete(people * temp);//ɾ��
people* sorting(people * head);//����
people* modify(people * temp);//�޸�
people* empty(people * head);//���
void pfile(people * head);//д���ļ���
void exchange(people * pend,people * pnext);//����������������