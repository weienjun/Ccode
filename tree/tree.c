#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"tree.h"
#include"stack.h"
#include"Queue.h"
// ���������� 
void CreateBinTree(PBTNode* pRoot, BTDataType* array, int size, BTDataType invalid)
{
	int index = 0;
	_CreateBinTree(pRoot,array,size,&index,invalid);//�ݹ鴴����ע�����β��ܸı���ֵ���ݣ������贫��ַ(index)������ݹ���˻ᷢ������
}

void _CreateBinTree(PBTNode* pRoot, BTDataType* array, int size, int* index, BTDataType invalid)//�ı�ָ�����ݣ����Դ�����ָ��
{
	if(array[*index] == invalid)
	{
		return ;
	}
	if(*index < size && array[*index] != invalid)//ֵ�Ϸ�
	{
		(*pRoot) = BuyBinTreeNode(array[*index]);//�����ڵ�
		++(*index);
		_CreateBinTree(&(*pRoot)->_pLeft,array,size,index,invalid);//�ı�ָ�����ݣ����Դ�����ָ��
		if((*pRoot)->_pLeft)
			(*pRoot)->_pLeft->_parent = *pRoot;
		++(*index);
		_CreateBinTree(&(*pRoot)->_pRight,array,size,index,invalid);//�ı�ָ�����ݣ����Դ�����ָ��
		if((*pRoot)->_pRight)
			(*pRoot)->_pRight->_parent = *pRoot;
	}
}
//�����ڵ�
PBTNode BuyBinTreeNode(BTDataType data)
{
	PBTNode Newnode = NULL;
	Newnode = (PBTNode)malloc(sizeof(BTNode));
	Newnode->_data = data;
	Newnode->_pLeft = NULL;
	Newnode->_pRight = NULL;
	Newnode->_leftpag = LINK;
	Newnode->_rightpag = LINK;
	return Newnode;
}

// ���� 
PBTNode CopyBinTree(PBTNode pRoot)
{
	PBTNode New = NULL;
	if(pRoot == NULL)
		return NULL;
	else
	{
		New = BuyBinTreeNode(pRoot->_data);//�½ڵ�
		New->_pLeft = CopyBinTree(pRoot->_pLeft);
		New->_pRight = CopyBinTree(pRoot->_pRight);
	}
	return New;
}

// ǰ��ݹ���� 
void PreOrder(PBTNode pRoot)
{
	if(pRoot)
	{
		printf("%c ",pRoot->_data);
		PreOrder(pRoot->_pLeft);
		PreOrder(pRoot->_pRight);
	}
}

// ǰ��ǵݹ� 
void PreOrderNor(PBTNode pRoot)
{
	stack entry;
	PBTNode cur = pRoot;
	if(pRoot == NULL)
	{
		return ;
	}
	Stack_Init(&entry);//��ʼ��ջ
	Stack_push(&entry,pRoot);
	while(!Stack_Empty(&entry))
	{
		cur = Stack_Top(&entry);
		printf("%c ",cur->_data);
		Stack_Pop(&entry);//���ɷ��ں��棬��������������Ҫ��ջ�����ȳ�ջ��������ջ

		if(cur->_pRight)
			Stack_push(&entry,cur->_pRight);
		if(cur->_pLeft)
		{
			Stack_push(&entry,cur->_pLeft);
		}
	}
}
// ����ݹ� 
void InOrder(PBTNode pRoot)
{
	if(pRoot != NULL)
	{
		InOrder(pRoot->_pLeft);
		printf("%c ",pRoot->_data);
		InOrder(pRoot->_pRight);
	}
}
// ����ǵݹ� 
void InOrderNor(PBTNode pRoot)
{
	stack entry;
	PBTNode cur = pRoot;
	if(pRoot == NULL)
		return ;
	Stack_Init(&entry);//��ʼ��ջ
	while(cur || !Stack_Empty(&entry))
	{
		while(cur)
		{
	         Stack_push(&entry,cur);
			 cur = cur->_pLeft;
		}
		cur = Stack_Top(&entry);
		printf("%c ",cur->_data);
		Stack_Pop(&entry);//���ɷ��ں��棬��������������Ҫ��ջ�����ȳ�ջ��������ջ

		cur = cur->_pRight;
	}
}
// �����ݹ� 
void PostOrder(PBTNode pRoot)
{
	if(pRoot)
	{
		PostOrder(pRoot->_pLeft);
		PostOrder(pRoot->_pRight);
		printf("%c ",pRoot->_data);
	}
}

