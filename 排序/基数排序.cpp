#include<iostream>
using namespace std;
//��������
//�ȶ�����
class RadixSort
{
private:
	int* data;  //��Ҫ���������
	int len;  //��Ҫ��������鳤��
	//�����ݵ����λ��
	int maxbit()
	{
		int maxData = data[0];
		for (int i = 1; i < len; i++)
		{
			if (maxData < data[i])
				maxData = data[i];
		}
		int d = 1;
		while (maxData >= 10)
		{
			maxData /= 10;
			d++;
		}
		return d;
	}
	void Sort()
	{
		int d = maxbit();
		int* temp = new int[len];
		int* count = new int[10];//������
		int** arr = new int* [10];
		int radix = 1;
		int j, k, h;
		for (int i = 1; i <= d; i++)
		{
			for (j = 0; j < 10; j++)
				count[j] = 0;//ÿ�η���ǰ��ռ�����

			for (j = 0; j < 10; j++)
			{
				arr[j] = NULL;
			}

			for (j = 0; j < len; j++)
			{
				k = (data[j] / radix) % 10;   //ͳ��ÿ��Ͱ�еļ�¼��
				if (arr[k] == NULL)
					arr[k] = new int[len];
				arr[k][count[k]] = data[j];
				count[k]++;
			}

			for (j = 0; j < 10; j++)
			{
				cout << j << ":";
				if (arr[j] == NULL)
					cout << "NULL" << endl;
				else
				{
					cout << "->";
					for (h = 0; h < count[j]; h++)
						cout << arr[j][h] << "->";
					cout << "^" << endl;
				}
			}

			for (j = 1; j < 10; j++)
				count[j] = count[j - 1] + count[j];
			for (j = len - 1; j >= 0; j--)
			{
				k = (data[j] / radix) % 10;
				temp[count[k] - 1] = data[j];
				count[k]--;
			}
			for (j = 0; j < len; j++)
				data[j] = temp[j];
			radix *= 10;
			display();
		}
		delete[]temp;
		delete[]count;
	}
public:
	//���캯��
	RadixSort(int* item, int n)
	{
		data = item;
		len = n;
		Sort();
	}
	void display()
	{
		for (int i = 0; i < len; i++)
		{
			cout << data[i] << " ";
		}
		cout << endl;
	}
};