
/*
//ð���Ż���
#include<stdio.h>
#include<stdlib.h>

void change(int arr[],int sz);
void print(int arr[],int sz);

int main()
{
	int arr[]={1,3,6,5,7,9,8,4,21,96,50,78,89,65};
	int sz=sizeof(arr)/sizeof(arr[0]);
	print(arr,sz);
	change(arr,sz);
	print(arr,sz);
	system("pause");
	return 0;
}

void change_num(int *x,int *y)//����
{
	*x ^=*y;
	*y ^=*x;
	*x ^=*y;
}

void change(int arr[],int sz)
{
	int i=0;
	int j=0;
	int z=0;//����Ƿ��ź�

	for(i=0;i<sz-1;i++)
	{
		z=0;//�����ź�
		for(j=0;j<sz-1-i;j++)
		{
			if(arr[j]<arr[j+1])
			{
				change_num(&arr[j],&arr[j+1]);
				z=1;//δ�źã����ڽ���
			}
		}
		if(z==0)//ȷ���źã����κ��������н���
		break;
	}
}

void print(int arr[],int sz)//���
{
	int i=0;
	for(i=0;i<sz;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

*/



//1.һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ� 
// �ҳ����������֣����ʵ�֡� 

/*

#include<stdio.h>
#include<stdlib.h>

int search(int arr[],int sz);

int main()
{
	int arr[]={1,2,3,5,2,3,6,1,7,6,8,9,9};
	int sz=sizeof(arr)/sizeof(arr[0]);

	search(arr,sz);
	system("pause");
	return 0;
}

//��������ָ�룬һָ��ָ��������һָ�����������ǰ���б������ң�
//������ͬ������pָ���¸�����q���������ٲ��ң�ֱ����һ����������ͬ�ģ��򽫴��������
//���ѭ����ֱ��p������������������
int search(int arr[],int sz)
{
	int num=0;
	int *p=arr;//����ָ��ĳ����
	int *q=&arr[sz-1];//���ڶ�ĳ�����в����Ƿ�����ͬ��

	while(1)
	{
		q=&arr[sz-1];//q�����������бȽ�
		while(q!=arr)//δ�Ƚ���������
		{
			if(*p==*q&&p!=q)//������ͬ�Ҳ���ͬһλ�ã�ͬһ����
			{
				if(p==&arr[sz-1])//pָ�����һ�������˳�
				{
					return 0;
				}
				else//p��Ϊ���һ�����������¸����Ƚ�
				{
					p++;
					q=&arr[sz-1];
				}
			}
			else//������ͬ��qָ���¸����Ƚ�
				q--;
		}//q������һ������δ��p����ͬ��

		if(p!=q&&*p!=*q)//������ͬ
		{
		printf("%d \n",*p);
		}

		if(p==&arr[sz-1])//���������ѱȽ�
		{
			return 0;
		}
		else//��δ�Ƚ��꣬p �����¸����Ƚ�
		p++;
	}
}

*/

/*
//2.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ�����ʵ�֡� 
#include<stdio.h>
#include<stdlib.h>

int jisuan(int menioy);

int main()
{
	int menoy=0;
	int num=0;
	printf("����Ǯ����");
	scanf("%d",&menoy);
	num=jisuan(menoy);
	printf("%d \n",num);

	system("pause");
	return 0;
}

int jisuan(int menoy)
{
	int num=menoy;
	int n=menoy;

	while(num>1)//ʣ��ƿ������2ʱ����
	{
		n+=num/2;//����
		num=(num%2+num/2);//ʣ��ƿ��
	}
	return n;
}


*/


