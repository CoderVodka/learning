#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//дһ���ݹ麯��DigitSum(n)������һ���Ǹ��������������λ����֮��
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