#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 200//�ַ������ȴ�С
int main()
{
	int i=0;
	int a=0;
	int b=0;
	char arr[N];
	printf("�����ַ���");
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
        printf("�ɶԳ���\n");
	else
	    printf("���ɶԳ���\n");

	system("pause");
	return 0;
}