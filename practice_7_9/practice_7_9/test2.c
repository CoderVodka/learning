#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

//求0~100000之间的自幂数
//自幂数指一个n位数，其各数字的n次方之和等于该数字本身，e.g.153 = 1^3 + 5^3 + 3^3
int SelfPower(const int num)
{
	int sum = 0;
	int quotient = num;
	int placeNum[10] = { 0 };
	int place = 0;
	int i = 0;

	while (quotient)
	{
		placeNum[i++] = quotient % 10;
		quotient /= 10;
		place++;
	}

	int j = 0;

	for (j = 0; j < place; j++)
	{
		sum += pow(placeNum[j], place);
	}

	return num == sum;
	//return 1;
}

int main()
{
	int i = 0;
	for (i = 0; i <= 100000; i++)
	{
		if (SelfPower(i))
			printf("%d ", i);
	}

	return 0;
}