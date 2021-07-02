#include<iostream>
#include<stdio.h>
using namespace std;
//ѭ����������
class ListNode
{
public:
	int data;  //�������
	ListNode* next;  //��һ������ָ��
	//���캯��
	ListNode()
	{
		next = NULL;
		data = 0;
	}
};
//ѭ��������
class LinkList
{
public:
	ListNode* head;  //ͷ���ָ��
	int len;  //ѭ��������
	LinkList();
	void LL_add(int x);  //��ѭ������β����������x
	ListNode* LL_index(int i);  //���Ҳ����ص�i������ָ��
	void LL_del(int i);  //ɾ����i�����
	void LL_display();  //��ӡ���ѭ���������н��
};
//���캯��
LinkList::LinkList()
{
	head = new ListNode();
	len = 0;
}
//��ѭ������β����������x
void LinkList::LL_add(int x)
{
	ListNode* l = new ListNode();
	l->data = x;
	l->next = head;
	if (head->next == NULL)
	{
		head->next = l;
	}
	else
	{
		LL_index(len)->next = l;
	}
	len++;
}
//���Ҳ����ص�i������ָ��
ListNode* LinkList::LL_index(int i)
{
	if (i > len)
	{
		i = i - len;
		ListNode* p;
		p = head;
		for (int k = 1; k <= i; k++)
		{
			p = p->next;
		}
		return p;
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
//ɾ����i�����
void LinkList::LL_del(int i)
{
	if ((i <= 0) || (i > len))
	{
		cout << "error" << endl;
	}
	else
	{
		if (i == 1)
		{
			head->next = LL_index(2);
		}
		else if (i == len)
		{
			LL_index(i - 1)->next = head;
		}
		else
		{
			LL_index(i - 1)->next = LL_index(i + 1);
		}
		len--;
	}
}
//��ӡ���ѭ���������н��
void LinkList::LL_display()
{
	ListNode* p;
	p = head;
	for (int i = 1; i <= len; i++)
	{
		p = p->next;
	}
	cout << endl;
}