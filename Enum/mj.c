#include<stdio.h>
#include<stdlib.h>
//����ö�ٽṹ��������Ա��ֵ���ӵ�һ����Ա���ÿ����Աֵ��һ����Blue=2...
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
				printf("�������\n");
		}
		 }
	
	system("pause");
	return 0;
}