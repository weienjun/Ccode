
//�����ʵ�ַ���1
#include<iostream>
using namespace std;

enum RB {RED,BLACK};
template<class T,class V>
struct RBTNode {
	T _key;
	V _value;
	enum RB _color;
	int _count;
	RBTNode<T, V> *_left;
	RBTNode<T,V> *_right;

	RBTNode(T key = (T), V value = (V)) 
		:_key(key)
		,_value(value)
		,_color(RED)
		,_count(1)
		,_left(NULL)
		,_right(NULL)
	{}
};

template<class T, class V>
class RBTree {
public:
	typedef RBTNode<T, V> RBTNode;
	//���죬�������죬��ֵ���������
	RBTree()
		:_root(NULL)
	{}

	int size() {
		size(_root);
	}

	int size(RBTNode* node) {
		if (node)  return node->_count;
		else return 0;
	}

	void put(T key, V value) {
		_root = _put(_root, key, value);  //�ݹ����
		_root->_color = BLACK; //������Ϊ��ɫ
	}
	RBTNode* _put(RBTNode* root, T key, V value) {
		//�����½ڵ�
		if (root == NULL) {
			return new RBTNode(key, value);
		}

		//�ݹ���Ҳ���λ��
		if (root->_key < key) {
			root->_right = _put(root->_right, key, value);
		}
		else if (root->_key > key) {
			root->_left = _put(root->_left, key, value);
		}
		else {
			root->_value = value;
		}

		//�ҵ��˲���ڵ�λ��root,�����ѽ��½ڵ����
		//�ݹ���к�ڵ���(����ڵ㶼Ϊ��ɫ)���������ϵ���������ɫ��ֱ�����ڽ���
		//1������λ�ýڵ�Ϊ��ɫ���½ڵ�������Ҳ࣬����һ������ת
		//2������λ�ýڵ�Ϊ��ɫ���½ڵ��������࣬����һ������ת��
		//3�����������ӽڵ㶼Ϊ��ɫ�ڵ㣬�������ӽڵ��Ϊ��ɫ�������Ϊ��ɫ
		if (isRED(root->_right) && !isRED(root->_left))       root = rotateLeft(root);  //�����ڵ�Ϊ����λ�õĽڵ�
		if (isRED(root->_left) && isRED(root->_left->_left))  root = rotateRight(root);  //ע�������Ľڵ�Ϊ����λ�ýڵ����һ���ڵ�
		if (isRED(root->_left) && isRED(root->_right)) root = flipColor(root);  //���������ӽڵ㶼Ϊ��ɫ���������ɫ�任

		//�ڵ���Ŀͳ��
		root->_count = size(root->_left) + size(root->_right) + 1;
	
		return root;
	}

	bool isRED(RBTNode* node) {
		if (node == NULL) return false;
		if (node->_color == RED) return true;
		else return false;
	}
	RBTNode* rotateLeft(RBTNode *root) {
		//�ڵ�λ�ý���
		RBTNode* root_right = root->_right;
		root->_right = root_right->_left;
		root_right->_left = root;

		//�ڵ����ɫ��ԭ����λ�ýڵ���ɫ����һ��
		root_right->_color = root->_color; 
		root->_color = RED;

		//�ڵ������Ҳͬ����ԭ������һ��
		root_right->_count = root->_count;

		//��ӽڵ�λ�ýڵ����¼���
		root->_count = size(root->_left) + size(root->_right) + 1;

		return root_right;  //�����µ�root
	}

	RBTNode* rotateRight(RBTNode* root) {
		//�ڵ�λ�ý���
		RBTNode* root_left = root->_left;
		root->_left = root_left->_right;
		root_left->_right = root;

		//����ԭλ�ýڵ����ɫ
		root->_color = RED;
		root_left->_color = root->_color;
		//����ԭ��λ�õļ�����ֵ
		root_left->_count = root->_count;
		//����ڵ�λ�õĽڵ����¼���
		root->_count = size(root->_left) + size(root->_right) + 1;

		return root_left;
	}

	RBTNode* flipColor(RBTNode* root) {
		root->_color = RED;
		root->_left->_color = BLACK;
		root->_right->_color = BLACK;
		return root;
	}

	//ɾ���ڵ�
	//����2-3�����ص㣬ɾ���ڵ�ֻ��ɾ��һ��3-�ڵ㣬����ɫ�ڵ㣬���������Ĳ�ƽ��
	//ɾ��2-�ڵ�ʱ������ɫ�ڵ�ʱ�����ȶ������е�����������һ����ɫ�ڵ㣬Ȼ����ɾ��

	void Delete(T key) {
		if (!isRED(_root->_left) && !isRED(_root->_right)) {
			_root->_color = RED;
		}
		_root = _delete(_root, key);
		if (_root) {
			_root->_color = BLACK;
		}
	}

