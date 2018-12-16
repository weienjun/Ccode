
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"test.h"
#include"stack.h"

//void RPN_test(void)
//{
//	//12*(3+4)/9-3--->12 3 4 +* 9 / 3 -
//	cell nota[]={{12,data},{3,data},{4,data},{'+',add},{'*',mul},{9,data},{'/',_div},{3,data},{'-',sub}};
//	int size=sizeof(nota)/sizeof(nota[0]);
//
//	Reverse_Polishu_Notation(nota,size);//�沨�����ʽ
//}

/*
void  Kuohao_test(void)
{
	char  arr[]="(())abc{[(]}";
	char  arr1[]="(())abc{[]}";
	char  arr2[]="((())abc{[]}";
	char  arr3[]="(())abc{[]}}";

    Kuohao(arr);//�����ж�
    Kuohao(arr1);//�����ж�
    Kuohao(arr2);//�����ж�
    Kuohao(arr3);//�����ж�
}
*/
/*
void Reverse_Polishu_Notation(cell * nota,const int size)//�沨�����ʽ
{
	int i=0;
	int num1;
	int num2;
	int num;
	stack entry1;
	Stack_Init(&entry1);
    for(i=0;i<size;i++)
	{
		switch(nota[i].oper)
		{
		case add://+
			num1=Stack_Top(&entry1);
			Stack_Pop(&entry1);
			num2=Stack_Top(&entry1);
			Stack_Pop(&entry1);
			num=num2+num1;
			Stack_push(&entry1,num);
			break;
		case sub://-
			num1=Stack_Top(&entry1);
			Stack_Pop(&entry1);
			num2=Stack_Top(&entry1);
			Stack_Pop(&entry1);
			num=num2-num1;
			Stack_push(&entry1,num);
			break;
		case 2:// *
			num1=Stack_Top(&entry1);
			Stack_Pop(&entry1);
			num2=Stack_Top(&entry1);
			Stack_Pop(&entry1);
			num=num2*num1;
			Stack_push(&entry1,num);
			break;
		case 3:// /
			
			num1=Stack_Top(&entry1);
			Stack_Pop(&entry1);
			if(!num1)
			{
			    printf("eorr!\n");
				return ;
			}
			num2=Stack_Top(&entry1);
			Stack_Pop(&entry1);
			num=num2/num1;
			Stack_push(&entry1,num);
			break;
		case 4:// ����,ѹջ
			Stack_push(&entry1,nota[i].size);
			break;
		default:
			printf("eorr!\n");
		}
	}
	num=Stack_Top(&entry1);
	printf("%d\n",num);
}
*/
/*
void Kuohao(char * arr)//�����ж�
{
	int i=0;
	int sz=strlen(arr)+1;
	stack entry;
	Stack_Init(&entry);
	for(i=0;i<sz;i++)
	{
		if(arr[i]  == '(' || 
		    arr[i] == '[' ||
			arr[i] == '{')//��ջ
		{
		Stack_push(&entry,arr[i]);
		}

		else if(arr[i] == ')' ||
			    arr[i] == ']' ||
				arr[i] == '}')
		{
			if(Stack_Empty(& entry))//ջΪ��
			{
				printf("�ұ���࣡\n");
				break;
			}
			else if((arr[i] == ')' && Stack_Top(&entry) == '(') ||
				    (arr[i] == ']' && Stack_Top(&entry) == '[') ||
					(arr[i] == '}' && Stack_Top(&entry) == '{'))//�Ƚ�ջ��Ԫ��
					Stack_Pop(&entry);//��ջ
			else
			{
				printf("���Ų�ƥ�䣡\n");
				break;
			}
		}
	}
	if(!Stack_Empty(&entry)&& i >= sz)
	{
		printf("�����ű������Ŷ࣡\n");
	}
	else if(i == sz)
		printf("������ȷ\n");
}
*/


void change(cell* cur,cell* next,const int size)//��׺ת��׺
{
	stack s;
	cell top ;
	int i = 0 ;
	int j = 0 ;

	Stack_Init(&s);
	for(i = 0 ;i < size ; i++)
	{
		if(!Stack_Empty(&s))//ջ��Ϊ��ȡջ����Ϊ�յĻ���ȡ���Ὣ������ջ����')'��
		{
		    top = Stack_Top(&s);
		}
		switch(cur[i].oper)
		{
		//add,sub,mul,_div
		case add:
		case sub:
		case mul:
		case _div:
			cur[i].sy = (cur[i].oper == add || cur[i].oper == sub)? Sub : Div;//+ - ���ȼ���ͬ
			{
				if(cur[i].sy <= top.sy && top.oper != zk)//��ǰ���������ȼ� <= ��һ���ȼ�����Ϊ�����ţ�
				{
					while(!Stack_Empty(&s) && top.oper != zk)//����г�ջ��������
					{
						top = Stack_Top(&s);
						next[j++] = top;
						Stack_Pop(&s);
					}
				}
				Stack_push(&s,cur[i]);//����ǰ��������ջ
			break;
			}
		case data:
			next[j++] = cur[i];
			break;
		case yk:
			while(!Stack_Empty(&s))//��ջ
			{
				top = Stack_Top(&s);
				if(top.oper != zk)
                next[j++] = top;
				Stack_Pop(&s);
			}
			break;
		case zk:
			cur[i].sy = Zk;
			Stack_push(&s,cur[i]);
			break;
		default:
		break;	
	    }
	}
	while(!Stack_Empty(&s))//��ջ��ʣ���������ջ
	{
	   top = Stack_Top(&s);
       next[j++] = top;
	   Stack_Pop(&s);
	}
}

