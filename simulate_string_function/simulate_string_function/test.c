#define  _CRT_SECURE_NO_WARNINGS

//模拟实现字符串相关的函数
#include "String.h"
#include <string.h>

int main()
{
	char arr1[20] = "abbcde";
	char arr2[20] = "bbce";
	//StringNumCopy(arr1, arr2, 10);
	//StringNumCat(arr1, arr2, 5);
	//printf("%s\n", arr1);

	//int ret = StringNumCompare(arr1, arr2, 7);
	//printf("%d\n", ret);

	char* pdest = StringString(arr1, arr2);
	int result = pdest - arr1 + 1;
	if (pdest)
		printf("字符串%s首元素在%d处", arr2, result);
	else
		printf("未找到");

	return 0;
}