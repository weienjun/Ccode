#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Test.h"

category cay;

void Trf(FILE * pfi,FILE * pfo)//�ж�
{
	cay=txt;//����Ϊ�ı�
	while(cay != eof) //��Ϊ�ļ���β
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
			default ://�ı�
				ftxt(pfi,pfo);
				break;
		}
	}
}

void ftxt(FILE * pfi,FILE * pfo)//�ı�����
{
	int ch=fgetc(pfi);
	switch(ch)
	{
	case '/':
		{
			int ch2=fgetc(pfi);// ��ȡ/�ĺ�һ���ַ�
			switch(ch2)//����
			{
			case '/'://  ����//
				fputc('/',pfo);//д��/
				fputc('/',pfo);//д��/
		      //  cay=txt;//�����ı�ģʽ
				cay=cpp;//�˻�cpp
				break;
			case '*': // ����/*
				fputc('/',pfo);//д��/
				fputc('/',pfo);//д��/
				cay=c; //�˻�c
				break;
			default :// һ��/
				fputc('/',pfo);//д��/
				ungetc(ch2,pfi);//�˻���һ��������д���/�Ḳ�Ǻ�һ���ַ�
				cay=cpp; //�˻�cpp
				break;
			}
		}
		break;
	case EOF:
		cay=eof;//����
		break;
	default ://�ı�
		fputc(ch,pfo);//д��
		cay=txt; //�˻��ı�
		break;
	}
}

void fcpp(FILE * pfi,FILE * pfo)//cpp����
{
	int ch1=fgetc(pfi);
	switch(ch1)
	{
	case '\n'://ע�ͣ�����
		fputc('\n',pfo);
		fputs("//",pfo);
		cay=txt;//һ��ע�ͽ����������ı�ģʽ
		break;
	case EOF:
	    cay=eof;
		break;
	default://�ַ�����
		fputc(ch1,pfo);
		cay=txt; //�˻�txt
		break;
	}
}

void fc(FILE * pfi,FILE * pfo)//c����
{
	int ch1=fgetc(pfi);
	switch(ch1)
	{
	case '\n'://���к�ע��
		fputc('\n',pfo);
		fputs("//",pfo);
		cay=c; //����c
		break;
	case '*':
		{
			int ch2=fgetc(pfi);
			switch(ch2)
			{
	           case '/':// ����*/
				   {
					   int ch3=fgetc(pfi);//�жϺ��Ƿ��з�ע�����
					   if(ch3 != '\n')//���з�ע����䣬���û��л�ԭ
					   {
						   fputc('\n',pfo); 
						   fputc(ch3,pfo);
					   }
					   else //������䣬����
						  fputc('\n',pfo); 
				   }
				   cay=txt;//����txtģʽ��*/����ע��
				   break;
			   case EOF:
				   cay=eof;
				   break;
			   default :// ֻ��һ��/
				   fputc(ch2,pfo);
				   cay=c;//����c
				   break;
			}
		}
		break;
	case EOF:
		cay=eof;
		break;
	default ://��ȡ�ַ�����
		fputc(ch1,pfo);
		cay=c;
		break;
	}
}

void fname(const char address[],int size)//���ļ���
{
	char name[N];
	int i=0;
	int j=0;
	int n=0;//ѭ������

	while(address[size] !='\\')
	{
		if(i>19)
		{
		 printf("eorr!\n");
		 exit(0);//��ֹ����
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

//int menu(char address1[],char address2[],FILE * pfi,FILE * pfo)//��ӡ�˵�
void menu(void)
{
	int num=0;
	FILE * pfi=NULL;
    FILE * pfo=NULL;
	char address1[MAX_SIZE];//�ļ�·��
	char address2[MAX_SIZE];//�ļ�·��

	while(1)
	{
		printf("\n0-->�˳�  1-->ע��ת��  2-->���ע��  3-->ȡ��ע��  4-->����\n");

		printf("\n����ѡ��");
		scanf("%d",&num);
		if(! num)//����0���˳�
			return ;
		printf("\n����Ҫת���ļ���·����");
	    scanf("%s",address1);

		pfi=pand(pfi,address1,"r");
		if(pfi == NULL)//��ʧ��
			continue;

		printf("\n����Ҫ����ת���ļ���·����");
	    scanf("%s",address2);
		pfo=pand(pfi,address2,"wt");
		if(pfo==NULL)//��ʧ��
			continue;

		switch(num)
		{
		case 0:
			return ;
			break;
		case 1:
		    print(address1,address2);
	        Trf(pfi,pfo);
			printf("\nת����ɣ�\n");
			break;
		case 2:
			print(address1,address2);
			xcpp(pfi,pfo);
			printf("\nת����ɣ�\n");
			break;
		case 3:
			print(address1,address2);
			fcancel(pfi,pfo);
			printf("\nת����ɣ�\n");
			break;
		case 4:
			print(address1,address2);
			fcopy(pfi,pfo);
			printf("\nת����ɣ�\n");
			break;
		default :
			printf("\n�������\n");
		}
		fclose(pfi);
	    fclose(pfo);
		printf("\n***************************************************\n");
	}
}

void boss(char address1[],char address2[])//��ʼ
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

void print(const char address1[],const char address2[])//���
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

void xcpp(FILE * pfi,FILE * pfo)//ѡ��ע��
{
	int m=0;
	int n=0;
	int i=1;
	int ch=0;

	printf("������ʼ���������:");
	scanf("%d%d",&m,&n);
	//���Ʋ�����ע��ǰ����
	while(i < m)
	{
		ch=fgetc(pfi);
		fputc(ch,pfo);
		if(ch=='\n')
			i++;
	}

	//����ע�͵�m��
	ch=fgetc(pfi);
	if(m&&ch!=EOF)
	{
		fputs("//",pfo);
	}
	ungetc(ch,pfi);
	//����ע��
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
	//���Ʋ�����ע�ͺ󲿷�
	while( ch !=EOF)
	{
		ch=fgetc(pfi);
		fputc(ch,pfo);
	}

}

void fcopy(FILE * pfi,FILE * pfo)//����
{
  	int ch;
	ch=fgetc(pfi);
	while(ch != EOF )
	{
	fputc(ch,pfo);
	ch=fgetc(pfi);
	}
}

void fcancel(FILE * pfi,FILE * pfo)//ȡ��ע��
{
	int m=0;
	int n=0;
	int i=1;
	int ch=0;
	
	printf("������ʼ���������:");
	scanf("%d%d",&m,&n);

	if(n==0)
		return ;

	if(m>1)//���ڻ����m��m!=1����ע�ͣ����Դ˴��������ִ���
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
				case '/'://  ����//
					{
						int ch3=fgetc(pfi);	//����//�������		
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
					fputc(ch2,pfo);//д��/����
					return ;
					break;
				case '\n':
					fputc('/',pfo);//д��/
			        fputc('\n',pfo);//����
			        m++;
			        break;
				default :// ֻ��һ��/ ��Ϊ�����ַ�
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

FILE* pand(FILE * pf,char address[],char* fa)//�ж�·��
{
	pf=fopen(address,fa);
	if(pf==NULL)
	{
		printf("eorr!\n");
		return NULL;
	}
	return pf;
}