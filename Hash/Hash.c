#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include"Hash.h"

//素数表
static const unsigned long _Primelist[_pMax] =
{
	3ul,7ul,21ul,53ul, 97ul,193ul,389ul,769ul,
	1543ul,3097ul,6151ul,12289ul,
	49157ul,98317ul,196613ul,393241ul
};

void InitHashTableD(HTD* ht,size_t sz,Compare com)//初始化
//void InitHashTableD(HTD* ht,size_t sz)//初始化
{
	size_t i = 0;
	assert(ht);
	ht->_capacity = achievePrm(sz);//获取素数
	ht->_size = 0;
	ht->_com = com;
	ht->_Data = (EndmD*)malloc(sizeof(EndmD)*ht->_capacity);
	assert(ht->_Data);
	for(; i < ht->_capacity; i++)
		ht->_Data[i]._state = EmptyD;//状态置空
}

size_t achievePrm(size_t sz)//获取素数
{
	size_t i = 0;
	size_t tmp = sz;
	for(; i < _pMax; i++)
	{
		if(sz < _Primelist[i] && tmp < _Primelist[i])
		  return _Primelist[i];
		sz = _Primelist[i];
	}
	return _Primelist[_pMax];
}

size_t DetectiveLineD(HTD* ht,size_t key)//线性探测
{
	key++;
	if(key >= ht->_capacity)
		key = 0;
	return key;
}

size_t DeletectiveTwoD(HTD* ht,size_t key1)//二次探测
{
	int i = 0;
	key1 = key1 + 2*i+1;
	while(ht->_Data[key1]._state == ExistD)
	{
		if(key1 >= ht->_capacity)
			key1 = key1%ht->_capacity;//不可直接取0位置，否则越界后一直查找0的位置
		i++;
		key1 = key1 + 2*i+1;
	}
	return key1;
}

void AddSeraveD(HTD* ht,size_t key)//扩容
{
	if(((ht->_size*10)/ht->_capacity) > 7)//大于平衡因子扩容
	{
		size_t i = 0;
		HTD tmph ;//临时哈希表
		//InitHashTableD(&tmph,ht->_capacity*2);
		InitHashTableD(&tmph,ht->_capacity*2,ht->_com);
		tmph._size = ht->_size;
		//放入数据
		//不可使用此方法,由于扩容后，容量不同，数据不在对应于新空间的位置(映射不正确)，应重新插入，重新映射
		//memcpy(tmph._Data,ht->_Data,sizeof(Endm)*ht->_size);
		for(; i < ht->_capacity; i++)
		{
			if(ht->_Data[i]._state == ExistD)//只移动有效数据
				InsertHashTableD(&tmph,ht->_Data[i]._data);//插入
		}
		//交换哈希表的内容
		Swap(ht,&tmph);

		free(tmph._Data);//数字和字符串交换方法不同？？？
		tmph._Data = NULL;
	}
}

void Swap(HTD*ht,HTD* tmph)//交换
{
	size_t sz = 0;
	size_t i = 0;
	
	//数据交换
	for(; i < ht->_capacity; i++)
	{
		if(ht->_Data[i]._state == ExistD)
		{
			EndmD tmpe = ht->_Data[i];//直接地址交换
			ht->_Data[i] = tmph->_Data[i];
			tmph->_Data[i] = tmpe;
		}
	}
	/*
	EndmD* tmpe = ht->_Data;//直接地址交换
	ht->_Data = tmph->_Data;
	tmph->_Data = tmpe;
	*/
	//容量交换
	sz = ht->_capacity;
	ht->_capacity = tmph->_capacity;
	tmph->_capacity = ht->_capacity;
}

size_t HashFunkD(HTD* ht,type data)//哈希函数(获取映射地址)
{
	//将容量设置为素数即可
	//return data % (ht->_capacity);//此处应模取最接近(<=容量)容量的素数
	return ht->_com(data) % (ht->_capacity);
}

