//1.实现strcpy 
//2.实现strcat 
//3.实现strstr 
//4.实现strchr 
//5.实现strcmp 
//6.实现memcpy 
//7.实现memmove 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"String.h"

int main()
{
	char arr[20]="abc123";
	char arr1[]="456def";

	printf("%d \n",strncmp(arr,"acd",2));

	//my_strcpy(arr,arr1);
	printf("%s \n",arr);

	my_strcat(arr,arr1);
	printf("%s \n",arr);

	printf("%s \n",my_strstr(arr,"56"));

	printf("%d \n",my_strcmp(arr,arr1));

	printf("%s\n",arr);
	printf("%p \n",my_strchr(arr,'2'));

	printf("%s\n",arr);
	printf("%s\n", my_memcpy(arr, "987", 4));
	printf("%s \n",my_memmove(arr,"456",3));

	printf("\n%s \n",arr);
	printf("%s \n",my_strncpy(arr,"456",2));

	printf("\n%s \n",arr);
	printf("%s \n",my_strncat(arr,"def",3));

	printf("\n%s \n",arr);
	printf("%d \n",my_strncmp(arr,"435",3));
	printf("\n%d \n",strncmp(arr,"435",3));

	

	system("pause");
	return 0;
}

//int main()
//{
// char arr[]={"abc123"};
// char ch[]={"456"};
// int sz=sizeof(ch)/sizeof(ch[0]);
// printf("%s\n",arr);
// my_strncpy(arr,ch,sz);
// printf("%s \n",arr);
// printf("%d\n",strncmp(arr,"435",2));
// printf("%d \n",my_strncmp(arr,"435",2));
// my_strncat(arr,"789",3);
// printf("%s \n",arr);
// system("pause");
// return 0;
//}
