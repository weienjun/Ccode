#include<stdio.h>
#include<stdlib.h>
struct //����ṹ�壬�޽ṹ������������һ��������
  {
		int num;
		char name[15];
		char tp;//�ַ����ͣ�����ѡ��ṹ���е����ͣ�s/t��
		union//���干����
		{
			int n;//��ʾ�༶
			char position[10];//��ʾְ��
		}job;//�����������
   }st[10];//�ṹ�������
int main()

{
	int i;
	
	for(i=0;i<3;i++)
	{
		printf("�������,���֣�����:\n");
		scanf("%d%s",&st[i].num,&st[i].name);
		getchar();
		scanf("%c",&st[i].tp);
		if(st[i].tp=='s')
		{
			printf("����༶:");
			scanf("%d",&st[i].job.n);
		}
		else
		{
			printf("����ְ��");
			scanf("%s",&st[i].job.position);
		}
	 }
	getchar();
	printf("���   ����   ����  �༶/ְ��\n");
	for(i=0;i<3;i++)
		if(st[i].tp=='s')
			printf("%d\t%s\t%c\t%d\n",st[i].num,st[i].name,st[i].tp,st[i].job.n);
		else
			printf("%d\t%s\t%c\t%s\n",st[i].num,st[i].name,st[i].tp,st[i].job.position);
	system("pause");
	return 0;
}