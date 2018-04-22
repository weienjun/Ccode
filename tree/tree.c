#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"tree.h"
#include"stack.h"
#include"Queue.h"
// 创建二叉树 
void CreateBinTree(PBTNode* pRoot, BTDataType* array, int size, BTDataType invalid)
{
	int index = 0;
	_CreateBinTree(pRoot,array,size,&index,invalid);//递归创建，注：传参不能改变数值内容，所以需传地址(index)，否则递归回退会发生错误
}

void _CreateBinTree(PBTNode* pRoot, BTDataType* array, int size, int* index, BTDataType invalid)//改变指针内容，所以传二级指针
{
	if(array[*index] == invalid)
	{
		return ;
	}
	if(*index < size && array[*index] != invalid)//值合法
	{
		(*pRoot) = BuyBinTreeNode(array[*index]);//创建节点
		++(*index);
		_CreateBinTree(&(*pRoot)->_pLeft,array,size,index,invalid);//改变指针内容，所以传二级指针
		if((*pRoot)->_pLeft)
			(*pRoot)->_pLeft->_parent = *pRoot;
		++(*index);
		_CreateBinTree(&(*pRoot)->_pRight,array,size,index,invalid);//改变指针内容，所以传二级指针
		if((*pRoot)->_pRight)
			(*pRoot)->_pRight->_parent = *pRoot;
	}
}
//创建节点
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

// 拷贝 
PBTNode CopyBinTree(PBTNode pRoot)
{
	PBTNode New = NULL;
	if(pRoot == NULL)
		return NULL;
	else
	{
		New = BuyBinTreeNode(pRoot->_data);//新节点
		New->_pLeft = CopyBinTree(pRoot->_pLeft);
		New->_pRight = CopyBinTree(pRoot->_pRight);
	}
	return New;
}

// 前序递归遍历 
void PreOrder(PBTNode pRoot)
{
	if(pRoot)
	{
		printf("%c ",pRoot->_data);
		PreOrder(pRoot->_pLeft);
		PreOrder(pRoot->_pRight);
	}
}

// 前序非递归 
void PreOrderNor(PBTNode pRoot)
{
	stack entry;
	PBTNode cur = pRoot;
	if(pRoot == NULL)
	{
		return ;
	}
	Stack_Init(&entry);//初始化栈
	Stack_push(&entry,pRoot);
	while(!Stack_Empty(&entry))
	{
		cur = Stack_Top(&entry);
		printf("%c ",cur->_data);
		Stack_Pop(&entry);//不可放在后面，否则出错，遍历后既要出栈，即先出栈顶，后入栈

		if(cur->_pRight)
			Stack_push(&entry,cur->_pRight);
		if(cur->_pLeft)
		{
			Stack_push(&entry,cur->_pLeft);
		}
	}
}
// 中序递归 
void InOrder(PBTNode pRoot)
{
	if(pRoot != NULL)
	{
		InOrder(pRoot->_pLeft);
		printf("%c ",pRoot->_data);
		InOrder(pRoot->_pRight);
	}
}
// 中序非递归 
void InOrderNor(PBTNode pRoot)
{
	stack entry;
	PBTNode cur = pRoot;
	if(pRoot == NULL)
		return ;
	Stack_Init(&entry);//初始化栈
	while(cur || !Stack_Empty(&entry))
	{
		while(cur)
		{
	         Stack_push(&entry,cur);
			 cur = cur->_pLeft;
		}
		cur = Stack_Top(&entry);
		printf("%c ",cur->_data);
		Stack_Pop(&entry);//不可放在后面，否则出错，遍历后既要出栈，即先出栈顶，后入栈

		cur = cur->_pRight;
	}
}
// 后续递归 
void PostOrder(PBTNode pRoot)
{
	if(pRoot)
	{
		PostOrder(pRoot->_pLeft);
		PostOrder(pRoot->_pRight);
		printf("%c ",pRoot->_data);
	}
}

