#ifdef __SEQLEST_H__

#define __SEQLEST_H__


#endif

#define MAX_SIZE 10 //�����С
typedef int type;  //�ض���������

//����һ��˳���
typedef struct seqlist
{
	type arr[MAX_SIZE]; //����һ��������
	int size; //������ЧԪ�ظ���������ǰ�����ڼ���Ԫ�أ�1��ʾ�±�Ϊ0��Ԫ�أ�0��ʾ����Чֵ��
}seqlist,*qseqlist; //�µ�������

void Init(qseqlist  arr,const int count);//��ʼ��

void Print(const qseqlist arr);//���
void Tail_Plug(qseqlist arr,const type data);//β��
void Tail_Delete(qseqlist arr);//βɾ
void Head_Plug(qseqlist arr,const type data);//ͷ��
void Head_Delete(qseqlist arr);//ͷɾ
void Plug(qseqlist arr,const int pos,const type data);//����
void Delete(qseqlist arr,const int pos);//ɾ��
void Delete1(qseqlist arr,const type data);//ɾ������data
void Delete2(qseqlist arr,const type data);//ɾ����������data

void Remove_all(qseqlist arr,const type data);//ɾ����������data������2

int SeqListEmpty(qseqlist arr); //�ж�˳����Ƿ�Ϊ�գ��շ���1
int  search(qseqlist arr,const type data);//�������ݣ�-1��ʾδ�ҵ����ҵ������±