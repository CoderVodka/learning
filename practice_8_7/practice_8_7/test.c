#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// 杨氏矩阵
// 有一个数字矩阵，矩阵每行从左到右递增，从上到下递增，
// 请编写一个程序，查找矩阵中是否存在某个数字
// 要求：时间复杂度小于O(N)（即不能遍历矩阵）
// 分析：这种矩阵的左下和右上角两个位置的值较为特殊，
// 左下为该列最大值及该行最小值，右上为该行最大值及该列最小值
// 通过与这两个值比较，可以快速排除一行元素
//int SearchYoungTableau(const void* arr, int row, int col, int num)
//{
//
//	const int* pLL = (int*)arr + (col * (row - 1));
//	const int* pUR = (int*)arr + col - 1;
//	int flag = 0;
//
//	while ((pLL >= (int*)arr) && (pLL <= (int*)arr + col * row - 1)  //超过数组边界结束循环
//		&& (pUR >= (int*)arr) && (pUR <= (int*)arr + col * row - 1)
//		&& ((pLL - (int*)arr) / col >= (pUR - (int*)arr) / col)  //pLL在pUR上方结束
//		&& ((pUR - (int*)arr) % col >= (pLL - (int*)arr) % col)) //pUR在pLL左侧结束
//	{
//		//判断左下角与目标数字的大小
//		if (*pLL > num)       //左下角数字大，向上移动一行
//			pLL -= col;
//		else if (*pLL < num)  //左下角数字小，向右移动一行
//			pLL++;
//		else
//		{
//			flag = 1;
//			break;
//		}
//
//		//判断右上角与目标数字大小
//		if (*pUR > num)       //右上角数字大，向左移动一行
//			pUR--;
//		else if (*pUR < num)  //右上角数字小，向下移动一行
//			pUR += col;
//		else
//		{
//			flag = 1;
//			break;
//		}
//	}
//
//	return flag;
//}

//简化
//注意：从两边找和从一边找的速度是一样的
int SearchYoungTableau(const void* arr, int row, int col, int num)
{
	const int* pUR = (int*)arr + col - 1;
	int flag = 0;

	while ((pUR >= (int*)arr) && (pUR <= (int*)arr + col * row - 1)) 
	{
		//判断右上角与目标数字大小
		if (*pUR > num)       //右上角数字大，向左移动一行
		{
			if ((pUR - arr) % col)
				pUR--;
			else              //当到达最左侧一列时，若*pUR > num，说明没找到，跳出循环
				break;
		}
		else if (*pUR < num)  //右上角数字小，向下移动一行
			pUR += col;
		else
		{
			flag = 1;
			break;
		}
	}

	return flag;
}

//关于返回值的问题，如果想返回找到数字的坐标，可以使用以下四种方法：
// 1.创建一个结构体，储存坐标的x、y值
// 2.将参数row、col改成指针，并在找到目标时将其改成目标位置x、y值
// 3.返回(pUR - arr)表示在数组的第几个数，之后可以通过计算得到坐标值
// 4.返回指针pUR，之后也可以通过计算得到坐标

int main()
{
	int arr[4][3] = { 1,3,5,2,4,6,8,10,11,9,13,16 };
	int num = 0;
	scanf("%d", &num);
	int ret = SearchYoungTableau(arr, 4, 3, num);
	if (ret)
		printf("找到了\n");
	else
		printf("没找到\n");

	return 0;
}