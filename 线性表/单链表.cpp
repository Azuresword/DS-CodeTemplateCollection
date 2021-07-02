#include<stdio.h>
#include<iostream>
using namespace std;
//���Ե���������
class ListNode
{
public:
	int data;   //�������
	ListNode* next;    //��һ�����ָ��
	//���캯��
	ListNode()
	{
		next = NULL;
		data = 0;
	}
};
//���Ե�������
class LinkList
{
public:
	ListNode* head;    //ͷ���ָ��
	int len;           //������
	LinkList();        //���캯��
	~LinkList();       //��������
	void LL_add(int x);//����������������x
	ListNode* LL_index(int i);   //���Ҳ����ص�i������ָ��
	void LL_get(int i);//��ӡ�����i����������
	void LL_insert(int i, int item);//�ڰ�����item���뵽����ĵ�i����㴦
	void LL_del(int i);//ɾ����i�����
	void LL_display();//��ӡ������������н��
	void swap(int pa, int pb);//��㽻������
	void sort();  //������������
	LinkList LL_merge(LinkList& La, LinkList& Lb);//�ϲ���������������һ������������
};
//���캯��
LinkList::LinkList()
{
	head = new ListNode();
	len = 0;
}
//��������
LinkList::~LinkList()
{
	head = NULL;
}
//����������������x
void LinkList::LL_add(int x)
{
	ListNode* l = new ListNode();
	l->data = x;
	if (head->next == NULL)
	{
		head->next = l;
	}
	else
	{
		ListNode* p;
		p = head;
		for (int k = 1; k <= len; k++)
		{
			p = p->next;
		}
		p->next = l;
	}
	len++;
}
//���Ҳ����ص�i������ָ��
ListNode* LinkList::LL_index(int i)
{
	if ((i <= 0) || (i > len))
	{
		cout << "error" << endl;
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
//��ӡ�����i����������
void LinkList::LL_get(int i)
{
	if ((i <= 0) || (i > len))
	{
		cout << "error" << endl;
	}
	else
	{
		int x;
		x = LL_index(i)->data;
		cout << x << endl;
	}
}
//�ڰ�����item���뵽����ĵ�i����㴦
void LinkList::LL_insert(int i, int item)
{
	if ((i <= 0) || (i > len + 1))
	{
		cout << "error" << endl;
	}
	else
	{
		ListNode* l = new ListNode();
		l->data = item;
		l->next = LL_index(i);
		LL_index(i - 1)->next = l;
		len++;
		LL_display();
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
			LL_index(i-1)->next = NULL;
		}
		else
		{
			LL_index(i-1)->next = LL_index(i+1);
		}
		len--;
		LL_display();
	}
}
//��ӡ������������н��
void LinkList::LL_display()
{
	ListNode* p;
	p = head;
	while (p->next != NULL)
	{
		p = p->next;
		cout << p->data << " ";
	}
	cout << endl;
}
//��㽻������
void LinkList::swap(int pa, int pb)
{
	if ((pa != pb) && (pa > 0) && (pa <= len) && (pb > 0) && (pb <= len))
	{
		ListNode* p;
		p = LL_index(pa);

		ListNode* q;
		q = LL_index(pb);

		ListNode* p_before;
		if (pa == 1)
		{
			p_before = head;
		}
		else
		{
			p_before = LL_index(pa - 1);
		}

		ListNode* p_after;
		if (pa == len)
		{
			p_after = NULL;
		}
		else
		{
			p_after = LL_index(pa + 1);
		}

		ListNode* q_before;
		if (pb == 1)
		{
			q_before = head;
		}
		else
		{
			q_before = LL_index(pb - 1);
		}

		ListNode* q_after;
		if (pb == len)
		{
			q_after = NULL;
		}
		else
		{
			q_after = LL_index(pa + 1);
		}

		p_before->next = q;
		q->next = p_after;

		q_before->next = p;
		p->next = q_after;
		LL_display();
	}
	else
	{
		cout << "error" << endl;
	}
}
//������������
void LinkList::sort()
{
	for (int i = 1; i <= len; i++)
	{
		for (int k = i; k <= len; k++)
		{
			if (LL_index(i)->data > LL_index(k)->data)
			{
				swap(i, k);
			}
		}
	}
}
//�ϲ���������������һ������������
LinkList LinkList::LL_merge(LinkList& La, LinkList& Lb)
{
	LinkList L;

	ListNode* p;
	p = La.head;
	for (int i = 1; i <= La.len; i++)
	{
		p = p->next;
		L.LL_insert(i, p->data);
	}

	p = Lb.head;
	for (int i = 1; i <= Lb.len; i++)
	{
		p = p->next;
		L.LL_insert(i, p->data);
	}
	//cout << L.len << endl;
	//L.LL_display();
	for (int i = 1; i <= L.len; i++)
	{
		for (int k = i; k <= L.len; k++)
		{
			//cout << "i=" << i << endl;
			//cout << "k=" << k << endl;
			if (L.LL_index(i)->data > L.LL_index(k)->data)
			{
				L.swap(i, k);
				//L.LL_display();
			}
		}
	}
	return L;
}