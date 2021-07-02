#include<iostream>
using namespace std;
//˳������������
class Sequential_Index_Search
{
private:
	int n;    //������
	int k;    //�����ֳ��Ŀ���
	int* item;//����
	int* maxkey_index;//���ؼ���������
	int* StartPosition_index;//���ؼ�����ʼλ��������
public:
	//���캯��
	Sequential_Index_Search(int n1, int k1, int* item1, int* a)
	{
		n = n1;
		k = k1;
		item = item1;
		maxkey_index = a;
		StartPosition_index = new int[k];
		int p = 1;
		for (int i = 0; i < k; i++)
		{
			StartPosition_index[i] = p + i * (n / k);
		}
	}
	//˳����������
	int Search(int key)
	{
		for (int i = 0; i < k; i++)
		{
			if (maxkey_index[i] >= key)
			{
				int spi = StartPosition_index[i];
				for (int j = spi; j < spi + (n / k); j++)
				{
					if (item[j] == key)
						return j;
				}
				return 0;
			}
		}
		return 0;
	}
	//��������Ҵ�����˳����������
	void Search_times(int key)
	{
		for (int i = 0; i < k; i++)
		{
			if (maxkey_index[i] >= key)
			{
				int spi = StartPosition_index[i];
				for (int j = spi; j < spi + (n / k); j++)
				{
					if (item[j] == key)
					{
						//(j - spi + 1)��ʾ�ڿ��ڲ��ҵĴ���
						//(i + 1)��ʾ�ڿ����ҵĴ���
						cout << j << "-" << (j - spi + 1) + (i + 1) << endl;
						return;
					}
				}
				cout << "error" << endl;
				return;
			}
		}
		cout << "error" << endl;
	}
};