//����ǵݹ� 
void PostOrderNor(PBTNode pRoot)
{
	stack entry;
	PBTNode cur = pRoot;
	PBTNode prev = pRoot;
	if(pRoot == NULL)
		return ;
	Stack_Init(&entry);//��ʼ��ջ
    while(!Stack_Empty(&entry))
	{
		while(cur)//�ߵ������
		{
	         Stack_push(&entry,cur);
			 cur = cur->_pLeft;
		}
		//ȡջ��
		cur = Stack_Top(&entry);
		//����ջ��
		if(cur->_pRight == NULL && cur != prev)
		{
			printf("%c ",cur->_data);
			prev = cur;
			Stack_Pop(&entry);//���ɷ��ں��棬��������������Ҫ��ջ�����ȳ�ջ��������ջ
		}
		//��������
		cur = cur->_pRight;
	}
}
//�������Ľڵ����
int Size(PBTNode pRoot)
{
	size_t count = 0 ;
	stack entry;
	PBTNode cur = pRoot;
	if(pRoot == NULL)
		return 0;
	Stack_Init(&entry);//��ʼ��ջ
	Stack_push(&entry,pRoot);
    while(!Stack_Empty(&entry))
	{
		cur = Stack_Top(&entry);
		count++;
		Stack_Pop(&entry);

		if(cur->_pLeft)
			Stack_push(&entry,cur->_pLeft);
		if(cur->_pRight)
			Stack_push(&entry,cur->_pRight);
	}
	return count;
}

// ���������Ҷ�ӽ��ĸ��� 
int GetLeafCount(PBTNode pRoot)
{
	static size_t count = 0;
	if(pRoot != NULL)
	{
		if(pRoot->_pLeft == NULL && pRoot->_pRight == NULL)
			++count;
		GetLeafCount(pRoot->_pLeft);
		GetLeafCount(pRoot->_pRight);
	}
	return count;
}

//�ݹ鷨��K-1��ĸ���
//1�����ջ�K=0 ����0
//2��K=1 ����1
//3�������������������ݹ���K-1��ĸ��������ĺ�
int GetKLevel(PBTNode pRoot, int K)// ��ȡ��K���н����� 
{
	if(pRoot == NULL || K == 0)
		return 0;
	if(K == 1)
		return 1;
	return GetKLevel(pRoot->_pLeft,K-1) + GetKLevel(pRoot->_pRight,K-1);
}

// ��ȡ�������ĸ߶� 
//1��ʹ��������������ʼֵΪ1
//2���ֱ�ȥ�ݹ������������
//3�����ҽڵ�������һ����Ϊ��ʱ�����ؼ��������ֵ+1
//ʹ����Ŀ����������+1
int Height(PBTNode pRoot)
{
	static size_t n1 = 1;
	static size_t n2 = 1;
	static size_t n = 0;
	if(pRoot == NULL)
		return 0;
	Height(pRoot->_pLeft);
	Height(pRoot->_pRight);
	if(pRoot->_pLeft || pRoot->_pRight)
	{
		//return (n1 > n2 ? n1 : n2)++;
		if(n1 > n2)
			return n1++;
		else
			return n2++;
	}
	return 1;//һ���ڵ㷵��1
}

