/*

#include<stdio.h>
#include<stdlib.h>
struct student//�ṹ��
{
	char Name[10];
	int num;
	struct student *pNext;//ָ����һ�ڵ�ָ��
};
struct student *put();//����������
struct student *out(struct student *pHead);//�����������
struct student *Lnsert(struct student *pHead);//������ӽڵ�����λ�ú���
void Delate(struct student *pHead);//����ɾ������
void Tianjia(struct student *pHead);//������ӽڵ㺯��(���λ�ò���Ϊ��һ�������һ��)
int count=0;//ȫ�ֱ�����ͳ�Ƹ���
int main()
{
	struct student *pHead;
	pHead=put();
	printf("������%d���ڵ�\n",count);
	pHead=Lnsert(pHead);
	printf("������%d���ڵ�\n",count);
	Delate(pHead);
	printf("������%d���ڵ�\n",count);
    out(pHead);
	Tianjia(pHead);
	printf("������%d���ڵ�\n",count);
    out(pHead);
    system("pause");
    return 0;
}
struct student *put()
{
	struct student *pHead=NULL;//����ͷ�ڵ�
	struct student *pNew,*pEnd;//pNew�������ӽڵ㣬pEnd��ǵ�ǰ���
	pEnd=pNew=(struct student*)malloc(sizeof(struct student));//Ϊ��һ���ڵ�����ڴ�
	printf("�����һ��������\n");
	scanf("%s",&pNew->Name);
	scanf("%d",&pNew->num);
	printf("����numΪ0ʱ��ֹ����\n");
	while(pNew->num!=0)//ѭ����������
	{
		count++;//������1
		printf("�����%d��\n",count+1);
		if(count==1)//¼���һ������ʱ���˴�3������Ϊ3������
		{
			pNew->pNext=pHead;//���µĽڵ��е�ָ���µ�ַΪͷ�ڵ�ĵ�ַ������һ���ڵ��ַ��
			pEnd=pNew;//���µĽڵ���Ϊ���ڵ�
			pHead=pNew;//�µĽڵ���Ϊͷ�ڵ�
		}
		else  //�˴���3�����Ϊ�������̡�
		{
			pNew->pNext=NULL;//1���½��Ľڵ㣨�¿��ڴ棩��ָ����һ���ڵ�Ϊ��
			pEnd->pNext=pNew;//2���˽ڵ���ָ����һ�ڵ���Ϊ�µĽڵ�
			pEnd=pNew;//3���˽ڵ�Ҳָ���µĽڵ�
		}
		pNew=(struct student*)malloc(sizeof(struct student));
		scanf("%s",&pNew->Name);
		scanf("%d",&pNew->num);
	}
	free(pNew);//�ͷ�����num=0;�����ٵ��ڴ�
	return pHead;//����ͷ�ڵ��ַ
}
struct student *out(struct student *pHead)//�����������,ͷ�ڵ�Ϊ�β�
{
	struct student *temp;//��ʱָ��
	int i=1;//��ǽڵ����
	temp=pHead;
	while(temp!=NULL)//�ڵ����ݲ�Ϊ��
	{
      printf("��%d���ڵ�����\n",i);
	  printf("����%s\n",temp->Name);
	  printf("����%d\n",temp->num);
	  temp=temp->pNext;//�ڵ����
	  i++;
	}
}
struct student *Lnsert(struct student *pHead)
{
	struct student *pNew;//�½ڵ�ָ��
	printf("������ͷ�ڵ�֮������\n");
	pNew=(struct student*)malloc(sizeof(struct student));//���½ڵ�����ڴ�
	scanf("%s",&pNew->Name);
	scanf("%d",&pNew->num);
	pNew->pNext=pHead;//�µĽڵ���ָ����һ�ڵ�ĵ�ַΪͷ�ڵ㣨ͷ�ڵ�ĵ�ַ��Ϊ��һ���ڵ��ַ��
	pHead=pNew;//�����趨ͷ�ڵ��ַΪ�½���ͷ�ڵ�
	count++;
	return pHead;
}
 void Delate(struct student *pHead)
{
	int i;//ѭ��ʹ��
	int delate=2;//Ҫɾ���Ľڵ����
	struct student *stmp;//��ʱ����
	struct student *pEnd;//�����Ҫɾ�����¸��ڵ�
	stmp=pHead;//ָ��ͷ�ڵ�
	pEnd=stmp;//��ǰ�ڵ�ҲΪͷ�ڵ�
	printf("ɾ����%d���ڵ�\n",delate);
	for(i=1;i<delate;i++)
	{
      pEnd=stmp;//��ǰ���ָ����ʱ�ڵ�
	  stmp=stmp->pNext;//��ʱ��������
	}//������delate��
	pEnd->pNext=stmp->pNext;//����pEnd�ڵ㣨��ɾ���ڵ㣩
	free(stmp);//�ͷ�ɾ���ڵ�Ŀռ�
	 count--;//�ܽ�������1��
}
void Tianjia(struct student *pHead)
{
	int i;//ѭ������
	int add=0;//��ӵĽڵ�λ��
	struct student *Stmp;//��ʱ����
	struct student *pNew;//�µĽڵ�
	struct student *pEnd;//��ǰ���λ��
	Stmp=pHead;//��ʱ�ڵ��ͷ�ڵ㿪ʼ
	printf("�������ڼ����ڵ�֮ǰ��");
	scanf("%d",&add);
	printf("��������\n");
	pNew=(struct student*)malloc(sizeof(struct student));//�����µ��ڴ�ռ�
	scanf("%s",&pNew->Name);//��������
	scanf("%d",&pNew->num);
	for(i=1;i<add;i++)//������������Ҫ��ӵĽڵ�֮ǰλ�ã�
	{
	  pEnd=Stmp;//�ƶ���ǰ�ڵ�
	  Stmp=Stmp->pNext;
	}
	pNew->pNext=pEnd->pNext;
	pEnd->pNext=pNew;
	count++;
} 
*/





