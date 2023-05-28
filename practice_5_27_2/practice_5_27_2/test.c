#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//在一个有序数组中查找某个数字n，本代码使用二分法
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = 0;
	int mid = 0;      //中点的下标
	int size = sizeof(arr) / sizeof(arr[0]);
	int left = 0;     //左边界
	int right = size - 1; //右边界
	scanf("%d", &n);

	do
	{
		mid = (left + right) / 2; //设置中点
		/*if ((arr[mid] != n) && (left == right))    //此处跳出循环的判断可能出现问题，
		{                                            // 在移动下标时可能出现left>right的情况，
			printf("未找到\n");                      //这种情况下无法跳出循环，从而出现死循环的情况
			break;
		}
		else*/ 
		if (arr[mid] > n)         //中点值大于所求值
		{
			right = mid - 1;      //将右边界移至中点处
		}
		else if (arr[mid] < n)
		{
			left = mid + 1;
		}
		else
		{
			printf("下标为：%d", mid);
			break;
		}
	} while (left <= right);
	//while (arr[mid] != n);    //不使用这种方法判断是否结束循环，理由同前， 防止死循环

	if (left > right)
	{
		printf("未找到\n");
	}
	return 0;
}