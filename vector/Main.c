#include<stdio.h>
#include<stdlib.h>
#include"Seqlest.h"

int main()
{
	seqlist arr;
	int count=0;
	type data=0;
	int n=0;
	printf("�����ʼ��������");
	scanf("%d",&count);

	Init(&arr,count);//��ʼ��
	printf("��ʼ����\n");
	Print(&arr);

	/*
	printf("ͷɾ����\n");
	Head_Delete(&arr);//ͷɾ
	Print(&arr);

	printf("βɾ����\n");
	Tail_Delete(&arr);//βɾ
	Print(&arr);

	printf("��������λ�ú�����:");//�����ڵڼ�����λ��
	scanf("%d%d",&n,&data);
	printf("��%d������%d��\n",n,data);
	Plug(&arr,n,data);
	Print(&arr);

	printf("��%d��ɾ����\n",n);
	Delete(&arr,n);//ɾ���ڼ�����
	Print(&arr);

	printf("������������:");//β��
	scanf("%d",&data);
	printf("β����%d��\n",data);
	Tail_Plug(&arr,data);
	Print(&arr);

	printf("������������:");//ͷ��
	scanf("%d",&data);
	printf("ͷ����%d��\n",data);
	Head_Plug(&arr,data);
	Print(&arr);

	printf("����ɾ��������:");//ɾ������data
	scanf("%d",&data);
	Delete1(&arr,data);
	printf("dataɾ��%d��\n",data);
	Print(&arr);

	printf("������ҵ�����:");//ɾ������data
	scanf("%d",&data);
	printf("�����%d\n",search(&arr,data));//-1��ʾδ�ҵ�
	
	
	printf("����ɾ��������:");//ɾ������data
	scanf("%d",&data);
	Delete2(&arr,data);
	printf("dataɾ��%d��\n",data);
	Print(&arr);
	*/
	printf("����ɾ��������:");//ɾ������data,����2
	scanf("%d",&data);
	Remove_all(&arr,data);//ɾ����������data
	Print(&arr);

    printf("�����%d\n",SeqListEmpty(&arr));//�ж�˳����Ƿ�Ϊ��

	system("pause");
	return 0;
}