#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//����n���ɼ������������߳ɼ�����ͳɼ��Ĳ�ɼ��ķ�Χ0~100
//int main()
//{
//	int num = 0;
//	int score[50] = { 0 };
//	int i = 0;
//	int j = 0;
//	scanf("%d", &num);
//
//	for (i = 0; i < num; i++)
//	{
//		scanf("%d", &score[i]);
//	}
//
//	int max = score[0];
//	int min = score[0];
//
//	for (j = 0; j < num; j++)
//	{
//		max = score[j] > max ? score[j] : max;
//		min = score[j] < min ? score[j] : min;
//	}
//
//	int dev = max - min;
//	printf("%d\n", dev);
//
//	return 0;
//}

//�򻯣�����������ʱ�ͽ���ɸѡ�����Сֵ
//��Ϊ�ɼ����з�Χ�ģ�0~100������ˣ���max = 0��min = 100
int main()
{
	int num = 0;
	int score[50] = { 0 };
	int max = 0;
	int min = 100;
	int i = 0;
	scanf("%d", &num);

	for (i = 0; i < num; i++)
	{
		scanf("%d", &score[i]);

		if (max < score[i])
			max = score[i];

		if (min > score[i])
			min = score[i];
	}

	int dev = max - min;
	printf("%d\n", dev);

	return 0;
}