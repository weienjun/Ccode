//1.�Զ������Ͳ���֪ʶдһƪ���͡� 
//֪ʶ�㣺 
//>�ṹ�����ʹ��� 
//>�ṹ���ʼ�� 
//>�ṹ���ڴ���� 
//>λ�Σ�λ�μ������С�� 
//>ö��+���ϡ� 
//
//2.ʵ��һ��ͨѶ¼�� 
//ͨѶ¼���������洢1000���˵���Ϣ��ÿ���˵���Ϣ������ 
//�������Ա����䡢�绰��סַ 
//
//�ṩ������ 
//1. �����ϵ����Ϣ 
//2. ɾ��ָ����ϵ����Ϣ 
//3. ����ָ����ϵ����Ϣ 
//4. �޸�ָ����ϵ����Ϣ 
//5. ��ʾ������ϵ����Ϣ 
//6. ���������ϵ�� 
//7. ����������������ϵ�� 

#include<stdio.h>
#include<stdlib.h>
#include"realization.h"
int count;

int main()
{  
	people * head=NULL;//ͷ�ڵ�

	Menu(head);//�˵�����

	system("pause");
	return 0;
}

int Menu(people * head)
{
	int num=0;
    char ch[20];
	people * ptemp;//������ҵĽ��

	while(1)
	{
	printf("\n**************��ӭʹ��ͨѶ¼***************\n");
	printf("\n  0-->�˳�\n  1-->��ʾ\n  2-->���\n  3-->����\n  4-->ɾ��\n  5-->����\n  6-->�޸�\n  7-->���\n  8-->�ļ�\n");
	printf("\n*******************************************\n");
	printf("\n����ѡ��");
	scanf("%d",&num);
	getchar();
	 switch(num)
	  {
		case 0:
			return 0;//�˳�
		case 1:
			if(count==0)
			{
			printf("\n����ϵ�ˣ�\n");
			printf("���ȴ�����ϵ��!\n");
			head=creat(head);//������ϵ��
			}
			printf("\n������ϵ��\n");
			print(head);//�����ϵ��
			break;
		case 2:
			head=creat(head);//���
			break;
		case 3:
			printf("\n���ҽ����\n");
			if(head)//ͨѶ¼��Ϊ��
			{
			printf("������ҵ�������");
			scanf("%s",&ch);
			search(head,ch);
			}
			else
			printf("����ϵ�ˣ�\n");
			break;
		case 4:
			if(head)
			{
				printf("����ɾ����������");
				scanf("%s",&ch);
				ptemp=search(head,ch);

				if(ptemp)//ͨѶ¼�д��ڴ���
				{
					char c;
					printf("\n�Ƿ�ɾ��?(Y or N)");
					getchar();
					scanf("%c",&c);
					if(c=='Y'||c=='y')
					{
					dete(ptemp);
					printf("\nɾ���ɹ���\n");
					}
				}
			    else
			    printf("\n�޴���ϵ�ˣ�\n");
			}
			else
			printf("����ϵ�ˣ�\n");
			break;
		case 5:
			if(count>0)
			{
				sorting(head);
				printf("\n����ɹ���\n");
			}
			else
			printf("����ϵ�ˣ�\n");
			break;
		case 6:

			if(head)
			{
				printf("�����޸ĵ�������");
				scanf("%s",&ch);
				ptemp=search(head,ch);

				if(ptemp)//ͨѶ¼�д��ڴ���
				{
					char c;
					printf("\n�Ƿ��޸�?(Y or N)");
					getchar();
					scanf("%c",&c);
					if(c=='Y'||c=='y')
					{
					modify(ptemp);
					printf("\n�޸ĳɹ���\n");
					}
				}
			    else
			    printf("\n�޴���ϵ�ˣ�\n");
			}
			else
			printf("����ϵ�ˣ�\n");
			break;
		case 7:
			if(head)
			{
				head=empty(head);
				printf("\n��ճɹ���\n");
			}
			else 
			printf("\nͨѶ¼Ϊ�գ�\n");
			break;
		case 8:
			if(count==0)
			printf("\n����ϵ�ˣ�\n");
			else
			{
				pfile(head);
				printf("\nд���ļ��ɹ���\n");
			}
			break;
		default :
			printf("\nput eorr!\n");
		}
	}
	return 0;
}
