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
		Sleep(1000);    //��Ϣ1000ms����Ҫͷ�ļ�windows.h
		system("cls");  //�����Ļ��system��һ���⺯��������ִ��ϵͳ�����Ҫͷ�ļ�stdlib.h
		left++;
		right--;
	}

	return 0;
}