// �������������---��α���
//�������е�����ʵ��
void LevelOrder(PBTNode pRoot)
{
	PBTNode cur = pRoot;
	Queue q;
	if(pRoot == NULL)
		return ;
	Queue_Init(&q);//��ʼ��
	Queue_Puch(&q,pRoot);//�����
	while(!Queue_Empty(&q))
	{
		cur =  Queue_Front(&q);
		printf("%c ",cur->_data);
		Queue_Pop(&q);//ɾ����ͷ

		if(cur->_pLeft)
			Queue_Puch(&q,cur->_pLeft);//�����
		if(cur->_pRight)
			Queue_Puch(&q,cur->_pRight);//�����
	}
	printf("\n");
}

//�ݹ龵��
void Mirror(PBTNode pRoot)
{
	if(pRoot)
	{
		Swap(&pRoot->_pLeft,&pRoot->_pRight);
		Mirror(pRoot->_pLeft);
		Mirror(pRoot->_pRight);
	}
}
//�ǵݹ龵��---�������У�����α�����Ϊ����
void Mirror_Nor(PBTNode pRoot)
{
	PBTNode cur = pRoot;
	Queue q;
	if(pRoot == NULL)
		return ;
	Queue_Init(&q);//��ʼ��
	Queue_Puch(&q,pRoot);//�����
	while(!Queue_Empty(&q))
	{
		cur =  Queue_Front(&q);
		Swap(&cur->_pLeft,&cur->_pRight);		
		Queue_Pop(&q);//ɾ����ͷ

		if(cur->_pLeft)
			Queue_Puch(&q,cur->_pLeft);//�����
		if(cur->_pRight)
			Queue_Puch(&q,cur->_pRight);//�����
	}
}
//�����ڵ�
void Swap(PBTNode* left,PBTNode* right)
{
	PBTNode tmp = *left;
	*left = *right;
	*right = tmp;
}

// �ж�һ�����Ƿ�����ȫ������----��������ʵ��
//������ȫ��������1�����Һ��������� 2��������С��N-1�㲻��
int IsCompleteBinTree(PBTNode pRoot)
{
	PBTNode cur = pRoot;
	PBTNode tmp = NULL; //��ǩ����ǲ����Ľڵ�
	Queue q;
	if(pRoot == NULL)
		return 0;
	Queue_Init(&q);//��ʼ��
	Queue_Puch(&q,pRoot);//�����
	while(!Queue_Empty(&q))
	{
		cur =  Queue_Front(&q);
		if((cur->_pLeft == NULL && cur->_pRight != NULL) ||
			(tmp != NULL && cur->_pLeft != NULL))
			return 0;
		if(cur->_pRight == NULL)
			tmp = cur;
		Queue_Pop(&q);//ɾ����ͷ

		if(cur->_pLeft)
			Queue_Puch(&q,cur->_pLeft);//�����
		if(cur->_pRight)
			Queue_Puch(&q,cur->_pRight);//�����
	}
	return 1;
}

// �ڶ������в���ֵΪdata�Ľ�� ---�����������Ϊ����
PBTNode Find(PBTNode pRoot, BTDataType data)
{
	stack entry;
	PBTNode cur = pRoot;
	if(pRoot == NULL)
		return NULL;
	Stack_Init(&entry);//��ʼ��ջ
	while(cur || !Stack_Empty(&entry))
	{
		while(cur)
		{
	         Stack_push(&entry,cur);
			 cur = cur->_pLeft;
		}
		cur = Stack_Top(&entry);
		if(cur->_data == data)
			return cur;
		Stack_Pop(&entry);//���ɷ��ں��棬��������������Ҫ��ջ�����ȳ�ջ��������ջ

		cur = cur->_pRight;
	}
	return NULL;
}

PBTNode FindNor(PBTNode pRoot, BTDataType data)//�ݹ�
{
	if(pRoot == NULL)//�ݹ����
		return NULL;
	if(pRoot->_data == data)//�ݹ����
		return pRoot;      
	                            
	if(!FindNor(pRoot->_pLeft,data))//��������������Ϊ�գ���������δ�ҵ��������������ң��ҵ��������������ң�
		FindNor(pRoot->_pRight,data);//�ݹ�                           //���ݺ������ִ���꣬�Զ�����һ�㷵��
}

