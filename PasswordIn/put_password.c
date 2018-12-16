#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10

int main()
{   
	int i=0;
	char arr[N];
	while(i<3)
	{
		printf("ÊäÈëÃÜÂë£º");
		scanf("%s",&arr);
		if(strcmp(arr,"123456")==0)
			printf("µÇÂ½³É¹¦£¡\n");
		else
			printf("ÃÜÂë´íÎó!\n");
		i++;
		
	}
	system("pause");
	return 0;
}