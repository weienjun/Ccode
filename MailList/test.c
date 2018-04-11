//1.自定义类型部分知识写一篇博客。 
//知识点： 
//>结构体类型创建 
//>结构体初始化 
//>结构体内存对齐 
//>位段，位段计算机大小。 
//>枚举+联合。 
//
//2.实现一个通讯录； 
//通讯录可以用来存储1000个人的信息，每个人的信息包括： 
//姓名、性别、年龄、电话、住址 
//
//提供方法： 
//1. 添加联系人信息 
//2. 删除指定联系人信息 
//3. 查找指定联系人信息 
//4. 修改指定联系人信息 
//5. 显示所有联系人信息 
//6. 清空所有联系人 
//7. 以名字排序所有联系人 

#include<stdio.h>
#include<stdlib.h>
#include"realization.h"
int count;

int main()
{  
	people * head=NULL;//头节点

	Menu(head);//菜单函数

	system("pause");
	return 0;
}

int Menu(people * head)
{
	int num=0;
    char ch[20];
	people * ptemp;//保存查找的结果

	while(1)
	{
	printf("\n**************欢迎使用通讯录***************\n");
	printf("\n  0-->退出\n  1-->显示\n  2-->添加\n  3-->查找\n  4-->删除\n  5-->排序\n  6-->修改\n  7-->清空\n  8-->文件\n");
	printf("\n*******************************************\n");
	printf("\n输入选择：");
	scanf("%d",&num);
	getchar();
	 switch(num)
	  {
		case 0:
			return 0;//退出
		case 1:
			if(count==0)
			{
			printf("\n无联系人！\n");
			printf("请先创建联系人!\n");
			head=creat(head);//创建联系人
			}
			printf("\n已有联系人\n");
			print(head);//输出联系人
			break;
		case 2:
			head=creat(head);//添加
			break;
		case 3:
			printf("\n查找结果：\n");
			if(head)//通讯录不为空
			{
			printf("输入查找的姓名：");
			scanf("%s",&ch);
			search(head,ch);
			}
			else
			printf("无联系人！\n");
			break;
		case 4:
			if(head)
			{
				printf("输入删除的姓名：");
				scanf("%s",&ch);
				ptemp=search(head,ch);

				if(ptemp)//通讯录中存在此人
				{
					char c;
					printf("\n是否删除?(Y or N)");
					getchar();
					scanf("%c",&c);
					if(c=='Y'||c=='y')
					{
					dete(ptemp);
					printf("\n删除成功！\n");
					}
				}
			    else
			    printf("\n无此联系人！\n");
			}
			else
			printf("无联系人！\n");
			break;
		case 5:
			if(count>0)
			{
				sorting(head);
				printf("\n排序成功！\n");
			}
			else
			printf("无联系人！\n");
			break;
		case 6:

			if(head)
			{
				printf("输入修改的姓名：");
				scanf("%s",&ch);
				ptemp=search(head,ch);

				if(ptemp)//通讯录中存在此人
				{
					char c;
					printf("\n是否修改?(Y or N)");
					getchar();
					scanf("%c",&c);
					if(c=='Y'||c=='y')
					{
					modify(ptemp);
					printf("\n修改成功！\n");
					}
				}
			    else
			    printf("\n无此联系人！\n");
			}
			else
			printf("无联系人！\n");
			break;
		case 7:
			if(head)
			{
				head=empty(head);
				printf("\n清空成功！\n");
			}
			else 
			printf("\n通讯录为空！\n");
			break;
		case 8:
			if(count==0)
			printf("\n无联系人！\n");
			else
			{
				pfile(head);
				printf("\n写入文件成功！\n");
			}
			break;
		default :
			printf("\nput eorr!\n");
		}
	}
	return 0;
}
