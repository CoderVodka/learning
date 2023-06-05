#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

//用函数实现判断一个数是否是素数，并输出100-200之间的所有素数及其个数
//int Prime(int num) 
//{
//	int j = 0;
//	for (j = 2; j <= sqrt(num); j++)   //一个数的一对因数中必定有一个小于该数的算数平方根
//	{                                  //即m = a x b中， a或b必有一个小于m的算术平方根
//		if ((num % j) == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 101; i <= 200; i += 2)
//	{
//		if (Prime(i))
//		{
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\ncount = %d\n", count);
//
//	return 0;
//}

//写一个函数判断是不是闰年
//打印1000--2000年之间的闰年

int leap_year(int year)
{
	if (((year % 4) == 0 && (year % 100)) || ((year % 400) == 0))
		return 1;
	else
		return 0;
}

int main()
{
	int i = 0;
	for (i = 1000; i <= 2000; i++)
	{
		if (leap_year(i))
			printf("%d ", i);
	}

	return 0;
}