#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num1=0,num2=0;
	int num=0;

	printf("����������:");
	scanf("%d %d",&num1,&num2);
	//�����С��
	if(num1>num2)
        num=num2;
	else
		num=num1;

	for(num;num>0;num--)//�Ӵ�С�ҳ����Լ��
	{
		if((num1%num==0)&&(num2%num==0))
		{
			printf("�������Ϊ��%d\n",num);
		    break;
		}
	}
	
	system ("pause");
	return 0;
}
