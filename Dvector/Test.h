#ifdef __TEST_H__

#define __TEST_H__

#endif 

typedef  int type;

typedef struct Seqlist//动态顺序表
{
	type * num;//存储数据
	unsigned int size; //统计数据个数，和标记数据，相当与数组下标作用
    unsigned int n_size; //容量，一次开辟内存空间大小
}seqlist;

void seq_init(seqlist * q);//初始化
void print(const seqlist *q);//输出
int seq_delete(seqlist * q,const type data);//删除data
int seq_delete_all(seqlist * q,const type data);//删除所有data
int seq_search(seqlist * q,const type data);//查找
int seq_size(seqlist * q);//获取容量
void seq_addsize(seqlist * q);//增容
void seq_clear(seqlist * q);//清空
void seq_clearseq(seqlist * q);//销毁
void seq_put(seqlist * q, const int pos,const int data);//任意位置插入
