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
	printf("ԭ����%3d%3d\n",num1,num2);
	printf("������%d:\n",num1|num2);
	printf("������%d:\n",num1&num2);
	printf("ȡ������;%d\n",~num1);
	printf("ȡ������;%d\n",!num1);
	printf("�������;%d\n",num1^num2);
	a=~(~0<<4); //�����ƺ���λΪ1111
	printf("ȡ����λ;%d\n",num1&a);
	//���������λ���������ֵ�����������
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
	printf("��������%dλ\n",i);
	a=1<<i;
	printf("0��ʾ������1��ʾ���������Ϊ��%d\n",(num1&a)==a);
	printf("����Ϊ%d\n",num4);
	//���㲹�뷽��2
	num5=num1 & 0100000;//���㲹��  0100000���˽��ƣ��ɻ�Ϊ65536������ʮ���η������λ����λΪ1��Ҳ��Ϊ2ʮ�ߴη�...����16λ��ȥ����λ
	if(num5==0100000)
		num5=~num1+1;
	else
		num5=num1;
	printf("����Ϊ%d\n",num5);
	//���kλȡ���Ľ��
	for(i=1;i<=2;i++)//����λ��ȡ��
	{
	printf("�����%d�εڼ�λȡ����",i);
	scanf("%d",&k);
    b=1<<(k-1);//��1<<4-->10000,1��Ϊ����λ��1λ���Դ˴�Ҫ��һ
	num1=num1^b;
	}
	printf("λȡ�����Ϊ��%d\n",num1);
	system("pause");
	return 0;
}


/*
//ѭ����λ��������λ�Ƶ���λ�򽫸�λ�Ƶ���λ
 int right(unsigned a,int n)//��λ����
{
	unsigned z;
	z=(a<<(32-n))|(a>>n);//ѭ������
	return z;
}
int main()
{
    unsigned a;//��λ��
	int i;//����λ��
	printf("����һ���˽�����\n");
	scanf("%o",&a);
	printf("�����Ƶ�λ��\n");
	scanf("%d",&i);
	printf("��λ��Ľ��%o:\n",right(a,i));
	system("pause");
	return 0;
}
*/




/*
//λ�β���

struct sb1//λ�ζ��壬λ�β�����ṹ����ͬ
{
	unsigned i:8;//�޷����ͣ�ռ8��λ����1B��=8��λ��
	int j:2;//���Σ�ռ2��λ
	int k:6;//ռ6��λ���������λ����һ�𣬹�ռ8��λ��1B
}s1;        //��ռ2���ֽ�
struct sb2
{
	int a:5;//���Σ�5��λ��������һ��λ���޴�С�����Դ�λ�����¸�λ�ζϿ�������3��λ���ٿ��á�����1B
	int b;//��λ��С��λ��bռ2B
	int c:2;//���Σ�ռ2��λ�������¸����ϸ�λ�β���������������6��λ������ʹ�ã�����1B
	int :6;//�ޱ�����������Ϊ����Ч��0��λ
}s2;       //��ռ4���ֽ�
int main()
{
	printf("λ�θ�ֵ\n");
	//scanf("%d%d%d",&s1.i,&s1.j,&s1.k);//����ʹ��scanf����
	s1.i=1;
	s1.j=10;
	s1.k=11;
	printf("���i=%d j=%d k=%d\n",s1.i,s1.j,s1.k);
	printf("���s1��ռ��Ϊ%d  ���s1��ռ���ֽ�%d\n",sizeof(struct sb1),sizeof(s1));
	printf("�����ַs1=%x s2=%x\n",&s1,&s2);
	printf("λ��ռ��λ s2.a:%d s2.b:%d\n",sizeof(s2),sizeof(s2.b));
	system("pause");
	return 0;
}

*/






