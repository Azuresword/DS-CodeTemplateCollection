#include<iostream>
using namespace std;
//��������������������
class BiTreeNode
{
public:
	char data;  //�������
	int balance;  //���ƽ������
	BiTreeNode* LeftChild;   //������ָ��
	BiTreeNode* RightChild;  //������ָ��
	BiTreeNode* Parent;      //˫��ָ��
	BiTreeNode() :LeftChild(NULL), RightChild(NULL), Parent(NULL) {}
	//~BiTreeNode();
};

//������������������
class BiTree
{
private:
	BiTreeNode* Root;   //���ڵ�ָ��
	int pos;
	string strTree;

	BiTreeNode* CreateBiTree();
	void PreOrder(BiTreeNode* t);
	void InOrder(BiTreeNode* t);
	void PostOrder(BiTreeNode* t);
	void LevelOrder(BiTreeNode* t, int i);
	BiTreeNode* Create_PreOrder(int i, string str);
	void Height_Subtree(BiTreeNode* t_root, BiTreeNode* t, int& h);
	void Balance_calculate(BiTreeNode* t);
public:
	BiTree();
	//~BiTree();
	void CreateTree(string TreeArray);    //������������������������
	void PreOrder();    //ǰ�����
	void InOrder();     //�������
	void PostOrder();   //�������
	void LevelOrder();  //��α�����ʹ�ö��еĵݹ��㷨
	void CreatePreOrder(int i, string str);  //�ݹ��������˳������洢�Ķ�����
	int LeafDepth(BiTreeNode* t);  //����Ҷ�ӽ������ڸ��������
	int LeafDepth(BiTreeNode* t, BiTreeNode* t_root);  //����Ҷ�ӽ��t�����t_root�������
	int HeightSubtree(BiTreeNode* t);   //���������߶�
	void Balance_calculate();  //������ƽ������
};
BiTree::BiTree()
{
	pos = 0;
	strTree = "";
}

//���������������
void BiTree::PreOrder() //���к���������ӿ�
{
	PreOrder(Root);
}
void BiTree::PreOrder(BiTreeNode* t)
{
	if (t != NULL)
	{
		cout << t->data;
		PreOrder(t->LeftChild);
		PreOrder(t->RightChild);
	}
	else
		return;
}

//���������������
void BiTree::InOrder()  //���к���������ӿ�
{
	InOrder(Root);
}
void BiTree::InOrder(BiTreeNode* t)
{
	if (t != NULL)
	{
		InOrder(t->LeftChild);
		cout << t->data;
		InOrder(t->RightChild);
	}
	else
		return;
}

//��������������
void BiTree::PostOrder()  //���к���������ӿ�
{
	PostOrder(Root);
}
void BiTree::PostOrder(BiTreeNode* t)
{
	if (t != NULL)
	{
		PostOrder(t->LeftChild);
		PostOrder(t->RightChild);
		cout << t->data;
	}
	else
		return;
}

//�����������������������������
void BiTree::CreateTree(string TreeArray) //���к���������ӿ�
{
	pos = 0;
	strTree.assign(TreeArray);
	Root = CreateBiTree();
}
//�ݹ齨����˽�к���������ʵ��
BiTreeNode* BiTree::CreateBiTree()
{
	BiTreeNode* T;
	char c;
	c = strTree[pos++];
	if (c == '0')
		T = NULL;
	else
	{
		T = new BiTreeNode();
		T->data = c;    //���ɸ����
		T->LeftChild = CreateBiTree();    //����������
		if (T->LeftChild != NULL)
			T->LeftChild->Parent = T;
		T->RightChild = CreateBiTree();   //����������
		if (T->RightChild != NULL)
			T->RightChild->Parent = T;
	}
	return T;
}
//����Ҷ�ӽ������ڸ��������
int BiTree::LeafDepth(BiTreeNode* t)
{
	int depth = 0;
	BiTreeNode* T = t;
	while (1)
	{
		if (T == Root)
		{
			return depth;
		}
		else
		{
			if (T->Parent != NULL)
			{
				T = T->Parent;
				depth++;
			}
			else
			{
				return depth;
			}
		}
	}
}
//����Ҷ�ӽ��t�����t_root�������
int BiTree::LeafDepth(BiTreeNode* t, BiTreeNode* t_root)
{
	int depth = 0;
	BiTreeNode* T = t;
	while (1)
	{
		if (T->Parent != t_root->Parent)
		{
			T = T->Parent;
			depth++;
		}
		else
		{
			depth++;
			return depth;
		}
	}
}
//��α�������
void BiTree::LevelOrder()    //���к���������ӿ�
{
	for (int i = 0; i < 10; i++)
	{
		LevelOrder(Root, i);
	}
}
void BiTree::LevelOrder(BiTreeNode* t, int i)
{
	if (t != NULL)
	{
		if (LeafDepth(t) == i)
		{
			cout << t->data << " ";
		}
		LevelOrder(t->LeftChild, i);
		LevelOrder(t->RightChild, i);
	}
	else
		return;
}
//�ݹ��������˳������洢�Ķ�����
void BiTree::CreatePreOrder(int i, string str)
{
	Root = Create_PreOrder(i, str);
}
BiTreeNode* BiTree::Create_PreOrder(int i, string str)
{
	BiTreeNode* T;
	if (i < str.length())
	{
		if (str[i] != '0')
		{
			T = new BiTreeNode;
			T->data = str[i];
			T->LeftChild = Create_PreOrder(2 * i + 1, str);
			if (T->LeftChild != NULL)
				T->LeftChild->Parent = T;
			T->RightChild = Create_PreOrder(2 * i + 2, str);
			if (T->RightChild != NULL)
				T->RightChild->Parent = T;
		}
		else
		{
			T = NULL;
		}
	}
	else
	{
		T = NULL;
	}
	return T;
}
void BiTree::Height_Subtree(BiTreeNode* t_root, BiTreeNode* t, int& h)
{
	if (t != NULL)
	{
		Height_Subtree(t_root, t->LeftChild, h);
		Height_Subtree(t_root, t->RightChild, h);
		if (LeafDepth(t, t_root) >= h)
			h = LeafDepth(t, t_root);
	}
	else
		return;
}
//������ƽ������
void BiTree::Balance_calculate()  //���к���������ӿ�
{
	Balance_calculate(Root);
}
void BiTree::Balance_calculate(BiTreeNode* t)
{
	if (t != NULL)
	{
		Balance_calculate(t->LeftChild);
		Balance_calculate(t->RightChild);
		t->balance = HeightSubtree(t->LeftChild) - HeightSubtree(t->RightChild);
	}
	else
		return;
}