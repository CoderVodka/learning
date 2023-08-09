#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//判断一个数列是否为有序数列
int JudgeSort(int* arr, int num)
{
	int i = 0;
	int flagUp = 0;
	int flagDown = 0;
	
	for (i = 0; i < num - 1; i++)
	{
		if (arr[i] < arr[i + 1])
			flagUp = 1;
		else if (arr[i] > arr[i + 1])
			flagDown = 1;

		if (flagDown + flagUp == 2)
			return 0;
	}

	return 1;
}

int main()
{
	int num = 0;
	scanf("%d", &num);
	int arr[50] = { 0 };
	int i = 0;

	for (i = 0; i < num; i++)
	{
		scanf("%d", &arr[i]);
	}

	int ret = JudgeSort(arr, num);

	if (1 == ret)
		printf("sort");
	else
		printf("unsort");

	return 0;
}