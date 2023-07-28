#define  _CRT_SECURE_NO_WARNINGS

//模拟实现字符串相关的函数
#include "String.h"
#include <string.h>

int main()
{
	char arr1[20] = "abcde";
	char arr2[20] = "abcde";
	//StringNumCopy(arr1, arr2, 10);
	//StringNumCat(arr1, arr2, 5);
	//printf("%s\n", arr1);

	int ret = StringNumCompare(arr1, arr2, 7);
	printf("%d\n", ret);

	return 0;
}