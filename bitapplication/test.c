/*
//�����Ƽ�żλ����˼·��
//1��ȡ���е�����λ����ż��λΪ0��Ȼ������1λ����ʱ��������λ����Ϊż��λ
//2��ȡ���е�ż��λ��������λΪ0��Ȼ������1λ����ʱ����ż��λ����Ϊ����λ
// & 0x5555 5555=0101 0101 0101 0101 0101 0101 0101 0101 ��ȡ���е�����λ��
// & 0xAAAA AAAA=1010 1010 1010 1010 1010 1010 1010 1010 ��ȡ���е�ż��λ��

#include<stdio.h>
#include<stdlib.h>
#define CHANGE(num)\
(((num&(0x55555555))<<1)|((num&(0xAAAAAAAA))>>1))//��������żλ����

int main()
{
	int i=0;
	int n=2;
	int num=5;//����������

	
	printf("�ı�ǰλΪ\n");
	for(i=31;i>=0;i--)//�Ӹ�λ����λ���������λ
	{
		printf("%d ",num>>i&1);
	}
	
	num=CHANGE(num);
	printf("\n�ı��λΪ\n");
	for(i=31;i>=0;i--)//���������ÿһλ
	{
		printf("%d ",num>>i&1);
	}

	system("pause");
	return 0;
}

*/

//1.��д������ 
//unsigned int reverse_bit(unsigned int value); 
//��������ķ���ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ�� 
//
//�磺 
//��32λ������25���ֵ�������и�λ�� 
//00000000000000000000000000011001 
//��ת�󣺣�2550136832�� 
//10011000000000000000000000000000 
//���������أ� 
//2550136832 

/*

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int change(int unsigned num)
{
	int i=0;
    int num1=0;
	int bit=0;

	for(i=0;i<32;i++)
	{   
		bit=num>>i&1;//ȡ������λ�����͵��ߵ�˳��ȡ
		num1=(num1+bit*pow(2.0,31-i));//������ȡ��ÿλ��ת���ֵ�������
	}
	return num1;
}

int main()
{
	int unsigned num=0;
	printf("��������: ");
	scanf("%d",&num);
	printf("��ת��%u\n",change(num));
	system("pause");
	return 0;
}

*/

/*

//2.��ʹ�ã�a+b��/2���ַ�ʽ������������ƽ��ֵ��
#include<stdio.h>
#include<stdlib.h>

int averge(const int num1,const int num2)
{
	//ע��num1+(num2-num1>>1)num��˳�򲻿�д������num1+(num1-num2>>1)����
	return num1+((num2-num1)>>1);//��λֻ��Ϊ��������
	//return (num1&num2)+((num1^num2)>>1);//������ͬ���ּ��ϲ�ͬ���ֵ�һ�룬��Ϊ������ƽ��ֵ
}
int main()
{
	int num1=0;
	int num2=0;
	printf("����������ֵ��");
	scanf("%d %d",&num1,&num2);
	printf("ƽ��ֵΪ%d\n",averge(num1,num2));
	
    system("pause");
    return 0;	
}

*/

/*

//3.���ʵ�֣� 
//һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ� 
//���ҳ�������֡���ʹ��λ���㣩 
#include<stdio.h>
#include<stdlib.h>
#define N 100 //��������඼��Nλ

int search( int num)
{
	int num2=0;
	int i=0;//�����±�
	int num1[N]={0};

	while(num)//�������ֲ�ֳɶ����
	{
		num1[i]=num%10;
		num=num/10;
		i++;
		
	}
	num2=num1[0];
	for(i=1;i<N;i++)
	{
		//����a^a=0; 0^a=a; ��������ʣ����Ǹ�������һ����������
		num2=num2^num1[i];
	}
	return num2;
}

int main()
{
	int num=243545020;
	printf("�����γ�������%d\n",search(num));
	system("pause");
	return 0;
}

*/

/*

//����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ�� 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int compare(int num1,int num2 );
int main()
{
	int num1=0;
	int num2=0;
	int count=0;

	printf("��������num1:");
	scanf("%d",&num1);
	printf("��������num2:");
	scanf("%d",&num2);

	count=compare(num1,num2);
	printf("��%dλ��ͬ\n",count);

	system("pause");
	return 0;
}

int compare(int num1,int num2)
{
   int i=0;
   int n=0;
   //��֤Ϊ�����Ƚϣ�������洢���Ƕ����ƵĲ��룬��������=ԭ�룬��������=ԭ��ȡ��+1
  // num1=sqrt(pow(num1,2.0));//sqrt�����ź�����qow�η�����
   //num2=sqrt(pow(num2,2.0));

   for(i=0;i<32;i++)
   {
	   if(((num1>>i)&1)!=((num2>>i)&1))//�Ƚ�λ�Ƿ���ͬ
		   n++;
   }
   return n;
}


*/

