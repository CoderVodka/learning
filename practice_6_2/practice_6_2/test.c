#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//���������������Ӵ�С��˳�����
void swap(int* no1, int* no2)   //����д���������н����ĺ���������������ĺ��������Ը���
{
	int tmp = *no1;
	*no1 = *no2;
	*no2 = tmp;
}

int main()
{
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	scanf("%d %d %d", &num1, &num2, &num3);
	
	if (num1 < num2)
	{
		swap(&num1, &num2);
	}
	if (num1 < num3)
	{
		swap(&num1, &num3);
	}
	if (num2 < num3)
	{
		swap(&num2, &num3);
	}
	printf("%d %d %d", num1, num2, num3);

	return 0;
}