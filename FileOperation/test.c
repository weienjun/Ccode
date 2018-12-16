/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void han(int count);

int main()
{
	int ch;
	int num=100;
	char arr[100];
	int count=0;
	int n=0;
	FILE * pfile;//定义一个文件变量

	//getchar();//清空缓冲区，防止获取字符流时出错
	
	//打开此目录下的文件，以 wt 方式打开（w 写入方式，t 若无此文件则创建一个）
	pfile=fopen("C:\\Users\\魏恩军\\Desktop\\my_file.txt","wt");//my_file文件名
	if(pfile==NULL)//打开失败
		printf("eorr\n");
	else//打开成功
	{
		printf("输入字符串：\n");

		while(1)//文本编译
		{
			//若改行超过5个字符，则读取5个字符，下次会继续读取未读取的字符，少于5个则会读取结束
		 //      if(count!=0)
			//   {
			//	han(count);
			//	count=0;
			//   }
			fgets(arr,5,stdin);//获取arr输入一行中的5个字符流(注：回车结束),
		 //   if(arr[0]=='{')
			//	   count=1;
		 //   if(arr[0]=='}')
			//	   count=0;
		   if(strcmp(arr,"exit")!=0)
		   {
		   fputs(arr,pfile);//向文件中写入字符串（arr）
		   }
		   else
		   break;
		}

	   rewind(pfile);//将文件指针指向开头，（注：在开头再次进行写入内容会替换掉原有的此处内容）
	   fseek(pfile,0,SEEK_END);//文件指针指向文件结尾，偏移位置0
	   fprintf(pfile,"%d\n",ftell(pfile));//ftell返回指针位置（数字）写入文件

	   fscanf(stdin,"%d",&num);//从输入流中读取内容（注：遇到空格或回车结束获取）
	   fprintf(pfile,"起始num=%d\n",num);//将输出流num写入文件中
	   //将输出流存放在文件中，仅在printf()前加文件变量名，其它不变
	   for(ch='A';ch<='Z';ch++)//将A~Z写入文件
		   putc(ch,pfile);//将字符写入文件
	}
	fclose(pfile);//关闭文件

	//打开此目录下的文件，以 r 方式打开
	pfile=fopen("C:\\Users\\魏恩军\\Desktop\\my_file.txt","r");
	do
	{
		ch=getc(pfile);//获取文件中的一个字符
		if(ch==' ')num++;//统计文件中的单词个数
	}while(ch != EOF);
	printf("%d\n",num+1);

	fclose(pfile);
	system("pause");
	return 0;
}

void han(int count)
{
	int i=0;
	for(i=0;i<count*4;i++)
     printf(" ");
}
*/

//2.研究 
//fread 
//fwrite 

//二进制文件操作
//1. size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);  
//2. size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
//fread和fwrite用于读写记录，这里的记录是指一串固定长度的字节，比如一个int、一个结构体或者一个定长数组。
//参数size指出一条记录的长度(即类型)，而nmemb指出要读或写多少条记录（个数），共操作（size*number个字节）
//fread从文件stream中读出size * nmemb个字节保存到ptr中，
//而fwrite把ptr中的size * nmemb个字节写到文件stream中
//列：
//读取文件（文件变量名pFile）中的1个字节，读取1size次，放在buffer变量（无类型void*）中
//fread (buffer,1,lSize,pFile);
// 将变量buffer（无类型void*）中的一个字节（char类型），写到文件pFile中，写sizeof(buffer)次
//fwrite (buffer1 , sizeof(char), sizeof(buffer), pFile);

