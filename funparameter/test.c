
/*
总结：
形参只是实参的一份临时拷贝。实例化时，在栈中形成栈帧
若仅改变变量的内容，传一级指针（变量所指向的地址）
若要改变变量的内存空间，或地址，需传二级指针（变量自身的地址）

传一级指针，变量所指向（或存储）的地址，退出函数时，释放变量所开辟的空间。不释放变量中成员的地址空间
只能改变变量的内容，包括变量中成员的地址，空间。
不能改变变量的地址，空间。若改变了变量的地址空间，则之后操作无效

传二级指针，即变量自身的地址，退函数时，变量所开辟的空间不被清空
传变量自身的地址（如：&指针变量名），此时变量所指向的地址（即指针变量名）相当于变量的内容
能改变变量的内存空间或地址，及变量中的内容

说明一下：arr[i]==*(arr+i),
一维数组名，是变量本身的地址，使用一级指针传参
指针数组名，是变量本身的地址，需使用二级指针
二维数组名，是变量本身的地址，但需使用指针数组传参，而不是二级指针，
因为二维数组是由一维数组构成的，使用（*arr）[N]或arr[][N]传参，要指明列的大小
动态开辟二维数组空间（arr[M][N]）？
解：先开辟M大的空间，在开辟N个M大的空间，每次释放只能释放一个M个大小的空间
int ** arr;
*arr =(int *)malloc(sizeof(int)*M);
for(i=0;i<N;i++)
arr[i]=(int *)malloc(sizeof(int)*M);
*/

#include<stdio.h>
#include<stdlib.h>

/*
typedef struct pos
{
	int M;
	int N;
}Pos;
*/

typedef struct Seqlist
{
	int  data;
	char * sch;
}node;

int test1(node * seq)//一级指针
{
	//sch无内存空间
	//*seq->sch='1';//错误，内存泄漏
	seq->sch="123";//正确，为sch在文字常量区开辟内存空间
	//为结构体成员开辟内存空间，sch指向新内存空间(堆)
	seq->sch=(char*)malloc(sizeof(char)*10);
	seq->sch[0]='2';//正确，sch已有内存空间（堆区地址）
	seq->sch[1]='\0';
	seq->sch="456";//sch空间变为文字常量区的地址
	//seq->sch[0]='7';//错误，文字常量区地址内容不可改变
	seq->data=20;
	//以下对seq的变量开辟内存空间，操作无效
	//为结构体指针开辟内存空间，seq指向新内存空间
	seq=(node*)malloc(sizeof(node));
	seq->data=10;
}//结构体指针临时变量内存空间被释放，成员sch空间保留

int test2(node ** seq)//二级指针
{
	//为结构体指针*seq开辟内存空间（堆区地址）
     *seq= (node*)malloc(sizeof(node));
	//为内部成员开辟空间（堆区）
	(*seq)->sch=(char*)malloc(sizeof(char)*10);
	(*seq)->sch[0]='0';//内存空间为堆区
	(*seq)->sch="321";//自动为sch在文字常量区开辟空间，并赋值（sch为文字常量区）
	(*seq)->data=10;
}//所开辟内存空间不被销毁

void test3(char **ch)//二级指针，可开辟内存空间
{
    printf("%p\n",ch[1]);
	//*ch[1]='1';//错误，ch[1]无内存空间
	ch[1]=(char*)malloc(1);//在堆上开辟一块内存空间
	*ch[1]='1';//正确，ch[1]有内存空间
	printf("%p\n",ch[1]);
	ch[1]="123456789011111111111";//重新给ch[1]分配一块内存空间（文字常量区）
    printf("%p\n",ch[1]);
}//开辟内存空间不消毁

void test4(char * ch)//1级指针,仅可以数值操作
{
    printf("%p\n",ch);
	*ch='1';//正确，ch有内存空
	*++ch='\0';
	//一下部分进行地址有关操作无效
	ch=(char*)malloc(1);//在堆上开辟一块内存空间
	*ch='2';//正确，ch有内存空间
	printf("%p\n",ch);
	ch="123456789011111111111";//重新给ch[1]分配一块内存空间（文字常量区）
    printf("%p\n",ch);
}//开辟的内存空间销毁

int main()
{
	node * seqlist=NULL;
	char * ch[3];

	test3(ch);//二级指针
    printf("%p\n",ch[1]);
	printf("%s\n",ch[1]);

	ch[1]=(char*)malloc(1);//在堆上开辟一块内存空间
	printf("%p\n",ch[1]);
	test4(ch[1]);//1级指针，不可传无内存空间的地址
	printf("%p\n",ch[1]);
	printf("%s\n",ch[1]);//1
	
	seqlist= (node*)malloc(sizeof(node));
	test1(seqlist);//一级指针传参，内存空间不可为空
	printf("%d\n",seqlist->data);
	printf("%s\n",seqlist->sch);
	
	free(seqlist);
	test2(&seqlist);
	printf("%d\n",seqlist->data);
	printf("%s\n",seqlist->sch);

	system("pause");
	return 0;
}
