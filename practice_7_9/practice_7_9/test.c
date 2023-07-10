#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

//输入a和n
//计算Sn = a + aa + aaa + aaaa……的前n项
int SeriesSum(int number, int count)
{
	int sum = 0;
	int item = 0;
	int i = 0;
	int j = 0;

	//for (i = 1; i <= count; i++)
	//{
	//	item = 0;
	//	
	//	for (j = 0; j < i; j++)
	//	{
	//		item += number * ((int)pow(10, j));
	//	}

	//	sum += item;
	//}
	for (i = 0; i < count; i++)
	{
		item = item * 10 + number;
		sum += item;
	}

	return sum;
}

int main()
{
	int num = 0;
	int count = 0;
	int sum = 0;
	scanf("%d %d", &num, &count);
	sum = SeriesSum(num, count);
	printf("%d\n", sum);

	return 0;
}