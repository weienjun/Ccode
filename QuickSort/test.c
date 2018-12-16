#include<stdio.h>
#include<stdlib.h>
/*
int main()
{
	int arr[5] = {1,2,3,4,5};
	int * p = arr;
	int i = 0;

	*(p++) += 1;//ͬ��*p = *(p++) + 1; *p = 2�����ȼ� * > p++,  *ͬ��++����*�Ǵ����������㣬������ִ��++p  arr[0] = 2
	printf("%d,%d\n",*p,*++p);//3 3---�β�ʵ��������������ִ��++p  *p = 3

	p = arr;
	*(p++) = *(p++) + 1; //arr[0] = 2; *p = 3
	printf("%d,%d\n",*p,*p++);//4 3 ---��ִ��*p��++ ֵΪ3,��*pֵΪ4  arr[0] = 3

	p =arr;
	*p = *(p++) + 1;//arr[0] = 4
	printf("%d,%d\n",*p,*++p);//3 3

	for(; i < 5; i++)
		printf("%d ",arr[i]);//4 2 3 4 5
	system("pause");
	return 0;
}
*/

int q_sort(int arr[],int sz);
void FSort(int arr[],int sz);
 void FSort2(int* arr,int right);


 void Swap(int* L,int* R)
 {
     int tmp = *L;
     *L = *R;
     *R = tmp;
 }


int _FastSort3(int*arr,int left,int right)
{
     int cur = left;
     int prev = left-1;//ע�˴�Ҫ��һ����Ϊprev��ǵ���ǰһ�������涼���ȼ�++��Ƚϵ�
     int key = arr[right-1];
	while(cur < right)
	{
		if(arr[cur] < key && ++prev != cur)
			Swap(&arr[cur],&arr[prev]);
		cur++;
	}
      
	if(++prev != right)
		Swap(&arr[prev],&arr[right-1]);
     return prev;
}

void FastSort(int* arr,size_t left,size_t right)
{

    if(arr && left < right)//�ݹ����
    {
        //size_t dev = _FastSort(arr,left,right);
        size_t dev = 0;
        //dev = _FastSort2(arr,left,right);//���ִ���
        dev = _FastSort3(arr,left,right);//���ִ���
        FastSort(arr,left,dev);//����ǰ�沿��
        FastSort(arr,dev+1,right);//������沿��
    }

}

//�����µ���
void AdjustDown(int* arr,int size,int parent)
{
	int child = parent*2+1;
	while(child < size)
	{
		if(child+1 < size && arr[child] < arr[child+1])
			child++;
		if(arr[parent] < arr[child])
		{
			Swap(&arr[parent],&arr[child]);
			parent = child;
			child = parent*2+1;
		}
		else
			return ;
	}
}

//������
void HeapSort(int* arr,int size)
{
	int parent = (size-2) >> 1;
	int i = 0;
	if(!arr || size < 1)
		return ;
	
	//�ѵ���
	for(i = parent; i >= 0;i--)
		AdjustDown(arr,size,i);
	//������	
	for(i = size-1; i > 0;)
	{
		Swap(&arr[0],&arr[i]);//���Ѷ��뵱ǰ���һ��Ԫ�ؽ���
		AdjustDown(arr,i,0);//�ӶѶ����µ���(����i��Ԫ��),ע�˴���һ�������䣬����i��֮��--
		i--;
	}
}

 void Mrege(int* arr,int size);

int main()
{
	int i=0;
	//int arr[]={1,3,4,6,9,8,2,5,5,6,8,2,31,23,98,100,25,10,87};
	 int arr[] = {1,9,9,9,4,6,9,8,2,0};
	int sz=sizeof(arr)/sizeof(arr[0]);
	for(i=0;i<sz;i++)
	{
		printf("%d  ",arr[i]);
	}
	printf("\n");
	//q_sort(arr,sz);
	//FSort2(arr,sz);
	 Mrege(arr,sz);
	//FastSort(arr,0,sz);
	//HeapSort(arr,sz);

	for(i=0;i<sz;i++)
	{
		printf("%d  ",arr[i]);
	}
	system("pause");
	return 0;
}

int q_sort(int arr[],int sz)
{
	int i=0;
	int j=sz-1;
	int key=arr[0];//������ֵ
	
	if(sz>1)//1����������
	{
		while(i < j)
		{
			while(i<j && key<=arr[j])
				j--;
			if(i<j)
			arr[i++]=arr[j];//������ֵ����ֵ�����ǣ�

			while(i<j && key>=arr[i])
				i++;
			if(i<j)
			arr[j--]=arr[i];//������ֵ����ֵ�����ǣ�

			arr[i]=key;//��ԭ����ֵ
		}
		q_sort(arr,i);
		q_sort(arr+i+1,sz-i-1);
	}
}

//��ȡ�м�ֵ�������м�ֵ������ǰ
int In(int* arr,int L,int R)
{
	int mid = L+((R-L)>>1);
	if(arr[mid] > arr[R])
		Swap(&arr[mid],&arr[R]);
	if(arr[L] > arr[R])
		Swap(&arr[L],&arr[R]);
	if(arr[mid] > arr[L])
		Swap(&arr[mid],&arr[L]);

	return arr[L];//�����ֵ��Ϊ�ο�ֵ
}