//�ܽ᣺һ������ݹ�����еݹ���ڡ�
//ִ��һ��returnֻ���ص���һ�㣬�˴��˳��󣬼���ִ���������䣬
//ִ������return����˴��˳����������Ϸ��أ���ִ���������
//ע���������ִ����Ҳ�൱��ִ��һ��return��䣬���Ϸ���һ��



// �ж�һ���ڵ��Ƿ��ڶ�������---��ǰ�������Ϊ���� 
int IsNodeInBinTree(PBTNode pRoot, PBTNode pNode) 
{
	stack entry;
	PBTNode cur = pRoot;
	if(pRoot == NULL)
	{
		return 0;
	}
	Stack_Init(&entry);//��ʼ��ջ
	Stack_push(&entry,pRoot);
	while(!Stack_Empty(&entry))
	{
		cur = Stack_Top(&entry);
		if(cur == pNode)
			return 1;
		Stack_Pop(&entry);//���ɷ��ں��棬��������������Ҫ��ջ�����ȳ�ջ��������ջ

		if(cur->_pRight)
			Stack_push(&entry,cur->_pRight);
		if(cur->_pLeft)
		{
			Stack_push(&entry,cur->_pLeft);
		}
	}
	return 0;
}

// ��ȡ��ǰ�ڵ������ 
PBTNode LeftChild(PBTNode pNode)
{
	assert(pNode);
	return pNode->_pLeft;
}
// ��ȡ��ǰ�ڵ���Һ��� 
PBTNode RightChild(PBTNode pNode)
{
	assert(pNode);
	return pNode->_pRight;
}

//����---�����������
void DestroyBinTree(PBTNode* pRoot)
{
	assert(pRoot);
	if(*pRoot)
	{
		DestroyBinTree(&(*pRoot)->_pLeft);
		DestroyBinTree(&(*pRoot)->_pRight);
		free(*pRoot);
	}
	*pRoot = NULL;
}

//////////////������//////////////////////

void PreOrderThd(PBTNode pRoot)//ǰ��������
{
	PBTNode prev = NULL;
	_PreOrderThd(pRoot,&prev);//prev���ݶ���ָ�룬��ı�ָ��ָ��(����)
}
void _PreOrderThd(PBTNode pRoot,PBTNode* prev)//�ݹ�ʵ��
{
	if(pRoot)
	{
		//��ǰ�ִ���ǰ��
		if(pRoot->_pLeft == NULL)
		{
			pRoot->_pLeft = *prev;
			pRoot->_leftpag = THREAD;
		}
		//��һ�ִ�����
		if(*prev && (*prev)->_pRight == NULL)
		{
			(*prev)->_pRight = pRoot;
			(*prev)->_rightpag = THREAD;
		}

		*prev = pRoot;
		if(pRoot->_leftpag == LINK)//�ж��Ƿ�����������ע�������⣬�������ѭ����
		_PreOrderThd(pRoot->_pLeft,prev);
		if(pRoot->_rightpag == LINK)
		_PreOrderThd(pRoot->_pRight,prev);
	}
}

//�ݹ�ǰ������������
void PreOrderThdPrt(PBTNode pRoot)//����������---������һ������
{
	PBTNode cur = pRoot;
	//�������Ҷ�ӽڵ�
	while(cur->_leftpag == LINK)
	{
		printf("%c ",cur->_data);
		cur = cur->_pLeft;
	}
	printf("%c ",cur->_data);//������Ҷ�ӽڵ�

	//���������ĺ�̽ڵ�
	while(cur->_rightpag == THREAD)
	{
		cur = cur->_pRight;
		printf("%c ",cur->_data);
	}
	//���δ���������������⴦��
	if(cur->_leftpag == LINK)
		PreOrderThdPrt(cur->_pLeft);
}
//�ǵݹ�ǰ������������
void PreOrderThdPrtNor(PBTNode pRoot)//����������---������һ������
{
	PBTNode cur = pRoot;
	//�������Ҷ�ӽڵ�
	while(cur)
	{
		while(cur->_leftpag == LINK)
		{
			printf("%c ",cur->_data);
			cur = cur->_pLeft;
		}
		printf("%c ",cur->_data);//������Ҷ�ӽڵ�
		//ֱ��ȥ����������
		cur = cur->_pRight;//��Ҷ�ӵ���ָ����ָ��������
		/*//����һ�ݴ������
		//���������ĺ�̽ڵ�
		while(cur->_rightpag == THREAD)
		{
			cur = cur->_pRight;
			printf("%c ",cur->_data);
		}
		//���δ���������������
		if(cur->_leftpag == LINK)
			cur = cur->_pLeft;
		//�����Ҳ�
		else
			cur = cur->_pRight;
		*/
	}
	printf("\n");
}

