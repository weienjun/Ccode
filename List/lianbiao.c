/*

#include<stdio.h>
#include<stdlib.h>
struct student//结构体
{
	char Name[10];
	int num;
	struct student *pNext;//指向下一节点指针
};
struct student *put();//构造链表函数
struct student *out(struct student *pHead);//构造输出函数
struct student *Lnsert(struct student *pHead);//构造添加节点在首位置函数
void Delate(struct student *pHead);//构造删除函数
void Tianjia(struct student *pHead);//构造添加节点函数(添加位置不可为第一个和最后一个)
int count=0;//全局变量，统计个数
int main()
{
	struct student *pHead;
	pHead=put();
	printf("链表有%d个节点\n",count);
	pHead=Lnsert(pHead);
	printf("链表有%d个节点\n",count);
	Delate(pHead);
	printf("链表有%d个节点\n",count);
    out(pHead);
	Tianjia(pHead);
	printf("链表有%d个节点\n",count);
    out(pHead);
    system("pause");
    return 0;
}
struct student *put()
{
	struct student *pHead=NULL;//定义头节点
	struct student *pNew,*pEnd;//pNew标记新添加节点，pEnd标记当前结点
	pEnd=pNew=(struct student*)malloc(sizeof(struct student));//为第一个节点分配内存
	printf("输入第一个组数据\n");
	scanf("%s",&pNew->Name);
	scanf("%d",&pNew->num);
	printf("输入num为0时终止输入\n");
	while(pNew->num!=0)//循环输入条件
	{
		count++;//总数加1
		printf("输入第%d组\n",count+1);
		if(count==1)//录入第一组数据时。此处3个句子为3个过程
		{
			pNew->pNext=pHead;//将新的节点中的指向下地址为头节点的地址（即第一个节点地址）
			pEnd=pNew;//将新的节点作为本节点
			pHead=pNew;//新的节点作为头节点
		}
		else  //此处的3个语句为三个过程。
		{
			pNew->pNext=NULL;//1将新建的节点（新开内存）中指向下一个节点为空
			pEnd->pNext=pNew;//2将此节点中指向下一节点设为新的节点
			pEnd=pNew;//3将此节点也指向新的节点
		}
		pNew=(struct student*)malloc(sizeof(struct student));
		scanf("%s",&pNew->Name);
		scanf("%d",&pNew->num);
	}
	free(pNew);//释放最后次num=0;所开辟的内存
	return pHead;//返回头节点地址
}
struct student *out(struct student *pHead)//构造输出函数,头节点为形参
{
	struct student *temp;//临时指针
	int i=1;//标记节点序号
	temp=pHead;
	while(temp!=NULL)//节点内容不为空
	{
      printf("第%d个节点内容\n",i);
	  printf("名字%s\n",temp->Name);
	  printf("数字%d\n",temp->num);
	  temp=temp->pNext;//节点后移
	  i++;
	}
}
struct student *Lnsert(struct student *pHead)
{
	struct student *pNew;//新节点指针
	printf("插入在头节点之后内容\n");
	pNew=(struct student*)malloc(sizeof(struct student));//给新节点分配内存
	scanf("%s",&pNew->Name);
	scanf("%d",&pNew->num);
	pNew->pNext=pHead;//新的节点中指向下一节点的地址为头节点（头节点的地址即为第一个节点地址）
	pHead=pNew;//重新设定头节点地址为新建的头节点
	count++;
	return pHead;
}
 void Delate(struct student *pHead)
{
	int i;//循环使用
	int delate=2;//要删除的节点序号
	struct student *stmp;//临时变量
	struct student *pEnd;//标记所要删除的下个节点
	stmp=pHead;//指向头节点
	pEnd=stmp;//当前节点也为头节点
	printf("删除第%d个节点\n",delate);
	for(i=1;i<delate;i++)
	{
      pEnd=stmp;//当前结点指向临时节点
	  stmp=stmp->pNext;//临时结点向后移
	}//检索到delate后
	pEnd->pNext=stmp->pNext;//跳过pEnd节点（即删除节点）
	free(stmp);//释放删除节点的空间
	 count--;//总结点个数减1；
}
void Tianjia(struct student *pHead)
{
	int i;//循环变量
	int add=0;//添加的节点位置
	struct student *Stmp;//临时变量
	struct student *pNew;//新的节点
	struct student *pEnd;//当前结点位置
	Stmp=pHead;//临时节点从头节点开始
	printf("输入插入第几个节点之前：");
	scanf("%d",&add);
	printf("输入内容\n");
	pNew=(struct student*)malloc(sizeof(struct student));//开辟新的内存空间
	scanf("%s",&pNew->Name);//输入内容
	scanf("%d",&pNew->num);
	for(i=1;i<add;i++)//遍历链表（查找要添加的节点之前位置）
	{
	  pEnd=Stmp;//移动当前节点
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

struct node *List(void);//创建链表
void Out(node *head);//输出函数
void  search(node *head);//查找中间数
void paixui(node *head);//排序函数

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

node *List(void)//建立链表函数
{
	node *head=NULL;
	node *End;
	node *New;
	int n = 1;
	New=(node*)malloc(sizeof(node));
	End=New;
	printf("输入第1个数据\n");
	scanf("%d %s",&New->num,&New->s);
	head=New;
	while(New->num)
	{
	  New->next=NULL;
	  End->next=New;
	  End=New;
      New=(node*)malloc(sizeof(node));
	  getchar();
	  printf("输入第%d个数据\n", ++n);
	  scanf("%d %s",&New->num,&New->s);
	 
	}
	free(New);
	return head;
}

void Out( node *head)//输出
{
	 node *s;
	s=head;
	while(s!=NULL)
	{
		printf("%d\t%s\n",s->num,s->s);
		s=s->next;
	}
}

void  search(node *head)//查找中间数
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
  printf("中间数字为%d",p->num);
}

void paixui(node *head)//按数字排序
{
	node *p;//标记最大数
	node *q;//遍历链表
	node *temp;//放置最大数位置
	temp=head;//最大数放在最前
	if(temp==NULL&&temp->next==NULL) return ;
	while(temp)
	{
		p=temp;//指向大数位置（假设），大——>小
		q=temp->next;//q指向大数后的一个数
		while(q)
		{
			if(q->num>p->num)//如果后一个数大于大数（假设）
			{
				p=q;//p标记后一个数（最大数）
			}
			q=q->next;//q移动检索
		}//找出一个最大数
		if(p!=temp)//假设的p指向大数不成立，即假设的最大数位置和实际最大数不在一个地方
		{
		  int num=0;//临时数字变量
		  char ts[10];//临时字符串变量
		  //数字排序
		  num=temp->num;
		  temp->num=p->num;
		  p->num=num;
		  //让字符串与数字同步
		  strcpy(ts,temp->s);
		  strcpy(temp->s,p->s);
		  strcpy(p->s,ts);
		}
		temp=temp->next;//排下一个最大数
   }
}
