#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//������̨�ף�ÿ����1�׻�2�ף�����n��̨�ף���һ���ж������߷�
int Step(int n)
{
	if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	else
		return Step(n - 1) + Step(n - 2);
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int num = Step(n);
	printf("%d\n", num);

	return 0;
}