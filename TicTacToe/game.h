#ifndef __GAME_H__
#define __GAME_H_
#define Column 3
#define Line 3

#endif //__GAME_H__

void Game();//游戏函数
void Board(const int column,const int line,char arr[][Line]);//打印棋盘
int  C_Piece(const int column,const int line,char arr[][Line]);//电脑落子位置
int U_piece(const int column,const int line,char arr[][Line]);//用户落子位置
int P_Judge(const int column,const int line,char arr[][Line]);//电脑评测
int U_Judge(const int column,const int line,char arr[][Line]);//用户评测
int tnum(const int n);//随机值