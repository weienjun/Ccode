#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Test.h"

category cay;

void Trf(FILE * pfi,FILE * pfo)//判断
{
	cay=txt;//假设为文本
	while(cay != eof) //不为文件结尾
	{
		switch(cay)
		{
			case c://c
				fc(pfi,pfo);
				break;
			case cpp://c++
				fcpp(pfi,pfo);
				break;
			case eof://EOF
				break;
			default ://文本
				ftxt(pfi,pfo);
				break;
		}
	}
}

void ftxt(FILE * pfi,FILE * pfo)//文本操作
{
	int ch=fgetc(pfi);
	switch(ch)
	{
	case '/':
		{
			int ch2=fgetc(pfi);// 获取/的后一个字符
			switch(ch2)//分类
			{
			case '/'://  连续//
				fputc('/',pfo);//写入/
				fputc('/',pfo);//写入/
		      //  cay=txt;//进入文本模式
				cay=cpp;//退回cpp
				break;
			case '*': // 连续/*
				fputc('/',pfo);//写入/
				fputc('/',pfo);//写入/
				cay=c; //退回c
				break;
			default :// 一个/
				fputc('/',pfo);//写入/
				ungetc(ch2,pfi);//退回上一个，否则写入的/会覆盖后一个字符
				cay=cpp; //退回cpp
				break;
			}
		}
		break;
	case EOF:
		cay=eof;//结束
		break;
	default ://文本
		fputc(ch,pfo);//写入
		cay=txt; //退回文本
		break;
	}
}

void fcpp(FILE * pfi,FILE * pfo)//cpp操作
{
	int ch1=fgetc(pfi);
	switch(ch1)
	{
	case '\n'://注释，换行
		fputc('\n',pfo);
		fputs("//",pfo);
		cay=txt;//一行注释结束，进入文本模式
		break;
	case EOF:
	    cay=eof;
		break;
	default://字符复制
		fputc(ch1,pfo);
		cay=txt; //退回txt
		break;
	}
}

void fc(FILE * pfi,FILE * pfo)//c操作
{
	int ch1=fgetc(pfi);
	switch(ch1)
	{
	case '\n'://换行和注释
		fputc('\n',pfo);
		fputs("//",pfo);
		cay=c; //保持c
		break;
	case '*':
		{
			int ch2=fgetc(pfi);
			switch(ch2)
			{
	           case '/':// 连续*/
				   {
					   int ch3=fgetc(pfi);//判断后是否有非注释语句
					   if(ch3 != '\n')//后有非注释语句，采用换行还原
					   {
						   fputc('\n',pfo); 
						   fputc(ch3,pfo);
					   }
					   else //后无语句，换行
						  fputc('\n',pfo); 
				   }
				   cay=txt;//进入txt模式，*/结束注释
				   break;
			   case EOF:
				   cay=eof;
				   break;
			   default :// 只有一个/
				   fputc(ch2,pfo);
				   cay=c;//保持c
				   break;
			}
		}
		break;
	case EOF:
		cay=eof;
		break;
	default ://获取字符复制
		fputc(ch1,pfo);
		cay=c;
		break;
	}
}

void fname(const char address[],int size)//求文件名
{
	char name[N];
	int i=0;
	int j=0;
	int n=0;//循环控制

	while(address[size] !='\\')
	{
		if(i>19)
		{
		 printf("eorr!\n");
		 exit(0);//终止进程
		}
		name[N-1-i]=address[size];
		i++;size--;
	}

	n = --i;
    while(j<=i)
	{
		name[j]=name[N-1-n];
		j++;n--;
	}
	printf("%s",name);
}

//int menu(char address1[],char address2[],FILE * pfi,FILE * pfo)//打印菜单
void menu(void)
{
	int num=0;
	FILE * pfi=NULL;
    FILE * pfo=NULL;
	char address1[MAX_SIZE];//文件路径
	char address2[MAX_SIZE];//文件路径

	while(1)
	{
		printf("\n0-->退出  1-->注释转换  2-->添加注释  3-->取消注释  4-->复制\n");

		printf("\n输入选择：");
		scanf("%d",&num);
		if(! num)//输入0，退出
			return ;
		printf("\n输入要转化文件的路径：");
	    scanf("%s",address1);

		pfi=pand(pfi,address1,"r");
		if(pfi == NULL)//打开失败
			continue;

		printf("\n输入要保存转化文件的路径：");
	    scanf("%s",address2);
		pfo=pand(pfi,address2,"wt");
		if(pfo==NULL)//打开失败
			continue;

		switch(num)
		{
		case 0:
			return ;
			break;
		case 1:
		    print(address1,address2);
	        Trf(pfi,pfo);
			printf("\n转化完成！\n");
			break;
		case 2:
			print(address1,address2);
			xcpp(pfi,pfo);
			printf("\n转化完成！\n");
			break;
		case 3:
			print(address1,address2);
			fcancel(pfi,pfo);
			printf("\n转化完成！\n");
			break;
		case 4:
			print(address1,address2);
			fcopy(pfi,pfo);
			printf("\n转化完成！\n");
			break;
		default :
			printf("\n输入错误！\n");
		}
		fclose(pfi);
	    fclose(pfo);
		printf("\n***************************************************\n");
	}
}

