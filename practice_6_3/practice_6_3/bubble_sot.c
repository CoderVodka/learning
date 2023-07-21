#define  _CRT_SECURE_NO_WARNINGS

#include "bubble_sort.h"



int CompareInt(const void* num1, const void* num2)
{
	return (*(int*)num1 - *(int*)num2);
}

void Swap(char* elem1, char* elem2, int width)
{
	int i = 1;

	for (i = 1; i <= width; i++)
	{
		char tmp = *elem1;
		*elem1 = *elem2;
		*elem2 = tmp;
		elem1++;
		elem2++;
	}
}

void BubbleSort(void* base, int num, int width,
	int (*compare)(const void* elem1, const void* elem2))
{
	int i = 0;

	//ð���������ִ���
	for (i = 0; i < (num - 1); i++)
	{
		int j = 0;
		int flag = 1;  //����һ���жϣ���һ������û�н��н���ʱ��˵�����������ֱ�ӽ���

		//һ������
		for (j = 0; j < (num - 1 - i); j++)
		{
			//�Ƚ�
			if (compare((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				//һ�ν���
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
				flag = 0;
			}
		}

		if (flag == 1) //flag != 0˵��û�н��й�����
			break;
	}
}