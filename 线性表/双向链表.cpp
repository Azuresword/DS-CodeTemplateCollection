#include<iostream>
using namespace std;
//˫����������
class ListNode
{
public:
	ListNode* front;  //ǰһ������ָ��
	char data;  //�������
	ListNode* next;  //��һ������ָ��
	//���캯��
	ListNode()
	{
		front = this;
		next = this;
		data = 0;
	}
};
//˫��������
class LinkList
{
public:
	ListNode* head;  //ͷ���ָ��
	int len;  //˫��������
	LinkList();
	void LL_add(char x);  //��˫������ĩβ���һ�����
	ListNode* LL_index(int i);  //���ص�i�����
	void LL_insert(int i, char item);  //��item����˫������ĵ�i�����
	void LL_del(int i);  //ɾ��˫�������еĵ�i�����
	void LL_display();  //��ӡ���˫���������н��
};
//���캯��
LinkList::LinkList()
{
	head = new ListNode();
	len = 0;
}
//��˫������ĩβ���һ�����
void LinkList::LL_add(char x)
{
	ListNode* l = new ListNode();
	l->data = x;
	l->next = head;
	if (head->next == head)
	{
		l->front = head;
		head->next = l;
		head->front = l;
	}
	else
	{
		l->front = LL_index(len);
		LL_index(len)->next = l;
		head->front = l;
	}
	len++;
}
//���ص�i�����
ListNode* LinkList::LL_index(int i)
{
	if ((i <= 0) || (i > len))
	{
		cout << "index_error" << endl;
	}
	else
	{
		ListNode* p;
		p = head;
		for (int k = 1; k <= i; k++)
		{
			p = p->next;
		}
		return p;
	}
}
//��item����˫������ĵ�i�����
void LinkList::LL_insert(int i, char item)
{
	if (i == len)
	{
		LL_add(item);
	}
	else if (i == 1)
	{
		if (len == 0)
		{
			LL_add(item);
		}
		else
		{
			ListNode* l = new ListNode();
			l->data = item;
			l->front = head;
			l->next = LL_index(1);
			LL_index(1)->front = l;
			head->next = l;
			len++;
		}
	}
	else
	{
		ListNode* l = new ListNode();
		l->data = item;
		l->next = LL_index(i);
		LL_index(i)->front = l;
		LL_index(i - 1)->next = l;
		l->front = LL_index(i - 1);
		len++;
	}
}
//ɾ��˫�������еĵ�i�����
void LinkList::LL_del(int i)
{
	if ((i <= 0) || (i > len))
	{
		cout << "del_error" << endl;
	}
	else
	{
		if (i == 1)
		{
			if (len == 1)
			{
				head->next = head;
				head->front = head;
			}
			else
			{
				head->next = LL_index(2);
				LL_index(2)->front = head;
			}
		}
		else if (i == len)
		{
			LL_index(i - 1)->next = head;
			head->front = LL_index(i - 1);
		}
		else
		{
			LL_index(i - 1)->next = LL_index(i + 1);
			LL_index(i)->front = LL_index(i - 1);
		}
		len--;
	}
}
//��ӡ���˫���������н��
void LinkList::LL_display()
{
	ListNode* p;
	p = head;
	if (p->next == head)
	{
		cout << "-";
	}
	while (p->next != head)
	{
		p = p->next;
		cout << p->data;
	}
	cout << endl;
}