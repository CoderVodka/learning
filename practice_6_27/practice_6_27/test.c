#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//输入一个整数序列，删除指定的某一个整数，输出删除指定整数之后的序列，其他数字的顺序不发生变化
int main()
{
	int arr[50];
	int count = 0;
	int num = 0;
	int i = 0;
	int j = 0;
	scanf("%d", &count);
	
	for (i = 0; i < count; i++)
	{
		scanf("%d", &arr[i]);
	}

	scanf("%d", &num);
	//int x = 0;
	//int y = 0;
	//
	//for (x = 0; x < count; x++)
	//{
	//	if (arr[x] == num)
	//	{
	//		break;
	//	}
	//}
	//
	//for (y = x; y < list - 1; y++)
	//{
	//	arr[y] = arr[y + 1];
	//}
	//	
	//for (y = 0; y < count - 1; y++)
	//{
	//	printf("%d ", arr[y]);
	//}

	//上述代码存在问题，当序列中有多个需要删除的数字时只会删除一个
	for (i = 0; i < count; i++)
	{
		if (arr[i] != num)
		{
			arr[j] = arr[i];
			j++;
		}
	}

	for (i = 0; i < j; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}