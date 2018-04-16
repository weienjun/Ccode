
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
//	Reverse_Polishu_Notation(nota,size);//逆波兰表达式
//}

/*
void  Kuohao_test(void)
{
	char  arr[]="(())abc{[(]}";
	char  arr1[]="(())abc{[]}";
	char  arr2[]="((())abc{[]}";
	char  arr3[]="(())abc{[]}}";

    Kuohao(arr);//括号判断
    Kuohao(arr1);//括号判断
    Kuohao(arr2);//括号判断
    Kuohao(arr3);//括号判断
}
*/
/*
void Reverse_Polishu_Notation(cell * nota,const int size)//逆波兰表达式
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
		case 4:// 数据,压栈
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
void Kuohao(char * arr)//括号判断
{
	int i=0;
	int sz=strlen(arr)+1;
	stack entry;
	Stack_Init(&entry);
	for(i=0;i<sz;i++)
	{
		if(arr[i]  == '(' || 
		    arr[i] == '[' ||
			arr[i] == '{')//入栈
		{
		Stack_push(&entry,arr[i]);
		}

		else if(arr[i] == ')' ||
			    arr[i] == ']' ||
				arr[i] == '}')
		{
			if(Stack_Empty(& entry))//栈为空
			{
				printf("右比左多！\n");
				break;
			}
			else if((arr[i] == ')' && Stack_Top(&entry) == '(') ||
				    (arr[i] == ']' && Stack_Top(&entry) == '[') ||
					(arr[i] == '}' && Stack_Top(&entry) == '{'))//比较栈顶元素
					Stack_Pop(&entry);//出栈
			else
			{
				printf("括号不匹配！\n");
				break;
			}
		}
	}
	if(!Stack_Empty(&entry)&& i >= sz)
	{
		printf("左括号比右括号多！\n");
	}
	else if(i == sz)
		printf("括号正确\n");
}
*/


void change(cell* cur,cell* next,const int size)//中缀转后缀
{
	stack s;
	cell top ;
	int i = 0 ;
	int j = 0 ;

	Stack_Init(&s);
	for(i = 0 ;i < size ; i++)
	{
		if(!Stack_Empty(&s))//栈不为空取栈顶，为空的话不取，会将符号入栈（除')'）
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
			cur[i].sy = (cur[i].oper == add || cur[i].oper == sub)? Sub : Div;//+ - 优先级相同
			{
				if(cur[i].sy <= top.sy && top.oper != zk)//当前操作符优先级 <= 上一优先级（不为左括号）
				{
					while(!Stack_Empty(&s) && top.oper != zk)//则进行出栈至左括号
					{
						top = Stack_Top(&s);
						next[j++] = top;
						Stack_Pop(&s);
					}
				}
				Stack_push(&s,cur[i]);//将当前操作符入栈
			break;
			}
		case data:
			next[j++] = cur[i];
			break;
		case yk:
			while(!Stack_Empty(&s))//将栈
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
	while(!Stack_Empty(&s))//将栈中剩余操作符出栈
	{
	   top = Stack_Top(&s);
       next[j++] = top;
	   Stack_Pop(&s);
	}
}

cell Reverse_Polishu_Notation(cell * nota,const int size)//逆波兰表达式
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
			if(!num1)//除数不可为0
			{
			    printf("eorr!\n");
				return num;
			}
			num2=Stack_Top(&entry1).size;
			Stack_Pop(&entry1);
			num.size=num2/num1;
			Stack_push(&entry1,num);
			break;
		case 4:// 数据,压栈
			Stack_push(&entry1,nota[i]);
			break;
		default:
			break;
		}
	}
	return Stack_Top(&entry1);
	//printf("%d\n",num);
}

void Handle(char* ch,cell* chu,size_t sz)//处理
{
	int i = 0;
	int j = 0;
	for(i = 0;i < sz-1;i++)
	{
		switch(ch[i])
		{//{add,sub,mul,_div,data,yk,zk}tech;//运算符
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
		default: //死循环
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

void change_test()//测试
{
	//须将优先级同时也传入
	//cell cur[]={{2,data},{'*',mul,Mul},//中缀表达式
	//{'(',zk,Zk},{2,data},{'+',add,Add},{3,data},{'*',mul,Mul},
	//{'(',zk,Zk},{3,data},{'+',add,Add},{4,data},
	//{')',yk},
	//{')',yk},
	//{'/',_div,Div},{9,data},{'-',sub,Sub},{3,data},{'*',mul,Mul},{6,data}};

	cell cur[]={{2,data},{'*',mul},//中缀表达式
	{'(',zk},{2,data},{'+',add},{3,data},{'*',mul},
	{'(',zk},{3,data},{'+',add},{4,data},
	{')',yk},
	{')',yk},
	{'/',_div},{9,data},{'-',sub},{3,data},{'*',mul},{6,data}};

	cell * next ;//后缀表达式
	int size = sizeof(cur)/sizeof(cur[0]);//统计个数
	cell num ;

	char ch[] = {"12*(2+3*(3+4))/276-3*6"};//思考负数如何处理？？？
	size_t sz = sizeof(ch)/sizeof(ch[0]);

	cell* chu = NULL;
	cell* next2 = NULL;
	chu = (cell*)malloc(sizeof(cell)*sz);
	next2 = (cell*)malloc(sizeof(cell)*sz);

	Handle(ch,chu,sz);//存储格式转化
	change(chu,next2,sz);//中缀转后缀
	num = Reverse_Polishu_Notation(next2,sz);//逆波兰表达式进行计算
	printf("%d\n",num);
	free(chu);
	free(next2);

	//next = (cell*)malloc(sizeof(cell)*size);
	//change(cur,next,size);//中缀转后缀
	//num = Reverse_Polishu_Notation(next,size);//逆波兰表达式进行计算
	//printf("%d\n",num);
	//free(next);
}