/*

//��������Ƶ�ÿһλ��ͳ���ж���λΪ1

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int num=0;
	int count =0;
	int i=0;

	printf("������ֵ��");
	scanf("%d",&num);

	for(i=31;i>=0;i--)//���ÿһλ
	{
	   printf("%d ",(num>>i)&1);
	}

	while(num)//ͳ��1��
	{
	num&=(num-1);
	count ++;
	}
	printf("\n Ϊһ����%dλ\n",count );
	system("pause");
	return 0;
}


*/


//4. 
//��һ���ַ����������Ϊ:"student a am i",���㽫��������ݸ�Ϊ"i am a student". 
//Ҫ�� 
//����ʹ�ÿ⺯����ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ��� 

/*

#include <stdio.h>
#include<stdlib.h>

char* word_reversal(char* str);
char* char_reversal(char ch[],const int sz);

char* char_reversal(char ch[],const int sz)//�ַ�����ת
{
	int i=0;

	for(i=0;i<sz/2;i++)
	{
		ch[i]=ch[i]^ch[sz-i-1];//ĩβ'\0'���ɷ�ת������-1
		ch[sz-i-1]=ch[i]^ch[sz-i-1];
		ch[i]=ch[i]^ch[sz-i-1];
	}
   
	word_reversal(ch);//���ʷ�ת
}

char* word_reversal(char* str)
{
	//pi,p2ָ���ַ������׵�ַ
	char *p1=str;
	char *p2=str;
	char *p=NULL;
    
    while(*p2 != '\0')//��Ϊ�ַ�������λ��
    {
		//ʹp2ָ�򵥴ʵ�����Ǹ��ַ��ĵ�ַ
        while(*p2 != ' ' && *p2 != '\0')//��Ϊ�ո�,�Ҳ�Ϊ�ַ�����β
        {   
            p2++;
        }
       
	    p = p2;//����������Ǹ��ַ��ĵ�ַ����ֵ��p
		//ÿ�������е��ַ�����λ�ý�����ǰ��󽻻�
        while(p1 < p2-1)//p1ָ�򵥴ʵĵ�һ���ַ���ַ��p2ָ�򵥴ʵ����һ���ַ���ַ
        {
		    //char tmp = *p1;
            //*p1 = *(p2-1);
            //*(p2-1) = tmp;

		    *p1=*p1^*(p2-1);
			*(p2-1)=*p1^*(p2-1);
			*p1=*p1^*(p2-1);
            p1++;//p1ָ����һ���ַ���ַ
            p2--;//p2ָ����һ���ַ���ַ
        }
        
        if(*p == '\0')//�����ַ�����β�������еĵ��ʶ��ѷ�ת
        {
            return str;//�˳�
        }
        p1 = p+1;//p1ָ����һ�����ʵĵ�һ���ַ���ַ
        p2 = p+1;//p2ָ����һ�����ʵĵ�һ���ַ���ַ
    }
	return str;//�˳�
}

int main ()
{
    char ch[] = "student a am i";
	int sz=sizeof(ch)/sizeof(ch[0])-1;//�����ַ�������������'\0'
    char *ret = char_reversal(ch,sz);
    printf("%s\n",ret);
	system("pause");
    return 0;
}


*/

