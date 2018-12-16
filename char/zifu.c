#include<stdio.h>
int main()
{
	int i;
	char a[5]={'1','2','3','4','5'};
	for (i=0;i<5;i++)
	{
	printf("%c",a[i]);
    }
    printf("\n");
    char b;
    for(i=0;i<=5/2;i++)
    {
    	b=a[i];
    	a[i]=a[5-i-1];
    	a[5-i-1]=b;
	}
	for (i=0;i<5;i++)
	{
	printf("%c",a[i]);
 } 
}
