#include<stdio.h>
#include"test2.h"
//c��֧�����أ�����ͬһ����Ŀ�в��ɳ�����ͬ�ĺ�����
//ͬһ���ļ��о��Բ��ɳ��֣���ͬ�ļ�����ͬ�ĺ�������Ҫ����static����ָ��ֻ���ڱ��ļ���ʹ�ã��Ӷ�������ͬ
static void Fun()
{
	printf("test2\n");
}

void test2()
{
	Fun();
}