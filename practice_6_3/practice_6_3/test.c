#define  _CRT_SECURE_NO_WARNINGS

#include "bubble_sort.h"

//֮ǰд��ð������ֻ�ܶ����������������
//�ο�C���ԵĿ⺯��qsort���һ��ͬ�������ڸ�����������ĺ���
//void qsort(void *base,      //Ҫ��������ݵ���ʼλ��
//           size_t num,      //Ҫ��������ݵ�����
//           size_t width,    //Ҫ��������ݵ�Ԫ�ش�С���ֽڣ�
//           int (*compare)(const void *elem1, const void *elem2)  //����ָ�룬ָ��ȽϺ���
//           );
//ͨ������ָ��ķ�ʽ��ֻҪ������Ӧ�ıȽϺ����������ú�����������������ʵ�ֶԲ�ͬ�������ݽ�������Ĺ���
int main()
{
	int arr[] = { 10,2,13,54,-5,-6,7,28,9,0 };
	int arrSize = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	BubbleSort(arr, arrSize, sizeof(arr[0]), CompareInt);

	for (i = 0; i < arrSize; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}