//1.��⺯��ָ��Ͷ��� 
//2.��⺯��ָ������Ͷ��壬ת�Ʊ� 
//3.���ָ����ָ�������ָ��Ͷ��� 
//4.���ص�������ʹ��  
//5.��ɿ��ô������ϰ�� 
//6.��ϰʹ��qsort��������������͵����ݡ� 
//7.ģ��qsort�Ĺ���ʵ��һ��ͨ�õ�ð������

#include<stdio.h>
#include<stdlib.h>

void my_bubble(void *base,int count,int size);//�������
//int cmp(const void *p1,const int size,const int j);//�����ж�
int cmp(const void *p1,const void *p2,const int size);//�����ж�
void swap(void *before ,void *after,int size);//����ʵ��
int main()
{
	int j=0;
	int i=0;
	//char arr[]={'1','2','3','6','5','8','4','a'};
	int arr[]={1,2,5,6,78,98,1424,666,8};
	int sz=sizeof(arr)/sizeof(arr[0]);
	
	my_bubble(arr,sz,sizeof(int));

	for(i=0;i<sz;i++)
	printf("%d \n",arr[i]);

	system("pause");
	return 0;
}

void my_bubble(void *base,int count,int size)
{
	int i=0;
	int j=0;
	int n=0;//���ڼ����Ƿ�����

	for(i=0;i<count-1;i++)
	{
		n=0;
		for(j=0;j<count-i-1;j++)
		{
			if(cmp(((char *)base+size*j),(char*)base+size*(j+1),size))//�ж��Ƿ�����,ÿ�δ����ʱ��ǰԪ�صĵ�ַ
			  //if(cmp(((char *)base),size,j))//�ж��Ƿ�����ÿ�δ�������׵�ַ
			{
				swap((char *)base+size*j,(char*)base+size*(j+1),size);//��������ÿ�δ�����ǵ�ǰ�ĵ�ַ
			    n=1;
			}
		}
		if(n=0)//�������˳�
			break;
	}
}

int cmp(const void *p1,const void *p2,const int size)
{
	if(size==1)//�ַ����������ΪASCLL����
	return (*(char*)p1 > *(char*)p2);
	else//��������
	return (*(int*)p1 > *(int*)p2);//�������ط�0
}

void swap(void *before ,void *after,int size)
{
	int i=0;
	char tmp;
	for(i=0;i<size;i++)//��ַ�е����ݽ��н�����ÿ�ν���һ���ֽڵ�����
	{
		tmp=*((char*)before+i);
		*((char*)before+i)=*((char*)after+i);
		*((char*)after+i)=tmp;
	}
}

//int cmp(const void *p1,const int size,const int j)
//{
//	if(size==1)//ֻ�������ַ���ASCLL�����ڵ����֣�char����ֻռһ���ֽڣ��洢�����ִ�С����
//	return (*((char*)p1+(size*j))) > (*((char*)p1+((j+1)*size)));//�������ط�0
//	else//��������
//	return (*((int*)p1+j)) > (*((int*)p1+(j+1)));//�������ط�0
//	
//}