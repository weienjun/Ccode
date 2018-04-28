/*
1. ��ʵ��λͼ�����²�������֤����ȷ�� 
typedef struct BitMap 
{ 
	size_t* _bitMap; 
	size_t _capacity; // �ռ�ĸ��� 
size_t _size; // ��Ч����λ�ĸ��� 
}BitMap; 

void InitBitMap(BitMap* bmp, size_t capacity); 
// ��Ϊ1 
void Set(BitMap* bmp, size_t which); 
// ��Ϊ0 
void ReSet(BitMap* bmp, size_t which); 

// ���ĳ������λ�Ƿ�Ϊ1 
int Test(BitMap* bmp, size_t which); 

size_t SizeBitMap(BitMap* bmp); 

// λͼ��1�ĸ��� 
size_t CountBitMap(BitMap* bmp); 

void DestroyBitMap(BitMap* bmp); 

2. ��Ϥ��¡��������ԭ��ʵ�����½ӿ� 
typedef char* DataType; 
typedef size_t (*PHF)(DataType); 
#define FUNCNUM 5 

typedef struct BloomFilter 
{ 
	BitMap _bmp; 
	PHF _HashFunc[FUNCNUM]; 
	size_t _size; 
}BF; 

//////////////////////////////////////////////////////////////////// 
// BloomFilter.h 
void InitBloomFilter(BF* bf, PHF hashFunc[FUNCNUM], size_t size); 
int InsertBF(BF* bf, DataType key); 
int IsInBloomFilter(BF* bf, DataType key); 
void DestroyBloomFilter(BF* bf); 
*/

#ifndef __BITMAP_H__

#define __BITMAP_H__

typedef size_t typeB;
typedef struct BitMap
{
	typeB* _data;
	size_t _size;//���ݸ���
	size_t _capacity;//����
}BitMap;

void Init_BitMap(BitMap* mp,size_t size);
int Insert_BitMap(BitMap* mp,typeB data);
void Set(BitMap* bmp, size_t which); 
// ��Ϊ0 
void ReSet(BitMap* bmp, size_t which); 
// ���ĳ������λ�Ƿ�Ϊ1 
int Test(BitMap* bmp, size_t which); 
size_t SizeBitMap(BitMap* bmp); 
// λͼ��1�ĸ��� 
size_t CountBitMap(BitMap* bmp); 
void DestroyBitMap(BitMap* bmp); 

void BitMap_test();


#endif

//λͼ��

//�����ݵ�״̬ʹ��bitλ��ʾ(1��ʾ���ڣ�0��ʾ������)
//��һ��ͼ������32��bitλ���ɱ�ʾ0~31������״̬,һ��������һ��bitλ��ʾ��32~63���ڵڶ������ݵı���λ�У�����

//�У�����data = {0,1,2,3,5,6,9,8,4,7,22,11} ;���ֵΪ22 ����Ҫ22��bitλ��(�������ݸ���ȷ��bitλ����ȷ���������ݸ���)
//������capacity = size>>5+1;  ͼ����λsize_t ���ͣ�
//bitλ0~7��ʾ����0~7֮���״̬���������ռ俪32��bitλ(ͼ����λsize_t ����)
//��ʾ������ͨ��ĳ��ӳ�䷽��ȷ�������ƹ�ϣ��
//�������ڵ�ͼ��λ�ã�idx = ����>>5  (����%32 ��ȡ����ӳ����±�)
//��������ͼĳλ������ռ��bitλ����1��bmp->_data[idx] |= (1 << which%32)
//��������ͼĳλ������ռ��bitλ����0��bmp->_data[idx] &= ~(1 << which%32)

//λͼ��ֵ�ԣ����ݣ����������ݸ���
//��ʼ���������ڴ�ռ䣬��С--->����Ԫ�ظ���>>5+1��Ԫ�ظ���/32+1��+1��Ϊ�˴�����Ϊ0�����⣩
//��ʼ��λͼ�е�ÿ������λΪ0

//ͳ���ж��ٸ�1
//ÿ����������Ӧ��Ϊ1��bitλ�ĸ���(λ���ݱ�bitCount)
//λ���ݱ�char* bitCount = "\0\1\1\2\1\2\2\3\1\2\3\2\3\3\4" (�ĸ�bitλ�����г���Ϊ1�Ŀ���0~16)
//ѭ�� i < capacity
//{
//j = 0;
//size_t value = bmp->_data[i];//ȡһ��size_t ���͵�����
//ѭ��(j < 4)//��һ������������ռ1�ĸ���
//{
//ȡһ���ֽ� char ch = value;
//count += bitCount[ch&0x0F];//����0~3bitλ��1�ĸ���
//ch >> 4;
//count += bitCount[ch&0x0F];//����4~7bitλ��1�ĸ���
//ch >> 8;//ȡ��һ���ֽڵĵ�0bitλ
//j++;//ȡ��һ���ֽ�
//}
//}