#pragma once

#pragma once
#include<iostream>
using namespace std;
enum Color{RED,BLACK};
template<class T,class V>
struct RBTNode
{
	T _key;
	T _value;
	RBTNode<T,V>* _left;
	RBTNode<T,V>* _right;
	RBTNode<T,V>* _parent;
	Color _col;

	RBTNode(const T& data,const V& value)
	:_key(data)
	,_value(value)
	,_left(NULL)
	,_right(NULL)
	,_parent(NULL)
	,_col(RED)
	{}
};

template<class T,class V>
class Tree{
	typedef RBTNode<T,V> Node;
	public:
	Tree()
		:_root(NULL)
	{}

	//����ѭ���ķ�ʽ����ڵ�
	bool Insert(const T& key,const V& value){
		if(_root == NULL){
			_root = new Node(key, value);
			_root->_col = BLACK;
			return true;
		}
		Node* parent = _root;
		Node* cur = _root;
		//Ѱ�Ҳ���ڵ�
		while(cur){
			parent = cur;
			if(cur->_key < key)      cur = cur->_right;
			else if(cur->_key > key) cur = cur->_left;
			else return false;//������ͬ���Ѵ��ڣ�������
		}
		//����ڵ�
		cur = new Node(key,value);
		if(parent->_key > key) parent->_left = cur;
		else  parent->_right = cur;
		cur->_parent = parent;
		//����
		while(parent && parent->_col == RED){
			Node* grandfather = parent->_parent;
			if(parent == grandfather->_left){//���ڵ����游����
				Node* uncle = grandfather->_right;
				if(uncle && uncle->_col == RED){//�������Ϊ��ɫ--->������ɫ
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;
					//���ϲ㴦��
					cur = grandfather;
					parent = cur->_parent;
				}
				else{ // ���岻���ڻ�Ϊ��ɫ---->����ƽ��
					//Node* tmp = parent;
					if (cur == parent->_right) {//cur�ڸ�����˫��
						RotateL(parent);//������
						parent = parent->_parent;
					}
					RotateR(grandfather);//����
					parent->_col = BLACK;
					//tmp->_col = BLACK;//����ֱ��дparent�����ڵ�����parent�����ı䣬����ʵ�ʲ����Ƕ�ԭparent����
					grandfather->_col = RED;
					//grandfather->_col = BLACK;
				}
			}
			else{ //�����游����	
				Node* uncle = grandfather->_left;
				if(uncle && uncle->_col == RED){//���������Ϊ��ɫ
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;
					//���ϲ㴦��
					cur = parent;
					parent = parent->_parent;
				}
				else{ //���岻���ڻ�Ϊ��ɫ
					//Node* tmp = parent;//����ԭparent��λ�ã���ֹ������parentλ�÷����仯��������ɫ���´���
					if (cur == parent->_left) {//�����ͣ�˫��
						RotateR(parent);//���� parent;
						parent = parent->_parent;
					}
					RotateL(grandfather);//���� parent->_parent;
					parent->_col = BLACK;
					//tmp->_col = BLACK;
					grandfather->_col = RED;
				}
			}
			_root->_col = BLACK;  //�����ڵ��Ϊ��ɫ
		}  //ѭ������
		return true;
	}


	//1����Ϊ��ɫ�����򷵻�false
	//�ݹ����
	//2���������ĺ�ɫ�ڵ���򷵻�false(j�ڵ�Ϊ��ɫ�����ڵ�Ϊ��ɫ)
	//3��ÿ��·����ɫ�ڵ�������ͬ
	//�ȼ���һ��·��(�����)��ɫ�ڵ�����������Ϊ��׼
	//�ټ�������·����ɫ�ڵ�����������ͬ����false
	bool Banlance(){
		if(_root && _root->_col == RED){
			printf("��Ϊ��ɫ!\n");
			return false;
		}
		int num = 0;
		Node* cur = _root;
		while(cur){
			if(cur->_col == BLACK) ++num;
			cur = cur->_left;
		}
		int count = 0;
		return _Balance(_root,num,count);
	}

	bool _Balance(Node* cur,int num,int count){
		if(cur == NULL){
			if(num != count)
				return false;
			return true;
		}
		if(cur->_col == RED && cur->_parent->_col == RED){
			printf("�����ĺ�ɫ�ڵ㣡\n");
			return false;
		}
		if (cur->_col == BLACK) {
			count++;
		}
		return _Balance(cur->_left,num,count) && _Balance(cur->_right,num,count);
	}
	
	void RotateR(Node* parent){
		Node* pparent = NULL;
		Node* SubL = parent->_left;
		Node* SubLR = SubL->_right;

		parent->_left = SubLR;
		if (SubLR) {
			SubLR->_parent = parent;
		}
		//����
		SubL->_right = parent;
		pparent = parent->_parent;
		parent->_parent = SubL;
		//�����µĸ��׵ĸ��׽ڵ�
		SubL->_parent = pparent;
		if(pparent == NULL){
		_root = SubL;
		}
		else{
			if(parent == pparent->_left) pparent->_left = SubL;
			else pparent->_right = SubL;
		SubL->_parent = pparent;
		}
		_root->_parent = NULL;
	}
	

