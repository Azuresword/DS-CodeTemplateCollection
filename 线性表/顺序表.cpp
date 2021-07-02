#include<iostream>
#include<stdio.h>
using namespace std;
//˳���
class SeqList
{
private:
	int* list;   //����
	int maxsize;   //����
	int size;      //��ǰ��
public:
	SeqList();
	~SeqList();
	void list_int(int n);  //����n�����������δ���˳����д�0��ʼ��λ��
	int list_size();   //���㲢���ص�ǰ˳���ı�
	void list_insert(int i, int item);  //��item���뵽˳���ĵ�i��λ��
	void list_del(int i);  //ɾ��˳����е�i������
	void list_get(int i);  //��ӡ˳����е�i������
	void list_display();   //��ӡ����˳����е�����
	//���������ݵ�list_multiinsert������ʵ���ڵ�i��λ�ã�����������������item��n�����ݡ�
	//����λ��i��ʼ���������ݡ�
	void list_multiinsert(int i, int n, int* item); 
	//ɾ��������ݵ�list_multidel������ʵ�ִӵ�i��λ�ÿ�ʼ������ɾ��n�����ݡ�
	//����λ��i��ʼɾ��������ݡ�
	void list_multidel(int i, int n);
	void list_sort();  //˳���������
	int* list_getlist();  //��������ָ�룬��list_combine�������
	int list_getsize();   //�������鳤�ȣ���list_combine�������
	SeqList list_combine(SeqList& a, SeqList& b);  //�ϲ�����˳���
	void list_move(int d, int n);  //˳���ѭ����λ����
};
//���캯��
SeqList::SeqList()
{
	maxsize = 1000;
	size = 0;
	list = new int[maxsize];
}
//��������
SeqList::~SeqList()
{
	delete[]list;
}
//����n�����������δ���˳����д�0��ʼ��λ��
void SeqList::list_int(int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> list[i];
	}
	size = n;
}
//���㲢���ص�ǰ˳���ı�
int SeqList::list_size()
{
	for (int i = 0; i < 1000; i++)
	{
		if (list[i] == '\0')
			size = i + 1;
	}
	return size;
}
//��item���뵽˳���ĵ�i��λ��
void SeqList::list_insert(int i, int item)
{
	if ((i > 0) && (i <= (size + 1)))
	{
		for (int k = size; k >= i; k--)
		{
			list[k] = list[k - 1];
		}
		list[i - 1] = item;
		size++;
		list_display();
	}
	else
		cout << "error" << endl;
}
//ɾ��˳����е�i������
void SeqList::list_del(int i)
{
	if ((i > 0) && (i <= size))
	{
		size--;
		for (int k = i - 1; k < size; k++)
		{
			list[k] = list[k + 1];
		}
		list_display();
	}
	else
		cout << "error" << endl;
}
//��ӡ˳����е�i������
void SeqList::list_get(int i)
{
	if ((i > 0) && (i <= size))
		cout << list[i - 1] << endl;
	else
		cout << "error" << endl;
}
//��ӡ����˳����е�����
void SeqList::list_display()
{
	//�ȴ�ӡ˳���ı�
	cout << size << " ";
	for (int i = 0; i < size; i++)
	{
		cout << list[i] << " ";
	}
	cout << endl;
}
//���������ݵ�list_multiinsert������ʵ���ڵ�i��λ�ã�����������������item��n�����ݡ�
//����λ��i��ʼ���������ݡ�
void SeqList::list_multiinsert(int i, int n, int* item)
{
	if ((i > 0) && (i <= (size + 1)))
	{
		for (int k = size + n - 1; k > i; k--)
		{
			list[k] = list[k - n];
		}
		for (int k = i - 1; k < i - 1 + n; k++)
		{
			list[k] = item[k - i + 1];
		}
		size += n;
		list_display();
	}
	else
		cout << "error" << endl;
}
//ɾ��������ݵ�list_multidel������ʵ�ִӵ�i��λ�ÿ�ʼ������ɾ��n�����ݡ�
//����λ��i��ʼɾ��������ݡ�
void SeqList::list_multidel(int i, int n)
{
	if ((i > 0) && (i <= size))
	{
		size -= n;
		for (int k = i - 1; k < size; k++)
		{
			list[k] = list[k + n];
		}
		list_display();
	}
	else
		cout << "error" << endl;
}
//˳���������
void SeqList::list_sort()
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (list[i] > list[i + 1])
			{
				int mid;
				mid = list[i];
				list[i] = list[i + 1];
				list[i + 1] = mid;
			}
		}
	}
}
//��������ָ�룬��list_combine�������
int* SeqList::list_getlist()
{
	return list;
}
//�������鳤�ȣ���list_combine�������
int SeqList::list_getsize()
{
	list_size();
	return size;
}
//�ϲ�����˳���
SeqList SeqList::list_combine(SeqList& a, SeqList& b)
{
	SeqList sum;
	sum.list_multiinsert(0, a.list_getsize(), a.list_getlist());
	sum.list_multiinsert(1, b.list_getsize(), b.list_getlist());
	sum.list_sort();
	sum.list_display();
	return sum;
}
//˳���ѭ����λ����
void SeqList::list_move(int d, int n)
{
	int* nlist = new int[size];
	if (d == 0)
	{
		for (int i = 0; i < size; i++)
		{
			if (i - n < 0)
			{
				nlist[i - n + size] = list[i];
			}
			else
			{
				nlist[i - n] = list[i];
			}
		}
	}
	else if (d == 1)
	{
		for (int i = 0; i < size; i++)
		{
			if (i + n > size - 1)
			{
				nlist[i + n - size] = list[i];
			}
			else
			{
				nlist[i + n] = list[i];
			}
		}
	}
	list = nlist;
}