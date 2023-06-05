#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//输入一个无符号整数，按顺序打印每一位
//递归实现
void print(unsigned int num)
{
	if (num > 9)			//当num为两位数以上时，执行该语句
	{
		print(num / 10);	//去掉最后一位数字
	}
	
	printf("%d ", num % 10);
}

int main()
{
	int number = 0;
	scanf("%d", &number);
	print(number);
	return 0;
}