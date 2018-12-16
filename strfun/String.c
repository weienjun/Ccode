#include<stdio.h>
#include<assert.h>

char *my_strcpy(char*arr,const char*arr1)//�ַ�������
{
	char *str=arr;//���ص�ַ��������ʽ��Ӧ
	assert(arr);
	assert(arr1);
	while(*arr++ = *arr1++);//��'\0'ҲҪ����
	return str;
}

char *my_strcat(char*arr,const char*arr1)//�ַ���ƴ��
{
	char *str=arr;
	assert(arr);
	assert(arr1);

	while(*arr++);
	arr--;//������һ��ѭ��ʱ����ָ��'\0'����һ����ַ
	while(*arr++ = *arr1++);//���ǵ�ԭ��'\0'����arr1ȫ����arr��
	return str;
}

char *my_strstr( char*arr,const char*arr1)//�Ӵ�����
{
	assert(arr);
	assert(arr1);

	if(*arr1=='\0')//arr1ֻ��һ��'\0'��'\0'���Ƚ�
	return NULL;

	while(*arr)
	{
		//q�ӵ�һ���ַ���ʼ�Ƚϣ�������ͬ��'\0'���ҵ�������q���¿�ʼ��p�ӵ�ǰλ�ü����Ƚ�
		const char *p=arr;//���浱ǰarr��λ��
		const char *q=arr1;//arr1�ӵ�һ���ַ���ʼ
		while(*q)
		{
			if(*p&&*p==*q)//�ж��Ƿ���ͬ���Ҳ�Ϊ'\0'
			{
				q++;
				p++;
			}
			else//��ͬ�˳�q���¿�ʼ,�����
				break;
		}
	    if(*q=='\0')//�ҵ�����
		{
           return arr;
		}
		else//δ������arr�����¸��ַ��Ƚϣ�arr1���¿�ʼ
		arr++;
	}//������arr��'\0'��δ�ҵ�
	return NULL;
}

int   my_strcmp(const char*arr,const char*arr1)//�ַ����Ƚ�
{
	assert(arr);
	assert(arr);

	while(*arr&&arr1)//����Ϊ'\0'
	{
		if(*arr>*arr1)
			return 1;
		else if(*arr<*arr1)
		{
			return -1;
		}
		arr++;arr1++;
	}

	if(*arr==0 && *arr1==0)//���ȽϽ��������
		return 0;
	if(*arr)//arr�����
    	return 1;
	else //����С
	    return -1;
}

const char* my_strchr(const char*arr, const char arr1)//�ַ�����
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

char *my_memcpy(void *arr,void *arr1,int count)//�ַ������ƣ��ڴ渴��
{
	void* str = arr;//������ʼ��ַ
	assert(arr);
	assert(arr1);

	while(count--)
	{
		*(char*)arr = *(char*)arr1;
		arr=(char*)arr+1;
		arr1=(char*)arr1+1;
	}//����ʱָ�����ַ�������һ���ַ�
	return (char*)str;//������ƺ�Ľ��
}


char *my_memmove(void *arr,void *arr1,int count)//�ַ������ƣ��ڴ渴��,�����ڴ��ص�
{
	void *str=arr;
	assert(arr);
	assert(arr1);

	if(arr<=arr1||(char*)arr>=((char*)arr1+count))//arr��arr1֮ǰ��arr��arr1+count֮��,ֱ�Ӹ���
	{
		while(count--)
		{
		*(char*)arr=*(char*)arr1;
		arr=(char*)arr+1;
		arr1=(char*)arr1+1;
		}
	}
	else//����ǰ���ƣ����ڴ��ص�
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
