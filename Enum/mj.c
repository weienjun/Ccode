#include<stdio.h>
#include<stdlib.h>
//定义枚举结构，并给成员赋值，从第一个成员向后每个成员值加一。即Blue=2...
enum Color{Red=1,Green,Blue}color;
int main()
{
	int  num;
	while(1)
	{
	scanf("%d",&num);
		switch(num)
		{
			case Red:
				printf("Red\n");break;
			case Green:
				printf("Green\n");break;
			case Blue:
				printf("Blue\n");break;
           default:
				printf("输入错误\n");
		}
		 }
	
	system("pause");
	return 0;
}