#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

//�ú���ʵ���ж�һ�����Ƿ��������������100-200֮������������������
//int Prime(int num) 
//{
//	int j = 0;
//	for (j = 2; j <= sqrt(num); j++)   //һ������һ�������бض���һ��С�ڸ���������ƽ����
//	{                                  //��m = a x b�У� a��b����һ��С��m������ƽ����
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

//дһ�������ж��ǲ�������
//��ӡ1000--2000��֮�������

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