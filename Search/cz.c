#include<stdio.h>
#include<stdlib.h>
struct index
{
	int key;
	int start;
	int end;
}index[4];//结构体变量长度为4
int search(int key,int a[])
{
	int i=0,j;
	while(i<3&&key>index[i].key)//判定是否在所分的块中
		i++;
	if(i>=3)//不在块中
		return -1;//返回-1退出
	j=index[i].start;//j存放起始值第一块0，第二块5，第三块10
	while(j<=index[i].end&&a[j]!=key)//在块内查找，直到a[j]=key;
		j++;//j的值加1
	if(j>index[i].end)//j大于块中的块值，则此块未找到
		j=-1;
	return j;
}

int main()
{
	int i,k,key,j=-1;
	int a[]={42,45,49,50,58,60,65,68,70,79,80,88,90,91,99};
	printf("已知数据\n");
	for(i=0;i<15;i++)
	printf("%3d",a[i]);
	printf("\n");
	for(i=0;i<3;i++)
	{
		index[i].start=j+1;//第一块0-5个数，块0，第二块5-10个数，块5。第三块11-15个数，块10
		j=j+1;
		index[i].end=j+4;
		j=j+4;
		index[i].key=a[j];//存放每块第一个值的数据
	}
	while(1)
	{
	printf("输入查找的数据：");
	scanf("%d",&key);
	k=search(key,a);
	if(k>=0)
		printf("成功，位置为%d:\n",k+1);
	else
		printf("失败，不在数据中\n");
	}
  system("pause");
  return 0;
}
