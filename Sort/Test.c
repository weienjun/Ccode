#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"Test.h"

int binary_search(const int arr[],const int data,int left,int right)
{
	int mid=left+((right-left)>>1);
	assert(arr);//���ԣ�arr��Ϊ��
	 if(arr[mid]==data)
		return mid;
	else if(left >= right)//δ�ҵ�,����right���ֵΪsz����ֵ������������ȥ�Ⱥţ���ֹԽ��
	{
		return -1;
	}
	else if(arr[mid]<data)//�Ҳ�
	{
		binary_search(arr,data,mid+1,right);
	}
	else //���
	{  
		binary_search(arr,data,left,mid-1);
	}
}

//ÿ���ּ����һ������󣬱�����ǰ������Ԫ�أ���ǳ�ʵ�������λ��
//�ҳ�������󣬽���ǰ��λ�õ�������������뵱ǰ�����һ��λ����������С��>��
//ѭ����1��������һ�ֽ����������һ��λ��ǰ�ƣ�
//�Ƚ�N-1�֣�ÿ�ֱȽ�N-i��
int choose_search(int arr[],const int sz)//ѡ������
{
	int i=0,j=0;
	int temp=0;
	int test;
	assert(arr);//���ԣ�arr��Ϊ��
	for(i=0;i<sz-1;i++)//һ�������ñȽ�
	{
		temp=0;//ÿ�ּ����һ�������
		for(j=0;j<sz-i;j++)//ÿ��arr[j]����temp�Ƚϣ����Բ���һ
		{
			if(arr[j]>arr[temp])
				temp=j;//����±�
		}
		if(sz-i-1 != temp)//���ڵ�ǰ�����λ��
			change(&arr[sz-i-1],&arr[temp]);
	}
}

void print(const int arr[],const int sz)//���
{
	int i=0;
	assert(arr);//���ԣ�arr��Ϊ��
	for(i=0;i<sz;i++)
	printf("%d  ",arr[i]);
	printf("\n");
}


int choose_search1(int arr[],const int sz)//�Ż�ѡ������
{
	int max_num=sz-1;
	int min_num=0;
	int n=1;
	int i=0;
	int j=0;
	assert(arr);//���ԣ�arr��Ϊ��
	//һ��ͬʱ�ҳ��������С����
	while(min_num<max_num)
	{
		for(i=j+1;i<sz-j;i++)
		{
			if(arr[i] > arr[max_num])//�ҳ������
				max_num=i;
			if(arr[i] < arr[min_num])//�ҳ���С��
				min_num=i;
		}

		if(n)
			change(&max_num,&min_num);

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

//ÿ���У�ÿ�����������Ƚϣ���ĺ��ƣ���ǰ�ƣ�
//���Ƚ�N-1�֣�ÿ�ֱȽ�N-1-i��
//�Ż�����һ�����޽���ʱ��������ֱ���˳�
int bubble_sort(int arr[],const int sz)//�Ż�ð������
{
	int i=0,j=0;//ѭ������
	int temp=0;
	int t;
	assert(arr);//���ԣ�arr��Ϊ��

	for(i=0;i<sz-1;i++)
	{
		temp=0;
		for(j=0;j<sz-1-i;j++)
		{
			if(arr[j] > arr[j+1])
			{
				change(&arr[j],&arr[j+1]);
				temp=1;
			}
		}
		if(temp==0)
			return ;
	}
}

//����һ����ǩ������ǰ�ֵ�һ���������һ������
//�ȴӺ���ǰ��j--~0�����ǩ���Ƚϣ��ȱ�ǩС������������������һ��λ�ã����ǣ���λ��+1(��Ϊ�ڶ���λ��)�˳�ѭ��
//��ǰ������λ��i������i++~j�����ǩ�Ƚϣ��ȱ�ǩ��ģ�����λ�õ�������j�����ǣ�����j-1���˳�ѭ��
//���ڲ�ȡ���ǣ�֮�󽫱�ǩֵ����iλ�ã����ǣ���ԭ
//ѭ���ϲ�פ��ֱ�������������˳�ѭ��
//�ݹ�����´����򣨴�arr��iֵ��//��֤��ǰ����С������ǰ����
//�ݹ�����������򣨴�arr+i+1,sz-1-i��//���������ų���ǰ��һ����С��

int selection_sort(int arr[],const int sz)//��������
{
	int left=0;//��
	int right=sz-1;//��
	int temp=arr[left];//��ǩ
	assert(arr);//���ԣ�arr��Ϊ��
	if(sz > 1)//�˳���������
	{
		while(left < right)//��ѭ���˳�����
		{
			for(;left<right;right--)//���ȱ�ǩС��������ǰ��leftλ��
				if(temp > arr[right])//left���䣬right--
				{
				arr[left++]=arr[right];//left++�Ǳ����´αȽϣ���ǩ�������ǩ����left���Ƚ�
				break;//�˳�
				}
			
			for(;left < right;left++)//���ȱ�ǩ��������ں�rightλ��
				if(temp < arr[left])//right���䣬left++
			    {
				 arr[right--]=arr[left];//right--�Ǳ����´αȽϣ���ǩ��������right�Ƚ�
				 break;
				}
			arr[left]=temp;//��ԭ���ǵ�ֵ��left��ֵ���ǳ�����ֵ��
		}//ѭ��������С��������ǰ����������ں󣬲��ܱ�֤��һ������С
		//��֤��һ����Ϊ��ǰ��Ϊ��С������
		selection_sort(arr,left);//�ӵ�һ�������˳�ѭ��ʱ��С����λ��֮��������򣬵�һ�ֽ���
		selection_sort(arr+left+1,sz-left-1);//����ѭ������ǰ�֣�left��ǣ���һ��������С��ȥ������
	}
}

static void change(int *arr,int *anum)//����������
{
	int temp=0;
	assert(arr);//���ԣ�arr��Ϊ��
	assert(anum);//���ԣ�anum��Ϊ��
	temp=*arr;
	*arr=*anum;
	*anum=temp;
}

