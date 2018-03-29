#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 200//字符串长度大小
int main()
{
	int i=0;
	int a=0;
	int b=0;
	char arr[N];
	printf("输入字符：");
	scanf("%s",arr);
	for(i=0;i<N;i++)
	{
		if(arr[i]=='{' )
		{
			a++;
		}
		if(arr[i]=='}')
		{
			b++;
		}	
	}

	if(a==b)
        printf("成对出现\n");
	else
	    printf("不成对出现\n");

	system("pause");
	return 0;
}