/*
//2

#include <stdio.h>
#include<stdlib.h>

char* word_reversal(char* str);

char * char_reversal(char *str)
{
	char *p1=str;//ָ��p1ָ��str���׵�ַ
    char *p2 = str;//ָ��p2ָ��str
   // char *p;//ָ��p
     
    while(*p2 != '\0')//p2ָ��\0
    {
        p2++;
    }
    //�����ַ����巴ת��ע��'\0'λ��δ�ı�
    while(p1 < p2-1)//p1��ָ������Ǹ��ַ���ַ
    {
        char tmp = *p1;//temp���浱ǰp1���ַ�
        *p1 = *(p2-1);//ǰһ���ַ������ĵ�ַ����
        *(p2-1) = tmp;
        p1++;//p1ָ����һ���ַ��ĵ�ַ
        p2--;//p2ָ����һ���ַ��ĵ�ַ
    }
    
	word_reversal(str);//���ʷ�ת
}

char* word_reversal(char* str)
{
	//pi,p2����ָ���ַ������׵�ַ
	char *p1=str;
	char *p2=str;
	char *p;
	//pi,p2����ָ���ַ������׵�ַ
   // p1 = str;//ָ���һ�����ʵ�һ���ַ���ַ
   // p2 = str;
    
    while(*p2 != '\0')//��Ϊ�ַ�������λ��
    {
		//ʹp2ָ�򵥴ʵ�����Ǹ��ַ��ĵ�ַ
        while(*p2 != ' ' && *p2 != '\0')//��Ϊ�ո�,�Ҳ�Ϊ�ַ�����β
        {   
            p2++;
        }
       
	    p = p2;//����������Ǹ��ַ��ĵ�ַ����ֵ��p
		//ÿ�������е��ַ�����λ�ý�����ǰ��󽻻�
        while(p1 < p2-1)//p1ָ�򵥴ʵĵ�һ���ַ���ַ��p2ָ�򵥴ʵ����һ���ַ���ַ
        {
            char tmp = *p1;
            *p1 = *(p2-1);
            *(p2-1) = tmp;
            p1++;//p1ָ����һ���ַ���ַ
            p2--;//p2ָ����һ���ַ���ַ
        }
        
        if(*p == '\0')//�����ַ�����β�������еĵ��ʶ��ѷ�ת
        {
            return str;//�˳�
        }
        p1 = p+1;//p1ָ����һ�����ʵĵ�һ���ַ���ַ
        p2 = p+1;//p2ָ����һ�����ʵĵ�һ���ַ���ַ
    }
	return str;//�˳�
}

int main ()
{
    char a[] = "student a am i";
    char *ret = char_reversal(a);
    printf("%s\n",ret);
	system("pause");
    return 0;
}

*/



#include<stdio.h>
#include<assert.h>
#include<ctype.h>
#include<stdlib.h>

void change2(char *q1, char *q2)
{
	while(q1 < q2)
	{
	*q1 ^=  *q2;
	*q2 ^=  *q1;
	*q1 ^=  *q2;
	q1++;//ָ���¸��ַ�
	q2--;//ָ���ϸ��ַ�
	}
}

void change(char arr[])
{
	char * p = arr;//����ָ�򵥴�β��
	char * q = arr;//����ָ�򵥴�ͷ��
	
	assert(arr);//��⺯�������arr�Ƿ�ΪNULL��ͷ�ļ�#include<assert.h>

	while(*p)//*p��Ϊ'\0'���ַ����еĵ��ʽ���
	{
		//if(*p1==' ') 
		if(isspace(*p))//�жϵ����Ƿ������isspace(*p)���*pΪ�ո񷵻�1,ͷ�ļ�#include<ctype.h>
		{               //���ʽ�������������������˳��
			change2(q,p-1);//�����˵�������˳������p1����ʱָ���Ϊ�ո�����-1
			p++;   //pָ���¸����ʵ�ͷ��
			q=p; //qָ���¸����ʵ�ͷ������һ����ĸ��
		}
		else //����δ����
			p++;//ָ��ָ���¸���ĸ
 	}//����ʱp1ָ��'\0'

	change2(arr,p-1);// �ַ������彻�� '\0'���ɽ��� p-1
}

int main()
{
	char arr[]="student a am i";
	printf("ת��ǰ��%s \n",arr);
	change(arr);
	printf("ת����%s \n",arr);
	system("pause");
	return 0;
}



/*

//���������е���������ǰ��

#include<stdio.h>
#include<stdlib.h>

int change(int arr[],int sz)
{
	int *p=arr;//ָ��ǰ�ߵ���
	int *q=&arr[sz-1];//ָ���ߵ���

	while(p<q)
	{
		//ע��������������2^n+2^k+...��ɣ�ż������2^0,
		//���Զ��������λΪ0��Ϊż����Ϊ1��Ϊ�������ж���ż����ʹ��λ����Ч�ʸ���
		if((*p&1)==0&&(*q&1)!=0)//ǰΪ��������Ϊż��������
		{
	    	*p=*p^*q;
			*q=*p^*q;
			*p=*p^*q;
		}
		if(*p&1)//ǰ��Ϊ����ǰָ�����
			p++;
		if((*q&1)==0)//���Ϊż����ָ��ǰ��,ע'=='���ȼ�����&�����Ա���������
            q--;
	}
}

void print(int arr[],int sz)//�������
{
	int i=0;
	for(i=0;i<sz;i++)
	printf("%d ",arr[i]);
	printf("\n");
}
int main()
{
	int arr[]={1,2,3,4,5,6,9,8,7};
	int sz=sizeof(arr)/sizeof(arr[0]);

	print(arr,sz);
	change(arr,sz);
	printf("������\n");
	print(arr,sz);

	system("pause");
	return 0;
}

*/