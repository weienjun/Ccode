#ifdef __STRING_H__

#define __STRING_H__

#endif

char *my_strcpy(char*arr,const char*arr1);//�ַ�������
char *my_strcat(char*arr,const char*arr1);//�ַ���ƴ��
char *my_strstr(const char*arr,const char*arr1);//�Ӵ����ң��з��ز��ҵ��ִ�������
const char *my_strchr(const char*arr,const char arr1);//�ַ����ң��з��ش��ַ���ַ���޷���NULL
int   my_strcmp(const char*arr,const char*arr1);//�ַ����Ƚ�
char *my_memcpy(void *arr,void *arr1,int count);//�ַ������ƣ��ڴ渴��
char *my_memmove(void *arr,void *arr1,int count);//�ַ������ƣ��ڴ渴��,�����ڴ��ص�
char *my_strncpy(char *arr,const char *ch,int sz);//�ַ������ƣ�����sz���ַ�
char *my_strncat(char *arr,char *arr1,int sz);//�ַ������ӣ�����sz���ַ�
int   my_strncmp(const char *arr,const char *arr1,int sz);//�ַ����ȴ�С����ͬ����0������ͬ���ص�һ������ͬ�ַ��Ĳ�ֵ