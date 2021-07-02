#include<iostream>
#include<cmath>
using namespace std;
//2·�鲢���򣬵ݹ�����
//�ȶ�����
class MergeSort
{
private:
	int* item;  //��Ҫ���������
	int* temp;  //��ʱ����
	int* item1;  //�ϲ�������ʹ�õ���ʱ����
	int len;  //��Ҫ��������鳤��
	int k;
	int p;  //2·�鲢�������
	//2·�鲢������
	void sort(int left, int right)
	{
		if (left < right)
		{
			int mid = (left + right) / 2;
			sort(left, mid);//��߹鲢����ʹ��������������
			sort(mid + 1, right);//�ұ߹鲢����ʹ��������������
			merge(left, mid, right);
		}
		p++;
	}
	//�鲢����
	void merge(int left, int mid, int right)
	{
		int i = left;//������ָ��
		int j = mid + 1;//������ָ��
		int t = 0;//��ʱ����ָ��
		while (i <= mid && j <= right)
		{
			if (item[i] < item[j])
			{
				temp[t] = item[i];
				t++;
				i++;
			}
			else
			{
				temp[t] = item[j];
				t++;
				j++;
			}
		}
		while (i <= mid)
		{
			//����������ʣ��Ԫ������temp��
			temp[t] = item[i];
			t++;
			i++;
		}
		while (j <= right)
		{
			//����������ʣ��Ԫ������temp��
			temp[t] = item[j];
			t++;
			j++;
		}
		//��temp�е�Ԫ��ȫ��������ԭ������
		t = 0;
		while (left <= right)
		{
			item[left] = temp[t];
			t++;
			left++;
		}
	}
	//�ж�a�Ƿ�Ϊ����
	bool IsInteger(double a)
	{
		if (a - (int)a == 0)
			return true;
		else
			return false;
	}
	//ѡ��������
	void SelectSort(int* arr, int n)
	{
		int min;
		for (int i = 0; i < n; i++)
		{
			min = i;
			for (int k = i + 1; k < n; k++)
			{
				if (arr[k] < arr[min])
				{
					min = k;
				}
			}

			int m = arr[i];
			arr[i] = arr[min];
			arr[min] = m;
		}
	}
public:
	//�ϲ�����
	MergeSort(int* str, int n)
	{
		p = 0;
		item = str;
		len = n;
		item1 = new int[len];
		for (int i = 0; i < len; i++)
		{
			item1[i] = str[i];
		}
		temp = new int[len];
		if (IsInteger(log2(len)))
			k = (int)log2(len) + 1;
		else
			k = (int)log2(len) + 2;
		sort(0, len - 1);
		cout << p << endl;
	}
	void display()
	{
		for (int i = 0; i < len; i++)
		{
			cout << item[i] << " ";
		}
		cout << endl;
	}
};