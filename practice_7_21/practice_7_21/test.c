#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//数组指针的使用

//void PrintArr(int arr[3][5], int row, int col)
//{
//	int i = 0;
//
//	for (i = 0; i < row; i++)
//	{
//		int j = 0;
//
//		for (j = 0; j < col; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//
//		printf("\n");
//	}
//}

//上述代码也可以写成另一种形式
void PrintArr(int (*parr)[5], int row, int col) //parr是指向一维数组的指针，
{                                               //而二维数组arr，其数组名既是指向首个一维数组，即二维数组的第0行，
	                                            //parr + i即指向第i行
	int i = 0;

	for (i = 0; i < row; i++)
	{
		int j = 0;

		for (j = 0; j < col; j++)
		{
			printf("%d ", *(*(parr + i) + j));
			//printf("%d ", parr[i][j]);    //也可直接写成这种形式
		}

		printf("\n");
	}
}

int main()
{
	int arr[3][5] = { 0,1,2,3,4,2,3,4,5,6,3,4,5,6,7 };
	PrintArr(arr, 3, 5);

	return 0;
}