
/*
//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果 
//A选手说：B第二，我第三； 
//B选手说：我第二，E第四； 
//C选手说：我第一，D第二； 
//D选手说：C最后，我第三； 
//E选手说：我第四，A第一； 
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。 
#include<stdio.h>  
#include<stdlib.h>
int main()  
{  
	  
int A = 0,B = 0,C = 0,D = 0,E = 0;  
for(A=1;A<=5;A++)  
{  
    for(B=0;B<=5;B++)  
    {  
        for(C=0;C<=5;C++)  
        {  
            for(D=0;D<=5;D++)  
            {  
				for(E=0;E<=5;E++)//这里将所有人说的话罗列出来，并且每个只说对了一半，所以他们每个人说的话加起等于1.  
				if(((B==2)+(A==3)==1)&&  
				((B==2)+(E==4)==1)&&  
				((C==1)+(D==2)==1)&&  
				((C==5)+(D==3)==1)&&  
				((A==1)+(E==4)==1))  
 {//因为名次是连续的，所以在这里做个处理：假设A=4，B=2，C=2，D=3，E=5；对假设作出判断下面进行分析  
					int num = 0;  
	                int flag = 1;
					num |=(1<<(A-1));  
					num |=(1<<(B-1));  
					num |=(1<<(C-1));  
					num |=(1<<(D-1));  
					num |=(1<<(E-1));  
					while(num)//判断名次是否连续，如果连续就输出  
					{  
						if(num%2==0)  
						{  
							flag=0;  
						}  
					num/=2;    
				}  
				 if(flag==1)  
                printf("A=%d B=%d C=%d D=%d E=%d\n",A,B,C,D,E);
                }  
             }  
         }  
      }
	  
  }  
system("pause");
    return 0;  
}  


*/


/*

//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯 
//的一个。以下为4个嫌疑犯的供词。 
//A说：不是我。 
//B说：是C。 
//C说：是D。 
//D说：C在胡说 
//已知3个人说了真话，1个人说的是假话。 
//现在请根据这些信息，写一个程序来确定到底谁是凶手。 
#include<stdio.h>  
#include<stdlib.h>
int main()  
{  
int i=0,a=0,b = 0,c = 0,d = 0;  
int nd = 0;  
for(i=1;i<=4;i++)//在这里有4中可能，所以用for循环循环四次
{  
        if(i==1)//假设A说了谎  
        {  
            a=1;c=1;nd=1;d=0;  
        }  
        if(i==2)//假设B说了谎  
        {  
            a=0;c=0;nd=1;d=0;  
        }  
        if(i==3)//假设C说了慌  
        {  
            a=0;c=1;nd=0;d=0;  
        }  
        if(i==4)//假设D说了慌
        {  
            a=0;c=1;nd=1;d=0;  
        }  
    if((a+b+c+d+nd==1)&&(nd==d))
	{
	printf("说假话的值为1！\n");
	printf("a=%d b=%d c=%d d=%d\n",a,b,c,d);  
	}
    }  
    system("pause");
    return 0;  
}

*/


/*

//3.在屏幕上打印杨辉三角。 
#include<stdio.h>
#include<stdlib.h>
int main()
{
int n = 0;
int k=0;
int i = 0, j = 0;
int arr[30][30];

printf("请输入需要打印的杨辉三角的行数： ");
scanf("%d", &n);

for (i = 1; i < n; i++)
{
arr[i][1] = 1;
arr[i][i] = 1;
}
for (i = 3; i < n;i++)
for (j = 2; j <= i - 1; j++)
{
arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
}
for (i = 1; i < n; i++)
{
	for(k=n-i;k>0;k--)
	{
		printf(" ");
	}
	for (j = 1; j <= i; j++)
	{
	printf("%2d ", arr[i][j]);
	}
	printf("\n");
}
system("pause");
return 0;
}


*/

