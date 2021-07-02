#include<iostream>
using namespace std;
class hash_node
{
public:
	int data;   //�������
	int order;
	hash_node* next;
	hash_node()
	{
		data = -1;
		order = 1;
		next = NULL;
	}
};
//�����෨Ϊ��ϣ����
//��ϣ��ͻ������ַ��(��ͷ����)
class hash_map
{
private:
	hash_node* hashmap;   //��ϣ�������
public:
	hash_map(int n)
	{
		hashmap = new hash_node[n];
		int a;
		int key;
		while (n--)
		{
			cin >> a;
			key = a % 11;
			if (hashmap[key].data != -1)
			{
				hash_insert(&hashmap[key], a);
			}
			else
				hashmap[key].data = a;
		}
	}
	//�ݹ���ҹ�ϣ��ͻ
	int find_next(hash_node* hash, int target)
	{
		if (hash != NULL)
		{
			if (hash->data != target)
				return find_next(hash->next, target);
			else
				return hash->order;
		}
		else
			return 0;
	}
	//��ϣ���Һ���
	void hash_find(int target)
	{
		int key;
		key = target % 11;
		if (hashmap[key].data != target)
		{
			if (find_next(hashmap[key].next, target) != 0)
			{
				cout << key << " " << find_next(hashmap[key].next, target) << endl;
			}
			else
			{
				//����ʧ�ܣ������ݲ��뵽��ϣ����
				hash_insert(&hashmap[key], target);
				cout << "error" << endl;
			}
		}
		else
		{
			cout << key << " " << hashmap[key].order << endl;
		}
	}
	//��ϣ���뺯��
	//������target���˵���ϣ���У���ϣ��ͻ������ַ��(��ͷ����)
	void hash_insert(hash_node* hash, int target)
	{
		if (hash->data == -1)
		{
			hash->data = target;
			return;
		}
		else
		{
			if (hash->next != NULL)
			{
				hash_insert(hash->next, target);
				hash->order++;
			}
			else
			{
				hash_node* h = new hash_node();
				h->data = target;
				hash->order++;
				hash->next = h;
			}
		}
	}
};