void boss(char address1[],char address2[])//开始
{
	FILE * pfi;
    FILE * pfo;

	pfi=fopen(address1,"r");
	if(pfi==NULL)
	{
		printf("eorr!\n");
		exit(0);
	}

	pfo=fopen(address2,"wt");
	if(pfi==NULL)
	{
		printf("eorr!\n");
		exit(0);
	}
	print(address1,address2);
	Trf(pfi,pfo);

	fclose(pfi);
	fclose(pfo);
}

void print(const char address1[],const char address2[])//输出
{
	int i=0;
	
	printf("\n");
	fname(address1,strlen(address1));
	printf("  |");
	for(i=0;i<10;i++)
	{
		printf(">");
	}
	printf("|  ");
	fname(address2,strlen(address2));
	printf("\n");
}

void xcpp(FILE * pfi,FILE * pfo)//选择注释
{
	int m=0;
	int n=0;
	int i=1;
	int ch=0;

	printf("输入起始行与结束行:");
	scanf("%d%d",&m,&n);
	//复制不处理注释前部分
	while(i < m)
	{
		ch=fgetc(pfi);
		fputc(ch,pfo);
		if(ch=='\n')
			i++;
	}

	//处理注释的m行
	ch=fgetc(pfi);
	if(m&&ch!=EOF)
	{
		fputs("//",pfo);
	}
	ungetc(ch,pfi);
	//处理注释
	while(m < n)
	{
		ch=fgetc(pfi);
		switch(ch)
		{
		case '\n':
			fputc('\n',pfo);
			fputs("//",pfo);
			m++;
			break;
		case EOF:
			return ;
			break;
		default:
			fputc(ch,pfo);
			break;
		}
	}
	//复制不处理注释后部分
	while( ch !=EOF)
	{
		ch=fgetc(pfi);
		fputc(ch,pfo);
	}

}

void fcopy(FILE * pfi,FILE * pfo)//复制
{
  	int ch;
	ch=fgetc(pfi);
	while(ch != EOF )
	{
	fputc(ch,pfo);
	ch=fgetc(pfi);
	}
}

void fcancel(FILE * pfi,FILE * pfo)//取消注释
{
	int m=0;
	int n=0;
	int i=1;
	int ch=0;
	
	printf("输入起始行与结束行:");
	scanf("%d%d",&m,&n);

	if(n==0)
		return ;

	if(m>1)//由于会忽略m（m!=1）行注释，所以此处进行区分处理
	{
		i++;
		n++;
	}
	while(i < m)
	{
		if(ch==EOF)
			return;
	    if(ch =='\n')
		{
			i++;
		}
		ch=fgetc(pfi);
		fputc(ch,pfo);
	}
	
	while(m <= n)
	{
		ch=fgetc(pfi);
		switch(ch)
		{
		case '/':
			{
				int ch2=fgetc(pfi);
				switch(ch2)
				{
				case '/'://  连续//
					{
						int ch3=fgetc(pfi);	//复制//后的内容		
						while(ch3 !='\n')
						{
						 if(ch3 == EOF)
						 return ;
		                 fputc(ch3,pfo);
						 ch3=fgetc(pfi);
						}
						 fputc('\n',pfo);
						m++;
					}
					break;
				case EOF:
					fputc(ch2,pfo);//写入/结束
					return ;
					break;
				case '\n':
					fputc('/',pfo);//写入/
			        fputc('\n',pfo);//换行
			        m++;
			        break;
				default :// 只有一个/ 后为其它字符
					 fputc('/',pfo);
					 fputc(ch2,pfo);
					break;
				}
			}
			break;
		case '\n':
			fputc('\n',pfo);
			m++;
			break;
		case EOF:
			return ;
			break;
		default:
			fputc(ch,pfo);
			break;
		}
	}

	while( ch !=EOF)
	{
		ch=fgetc(pfi);
		fputc(ch,pfo);
	}
}

FILE* pand(FILE * pf,char address[],char* fa)//判断路径
{
	pf=fopen(address,fa);
	if(pf==NULL)
	{
		printf("eorr!\n");
		return NULL;
	}
	return pf;
}