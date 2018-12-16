#ifdef __STRING_H__

#define __STRING_H__

#endif

char *my_strcpy(char*arr,const char*arr1);//字符串复制
char *my_strcat(char*arr,const char*arr1);//字符串拼接
char *my_strstr(const char*arr,const char*arr1);//子串查找，有返回查找的字串到结束
const char *my_strchr(const char*arr,const char arr1);//字符查找，有返回此字符地址，无返回NULL
int   my_strcmp(const char*arr,const char*arr1);//字符串比较
char *my_memcpy(void *arr,void *arr1,int count);//字符串复制，内存复制
char *my_memmove(void *arr,void *arr1,int count);//字符串复制，内存复制,避免内存重叠
char *my_strncpy(char *arr,const char *ch,int sz);//字符串复制，复制sz个字符
char *my_strncat(char *arr,char *arr1,int sz);//字符串链接，链接sz个字符
int   my_strncmp(const char *arr,const char *arr1,int sz);//字符串比大小，相同返回0，不相同返回第一个不相同字符的差值