//����������
void InOrderThd(PBTNode pRoot)
{
	PBTNode prev = NULL;
	_InOrderThd(pRoot,&prev);
}
void _InOrderThd(PBTNode cur,PBTNode* prev)//prev���ݶ���ָ�룬��ı�ָ��ָ��(����)
{
	if(cur)
	{
		//�ݹ��������
		_InOrderThd(cur->_pLeft,prev);
		//����ǰ��
		if(cur->_pLeft == NULL)
		{
			cur->_leftpag = THREAD;
			cur->_pLeft = *prev;
		}
		//������
		if(*prev && (*prev)->_leftpag == THREAD)
		{
			(*prev)->_rightpag = THREAD;
			(*prev)->_pRight = cur;
		}
		*prev = cur;//���ǰһ�ڵ�
		//��������
		_InOrderThd(cur->_pRight,prev);	
	}
}
//��������������
void InOrderThdPrtNor(PBTNode pRoot)//�ǵݹ����
{
	PBTNode prev = pRoot;
	//ѭ��---��Ϊ��
	while(pRoot)
	{
		//�ߵ������
		while(pRoot->_leftpag == LINK)
		{
			pRoot = pRoot->_pLeft;
		}
		//��������Ҷ�ӽڵ�
		printf("%c ",pRoot->_data);
		//ѭ�����������ĺ��(�ұ��ΪTHREAD)
		while(pRoot && pRoot->_rightpag == THREAD)
		{
			pRoot = pRoot->_pRight;
			if(pRoot == NULL)
				break;
			printf("%c ",pRoot->_data);
		}
		//��������
		if(pRoot)
		pRoot = pRoot->_pRight;
	}
}
//����������
void PosOrderThd(PBTNode pRoot)//����������
{
	PBTNode prev = NULL;
	_PosOrderThd(pRoot,&prev);
}
void _PosOrderThd(PBTNode pRoot,PBTNode* prev)//prev���ݶ���ָ�룬��ı�ָ��ָ��(����)
{
	if(pRoot)
	{
		_PosOrderThd(pRoot->_pLeft,prev);
		_PosOrderThd(pRoot->_pRight,prev);
		//����ǰ��
		if(pRoot->_pLeft == NULL)
		{
			pRoot->_leftpag = THREAD;
			pRoot->_pLeft = *prev;
		}
		//������
		if(*prev && (*prev)->_pRight == NULL)
		{
			(*prev)->_rightpag = THREAD;
			(*prev)->_pRight = pRoot;
		}
		*prev = pRoot;
	}
}

