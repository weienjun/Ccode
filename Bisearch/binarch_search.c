/*
#include<stdio.h>
#include<stdlib.h>

int search(int arr[],int n,int snum);
int main()
{
	int num=0;
	int snum=0;
	int arr[]={1,2,3,4,5};
	int n=sizeof(arr)/sizeof(arr[0]);//���������С

	printf("����Ҫ���ҵ�����");
	scanf("%d",&snum);
	num=search(arr,n,snum);
	printf("���%d\n",num);

	system("pause");
	return 0;

}

int search(int arr[],int n,int snum)
{

	int i=0;
	int start=0;
	int mid=0;
	while(start<=n)
	{
		mid=(start+n)/2;

		if (snum>arr[mid])//�ں�벿�ֲ���
			start=mid+1;

		else if(snum<arr[mid])//��ǰ�벿�ֲ���
			n=mid-1;

		else 
			return mid;//�ҵ����ش��±�
	}

	return -1;//δ�ҵ�����-1
}


*/

#include<stdio.h>
#include<stdlib.h>
//�۰����
int search(int arr[],int num,int sz);//�ҵ������±꣬δ�ҵ�����-1
int main()
{
	int arr[]={1,2,4,5,6,7,8,9};
	int sz=0;//ͳ�������С
	int i=0;//��¼����ֵ
	int num=0;//Ҫ���ҵ���

	printf("����Ҫ���ҵ�����");
	scanf("%d",&num);

	//������鲻��������ʵ�ֺ������������С��
	sz=sizeof(arr)/sizeof(arr[0]);//���������С��������Ϊ����ʱ�������������׵�ַ��sizeof(arr)�������׸�Ԫ�ش�С�����������ܴ�С��
	i=search(arr,num,sz);//�ҵ������±꣬δ�ҵ�����-1

	if(-1==i)
		printf("δ�ҵ���\n");
	else
		printf("�±�Ϊ%d\n",i);

	system("pause");
	return 0;
}

int search(int arr[],int num,int sz)
{
	int light=0;//��ֵ�±꣬�±��0��ʼ
	int right=sz-1;//��ֵ�±�Ϊ�����С-1��
	int mid=0;//�м�ֵ�±�

	while(light<=right)//���ҵ��ǴΡ�ÿѭ��һ�Σ�������±���м��±귢��һ�α仯�����±�ӣ����±����
	{
		//�ҳ��м�ֵ�±�
		//mid=(light+right)/2;//��ƽ��ֵ���÷������ܴ�����ֵ�ʹ��������ֵ��Χ����
		//mid=(light&right)+((light^right)>>1)//��ƽ��ֵ���÷���������⣬a>>1�൱��a/2
		mid=light+((right-light)>>1);//��ƽ��ֵ

		if(num<arr[mid])//��С���м�ֵ
			right=mid-1;//���±��Ϊ�м�ֵ�±��ǰһ��
		else if(num>arr[mid])//�������м�ֵ
			light=mid+1;//���±��Ϊ�м�ֵ�±�ĺ�һ��
		else//��ֵ�����м�ֵ
			return mid;//�����±�

	}
	return -1;//δ�ҵ�
}
