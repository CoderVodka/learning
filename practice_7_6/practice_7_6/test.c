#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//写一个函数，返回参数二进制中1的个数
//方法一
//int Count_1(int number)
//{
//	int count = 0;
//	int i = 0;
//
//	for (i = 0; i < 8 * sizeof(int); i++)
//	{
//		if ((number & 1) == 1)
//			count++;
//		number >>= 1;
//	}
//
//	return count;
//}

//方法2
//int Count_1(int number)
//上面这行代码在number为负数时不能返回正确数值，因为负数在内存中以补码形式存储，应将参数类型改为无符号整数
//int Count_1(unsigned int number)
//{
//	int sum = 0;
//	int i = 0;
//	
//	while (number)
//	{
//		//思路类似于分别取出十进制数字的每一位
//		//number / 2即为将二进制最后一位舍弃
//		//当number为奇数时，二进制数最后一位为1，number % 2 = 1既是取出这一位1。
//		sum += number % 2;
//		number /= 2;
//	}
//
//	return sum;
//}

//方法3
int Count_1(int number)
{
	int count = 0;

	while (number)
	{
		//这一步运算将number最右边的1变为0
		//e.g. number = 1110
		// number - 1 = 1101
		// 1110 & 1101 = 1100
		// 这种方法可以大幅度减少循环次数
		number = number & (number - 1);
		count++;
	}
	
	return count;
}

int main()
{
	int num = 0;
	scanf("%d", &num);
	printf("%d\n", Count_1(num));

	return 0;
}