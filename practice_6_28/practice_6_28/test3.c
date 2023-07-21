#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

//���������ִ��м��ֳ��������֣�����1428��ֳɣ�1��428������14��28������142��8��
//������֮��ĳ˻�֮�͵���ԭ�������֣������ΪLily Number
//���5λ���е�����Lily Number
bool LilyNumber(const int number)
{
	int sum = 0;
	int n = 1;
	while (number / pow(10, n))
	{
		sum += (number / (int)pow(10, n)) * (number % (int)pow(10, n));
		n++;
	}

	if (number == sum)
		return true;
	else
		return false;
}

int main()
{
	int i = 0;

	for (i = 10000; i < 100000; i++)
	{
		if (LilyNumber(i))
			printf("%d ", i);
	}

	return 0;
}