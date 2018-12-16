#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char * ch ;
	char * temp="12";//temp指向文字常量区
	int i=0;
	//*temp='1';//错误，文字常量区内容不可修改
	temp="000";//正确，但地址被修改，重新在文字常量区开辟一块空间存放内容，并使temp指向他

	//使用malloc开辟内存空间，malloc返回类型为void *需强转成其它类型
	//malloc 开辟的内存空不进行初始化
	ch=(char *)malloc(sizeof(char)*10);
	if(ch==NULL)
		printf("eorr\n");
	else 
		ch="123456789";
	printf("%s\n",ch);

	printf("%p\n",ch);
	//calloc与malloc类似，但会将开辟的内存空间进行初始化为0
	 printf("%p\n",temp);
	temp=(char *)calloc(sizeof(char),10);//开辟内存空间后指向堆区
	if(temp==NULL)
		printf("eorr!\n");

	 *temp='1';//正确，由于temp指向堆区，内容可修改

	 //temp="000";//错误，地址被修改，重新在文字常量区开辟一块空间存放内容，并使temp指向他
	//temp++;//错误， 使用realloc开辟空间，起始地址不可改变，否则内存泄漏
	//修改空间大小，变量必须有一定的内存空间且未进行初始化
	//若ch后空间足够，则直接在后面扩展所需的空间，返回ch地址不变
	//若ch后空间不足，则重新寻找一块足够的空间，并将原空间内容复制到新空间中去，返回ch地址改变
	//若无法在内存空间找到复合要求的内存大小，则返回NULL;原内存空丢失
	ch=(char *)realloc(temp,50);
	if(ch==NULL)
	{
		printf("eorr!\n");
		exit(0);
	}
	else
	{
		ch=temp;
		//空间>50，这与编译器有关，说明动态内存开辟空间实际偏大。
		//但注意，多出的空间最好不要使用，否则可能会出现内存泄漏，
		while(i<49)
		{
			*ch=(i+'0');
			ch++;
			i++;
		}
		*ch='\0';//末尾添加'\0'结束字符，否则输出会有问题
		ch=temp;//重新指向起始位置
		printf("%s\n",ch);
		printf("%d\n",strlen(ch));
	}
	//不可对同一地址空间多次释放，且只能全部释放，不可只释放一部分
	//temp++;//错误，起始地址被改变，空间不可部分释放，只可整体释放（从起始地址）
	free(temp);//ch与temp指向同一块内存空间，只需释放一个就可
	//free(ch);//temp与ch为同一空间，同一空间不可多次释放
	system("pause");
	return 0;
}