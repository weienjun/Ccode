#include<stdio.h>
#include<stdlib.h>
#define N 9  //�����ܸ���
#define OVERFLOW 0 //
int Key[N]={4,7,5,9,3,2,6,1,8};//����
typedef struct LNode
{
	int n;
	struct LNode *next;
}LNode,*num;//LNode=struct LNode����ṹ������.*num�ǽṹ��ָ��
void Joseph(num p,int m,int x);
void out (num p,int a);
int main()
{
	int i,m;
	num Lhead ,p,q;//�ṹ�����
	for(i=0;i<9;i++)
		printf("%d ",Key[i]);
	Lhead=(num)malloc(sizeof(LNode));
    if(!Lhead)//�ڴ濪��ʧ��
		return OVERFLOW;
	Lhead->n=Key[0];//ָ��ָ�������׵�ַ
	Lhead->next=NULL;
	p=Lhead;
	for(i=1;i<9;i++)
	{
		if(!(q=(num)malloc(sizeof(LNode))))//�ڴ濪��ʧ��
			return OVERFLOW;//�˳�
		q->n=Key[i];//��������ֵ
		p->next=q;//p��ָ����һ����ַΪָ���¿��ٽڵ�
		p=q;//pָ���¿��ٽڵ�
	}
	p->next=Lhead;//������ָ��pָ��ͷ�ڵ�
	printf("\n�����һ�μ���ֵm:\n");
	scanf("%d",&m);
	printf("����Ķ�����:\n");
	Joseph(p,m,N);
	system("pause");
	return 0;
}
void Joseph(num p,int m,int x)
{
	num q;//��ʱָ��
	int i;
	if(x==0)//���鳤Ϊ0(����)
		return ;//�˳�
	q=p;//ָ��ָ��ͷ�ڵ�
	m%=x;//�ж��Ƿ�Ϊ�������һ��
	if(m==0)//�����һ��
		m=x;
	for(i=1;i<=m;i++)
	{
		p=q;//�ӵ�һ���ڵ㿪ʼ�������˽ڵ�
		q=p->next;
	}
	p->next=q->next;
	i=q->n;//��¼�˽ڵ��е�ֵ
	printf("\n");
	if(q->next==NULL) return;
	printf("ɾ��%d  ",q->n);
	//out(q,x-1);
	free(q);
	
	Joseph(p,i,x-1);//�ݹ飬pΪͷ�ڵ㣬iΪ��ɾȥ�е�ֵ���ܽ�����-1
}

/*void out(num p,int a)
{
	int i;
	int b[10];
	printf("\n");
	for(i=0;i<=a;i++)
	{
		if(p->n==b[i])continue;
		 b[i]=Key[i];
		printf("%d ",b[i]);

	}
}*/