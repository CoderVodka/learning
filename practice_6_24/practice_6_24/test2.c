#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//����һ�������Ķ���������1�ĸ���
int main()
{
	int a = 5;  //101
	int count = 0;
	int i = 0;

	for (i = 0; i < 32; i++)
	{
		count += a & 1;
		a >>= 1;
	}
	printf("%d\n", count);

	return 0;
}