//后序非递归 
void PostOrderNor(PBTNode pRoot)
{
	stack entry;
	PBTNode cur = pRoot;
	PBTNode prev = pRoot;
	if(pRoot == NULL)
		return ;
	Stack_Init(&entry);//初始化栈
    while(!Stack_Empty(&entry))
	{
		while(cur)//走到最左侧
		{
	         Stack_push(&entry,cur);
			 cur = cur->_pLeft;
		}
		//取栈顶
		cur = Stack_Top(&entry);
		//遍历栈顶
		if(cur->_pRight == NULL && cur != prev)
		{
			printf("%c ",cur->_data);
			prev = cur;
			Stack_Pop(&entry);//不可放在后面，否则出错，遍历后既要出栈，即先出栈顶，后入栈
		}
		//走右子树
		cur = cur->_pRight;
	}
}
//计算树的节点个数
int Size(PBTNode pRoot)
{
	size_t count = 0 ;
	stack entry;
	PBTNode cur = pRoot;
	if(pRoot == NULL)
		return 0;
	Stack_Init(&entry);//初始化栈
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

// 求二叉树中叶子结点的个数 
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

//递归法求K-1层的个数
//1、树空或K=0 返回0
//2、K=1 返回1
//3、其它返回左右子树递归求K-1层的个数个数的和
int GetKLevel(PBTNode pRoot, int K)// 获取第K层中结点个数 
{
	if(pRoot == NULL || K == 0)
		return 0;
	if(K == 1)
		return 1;
	return GetKLevel(pRoot->_pLeft,K-1) + GetKLevel(pRoot->_pRight,K-1);
}

// 获取二叉树的高度 
//1、使用两个计数器初始值为1
//2、分别去递归遍历左右子树
//3、左右节点至少有一个不为空时，返回计数器大的值+1
//使用三目运算符，大的+1
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
	return 1;//一个节点返回1
}

// 二叉树层序遍历---层次遍历
//借助队列的特性实现
void LevelOrder(PBTNode pRoot)
{
	PBTNode cur = pRoot;
	Queue q;
	if(pRoot == NULL)
		return ;
	Queue_Init(&q);//初始化
	Queue_Puch(&q,pRoot);//入队列
	while(!Queue_Empty(&q))
	{
		cur =  Queue_Front(&q);
		printf("%c ",cur->_data);
		Queue_Pop(&q);//删除队头

		if(cur->_pLeft)
			Queue_Puch(&q,cur->_pLeft);//入队列
		if(cur->_pRight)
			Queue_Puch(&q,cur->_pRight);//入队列
	}
	printf("\n");
}

//递归镜像
void Mirror(PBTNode pRoot)
{
	if(pRoot)
	{
		Swap(&pRoot->_pLeft,&pRoot->_pRight);
		Mirror(pRoot->_pLeft);
		Mirror(pRoot->_pRight);
	}
}
//非递归镜像---借助队列，将层次遍历改为交换
void Mirror_Nor(PBTNode pRoot)
{
	PBTNode cur = pRoot;
	Queue q;
	if(pRoot == NULL)
		return ;
	Queue_Init(&q);//初始化
	Queue_Puch(&q,pRoot);//入队列
	while(!Queue_Empty(&q))
	{
		cur =  Queue_Front(&q);
		Swap(&cur->_pLeft,&cur->_pRight);		
		Queue_Pop(&q);//删除队头

		if(cur->_pLeft)
			Queue_Puch(&q,cur->_pLeft);//入队列
		if(cur->_pRight)
			Queue_Puch(&q,cur->_pRight);//入队列
	}
}
//交换节点
void Swap(PBTNode* left,PBTNode* right)
{
	PBTNode tmp = *left;
	*left = *right;
	*right = tmp;
}

// 判断一棵树是否是完全二叉树----借助队列实现
//不是完全二叉树：1、有右孩子无左孩子 2、不满足小于N-1层不满
int IsCompleteBinTree(PBTNode pRoot)
{
	PBTNode cur = pRoot;
	PBTNode tmp = NULL; //标签，标记不满的节点
	Queue q;
	if(pRoot == NULL)
		return 0;
	Queue_Init(&q);//初始化
	Queue_Puch(&q,pRoot);//入队列
	while(!Queue_Empty(&q))
	{
		cur =  Queue_Front(&q);
		if((cur->_pLeft == NULL && cur->_pRight != NULL) ||
			(tmp != NULL && cur->_pLeft != NULL))
			return 0;
		if(cur->_pRight == NULL)
			tmp = cur;
		Queue_Pop(&q);//删除队头

		if(cur->_pLeft)
			Queue_Puch(&q,cur->_pLeft);//入队列
		if(cur->_pRight)
			Queue_Puch(&q,cur->_pRight);//入队列
	}
	return 1;
}

