#ifndef __GAME_H__
#define __GAME_H_
#define Column 3
#define Line 3

#endif //__GAME_H__

void Game();//��Ϸ����
void Board(const int column,const int line,char arr[][Line]);//��ӡ����
int  C_Piece(const int column,const int line,char arr[][Line]);//��������λ��
int U_piece(const int column,const int line,char arr[][Line]);//�û�����λ��
int P_Judge(const int column,const int line,char arr[][Line]);//��������
int U_Judge(const int column,const int line,char arr[][Line]);//�û�����
int tnum(const int n);//���ֵ