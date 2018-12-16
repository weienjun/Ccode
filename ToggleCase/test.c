#include<stdio.h>
#include<stdlib.h>

void Conversion(char ch[]);
int main()
{
	char ch[10];

	while(1)
	{
	printf("输入字符串:");
	scanf("%s",ch);
	Conversion(ch);
	}

	system("pause");
	return 0;
}

void Conversion(char ch[])
{
	int i=0;
	
	printf("转换后：");
	while(ch[i]!='\0')//不为字符串结尾
	{
		if(ch[i]>=97&&ch[i]<=122)
		{
	    ch[i]-=32;//每个字符进行转换
		printf("%c",ch[i]);
		}

	    else if(ch[i]>=65&&ch[i]<=90)
		{
		ch[i]+=32;
		printf("%c",ch[i]);
		}

		else if(ch[i]>=48&&ch[i]<=57)//忽略数字
		{
			i++;
			continue;
		}

		else//其他字符不变输出
		printf("%c",ch[i]);
	
	i++;
	}
	printf("\n");//换行进行下个字符串转换
}