//������������������ʹ��������
void PosOrderThdPrtNor(PBTNode pRoot)//�ǵݹ����
{
	PBTNode prev = NULL;
	PBTNode cur = pRoot;
	while(cur)
	{
		//���ߵ�����࣬ע:�����жϸ�����Ƿ��߹�,��prev != cur
		while(cur->_leftpag == LINK && prev != cur)
		{
			cur = cur->_pLeft;
		}
		//ѭ������������Ҷ�ӽڵ����Ϊ��(��ΪTHREAD)�Ľڵ㣬ͬʱ��Ǳ��α����Ľڵ㣬(������֧)
		while(cur && cur->_rightpag == THREAD)
		{
			printf("%c ",cur->_data);
			prev = cur;//����ѱ����ڵ�
			cur = cur->_pRight;
		}
		//����ߵ����ڵ�,��cur == pRoot && pRoot->_pRight == NULL || prev == pRoot->_pRight �����������ڵ��˳�
		if(cur == pRoot )
		{
			printf("%c ",cur->_data);
			return ;
		}
		//ѭ����ǰ�ڵ㲻Ϊ�գ��ҵ�ǰ�����ҵ���prev��cur && cur->right == prev����ѭ�������ҵ�֧
		while(cur && cur->_pRight == prev)
		{
			printf("%c ",cur->_data);
			prev = cur;//����ѱ����ڵ�
			cur = cur->_parent;

		}
		//������ҽڵ㣬����������
		if(cur && cur->_rightpag == LINK)
			cur = cur->_pRight;
	}
}

//����1���ȼ��㣬��ݹ飬˳����㣩
//�������----�ݹ�⣨����������߶ȣ��ظ�����Ľڵ�̫�࣬ʱ�临�Ӷȣ�O(N^2)��
//���ڵ�Ϊ�գ�����NULL
//�ֱ������������ĸ߶ȣ�����ӣ�add��
//���м�ֵ(���ֵ:maxlen)����ͽ�����бȽϣ����м�󣬸����м�ֵ��maxlen = add;
//�ݹ���ڵ���󣬵ݹ���ڵ����
int Max(PBTNode pRoot,int* maxlen)
{
	int leftsz = 0;
	int rightsz = 0;
	if(pRoot == NULL)
		return 0;

	leftsz = Height(pRoot->_pLeft); 
	rightsz = Height(pRoot->_pRight);

	if(leftsz+rightsz > *maxlen)
		*maxlen = leftsz+rightsz;
	Max(pRoot->_pLeft,maxlen);
	Max(pRoot->_pRight,maxlen);
	 return *maxlen;
}

//����2���ȵݹ飬����㣬���ż���,�ݹ�ͬʱͳ�Ƹ߶ȣ������������ĸ߶�---ʱ�临�Ӷ�O(N)
//�ݹ��ߵ��գ��ټ���߶�

//���ڵ�Ϊ�գ�����0
//�ݹ�������󣬵ݹ���ң�ע��Ҫ���淵�صĽ����

//������1������ ��Ľ��+�ҵĽ��+1

//������2�������Ľ��+�ҵĽ�������м�ֵ�������м�ֵ+1
//    ���� ��Ľ��+1����Ŀ�������

//ע���м�ֵʹ��ָ�봫��,ͳ��ʱ���ͳ�����θ��ڵ����Խ������-1
int Max2(PBTNode pRoot,int* maxlen)
{
	int leftsz = 0;
	int rightsz = 0;
	if(pRoot == NULL)
	{
		return 0;
	}
	leftsz = Max2(pRoot->_pLeft,maxlen);
	rightsz = Max2(pRoot->_pLeft,maxlen);
	if(leftsz+rightsz > *maxlen)
		*maxlen = leftsz+rightsz;//ͳ�Ƽ��
	return (leftsz > rightsz)? leftsz+1 : rightsz+1;//�������ĸ߶�
}

