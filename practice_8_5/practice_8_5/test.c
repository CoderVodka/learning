#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
//�޸��������ֵ�ÿһλ��ż����Ϊ0��������Ϊ1
int SetNum(int* pnum)
{
	int digi = 0;
	int num = *pnum;
	int sum = 0;
	int count = 0;
	
	do
	{
		digi = num % 10;

		if (digi % 2 != 0)
			sum += 1 * (int)pow(10, count++);
		else
			count++;

		num /= 10;
		
	} while (num);

	*pnum = sum;

	return sum;
}

int main()
{
	int input = 0;
	scanf("%d", &input);
	SetNum(&input);
	printf("%d\n", input);

	return 0;
}