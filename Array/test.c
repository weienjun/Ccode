
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//*(地址)----->内容
//&(内容)----->地址
//&(地址)----->（二维数组）整块的地址，范围增大。（指针）存储此地址的地址
//sizeof(数组名)---->数组占总字节大小，注:字符串末尾有一个'\0'
//sizeof(地址)------>一个地址所占总字节大小（4）
//sizeof(元素)------>次元素类型所占字节大小
//sizeof(类型)------>类型所占字节大小
//strlen(字符串地址)---->从此地址到'\0'的字符个数，不统计'\0'，无'\0'随机值
int main()
{ 
	int arr[2][3]={1,3,3,4,5,6};
	int arr1[3]={1,4,5};
	char ch[2][4]={"123","456"};//前一个下标表示字符串个数，后一个下标表示字符串大小（包隐含'\0'）
	//arr1数组名表示数组的首地址,即第一个元素的地址，arr1+1表示第二个元素的地址
	//&arr1表示数组的整个地址，&arr+1表示指向下个变量的地址
	//&arr1[i]表示第i个元素的地址，&arr1[i]+j表示第i+j个元素的地址
	//首地址，第一个元素的地址，整个数组的地址，它们的值相同，意义不同"
	//arr1数组名可用于求数组所占总字节大小，列：sizeof(arr1)，注：字符串末尾有一个隐含的'\0'
	//sizeof(arr1[0])计算的是此类型所占子节大小，sizeof(arr1)/sizeof(arr1[0]);计算的是数组大小，
	//除此外，sizeof(A);若A仅表示地址，而不是数组名时，则计算的是一个地址所占字节大小（4）
	//*arr1表示arr1[0]的值
	//*arr1+1表示arr1[0]的值加1
	printf("\n****************一维数组*****************\n");
	printf("\n int arr1[3]; \n \
	\n arr1数组名表示数组的首地址,即第一个元素的地址，arr1+1表示第二个元素的地址 \
	\n &arr1表示数组的整个地址，&arr+1表示指向下个变量的地址 \
	\n &arr1[i]表示第i个元素的地址，&arr1[i]+j表示第i+j个元素的地址 \
	\n 首地址，第一个元素的地址，整个数组的地址，它们的值相同，意义不同 \n");

	printf("\narr1=%p \n",arr1);
	printf("&arr1[0]=%p\n",&arr1[0]);

	printf("&arr1[1]=%p\n",&arr1[1]);
	printf("\narr1+1=%p\n",arr1+1);
	printf("&arr1[0]+1=%p\n",&arr1[0]+1);

	printf("\n&arr1=%p\n",&arr1);

	printf("\n&arr1+1=%p\n",&arr1+1);
	printf("\n(int)arr1-(int)(&arr1+1)=%d \n",(int)arr1-(int)(&arr1+1));

	printf("\nsizeof(arr1)=%d \n",sizeof(arr1));//数组所占总字节

	
	printf("\nsizeof(arr1+0)=%d \n",sizeof(arr1+0));//地址所占字节
	printf("sizeof(&arr1)=%d \n",sizeof(&arr1));//地址所占字节
	printf("sizeof(arr1[0])=%d \n",sizeof(arr1[0]));//一个此元素类型所占字节

	printf("\n%d \n",*arr1);//*arr1表示arr1[0]的值
	printf("%d \n",*arr1+1);//*arr1+1表示arr1[0]的值加1

//二维数组要区分开数组名arr,arr[i],&arr,&arr[i]
//arr表示数组首地址，即第一行的地址，arr+1表示第二行的首地址
//&arr代表数组整个地址，指向首原素地址，&arr+1即指向下一个变量地址 
//arr[i]表示第i行的第一个元素的地址，arr[i]+1即指向本行的下一元素地址
//&arr[i]表示第i行的地址，&arr[i]+j即表示i+j行的地址
//首地址，第一个元素的地址，整个数组的地址，地址值相同意义不同
//第i行地址，第i行的第一个元素地址，第i行的整个地址，地址值相同意义不同。

//sizeof(arr));数组所占总字节大小,与一维数组相同作用
//sizeof(arr[0][0]))；此元素所占字节大小
//sizeof(arr[i]));数组第i行所占总字节大小，arr[i]相当于一维数组的数组名arr1

//sizeof(&arr[0]));地址所占字节，&arr[0]相当于一维数组的&arr1
//sizeof(arr[0]+1));地址所占字节大小，第1行第二个元素的地址
//sizeof(arr+1));地址所占字节大小，第二行的地址所占字节大小
//sizeof(&arr));地址所占字节大小，数组的地址所占字节大小
//sizeof(&arr[0]+1));地址所占字节大小,数组第0+1行的地址
//sizeof(&arr+1));地址所占字节大小，下个变量地址所占字节大小
//*arr表示首元素的地址，即&arr[0][0]的地址，*arr+1即表示第二个元素的地址，即&arr[0][1]
//*（arr+1）表示第二行的第一个元素地址，*（arr+1)+1表示第二行的第二个元素地址
//**arr，表示首元素值,由此可推出给取地址加*（地址），则表示取地址中的值
//*arr[0]，表示第一行的第一个元素的值
//*arr[1]+2=*(arr[1]+2)表示给第二行的第一个元素值+2
	printf("\n****************二维数组*****************\n");
   printf("\n int arr[2][3];) \n \
\n arr表示数组首地址，即第一行的地址，arr+1表示第二行的首地址 \
\n &arr代表数组整个地址，指向首原素地址，&arr+1即指向下一个变量地址 \
\n arr[i]表示第i行的第一个元素的地址，arr[i]+1即指向本行的下一元素地址 \
\n &arr[i]表示第i行的地址，&arr[i]+j即表示i+j行的地址 \
\n 首地址，第一个元素的地址，整个数组的地址，地址值相同意义不同 \
\n 第i行地址，第i行的第一个元素地址，第i行的整个地址，地址值相同意义不同。\n\n");
	printf("arr=%p \n",arr);
	printf("&arr[0][0]=%p \n",&arr[0][0]);

	printf("\narr[0]+1=%p \n",arr[0]+1); 
	printf("&arr[0][1]%p \n",&arr[0][1]);
	
	printf("\narr+1=%p \n",arr+1);
	printf("&arr[1]=%p \n",&arr[1]);
	printf("&arr[0]+1=%p \n",&arr[0]+1); 
	printf("&arr[1][0]=%p \n",&arr[1][0]);
	
	printf("\n&arr+1=%p \n",&arr+1);
		
	printf("(int)arr-(int)(&arr+1)=%d \n",(int)arr-(int)(&arr+1));

	printf("\nsizeof(arr)=%d \n",sizeof(arr));//2*3*4 数组所占总字节大小

	printf("\nsizeof(arr[0])=%d \n",sizeof(arr[0]));//3*4 数组第一行所占总字节大小，arr[0]相当于一维数组的数组名arr1

	printf("\nsizeof(&arr[0])=%d \n",sizeof(&arr[0]));//地址所占字节，&arr[0]相当于一维数组的&arr1

	printf("\nsizeof(arr[0][0])=%d \n",sizeof(arr[0][0]));//此元素所占字节大小
	printf("sizeof(arr[0]+1)=%d \n",sizeof(arr[0]+1));//地址所占字节大小，第1行第二个元素的地址
	printf("sizeof(arr+1)=%d \n",sizeof(arr+1));//地址所占字节大小，第二行的地址所占字节大小
	
	printf("\nsizeof(&arr)=%d \n",sizeof(&arr));//地址所占字节大小，数组的地址所占字节大小
	printf("sizeof(&arr[0]+1)=%d \n",sizeof(&arr[0]+1));//地址所占字节大小,数组第0+1行的地址
	printf("sizeof(&arr+1)=%d \n",sizeof(&arr+1));//地址所占字节大小，下个变量地址所占字节大小

	printf("\n*arr=%p \n",*arr);//*arr表示首元素的地址，即&arr[0]的地址
	printf("\n*arr+1=%p \n",*arr+1);//*arr+1表示第一行第二个元素的地址，即&arr[0][1]
	printf("*(arr+1)=%p \n",*(arr+1));//*（arr+1）表示第二行的第一个元素地址
	printf("*(arr+1)+1=%p \n",*(arr+1)+1);//*（arr+1)+1表示第二行的第二个元素地址

	printf("\n**arr=%d \n",**arr);//表示首元素值,由此可推出给取地址加*（地址），则表示取地址中的值
	printf("\n*arr[0]=%d ",*arr[0]);//表示第一行的第一个元素的值
	printf("*arr[1]+2%d \n",*arr[1]+2);//表示给第二行的第一个元素值+2
	printf("*(arr[1]+2)=%d \n",*(arr[1]+2));//表示给第一行的第一个元素值+2

	printf("\n*************字符串***************\n");
	//字符串：
	//char ch[2][4]={"123","456"};
	//前一个下标表示字符串个数，后一个下标表示字符串大小（包隐含'\0'）
	//地址------------->输出字符串，不可输出字符，从当前地址输出此字符串
	//内容（非地址）--->输出字符，不可输出字符串
	//*（地址）-------->内容，输出此地址中的一个字符
	//&（内容）-------->地址，从当前地址输出此字符串
	//列：
	//ch[0]表示第一行的第一个元素地址，所以输出第一个字符串
	//&ch[0]表示第一行地址，所以输出第一个字符串
	//ch[0][0]表示第一行的第一个字符内容，非地址，输出字符
	//&ch[0][0]表示第一行的第一个字符地址，输出第一个字符串
	//*ch表示首元素的地址，即第一行的地址，arr[0]的地址,输出第一个字符串
	//*ch+1表示第一行的第二个元素地址，从第二个字符输出第一个字符串
	//*（ch+1）表示第二行的地址,输出第二个字符串
	//*（arr+1)+1表示第二行的第二个元素地址，从第二个字符输出第二个字符串

	//*ch表示首元素的地址，即第一行的地址，arr[0]的地址,*（地址）输出地址中的内容，即一个字符
	//*ch[0]表示第一行的第一个元素的字符

	printf("\n char ch[2][4]={\"123\",\"456\"} \n");

	printf("\nch[0]=%s \n",ch[0]);//ch[0]表示第一行的第一个元素地址，所以输出第一个字符串
	printf("&ch[0]=%s \n",&ch[0]);//&ch[0]表示第一行地址，所以输出第一个字符串

	printf("ch[0][0]=%c\n",ch[0][0]);//表示第一行的第一个字符内容，非地址，输出字符
	printf("&ch[0][0]=%s\n",&ch[0][0]);//表示第一行的第一个字符地址，输出第一个字符串

	printf("\n*ch=%s \n",*ch);//*ch表示首元素的地址，即第一行的地址，arr[0]的地址,输出第一个字符串
	printf("*ch+1=%s \n",*ch+1);//*ch+1表示第一行的第二个元素地址，从第二个字符输出第一个字符串
	printf("*(ch+1)=%s \n",*(ch+1));//*（ch+1）表示第二行的地址,输出第二个字符串
	printf("*(ch+1)+1=%s \n",*(ch+1)+1);//*（ch+1)+1表示第二行的第二个元素地址，从第二个字符输出第二个字符串

	printf("\n**ch=%c \n",**ch);//*ch表示首元素的地址，即第一行的地址，arr[0]的地址,*（地址）输出地址中的内容，即一个字符
	printf("\n*ch[0]=%c ",*ch[0]);//表示第一行的第一个元素的值

	printf("\nstrlen(ch[0])=%d \n",strlen(ch[0]));
	printf("strlen(&ch[0][1])=%d \n",strlen(&ch[0][1]));

	system("pause");
	return 0;
}

