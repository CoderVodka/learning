#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//����ָ���ʹ��

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

//��������Ҳ����д����һ����ʽ
void PrintArr(int (*parr)[5], int row, int col) //parr��ָ��һά�����ָ�룬
{                                               //����ά����arr��������������ָ���׸�һά���飬����ά����ĵ�0�У�
	                                            //parr + i��ָ���i��
	int i = 0;

	for (i = 0; i < row; i++)
	{
		int j = 0;

		for (j = 0; j < col; j++)
		{
			printf("%d ", *(*(parr + i) + j));
			//printf("%d ", parr[i][j]);    //Ҳ��ֱ��д��������ʽ
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