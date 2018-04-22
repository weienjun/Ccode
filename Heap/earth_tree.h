#include<iostream>
#include<stack>
#include<queue>

using namespace std;

template<class T>
struct TreeNode
{
	T _value;
	TreeNode* _left;
	TreeNode* _right;

	TreeNode(const T& x)//���캯��
		:_value(x)
		,_left(NULL)
		,_right(NULL)
	{}
};

template <class T>
class Tool//���캯��
{
	typedef TreeNode<T> TNode;//�Զ�������
public :
	Tool(T* arr,size_t size,const T invalid)//invalid�Ƿ�ֵ
	{
		size_t index = 0;
		//while(size--)//���ɼ�ѭ��
		_tree = CreateBinaryTree(arr,size,index,invalid);//������
	}

	TNode* CreateBinaryTree(T* arr,const size_t size,size_t& index,T invalid)//��������ǰ��
	{
	    TNode* _tree = NULL;
		if(index < size && arr[index] != invalid)//ע��Խ��
		{
			_tree = new TNode(arr[index]);//�������ڵ㣨�Զ����ù��캯����
			_tree->_left = CreateBinaryTree(arr,size,++index,invalid);//����������

			_tree->_right = CreateBinaryTree(arr,size,++index,invalid);//����������
		}
		return _tree;
	}

	size_t Size()//ʹ�õݹ�ķ������㣬��Ҫ���Σ��������صķ���
	{
		size_t size = 0;
		Size(_tree,size);
		return size;
	}
	size_t Size(TNode* _tree,size_t& size)//�ڵ���
	{
		if(_tree == NULL) 
			return 0;
		size++;
	    Size(_tree->_left,size);
		Size(_tree->_right,size);
		return size;
	}

	size_t Size_leave()//Ҷ����
	{
		size_t count = 0;
		return Size_leave(_tree,count);
	}

	size_t Size_leave(TNode* _tree,size_t& count)
	{
		
		if(NULL == _tree)
			return count;//�˳��ݹ�����
		if(_tree->_left == NULL && _tree->_right == NULL)
			 count++;
		Size_leave(_tree->_left,count);
		Size_leave(_tree->_right,count);
		return count;//ÿ��ݹ鷵��ֵ
	}

	size_t Heigh()//��������ȣ���Ŀ����� �ֱ����������������+1
	{
		size_t count = 0;
		return Heigh(_tree);
	}
	size_t Heigh(TNode* _tree)
	{
		static size_t n1 = 1;//���ڵ�Ϊ��һ��
		static size_t n2 = 1;
	
		if(NULL == _tree)//�սڵ㷵��0
			return 0;
		Heigh(_tree->_left);
		Heigh(_tree->_right);//����ʱ����
		if(_tree->_left || _tree->_right)//��������������Ľڵ�Ž��бȽ�
		return (n1 > n2 ? n1 : n2)++;
		return 1;//ֻ�и��ڵ�
	}

	size_t GetKleve(size_t K)
	{
		return GetKleve(_tree,K);
	}
	size_t GetKleve(TNode* tree,size_t K)//���K��Ľڵ���  �ݹ�������K-1��
	{
		if(tree == NULL || K == 0)
			return 0;
		if(K == 1)
			return 1;
		return GetKleve(tree->_left,K-1)+GetKleve(tree->_right,K-1);
	}

	void Mirror()//����---ǰ������ݹ飬�������������н���
	{
		Mirror(_tree);
	}
	void Mirror(TNode* _tree)
	{
		TNode* ptemp = NULL;//�����м����
		if(NULL == _tree)
			return ;
	
		ptemp = _tree->_left;
		_tree->_left = _tree->_right;
		_tree->_right = ptemp;

		Mirror(_tree->_left);
		Mirror(_tree->_right);
	}
	//������ȼ� ʹ�ö���ʵ��
	//1.ͷ�ڵ������
	//2�����в�Ϊ��-->ѭ������
	//3��������ͷ
	//4�������������Ϊ��--�����
	//5����ͷ������
	void Leve_Order()//������ȼ� ʹ�ö���ʵ��
	{
		Leve_Order(_tree);
	}
	void Leve_Order(TNode* tree)
	{
		queue<TNode*> q;
		TNode* cur = tree;
		TNode* Top = NULL;
		if(cur == NULL )
			return ;
		q.push(tree);
		while(!q.empty())
		{
			Top = q.front();
			cout << Top->_value << ' ' ;
			q.pop();
			if(Top->_left != NULL)
			{
				q.push(Top->_left);
			}
			if(Top->_right != NULL)
				q.push(Top->_right);
		}
	}

