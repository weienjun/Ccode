#include<stdio.h>
#include<stdlib.h>
#include"snake.h"
int main()
{

	//mode 改变屏幕大小
	system("mode con cols=100 lines=30");
	menu();//菜单

	printf("\n");
	system("pause");
	return 0;
}

//□,是一个汉字，占两字节（行占两字符（x每次+2），列占一列（y每次+1））