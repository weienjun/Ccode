#ifndef __GAME_H__
#define __GAME___

#endif __GAME_H__
#define Column 10
#define Line 10

void Game(const int count);//��Ϸ
void Board(const int column,const int line,char arr2[][Line+2]);//��ӡ����
int Position(const int count,const int column,const int line,char arr1[][Line+2]);//����
int Choose(const int count,const int column,const int line,char arr1[][Line+2],char arr2[][Line+2]);//λ��ѡ��
static void print(const int column,const int line,char arr1[][Line+2],char arr2[][Line+2]);//�������
void Board1(const int column,const int line,char arr1[][Line+2]);//��ӡ����
static int num(const int count,const int column,const int line,char arr2[][Line+2]);//�ж��Ƿ�Ӯ��