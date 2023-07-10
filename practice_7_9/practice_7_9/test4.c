#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

//求最大公因数
int CommonFactor(int num1, int num2)
{
	int count = 0;
	int max = 0;
	int min = 0;
	int factor = 0;

	while ((num1 % 2 == 0) && (num2 % 2 == 0))
	{
			num1 /= 2;
			num2 /= 2;
			count++;
	}
	max = num1 > num2 ? num1 : num2;
	min = num1 <= num2 ? num1 : num2;

	while (max > min)
	{
		int tmp = max - min;
		max = tmp > min ? tmp : min;
		min = tmp <= min ? tmp : min;
	}

	factor = pow(2, count) * min;

	return factor;
}

//求最小公倍数
int CommonMultiple(int num1, int num2)
{
	int mul = 0;
	if (((num1 % num2) == 0) || ((num2 % num1) == 0))
		mul = num1 > num2 ? num1 : num2;
	else
	{
		int factor = CommonFactor(num1, num2);
		mul = num1 * num2 / factor;
	}

	return mul;
}

int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int factor = CommonFactor(a, b);
	int multiple = CommonMultiple(a, b);
	printf("%d\n", factor);
	printf("%d\n", multiple);

	return 0;
}