#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//打印杨辉三角
//思路：将杨辉三角看作一个矩形，如下
// 1 - - - -
// 1 1 - - -
// 1 2 1 - - 
// 1 3 3 1 -
// 1 4 6 4 1
//左边和斜边是1，其他通过计算求得
int main()
{
	int row = 0;
	scanf("%d", &row);
	int pascalTri[20][20] = {0};
	int i = 0;
	int j = 0;
	int k = 0;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (0 == j || j == i)
				pascalTri[i][j] = 1;
			else
				pascalTri[i][j] = pascalTri[i - 1][j - 1] + pascalTri[i - 1][j];
		}
	}

	for (i = 0; i < row; i++)
	{
		for (k = 0; k < row - i - 1; k++)
			printf(" ");

		for (j = 0; j <= i; j++)
			printf("%d ", pascalTri[i][j]);

		printf("\n");
	}

	return 0;
}



//
//         1
//        1 1
//       1 2 1
//      1 3 3 1
//     1 4 6 4 1
//