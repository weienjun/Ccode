#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
//进度条
int main()
{
   int i = 0;
   char bar[102];
   const char* lable = "|/-\\";//旋转图标
   bar[0] = 0;
   printf("正在运行：\n");
   while(i <= 50)
   {
       printf("[%-50s][%d%%][%c]\r",bar,i*2,lable[i%4]);//左对齐，预留50个字符
       fflush(stdout);//刷新输出流，由于按换行刷新，此处无换行，所以添加
       bar[i] = '#';
       i++;
       bar[i] = 0;
       Sleep(100);//0.1s
   }
   printf("\n运行结束：\n");
   system("pause");
   return 0;
}
