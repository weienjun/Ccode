


//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//void pointer_arr(char **ch);//ָ�����飬�����飬�洢���ǣ�ָ�루��ַ��
//
//void test (char **ptr)
//{
//	printf("%c \n",**ptr);
//}
//
//int main()
//{
//	//�����е����ݿ��޸�
//	//һά���飬�±��ʾ�ɴ��ַ�����
//	char arr1[3]={'1','2','3'};
//
//	//��ά���飬��һ���±��ʾ�ַ����������ڶ����±��ʾ�ַ������ȣ��ַ���ĩβ������'\0'��
//	//���Σ�//void arr(char (*arr)[3])
//            //void arr(char arr[][3])
//	char arr2[2][4]={"123","456"};
//
//	//char*���͵��ַ������������ֳ���������ch��ַΪ���ֳ������ĵ�ַ��
//	//���ֳ������������ڱ���ʱ����ȷ�������ɸ��ġ���ch���ַ��������޸�
//	//ֻ�� char *���Ϳ��ڶ���ʱֱ�ӳ�ʼ������ char * ch="123456";�� int * num=5;������ΪnumΪҰָ��
//	//ch[0]=*p='1'; *++p=ch[1]='2'...ch[6]='\0'
//	// ע������ǰ��ch��ַ����ch[0]��Ȼ������������ch[2]������һ��������ʼ��ַ����
//	char * ch=NULL;//chδ�����ڴ�ռ䣬�Ǹ�Ұָ�룬���ɸ�ֵ
//
//	char * arrp[2]={"100","456"};
//	//arrp[0]��ʾ��һ���ַ����ĵ�ַ��arrp[1]��ʾ�ڶ����ַ����ĵ�ַ
//	//*arrp[0]��ʾȡ��һ���ַ�����ַ�е��ַ�������һ���ַ�'1',*arrp[1]��ʾȡ�ڶ����ַ�����һ���ַ�'4'
//	//ע��arrp[0]�Ǵ��������ַ����ĵ�ַ�������Ǵ����һ���ַ���ַ����ַ��ͬ�����岻ͬ
//	//arr[i]+j��ʾ��i+1���ַ����еĵ�j+1���ַ��ĵ�ַ  *(arr[1]+1)��ȡ�ڶ����ַ����еڶ����ַ�(5)
//	//char * arrp[2]={"100","456"};
//
//	//���ú��������ڴ�ռ���䣬����Ϊ����ch��ַ�ĵ�ַ��������ch,
//	//���Ƹı�ĳ������������Ǳ����ĵ�ַ�������Ǳ�����һ��
//
//	char * arrr[10]={"789"};
//	test(arrr);
//
//	pointer_arr(&ch);
//	ch="123456";
//
//	printf("%s \n",ch);//123456
//	printf("%c \n",*++ch);//2
//	printf("%c \n",ch[2]);//4 ע���ӽ�h��ǰ�ĵ�ַ����ch[0]��Ȼ������������ch[2]
//	
//	printf("%s \n",arrp[0]);
//	printf("%d \n",strlen(arrp[0]));
//	printf("%s \n",arrp[1]);
//	printf("%s \n",(arrp[0]+1));//arrp[0]+1��ʾ��һ���ַ����еĵڶ����ַ��ĵ�ַ
//	printf("%c \n",*(arrp[1]+2));
//	system("pause");
//	return 0;
//}
//
//
//void pointer_arr(char **ch)//ʹ�ú���Ϊָ������ڴ�ռ�
//{
//	*ch=(char*)malloc(sizeof(char)*100);
//}



/*
//����ָ������
#include<stdio.h>
#include<stdlib.h>

int add(int x,int y);//���������뺯��ָ�����鷵��������ͬ
int sub(int x,int y);//�Ӻ���������Ҫ�ں���ָ������֮ǰ
//����int�ͣ�������(*pointer[]),����������Ӻ���(�ֱ�Ϊadd,sub,0δ��)������Ϊ����int��,�����Ӻ���
int (*pointer[3])(int x,int y)={0,add,sub};//����ָ�����飬��д�˺�����ʵ��

int main()
{
	int x=0;
	int y=0;
	int  num=0;//ѡ�������±�ѡ��
	int ret=0;//������

	printf("����ѡ��(0->�˳���1->�ӣ�2->��);");
	scanf("%d",&num);
	while(num)
	{
		printf("����������:");
		scanf("%d %d",&x,&y);
		ret=(*pointer[num])(x,y);//numΪ�����±�ѡ��
		printf("�����%d\n",ret);
		break;
	}
	system("pause");
	return 0;
}

int add(int x,int y)
{
	return x+y;
}

int sub(int x,int y)
{
	return x-y;
}

*/

/*

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int num[3]={1,2,3};
	char arr[2][3]={"12","ab"};
	//int num[3]={1,2,3};
	int *p=((int *)((int)arr));
	

	printf("%p \n",arr);
	printf("%p \n",&arr[0][1]);
	printf("%p \n",&arr[0][2]);
	printf("%p \n",arr+1);
	printf("%d \n",*p);
	printf("%p \n",p);
	printf("%p \n",&arr[1][2]);
	printf("%p\n",&arr+1);
	printf("%p \n",num);
	printf("%s\n",arr+1);
	printf("%p \n",&p);
	system("pause");
	return  0;
}

*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	char *c[]={"ENTER","NEW","POINT","FIRST"};
	char **cp[]={c+3,c+2,c+1,c};
	char *** cpp=cp;
	printf("%s\n",**cp+1);
	printf("%s\n",**cpp);
	printf("%s\n",*cp[1]);
	printf("%c\n",cp[0][0]);
	printf("%s\n",cpp[0][0]);
	printf("%s\n",**++cpp);
	
	system("pause");
	return 0;
}