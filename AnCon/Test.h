#ifdef __TEST_H__

#define __TEST_H__



#endif 

#define MAX_SIZE 100 //·���ַ�����
#define N 20 //�ļ����ַ�����

typedef enum Category{
	c,
	cpp,
	eof,
	txt
}category;

void Trf(FILE * pfi,FILE * pfo);//�ж�
void ftxt(FILE * pfi,FILE * pfo);//�ı�����
void fcpp(FILE * pfi,FILE * pfo);//cpp����
void fc(FILE * pfi,FILE * pfo);//c����
void fname(const char address[],int size);//���ļ���
//int menu(char address1[],char address2[],FILE * pfi,FILE * pfo);//��ӡ�˵�
void menu(void);
void boss(char address1[],char address2[]);//��ʼ
void print(const char address1[],const char address2[]);//���
void xcpp(FILE * pfi,FILE * pfo);//ѡ��ע��
void fcopy(FILE * pfi,FILE * pfo);//����
void fcancel(FILE * pfi,FILE * pfo);//ȡ��ע��
FILE * pand(FILE * pf,char address[],char *fa);//�ж�·��