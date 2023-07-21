#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//函数递归求斐波那契数列的第n项
int Fibonacci(int item)
{
	if ((item == 0) || (item == 1))
		return 1;
	else
		return Fibonacci(item - 1) + Fibonacci(item - 2);
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int fib = Fibonacci(n);
	printf("%d\n", fib);

	return 0;
}
