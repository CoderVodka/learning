#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>

int main()
{
	char arr1[] = "*************";
	char arr2[] = "Hellow World!";
	int left = 0;
	int right = strlen(arr2)-1;
	while(left <= right)
	{
		arr1[right] = arr2[right];
		arr1[left] = arr2[left];
		printf("%s\n", arr1);
		Sleep(1000);    //休息1000ms，需要头文件windows.h
		system("cls");  //清空屏幕，system是一个库函数，可以执行系统命令，需要头文件stdlib.h
		left++;
		right--;
	}

	return 0;
}