	void Mirror2()//�ǵݹ�---ʹ�ö��д���������������ƹ�����ȼ������������Ľ���������(��)������������
	{
		Mirror2(_tree);
	}
	void Mirror2(TNode* tree)
	{
		queue<TNode*> q;
		TNode* temp = NULL;
		TNode* Top = tree;
		if(tree == NULL)
			return ;

		q.push(tree);
		while(!q.empty())
		{
			Top = q.front();
			//����λ��
			temp = Top->_left;
			Top->_left = Top->_right;
			Top->_right = temp;

			q.pop();
			if(Top->_left != NULL)
			{
				q.push(Top->_left);
			}
			if(Top->_right != NULL)
				q.push(Top->_right);
		}
	}
	//�ж��Ƿ�Ϊ��ȫ������
	//������ȫ��������1��ͬһ�ڵ����������������� 2��С��N-1�㲻�����������Һ��ӽڵ㿪ʼ��֮��ڵ��޺��ӽڵ㣩
	int IsCompleteBinTree()//�ж��Ƿ�Ϊ��ȫ������---��α�����ʹ�ö���
	{
		return IsCompleteBinTree(_tree);
	}
	int IsCompleteBinTree(TNode* tree)
	{
		queue<TNode*> q;
		TNode* Top = tree;
		TNode* cur = NULL;//��ǲ����ĸ��׽ڵ�
		if(tree == NULL)
			return 0;

		q.push(tree);
		while(!q.empty())
		{
			Top = q.front();
		
			if(Top->_left == NULL && Top->_right != NULL ||//������������������
				Top->_left != NULL && cur != NULL)//С��N-1�㲻��curΪ������
				return 0;
			if(Top->_right == NULL)
				cur = Top;//��ǲ���λ��
			q.pop();

			if(Top->_left)
				q.push(Top->_left);
			if(Top->_right)
				q.push(Top->_right);
		}
		return 1;
	}

	void Tree_print()//_tree�ⲿ���ɷ���
	{
		Tree_print(_tree);//����
	}
    void Tree_print(TNode* ptool)//ǰ�����
	{
		if(ptool)
		{
			printf("%c ",ptool->_value);
			Tree_print(ptool->_left);//��
			Tree_print(ptool->_right);//��
		}
	}

	TNode* Find(const T& data)//����
	{
		return Find(_tree,data);//�ݹ�
		//return find(_tree,data);//�ǵݹ�
	}
	TNode* Find(TNode* tree,const T& data)//�ݹ�ʵ��
	{
		TNode* tmp = NULL;
		if(NULL == tree)
			return NULL;
		if(tree->_value == data)
			return tree;

		tmp = Find(tree->_left,data);
		if(tmp)//���ڼ���������Ƿ��ҵ��������жϣ���һֱ��Ҫ�����������ң����´���
		{
            return tmp;//�ҵ������˳�
		}
		return Find(tree->_right,data);//������δ�ҵ���������������
	}
	TNode* find(TNode* tree,const T& data)//�ǵݹ����---ջʵ��
	{
		stack<TNode*> s;
		TNode* cur = tree;
		if(NULL == tree)
			return NULL;
		s.push(tree);
		while(!s.empty())
		{
			TNode* Top = s.top();
			if(Top->_value == data)
				return Top;
			s.pop();
			if(Top->_left)
				s.push(Top->_left);
			if(Top->_right)
				s.push(Top->_right);
		}
		return NULL;
	}
	//�ǵݹ�---ʹ��ջ
	//ǰ�����,����������������
	void PreOrderNor()//ǰ�����
	{
		PreOrderNor(_tree);
	}
	void PreOrderNor(TNode* _tree)
	{
		stack<TNode*> entry;
		TNode* cur = _tree;
		if(_tree == NULL)
			return ;
		entry.push(_tree);//���ڵ���ջ

		while(cur && !entry.empty())
		{
			cur = entry.top();
			cout << cur->_value << ' ' ;
			entry.pop();

			if(cur->_right)//ջ���Ƚ��������������������ջ
			{
				entry.push(cur->_right);//��������ջ
			}

			if(cur->_left)
			{
				entry.push(cur->_left);//��������ջ
				cur = cur->_left;
			}
		}
	}
	//����ݹ����
	void InOrder()
	{
		InOrder(_tree);
	}
	void InOrder(TNode* pRoot)
	{
		if(pRoot != NULL)
		{
			InOrder(pRoot->_left);
			printf("%c ",pRoot->_value);
			InOrder(pRoot->_right);
		}
	}

