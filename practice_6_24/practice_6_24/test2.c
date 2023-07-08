#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//计算一个整数的二进制数中1的个数
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
