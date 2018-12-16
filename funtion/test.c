/*
#include<stdio.h>
#include<stdlib.h>

void test(char arr[][3])
{
	arr[0][1]='*';
}
int main()
{
	char arr[2][3]={'1','2','3'};
	printf("%c\n",arr[0][1]);
	test(arr);
	printf("%c\n",arr[0][1]);
	system("pause");
	return 0;
}

*/

#include<stdio.h>
#include<stdlib.h>
int Add(int x,int y)
{
	int z=0;
	z=x+y;
	return z;
}
int main()
{
	int a=2;
	int b=1;
	printf("%d \n",Add(a,b));
	system ("pause");
	return 0;
}