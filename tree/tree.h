#ifndef __TREE_H__

#define __TREE_H__

enum Point{LINK,THREAD};//ָ����״̬
typedef char BTDataType; 

typedef struct BinTreeNode 
{ 
	BTDataType _data; //����
	struct BinTreeNode* _pLeft;  //������
	struct BinTreeNode* _pRight; //������
	struct BinTreeNode* _parent; //˫��
	enum Point _leftpag; //��ָ����״̬(ǰ��)
	enum Point _rightpag; //��ָ����״̬(���)

}BTNode, *PBTNode; 

///////////////////////////////////////////////////// 
// ���������� 
void CreateBinTree(PBTNode* pRoot, BTDataType* array, int size, BTDataType invalid); 
void _CreateBinTree(PBTNode* pRoot, BTDataType* array, int size, int* index, BTDataType invalid); 
PBTNode BuyBinTreeNode(BTDataType data); 
// ���� 
PBTNode CopyBinTree(PBTNode pRoot);

// ǰ��ݹ���� 
void PreOrder(PBTNode pRoot); 
// ǰ��ǵݹ� 
void PreOrderNor(PBTNode pRoot); 
// ����ݹ� 
void InOrder(PBTNode pRoot); 
// ����ǵݹ� 
void InOrderNor(PBTNode pRoot); 
// �����ݹ� 
void PostOrder(PBTNode pRoot); 
// ����ǵݹ� 
void PostOrder(PBTNode pRoot); 
// ��������н��ĸ��� 
int Size(PBTNode pRoot); 
// ���������Ҷ�ӽ��ĸ��� 
int GetLeafCount(PBTNode pRoot); 
// ��ȡ��K���н����� 
int GetKLevel(PBTNode pRoot, int K); 
// ��ȡ�������ĸ߶� 
int Height(PBTNode pRoot); 

// ������������� 
void LevelOrder(PBTNode pRoot); 
void Swap(PBTNode* left,PBTNode* right);//�����ڵ�,�ı�ָ�������(��ַ)��ʹ�ö���ָ��
// ����������ݹ� 
void Mirror(PBTNode pRoot); 
// ����������ǵݹ� 
void Mirror_Nor(PBTNode pRoot); 

// �ж�һ�����Ƿ�����ȫ������ 
int IsCompleteBinTree(PBTNode pRoot); 

// �ڶ������в���ֵΪdata�Ľ�� 
PBTNode Find(PBTNode pRoot, BTDataType data); 

PBTNode FindNor(PBTNode pRoot, BTDataType data); //�ݹ�
// �ж�һ���ڵ��Ƿ��ڶ������� 
int IsNodeInBinTree(PBTNode pRoot, PBTNode pNode); 

// ��ȡ��ǰ�ڵ������ 
PBTNode LeftChild(PBTNode pNode); 
// ��ȡ��ǰ�ڵ���Һ��� 
PBTNode RightChild(PBTNode pNode); 

PBTNode Parent(PBTNode pRoot,BTDataType data1,BTDataType data2);//������������Ƚڵ�

//����
void DestroyBinTree(PBTNode* pRoot); 


void Tree_test();//����

//������
void PreOrderThd(PBTNode pRoot);//ǰ��������
void _PreOrderThd(PBTNode pRoot,PBTNode* prev);//prev���ݶ���ָ�룬��ı�ָ��ָ��(����)
void PreOrderThdPrt(PBTNode pRoot);//�����ݹ�
void PreOrderThdPrtNor(PBTNode pRoot);//�ǵݹ�

void InOrderThd(PBTNode pRoot);//����������
void _InOrderThd(PBTNode pRoot,PBTNode* prev);//prev���ݶ���ָ�룬��ı�ָ��ָ��(����)
void InOrderThdPrtNor(PBTNode pRoot);//�ǵݹ����

void PosOrderThd(PBTNode pRoot);//����������
void _PosOrderThd(PBTNode pRoot,PBTNode* prev);//prev���ݶ���ָ�룬��ı�ָ��ָ��(����)
void PosOrderThdPrtNor(PBTNode pRoot);//�ǵݹ����

#endif