/*

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Tchar_arr(void);//二维数组存放字符
void Ochar_arr(void);//一维数组
void Pchar_arr(void);//指针数组
int main()
{
	printf("\n****************一维数组********************\n");
	Ochar_arr();//一维数组
	printf("\n****************二维数组********************\n");
	Tchar_arr();//二维数组
	printf("\n****************指针数组**********************\n");
	Pchar_arr();//指针数组
	system("pause");
	return 0;
}

void Ochar_arr(void)//一维数组
{
    //strlen();参数为数组地址，统计数组中传入的地址到'\0'之前的元素个数，不包含'\0'；数组中无'\0'，则返回一个随机值
	//一个数组中只能存放一个字符串，存放字符串时将其拆为多个字符存放在数组中
	//列：char arr3[5]="1a\0A";arr[0]=1;arr[1]=a,arr[2]=\0,arr[3]=A,arr[4]='\0',arr[5]=null;
	//字符\0和\n打印出来为空格和换行而不是\0,\n
	char arr[]={'1','a','A'};
	char arr1[]={'1','a','\0','A'};
	char arr2[]="1aA";//隐含'\0'占一个字符数组大小为4，即arr[4]={"1aA"};而不是arr[3]={"1aA"}
	char arr3[]={"1a\0A"};//arr[]="1aA"同于arr[]={"1a\0A"}
	//数组可用指针访问
	char *parr;
	parr=arr;//指向首地址，即&arr[0];
  
	printf("\nchar arr[]={'1','a','A'}\n");
	printf("\nchar *parr=arr\n");
	printf("arr[0]=%c\n",arr[0]);
	printf("*parr=%c\n",*parr);
	printf("parr=%p\n",parr);
	parr++;//指向下一个地址，即&arr[1];
	printf("\nparr++\n");
	printf("arr[0]=%c\n",arr[1]);
	printf("*parr=%c\n",*parr);
	printf("parr=%p\n",parr);

	printf("\n首地址:%p\n",arr);//首地址，即第一个元素地址
	printf("第一个元素地址:%p\n",&arr[0]);//第一个元素地址
	printf("第二个元素地址:%p\n",arr+1);//第二个元素地址

	printf("\nchar arr[]={'1','a','A'}\n");
	printf("arr大小%d\n",sizeof(arr)/sizeof(arr[0]));//3,计算数组大小
	printf("strlen(arr)=%d\n",strlen(arr));//随机值
	printf("sizeof(&arr)=%d\n",sizeof(&arr));//4,第一个元素地址所占字节
	//printf("strlen(&arr)=%d\n",strlen(&arr));//随机值,错误表达式
	printf("sizeof(&arr[0])=%d\n",sizeof(&arr[0]));//4，第一个元素地址所占字节
	printf("strlen(&arr[0])=%d\n",strlen(&arr[0]));//随机值

	printf("\nchar arr1[]={'1','a','\\0','A'}\n");//  \\0 表示打印 \0
	printf("arr1大小%d\n",sizeof(arr1)/sizeof(arr1[0]));//4,计算数组大小
	printf("strlen(arr)=%d\n",strlen(arr1));//3,计算数组中元素到'\0'字符之前个数不包含'\0'

	printf("\nchar arr2[]=\"1aA\"\n");
	printf("arr2大小%d\n",sizeof(arr2)/sizeof(arr2[0]));//4,计算数组大小
	printf("strlen(arr2)=%d\n",strlen(arr2));//3,计算数组中元素到'\0'字符之前个数不包含'\0'
	printf("strlen(&arr2[0])=%d\n",strlen(&arr2[1]));//2随机值
	
	printf("\nchar arr3[]={\"1a\\0A\"}\n");//  \" 表示打印"
	printf("arr3[0]=%c\n",arr3[0]);
	printf("arr3[0]=%c\n",arr3[1]);
	printf("arr3[2]=%c\n",arr3[2]);//打印空格
	printf("arr3[3]=%c\n",arr3[3]);
	printf("arr3大小%d\n",sizeof(arr3)/sizeof(arr3[0]));//4,计算数组大小
	printf("strlen(arr3)=%d\n",strlen(arr3));//2，计算数组中元素到'\0'字符之前个数不包含'\0'
}

void Tchar_arr(void)
{
	char arr[3][3]={{'1','2','3'},{'3','4','7'},{'5','\0','1'}};

	printf("char arr[3][3]={{'1','2','3'},{'3','4','7'},{'5','\\0','1'}}\n");
	printf("\nsizeof(arr)=%d\n",sizeof(arr));//数组总大小.3*3/1=9，有3*3个元素，字符1个元素占1个字节
	
	//&arr=&arr[0]=arr+0=&arr[0][0],都是0行0列元素地址
	printf("\n&arr=%d\n",&arr);//首地址，0行地址第一个元素地址
	printf("sizeof(&arr)=%d\n",sizeof(&arr));//4，计算的是地址所占的大小，一个地址占4个字节

	printf("\narr+0=%d\n",arr+0);//0行第一个元素地址,即arr[0][0]地址
	printf("sizeof(arr+0)=%d\n",sizeof(arr+0));//4，0行0列元素地址所占字节所占的大小，一个地址占4个字节
	printf("&arr[0]=%d\n",&arr[0]);//0行第一个元素地址，即arr[0][0]地址
	printf("sizeof(&arr[0])=%d\n",sizeof(&arr[0]));//4，0行0列元素地址所占字节所占的大小，一个地址占4个字节
	//&arr[0][j]=arr[0]+j=arr+j=&arr[0][j]，0行j列元素地址
	printf("\n&arr[0][1]=%d\n",&arr[0][1]);//0行1列元素地址，即arr[0][1]地址
	printf("sizeof(&arr[0][1])%d\n",sizeof(&arr[0][1]));//4，0行1列元素所占字节所占的大小，一个地址占4个字节
    printf("arr[0]+1=%d\n",arr[0]+1);//0行1列地址，，即arr[0][1]地址
	printf("sizeof(arr[0]+1)%d\n",sizeof(arr[0]+1));//4，0行1列元素地址所占字节所占的大小，一个地址占4个字节
	//注：二维数组中，i行的地址与i行的第一个元素地址值相同，表示范围不同
	//即*（arr+i)=arr[i]//表示i行地址
	//sizeof(arr[0])=sizeof(*(arr+0))//第0行元素所占字节
	printf("\narr[0]=%d\n",arr[0]);//0行地址
	printf("sizeof(arr[0])=%d\n",sizeof(arr[0]));//3，第0行元素所占字节
	printf("*(arr+0)=%d\n",*(arr+0));//0行地址
	printf("sizeof(*(arr+0))=%d\n",sizeof(*(arr+0)));//3，第0行元素所占字节

	printf("\narr[1]=%d\n",arr[1]);//1行地址
    printf("arr+1=%d\n",arr+1);//1行第一个元素地址

	printf("\n&arr[1][1]=%d\n",&arr[1][1]);//1行1列元素地址

	printf("\n*********************************\n");
	//注：字符数组存放字符（一维与二维相同），若无'\0'则用strlen()函数求出的数组大小为随机值，有'\0'则求的值为从传入递的地址到第一个'\0'之前的大小
	//char arr[3][3]={{'1','2','3'},{'3','5','6'},{'5','\0'}};
	//数组该地址起到'\0'之前的大小
	printf("strlen(arr[0])=%d\n",strlen(arr[0]));//7
	printf("strlen(*(arr+0))=%d\n",strlen(*(arr+0)));//7，arr+1表示0行地址
	printf("strlen(arr[1]+0)=%d\n",strlen(arr[1]+0));//4，arr[1]+0表示1行0列地址
	printf("strlen(&arr[1][1])=%d\n",strlen(&arr[1][1]));//3，&arr[1][1]表示1行1列地址
	printf("strlen(arr[1])=%d\n",strlen(arr[1]));//4，arr[1]表示1行地址
	printf("strlen(*(arr+1))=%d\n",strlen(*(arr+1)));//4，arr[1]表示1行地址
	printf("strlen(&arr[2][0])=%d\n",strlen(&arr[2][0]));//1,
	printf("strlen(*(arr+2))=%d\n",strlen(*(arr+2)));//1，
	
	printf("\n**********************************************\n");
}

void Pchar_arr(void)
{
   char arr1[]="123a\0s";//可省去{}
   char *arr2[]={"123as"};//指针数组不可省去{}
   char *arr3[2]={{"\n1a"},{"123\043"}};
   char *arr4[3][2]={{"12345","ABC"},{"abcd"},{"你好"}};//汉字可存储在字符指针变量或字符指针数组中
   
   //指针数组中使用strlen()计算字符串中字符个数时，会跳过'\0'，统计除'\0'的所有字符。非指针数组计算时统计'\0'之前的字符
   // '\0和'\n'不可用字符方式输出打印，输出为换行和空格，注：若'\0'后有数字，则还可能输出其他字符
   //数组中的每个字符串都为一个地址
   //数组指针arr[i],表示第i行的地址，即存放arr4[i][0]字符串的地址
   //二维数组行地址相差  列数*4
   //数组指针arr[i][j]==*(&arr[i][j])表示字符串(arr[i][j])中的字符1arr[0][1])的地址
   //数组指针&arr[i][j]=*(arr+i)+j=arr[i]+j,表示字符串arr[i][j])的地址
   //注：数组指针的数组名计算的是数组中有多少个地址所占的字节，而不在是元素所占的地址
   //数组指针：sizeof(arr)计算的是所有地址所占字节，数组大小为几，则地址就有几个,
   //一维数组指针大小：sizeof(arr)/sizeof(arr[0]);sizeof(arr1[0])表示一个地址所占的字节（4）
   //二维指针数组大小：sizeof(arr)/sizeof(arr[0][0]);sizeof(arr[0][0])为一个地址占4个字节
 
   printf("\n******************************************\n");
   printf("\nchar arr1[]=\"123a\\0s\"\n");//  \\0表示打印\0
   //printf("arr1[0]=%s\n",arr1[0]);//错误表达式 不可用 %s 输出字符
   printf("arr1[0]=%c\n",arr1[0]);//打印第一个字符
   printf("arr1=%d\n",sizeof(arr1));//计算数组中所有元素所占大小大小，包含隐含'\0'
   printf("strlen(arr1)=%d\n",strlen(arr1));//arr[0]字符串中'\0'之前的字符个数
   printf("arr1[4]=%c\n",arr1[4]);//打印'\0'结果为空格

   printf("\n******************************************\n");
   printf("\nchar *arr2[]={\"123as\"}\n");
   //printf("arr2[0]=%s\n",arr2[0]);//错误表达式
   //printf("*arr2[0]=%s\n",*arr2[0]);//错误表达式
   printf("*arr2[0]=%c\n",*arr2[0]);//第一个字符值
   printf("arr2[0]=%p\n",arr2[0]);//打印第一个字符串地址
   printf("sizeof(arr2)=%d\n",sizeof(arr2));//计算的是所有地址所占字节（4），数组大小为几就有几个地址
   printf("sizeof(arr2[0])=%d\n",sizeof(arr2[0]));//计算的是1个地址所占字节（4）
   printf("sizeof(&arr2)=%d\n",sizeof(&arr2));//计算的是1个地址所占字节（4）
   printf("sizeof(&arr2[0])=%d\n",sizeof(&arr2[0]));//计算的是1个地址所占字节（4）
   printf("sizeof(&(*arr2[0]))=%d\n",sizeof(&(*arr2[0])));//计算的是1个地址所占字节（4）
   printf("strlen(arr2[0])=%d\n",strlen(arr2[0]));//字符串中字符个数

   printf("\n******************************************\n");
   printf("\nchar *arr3[2]={{\"\\n1a\"},{\"123\\043\"}}\n");
   //printf("arr3[0]=%s\n",arr3[0]);//错误表达式
   printf("*(&arr3[0])=%s\n",*(&arr3[0]));//打印第二个字符串，指针可打印字符'\0'
   printf("*(&arr3[1])=%s\n",*(&arr3[1]));
   printf("arr3[0]=%p\n",arr3[0]);//打印第一个字符串地址
   printf("arr3=%d\n",sizeof(arr3));//8,计算数组中所有地址所占字节
   printf("%d\n",strlen(arr3[0]));//arr[0]字符串的字符个数，字符串结尾无\0
   printf("%d\n",strlen(arr3[1]));//arr[1]字符串的字符个数，包含字符串中原有的\0


   printf("sizeof(arr3)=%d\n",sizeof(arr3));//计算的是所有地址所占字节，数组大小为几就有几个地址
   printf("sizeof(arr3[0])=%d\n",sizeof(arr3[0]));//计算的是1个地址所占字节（4）
   printf("sizeof(&arr3)=%d\n",sizeof(&arr3));//计算的是1个地址所占字节（4）
   printf("sizeof(&arr3[0])=%d\n",sizeof(&arr3[0]));//计算的是1个地址所占字节（4）
   printf("sizeof(&(*arr3[0]))=%d\n",sizeof(&(*arr3[0])));//计算的是1个地址所占字节（4）


   printf("\n************字符串输出**************\n");
   printf("\n char *arr4[3][2]={{\"12345\",\"ABC\"},{\"abcd\"},{\"你好\"}}\n");
   printf("*(&arr4[0][0])=%s\n",*(&arr4[0][0]));//打印第一个(arr[0][0])字符串
   printf("*arr4[0]+0=%s\n",*(arr4[0]+0));//打印第一个(arr[0][0])字符串
   printf("*arr4[0]+1=%s\n",*(arr4[0]+1));//打印(arr[0][1])字符串
   printf("*(&arr4[1][0])=%s\n",*(&arr4[1][0]));//打印(arr[1][0])字符串
   printf("*arr4[2]=%s\n",*(arr4[2]));//打印(arr[2][0])字符串

   printf("\n*************字符输出****************\n");
   //printf("*arr4[0][0]=%s\n",*arr4[0][0]);//错误表达式,不可用 %s 输出
   printf("*arr4[0][0]=%c\n",*arr4[0][0]);//打印第一个字符串(arr[0][0])中的第一个字符1
   printf("*arr4[0][1]=%c\n",*arr4[1][2]);//打印第一个字符串(arr[0][1])中的第一个字符1
   printf("*arr4[0][0]=%c\n",*arr4[2][0]);//打印第一个字符串(arr[2][0])中的第一个字符1(由于汉字不是ASCLL字符,所以打印乱码）

   printf("\n******************************************\n");
   //printf("arr4[0]=%s\n",arr4[0]);//错误表达式
   printf("arr4[0]=%p\n",arr4[0]);//打印第0行地址，即存放arr4[0][0]字符串的地址
   printf("arr4[1]=%p\n",arr4[1]);//打印第行1地址，与相邻行地址差  列数*4
   printf("arr4[0][0]=%p\n",arr4[0][0]);//第一个字符串(arr[0][0])中的字符1的地址
   printf("&(*arr4[0][0])=%p\n",&(*arr4[0][0]));//第一个字符串中的字符1的地址
   printf("arr4[0][1]=%p\n",arr4[0][1]);//第二个字符串中的字符1arr[0][1])的地址
   printf("&arr4[0][0]=%p\n",&arr4[0][0]);//第一个字符串(&(*arr[0][0]))的地址
   printf("*(arr4+0)=%p\n",*(arr4+0));//第一个字符串(&(*arr[0][0]))的地址
   printf("*(arr4+0)+0=%p\n",*(arr4+0)+0);//第一个字符串(&(*arr[0][0]))的地址
   printf("&arr4[0][1]=%p\n",&arr4[0][1]);//第二个字符串(&(*arr[0][1]))的地址
   printf("*(arr4+0)+1=%p\n",*(arr4+0)+1);//第一个字符串(&(*arr[0][1]))的地址
   printf("arr4[0]+1=%p\n",arr4[0]+1);//第一个字符串(&(*arr[0][1]))的地址
   printf("&arr4[1][0]=%p\n",&arr4[1][0]);//字符串(*(&arr[1][0]))的地址
   printf("arr4[1]+0=%p\n",arr4[1]+0);//第一个字符串(&(*arr[0][0]))的地址
   printf("*(arr4+0)+2=%p\n",*(arr4+0)+2);//第二个字符串(&(*arr[1][0]))的地址

   printf("sizeof(arr4[0])=%d\n",sizeof(arr4[0]));//8,arr4[0]表示行地址，一行地址共占8个字节，
   printf("sizeof(arr4[0][0])=%d\n",sizeof(arr4[0][0]));//字符串(arr[0][0])中的字符1的地址，一个元素地址占4个字节
   printf("sizeof(arr4)=%d\n",sizeof(arr4));//24,地址共占24个字节
   printf("数组大小%d\n",sizeof(arr4)/sizeof(arr4[0])[0]);//  6=24/4  (地址共占24个字节，一个地址占4个字节）
   
   printf("strlen(arr4[0])=%d\n",strlen(arr4[0][0]));//字符串a[0][0]的长度 
   printf("\n******************************************\n");
}

/*

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{  
	//一个汉字占4个字节
	char * ch="你好";
	char ch1[3][5]={"123","你h",{"anv"}};//前一个数3表式字符串个数，后一个数5表式每个字符串最大长度(字符个数-1)，包含'\0'
	int i=0;
	//sizeof(ch1)计算数组可存总字节数大小，
	printf("可存字符串个数：%d \n",sizeof(ch1)/sizeof(ch1[0]));//计算数组可存字符串多少
	printf("第1个字符串字符数：%d \n",strlen(ch1[0]));//strlen(ch1[i])计算第i个字符串的字符个数不含'\0'
	for(i=0;i<3;i++)//对二维数组初始化，（汉字串末尾无隐含'\0'，占1个字节）
	{
		printf("输入第%d个字符串：",i);
	   scanf("%s",ch1[i]);
	}
	printf("\n********输出*********\n");
	for(i=0;i<sizeof(ch1)/sizeof(ch1[0]);i++)
    printf("%s\n",ch1[i]);//ch1[i]表式对第i个字符串输出
	//printf("%s \n",ch1[1][1]);//错误，ch1[i]即表式对第i个字符串输出
	printf("ch1[1][1]=%c \n",ch1[1][1]);//ch1[i][j]表式对第i个字符串中的第j个字符输出，汉字不在ASCLL码中，不可输出汉字，
	printf("ch=%s\n",ch);

	printf("%p \n",ch1);//ch1表式首地址
	printf("%p \n",&ch1);//表式首地址
	printf("%p \n",ch1[0]);//表式第一个字符串地址
	printf("%p \n",&ch1[0][0]);//表式第一个字符串的第一个字符地址
	printf("%p \n",&ch1[0][1]);//表式第一个字符串的第二个字符地址
	printf("%p \n",ch1[1]);//表式第二个字符串地址

	printf("可存字符串个数：%d \n",sizeof(ch1));//数组所占总字节大小 15
	printf("可存字符串个数：%d \n",sizeof(&ch1));//一个地址变量所占字节大小（4）
	printf("可存字符串个数：%d \n",sizeof(ch1[0]));//一个字符串所定义字节大小 5
	printf("可存字符串个数：%d \n",sizeof(&ch1[0]));//一个地址变量所占字节大小（4）
	printf("可存字符串个数：%d \n",sizeof(ch1[1]));//一个字符串所定义字节大小 5
	printf("可存字符串个数：%d \n",sizeof(ch1[0][0]));//一个字符所占字节 1
	printf("可存字符串个数：%d \n",sizeof(&ch1[0][0]));//一个地址变量所占字节大小（4）
	printf("可存字符串个数：%d \n",sizeof(ch1[0][1]));//一个字符所占字节 1
	printf("可存字符串个数：%d \n",sizeof(ch1[2]));//字符串ch1[2]所定义字节大小 5

	system("pause");
	return 0;
}

*/