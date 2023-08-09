#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <assert.h>

//编写一个函数，左旋字符串中的k个字符
// e.g. ABCD左旋1个 -> BCDA
//          左旋2个 -> CDAB
// 每次旋转一个字符，当k大于字符串长度时，重复之前的操作
// e.g. ABCD左旋6个 -> CDAB
//          左旋5个 -> BCDA
//方法1
//void LeftRevolve(char* string, int num)
//{
//  int length = strlen(string);
//  num %= length;
// 
//	while (num--)
//	{
//		char* pfirst = string;
//		char first = *string;
//
//		while (*string)
//		{
//			*string = *(string + 1);
//			string++;
//		}
//
//		*(string - 1) = first;
//		string = pfirst;
//	}
//}

//方法2
//将字符串分为左右两部分，左侧字符串长度为k，
//分别逆序这两部分，再整体逆序，即可实现 
//e.g.ABCD左旋2个字符，AB|CD -> 分别逆序 -> BA|DC -> 整体逆序 -> CDAB
void Invert(char* start, char* end)
{
	assert(start && end);

	while (start < end)
	{
		char tmp = *start;
		*start = *end;
		*end = tmp;
		end--;
		start++;
	}
}

void LeftRevolve(char* string, int num)
{
	int length = strlen(string);
	num %= length;                           //防止越界

	Invert(string, string + num - 1);
	Invert(string + num, string + length - 1);
	Invert(string, string + length - 1);
}

int main()
{
	int num = 0;
	char str[10];
	scanf("%d,%s", &num, str);
	LeftRevolve(str, num);
	printf("%s\n", str);

	return 0;
}