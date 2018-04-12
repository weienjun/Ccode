#include<stdio.h>
#include<stdlib.h>
int binary_search(const int arr[],const int data,int left,int right);//�ݹ���ֲ���
int choose_search(int arr[],const int sz);//ѡ������
int choose_search1(int arr[],int sz);//�Ż�ѡ������
static void change(int *arr,int *anum);
void print(const int arr[],const int sz);//���
int main()
{

	int arr[]={2,1,3,5,9,8,6,7,0,12,65,98,32,11,22,33,41,11};
	int sz=sizeof(arr)/sizeof(arr[0]);
	int data=0;
	int num=0;

	print(arr,sz);
	choose_search1(arr,sz);
	print(arr,sz);

	print(arr,sz);
	choose_search(arr,sz);
	print(arr,sz);

	printf("put data:");
	scanf("%d",&data);
	
	num=binary_search(arr,data,0,sz);
	printf("�±�Ϊ��%d\n",num);
	choose_search(arr,sz);
	system("pause");
	return 0;
}

int binary_search(const int arr[],const int data,int left,int right)
{
	int mid=left+((right-left)>>1);
	if(left >= right)//δ�ҵ�,���ڴ���ʱszδ��һ������ȡ�Ⱥ�
	{
		return -1;
	}
	else if(arr[mid]<data)//�Ҳ�
	{
		binary_search(arr,data,mid+1,right);
	}
	else if(arr[mid]>data)//���
	{
		binary_search(arr,data,left,mid-1);
	}
	else//�ҵ�
		return mid;
}

int choose_search(int arr[],const int sz)//ѡ������
{
	int i=0,j=0;
	int temp=0;
	int test;
	for(i=0;i<sz-1;i++)//һ�������ñȽ�
	{
		temp=0;//ÿ�ּ����һ�������
		for(j=0;j<sz-i;j++)//ÿ��arr[j]����temp�Ƚϣ����Բ���һ
		{
			if(arr[j]>arr[temp])
				temp=j;//����±�
		}
		//��������������������򽻻���ӦΪ������λ��ʱ����
		test=arr[sz-i-1];
		arr[sz-i-1]=arr[temp];
		arr[temp]=test;
	}
}

void print(const int arr[],const int sz)//���
{
	int i=0;
	for(i=0;i<sz;i++)
	printf("%d  ",arr[i]);
	printf("\n");
}


int choose_search1(int arr[],int sz)//�Ż�ѡ������
{
	int max_num=sz-1;
	int min_num=0;
	int i=0;
	int j=0;
	//һ��ͬʱ�ҳ��������С����
	while(min_num<max_num)
	{
		for(i=j+1;i<sz-j;i++)
		{
			if(arr[i]>arr[max_num])//�ҳ������
				max_num=i;
			if(arr[i]<arr[min_num])//�ҳ���С��
				min_num=i;
		}

		if(j != min_num)//��С��������С��λ�ã��轻��
		change(&arr[j],&arr[min_num]);
		if(max_num==j)//���������С����λ�ã���������ʱ����������ƶ���min_numλ��
		{
			max_num=min_num;//��max_num�ƶ����µ�λ��
		}
		if(max_num != sz-1-j)//������������λ�ã�����
		change(&arr[sz-j-1],&arr[max_num]);
		j++;//���´ο�ʼ����
		max_num=sz-j-1;//max_numǰ��
		min_num=j;//min_num����
	}
}

static void change(int *arr,int *anum)
{
	int temp=0;
	temp=*arr;
	*arr=*anum;
	*anum=temp;
}

