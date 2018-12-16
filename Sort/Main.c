/*
#include<stdio.h>
#include<stdlib.h>
#include"Test.h"

int main()
{

	int arr[]={2,1,3,5,9,8,6,7,0,12,65,98,32,11,22,33,41,11};
	int sz=sizeof(arr)/sizeof(arr[0]);
	int data=0;
	int num=0;

	print(arr,sz);
	selection_sort(arr,sz);
	print(arr,sz);

	print(arr,sz);
	bubble_sort(arr,sz);
	print(arr,sz);

	print(arr,sz);
	choose_search1(arr,sz);
	print(arr,sz);

	print(arr,sz);
	choose_search(arr,sz);
	print(arr,sz);

	printf("%d \n",sz);
	printf("put data:");
	scanf("%d",&data);
	
	num=binary_search(arr,data,0,sz);
	printf("ÏÂ±êÎª£º%d\n",num);
	choose_search(arr,sz);
	system("pause");
	return 0;
}

*/

#include<stdio.h>
#include<stdlib.h>

char * G(char **p)
{
	*p="123";
	return *p;
}
int main()
{
	char * str =NULL;
	//str=(char*)malloc(20);
	if(NULL != G(&str))
	{
		printf("\r\n str= %s",str);
	}

	system("pause");
	return 0;
}