cell Reverse_Polishu_Notation(cell * nota,const int size)//�沨�����ʽ
{
	int i=0;
	int num1;
	int num2;
	cell num;
	stack entry1;
	Stack_Init(&entry1);
    for(i=0;i<size;i++)
	{
		switch(nota[i].oper)
		{
		case add://+
			num1=Stack_Top(&entry1).size;
			Stack_Pop(&entry1);
			num2=Stack_Top(&entry1).size;
			Stack_Pop(&entry1);
			num.size=num2+num1;
			Stack_push(&entry1,num);
			break;
		case sub://-
			num1=Stack_Top(&entry1).size;
			Stack_Pop(&entry1);
			num2=Stack_Top(&entry1).size;
			Stack_Pop(&entry1);
			num.size=num2-num1;
			Stack_push(&entry1,num);
			break;
		case 2:// *
			num1=Stack_Top(&entry1).size;
			Stack_Pop(&entry1);
			num2=Stack_Top(&entry1).size;
			Stack_Pop(&entry1);
			num.size=num2*num1;
			Stack_push(&entry1,num);
			break;
		case 3:// /
			
			num1=Stack_Top(&entry1).size;
			Stack_Pop(&entry1);
			if(!num1)//��������Ϊ0
			{
			    printf("eorr!\n");
				return num;
			}
			num2=Stack_Top(&entry1).size;
			Stack_Pop(&entry1);
			num.size=num2/num1;
			Stack_push(&entry1,num);
			break;
		case 4:// ����,ѹջ
			Stack_push(&entry1,nota[i]);
			break;
		default:
			break;
		}
	}
	return Stack_Top(&entry1);
	//printf("%d\n",num);
}

void Handle(char* ch,cell* chu,size_t sz)//����
{
	int i = 0;
	int j = 0;
	for(i = 0;i < sz-1;i++)
	{
		switch(ch[i])
		{//{add,sub,mul,_div,data,yk,zk}tech;//�����
		case '+':
			(chu[j]).size = '+';
			(chu[j++]).oper = add;
			break;
		case '-':
			(chu[j]).size = '-';
			(chu[j++]).oper = sub;
			break;
		case '*':
			(chu[j]).size = '*';
			chu[j++].oper = mul;
			break;
		case '/':
			(chu[j]).size = '/';
			chu[j++].oper = _div;
			break;
		case '(':
			(chu[j]).size = '(';
			chu[j++].oper = zk;
			break;
		case ')':
			(chu[j]).size = ')';
			(chu[j++]).oper = yk;
			break;
		case ' ':
			break;
		default: //��ѭ��
			{
				int num = 0;
				while(ch[i] >= '0'&& ch[i] <= '9')
				{
					num += ch[i++] - '0';
					num *= 10;
				}
			  (chu[j]).size = num/10;
			  (chu[j++]).oper = data;
			  if(!(ch[i] >= '0'&& ch[i] <= '9'))
			  i--;
			}
			break;
		}
	}
}

void change_test()//����
{
	//�뽫���ȼ�ͬʱҲ����
	//cell cur[]={{2,data},{'*',mul,Mul},//��׺���ʽ
	//{'(',zk,Zk},{2,data},{'+',add,Add},{3,data},{'*',mul,Mul},
	//{'(',zk,Zk},{3,data},{'+',add,Add},{4,data},
	//{')',yk},
	//{')',yk},
	//{'/',_div,Div},{9,data},{'-',sub,Sub},{3,data},{'*',mul,Mul},{6,data}};

	cell cur[]={{2,data},{'*',mul},//��׺���ʽ
	{'(',zk},{2,data},{'+',add},{3,data},{'*',mul},
	{'(',zk},{3,data},{'+',add},{4,data},
	{')',yk},
	{')',yk},
	{'/',_div},{9,data},{'-',sub},{3,data},{'*',mul},{6,data}};

	cell * next ;//��׺���ʽ
	int size = sizeof(cur)/sizeof(cur[0]);//ͳ�Ƹ���
	cell num ;

	char ch[] = {"12*(2+3*(3+4))/276-3*6"};//˼��������δ�������
	size_t sz = sizeof(ch)/sizeof(ch[0]);

	cell* chu = NULL;
	cell* next2 = NULL;
	chu = (cell*)malloc(sizeof(cell)*sz);
	next2 = (cell*)malloc(sizeof(cell)*sz);

	Handle(ch,chu,sz);//�洢��ʽת��
	change(chu,next2,sz);//��׺ת��׺
	num = Reverse_Polishu_Notation(next2,sz);//�沨�����ʽ���м���
	printf("%d\n",num);
	free(chu);
	free(next2);

	//next = (cell*)malloc(sizeof(cell)*size);
	//change(cur,next,size);//��׺ת��׺
	//num = Reverse_Polishu_Notation(next,size);//�沨�����ʽ���м���
	//printf("%d\n",num);
	//free(next);
}