#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 typedef struct node
{
	int num;
	char s[10];
	struct node *next;

}node;

struct node *List(void);//��������
void Out(node *head);//�������
void  search(node *head);//�����м���
void paixui(node *head);//������

int main()
{
	 node *head;
	head=List();
	printf("\n************************\n");
	Out(head);
	search(head);
	printf("\n**********************\n");
	paixui(head);
	Out(head);
	system("pause");
	return 0;
}

node *List(void)//����������
{
	node *head=NULL;
	node *End;
	node *New;
	int n = 1;
	New=(node*)malloc(sizeof(node));
	End=New;
	printf("�����1������\n");
	scanf("%d %s",&New->num,&New->s);
	head=New;
	while(New->num)
	{
	  New->next=NULL;
	  End->next=New;
	  End=New;
      New=(node*)malloc(sizeof(node));
	  getchar();
	  printf("�����%d������\n", ++n);
	  scanf("%d %s",&New->num,&New->s);
	 
	}
	free(New);
	return head;
}

void Out( node *head)//���
{
	 node *s;
	s=head;
	while(s!=NULL)
	{
		printf("%d\t%s\n",s->num,s->s);
		s=s->next;
	}
}

void  search(node *head)//�����м���
{
  node *p;
  node *q;
  p=q=head;
  while(q)
  {
	  if( q->next) 
	  {
	  p=p->next;
	  q=q->next->next;
	  }
	  else
		 break;
  }
  printf("�м�����Ϊ%d",p->num);
}

void paixui(node *head)//����������
{
	node *p;//��������
	node *q;//��������
	node *temp;//���������λ��
	temp=head;//�����������ǰ
	if(temp==NULL&&temp->next==NULL) return ;
	while(temp)
	{
		p=temp;//ָ�����λ�ã����裩���󡪡�>С
		q=temp->next;//qָ��������һ����
		while(q)
		{
			if(q->num>p->num)//�����һ�������ڴ��������裩
			{
				p=q;//p��Ǻ�һ�������������
			}
			q=q->next;//q�ƶ�����
		}//�ҳ�һ�������
		if(p!=temp)//�����pָ�������������������������λ�ú�ʵ�����������һ���ط�
		{
		  int num=0;//��ʱ���ֱ���
		  char ts[10];//��ʱ�ַ�������
		  //��������
		  num=temp->num;
		  temp->num=p->num;
		  p->num=num;
		  //���ַ���������ͬ��
		  strcpy(ts,temp->s);
		  strcpy(temp->s,p->s);
		  strcpy(p->s,ts);
		}
		temp=temp->next;//����һ�������
   }
}
