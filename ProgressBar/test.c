#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
//������
int main()
{
   int i = 0;
   char bar[102];
   const char* lable = "|/-\\";//��תͼ��
   bar[0] = 0;
   printf("�������У�\n");
   while(i <= 50)
   {
       printf("[%-50s][%d%%][%c]\r",bar,i*2,lable[i%4]);//����룬Ԥ��50���ַ�
       fflush(stdout);//ˢ������������ڰ�����ˢ�£��˴��޻��У��������
       bar[i] = '#';
       i++;
       bar[i] = 0;
       Sleep(100);//0.1s
   }
   printf("\n���н�����\n");
   system("pause");
   return 0;
}
