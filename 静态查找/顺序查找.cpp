#include<iostream>
using namespace std;
//���ڱ���˳����Һ���
//���ҳɹ��򷵻�Ԫ���������е�λ��
//����ʧ���򷵻�0
int Sequential_Search(int* item, int n, int key)
{
	int i = n;
	item[0] = key;

	while (item[i] != key)
		i--;

	return i;
}