#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//ð������
void bubbleSort(int arr[], int size)
{
	int i = 0;
	
	//ð���������ִ���
	for (i = 0; i < (size - 1); i++)
	{
		int j = 0;

		//һ������
		for (j = 0; j < (size - 1 - i); j++)
		{
			//һ�ν���
			if (arr[j] < arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
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