//�����Ż�---����ȡ�з�(��������ƽ������)
void FSort2(int* arr,int right)
{
	int left = 0;
	int end = right-1;
	
	//if(!arr || left >= end)
	//	return ;
	//int key = arr[0];
	int key = In(arr,left,end);
	if(right > 1)
	{
		while(left < end)//ѭ����������������������һ�ִ������
		{

			//�����Ҳ�С��key��ֵ
			while(left < end && arr[end] >= key)
				end--;
			if(left < end)
				arr[left++] = arr[end];

			//�������С��key��ֵ
			while(left < end && arr[left] <= key)
				left++;
			if(left < end)
				arr[end--] = arr[left];//key����ֵ������
		
			arr[left] = key;
		}
		//arr[left] = key;//��ԭkeyֵ
		FSort2(arr,left);
		FSort2(arr+left+1,right-left-1);
	}
}

void FSort(int* arr,int right)
{
	int left = 0;
	int end = right-1;
	//if(!arr || left >= end)
	//	return ;
	int key = arr[0];
	if(right >1)
	{
		while(left < end)//ѭ����������������������һ�ִ������
		{

			//�����Ҳ�С��key��ֵ
			while(left < end && arr[end] >= key)
				end--;
			if(left < end)
				arr[left++] = arr[end];

			//�������С��key��ֵ
			while(left < end && arr[left] <= key)
				left++;
			if(left < end)
				arr[end--] = arr[left];//key����ֵ������
		
			arr[left] = key;
		}
		//arr[left] = key;//��ԭkeyֵ
		FSort(arr,left);
		FSort(arr+left+1,right-left-1);
	}
}

#include<string.h>
//Ͱ����
static int Maxnum(int* arr,int size)
{
	int i = 1;
	int max = arr[0];
	for(; i < size; i++)
	{
		if(max < arr[i])
			max = arr[i];
	}
	return max;
}
void Mrege(int* arr,int size)
{
	
	int* bulack = (int*)malloc(sizeof(int)*size);
	int i = 0;
	int bitnum = 1;
	int maxnum = Maxnum(arr,size);//�������
	while(bitnum < maxnum*10)//ѭ������(λ)
	{
		int count[10] = {0};//ͳ��ÿ��Ͱ��Ԫ�ظ���
		int startadds[10] = {0};//ͳ��ÿ��Ͱ����ʼ��ַ

		////ͳ��ÿ��Ͱ�е����ݸ���
		for(i = 0; i < size; i++)
			count[(arr[i]/bitnum)%10]++;

		//Ͱ��ÿ��Ͱ����ʼλ��
		for(i = 1; i < 10; i++)
			startadds[i] = startadds[i-1]+count[i-1];

		//�����ݷ��ڶ�Ӧ��Ͱ��
		for(i = 0; i < size; i++)
		{
			int n = arr[i]/bitnum%10;//����ӳ��λ��
			bulack[startadds[n]++] = arr[i];
		}
		//�����ݷŻ�������
		memmove(arr,bulack,sizeof(int)*size);
		//�������λ
		bitnum *= 10;
	}
	free(bulack);
}



/*
template<class T>
size_t _FastSort2(T* arr,size_t left,size_t right)
{
	int begin = left;
	int end = right-1;
	if(!arr && left >= right)
	return 0;
	T key = arr[end];
	while(begin < end)
	{
		//T key = arr[end];
		while(begin < end && arr[begin] <= key)
			begin++;
		if(begin < end)
		arr[end--] = arr[begin];
		while(begin < end && arr[end] >= key)
			end--;
		if(begin < end)
		arr[begin++] = arr[end];
	//	if(begin < right-1)
		arr[begin] = key;
	}
	return begin;
}

*/
//
//#include<stdio.h>
//#include<stdlib.h>
//int partition(int arr[],int left,int right);
//void qsort(int arr[],int left,int right);
//int main()
//{
//	int arr[]={32,12,7,78,23,45};
//    int i=0;
//	qsort(arr,0,5);
//	for(i=0;i<6;i++)
//		printf("%d  ",arr[i]);
//	system("pause");
//	return 0;
//}
//
//void qsort(int arr[],int left,int right)
//{
//	int dp;
//	if(left<right)
//	{
//		dp=partition(arr,left,right);
//		qsort(arr,left,dp-1);
//		qsort(arr,dp+1,right);
//	}
//}
//
//int partition(int arr[],int left,int right)
//{
//	int temp=arr[left];
//
//	while(left < right)
//	{
//		while(left<right && arr[right]>=temp)
//			right--;
//			if(left<right)
//			arr[left++]=arr[right];
//		while(left<right && arr[left]<=temp)
//			left++;
//			if(left<right)
//			arr[right--]=arr[left];
//	}
//	arr[left]=temp;
//    return left;
//}


//#include <stdio.h>
//#include <stdlib.h>
//#define N 6
//int partition(int arr[], int low, int high)
//{
//    int key;
//    key = arr[low];
//    while(low<high)
//	{
//        while(low <high && arr[high]>= key )
//            high--;
//        if(low<high)
//            arr[low++] = arr[high];
//        while( low<high && arr[low]<=key )
//            low++;
//        if(low<high)
//            arr[high--] = arr[low];
//    }
//    arr[low] = key;
//    return low;
//}
//
//void quick_sort(int arr[], int left, int right){
//    int pos;
//    if (left<right){
//        pos = partition(arr, left, right);
//        quick_sort(arr,left,pos-1);
//        quick_sort(arr,pos+1,right);
//    }
//    return;
//}
//
//int main(void){
//    int i;
//    int arr[N]={32,12,7, 78, 23,45};
//    printf("����ǰ \n");
//    for(i=0;i<N;i++)
//        printf("%d\t",arr[i]);
//    quick_sort(arr,0,N-1);
//    printf("\n ����� \n");
//    for(i=0; i<N; i++)
//        printf("%d\t", arr[i]);
//    printf ("\n");
//    system("pause");
//    return 0;
//}

