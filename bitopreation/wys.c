#include<stdio.h>
#include<stdlib.h>
/*
int main(){
	int a = 0;
	while(1){
		scanf("%d", &a);
		printf("%d\n", 0100000);
	}
}*/
 int main()
{
	int num1=-1515,num2=5;
	int num3;
	int num4;
	int num5;
	int a;
	int i;
	int k,b;
	printf("原数据%3d%3d\n",num1,num2);
	printf("或运算%d:\n",num1|num2);
	printf("与运算%d:\n",num1&num2);
	printf("取反运算;%d\n",~num1);
	printf("取反运算;%d\n",!num1);
	printf("异或运算;%d\n",num1^num2);
	a=~(~0<<4); //二进制后四位为1111
	printf("取后四位;%d\n",num1&a);
	//计算二进制位数，和数字的正负及补码
	if(num1>0)
	{
      num3=num1;
	  num4=num1;
	  i=0;
	}
	else
	{
		num3=~num1;
		i=1;
		num4=(~num1)+1;
	}
	while(num3)
	{
	num3=num3>>1;
	i++;
	}
	printf("二进制有%d位\n",i);
	a=1<<i;
	printf("0表示正数，1表示负数，结果为：%d\n",(num1&a)==a);
	printf("补码为%d\n",num4);
	//计算补码方法2
	num5=num1 & 0100000;//计算补码  0100000（八进制）可换为65536（二的十六次方，最高位符号位为1）也可为2十七次方...超过16位会去除低位
	if(num5==0100000)
		num5=~num1+1;
	else
		num5=num1;
	printf("补码为%d\n",num5);
	//求第k位取反的结果
	for(i=1;i<=2;i++)//二个位置取反
	{
	printf("输入第%d次第几位取反：",i);
	scanf("%d",&k);
    b=1<<(k-1);//列1<<4-->10000,1变为第五位高1位所以此处要减一
	num1=num1^b;
	}
	printf("位取反结果为：%d\n",num1);
	system("pause");
	return 0;
}


/*
//循环移位，即将低位移到高位或将高位移到低位
 int right(unsigned a,int n)//移位函数
{
	unsigned z;
	z=(a<<(32-n))|(a>>n);//循环右移
	return z;
}
int main()
{
    unsigned a;//移位数
	int i;//所移位数
	printf("输入一个八进制数\n");
	scanf("%o",&a);
	printf("输入移的位数\n");
	scanf("%d",&i);
	printf("移位后的结果%o:\n",right(a,i));
	system("pause");
	return 0;
}
*/




/*
//位段操作

struct sb1//位段定义，位段操作与结构体相同
{
	unsigned i:8;//无符号型，占8个位，有1B（=8个位）
	int j:2;//整形，占2个位
	int k:6;//占6个位，与上面的位连在一起，共占8个位，1B
}s1;        //共占2个字节
struct sb2
{
	int a:5;//整形，5个位，由于下一个位段无大小，所以此位段与下个位段断开，其余3个位不再可用。即有1B
	int b;//无位大小，位域b占2B
	int c:2;//整形，占2个位，由于下个与上个位段不完整，所以其余6个位不可再使用，共有1B
	int :6;//无变量名，即此为段无效，0个位
}s2;       //共占4个字节
int main()
{
	printf("位段赋值\n");
	//scanf("%d%d%d",&s1.i,&s1.j,&s1.k);//不可使用scanf输入
	s1.i=1;
	s1.j=10;
	s1.k=11;
	printf("输出i=%d j=%d k=%d\n",s1.i,s1.j,s1.k);
	printf("输出s1所占的为%d  输出s1所占的字节%d\n",sizeof(struct sb1),sizeof(s1));
	printf("输出地址s1=%x s2=%x\n",&s1,&s2);
	printf("位段占的位 s2.a:%d s2.b:%d\n",sizeof(s2),sizeof(s2.b));
	system("pause");
	return 0;
}

*/






