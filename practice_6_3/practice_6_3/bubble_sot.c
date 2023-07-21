#define  _CRT_SECURE_NO_WARNINGS

#include "bubble_sort.h"



int CompareInt(const void* num1, const void* num2)
{
	return (*(int*)num1 - *(int*)num2);
}

void Swap(char* elem1, char* elem2, int width)
{
	int i = 1;

	for (i = 1; i <= width; i++)
	{
		char tmp = *elem1;
		*elem1 = *elem2;
		*elem2 = tmp;
		elem1++;
		elem2++;
	}
}

void BubbleSort(void* base, int num, int width,
	int (*compare)(const void* elem1, const void* elem2))
{
	int i = 0;

	//冒泡排序总轮次数
	for (i = 0; i < (num - 1); i++)
	{
		int j = 0;
		int flag = 1;  //增加一个判断，当一轮排序没有进行交换时，说明已完成排序，直接结束

		//一轮排序
		for (j = 0; j < (num - 1 - i); j++)
		{
			//比较
			if (compare((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				//一次交换
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
				flag = 0;
			}
		}

		if (flag == 1) //flag != 0说明没有进行过交换
			break;
	}
}