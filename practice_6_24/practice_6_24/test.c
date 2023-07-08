#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//交换两个整数，不创建临时变量
//^：按位异或操作符，二进制位相同为0，相异为1；
//a ^ a = 0，a ^ 0 = a，且异或操作符可使用交换律
int main()
{
	int a = 5;
	int b = 3;
	a = a ^ b;
	b = a ^ b; //此时b = a(原本的a，即5) ^ b ^ b, 而b ^ b = 0，5 ^ 0 = 5，因此，b = 5
	a = a ^ b; //此时a = a(原本的a，即5) ^ b ^ a(原本的a，即5)，同上可得，a = 3
	printf("%d %d", a, b);

	return 0;
}