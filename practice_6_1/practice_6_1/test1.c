#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//编写一个函数，求字符串长度
//int getLength(char *str)
//{
//	int count = 0;
//
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//
//	return count;
//}

//编写一个函数，求字符串长度,不能使用临时变量
int getLength(char* str)
{
	if (*str != '\0')
	{
		return 1 + getLength(str + 1);  //这里不使用++str，保证str的值不改变
	};

	return 0;
}

int main()
{
	char ch[30];
	scanf("%s", ch);
	int len = getLength(ch);
	printf("%d", len);

	return 0;
}