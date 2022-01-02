#include<iostream>
#include<string>
#include<queue>
#include<stack>
using namespace std;
//�����������
class BiTreeNode
{
public:
	char data;  //�������
	BiTreeNode* LeftChild;   //������ָ��
	BiTreeNode* RightChild;  //������ָ��
	//���캯��
	BiTreeNode() :LeftChild(NULL), RightChild(NULL) {}
	//~BiTreeNode();
};

//��������
class BiTree
{
private:
	BiTreeNode* Root;   //�����ָ��
	int pos;
	string strTree;

	BiTreeNode* CreateBiTree();
	void PreOrder(BiTreeNode* t);
	void InOrder(BiTreeNode* t);
	void PostOrder(BiTreeNode* t);
	void PostOrder_stack(BiTreeNode* t);
	void LevelOrder(BiTreeNode* t);
public:
	BiTree();
	//~BiTree();
	void CreateTree(string TreeArray);    //������������������������
	void PreOrder();    //ǰ�����
	void InOrder();     //�������
	void PostOrder();   //�������
	void PostOrder_stack();  //��������ǵݹ��㷨
	void LevelOrder();  //��α���
	void PreOrder_nonerecursion(BiTreeNode * t);		//dylan-�ύ�ǵݹ鷽���Ķ��������� ʹ��ջ����
	void InOrder_nonerecursion(BiTreeNode* t);			
};
BiTree::BiTree()
{
	pos = 0;
	strTree = "";
}

//���������������
void BiTree::PreOrder_nonerecursion(BiTreeNode * t);
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
		T->RightChild = CreateBiTree();   //����������
	}
	return T;
}

//��α�������
void BiTree::LevelOrder()    //���к���������ӿ�
{
	LevelOrder(Root);
}
void BiTree::LevelOrder(BiTreeNode* t)
{//�ö���ʵ��
	queue<BiTreeNode*> tq;
	BiTreeNode* p = t;
	if (p != NULL)
	{
		tq.push(p);
	}
	while (!tq.empty())
	{
		p = tq.front();
		tq.pop();
		if (p != NULL)
		{
			cout << p->data;
			tq.push(p->LeftChild);
			tq.push(p->RightChild);
		}
	}
}

//����ǵݹ����
void BiTree::PostOrder_stack()   //���к���������ӿ�
{
	PostOrder_stack(Root);
}
void BiTree::PostOrder_stack(BiTreeNode* t)
{
	stack<BiTreeNode*> s1;
	stack<int> s2;
	int tag;
	BiTreeNode* p = t;
	do
	{
		while (1)
		{
			if (p != NULL)
			{
				s1.push(p);
				tag = 0;
				s2.push(tag);
				p = p->LeftChild;
			}
			else
				break;
		}

		if (s1.empty())
			break;
		if (p == NULL)
		{
			tag = s2.top();
			if (tag == 0)
			{
				s2.top() = 1;
				p = s1.top()->RightChild;
			}
			else
			{
				p = s1.top();
				s1.pop();
				s2.pop();
				cout << p->data;
				p = NULL;
			}
		}
	} while (!s1.empty());
}

void BiTree:: PreOrder_nonerecursion(BiTreeNode * t){
	stack <BiTreeNode*> s1;
	while ((t!=NULL)||(s1.empty()!=1))
	{
		if(t!=NULL){
			cout<<t->data;
			s1.push(t);
			t=t->LeftChild;
		}
		else{
			s1.pop();
			t=t->RightChild;
		}
	}
}

void BiTree:: InOrder_nonerecursion(BiTreeNode* t){
		stack <BiTreeNode*> s1;
	while ((t!=NULL)||(s1.empty()!=1))
	{
		if(t!=NULL){
			
			s1.push(t);
			t=t->LeftChild;
		}
		else{
			s1.pop();
			cout<<t->data;
			t=t->RightChild;
		}
	}
}

//���������