	void InOrderNor()//���������
	{
		InOrderNor(_tree);
	}
	void InOrderNor(TNode* _tree)
	{
		stack<TNode*> entry;
		TNode* cur = _tree;
		TNode* Top = NULL;
		if(NULL == _tree)
			return ;
		while(cur || !entry.empty())
		{
			while(cur)//�ߵ������
			{
				entry.push(cur);
				cur = cur->_left;
				
			}

			Top = entry.top();//ȡջ��
			cout << Top->_value <<' ' ;//���ջ��

			if(Top->_right)//����������ջ
				cur = Top->_right;
			entry.pop();
		}
	}

	void PostOderNor()//�������
	{
		PostOderNor(_tree);
	}
	void PostOderNor(TNode* _tree)
	{
		stack<TNode*> entry;
		TNode* cur = _tree;
		TNode* Top = NULL;
		TNode* prev = NULL;
		if(NULL == _tree)
			return ;
		while(cur || !entry.empty())
		{
			while(cur)//�ߵ���ǰ���������
			{
				entry.push(cur);
				cur = cur->_left;
			}
			Top = entry.top();

			if(Top->_right == NULL || prev == Top->_right)//��Ϊ�ջ����ѱ����ʣ�����ʵ�ǰ���ڵ�
			{
				cout << Top->_value << ' ' ;
				prev = entry.top();//����ѷ��ʹ����ҽڵ�
				entry.pop();//���ʹ��Ľڵ��ջ
			}
			else//���ҽڵ���Ϊһ���µ���
			cur = Top->_right;
		}
	}

	~Tool()//����---��������
	{
		Delete(_tree);
		_tree = NULL;
	}
	void Delete(TNode* tree)
	{
		if(!tree)
			return ;
		Delete(tree->_left);
		Delete(tree->_right);
		delete tree;
	}

	//�ж��Ƿ�Ϊ������
	#include<queue>
	bool Judge()
	{
		return Judge(_tree);
	}

	bool Judge(TNode* root)
	{
		queue<TNode*> q;
		if(root == NULL)
			return true;
		q.push(root);
		while(!q.empty())
		{
			TNode* top = q.front();
			q.pop();

			if(top->_left && top->_right)
			{
				if(!(top->_left ->_value < top->_value && top->_value < top->_right->_value ))
					return false;
				q.push(top->_left);
				q.push(top->_right);
			}
			else if(top->_left == NULL && top->_right != NULL)
			{
				if(!(top->_value < top->_right->_value))
					return false;
				q.push(top->_right);	
			}
			else if((top->_left != NULL) && (top->_right == NULL))
			{
				if(!(top->_left ->_value < top->_value))
					return false;
				q.push(top->_left);
			}
		}
		return true;
	}

	
private :
	TNode* _tree;
};

//ʱ�临�Ӷȣ�O(n+1)==O(n)
//�ռ临�Ӷȣ�O(n)
//ǰ��
//����
//����
//���򣨹�����ȱ�����--->ʹ�ö���ʵ��
//template <class T>
void tree_test()
{
	char arr[] = {'a','b','d','#','#','g','#','#','c','e','#','#'};
	//char arr[] = {'a','b','d','#','#','g','#','#','c','#','e','#','#'};
	//char arr[] = {'a','b','d','f','#','#','m','#','#','g','#','#','c','e','#','#','#','#'};

	//char arr[] = {'a','#','#','#','#'};

	int sz = sizeof(arr)/sizeof(arr[0]);
	Tool<char> tree(arr,sz,'#');
	
	tree.Tree_print();
	cout << endl;
	cout << "�ܽ������" << tree.Size() << endl;
	cout << "Ҷ�ӽڵ�����" << tree.Size_leave() << endl;
	cout << "������ȣ�" << tree.Heigh() << endl;
	cout << "��K��ڵ�����" << tree.GetKleve(2) << endl;

	cout << "��һ�ξ���" ;
	tree.Mirror();
	tree.Tree_print();
	cout << endl;
	cout << "�ڶ��ξ���" ;
	tree.Mirror();
	tree.Tree_print();

	cout <<"\n���������";
	tree.PreOrderNor();

	cout <<"\n���������";
	tree.InOrderNor();
	cout <<"\n����ݹ������";
	tree.InOrder();

	cout <<"\n���������";
	tree.PostOderNor();
	cout <<"\n��α�����" ;
	tree.Leve_Order();

	cout << "\n��һ�ξ���";
	tree.Mirror2();
	tree.Tree_print();
	cout << "\n�ڶ��ξ���";
	tree.Mirror2();
	tree.Tree_print();

	cout << "\n�Ƿ�Ϊ��ȫ��������" ;
	cout << tree.IsCompleteBinTree() << endl;

	cout << tree.Find('b')->_value << endl;
	
	cout << tree.Judge() << endl;
}

//���������
