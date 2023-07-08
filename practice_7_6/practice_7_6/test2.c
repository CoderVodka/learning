#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//判断一个数是不是2的n次方
int main()
{
	int num = 0;
	scanf("%d", &num);

	if (num & (num - 1) == 0)
		printf("该数字是2的n次方");
	else
		printf("该数字不是2的n次方");

	return 0;
}