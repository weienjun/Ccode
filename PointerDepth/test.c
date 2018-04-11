


//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//void pointer_arr(char **ch);//指针数组，是数组，存储的是，指针（地址）
//
//void test (char **ptr)
//{
//	printf("%c \n",**ptr);
//}
//
//int main()
//{
//	//数组中的内容可修改
//	//一维数组，下标表示可存字符个数
//	char arr1[3]={'1','2','3'};
//
//	//二维数组，第一个下标表示字符串个数，第二个下标表示字符串长度（字符串末尾有隐含'\0'）
//	//传参：//void arr(char (*arr)[3])
//            //void arr(char arr[][3])
//	char arr2[2][4]={"123","456"};
//
//	//char*类型的字符串保存在文字常量区，即ch地址为文字常量区的地址，
//	//文字常量区的内容在编译时就已确定，不可更改。即ch的字符串不可修改
//	//只有 char *类型可在定义时直接初始化，列 char * ch="123456";而 int * num=5;错误，因为num为野指针
//	//ch[0]=*p='1'; *++p=ch[1]='2'...ch[6]='\0'
//	// 注：将当前的ch地址当作ch[0]，然后依次往后退ch[2]，而不一定都从起始地址算起，
//	char * ch=NULL;//ch未分配内存空间，是个野指针，不可赋值
//
//	char * arrp[2]={"100","456"};
//	//arrp[0]表示第一个字符串的地址，arrp[1]表示第二个字符串的地址
//	//*arrp[0]表示取第一个字符串地址中的字符，即第一个字符'1',*arrp[1]表示取第二个字符串第一个字符'4'
//	//注：arrp[0]是代表整个字符串的地址，而不是代表第一个字符地址，地址相同，意义不同
//	//arr[i]+j表示第i+1个字符串中的第j+1个字符的地址  *(arr[1]+1)即取第二个字符串中第二个字符(5)
//	//char * arrp[2]={"100","456"};
//
//	//调用函数进行内存空间分配，参数为保存ch地址的地址，而不是ch,
//	//类似改变某个变量传入的是变量的地址，而不是变量名一样
//
//	char * arrr[10]={"789"};
//	test(arrr);
//
//	pointer_arr(&ch);
//	ch="123456";
//
//	printf("%s \n",ch);//123456
//	printf("%c \n",*++ch);//2
//	printf("%c \n",ch[2]);//4 注：从将h当前的地址当作ch[0]，然后依次往后退ch[2]
//	
//	printf("%s \n",arrp[0]);
//	printf("%d \n",strlen(arrp[0]));
//	printf("%s \n",arrp[1]);
//	printf("%s \n",(arrp[0]+1));//arrp[0]+1表示第一个字符串中的第二个字符的地址
//	printf("%c \n",*(arrp[1]+2));
//	system("pause");
//	return 0;
//}
//
//
//void pointer_arr(char **ch)//使用函数为指针分配内存空间
//{
//	*ch=(char*)malloc(sizeof(char)*100);
//}



/*
//函数指针数组
#include<stdio.h>
#include<stdlib.h>

int add(int x,int y);//返回类型与函数指针数组返回类型相同
int sub(int x,int y);//子函数的声明要在函数指针数组之前
//返回int型，函数名(*pointer[]),最多有三个子函数(分别为add,sub,0未用)，参数为两个int型,传给子函数
int (*pointer[3])(int x,int y)={0,add,sub};//函数指针数组，不写此函数的实现

int main()
{
	int x=0;
	int y=0;
	int  num=0;//选择数即下标选择
	int ret=0;//计算结果

	printf("输入选择(0->退出，1->加，2->减);");
	scanf("%d",&num);
	while(num)
	{
		printf("输入两个数:");
		scanf("%d %d",&x,&y);
		ret=(*pointer[num])(x,y);//num为数组下标选择
		printf("结果：%d\n",ret);
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