	RBTNode* _delete(RBTNode* root, T key) {
		if (root->_key > key) {
			if (!isRED(root->_left) && !isRED(root->_left->_left)) {
				root = moveRedLeft(root);
			}
			root->_left = _delete(root->_left, key);
		}
		else {
			if (isRED(root->_left)) root = rotateRight(root);
			if (root->_key == key && root->_right == NULL) return NULL;
			if (!isRED(root->_right) && !isRED(root->_right->_left)) root = moveRedRight(root);
			if (root->_key == key) {
				T min_key = min(root->_right);
				root->_value = get(root->_right, min_key);
				root->_key = min_key;
				root->_right = _deleteMin(root->_right);
			}
			else {
				root->_right = _delete(root->_right, key);
			}
		}
		return balance(root);
	}

	RBTNode* moveRedLeft(RBTNode* root) {
		noFlipColor(root);
		if (isRED(root->_right->_left)) {
			root->_right = rotateRight(root->_right);
			root = rotateLeft(root);
		}
		return root;
	}

	RBTNode* moveRedRight(RBTNode* root) {
		noFlipColor(root);
		if (!isRED(root->_left->_left)) {
			root = rotateRight(root);
		}
		return root;
	}

	RBTNode* _deleteMin(RBTNode* root,RBTNode* &del) {
		if (root->_left == NULL) {  //�ҵ���С�ڵ�
			del = root;  //������С�ڵ�
			return NULL;  //����NULL���ڽ���,��ɾ������С�ڵ�
		}
		if (!isRED(root->_left) && isRED(root->_left->_left)) {
			root = moveRedLeft(root);
		}
		root->_left = _deleteMin(root->_left,del);  //����ɾ����Ľڵ㣬��������ΪNULL
		return balance(root);
	}

	RBTNode* _deleteMin(RBTNode* root) {
		RBTNode* del = NULL;
		root = _deleteMin(_root, del);
		if (del) {
			delete del;
			del = NULL;
		}
		return root;
	}

	RBTNode* _deleteMax(RBTNode* root,RBTNode* &del) {
		if (isRED(root->_left)) root = rotateRight(root);
		if (root->_right == NULL) {
			del = root;
			return NULL;
		}
		if (!isRED(root->_right) && isRED(root->_right->_left)) {
			root = moveRedRight(root);
		}
		root->_right = _deleteMax(root->_right,del);
		return balance(root);
	}

	RBTNode* _deleteMax(RBTNode* root) {
		RBTNode* del = NULL;
		root = _deleteMax(_root, del);
		if (del) {
			delete del;
			del = NULL;
		}
		return root;
	}

	RBTNode* balance(RBTNode* root) {
		if (isRED(root->_right)) root = rotateLeft(root);
		if (isRED(root->_right) && !isRED(root->_left))       root = rotateLeft(root);  //�����ڵ�Ϊ����λ�õĽڵ�
		if (isRED(root->_left) && isRED(root->_left->_left))  root = rotateRight(root);  //ע�������Ľڵ�Ϊ����λ�ýڵ����һ���ڵ�
		if (isRED(root->_left) && isRED(root->_right)) root = flipColor(root);  //���������ӽڵ㶼Ϊ��ɫ���������ɫ�任																			//�ڵ���Ŀͳ��
		root->_count = size(root->_left) + size(root->_right) + 1;

		return root;
	}

	void noFlipColor(RBTNode* root) {
		if (root) {
			root->_color = BLACK;
			root->_left->_color = RED;
			root->_right->_color = RED;
		}
	}

	V get(RBTNode* root, T key) {
		if (root == NULL) return -1;
		if (root->_key == key) return root->_value;
		else if (root->_key < key)  return get(root->_right, key);
		else  return get(root->_left, key);
	}

	T min(RBTNode* root) {
		if (root == NULL) return -1;
		if (root->_left == NULL) return root->_key;
		return min(root->_left);
	}

	T get() {
		return get(_root, min(_root));
	}

	void deleteMin() {
		_deleteMin(_root);
	}

	void deleteMax() {
		_deleteMax(_root);
	}

	void Print() {
		_Print(_root);
	}

	void _Print(RBTNode* root) {
		if (root == NULL) return;
		_Print(root->_left);
		cout << root->_key << " ";
		_Print(root->_right);
	}

private:
	RBTNode *_root;
 };

void test_RBTree() {
	RBTree<int, int> rb;
	rb.put(1, 1);
	rb.put(2, 2);
	rb.put(3, 3);
	rb.put(4, 4);


	cout << rb.get() << endl;

	rb.Print();
	cout << endl;
	rb.deleteMin();
	rb.Delete(3);
	rb.deleteMax();
	rb.Print();
	cout << endl;

}