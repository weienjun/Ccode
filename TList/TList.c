#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//添加typedef可简化书写，后Student不再是变量而代表的是结构体定义即Student=struct student 的书写
typedef struct node//用户自定义类型名 typedef 原类型名 新类型名（typedf int A  //之后A就代表int）
{
	char name[10];
	struct node *prior;
	struct node *next;//双向链表，prior指向前，next指向后
}Student;//Student代表 struct student的书写
Student *creat(int n);//创建链表函数
Student *del(Student *sp,Student *head);//删除函数
Student *search(Student *h,char *x);//查找函数
int main ()
{
	int n;//链表大小
	Student *head;//头节点
	char sname[10];
	Student *sp;
	Student *p;
	puts("输入链表大小：");
	scanf("%d",&n);
	head=creat(n);
	sp=head->next;
	printf("双向链表是：\n");
	while(sp)
	{
		printf("%s\t",sp->name);
		sp=sp->next;
	}
	printf("\n输入查找的名字\n");
	scanf("%s",sname);
	p=search(head,sname);
	printf("查找的名字是：%s\n",p->name);
	del(p,head);//删除节点函数
	sp=head->next;
	printf("双向链表为：\n");
	while(sp)
	{
		printf("%s  ",&*(sp->name));
		sp=sp->next;
	}
	printf("\n");
	puts("\n 按键退出 ");
	system("pause");
	return 0;
}
Student *creat(int n)
{
	int i;//循环变量
	Student *p;//指向当前结点
	Student *h;//指向新的节点（后节点）
	Student *s;//指向新的节点（前节点）
	h=(Student*)malloc(sizeof(Student));//分配空间
	h->name[0]='\0';
	h->prior=NULL;//指向前一个节点为空
	h->next=NULL;
	p=h;//指向本节点为当前新的节点
	for(i=0;i<n;i++)
	{
		s=(Student*)malloc(sizeof (Student));//为前一个节点开辟空间
		p->next=s;//（本节点指向下一个的节点）为下一节点//形成双向链表
		s->prior=p;//（下一个指向前一个的节点）是本节点
	    printf("输入第%d个学生的姓名\n",i+1);
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
	printf("未找到\n");
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
			if(sp->next==NULL)//判断是否为最后一个节点
			 {
				temp->prior->next=NULL;//是最后一个节点时，将最后一个指向前一个的后一个节点为空（即让自己为空）
			  }
			else
			 {
			  temp->next->prior=temp->prior;//删除节点p
			  temp->prior->next=temp->next;	
			  return head;
			 }
			free(sp);break;//删除后立刻跳出循环，不在向后下遍历，否则若是删除了最后节点就会出错
		}
		temp=temp->next;
	}
}



