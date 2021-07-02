#include<iostream>
using namespace std;
//�۰���Һ���
//���ҳɹ��򷵻�Ԫ���������е�λ��
//����ʧ���򷵻�0
int Binary_Search(int* item, int n, int key)
{
	int low = 1;
	int high = n;
	int mid = (n + 1) / 2;
	while (low <= high)
	{
		if (key < item[mid])
		{
			high = mid - 1;
			mid = (low + high) / 2;
		}
		else if (key > item[mid])
		{
			low = mid + 1;
			mid = (low + high) / 2;
		}
		else if (key == item[mid])
		{
			return mid;
		}
	}
	return 0;
}