void InsertHashTableD(HTD* ht,type data)//插入
{
	size_t key = 0;
	AddSeraveD(ht,key);//扩容处理
	key = HashFunkD(ht,data);//哈希函数(获取映射地址)
	//寻找可插入位置（空，或删除非空）
	while(ht->_Data[key]._state == ExistD)
	{
		//线性探测
		//key = DetectiveLineD(ht,key);
		//二次探测
		key = DeletectiveTwoD(ht,key);//二次探测
	}
	//ht->_Data[key]._data = 1;
	ht->_Data[key]._data = data;
	ht->_Data[key]._state = ExistD;
	ht->_size++;
}

int FindHashTableD(HTD* ht,type data)//查找
{
	size_t key = HashFunkD(ht,data);//哈希函数(获取映射地址)
	size_t tmp = key;//标记起始查找地址
	assert(ht);
	if(ht->_size == 0)
		return -1;

	while(ht->_Data[key]._state != EmptyD)
	{
		//if(key == data)//字符应用处理添加
		//return key;

		if(ht->_Data[key]._data == data)
			return key;
		//线性探测
		//key = DetectiveLineD(ht,key);
		//二次探测
		key = DeletectiveTwoD(ht,key);//二次探测

		if(key == tmp)//再次到达key--->未找到
			break;
	}
	return -1;
}

void DeleteHashTableD(HTD* ht,type data)//删除
{
	size_t key = 0;
	assert(ht);
	key = FindHashTableD(ht,data);//查找
	if(key < 0)//未找到
		return ;
	ht->_Data[key]._state = DExistD;
	ht->_size--;
}

void PrintHashTableD(HTD* ht)
{
	size_t i = 0;
	while(i < ht->_capacity)
	{
		if(ht->_Data[i]._state == ExistD)
			printf("%s ",ht->_Data[i]._data);
		i++;
	}
	printf("\n");
}

static size_t BKDRHash(const char* str)//字符串哈希算法(字符串转数值)
{
	unsigned int seed = 131;
	unsigned int hash = 0;
	while(*str)
	{
		hash = hash * seed + (*str++);
	}
	return (hash & 0x7FFFFFFF);
}

static size_t intBKDRHash(const type data)//字符数字处理
{
	return (unsigned int)data;
}

void Hash_testD()//测试
{
	HTD ht;
	
    InitHashTableD(&ht,2,BKDRHash);//初始化,当作字符串
    InsertHashTableD(&ht,"123");//    InsertHashTableD(&ht,"123");//插入
    InsertHashTableD(&ht,"12");//插入
    DeleteHashTableD(&ht,"123");//删除
    InsertHashTableD(&ht,"11");//插入
    InsertHashTableD(&ht,"456");//插入
    InsertHashTableD(&ht,"4567");//插入
    InsertHashTableD(&ht,"4567");//插入
    InsertHashTableD(&ht,"489705");//插入
	/*
    InitHashTableD(&ht,4,intBKDRHash);//初始化
    InsertHashTableD(&ht,1);//插入
    InsertHashTableD(&ht,3);//插入
    DeleteHashTableD(&ht,1);//删除
    InsertHashTableD(&ht,11);//插入

	//PrintHashTableD(&ht);
	
    InsertHashTableD(&ht,1);//插入
   // InsertHashTableD(&ht,9);//插入
    InsertHashTableD(&ht,2);//插入
    InsertHashTableD(&ht,8);

	PrintHashTableD(&ht);
	InsertHashTableD(&ht,17);//插入

	InsertHashTableD(&ht,9);//插入
    InsertHashTableD(&ht,12);//插入
    InsertHashTableD(&ht,18);//插入
    InsertHashTableD(&ht,20);//插入

    //printf("%d\n",FindHashTableD(&ht,2));//查找
    DeleteHashTableD(&ht,1);//删除
    InsertHashTableD(&ht,21);//插入
    InsertHashTableD(&ht,24);//插入
	*/
	PrintHashTableD(&ht);
}