/*
#include<stdio.h>
#include<stdlib.h>

int main () 
{  
	FILE * pFile; 
	long lSize; 
    char * buffer; 
    size_t result; 
    char buffer1[] = { 'x' , 'y' , 'z' };

  pFile = fopen ( "C:\\Users\\魏恩军\\Desktop\\myfile.bin" , "rb" ); 
  if (pFile==NULL)
  {
	  fputs ("File error",stderr); 
	  exit (1);
  } 
 
  // obtain file size:
   fseek (pFile , 0 , SEEK_END); 
   lSize = ftell (pFile);
   rewind (pFile); 
 
  // allocate memory to contain the whole file:
   buffer = (char*) malloc (sizeof(char)*lSize); 
   if (buffer == NULL) 
   {
	   fputs ("Memory error",stderr); 
       exit (2);
   } 
 
  // copy the file into the buffer:
   result = fread (buffer,1,lSize,pFile);
   if (result != lSize) 
   {
	   fputs ("Reading error",stderr);
	   exit (3);
   } 
  pFile = fopen ("myfile.bin", "wb");
  fwrite (buffer1 , sizeof(char), sizeof(buffer), pFile); 
 // the whole file is now loaded in the memory buffer. 
 
 
  // terminate
   fclose (pFile); 
   free (buffer);
   system("pause");
   return 0; 
}

*/

//1.研究 
//sscanf 
//sprintf 

#include<stdio.h>
#include<stdlib.h>
//sprintf()
//1、格式转换
//sprintf(字符数组名，"类型"，转化变量名)
//将变量以某种格式（整型，字符，八进制，十六进制，浮点型）以字符形式存储在字符数组中
//2、连接
//sprintf(字符数组名，"类型1" "类型2"，变量名1，变量名2)
//将多个变量以各自某种格式，连接存储在字符数组中

//sscanf();
//1、格式输入
//sscanf("字符串","类型",&获取变量名);
//将字符（字符串）以某种格式赋给变量，即某种格式获取字符串中的变量
//2、获取指定长度的字符串
//sscanf("字符串","%ns",&获取变量名);
//获取字符串中的n个字符，赋给变量，（若字符串中字符个数 < n 则取最大值(即0—n)）
//3、获取指定内容
//注：若第一个字符不在范围内则获取失败，一直获取到不在范围内的第一个字符为止
//sscanf("字符串","范围",&获取变量名);
//sscanf可以支持格式字符%[] 这为分析字符串提供了很大方便(其实scanf也支持%[])
//(1)-: 表示范围，如：%[1-9]表示只读取1-9这几个数字， %[a-z]表示只读取a-z小写字母，类似地 %[A-Z]只读取大写字母
//(2)^: 表示不取，如：%[^1]表示读取除'1'以外的所有字符， %[^/]表示除/以外的所有字符
//(3),: 范围可以用","相连接 如%[1-9,a-z]表示同时取1-9数字和a-z小写字母 
//(4)原则：从第一个在指定范围内的数字开始读取，到第一个不在范围内的数字结束%s 可以看成%[] 的一个特例 %[^ ](注意^后面有一个空格！)
//(5)%*s%s:忽略第一个字符串， %s%*s忽略第二个字符串（用于两个字符串）
int main()
{
	int num=12;
	float fnum=49.12;
	char arr[100];
	int num1[10];
	int num2[20];

	sprintf(arr,"%0.3f",fnum);//浮点数保三位小数以字符形式存储在字符数组arr中
	printf("%s\n",arr);//输出：49.120

	sprintf(arr,"%o",num);//将num以八进制保存字符数组中
	printf("%s\n",arr);//14
	//将fnum保三位小数，num以十六进制都以字符形式，连接存储在字符数组arr中
	sprintf(arr,"%0.3f%x",fnum,num);
	printf("%s\n",arr);//49.120c

	scanf("%s",arr);//49
	sscanf(arr,"%d",&num1);//字符49->数值1，将arr中的字符串转化成整型，赋给num1
	printf("*%s  \n",num1);//1

	sscanf(arr,"%1s",&num1);//获取arr中的1个字符，赋给num1
	printf("*%s  \n",num1);//4

	scanf("%s",arr);//abc129
    sscanf(arr,"%[a-z,1-5]s",&num2);//获取字符串arr中的a~z,或1~5中的字符
	printf("num2=%s\n",num2);//abc12

	sscanf("hello word c!","%*s%s",&num1);//忽略第一个字符串,只获取第二个字符串
	printf("%s\n",num1);//word

	system("pause");
	return 0;
}