/*

//3.ģ��ʵ��strcpy 
//4.ģ��ʵ��strcat 

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

char * my_strcpy(char *ch, const char *ch1);//���ƺ���
char * my_strcat(char *ch, const char *ch2);//�ַ���ƴ�� ��ע��ch����ɴ洢��ch1������Խ��
char * my_strstr(const char *ch,const char *ch1);//�ж��Ӵ�

int main()
{
	char ch[20]={"abc123"};
	char ch1[]={"456"};
	char *ch2;

	my_strcpy(ch,"def");
	printf("���ƽ����%s \n",ch);

	my_strcat(ch,ch1);//ע��ch����ɴ洢��ch1������Խ��
	printf("ƴ�ӽ����%s \n",ch);

    printf("�жϽ����%s \n",my_strstr(ch,"f4"));
	system("pause");
	return 0;
}

char *my_strcpy(char *ch,const char *ch1)
{
	char  *srt=ch;
	assert(ch!=NULL);//���ԣ����
	assert(ch1!=NULL);
	while(*ch++=*ch1++)	;//����
	return srt;//����ch��ַ��������ʽ��Ӧ
}

char *my_strcat(char *ch,const char *ch2)//�ַ���ƴ��
{
    char *srt=ch;//������ʽ��Ӧ
	assert(ch);//�п�
	assert(ch2);

	while(*ch)//ʹchָ��'\0'
	{
		ch++;
	}
	while(*ch2)//��ch��'\0'��ƴ��
	{
		*ch=*ch2;
		ch++;
		ch2++;
	}
	return srt;
}

char * my_strstr(char *ch,const char *ch1)//�ж��ִ�
{
	assert(ch);//�п�
	assert(ch1);
	
	if(*ch1=='\0')
	  return NULL;

	while(*ch)
	{
		const char *start=ch;//startָ��ch(ԭ�ַ����еĵ�ǰ�ַ�)
	    const char *target=ch1;//targetһֱָ��Ƚ��ַ����ĵ�һ���ַ�
		//���Ƚϳɹ��ǣ������ַ���ͬ��ֱ��ch1='\0'������ѭ������ʱ��ch1='\0����
		//��������һ���ַ���ͬ��ch1���´ӵ�һ���ַ���ʼ�Ƚϣ�startλ�ò��䡣��

		while(*ch1)//ԭ�ַ���δ�ȽϽ���
		{
			if(*start==*target&&*start&&*target)//�ַ���ͬ������һ��Ϊ'\0'
			{
				start++; target++;//���бȽ��¸��ַ�
			}
			else//����ͬ������
				break;
		}
		
		if(*target=='\0')//�ַ�Ϊ'\0'���ȽϽ���
			return ch;//���Ӵ������ش��Ӵ�֮����ַ���

		ch++;//�����ַ����е��¸��ַ��Ƚϡ�
	}
	return NULL;//���Ƿ���NULL��0��
}

*/

/*

//1.ʹ��main�����Ĳ�����ʵ��һ��������������������Խ���������������һ��������-a��ѡ��ִ�мӷ�����-s��ѡ��ִ�м�������-m��ѡ��ִ�г˷�����-d��ѡ��ִ�г�����������������Ϊ�������� 
//���磺�����в������룺test.exe -a 1 2 
//ִ��1+2���3 
//


#include<stdio.h>
#include<assert.h>
#include<stdarg.h>
#include<stdlib.h>

int calculation(const char* ch,...);

int main()
{
	int a=0;
	int b=0;
	char ch[5];
	char *ch1=(char*)malloc(sizeof(char)*10);//ָ��������ڴ�ռ�����ڴ�ռ䣬��Ȼ����Ұָ��
	printf("���������:");
	//�ַ��������������
	//scanf("%s",&ch);//�������ɱ�ʾ��ַ���Կɼ�&��Ҳ�ɲ���
	//printf("%s\n",ch);
	scanf("%s",ch1);//ch1Ϊָ�룬�����ټ�&
	printf("������ֵ;");
	scanf("%d %d",&a,&b);
	printf("���룺%s %d %d \n",ch1,a,b);//������Ϊch1�����ɼ�*
	printf("��������%d \n",calculation(ch1,a,b));
	system("pause");
	return 0;
}


int calculation(const char* ch,...)
{
	int num=0;
	va_list arg;

	assert(ch);
	va_start(arg,ch);
	if(*ch=='-')
	{
		ch++;
		switch(*ch)
		{
		case 'a':
			num=va_arg(arg,int);
			return num+=va_arg(arg,int);
			break;
		case 's':
			num=va_arg(arg,int);
			return num-=va_arg(arg,int);
			break;
		case 'm':
			num=va_arg(arg,int);
			return num*=va_arg(arg,int);
			break;
		case 'd':
			num=va_arg(arg,int);
			return num/=va_arg(arg,int);
			break;
		}
	}
	else
		printf("eorr\n");
		va_end(arg);
	return NULL;
}


*/

