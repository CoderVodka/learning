#define  _CRT_SECURE_NO_WARNINGS

#include "bubble_sort.h"

//之前写的冒泡排序只能对整型数组进行排序，
//参考C语言的库函数qsort设计一个同样适用于各种数组排序的函数
//void qsort(void *base,      //要排序的数据的起始位置
//           size_t num,      //要排序的数据的数量
//           size_t width,    //要排序的数据的元素大小（字节）
//           int (*compare)(const void *elem1, const void *elem2)  //函数指针，指向比较函数
//           );
//通过函数指针的方式，只要创建对应的比较函数，并将该函数传入排序函数即可实现对不同类型数据进行排序的功能
int main()
{
	int arr[] = { 10,2,13,54,-5,-6,7,28,9,0 };
	int arrSize = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	BubbleSort(arr, arrSize, sizeof(arr[0]), CompareInt);

	for (i = 0; i < arrSize; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}