#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//дһ������������һ���������飬ʹ����λ������ǰ�벿�֣�ż��λ�������벿��
void SeparateOddEven(int* arr, int size)
{
	int* left = arr;
	int* right = arr + size - 1;

	while (left < right)
	{
		//��ǰ�����ż��
		while ((left < right) && (*left % 2 == 1))  //while (*left % 2 == 1)			
		{                                           //�˴�����д����������Ϊ��ȫ������ʱ�����Խ��
			left++;
		}

		//�Ӻ���ǰ������
		while ((left < right) && (*right % 2 == 0))  //while (*right % 2 == 0) ͬ��
		{
			right--;
		}

		//����
		if (left < right)
		{
			int tmp = *left;
			*left = *right;
			*right = tmp;
			left++;
			right--;
		}
	}
}


int main()
{
	int arr[10] = { 1,3,5,7,9,11,13,15,17,19 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	SeparateOddEven(arr, sz);
	int i = 0;

	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}