/*

//2.дð����������������ַ����е��ַ���
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void sorting(char *ch[],int sz);

int main()
{
	char *ch[]={"125673","acb","DS12A","cba"};//����ָ���ŵĶ���ÿ���ַ����ĵ�ַ
	//sizeof(ch[0]),�������һ����ַ��ռ�ֽ�
	//sizeof(ch),ͳ�Ƶ������е�ַ��ռ���ֽ�����һ����ַռ4���ֽ�
	int sz=sizeof(ch)/sizeof(ch[0]);//�����ַ���������
	sorting(ch,4);
	printf("%d \n",sz);
//	printf("%s \n",*ch[3]);
	system("pause");
    return 0;
}


void sorting(char  *ch[],int sz)
{
	int i=0;
	int j=0;
	int n=3;

	char *ch2="3210";
	char *ch1="3210";//char * ֱ��ָ�����ֳ��������ɸ�ֵ����ֵ�󲻿��޸ģ�
	 //*ch1="123";//���ֳ��������ݲ����޸ģ�ch������ֳ������д���ַ����ĵ�ַ
	//&ch������ַ��ջ�У�chΪ���ֳ������ĵ�ַ��ÿ���������ֳ������ĵ�ַ������
	//char *���Ͷ���ı�����������ͬ�����ַ��ͬ����ֻ��һ�����ݡ����������͵�ַ���ǲ�ͬ�ģ���������
	char ch[]="123";//ch��ַ��ջ�У���ַ��ŵ����ַ�����123\0�������޸�
	ch[0]='3';

	int *a;*a=1;//a���ָ��ջ�е�ĳһ��ַ�����ڴ�ռ䣬ΪҰָ�룬���ڴ�ռ䲻�ɸ�ֵ

	int *b;//b���ָ��ջ�е�ĳһ��ַ�����ڴ�ռ䣬ΪҰָ��
	b=(int *)malloc (sizeof(int)*3)//Ϊb�����ڴ�ռ�
	*b=1;//���ڴ�ռ�ɸ�ֵ
	
	//a=(int*)malloc(100);
	//*a=12;
	//*a=13;
	// n=strlen(ch1);
 //      for(i=0;i<n;i++)
	//	{
	//		for(j=0;j<n-i-1;j++)
	//		{
	//			if(ch1[j]>ch1[j+1])
	//			{
	//				ch1[j] ^=ch1[j+1];
	//				ch1[j+1] ^=ch1[j];
	//				ch1[j] ^=ch1[j+1];
	//			}
	//		}
	//	}
	   printf("%s \n",ch1);
}

//
//void sorting(char  *ch[],int sz)
//{
//	char temp;
//	int i=0;
//	int n=0;
//	char *ch1="321";
//	char ch3;
//	int j=0;
//	//ch1=ch[3];
//	//printf("%s \n",ch1);
//	while(sz)
//	{
//	    //ch1=ch[sz-1];
//		printf("%d \n",strlen(ch1));
//		n=strlen(ch1);
//		temp=ch1[1];
//
//		for(i=0;i<n;i++)
//		{
//			for(j=0;j<n-i-1;j++)
//			{
//				/*if(temp<ch1[j])
//				{
//					temp=ch1[j];
//					ch1[j]=ch1[j+1];
//					ch1[j+1]=temp;
//				}*/
//				if(ch1[j]>ch1[j+1])
//				{
//					ch1[j] ^=ch1[j+1];
//					ch1[j+1] ^=ch1[j];
//					ch1[j] ^=ch1[j+1];
//				}
//			}
//		}
//	//	{
//	//			 /*  *ch1 ^=*++ch1;
//	//			   *ch1 ^=*--ch1;
//	//			   *ch1 ^=*++ch1;
//	//*/
//	//			}
//	//			ch1--;
//	//		}
//	//		//ch1++;
//	//	//ch1=ch[sz-1];
//		printf("%s \n",ch1);
//		sz--;
//	}
//}