//�������ڵ���������
//����1��(������)ʹ��ջ+�ݹ�ʵ��
//��һ���ڵ��·��
int _GetCOmmonAncestor(PBTNode pRoot,stack* entry1,PBTNode Node)
{
	//1������һ����־λ
	//��Ϊ�գ�����0��
	//���ڵ���ջ
	//���ڵ�Ϊ���ҵĽڵ㣬����1
	//���ڵ����Ϊ�գ��ݹ�������󣬲����շ���ֵ(tmp)
	//�Ϸ���ֵ(tmp)Ϊ�٣����Ҹ����Ҳ�Ϊ�գ��ݹ�����ң����շ���ֵ
	//�Ͻ��յķ���ֵ(tmp)Ϊ�٣���ջ
	//����tmp;

	int tmp = 0;
	if(pRoot == NULL)
		return 0;
	Stack_push(entry1,pRoot);

	if(pRoot == Node)
		return 1;
	if(pRoot->_pLeft)//·����ȷ������
	{
		tmp = _GetCOmmonAncestor(pRoot->_pLeft,entry1,Node);
	}
	//else
		//Stack_Pop(entry1);
	if(!tmp && pRoot->_pRight)
	{
		tmp = _GetCOmmonAncestor(pRoot->_pRight,entry1,Node);
	}
	if(!tmp)
		Stack_Pop(entry1);
	return tmp;

	//������2��
	//��Ϊ�շ���false
	//����ջ
	//��Ϊ�ýڵ㣬����true
	//����ݹ������Ϊ�棬����true
	//����ݹ������Ϊ�棬����true	
}
//2�����·�������ǲ����ȳ�ջ��
//3���ֱ�ȡ����ջ���Ƚϣ���ͬ��ջ����ͬ��Ϊ�������
//�������ڵ���������
PBTNode GetCOmmonAncestor(PBTNode pRoot,BTDataType data1,BTDataType data2)
{
	stack entry1;
	stack entry2;
	int sz1 = 0;
	int sz2 = 0;
	int dl = 0;
	PBTNode cur1 =  Find(pRoot, data1); 
	PBTNode cur2 =  Find(pRoot, data2);
	if(!cur1 || !cur2)
		return NULL;

	Stack_Init(&entry1);
	Stack_Init(&entry2);
	 _GetCOmmonAncestor(pRoot,&entry1,cur1);
	 _GetCOmmonAncestor(pRoot,&entry2,cur2);
	 sz1 = entry1._size;
	 sz2 = entry2._size;
	 dl = sz1 - sz2;
	 if(dl > 0)
	 {
		 while(dl--)
		 Stack_Pop(&entry1);
	 }
	 else if(dl < 0)
	 {
		 dl = -dl;
		 while(dl--)
		 {
			 PBTNode cur = Stack_Top(&entry2); 
			Stack_Pop(&entry2);
		 }
	 }
	
	 while(!Stack_Empty(&entry1))
	 {
		 if(Stack_Top(&entry1) == Stack_Top(&entry2))
		 {
			 printf("%c \n", Stack_Top(&entry1)->_data);
			 return Stack_Top(&entry1);
		 }
		 Stack_Pop(&entry1);
		 Stack_Pop(&entry2);
	 }
}


//����2��(����)�ݹ�ʵ��
PBTNode Parent(PBTNode pRoot,PBTNode Node1,PBTNode Node2)//������������Ƚڵ�
{
	PBTNode n1 = NULL;
	PBTNode n2 = NULL;
	//�ڵ�Ϊ��
	if(pRoot == NULL)
		return pRoot;
	//��һ��Ϊ���ڵ�
	if(pRoot == Node1 || pRoot == Node2)
		return pRoot;
	//�ݹ鴦����������
    n1 = Parent(pRoot->_pLeft,Node1,Node2);
	n2 = Parent(pRoot->_pLeft,Node1,Node2);

	//2����ͬһ������
	if(n1 && n2)
		return pRoot;
	//���ز�Ϊ�յĽڵ�
	return (n1 != NULL) ? n1 : n2;

	//3���ֱ��ڸ����󣬺��ң����ظ�,��ͬһ��������

	//����ͬһ�������ϣ��ӵ�����ң�����������Ľ��� 
	//4����ͬһ��������
	//���ڸ��ڵ���������ϣ����صݹ���ڵ����(ע����ָ���ǵ�ǰ�����ĸ�)
	//���ڸ��ڵ���������ϣ����صݹ���ڵ����
	//���򷵻�NULL(��1����������)
}

//����3��ʹ��������+���У�������ջ��

