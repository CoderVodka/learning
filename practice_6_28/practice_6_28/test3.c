#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//把任意数字从中间拆分成两个数字，例如1428拆分成（1，428），（14，28），（142，8）
//如果拆分之后的乘积之和等于原本的数字，则称其为Lily Number
//输出5位数中的所有Lily Number
int main()
{
	int i = 10000;

	for (i = 10000; i < 100000; i++)
	{
		if (i == (i / 10000) * (i % 10000)
			+ (i / 1000) * (i % 1000)
			+ (i / 100) * (i % 100)
			+ (i / 10) * (i % 10))
			printf("%d ", i);
	}

	return 0;
}