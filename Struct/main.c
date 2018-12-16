
#include<stdlib.h>
#include<stdio.h>
#include"main.h"

Hero heros;
void put()
{
	heros = (Hero)malloc(sizeof(HeroNode));
	scanf("%d", &heros->id);
	//heros[i].name=(char*)malloc(50);//动态分配
	scanf("%s",heros->name);
	getchar();
	scanf("%c",&(heros->cex));
	//jobs[i].name=(char*)malloc(20);
	//jobs[i].desc=(char*)malloc(30);
	heros->job = (Job)malloc(sizeof(JobNode));
	scanf("%s",heros->job->name);
	scanf("%s",heros->job->desc);

}
void out()
{
	printf("***************\n");
	printf("%d\n%s\n%c\n%s\n%s\n",heros->id,heros->name,heros->cex,heros->job->name, heros->job->desc);//输出为字符串类型报错？？？
	
}
int main()
{
	put();
	out();
	system("pause");
	return 0;
}