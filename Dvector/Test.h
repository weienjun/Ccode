#ifdef __TEST_H__

#define __TEST_H__

#endif 

typedef  int type;

typedef struct Seqlist//��̬˳���
{
	type * num;//�洢����
	unsigned int size; //ͳ�����ݸ������ͱ�����ݣ��൱�������±�����
    unsigned int n_size; //������һ�ο����ڴ�ռ��С
}seqlist;

void seq_init(seqlist * q);//��ʼ��
void print(const seqlist *q);//���
int seq_delete(seqlist * q,const type data);//ɾ��data
int seq_delete_all(seqlist * q,const type data);//ɾ������data
int seq_search(seqlist * q,const type data);//����
int seq_size(seqlist * q);//��ȡ����
void seq_addsize(seqlist * q);//����
void seq_clear(seqlist * q);//���
void seq_clearseq(seqlist * q);//����
void seq_put(seqlist * q, const int pos,const int data);//����λ�ò���
