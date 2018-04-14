#ifdef __SEQLEST_H__

#define __SEQLEST_H__


#endif

#define MAX_SIZE 10 //数组大小
typedef int type;  //重定义类型名

//定义一个顺序表
typedef struct seqlist
{
	type arr[MAX_SIZE]; //定义一个的数组
	int size; //数组有效元素个数，及当前操作第几个元素（1表示下标为0的元素，0表示无有效值）
}seqlist,*qseqlist; //新的类型名

void Init(qseqlist  arr,const int count);//初始化

void Print(const qseqlist arr);//输出
void Tail_Plug(qseqlist arr,const type data);//尾插
void Tail_Delete(qseqlist arr);//尾删
void Head_Plug(qseqlist arr,const type data);//头插
void Head_Delete(qseqlist arr);//头删
void Plug(qseqlist arr,const int pos,const type data);//插入
void Delete(qseqlist arr,const int pos);//删除
void Delete1(qseqlist arr,const type data);//删除数据data
void Delete2(qseqlist arr,const type data);//删除所有数据data

void Remove_all(qseqlist arr,const type data);//删除所有数据data，方法2

int SeqListEmpty(qseqlist arr); //判断顺序表是否为空，空返回1
int  search(qseqlist arr,const type data);//查找数据，-1表示未找到，找到返回下标