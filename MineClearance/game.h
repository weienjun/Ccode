#ifndef __GAME_H__
#define __GAME___

#endif __GAME_H__
#define Column 10
#define Line 10

void Game(const int count);//游戏
void Board(const int column,const int line,char arr2[][Line+2]);//打印棋盘
int Position(const int count,const int column,const int line,char arr1[][Line+2]);//设雷
int Choose(const int count,const int column,const int line,char arr1[][Line+2],char arr2[][Line+2]);//位置选择
static void print(const int column,const int line,char arr1[][Line+2],char arr2[][Line+2]);//输出管理
void Board1(const int column,const int line,char arr1[][Line+2]);//打印雷区
static int num(const int count,const int column,const int line,char arr2[][Line+2]);//判断是否赢了