// 在二叉树中查找值为data的结点 ---将中序遍历改为查找
PBTNode Find(PBTNode pRoot, BTDataType data)
{
	stack entry;
	PBTNode cur = pRoot;
	if(pRoot == NULL)
		return NULL;
	Stack_Init(&entry);//初始化栈
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
		Stack_Pop(&entry);//不可放在后面，否则出错，遍历后既要出栈，即先出栈顶，后入栈

		cur = cur->_pRight;
	}
	return NULL;
}

PBTNode FindNor(PBTNode pRoot, BTDataType data)//递归
{
	if(pRoot == NULL)//递归出口
		return NULL;
	if(pRoot->_data == data)//递归出口
		return pRoot;      
	                            
	if(!FindNor(pRoot->_pLeft,data))//左子数遍历返回为空，则左子数未找到，再在右子数找，找到则不再在右子树找，
		FindNor(pRoot->_pRight,data);//递归                           //依据函数语句执行完，自动向上一层返回
}

//总结：一旦进入递归必须有递归出口。
//执行一个return只返回到上一层，此次退出后，继续执行下面的语句，
//执行两个return，则此次退出后，连续向上返回，不执行下面语句
//注：函数语句执行完也相当于执行一次return语句，向上返回一层



// 判断一个节点是否在二叉树中---将前序遍历改为查找 
int IsNodeInBinTree(PBTNode pRoot, PBTNode pNode) 
{
	stack entry;
	PBTNode cur = pRoot;
	if(pRoot == NULL)
	{
		return 0;
	}
	Stack_Init(&entry);//初始化栈
	Stack_push(&entry,pRoot);
	while(!Stack_Empty(&entry))
	{
		cur = Stack_Top(&entry);
		if(cur == pNode)
			return 1;
		Stack_Pop(&entry);//不可放在后面，否则出错，遍历后既要出栈，即先出栈顶，后入栈

		if(cur->_pRight)
			Stack_push(&entry,cur->_pRight);
		if(cur->_pLeft)
		{
			Stack_push(&entry,cur->_pLeft);
		}
	}
	return 0;
}

// 获取当前节点的左孩子 
PBTNode LeftChild(PBTNode pNode)
{
	assert(pNode);
	return pNode->_pLeft;
}
// 获取当前节点的右孩子 
PBTNode RightChild(PBTNode pNode)
{
	assert(pNode);
	return pNode->_pRight;
}

//销毁---后序遍历销毁
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

//////////////线索化//////////////////////

void PreOrderThd(PBTNode pRoot)//前序线索化
{
	PBTNode prev = NULL;
	_PreOrderThd(pRoot,&prev);//prev传递二级指针，需改变指针指向(内容)
}
void _PreOrderThd(PBTNode pRoot,PBTNode* prev)//递归实现
{
	if(pRoot)
	{
		//当前轮处理前驱
		if(pRoot->_pLeft == NULL)
		{
			pRoot->_pLeft = *prev;
			pRoot->_leftpag = THREAD;
		}
		//上一轮处理后继
		if(*prev && (*prev)->_pRight == NULL)
		{
			(*prev)->_pRight = pRoot;
			(*prev)->_rightpag = THREAD;
		}

		*prev = pRoot;
		if(pRoot->_leftpag == LINK)//判断是否需线索化（注：必须检测，否则会死循环）
		_PreOrderThd(pRoot->_pLeft,prev);
		if(pRoot->_rightpag == LINK)
		_PreOrderThd(pRoot->_pRight,prev);
	}
}

//递归前序线索化遍历
void PreOrderThdPrt(PBTNode pRoot)//线索化遍历---像链表一样遍历
{
	PBTNode cur = pRoot;
	//遍历左非叶子节点
	while(cur->_leftpag == LINK)
	{
		printf("%c ",cur->_data);
		cur = cur->_pLeft;
	}
	printf("%c ",cur->_data);//遍历左叶子节点

	//遍历连续的后继节点
	while(cur->_rightpag == THREAD)
	{
		cur = cur->_pRight;
		printf("%c ",cur->_data);
	}
	//左侧未线索化，当子问题处理
	if(cur->_leftpag == LINK)
		PreOrderThdPrt(cur->_pLeft);
}
//非递归前序线索化遍历
void PreOrderThdPrtNor(PBTNode pRoot)//线索化遍历---像链表一样遍历
{
	PBTNode cur = pRoot;
	//遍历左非叶子节点
	while(cur)
	{
		while(cur->_leftpag == LINK)
		{
			printf("%c ",cur->_data);
			cur = cur->_pLeft;
		}
		printf("%c ",cur->_data);//遍历左叶子节点
		//直接去遍历左子树
		cur = cur->_pRight;//左叶子的右指针域，指向右子树
		/*//上述一据代码代替
		//遍历连续的后继节点
		while(cur->_rightpag == THREAD)
		{
			cur = cur->_pRight;
			printf("%c ",cur->_data);
		}
		//左侧未线索化，访问左侧
		if(cur->_leftpag == LINK)
			cur = cur->_pLeft;
		//访问右侧
		else
			cur = cur->_pRight;
		*/
	}
	printf("\n");
}

//中序线索化
void InOrderThd(PBTNode pRoot)
{
	PBTNode prev = NULL;
	_InOrderThd(pRoot,&prev);
}
void _InOrderThd(PBTNode cur,PBTNode* prev)//prev传递二级指针，需改变指针指向(内容)
{
	if(cur)
	{
		//递归至最左侧
		_InOrderThd(cur->_pLeft,prev);
		//处理前驱
		if(cur->_pLeft == NULL)
		{
			cur->_leftpag = THREAD;
			cur->_pLeft = *prev;
		}
		//处理后继
		if(*prev && (*prev)->_leftpag == THREAD)
		{
			(*prev)->_rightpag = THREAD;
			(*prev)->_pRight = cur;
		}
		*prev = cur;//标记前一节点
		//走右子树
		_InOrderThd(cur->_pRight,prev);	
	}
}
//中序线索化遍历
void InOrderThdPrtNor(PBTNode pRoot)//非递归遍历
{
	PBTNode prev = pRoot;
	//循环---不为空
	while(pRoot)
	{
		//走到最左边
		while(pRoot->_leftpag == LINK)
		{
			pRoot = pRoot->_pLeft;
		}
		//遍历最左叶子节点
		printf("%c ",pRoot->_data);
		//循环遍历连续的后继(右标记为THREAD)
		while(pRoot && pRoot->_rightpag == THREAD)
		{
			pRoot = pRoot->_pRight;
			if(pRoot == NULL)
				break;
			printf("%c ",pRoot->_data);
		}
		//走右子树
		if(pRoot)
		pRoot = pRoot->_pRight;
	}
}
//后序线索化
void PosOrderThd(PBTNode pRoot)//后序线索化
{
	PBTNode prev = NULL;
	_PosOrderThd(pRoot,&prev);
}
void _PosOrderThd(PBTNode pRoot,PBTNode* prev)//prev传递二级指针，需改变指针指向(内容)
{
	if(pRoot)
	{
		_PosOrderThd(pRoot->_pLeft,prev);
		_PosOrderThd(pRoot->_pRight,prev);
		//处理前驱
		if(pRoot->_pLeft == NULL)
		{
			pRoot->_leftpag = THREAD;
			pRoot->_pLeft = *prev;
		}
		//处理后继
		if(*prev && (*prev)->_pRight == NULL)
		{
			(*prev)->_rightpag = THREAD;
			(*prev)->_pRight = pRoot;
		}
		*prev = pRoot;
	}
}

