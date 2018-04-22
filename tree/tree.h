#ifndef __TREE_H__

#define __TREE_H__

enum Point{LINK,THREAD};//指针域状态
typedef char BTDataType; 

typedef struct BinTreeNode 
{ 
	BTDataType _data; //数据
	struct BinTreeNode* _pLeft;  //左子树
	struct BinTreeNode* _pRight; //右子树
	struct BinTreeNode* _parent; //双亲
	enum Point _leftpag; //左指针域状态(前驱)
	enum Point _rightpag; //右指针域状态(后继)

}BTNode, *PBTNode; 

///////////////////////////////////////////////////// 
// 创建二叉树 
void CreateBinTree(PBTNode* pRoot, BTDataType* array, int size, BTDataType invalid); 
void _CreateBinTree(PBTNode* pRoot, BTDataType* array, int size, int* index, BTDataType invalid); 
PBTNode BuyBinTreeNode(BTDataType data); 
// 拷贝 
PBTNode CopyBinTree(PBTNode pRoot);

// 前序递归遍历 
void PreOrder(PBTNode pRoot); 
// 前序非递归 
void PreOrderNor(PBTNode pRoot); 
// 中序递归 
void InOrder(PBTNode pRoot); 
// 中序非递归 
void InOrderNor(PBTNode pRoot); 
// 后续递归 
void PostOrder(PBTNode pRoot); 
// 后序非递归 
void PostOrder(PBTNode pRoot); 
// 求二叉树中结点的个数 
int Size(PBTNode pRoot); 
// 求二叉树中叶子结点的个数 
int GetLeafCount(PBTNode pRoot); 
// 获取第K层中结点个数 
int GetKLevel(PBTNode pRoot, int K); 
// 获取二叉树的高度 
int Height(PBTNode pRoot); 

// 二叉树层序遍历 
void LevelOrder(PBTNode pRoot); 
void Swap(PBTNode* left,PBTNode* right);//交换节点,改变指针的内容(地址)需使用二级指针
// 二叉树镜像递归 
void Mirror(PBTNode pRoot); 
// 二叉树镜像非递归 
void Mirror_Nor(PBTNode pRoot); 

// 判断一棵树是否是完全二叉树 
int IsCompleteBinTree(PBTNode pRoot); 

// 在二叉树中查找值为data的结点 
PBTNode Find(PBTNode pRoot, BTDataType data); 

PBTNode FindNor(PBTNode pRoot, BTDataType data); //递归
// 判断一个节点是否在二叉树中 
int IsNodeInBinTree(PBTNode pRoot, PBTNode pNode); 

// 获取当前节点的左孩子 
PBTNode LeftChild(PBTNode pNode); 
// 获取当前节点的右孩子 
PBTNode RightChild(PBTNode pNode); 

PBTNode Parent(PBTNode pRoot,BTDataType data1,BTDataType data2);//查找最近的祖先节点

//销毁
void DestroyBinTree(PBTNode* pRoot); 


void Tree_test();//测试

//线索化
void PreOrderThd(PBTNode pRoot);//前序线索化
void _PreOrderThd(PBTNode pRoot,PBTNode* prev);//prev传递二级指针，需改变指针指向(内容)
void PreOrderThdPrt(PBTNode pRoot);//遍历递归
void PreOrderThdPrtNor(PBTNode pRoot);//非递归

void InOrderThd(PBTNode pRoot);//中序线索化
void _InOrderThd(PBTNode pRoot,PBTNode* prev);//prev传递二级指针，需改变指针指向(内容)
void InOrderThdPrtNor(PBTNode pRoot);//非递归遍历

void PosOrderThd(PBTNode pRoot);//后序线索化
void _PosOrderThd(PBTNode pRoot,PBTNode* prev);//prev传递二级指针，需改变指针指向(内容)
void PosOrderThdPrtNor(PBTNode pRoot);//非递归遍历

#endif