/*
//
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void arr_bubble_sort(char(*p)[10],const int sz)//����ָ�룬��ָ���СΪ10�������ָ��
{
     int i = 0;
     int j = 0;
	 char *temp;

	 temp=(char*)malloc (sizeof(char)*100);//Ϊtemp�����ڴ�ռ�
	 for(j=0;j<sz;j++)
	 {
		 for(i=0;i<sz-j-1;i++)
		 {
			 if (strcmp(p[i], p[i+1])>0)//ʹ���ַ����ȽϺ��������бȽϣ�����
			 {
				  strcpy(temp, p[i]);//ʹ���ַ������ƺ����������ַ�������
				  strcpy(p[i],p[i+1]);
				  strcpy(p[i+1], temp);
			 }
		 }
	 }
	 free(temp);  
}
int main()
{
	 int i=0;
     char ch[3][10] = { "adacd", "aaers", "baiu" };
     //sizeof(ch[0]),�������һ����ַ��ռ�ֽ�
	//sizeof(ch),ͳ�Ƶ������е�ַ��ռ���ֽ�����һ����ַռ4���ֽ�
	int sz=sizeof(ch)/sizeof(ch[0]);//�����ַ���������

     arr_bubble_sort(ch,sz);
     for (i = 0; i < sz; i++)
     {
        printf("%s\n", ch[i]);//�������
     }
     system("pause");
     return 0;
}

*/
//
//#include<stdio.h>
//#include<stdlib.h>
//#define D(x) x+x
//
//int (*foo(int(*a)[3]))[3]
//{
//	return ++a;
//}
//
//int main()
//{
//	char *a[]={"123","321","abc","dbf"};
//	char *s="\ta\x0f0g";
//	char *p="abcd";
//	int i=0;
//	/*int j=i++;
//	int w[2][3]={1,2,3,4,5,6};
//	int (*pw) [3];
//	int a[3][3]={2,-1,3,4,8,1,20,7,6};
//	int (*p)[3]=foo(a);
//	void *q=malloc(100);
//	printf("%d\n",sizeof(q));
//	printf("\n\n %d \n\n",*1[p]);*/
//
//	//pw=w;
//	//printf("%d\n",*(pw+1)[2]);
//	//printf("%d\n",*(pw[1]+2));
//	//while((i>j++)&&(i++==j))
//	//{
//	//	i+=j;
//	//}
//	//printf("\n %d \n",i);
//	for(;*s!='\0';s++)
//	{
//		i++;
//		printf("%d\n",i);
//	}
//	/*printf("%d\n",sizeof(p));
//	printf("%p \n",a[2]);
//	printf("%d\n",5*D(2+3));*/
//	system("pause");
//	return 0;
//}

//�ڴ����
#include<stdio.h>
#include<stdlib.h>
#define value(Structure,Field) ((unsigned int )&(((Structure*)0)->Field))//��0ת�ɵ�ַ
typedef struct //0ת�ɵ�ַ��ṹ���ַ��0��ʼ
	{
		short a;//shortռ2���ֽڣ�����2����
		char b;//charռһ���ֽ� 1<2 ��2�������ַΪ3
		char* c;//char*ռ4���ֽڣ�4>2 ��4���룬ԭ��Ϊ3+4=7,��4���룬��4�ı�����Ϊ8
		long (*d)[3];//longռ4���ֽڣ�4==4���Ķ��룬8+4=12��4�ı���
		float e;//��eʱ��Ϊ12
	}init;

int main()
{
	printf("%d", value(init,e));//12
	system("PAUSE");
	return 0;
}