void Tree_test()//����
{
	//BTDataType arr[] = {'a','b','d','#','#','g','#','#','c','e','#','#'};
	BTDataType arr[] = {'a','b','d','f','#','#','m','#','#','g','#','#','c','e','#','#','#','#'};
	int size = sizeof(arr)/sizeof(arr[0]);
	int i = 0;

	PBTNode pRoot = NULL;
	PBTNode Search = NULL;
	
	CreateBinTree(&pRoot,arr,size,'#');//����
	CopyBinTree(pRoot);//����
	/*
	//�ݹ����
	printf("ǰ��ݹ������");
	PreOrder(pRoot);
	printf("\n");
	printf("����ݹ������");
	InOrder(pRoot); 
	printf("\n");
	printf("����ݹ������");
	PostOrder(pRoot);
	printf("\n");
	//�ǵݹ����
	printf("ǰ��ǵݹ������");
	PreOrderNor(pRoot);
	printf("\n");
	printf("����ǵݹ������");
	InOrderNor(pRoot);
	printf("\n");
	printf("����ǵݹ������");
    PostOrder(pRoot); 
	printf("\n");

    printf("�ڵ������%d \n",Size(pRoot)); 
	printf("Ҷ�ӽ�����:%d\n", GetLeafCount(pRoot)); 
    printf("��2���н�����:%d\n",GetKLevel(pRoot,2)); 
	printf("�������ĸ߶�:%d\n",Height(pRoot));

	
	printf("�������������:");
	LevelOrder(pRoot); 

	printf("����������ݹ�:"); 
	Mirror(pRoot); 
	printf("\n����������ǵݹ�:"); 
	Mirror_Nor(pRoot); 

	printf("\n�������������:");
	LevelOrder(pRoot);
	// �ж�һ�����Ƿ�����ȫ������ 
    printf("�Ƿ�����ȫ��������%d \n", IsCompleteBinTree(pRoot));

	// �ڶ������в���ֵΪdata�Ľ�� 
	*/
	//Search = Find(pRoot,'c');
	Search = FindNor(pRoot,'f');
	printf("'f'= %c\n", Search->_data); 
	/*
	printf("%d\n",IsNodeInBinTree(pRoot,Search)); 
	//˼���ݹ�ʵ�ֲ���

	// ��ȡ��ǰ�ڵ������ 
	printf("%p \n",LeftChild(Search)); 
   // ��ȡ��ǰ�ڵ���Һ��� 
	printf("%p \n",RightChild(Search)); 
	//����
   // DestroyBinTree(&pRoot); 
	

	  //printf("ǰ����������");
	  //PreOrderThd(pRoot);//ǰ��������
	  //PreOrderThdPrt(pRoot);//ǰ���������ݹ����
	  //printf("\n");
	  //PreOrderThdPrtNor(pRoot);//ǰ������������
	 
	  printf("������������");
	  InOrderThd(pRoot);//����������
      InOrderThdPrtNor(pRoot);//�ǵݹ����
	  */
	  printf("ǰ��ݹ������");
	  PreOrder(pRoot);
	  printf("\n����ࣺ");
	  printf("%d \n", Max(pRoot,&i));
	 
	  i = 0;
	  Max2(pRoot,&i);
	  printf("%d \n",--i);

	  GetCOmmonAncestor(pRoot,'f','e');
	  printf("%p \n",Parent(pRoot,Find(pRoot,'f'),Find(pRoot,'e')));//������������Ƚڵ�

	  //printf("������������");
	  //PosOrderThd(pRoot);//����������
   //   PosOrderThdPrtNor(pRoot);//�ǵݹ����
}



//��������
//��N����ļ����ҳ�ĳK����ʵ������ļ�
//�ο��飺����������
//��д��������������Ŀ

//�⣺��K����ʷֳ�M�ݣ���M��ʷ��ڹ�ϣ���У�
//���ļ��ж�ȡһ�����Σ����ڹ�ϣ���в����Ƿ���ڸõ��ʣ����ڼ�¼���ļ������ζ�ȡ����ļ������еĵ��ʣ�ͬ���ٱȽ���һ���ļ�
//�����ļ����������ȡM�����ʷ��ڹ�ϣ���У�ͬ�ϵķ������������е���
