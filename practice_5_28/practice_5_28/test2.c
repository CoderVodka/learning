#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void fun(int arr[])
{
	printf("%zu\n", sizeof(arr));
}

int main()
{
	int arr[10] = { 0 };
	printf("%zu\n", sizeof(arr));    //输出40
	printf("%zu\n", sizeof(arr[0])); //输出4
	fun(arr);                        //输出8

	return 0;
}

//数组在传参的时候传递的时数组首元素的地址，
//即void fun(int arr[])中arr[]是指针变量