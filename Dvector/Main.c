
#include<stdio.h>
#include<stdlib.h>
#include"Test.h"

int main()
{
	seqlist q;
	type data=0;
	int n=0;
	seq_init(&q);//��ʼ��
	print(&q);

	printf("put search data:");
	scanf("%d",&data);//������
	printf("��%d����\n",seq_search(&q,data));

	printf("put delete data:");
	scanf("%d",&data);
	seq_delete(&q,data);//ɾ��data��
	print(&q);

	printf("put delete data:");
	scanf("%d",&data);
	seq_delete_all(&q,data);//ɾ������data
	print(&q);

	printf("put  n and data:");//dataλ�����data
	scanf("%d%d",&n,&data);
	seq_put(&q,n,data);
	print(&q);

	seq_clear(&q);//���

	seq_clearseq(&q);//����

	printf("֮ǰ����%d\n",seq_size(&q));
	seq_addsize(&q);//����
	printf("֮������%d\n",seq_size(&q));

	seq_clearseq(&q);//����

	system("pause");
	return 0;
}


/*

#include<stdio.h>
#include<stdlib.h>

typedef int type;
typedef struct Seqlist//��̬˳���
{
	type * num;//�洢����
	unsigned int size; //ͳ�����ݸ���
    unsigned int n_size; //������һ�ο����ڴ�ռ��С
}seqlist;

int a;
int b=0;

int main()
{
	seqlist p1;
	seqlist * p2=NULL;
	int i=0;

	type * temp;

	printf("p2=%p\n",p2);
	//printf("p1=%p\n",p1);
	printf("&p1=%p\n",&p1);//�ṹ���׵�ַ���ṹ������ĵ�ַ��ջ��
	printf("&p1.num=%p\n",&p1.num);
	printf("&p2=%p\n",&p2);


	p1.size=0;
	p1.n_size=5;
	scanf("%u",&p1.n_size);
	if((int)p1.n_size <= 0)
	 printf("put eorr!\n");
	else 
	p1.num=(type *)malloc(sizeof(type)*p1.n_size);//Ϊnum���ٿռ�
	if(! p1.num)
	{
		printf("eorr!\n");
		exit(0);
	}

	for(i=0;i<p1.n_size;i++)//��ʼ��num
	{
		p1.num[i]=i;
		p1.size++;
	}

	temp=p1.num;//��ȡ���ϵ�ַ
	p2=&p1;//��p1��ַ����p2��ջ��ַ��
	printf("*%d\n",sizeof(p1));
	printf("*%d\n",sizeof(p2));


	printf("%p\n",&p1.num);//��ȡָ����ϵĵ�ַ��ջ�ϣ���p1.num��ַ�ڶ���)

	//p2=(seqlist*)malloc(sizeof(seqlist));
	printf("p2=%p\n",p2);
	printf("p1=%p\n",p1);
	printf("&p1=%p\n",&p1);//�ṹ���׵�ַ���ṹ������ĵ�ַ��ջ��
	printf("&p2=%p\n",&p2);
	printf("%p\n",p1.num);//p1.numΪ���Ͽ��ٵ��׵�ַ
	printf("%p\n",&(p1.num[0]));//���Ͽ��ٵĵ�һ��Ԫ�ص�ַ

	printf("%d\n",*p1.num++);//0
	printf("%d\n",*p2->num++);//1

	printf("%d\n",*temp++);//0
	printf("%d\n",*temp++);//1

	printf("%d\n",*p1.num);//2
	//free(p1.num);

	p2=(seqlist *)malloc(sizeof(seqlist));
	p2->num=(type*)malloc(sizeof(type)*3);
	*p2->num=10;

	printf("%p\n",&p2);//��Žṹ��ĵ�ַ���õ�ַ��ջ��

	printf("p2=%p\n",p2);//�ṹ��ĵ�ַ���ṹ���׵�ַ����p2��ַ�ڶ���
	printf("%p\n",&p2->num);//ȡ��num�ı�����ַ
	
	printf("%p\n",p2->num);//ȡnum���׵�ַ
	printf("%p\n",&(p2->num[0]));//ȡnum�еĵ�һ��Ԫ�ص�ַ

	printf("%p\n",++p2->num);//num�еĵڶ���Ԫ�ص�ַ

	printf("%p\n",&p2->size);
	printf("%p\n",&p2->n_size);
	printf("%p\n",++p2);//�ṹ�������һ��������ַ

//	printf("%d\n",*p2->num);//1

	system("pause");
	return 0;
}

*/

//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	char *ch="123";
//	//int *a;
//	char *arr[4]={"123","456","789","147"};
//	//a=(int *)malloc(20);
//	//*a=1;
//	//*a=2;
//	//arr[1]="000";
//	char a[20];
//
//	printf("%p\n",arr[1]);
//	arr[1]="000";
//	printf("%p\n",arr[1]);
//
//	printf("%p\n",arr[2]);
//	printf("%s\n",arr[2]);
//
//	printf("pch=%p\n",ch);
//	printf("&ch=%p\n",&ch);
//	ch="1213";
//	printf("ch=%s\n",ch);
//
//	printf("pch=%p\n",ch);
//	printf("&ch=%p\n",&ch);
//	printf("&arr=%p\n",&arr);
//	printf("arr=%p\n",arr);
//	printf("arr[0]=%p\n",arr[0]);
//	printf("&arr[0]=%p\n",&arr[0]);
//
//	printf("arr[1]=%p\n",arr[1]);
//	printf("&arr[1]=%p\n",&arr[1]);
//
//	printf("%p\n",arr[2]);
//
//	free(&a[0]);
//
//	system("pause");
//	return 0;
//}
//
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	
//	int i=0;
//	int arr[5]={1,1,2,3,5};
//
//	for(i=0;i<=10;i++)
//	{
//		printf("****\n");
//		arr[i]=0;
//	}
//
//	system("pause");
//	return 0;
//}