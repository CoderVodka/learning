#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void fun(int arr[])
{
	printf("%zu\n", sizeof(arr));
}

int main()
{
	int arr[10] = { 0 };
	printf("%zu\n", sizeof(arr));    //���40
	printf("%zu\n", sizeof(arr[0])); //���4
	fun(arr);                        //���8

	return 0;
}

//�����ڴ��ε�ʱ�򴫵ݵ�ʱ������Ԫ�صĵ�ַ��
//��void fun(int arr[])��arr[]��ָ�����