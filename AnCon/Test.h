#ifdef __TEST_H__

#define __TEST_H__



#endif 

#define MAX_SIZE 100 //路径字符个数
#define N 20 //文件名字符个数

typedef enum Category{
	c,
	cpp,
	eof,
	txt
}category;

void Trf(FILE * pfi,FILE * pfo);//判断
void ftxt(FILE * pfi,FILE * pfo);//文本操作
void fcpp(FILE * pfi,FILE * pfo);//cpp操作
void fc(FILE * pfi,FILE * pfo);//c操作
void fname(const char address[],int size);//求文件名
//int menu(char address1[],char address2[],FILE * pfi,FILE * pfo);//打印菜单
void menu(void);
void boss(char address1[],char address2[]);//开始
void print(const char address1[],const char address2[]);//输出
void xcpp(FILE * pfi,FILE * pfo);//选择注释
void fcopy(FILE * pfi,FILE * pfo);//复制
void fcancel(FILE * pfi,FILE * pfo);//取消注释
FILE * pand(FILE * pf,char address[],char *fa);//判断路径