	//����
	void RotateL(Node* parent){
		Node* SubR = parent->_right;
		Node* SubRL = SubR->_left;

		parent->_right = SubRL;
		if (SubRL) {//����SubRL�ĸ���
			SubRL->_parent = parent;
		}
		SubR->_left = parent;
		Node* pparent = parent->_parent;
		parent->_parent = SubR;
		//�����µĸ��׵ĸ��׽ڵ�
		SubR->_parent = pparent;
		if (pparent == NULL) {
			_root = SubR;
		}
		else{
			if(parent == pparent->_left) pparent->_left = SubR;
			else pparent->_right = SubR;
			SubR->_parent = pparent;
		}
		_root->_parent = NULL;
	}

	void InOrder(){
		_InOrder(_root);
	}

	void _InOrder(Node* root){
		if(root){
			_InOrder(root->_left);
			cout << root->_key << ' ' <<endl;
			_InOrder(root->_right);
		}
	}

	private:
	Node* _root;
};


void RBSTree_test(){
	int a[] = { 16,3,7,11,9,26,18,14,15,1,2};
	//int a[] = {3,1,2,4,5,6,7,8};
	//int a[] = {1,2,3};
	//int a[] = { 16,3,7};

	int i = 0;
	Tree<int,int> t;
	for(; i < sizeof(a)/sizeof(a[0]); ++i){
		t.Insert(a[i],i);
	}
	t.InOrder();
	if (t.Banlance()) {
		printf("�Ǻ������\n");
	}
}








/*
//�����-----��һ�ý���ƽ��Ķ���������
//Ϊʲô��һ������ƽ�����������
ͨ�����κ�һ���Ӹ��ڵ㵽Ҷ�ӽڵ����ɫԼ������֤�·�����������·���Ķ���
��������Ϊ�˼��ٵ������Ŀ���
ʱ�临�Ӷȣ�O(lgN)  �ռ临�Ӷȣ�O(N)
���ʣ�
1��ÿ���ڵ㲻�Ǻ�ɫ���Ǻ�ɫ�ģ����ڵ����ɫ�Ǻ�ɫ��
2����ɫ�ڵ�������ӽڵ��Ǻ�ɫ�ģ����������ĺ�ɫ�ڵ�
3�����ڵ㵽Ҷ�ӽڵ�ĺ�ɫ�ڵ�������ͬ����ÿ��·���ϵĺ�ɫ�ڵ�������ͬ
4��Ҷ�ӽڵ��Ǻ�ɫ�ģ�Ҷ��---�սڵ㣩

Ϊʲô�����������ʺ�������ܽ���ƽ�⣿
��Ϊ���������ĺ�ɫ�ڵ㣬��ÿ��·���ϵĺ�ɫ�ڵ������ͬ���������·�����·����С��2������������ÿ��·����ɫ�ڵ�����ͬ��
�磺���·��ֻ��һ����ɫ�ڵ㣬�·�����Һ�ɫҲ�к�ɫ�ڵ㡣

ÿ�β����ɫ�ڵ㣺
�������ɫ�ڵ㣬���ı�·���Ϻ�ɫ�ڵ�����������ɫ�ڵ㣬�ٿ����������Ƿ����㣬��������е���

��ɫ������
1������Ľڵ�(cur)�ĸ��ڵ�(p)Ϊ��ɫ����ֱ�Ӳ���

2������Ľڵ�(cur)�ĸ��ڵ�(p)Ϊ��ɫ��������ڵ�
2.1������ڵ������Ϊ��ɫ---->�����ڵ������ڵ��Ϊ��ɫ���游�ڵ��Ϊ��ɫ��
֮�����游�ڵ�Ϊ���ڵ㣬���ٱ�Ϊ��ɫ
����cur,p,g�����ƶ�����cur = p,���ж�cur�ĸ��ڵ㣬������ڵ㣨ѭ��2�������ϲ��裬ֱ��pΪ��ɫ�ڵ�Ϊֹ����

2.2������ڵ㲻���ڻ�Ϊ��ɫ�ڵ㣬ֱ����ʽ---->����ת
pΪg�����ӣ�curΪp������---->�ҵ���
pΪg���Һ��ӣ�curΪp���Һ���---->����
�ٽ�p��Ϊ�ڣ�g��Ϊ�졣

2.3������ڵ�Ϊ��ɫ�򲻴��ڣ�������ʽ-------->˫��
pΪg�����ӣ�curΪp���Һ���---->���p����--->�ҵ���
pΪg���Һ��ӣ�curΪp������---->���p�ҵ���--->����
�ٽ�p��Ϊ�ڣ�g��Ϊ�졣

ע�����ڵ�����parent��λ�÷����仯���ڶ�ԭ��λ�õĽڵ���ɫ�����ᵼ�´������Ե���֮ǰ����parent��λ�ã��ڶԱ���Ľڵ����ɫ���е���

�ڵ�ɾ����
�ڵ��ɾ����AVL����ɾ�����ƣ���Ϊ5�����
��ɾ��ĵ�ʱ�临�Ӷ�Ϊ0(lgN)

*/