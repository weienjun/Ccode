#include<stdio.h>
#include<stdlib.h>
struct index
{
	int key;
	int start;
	int end;
}index[4];//�ṹ���������Ϊ4
int search(int key,int a[])
{
	int i=0,j;
	while(i<3&&key>index[i].key)//�ж��Ƿ������ֵĿ���
		i++;
	if(i>=3)//���ڿ���
		return -1;//����-1�˳�
	j=index[i].start;//j�����ʼֵ��һ��0���ڶ���5��������10
	while(j<=index[i].end&&a[j]!=key)//�ڿ��ڲ��ң�ֱ��a[j]=key;
		j++;//j��ֵ��1
	if(j>index[i].end)//j���ڿ��еĿ�ֵ����˿�δ�ҵ�
		j=-1;
	return j;
}

int main()
{
	int i,k,key,j=-1;
	int a[]={42,45,49,50,58,60,65,68,70,79,80,88,90,91,99};
	printf("��֪����\n");
	for(i=0;i<15;i++)
	printf("%3d",a[i]);
	printf("\n");
	for(i=0;i<3;i++)
	{
		index[i].start=j+1;//��һ��0-5��������0���ڶ���5-10��������5��������11-15��������10
		j=j+1;
		index[i].end=j+4;
		j=j+4;
		index[i].key=a[j];//���ÿ���һ��ֵ������
	}
	while(1)
	{
	printf("������ҵ����ݣ�");
	scanf("%d",&key);
	k=search(key,a);
	if(k>=0)
		printf("�ɹ���λ��Ϊ%d:\n",k+1);
	else
		printf("ʧ�ܣ�����������\n");
	}
  system("pause");
  return 0;
}