//后序线索化遍历，需使用三叉链
void PosOrderThdPrtNor(PBTNode pRoot)//非递归遍历
{
	PBTNode prev = NULL;
	PBTNode cur = pRoot;
	while(cur)
	{
		//先走到最左侧，注:需先判断该左侧是否走过,即prev != cur
		while(cur->_leftpag == LINK && prev != cur)
		{
			cur = cur->_pLeft;
		}
		//循环遍历连续左叶子节点的右为空(右为THREAD)的节点，同时标记本次遍历的节点，(处理左单支)
		while(cur && cur->_rightpag == THREAD)
		{
			printf("%c ",cur->_data);
			prev = cur;//标记已遍历节点
			cur = cur->_pRight;
		}
		//如果走到根节点,（cur == pRoot && pRoot->_pRight == NULL || prev == pRoot->_pRight ）遍历到根节点退出
		if(cur == pRoot )
		{
			printf("%c ",cur->_data);
			return ;
		}
		//循环当前节点不为空，且当前结点的右等于prev（cur && cur->right == prev），循环遍历右单支
		while(cur && cur->_pRight == prev)
		{
			printf("%c ",cur->_data);
			prev = cur;//标记已遍历节点
			cur = cur->_parent;

		}
		//如果有右节点，则走右子树
		if(cur && cur->_rightpag == LINK)
			cur = cur->_pRight;
	}
}

//方法1（先计算，后递归，顺序计算）
//求最大间距----递归解（从上向下求高度，重复计算的节点太多，时间复杂度：O(N^2)）
//根节点为空，返回NULL
//分别求左右子树的高度，再相加（add）
//用中间值(最大值:maxlen)与求和结果进行比较，比中间大，更新中间值，maxlen = add;
//递归根节点的左，递归根节点的右
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

//方法2（先递归，后计算，到着计算,递归同时统计高度）类似于求树的高度---时间复杂度O(N)
//递归走到空，再计算高度

//根节点为空，返回0
//递归求根的左，递归根右（注：要保存返回的结果）

//（方法1）返回 左的结果+右的结果+1

//（方法2）如果左的结果+右的结果大于中间值，更新中间值+1
//    返回 大的结果+1（三目运算符）

//注：中间值使用指针传参,统计时会多统计依次根节点所以结果还需-1
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
		*maxlen = leftsz+rightsz;//统计间距
	return (leftsz > rightsz)? leftsz+1 : rightsz+1;//计算树的高度
}

//求两个节点的最近祖先
//方法1：(不分类)使用栈+递归实现
//求一个节点的路径
int _GetCOmmonAncestor(PBTNode pRoot,stack* entry1,PBTNode Node)
{
	//1、设置一个标志位
	//根为空，返回0，
	//根节点入栈
	//根节点为查找的节点，返回1
	//根节点的左不为空，递归根结点的左，并接收返回值(tmp)
	//上返回值(tmp)为假，并且根的右不为空，递归根的右，接收返回值
	//上接收的返回值(tmp)为假，出栈
	//返回tmp;

	int tmp = 0;
	if(pRoot == NULL)
		return 0;
	Stack_push(entry1,pRoot);

	if(pRoot == Node)
		return 1;
	if(pRoot->_pLeft)//路径正确继续走
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

	//（方法2）
	//根为空返回false
	//根入栈
	//根为该节点，返回true
	//如果递归根的左为真，返回true
	//如果递归根的右为真，返回true	
}
//2、最后将路径长的那部分先出栈，
//3、分别取两个栈顶比较，不同出栈，相同即为最近祖先
//求两个节点的最近祖先
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


//方法2：(分类)递归实现
PBTNode Parent(PBTNode pRoot,PBTNode Node1,PBTNode Node2)//查找最近的祖先节点
{
	PBTNode n1 = NULL;
	PBTNode n2 = NULL;
	//节点为空
	if(pRoot == NULL)
		return pRoot;
	//有一个为根节点
	if(pRoot == Node1 || pRoot == Node2)
		return pRoot;
	//递归处理左右子树
    n1 = Parent(pRoot->_pLeft,Node1,Node2);
	n2 = Parent(pRoot->_pLeft,Node1,Node2);

	//2、在同一个子树
	if(n1 && n2)
		return pRoot;
	//返回不为空的节点
	return (n1 != NULL) ? n1 : n2;

	//3、分别在根的左，和右，返回根,在同一个子树上

	//不在同一个子树上，从的左或右，求两个链表的交点 
	//4不在同一个子树上
	//都在根节点的左子树上，返回递归根节点的左(注：根指的是当前子树的根)
	//都在根节点的右子树上，返回递归根节点的右
	//否则返回NULL(将1情况放在最后)
}

