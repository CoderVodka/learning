#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//冒泡排序
void bubbleSort(int arr[], int size)
{
	int i = 0;
	
	//冒泡排序总轮次数
	for (i = 0; i < (size - 1); i++)
	{
		int j = 0;
		int flag = 1;  //增加一个判断，当一轮排序没有进行交换时，说明已完成排序，直接结束

		//一轮排序
		for (j = 0; j < (size - 1 - i); j++)
		{
			//一次交换
			if (arr[j] < arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;
			}
		}

		if (flag == 1) //flag != 0说明没有进行过交换
			break;
	}
}

int main()
{
	int arr[] = { 10,2,13,54,-5,-6,7,28,9,0 };
	int arrSize = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	bubbleSort(arr, arrSize);
	
	for (i = 0; i < arrSize; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}