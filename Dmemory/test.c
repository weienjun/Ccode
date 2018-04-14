//
//1.将通讯录改成动态的版本。 
//2.练习动态内存开辟 
//malloc 
//calloc 
//realloc 
//free 
//函数 
//3.看《高质量C/C++编程》上的题目。 

#include<stdio.h>
#include<stdlib.h>

int main()
{
	char ch[80];
	int num=0;
	int n=0;
	scanf("%79s",ch);
	scanf("%98d%79d",&num,&n);
	printf("%79d\n",num);
	system("pause");
	return 0;
}