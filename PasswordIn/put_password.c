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
		printf("�������룺");
		scanf("%s",&arr);
		if(strcmp(arr,"123456")==0)
			printf("��½�ɹ���\n");
		else
			printf("�������!\n");
		i++;
		
	}
	system("pause");
	return 0;
}