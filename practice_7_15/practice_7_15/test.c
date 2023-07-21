#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//写一个函数，调整一个整数数组，使奇数位于数组前半部分，偶数位于数组后半部分
void SeparateOddEven(int* arr, int size)
{
	int* left = arr;
	int* right = arr + size - 1;

	while (left < right)
	{
		//从前向后找偶数
		while ((left < right) && (*left % 2 == 1))  //while (*left % 2 == 1)			
		{                                           //此处不能写成这样，因为当全是奇数时会产生越界
			left++;
		}

		//从后向前找奇数
		while ((left < right) && (*right % 2 == 0))  //while (*right % 2 == 0) 同上
		{
			right--;
		}

		//交换
		if (left < right)
		{
			int tmp = *left;
			*left = *right;
			*right = tmp;
			left++;
			right--;
		}
	}
}


int main()
{
	int arr[10] = { 1,3,5,7,9,11,13,15,17,19 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	SeparateOddEven(arr, sz);
	int i = 0;

	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}