/*
//字符应用处理
void Application_test()
{
	char ch[] = {"ahabccdssdfzkycbabcsd"};
	int i = 0;
	size_t sz = sizeof(ch)/sizeof(ch[0]);
	HT hc;
	InitHashTable(&hc);//初始化
	AddSerave(&hc,255);//扩容
	//根据字符对应的数值，放在对应的哈希表地址中,表中存储的是个数
	for(; i < sz; i++)
	{
		//int c = FindHashTable(&hc,2);//返回下标---下标即为字符的ASCLL
		if(FindHashTable(&hc,ch[i]) == ch[i])
			hc._Data[ch[i]]._data++;
		else
			 InsertHashTable(&hc,ch[i]);//插入
	}
	//遍历字符串，找出出现次数为1的字符
	for(i = 0; i < sz; i++)
	{
		int key = FindHashTable(&hc,ch[i]);
		if(hc._Data[key]._data == 1)
		{
			printf("%c ",ch[i]);
			//break;
		}
	}
}
*/
//哈希表
//将数据存储在顺序表中，存储时按某种映射关系(哈希函数)存储在对应的下标处。
//哈希函数：hf(Key) = A*Key+1;
//哈希函数：
//1、直接定制法：
//直接根据数据与下标的关系，确定映射

//应用：求一个字符串中第一次只出现一次的字符
//解：建一个大小为256(最多有256种字符)的哈希表
//根据字符的数值，作为对应的下标，数组中放出现的次数（循环遍历一次所有数据）
//遍历字符串中的字符，确定那个字符第一次出现，返回字符即可

//除留余数法：
//地址(下标) = 数据 % p；(p是最接近哈希大小的素数（p <= max_size）)

//哈希冲突：
//原因：哈希函数的不合理
//哈希冲突是无法避免的，
//解决：闭散列
//冲突检测：使用位置状态标记的方法：三种状态：空，非空，删除非空
//方法：冲突后，将数据放在冲突位置的后面的空位处(每个位置有三种状态：空，不空，删除不空)
//线性探测：查找时从映射的地址处开始向后找，直到找到(数据相同)或遇到空位退出
//注：若到达最后一个元素还未找打，则返回到表的起始位置，继续向后找
//插入：映射的地址状态为空--->直接插入，不为空--->查找从该地址后查找插入位置
//插入位置查找与查找类似，插入在空(或删除非空)位置处，插入前线检侧是否表满，表满扩容
//查找：计算映射地址，从映射地址处开始查找，直到找到数据或遇到空位置退出(注意：回到起始查找位置也应退出)
//删除仅将删除为位置状态更改为 删除不空 （注：退出条件防止出现死循环，回到起始位置也应退出）

//线性探测缺陷：数据堆积(一但发生冲突，就会容易连续发生冲突)
//数据越多也容易发生冲突，
//解决方法：1、使用负载因子控制扩容，2、采用二次探测不使用顺序探测
//负载因子：size/capacity <= 0.7~0.8 效率较高
//          size*10/capacity <= 7~8（*10是处理整型除法问题）
//二次探测：
//H(i+1) = Hi + (2*i+1);(i = 0, 1,2,3...)
//缺陷：当容量快满时，会一直查找空位，导致效率低
//解决方法：使用控制负载因子增容--->以空间换时间


//综上待处理问题
//1、动态增容----如何使用负载因子增容
//如何将数据放回到新空间，不可直接内存复制？，使用诼个插入的方法(只插入有效元素)，交换哈希表的内容，释放旧空间
//2、哈希函数中，%素数，素数如何查找
//
//3、存储字符串，时如何求映射地址？
//除留余数法：如何处理 字符串取模问题？
//解决方法：字符串转化成整型
//1、将每个字符对应的ASCLL数值相加
//2、字符哈希算法，将字符串转化成数字
//3、使用函数指针，将所有字符串数据类型转换成整型
//注：哈希表结构体中，添加一个函数指针类型变量，用于转化数据类型


//开散列(开链法)
//哈希桶：哈希表中存放的不在是数据，而是具有相同映射关系的链表的表头
//哈希表中存的是一个结构体指针变量，二级指针，由于哈希表存的是一组数据(一级指针)，每个位置为一个链表(二级指针)
//缺点：当冲突比较大时，查找数据的时间复杂度增大(变成链表查找)
//解决放法：空间增容---重新计算映射地址，重排布(增容时机：链表长接近桶容量时增容)


