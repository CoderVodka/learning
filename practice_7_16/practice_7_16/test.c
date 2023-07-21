#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//�������������кϲ���һ����������
void CombineArr(int* targetArr, int* firstArr, int* secondArr, int firstSize, int secondSize)
{
	int* pointFirst = firstArr;
	int* pointSecond = secondArr;
	int i = 0;

	for (i = 0; i < firstSize + secondSize; i++)
	{
		//�Ƚ�����Ԫ��
		if (*pointFirst < *pointSecond)
		{
			//Сֵ����Ŀ������
			targetArr[i] = *pointFirst;
			if (pointFirst < firstArr + firstSize - 1)
				pointFirst++;
		}
		else 
		{
			targetArr[i] = *pointSecond;
			if (pointSecond < secondArr + secondSize - 1)
				pointSecond++;
		}

		//����һ��������ʵ����һ��Ԫ���ҽ������Ŀ������
		if ((pointFirst == firstArr + firstSize - 1) && 
			(targetArr[i] == *pointFirst))
		{
			//����һ�������ʣ��Ԫ�ذ�˳�����Ŀ������
			int j = 0;

			for (j = i + 1; j < firstSize + secondSize; j++)
			{
				targetArr[j] = *pointSecond;
				pointSecond++;
			}

			break;
		}
	}
}

int main()
{
	int arr1[10];
	int arr2[10];
	int size1 = 0;
	int size2 = 0;
	int arrTarget[20];
	scanf("%d %d", &size1, &size2);
	int i = 0;

	for (i = 0; i < size1; i++)
	{
		scanf("%d", &arr1[i]);
	}

	for (i = 0; i < size2; i++)
	{
		scanf("%d", &arr2[i]);
	}

	CombineArr(arrTarget, arr1, arr2, size1, size2);

	for (i = 0; i < size1 + size2; i++)
	{
		printf("%d ", arrTarget[i]);
	}

	return 0;
}