//方法3：使用三叉链+队列（类似于栈）

void Tree_test()//测试
{
	//BTDataType arr[] = {'a','b','d','#','#','g','#','#','c','e','#','#'};
	BTDataType arr[] = {'a','b','d','f','#','#','m','#','#','g','#','#','c','e','#','#','#','#'};
	int size = sizeof(arr)/sizeof(arr[0]);
	int i = 0;

	PBTNode pRoot = NULL;
	PBTNode Search = NULL;
	
	CreateBinTree(&pRoot,arr,size,'#');//建树
	CopyBinTree(pRoot);//复制
	/*
	//递归遍历
	printf("前序递归遍历：");
	PreOrder(pRoot);
	printf("\n");
	printf("中序递归遍历：");
	InOrder(pRoot); 
	printf("\n");
	printf("后序递归遍历：");
	PostOrder(pRoot);
	printf("\n");
	//非递归遍历
	printf("前序非递归遍历：");
	PreOrderNor(pRoot);
	printf("\n");
	printf("中序非递归遍历：");
	InOrderNor(pRoot);
	printf("\n");
	printf("后序非递归遍历：");
    PostOrder(pRoot); 
	printf("\n");

    printf("节点个数：%d \n",Size(pRoot)); 
	printf("叶子结点个数:%d\n", GetLeafCount(pRoot)); 
    printf("第2层中结点个数:%d\n",GetKLevel(pRoot,2)); 
	printf("二叉树的高度:%d\n",Height(pRoot));

	
	printf("二叉树层序遍历:");
	LevelOrder(pRoot); 

	printf("二叉树镜像递归:"); 
	Mirror(pRoot); 
	printf("\n二叉树镜像非递归:"); 
	Mirror_Nor(pRoot); 

	printf("\n二叉树层序遍历:");
	LevelOrder(pRoot);
	// 判断一棵树是否是完全二叉树 
    printf("是否是完全二叉树：%d \n", IsCompleteBinTree(pRoot));

	// 在二叉树中查找值为data的结点 
	*/
	//Search = Find(pRoot,'c');
	Search = FindNor(pRoot,'f');
	printf("'f'= %c\n", Search->_data); 
	/*
	printf("%d\n",IsNodeInBinTree(pRoot,Search)); 
	//思考递归实现查找

	// 获取当前节点的左孩子 
	printf("%p \n",LeftChild(Search)); 
   // 获取当前节点的右孩子 
	printf("%p \n",RightChild(Search)); 
	//销毁
   // DestroyBinTree(&pRoot); 
	

	  //printf("前序线索化：");
	  //PreOrderThd(pRoot);//前序线索化
	  //PreOrderThdPrt(pRoot);//前序线索化递归遍历
	  //printf("\n");
	  //PreOrderThdPrtNor(pRoot);//前序线索化遍历
	 
	  printf("中序线索化：");
	  InOrderThd(pRoot);//中序线索化
      InOrderThdPrtNor(pRoot);//非递归遍历
	  */
	  printf("前序递归遍历：");
	  PreOrder(pRoot);
	  printf("\n最大间距：");
	  printf("%d \n", Max(pRoot,&i));
	 
	  i = 0;
	  Max2(pRoot,&i);
	  printf("%d \n",--i);

	  GetCOmmonAncestor(pRoot,'f','e');
	  printf("%p \n",Parent(pRoot,Find(pRoot,'f'),Find(pRoot,'e')));//查找最近的祖先节点

	  //printf("后序线索化：");
	  //PosOrderThd(pRoot);//后序线索化
   //   PosOrderThdPrtNor(pRoot);//非递归遍历
}



//倒排索引
//从N多个文件中找出某K多个词的所在文件
//参考书：搜索引擎书
//可写个倒排索引的项目

//解：将K多个词分成M份，将M歌词放在哈希表中，
//从文件中读取一个单次，并在哈希表中查找是否存在该单词，存在记录该文件，依次读取完该文件中所有的单词，同样再比较下一个文件
//所有文件处理完后，再取M个单词放在哈希表中，同上的方法处理完所有单词
