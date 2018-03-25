#include<stdio.h>
#include<stdlib.h>
struct //定义结构体，无结构体名，包含有一个共用体
  {
		int num;
		char name[15];
		char tp;//字符类型，用于选择结构体中的类型（s/t）
		union//定义共用体
		{
			int n;//表示班级
			char position[10];//表示职务
		}job;//共用体变量名
   }st[10];//结构体变量名
int main()

{
	int i;
	
	for(i=0;i<3;i++)
	{
		printf("输入序号,名字，类型:\n");
		scanf("%d%s",&st[i].num,&st[i].name);
		getchar();
		scanf("%c",&st[i].tp);
		if(st[i].tp=='s')
		{
			printf("输入班级:");
			scanf("%d",&st[i].job.n);
		}
		else
		{
			printf("输入职务：");
			scanf("%s",&st[i].job.position);
		}
	 }
	getchar();
	printf("序号   姓名   类型  班级/职务\n");
	for(i=0;i<3;i++)
		if(st[i].tp=='s')
			printf("%d\t%s\t%c\t%d\n",st[i].num,st[i].name,st[i].tp,st[i].job.n);
		else
			printf("%d\t%s\t%c\t%s\n",st[i].num,st[i].name,st[i].tp,st[i].job.position);
	system("pause");
	return 0;
}