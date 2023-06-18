#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//写一个递归函数DigitSum(n)，输入一个非负整数，输出它各位数字之和
int DigitSum(unsigned int n)
{
	if (n > 10)
		return n % 10 + DigitSum(n / 10);
	else
		return n;
}

int main()
{
	unsigned int num = 0;
	scanf("%d", &num);
	int sum = DigitSum(num);
	printf("%d\n", sum);

	return 0;
}