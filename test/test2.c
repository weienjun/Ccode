#include<stdio.h>
#include"test2.h"
//c不支持重载，所以同一个项目中不可出现相同的函数名
//同一个文件中绝对不可出现，不同文件中相同的函数名都要加上static用于指定只能在本文件中使用，从而可以相同
static void Fun()
{
	printf("test2\n");
}

void test2()
{
	Fun();
}