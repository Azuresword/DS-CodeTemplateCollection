#include<iostream>
#include<string>
#include<queue>
using namespace std;
//Trie�������
class TrieTreeNode
{
public:
	string word;  //����ַ�
	int num;    // �ж��ٵ���ͨ������ڵ�,���ɸ����ýڵ���ɵ��ַ���ģʽ���ֵĴ���
	bool isEnd; // �ǲ������һ���ڵ�
	TrieTreeNode** Nextword = new TrieTreeNode * [26];
	TrieTreeNode()
	{
		num = 0;
		isEnd = false;
		for (int i = 0; i < 26; i++)
		{
			Nextword[i] = NULL;
		}
	}
	//~TrieTreeNode();
};

//Trie����
class TrieTree
{
private:
	TrieTreeNode* Root;   //���ڵ�ָ��
public:
	TrieTree();
	//~TrieTree();
	void insert(string str); //���ֵ����в���һ������
	int find(string str);   //���ֵ����в����Ը��ַ���Ϊ����ǰ׺�ĵ�����
	void show();            //��α����ֵ���
};
TrieTree::TrieTree()
{
	Root = new TrieTreeNode();
}
//���ֵ����в���һ������
void TrieTree::insert(string str)
{
	if (str == "" || str.length() == 0)
	{
		return;
	}
	TrieTreeNode* T = Root;
	int len = str.length();
	for (int i = 0; i < len; i++)
	{
		int pos = str[i] - 'a';
		//�����ǰ�ڵ�Ķ��ӽڵ���û�и��ַ����򹹽�һ��TrieTrieTreeNode����ֵ���ַ�
		if (T->Nextword[pos] == NULL)
		{
			T->Nextword[pos] = new TrieTreeNode();
			T->Nextword[pos]->word = str[i];
			T->Nextword[pos]->num++;
		}
		//����Ѿ����ڣ����ɸ����ö��ӽڵ���ɵ��ַ���ģʽ���ֵĴ���+1
		else
		{
			T->Nextword[pos]->num++;
		}
		T = T->Nextword[pos];
	}
	T->isEnd = true;
}
//���ֵ����в����Ը��ַ���Ϊ����ǰ׺�ĵ�����
int TrieTree::find(string str)
{
	if (str == "" || str.length() == 0)
	{
		return 0;
	}
	TrieTreeNode* T = Root;
	int len = str.length();
	for (int i = 0; i < len; i++)
	{
		int pos = str[i] - 'a';
		//�����ǰ�ڵ�Ķ��ӽڵ���û�и��ַ����򹹽�һ��TrieTrieTreeNode����ֵ���ַ�
		if (T->Nextword[pos] != NULL)
		{
			T = T->Nextword[pos];
		}
		//����Ѿ����ڣ����ɸ����ö��ӽڵ���ɵ��ַ���ģʽ���ֵĴ���+1
		else
		{
			return 0;
		}
	}
	return T->num;
}
//��α����ֵ���
void TrieTree::show()
{
	if (!Root) return;
	deque<TrieTreeNode*> q;
	q.push_back(Root);
	while (!q.empty())
	{
		int qs = q.size();
		for (int i = 0; i < qs; i++)
		{
			TrieTreeNode* tp = q.front(); q.pop_front();
			cout << tp->word;
			for (int i = 0; i < 26; i++)
				if (tp->Nextword[i]) q.push_back(tp->Nextword[i]);
		}
	}
	cout << endl;
}