#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//���typedef�ɼ���д����Student�����Ǳ�����������ǽṹ�嶨�弴Student=struct student ����д
typedef struct node//�û��Զ��������� typedef ԭ������ ����������typedf int A  //֮��A�ʹ���int��
{
	char name[10];
	struct node *prior;
	struct node *next;//˫������priorָ��ǰ��nextָ���
}Student;//Student���� struct student����д
Student *creat(int n);//����������
Student *del(Student *sp,Student *head);//ɾ������
Student *search(Student *h,char *x);//���Һ���
int main ()
{
	int n;//�����С
	Student *head;//ͷ�ڵ�
	char sname[10];
	Student *sp;
	Student *p;
	puts("���������С��");
	scanf("%d",&n);
	head=creat(n);
	sp=head->next;
	printf("˫�������ǣ�\n");
	while(sp)
	{
		printf("%s\t",sp->name);
		sp=sp->next;
	}
	printf("\n������ҵ�����\n");
	scanf("%s",sname);
	p=search(head,sname);
	printf("���ҵ������ǣ�%s\n",p->name);
	del(p,head);//ɾ���ڵ㺯��
	sp=head->next;
	printf("˫������Ϊ��\n");
	while(sp)
	{
		printf("%s  ",&*(sp->name));
		sp=sp->next;
	}
	printf("\n");
	puts("\n �����˳� ");
	system("pause");
	return 0;
}
Student *creat(int n)
{
	int i;//ѭ������
	Student *p;//ָ��ǰ���
	Student *h;//ָ���µĽڵ㣨��ڵ㣩
	Student *s;//ָ���µĽڵ㣨ǰ�ڵ㣩
	h=(Student*)malloc(sizeof(Student));//����ռ�
	h->name[0]='\0';
	h->prior=NULL;//ָ��ǰһ���ڵ�Ϊ��
	h->next=NULL;
	p=h;//ָ�򱾽ڵ�Ϊ��ǰ�µĽڵ�
	for(i=0;i<n;i++)
	{
		s=(Student*)malloc(sizeof (Student));//Ϊǰһ���ڵ㿪�ٿռ�
		p->next=s;//�����ڵ�ָ����һ���Ľڵ㣩Ϊ��һ�ڵ�//�γ�˫������
		s->prior=p;//����һ��ָ��ǰһ���Ľڵ㣩�Ǳ��ڵ�
	    printf("�����%d��ѧ��������\n",i+1);
	    scanf("%s",s->name);
		s->next=NULL;
		p=s;
	}
	p->next=NULL;
	return (h);
}
Student *search(Student *h,char *x)
{
	Student *p;
	char *y;
	p=h->next;
	while(p)
	{
		y=p->name;
		if(strcmp(y,x)==0)
			return p;
		else
			p=p->next;
   	}
	printf("δ�ҵ�\n");
}
Student *del(Student *sp,Student *head)
{
	Student *temp;
	temp=head;
	while(temp)
	{
		
		if(strcmp(temp->name,sp->name)==0)
		{
			printf("*********************\n");
			if(sp->next==NULL)//�ж��Ƿ�Ϊ���һ���ڵ�
			 {
				temp->prior->next=NULL;//�����һ���ڵ�ʱ�������һ��ָ��ǰһ���ĺ�һ���ڵ�Ϊ�գ������Լ�Ϊ�գ�
			  }
			else
			 {
			  temp->next->prior=temp->prior;//ɾ���ڵ�p
			  temp->prior->next=temp->next;	
			  return head;
			 }
			free(sp);break;//ɾ������������ѭ������������±�������������ɾ�������ڵ�ͻ����
		}
		temp=temp->next;
	}
}



