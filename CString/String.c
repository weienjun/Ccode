#include<stdio.h>
#include<assert.h>

char *my_strcpy(char*arr,const char*arr1)//字符串复制
{
	char *str=arr;//返回地址，便于链式反应
	assert(arr);
	assert(arr1);
	while(*arr++ = *arr1++);//将'\0'也要复制
	return str;
}

char *my_strcat(char*arr,const char*arr1)//字符串拼接
{
	char *str=arr;
	assert(arr);
	assert(arr1);

	while(*arr++);
	arr--;//跳出上一个循环时，已指向'\0'的下一个地址
	while(*arr++ = *arr1++);//覆盖掉原有'\0'，将arr1全接在arr后
	return str;
}

char *my_strstr( char*arr,const char*arr1)//子串查找
{
	assert(arr);
	assert(arr1);

	if(*arr1=='\0')//arr1只有一个'\0'，'\0'不比较
	return NULL;

	while(*arr)
	{
		//q从第一个字符开始比较，连续相同至'\0'则找到，否则q重新开始，p从当前位置继续比较
		const char *p=arr;//保存当前arr的位置
		const char *q=arr1;//arr1从第一个字符开始
		while(*q)
		{
			if(*p&&*p==*q)//判断是否相同，且不为'\0'
			{
				q++;
				p++;
			}
			else//不同退出q重新开始,或结束
				break;
		}
	    if(*q=='\0')//找到结束
		{
           return arr;
		}
		else//未结束，arr进行下个字符比较，arr1重新开始
		arr++;
	}//遍历至arr的'\0'则未找到
	return NULL;
}

int   my_strcmp(const char*arr,const char*arr1)//字符串比较
{
	assert(arr);
	assert(arr);

	while(*arr&&arr1)//都不为'\0'
	{
		if(*arr>*arr1)
			return 1;
		else if(*arr<*arr1)
		{
			return -1;
		}
		arr++;arr1++;
	}

	if(*arr==0 && *arr1==0)//都比较结束，相等
		return 0;
	if(*arr)//arr长则大
    	return 1;
	else //否则小
	    return -1;
}

const char* my_strchr(const char*arr, const char arr1)//字符查找
{
	assert(arr);
	assert(arr1);
	while(*arr){
		if(*arr == arr1)
			return arr;
		arr++;
	}
	return NULL;
}

char *my_memcpy(void *arr,void *arr1,int count)//字符串复制，内存复制
{
	void* str = arr;//保留起始地址
	assert(arr);
	assert(arr1);

	while(count--)
	{
		*(char*)arr = *(char*)arr1;
		arr=(char*)arr+1;
		arr1=(char*)arr1+1;
	}//跳出时指向复制字符串的下一个字符
	return (char*)str;//输出复制后的结果
}


char *my_memmove(void *arr,void *arr1,int count)//字符串复制，内存复制,避免内存重叠
{
	void *str=arr;
	assert(arr);
	assert(arr1);

	if(arr<=arr1||(char*)arr>=((char*)arr1+count))//arr在arr1之前或arr在arr1+count之后,直接复制
	{
		while(count--)
		{
		*(char*)arr=*(char*)arr1;
		arr=(char*)arr+1;
		arr1=(char*)arr1+1;
		}
	}
	else//后往前复制，有内存重叠
	{
		arr=(char*)+count;
	    arr1=(char*)+count;
		while(count--)
		{
         *(char*)arr=*(char*)arr1;
		 arr=(char*)arr-1;
		 arr1=(char*)arr1-1;
		}
	}
	   return (char*)str;
}

char *my_strncpy(char *arr,const char *ch,int sz){
 char * str=arr;
 assert(arr);
 assert(ch);

 while(sz--){
 *arr++=*ch++;
}
 return str;
}

char *my_strncat(char *arr,char *arr1,int sz){
 char * str=arr;
 assert(arr);
 assert(arr1);
 assert(sz>0);

 while(*arr)
	arr++;

 while(sz--){
 *arr++=*arr1++;
 }
 *arr='\0';
 return str;
}

//int   my_strncmp(const char *arr,const char *arr1,int sz){
// int size=0;
// assert(arr);
// assert(arr1);
// assert(sz>0);
// while(sz--&&*arr){
// if(*arr>*arr1){
//  return 1;
// }
// else if(*arr<*arr1){
//  return -1;
// }
// else{
//  arr++;arr1++;
// }
//}
// if(*arr)
// return 0;
// else
// return -1;
//}
//
int   my_strncmp(const char *arr,const char *arr1,int sz){
	while(sz--)
	{
	  if(*arr!=*arr1)
		return *arr-*arr1;
	  else
		arr++;arr1++;
	}
	return 0;
	//if(*arr)
	//	return 0;
	//else

}
