#include<iostream>
using namespace std;
//������
//���ȶ�����
class HeapSort
{
private:
	int* item;  //����ָ��
	int len;    //���鳤��
public:
	HeapSort(int n)
	{
		len = n;
		item = new int[len];
		for (int i = 0; i < len; i++)
		{
			cin >> item[i];
		}
	}
	void sort()
	{
		//����С�Ѷ�
		for (int i = len / 2 - 1; i >= 0; i--)
		{
			//�����һ����Ҷ�ӽ�㿪ʼ���������ϣ��������ҵ����ṹ
			adjustHeap(i, len);
		}
		display();
		//���Ѷ�Ԫ�غ�ĩβԪ�ؽ��н�����Ȼ�������¶Զѽ��е���
		for (int j = len - 1; j > 0; j--)
		{
			swap(0, j);      //���Ѷ�Ԫ�غ�ĩβԪ�ؽ��н���
			adjustHeap(0, j);  //���¶Զѽ��е���
			display();
		}
	}
	void adjustHeap(int i, int length)
	{
		int temp = item[i];  //��ȡ����ǰԪ��
		for (int k = i * 2 + 1; k < length; k = k * 2 + 1)
		{
			if (k + 1 < length && item[k] > item[k + 1])//��i�������ӽ�㿪ʼ��Ҳ����2i+1����ʼ
			{
				//����ҽ����ڣ�����������ҽ�㣬��ôkָ���ҽ��
				k++;
			}
			if (item[k] < temp)
			{
				//����ӽڵ�С�ڸ��ڵ㣬���ӽڵ�ֵ�������ڵ�
				item[i] = item[k];
				i = k;
			}
		}
		item[i] = temp;
	}
	void swap(int a, int b)
	{
		int m = item[a];
		item[a] = item[b];
		item[b] = m;
	}
	void display()
	{
		cout << len << " ";
		for (int i = 0; i < len; i++)
		{
			cout << item[i] << " ";
		}
		cout << endl;
	}
};