#include<iostream>
using namespace std;
//ֱ�Ӳ�������
//�ȶ�����
void StraightInsertSort(int* item, int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int k = i; k > 0; k--)
		{
			if (item[k] <= item[k - 1])
			{
				int m = item[k];
				item[k] = item[k - 1];
				item[k - 1] = m;
			}
			else
				break;
		}

		//ÿ����������һ�ν��
		for (int i = 0; i < n; i++)
		{
			cout << item[i] << " ";
		}
		cout << endl;
	}
}