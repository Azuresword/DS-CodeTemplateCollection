#include<iostream>
using namespace std;
class hash_map
{
private:
	int* hashmap;
	int len;
	int pos;

	//��ϣ�����ͻʱ�ݹ�ɢ��
	//˽�к��������ڵ���
	void next_insert(int& key, int p)
	{
		int original_key = key;
		key += pos * pos;
		if (key >= len)
			key = key - len;
		if (hashmap[key] < 0)
			hashmap[key] = p;
		else
		{
			key = key - pos * pos * 2;
			if (key < 0)
				key = key + len;
			if (hashmap[key] < 0)
				hashmap[key] = p;
			else
			{
				pos++;
				next_insert(original_key, p);
			}
		}
	}
	//��ϣ���ҳ�ͻʱ�ݹ�ɢ��
	//˽�к��������ڵ���
	int next_find(int& key, int target, int& num)
	{
		num++;
		int original_key = key;
		key += pos * pos;
		if (key >= len)
			key = key - len;
		if (hashmap[key] == target)
			return key + 1;
		else if (hashmap[key] < 0)
			return 0;
		else
		{
			num++;
			key = key - pos * pos * 2;
			if (key < 0)
				key = key + len;
			if (hashmap[key] == target)
				return key + 1;
			else if (hashmap[key] < 0)
				return 0;
			else
			{
				pos++;
				next_find(original_key, target, num);
			}
		}
	}
public:
	hash_map(int m)
	{
		len = m;
		hashmap = new int[m];
		pos = 1;
	}
	//��ϣ����չʾ����
	void hash_display()
	{
		for (int i = 0; i < len; i++)
		{
			if (hashmap[i] >= 0)
				cout << hashmap[i] << " ";
			else
			{
				cout << "NULL ";
				//cout << hashmap[i] << " ";
			}
		}
		cout << endl;
	}
	//��ϣ���뺯��
	void hash_insert(int p)
	{
		int key;
		key = p % 11;
		if (hashmap[key] < 0)
			hashmap[key] = p;
		else
		{
			pos = 1;
			next_insert(key, p);
		}
	}

	//��ϣ���Һ���
	void hash_find(int target)
	{
		int key;
		key = target % 11;
		int num;  //���Ҵ���
		num = 1;
		if (hashmap[key] < 0)
		{
			cout << 0 << " ";
			cout << num << endl;
		}
		else if (hashmap[key] == target)
		{
			cout << 1 << " ";
			cout << num << " ";
			cout << key + 1 << endl;
		}
		else
		{
			pos = 1;
			int result = next_find(key, target, num);
			if (result != 0)
			{
				cout << 1 << " ";
				cout << num << " ";
				cout << result << endl;
			}
			else
			{
				cout << 0 << " ";
				cout << num << endl;
			}
		}
	}
};