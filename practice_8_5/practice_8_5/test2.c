#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//根据输入数字，输出对应直角边长的直角三角形
int main()
{
	//char arr[20][20] = { 0 };
	int i = 0;
	int j = 0;
	int input = 0;
	scanf("%d", &input);

	//for (i = 0; i < 20; i++)
	//{
	//	for (j = 0; j < 20; j++)
	//		arr[i][j] = ' ';
	//}

	for (i = 0; i < input; i++)
	{
		for (j = 0; j < input; j++)
		{
			//if (i + j >= 4)
			//	arr[i][j] = '*';
			if (i + j >= 4)
				printf("* ");
			else
				printf("  ");
		}

		printf("\n");
	}

	return 0;
}